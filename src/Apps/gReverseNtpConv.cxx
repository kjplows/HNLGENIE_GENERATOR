//_____________________________________________________________________________________________
/*!

\program grvntpc

\brief   Converts a native GENIE (GHEP/ROOT) event tree file to a host of
         plain text, XML or bare-ROOT formats.

         Syntax:
           gntpc -i input_file [-o output_file] [-n nev]

         Options :

           [] denotes an optional argument

           -n 
              Number of events to convert 
              (optional, default: convert all events)

              >>
	      >> Generic input formats:
              >>
               * `gst': 
                    The 'definite' GENIE summary tree format (gst).
   	       * `gxml': 
                     GENIE XML event format 
   	       * `ghep_mock_data': 
                     Output file has the same format as the input file (GHEP) but
                     all information other than final state particles is hidden
   	       * `rootracker': 
                     A bare-ROOT STDHEP-like GENIE event tree.
   	       * `rootracker_mock_data': 
                     As the `rootracker' format but hiddes all information
                     except the final state particles.
              >>
	      >> Experiment-specific formats:
              >>
   	       * `t2k_rootracker':
                     A variance of the `rootracker' format used by the nd280, INGRID and 2km. 
                     Includes, in addition, JPARC flux pass-through info.
   	       * `numi_rootracker':
                     A variance of the `rootracker' format for the NuMI expts.
                     Includes, in addition, NuMI flux pass-through info.
   	       * `t2k_tracker': 
                     A tracker-type format with tweaks required by the SuperK MC (SKDETSIM):
                        - Converting K0, \bar{K0} -> KO_{long}, K0_{short}
                        - Emulating 'NEUT' reaction codes
                        - Appropriate $track ordering for SKDETSIM
                        - Passing detailed GENIE MC truth and JPARC flux info
                          using the tracker $info lines. This information, 
                          propaged by SKDETSIM to the DSTs, is identical with the 
                          one used at the near detectors and can be used for 
                          global systematic studies.
              >>
	      >> GENIE test / cross-generator comparison formats:
              >>
   	       * `ghad': 
	             NEUGEN-style text-based format for hadronization studies
   	       * `ginuke': 
	             A summary ntuple for intranuclear-rescattering studies using simulated
                     hadron-nucleus samples
              >>
	      >> Other (depreciated) formats:
              >>
   	       * `nuance_tracker': 
   		     NUANCE-style tracker text-based format 
           -o  
              Specifies the output filename. 
              If not specified a the default filename is constructed by the 
              input base name.
	      `gst'                  -> *.gst.root  // this is the 'default' format
	      `gxml'                 -> *.gxml 
	      `ghep_mock_data'       -> *.mockd.ghep.root
	      `rootracker'           -> *.gtrac.root
	      `rootracker_mock_data' -> *.mockd.gtrac.root
	      `t2k_rootracker'       -> *.gtrac.root
	      `numi_rootracker'      -> *.gtrac.root
	      `t2k_tracker'          -> *.gtrac.dat
	      `nuance_tracker'       -> *.gtrac_legacy.dat
	      `ghad'                 -> *.ghad.dat
	      `ginuke'               -> *.ginuke.root
	      
         Examples:
           (1)  shell% grvntpc -i myfile.gst.root

                Converts all events in the GST file myfile.gst.root into a native GHEP tree
                The output file is named myfile.ghep.root

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab
	 John Plows <komninos-john.plows \at physics.ox.ac.uk>

\created April 22nd, 2022

\cpright ??? - TBD
*/
//_____________________________________________________________________________________________

#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "libxml/parser.h"
#include "libxml/xmlmemory.h"

#include <TSystem.h>
#include <TFile.h>
#include <TTree.h>
#include <TFolder.h>
#include <TBits.h>
#include <TObjString.h>
#include <TMath.h>
#include "BaryonResonance/BaryonResonance.h"
#include "BaryonResonance/BaryonResUtils.h"
#include "Conventions/GBuild.h"
#include "Conventions/Constants.h"
#include "Conventions/Units.h"
#include "EVGCore/EventRecord.h"
#include "GHEP/GHepStatus.h"
#include "GHEP/GHepParticle.h"
#include "GHEP/GHepUtils.h"
#include "Ntuple/NtpMCFormat.h"
#include "Ntuple/NtpMCTreeHeader.h"
#include "Ntuple/NtpMCEventRecord.h"
#include "Ntuple/NtpWriter.h"
#include "Numerical/RandomGen.h"
#include "Messenger/Messenger.h"
#include "PDG/PDGCodes.h"
#include "PDG/PDGUtils.h"
#include "PDG/PDGLibrary.h"
#include "Utils/AppInit.h"
#include "Utils/RunOpt.h"
#include "Utils/CmdLnArgParser.h"
#include "Utils/SystemUtils.h"
#include "Utils/T2KEvGenMetaData.h"

#ifdef __GENIE_FLUX_DRIVERS_ENABLED__
#include "FluxDrivers/GJPARCNuFlux.h"
#include "FluxDrivers/GNuMIFlux.h"
#endif

//define __GHAD_NTP__

using std::string;
using std::ostringstream;
using std::ofstream;
using std::endl;
using std::setw;
using std::setprecision;
using std::setfill;
using std::ios;
using std::setiosflags;
using std::vector;

using namespace genie;
using namespace genie::constants;
#ifdef __GENIE_SIMPLE_HNL_ENABLED__
using namespace genie::HNL;
#endif

//format enum
typedef enum EGNtpcFmt {
  kConvFmt_undef = 0,
  kConvFmt_gst,
  kConvFmt_gxml,
  kConvFmt_ghep_mock_data,
  kConvFmt_rootracker,
  kConvFmt_rootracker_mock_data,
  kConvFmt_t2k_rootracker,
  kConvFmt_numi_rootracker,
  kConvFmt_t2k_tracker,
  kConvFmt_nuance_tracker,
  kConvFmt_ghad,
  kConvFmt_ginuke
} GNtpcFmt_t;

// function prototypes

void ConvertFromGST (void);
// void ConvertFromGXML (void);
// etc
void GetCommandLineArgs (int argc, char ** argv);
string DefaultOutputFile (void);
string FormatToString (GNtpcFmt_t fmt);

//input options (from command line arguments):
string     gOptInpFileName;         ///< input file name
string     gOptOutFileName;         ///< output file name
GNtpcFmt_t gOptInpFileFormat;       ///< input file format id
Long64_t   gOptN;                   ///< number of events to process
int        gOptRunNu;               ///< run number

const int kNPmax = 20;
//____________________________________________________________________________________
int main(int argc, char ** argv)
{
  GetCommandLineArgs(argc, argv);
  utils::app_init::MesgThresholds(RunOpt::Instance()->MesgThresholdFiles());

  GHepRecord::SetPrintLevel(RunOpt::Instance()->EventRecordPrintLevel());

  // call the appropriate conversion function
  switch( gOptInpFileFormat ) {
  case kConvFmt_gst: ConvertFromGST(); break;
  default: LOG( "grvntpc", pERROR ) << "Unimplemented feature. Doing nothing";
  }

  LOG( "grvntpc", pDEBUG ) << "All done, exiting normally.";

  return 0;
}
//____________________________________________________________________________________
void ConvertFromGST(void)
{
  // get the input root file contents

  // Define branch variables
  //
  int    brIev         = 0;      // Event number
  int    brNeutrino    = 0;      // Neutrino pdg code
  int    brFSPrimLept  = 0;      // Final state primary lepton pdg code
  int    brTarget      = 0;      // Nuclear target pdg code (10LZZZAAAI)
  int    brTargetZ     = 0;      // Nuclear target Z (extracted from pdg code above)
  int    brTargetA     = 0;      // Nuclear target A (extracted from pdg code above)
  int    brHitNuc      = 0;      // Hit nucleon pdg code      (not set for COH,IMD and NuEL events)
  int    brHitQrk      = 0;      // Hit quark pdg code        (set for DIS events only)
  bool   brFromSea     = false;  // Hit quark is from sea     (set for DIS events only)
  int    brResId       = 0;      // Produced baryon resonance (set for resonance events only)
  bool   brIsQel       = false;  // Is QEL?
  bool   brIsRes       = false;  // Is RES?
  bool   brIsDis       = false;  // Is DIS?
  bool   brIsCoh       = false;  // Is Coherent?
  bool   brIsMec       = false;  // Is MEC?
  bool   brIsDfr       = false;  // Is Diffractive?
  bool   brIsImd       = false;  // Is IMD?
  bool   brIsSingleK   = false;  // Is single kaon?  
  bool   brIsImdAnh    = false;  // Is IMD annihilation?
  bool   brIsNuEL      = false;  // Is ve elastic?
  bool   brIsEM        = false;  // Is EM process?
  bool   brIsCC        = false;  // Is Weak CC process?
  bool   brIsNC        = false;  // Is Weak NC process?
  bool   brIsCharmPro  = false;  // Produces charm?
  bool   brIsHNLDecay  = false;  // Is HNL decay?
  int    brCodeNeut    = 0;      // The equivalent NEUT reaction code (if any)
  int    brCodeNuance  = 0;      // The equivalent NUANCE reaction code (if any)
#ifdef __GENIE_SIMPLE_HNL_ENABLED__
  // --- HNL specific branches
  double brHNLMass     = 0;      // HNL mass in GeV
  double brHNLECoup    = 0;      // |U_e4|^2
  double brHNLMCoup    = 0;      // |U_m4|^2
  double brHNLTCoup    = 0;      // |U_t4|^2
  int    brHNLType     = 0;      // 0 = only N, 1 = only Nbar, 2 = mix
  bool   brHNLMajorana = false;  // Dirac or Majorana HNL?
  int    brFS0Pdg      = 0;      // 1st daughter: Pdg
  double brFS0E        = 0;      // 1st daughter: E
  double brFS0Px       = 0;      // 1st daughter: Px
  double brFS0Py       = 0;      // 1st daughter: Py
  double brFS0Pz       = 0;      // 1st daughter: Pz
  int    brFS1Pdg      = 0;      // 2nd daughter: Pdg
  double brFS1E        = 0;      // 2nd daughter: E
  double brFS1Px       = 0;      // 2nd daughter: Px
  double brFS1Py       = 0;      // 2nd daughter: Py
  double brFS1Pz       = 0;      // 2nd daughter: Pz
  int    brFS2Pdg      = 0;      // 3rd daughter: Pdg
  double brFS2E        = 0;      // 3rd daughter: E
  double brFS2Px       = 0;      // 3rd daughter: Px
  double brFS2Py       = 0;      // 3rd daughter: Py
  double brFS2Pz       = 0;      // 3rd daughter: Pz
  // --- END OF HNL specific branches
#endif
  double brWeight      = 0;      // Event weight
  double brKineXs      = 0;      // Bjorken x as was generated during kinematical selection; takes fermi momentum / off-shellness into account
  double brKineYs      = 0;      // Inelasticity y as was generated during kinematical selection; takes fermi momentum / off-shellness into account
  double brKineTs      = 0;      // Energy transfer to nucleus at COH events as was generated during kinematical selection
  double brKineQ2s     = 0;      // Momentum transfer Q^2 as was generated during kinematical selection; takes fermi momentum / off-shellness into account
  double brKineWs      = 0;      // Hadronic invariant mass W as was generated during kinematical selection; takes fermi momentum / off-shellness into account
  double brKineX       = 0;      // Experimental-like Bjorken x; neglects fermi momentum / off-shellness 
  double brKineY       = 0;      // Experimental-like inelasticity y; neglects fermi momentum / off-shellness 
  double brKineT       = 0;      // Experimental-like energy transfer to nucleus at COH events 
  double brKineQ2      = 0;      // Experimental-like momentum transfer Q^2; neglects fermi momentum / off-shellness
  double brKineW       = 0;      // Experimental-like hadronic invariant mass W; neglects fermi momentum / off-shellness 
  double brEvRF        = 0;      // Neutrino energy @ the rest-frame of the hit-object (eg nucleon for CCQE, e- for ve- elastic,...)
  double brEv          = 0;      // Neutrino energy @ LAB
  double brPxv         = 0;      // Neutrino px @ LAB
  double brPyv         = 0;      // Neutrino py @ LAB
  double brPzv         = 0;      // Neutrino pz @ LAB
  double brEn          = 0;      // Initial state hit nucleon energy @ LAB
  double brPxn         = 0;      // Initial state hit nucleon px @ LAB
  double brPyn         = 0;      // Initial state hit nucleon py @ LAB
  double brPzn         = 0;      // Initial state hit nucleon pz @ LAB
  double brEl          = 0;      // Final state primary lepton energy @ LAB
  double brPxl         = 0;      // Final state primary lepton px @ LAB
  double brPyl         = 0;      // Final state primary lepton py @ LAB
  double brPzl         = 0;      // Final state primary lepton pz @ LAB
  double brPl          = 0;      // Final state primary lepton p  @ LAB
  double brCosthl      = 0;      // Final state primary lepton cos(theta) wrt to neutrino direction
  int    brNfP         = 0;      // Nu. of final state p's + \bar{p}'s (after intranuclear rescattering)
  int    brNfN         = 0;      // Nu. of final state n's + \bar{n}'s
  int    brNfPip       = 0;      // Nu. of final state pi+'s
  int    brNfPim       = 0;      // Nu. of final state pi-'s
  int    brNfPi0       = 0;      // Nu. of final state pi0's (
  int    brNfKp        = 0;      // Nu. of final state K+'s
  int    brNfKm        = 0;      // Nu. of final state K-'s
  int    brNfK0        = 0;      // Nu. of final state K0's + \bar{K0}'s
  int    brNfEM        = 0;      // Nu. of final state gammas and e-/e+ 
  int    brNfOther     = 0;      // Nu. of heavier final state hadrons (D+/-,D0,Ds+/-,Lamda,Sigma,Lamda_c,Sigma_c,...)
  int    brNiP         = 0;      // Nu. of `primary' (: before intranuclear rescattering) p's + \bar{p}'s  
  int    brNiN         = 0;      // Nu. of `primary' n's + \bar{n}'s  
  int    brNiPip       = 0;      // Nu. of `primary' pi+'s 
  int    brNiPim       = 0;      // Nu. of `primary' pi-'s 
  int    brNiPi0       = 0;      // Nu. of `primary' pi0's 
  int    brNiKp        = 0;      // Nu. of `primary' K+'s  
  int    brNiKm        = 0;      // Nu. of `primary' K-'s  
  int    brNiK0        = 0;      // Nu. of `primary' K0's + \bar{K0}'s 
  int    brNiEM        = 0;      // Nu. of `primary' gammas and e-/e+ 
  int    brNiOther     = 0;      // Nu. of other `primary' hadron shower particles
  int    brNf          = 0;      // Nu. of final state particles in hadronic system
  int    brPdgf  [kNPmax];       // Pdg code of k^th final state particle in hadronic system
  double brEf    [kNPmax];       // Energy     of k^th final state particle in hadronic system @ LAB
  double brPxf   [kNPmax];       // Px         of k^th final state particle in hadronic system @ LAB
  double brPyf   [kNPmax];       // Py         of k^th final state particle in hadronic system @ LAB
  double brPzf   [kNPmax];       // Pz         of k^th final state particle in hadronic system @ LAB
  double brPf    [kNPmax];       // P          of k^th final state particle in hadronic system @ LAB
  double brCosthf[kNPmax];       // cos(theta) of k^th final state particle in hadronic system @ LAB wrt to neutrino direction
  int    brNi          = 0;      // Nu. of particles in 'primary' hadronic system (before intranuclear rescattering)
  int    brPdgi[kNPmax];         // Pdg code of k^th particle in 'primary' hadronic system 
  int    brResc[kNPmax];         // FSI code of k^th particle in 'primary' hadronic system 
  double brEi  [kNPmax];         // Energy   of k^th particle in 'primary' hadronic system @ LAB
  double brPxi [kNPmax];         // Px       of k^th particle in 'primary' hadronic system @ LAB
  double brPyi [kNPmax];         // Py       of k^th particle in 'primary' hadronic system @ LAB
  double brPzi [kNPmax];         // Pz       of k^th particle in 'primary' hadronic system @ LAB
  double brVtxX = 0;             // Vertex x in detector coord system (SI)
  double brVtxY = 0;             // Vertex y in detector coord system (SI)
  double brVtxZ = 0;             // Vertex z in detector coord system (SI)
  double brVtxT = 0;             // Vertex t in detector coord system (SI)
  double brSumKEf = 0;           // Sum of kinetic energies of all final state particles
  double brCalResp0 = 0;         // Approximate calorimetric response to the hadronic system computed as sum of
				 //  - (kinetic energy) for pi+, pi-, p, n 
                                 //  - (energy + 2*mass) for antiproton, antineutron
                                 //  - ((e/h) * energy)   for pi0, gamma, e-, e+, where e/h is set to 1.3
                                 //  - (kinetic energy) for other particles

  // Open the ROOT file and get the TTree ( & its header ? Non-existent! )
  TFile fin(gOptInpFileName.c_str(),"READ");
  TTree * s_tree = 0;
  s_tree = dynamic_cast< TTree * > ( fin.Get("gst") );

  LOG( "grvntpc", pDEBUG )
    << "Initialising an Ntuple writer. . .";

  // open a GENIE GHEP tree for writing
  // do this using an Ntuple Writer
  NtpWriter ntpw(kNFGHEP, gOptRunNu);
  ntpw.CustomizeFilenamePrefix("gntp");
  ntpw.Initialize();

  LOG( "grvntpc", pDEBUG )
    << "Setting branch addresses. . .";

  // Set all the branches manually.
  s_tree->SetBranchAddress( "iev", &brIev );
  s_tree->SetBranchAddress( "neu" , &brNeutrino );
  s_tree->SetBranchAddress( "fspl", &brFSPrimLept );
  s_tree->SetBranchAddress( "tgt", &brTarget );
  s_tree->SetBranchAddress( "Z", &brTargetZ );
  s_tree->SetBranchAddress( "A", &brTargetA );
  s_tree->SetBranchAddress( "hitnuc", &brHitNuc );
  s_tree->SetBranchAddress( "hitqrk", &brHitQrk );
  s_tree->SetBranchAddress( "resid", &brResId );
  s_tree->SetBranchAddress( "sea", &brFromSea );
  s_tree->SetBranchAddress( "qel", &brIsQel );
  s_tree->SetBranchAddress( "mec", &brIsMec );
  s_tree->SetBranchAddress( "res", &brIsRes );
  s_tree->SetBranchAddress( "dis", &brIsDis );
  s_tree->SetBranchAddress( "coh", &brIsCoh );
  s_tree->SetBranchAddress( "dfr", &brIsDfr );
  s_tree->SetBranchAddress( "imd", &brIsImd );
  s_tree->SetBranchAddress( "imdanh", &brIsImdAnh );
  s_tree->SetBranchAddress( "singlek", &brIsSingleK );
  s_tree->SetBranchAddress( "nuel", &brIsNuEL );
  s_tree->SetBranchAddress( "em", &brIsEM );
  s_tree->SetBranchAddress( "cc", &brIsCC );
  s_tree->SetBranchAddress( "nc", &brIsNC );
  s_tree->SetBranchAddress( "charm", &brIsCharmPro );
  s_tree->SetBranchAddress( "nhl", &brIsHNLDecay );
  s_tree->SetBranchAddress( "neut_code", &brCodeNeut );
  s_tree->SetBranchAddress( "nuance_code", &brCodeNuance );
#ifdef __GENIE_SIMPLE_HNL_ENABLED__
  s_tree->SetBranchAddress( "nhl_mass", &brHNLMass );
  s_tree->SetBranchAddress( "nhl_e_coup", &brHNLECoup );
  s_tree->SetBranchAddress( "nhl_m_coup", &brHNLMCoup );
  s_tree->SetBranchAddress( "nhl_t_coup", &brHNLTCoup );
  s_tree->SetBranchAddress( "nhl_type", &brHNLType );
  s_tree->SetBranchAddress( "nhl_majorana", &brHNLMajorana );
  s_tree->SetBranchAddress( "nhl_FS0_Pdg", &brFS0Pdg );
  s_tree->SetBranchAddress( "nhl_FS0_E", &brFS0E );
  s_tree->SetBranchAddress( "nhl_FS0_Px", &brFS0Px );
  s_tree->SetBranchAddress( "nhl_FS0_Py", &brFS0Py );
  s_tree->SetBranchAddress( "nhl_FS0_Pz", &brFS0Pz );
  s_tree->SetBranchAddress( "nhl_FS1_Pdg", &brFS1Pdg );
  s_tree->SetBranchAddress( "nhl_FS1_E", &brFS1E );
  s_tree->SetBranchAddress( "nhl_FS1_Px", &brFS1Px );
  s_tree->SetBranchAddress( "nhl_FS1_Py", &brFS1Py );
  s_tree->SetBranchAddress( "nhl_FS1_Pz", &brFS1Pz );
  s_tree->SetBranchAddress( "nhl_FS2_Pdg", &brFS2Pdg );
  s_tree->SetBranchAddress( "nhl_FS2_E", &brFS2E );
  s_tree->SetBranchAddress( "nhl_FS2_Px", &brFS2Px );
  s_tree->SetBranchAddress( "nhl_FS2_Py", &brFS2Py );
  s_tree->SetBranchAddress( "nhl_FS2_Pz", &brFS2Pz );
#endif
  s_tree->SetBranchAddress( "wght", &brWeight );
  s_tree->SetBranchAddress( "xs", &brKineXs );
  s_tree->SetBranchAddress( "ys", &brKineYs );
  s_tree->SetBranchAddress( "ts", &brKineTs );
  s_tree->SetBranchAddress( "Q2s", &brKineQ2s );
  s_tree->SetBranchAddress( "Ws", &brKineWs );
  s_tree->SetBranchAddress( "x", &brKineX );
  s_tree->SetBranchAddress( "y", &brKineY );
  s_tree->SetBranchAddress( "t", &brKineT );
  s_tree->SetBranchAddress( "Q2", &brKineQ2 );
  s_tree->SetBranchAddress( "W", &brKineW );
  s_tree->SetBranchAddress( "EvRF", &brEvRF );
  s_tree->SetBranchAddress( "Ev", &brEv );
  s_tree->SetBranchAddress( "pxv", &brPxv );
  s_tree->SetBranchAddress( "pyv", &brPyv );
  s_tree->SetBranchAddress( "pzv", &brPzv );
  s_tree->SetBranchAddress( "En", &brEn );
  s_tree->SetBranchAddress( "pxn", &brPxn );
  s_tree->SetBranchAddress( "pyn", &brPyn );
  s_tree->SetBranchAddress( "pzn", &brPzn );
  s_tree->SetBranchAddress( "El", &brEl );
  s_tree->SetBranchAddress( "pxl", &brPxl );
  s_tree->SetBranchAddress( "pyl", &brPyl );
  s_tree->SetBranchAddress( "pzl", &brPzl );
  s_tree->SetBranchAddress( "pl", &brPl );
  s_tree->SetBranchAddress( "cthl", &brCosthl );
  s_tree->SetBranchAddress( "nfp", &brNfP );
  s_tree->SetBranchAddress( "nfn", &brNfN );
  s_tree->SetBranchAddress( "nfpip", &brNfPip );
  s_tree->SetBranchAddress( "nfpim", &brNfPim );
  s_tree->SetBranchAddress( "nfpi0", &brNfPi0 );
  s_tree->SetBranchAddress( "nfkp", &brNfKp );
  s_tree->SetBranchAddress( "nfkm", &brNfKm );
  s_tree->SetBranchAddress( "nfk0", &brNfK0 );
  s_tree->SetBranchAddress( "nfem", &brNfEM );
  s_tree->SetBranchAddress( "nfother", &brNfOther );
  s_tree->SetBranchAddress( "nip", &brNiP );
  s_tree->SetBranchAddress( "nin", &brNiN );
  s_tree->SetBranchAddress( "nipip", &brNiPip );
  s_tree->SetBranchAddress( "nipim", &brNiPim );
  s_tree->SetBranchAddress( "nipi0", &brNiPi0 );
  s_tree->SetBranchAddress( "nikp", &brNiKp );
  s_tree->SetBranchAddress( "nikm", &brNiKm );
  s_tree->SetBranchAddress( "nik0", &brNiK0 );
  s_tree->SetBranchAddress( "niem", &brNiEM );
  s_tree->SetBranchAddress( "niother", &brNiOther );
  s_tree->SetBranchAddress( "nf", &brNf );
  s_tree->SetBranchAddress( "pdgf", brPdgf );
  s_tree->SetBranchAddress( "Ef", brEf );
  s_tree->SetBranchAddress( "pxf", brPxf );
  s_tree->SetBranchAddress( "pyf", brPyf );
  s_tree->SetBranchAddress( "pzf", brPzf );
  s_tree->SetBranchAddress( "pf", brPf );
  s_tree->SetBranchAddress( "cthf", brCosthf );
  s_tree->SetBranchAddress( "ni", &brNi );
  s_tree->SetBranchAddress( "pdgi", brPdgi );
  s_tree->SetBranchAddress( "resc", &brResc );
  s_tree->SetBranchAddress( "Ei", brEi );
  s_tree->SetBranchAddress( "pxi", brPxi );
  s_tree->SetBranchAddress( "pyi", brPyi );
  s_tree->SetBranchAddress( "pzi", brPzi );
  s_tree->SetBranchAddress( "vtxx", &brVtxX );
  s_tree->SetBranchAddress( "vtxy", &brVtxY );
  s_tree->SetBranchAddress( "vtxz", &brVtxZ );
  s_tree->SetBranchAddress( "sumKEf", &brSumKEf );
  s_tree->SetBranchAddress( "calresp0", &brCalResp0 );

  // and add some custom branches to NtupleWriter
#ifdef __GENIE_SIMPLE_HNL_ENABLED__
  ntpw.EventTree()->Branch("hnl_mass", &brHNLMass, "brHNLMass/D");
  ntpw.EventTree()->Branch("hnl_coup_e", &brHNLECoup, "brHNLECoup/D");
  ntpw.EventTree()->Branch("hnl_coup_mu", &brHNLMCoup, "brHNLMCoup/D");
#endif

  // Figure out how many events to analyze
  Long64_t nmax = (gOptN<0) ? 
       s_tree->GetEntries() : TMath::Min( s_tree->GetEntries(), gOptN );
  if (nmax<0) {
    LOG("grvntpc", pERROR) << "Number of events = 0";
    return;
  }

  LOG("grvntpc", pNOTICE) << "*** Analyzing: " << nmax << " events";

  // Event loop
  for(Long64_t iev = 0; iev < nmax; iev++){
    LOG( "grvntpc", pINFO ) << "Event no: " << iev;
    
    s_tree->GetEntry(iev);

#ifdef __GENIE_SIMPLE_HNL_ENABLED__
    if( !PDGLibrary::Instance()->Find( brNeutrino ) && brIsHNLDecay ){ // must add to PDGLibrary first.
      LOG( "grvntpc", pINFO ) << "Adding code " << brNeutrino << " to PDGLibrary...";
      PDGLibrary::Instance()->AddSimpleHNL( brNeutrino, brHNLMass, brHNLECoup, brHNLMCoup );
    }
#endif
    
    // Create the event record and set it
    LOG( "grvntpc", pDEBUG ) << "Creating event record. . .";
    EventRecord * event = new EventRecord;

    // build Interaction object and attach it
    LOG( "grvntpc", pDEBUG ) << "Creating Interaction. . .";
    TLorentzVector p4HNL( brPxv, brPyv, brPzv, brEv );
    TLorentzVector x4HNL( brVtxX, brVtxY, brVtxZ, brVtxT );
    int probepdg = brNeutrino;
    if( !brIsHNLDecay ){ LOG( "grvntpc", pFATAL ) << "Can only handle HNL so far..."; }
    assert( brIsHNLDecay );
    Interaction * interaction = Interaction::HNLDecay( probepdg, HNLenums::kInit, p4HNL );
    // make sure InitialState knows about this!
    interaction->InitStatePtr()->SetProbePdg( probepdg );
    interaction->InitStatePtr()->SetProbeP4( p4HNL );

    assert( interaction->InitStatePtr()->Probe() );
    
    // update vtx
    event->SetVertex( x4HNL );

    // update kine
    interaction->KinePtr()->SetW( brKineWs, true );
    interaction->KinePtr()->SetQ2( brKineQ2s, true );
    interaction->KinePtr()->Sett( brKineTs, true );

    // update xclstag
    interaction->ExclTagPtr()->SetNPions( brNfPip, brNfPi0, brNfPim );

    // update weight
    event->SetWeight( brWeight );

    // Add particles to the event record
    LOG( "grvntpc", pDEBUG ) << "Adding particles to event record";
    
    // 1st daughter
    TLorentzVector d1p4( brFS0Px, brFS0Py, brFS0Pz, brFS0E );
    int d1pdg = brFS0Pdg;
    
    // 2nd daughter
    TLorentzVector d2p4( brFS1Px, brFS1Py, brFS1Pz, brFS1E );
    int d2pdg = brFS1Pdg;

    // 3rd daughter
    TLorentzVector d3p4( brFS2Px, brFS2Py, brFS2Pz, brFS2E );
    int d3pdg = brFS2Pdg;

    // finally, add the particles
    int hnl_ld = ( d3pdg != 0 ) ? 3 : 2;
    event->AddParticle( brNeutrino, kIStInitialState, -1, -1, 1, hnl_ld, p4HNL, x4HNL );
    event->AddParticle( d1pdg, kIStStableFinalState, 0, -1, -1, -1, d1p4, x4HNL );
    event->AddParticle( d2pdg, kIStStableFinalState, 0, -1, -1, -1, d2p4, x4HNL );
    if( d3pdg != 0 ){
      event->AddParticle( d3pdg, kIStStableFinalState, 0, -1, -1, -1, d3p4, x4HNL );
    }

    LOG( "grvntpc", pDEBUG ) << "Attaching summary. . .";
    event->AttachSummary(interaction);

    assert( event->Probe() );

    // Add event at the output ntuple & clean-up
    LOG( "grvntpc", pDEBUG ) << "Adding to event record. . .";
    ntpw.AddEventRecord(iev, event);
    delete event;

    // dump output
    if(false){
      LOG( "grvntpc", pDEBUG ) << "DUMPING OUTPUT OF INTERESTING BRANCHES NOW:"
			       << "\niev          = " << brIev
			       << "\nneu          = " << brNeutrino
			       << "\nfspl         = " << brFSPrimLept
			       << "\ntgt          = " << brTarget
			       << "\nZ            = " << brTargetZ
			       << "\nA            = " << brTargetA
			       << "\nnhl          = " << brIsHNLDecay
#ifdef __GENIE_SIMPLE_HNL_ENABLED__
			       << "\nnhl_mass     = " << brHNLMass
			       << "\nnhl_e_coup   = " << brHNLECoup
			       << "\nnhl_m_coup   = " << brHNLMCoup
			       << "\nnhl_t_coup   = " << brHNLTCoup
			       << "\nnhl_type     = " << brHNLType
			       << "\nnhl_majorana = " << brHNLMajorana
#endif
			       << "\nwght         = " << brWeight
			       << "\nts           = " << brKineTs
			       << "\nQ2s          = " << brKineQ2s
			       << "\nWs           = " << brKineWs
			       << "\nEv           = " << brEv
			       << "\npxv          = " << brPxv
			       << "\npyv          = " << brPyv
			       << "\npzv          = " << brPzv
			       << "\nEl           = " << brEl
			       << "\npxl          = " << brPxl
			       << "\npyl          = " << brPyl
			       << "\npzl          = " << brPzl
			       << "\ncthl         = " << brCosthl
			       << "\nnfpip        = " << brNfPip
			       << "\nnfpim        = " << brNfPim
			       << "\nnfpi0        = " << brNfPi0
			       << "\nnf           = " << brNf
			       << "\npdgf[0]      = " << brPdgf[0]
			       << "\npxf[0]       = " << brPxf[0]
			       << "\npyf[0]       = " << brPyf[0]
			       << "\npzf[0]       = " << brPzf[0]
			       << "\nvtxx         = " << brVtxX
			       << "\nvtxy         = " << brVtxY
			       << "\nvtxz         = " << brVtxZ
			       << "\nvtxt         = " << brVtxT
			       << "\nsumKEf       = " << brSumKEf
			       << "\ncalresp0     = " << brCalResp0;
    }

    // Clean-up arrays
    //
    for(int j=0; j<kNPmax; j++) {
       brPdgi   [j] =  0;     
       brResc   [j] = -1;     
       brEi     [j] =  0;     
       brPxi    [j] =  0;     
       brPyi    [j] =  0;     
       brPzi    [j] =  0;     
       brPdgf   [j] =  0;     
       brEf     [j] =  0;     
       brPxf    [j] =  0;     
       brPyf    [j] =  0;     
       brPzf    [j] =  0;     
       brPf     [j] =  0;     
       brCosthf [j] =  0;     
    }
  }

  // Save the generated event tree & close the output file
  ntpw.Save();

  LOG( "grvntpc", pDEBUG ) << "Done!";
}
//____________________________________________________________________________________
// FUNCTIONS FOR PARSING CMD-LINE ARGUMENTS 
//____________________________________________________________________________________
void GetCommandLineArgs(int argc, char ** argv)
{
  // Common run options. 
  RunOpt::Instance()->ReadFromCommandLine(argc,argv);

  // Parse run options for this app

  CmdLnArgParser parser(argc,argv);

  // get input ROOT file (containing a GENIE GHEP event tree)
  if( parser.OptionExists('i') ) {
    LOG("gntpc", pINFO) << "Reading input filename";
    gOptInpFileName = parser.ArgAsString('i');

    // get the input file format
    size_t pos = gOptInpFileName.find(".root");
    if( pos == std::string::npos ){
      pos = gOptInpFileName.find(".dat");
      if( pos == std::string::npos ){
	pos = gOptInpFileName.find(".gxml");
	if( pos == std::string::npos ){
	  LOG( "grvntpc", pFATAL )
	    << "Unknown file format! Exiting.";
	} // failed all
	else{ gOptInpFileFormat = kConvFmt_gxml; }
      } // failed dat
      pos = gOptInpFileName.find(".gtrac.dat");
      if( pos == std::string::npos ){
	pos = gOptInpFileName.find(".gtrac_legacy.dat");
	if( pos == std::string::npos ){
	  pos = gOptInpFileName.find(".ghad.dat");
	  if( pos == std::string::npos ){
	    LOG( "grvntpc", pFATAL )
	      << "Unknown file format! Exiting.";
	    gAbortingInErr = true;
	    exit(3);
	  } // failed all dat
	  else{ gOptInpFileFormat = kConvFmt_ghad; }
	} // failed all gtrac
	else{ gOptInpFileFormat = kConvFmt_nuance_tracker; }
      } // failed gtrac.dat
      else{ gOptInpFileFormat = kConvFmt_t2k_tracker; }
    } // failed root
    else {
      pos = gOptInpFileName.find(".gst.root");
      if( pos == std::string::npos ){
	pos = gOptInpFileName.find(".mockd");
	if( pos == std::string::npos ){
	  if( pos == std::string::npos ){
	    pos = gOptInpFileName.find(".gtrac.root");
	    if( pos == std::string::npos ) {
	      pos = gOptInpFileName.find(".ginuke.root");
	      if( pos == std::string::npos ){
		LOG( "grvntpc", pFATAL )
		  << "Unknown file format! Exiting.";
		gAbortingInErr = true;
		exit(3);
	      } // succeeded root but unrecognised
	      else{ gOptInpFileFormat = kConvFmt_ginuke; }
	    } // failed gtrac
	    else{
	      LOG( "grvntpc", pFATAL )
		<< "File format is gtrac.root - unimplemented. Exiting.";
	      gAbortingInErr = true;
	      exit(3);
	    } // succeeded gtrac
	  }
	} // failed mock_data
	else{
	  pos = gOptInpFileName.find(".mockd.ghep.root");
	  if( pos == std::string::npos ){
	    pos = gOptInpFileName.find(".mockd.gtrac.root");
	    if( pos == std::string::npos ){
	      LOG( "grvntpc", pFATAL )
		<< "Unknown file format! Exiting.";
	      gAbortingInErr = true;
	      exit(3);
	    } // succeeded mock_data but unrecognised
	    else{ gOptInpFileFormat = kConvFmt_rootracker_mock_data; }
	  } // failed ghep_mock_data
	  else{ gOptInpFileFormat = kConvFmt_ghep_mock_data; } // does this mean anything?
	} // succeeded mock_data
      } // failed gst
      else{ gOptInpFileFormat = kConvFmt_gst; }
    } // succeeded root
  } else {
    LOG("grvntpc", pFATAL)
       << "Unspecified input filename - Exiting";
    //PrintSyntax();
    gAbortingInErr = true;
    exit(1);
  }

  // check input GENIE file
  bool inpok = !(gSystem->AccessPathName(gOptInpFileName.c_str()));
  if (!inpok) {
    LOG("grvntpc", pFATAL)
        << "The input GENIE file ["
        << gOptInpFileName << "] is not accessible";
    gAbortingInErr = true;
    exit(2);
  }

  // get output file name 
  if( parser.OptionExists('o') ) {
    LOG("grvntpc", pINFO) << "Reading output filename";
    gOptOutFileName = parser.ArgAsString('o');
  } else {
    LOG("grvntpc", pINFO)
       << "Unspecified output filename - Using default";
    gOptOutFileName = DefaultOutputFile();
  }

  // get number of events to convert
  if( parser.OptionExists('n') ) {
    LOG("grvntpc", pINFO) << "Reading number of events to analyze";
    gOptN = parser.ArgAsInt('n');
  } else {
    LOG("grvntpc", pINFO)
       << "Unspecified number of events to analyze - Use all";
    gOptN = -1;
  }

  // get run number
  if( parser.OptionExists('r') ) {
    LOG("grvntpc", pINFO) << "Reading run number";
    gOptRunNu = parser.ArgAsInt('r');
  } else {
    LOG("grvntpc", pINFO)
      << "Unspecified run number - Using default";
    gOptRunNu = 1234;
  }

  LOG("grvntpc", pNOTICE) << "Input filename  = " << gOptInpFileName;
  LOG("grvntpc", pNOTICE) << "Output filename = " << gOptOutFileName;
  LOG("grvntpc", pNOTICE) << "Conversion from format = " << FormatToString( gOptInpFileFormat );
  LOG("grvntpc", pNOTICE) << "Number of events to be converted = " << gOptN;

  LOG("grvntpc", pNOTICE) << *RunOpt::Instance();
}
//____________________________________________________________________________________
string DefaultOutputFile(void)
{
  // filename extension - depending on file format
  string ext=".ghep.root";

  string inpname = gOptInpFileName;
  unsigned int L = inpname.length();

  // if the last 5 characters are ".root" (ROOT file extension) then
  // remove them
  if(inpname.substr(L-5, L).find(".root") != string::npos) {
    inpname.erase(L-5, L);
    L = inpname.length();
    // if the last 4 characters are ".gst" then remove them
    if(inpname.substr(L-4, L).find(".gst") != string::npos) {
      inpname.erase(L-4, L);
    }
    // if the last 6 characters are ".gtrac" then remove them
    if(inpname.substr(L-6, L).find(".gtrac") != string::npos) {
      inpname.erase(L-6, L);
      L = inpname.length();
      // if the last 6 characters are ".mockd" then remove them
      if(inpname.substr(L-6, L).find(".mockd") != string::npos) {
	inpname.erase(L-6, L);
      }
    }
    // if the last 11 characters are ".mockd.ghep" then remove them
    if(inpname.substr(L-11, L).find(".mockd.ghep") != string::npos) {
      inpname.erase(L-11, L);
    }
    // if the last 7 characters are ".ginuke" then remove them
    if(inpname.substr(L-7, L).find(".ginuke") != string::npos) {
      inpname.erase(L-7, L);
    }
  }
  // if the last 4 characters are ".dat" then remove them
  if(inpname.substr(L-4, L).find(".dat") != string::npos) {
    inpname.erase(L-4, L);
  }
  // if the last 5 characters are ".gxml" then remove them
  if(inpname.substr(L-5, L).find(".gxml") != string::npos){
    inpname.erase(L-5, L);
  }

  ostringstream name;
  name << inpname << ext;

  return gSystem->BaseName(name.str().c_str());
}
//____________________________________________________________________________________
string FormatToString( GNtpcFmt_t fmt )
{
  switch( (int)fmt ){
  case 0:  return "Undefined";
  case 1:  return "GST";
  case 2:  return "GXML";
  case 3:  return "GHEP mock";
  case 4:  return "Rootracker";
  case 5:  return "Rootracker mock";
  case 6:  return "Rootracker T2K";
  case 7:  return "Rootracker NuMI";
  case 8:  return "Tracker T2K";
  case 9:  return "Tracker Nuance";
  case 10: return "GHAD";
  case 11: return "GINUKE";
  default: return "None";
  }
}
//____________________________________________________________________________________
