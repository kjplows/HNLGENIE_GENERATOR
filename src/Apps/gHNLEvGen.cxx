//________________________________________________________________________________________
/*!

\program gevgen_hnl

\brief   A GENIE-based Heavy Neutral Lepton decay application.
         Heavily based on the Nucleon Decay application written by Costas Andreopoulos.

         *** Synopsis :

         gevgen_hnl  [-h] 
                     [-r run#] 
                      -n n_of_events
                     [-c coproduced_lepton_pdg]
		      -M HNL_mass 
		     [-k HNL_kind]
		     [-j isMajorana]
		     [-e eCoupling]  Currently under pseudounitarity
		     [-m muCoupling] Defaults to 1:1
		     [-f path/to/flux/file] Programme searches for this if not given
		      -E energy_range. Same syntax as gevgen's '-e' option.
	              -g geometry
                     [-L geometry_length_units] 
                     [-D geometry_density_units]
                     [-t geometry_top_volume_name]
                     [-o output_event_file_prefix]
                     [--seed random_number_seed]
                     [--message-thresholds xml_file]
                     [--event-record-print-level level]
                     [--mc-job-status-refresh-rate  rate]

         *** Options :

           [] Denotes an optional argument

           -h 
              Prints out the gevgen_ndcy syntax and exits.
           -r 
              Specifies the MC run number [default: 1000].
           -n  
              Specifies how many events to generate.

	   -c
	      Specifies whether the HNL was produced by P --> e N or P --> mu N
	      If not given, weighted mix of both is considered
	      i.e. for 1:2 e:mu flux = 1/3 * e-coup + 2/3 * mu-coup

	   -M
	      HNL mass in GeV
	   -k
	      HNL kind: nu vs nubar
	   -j
	      Is Majorana? Overrides -k flag
	   -q
	      Use all HNL flavours at same time? Equivalent to -j 1 -e 1 -m 1
	   -e
	      Electron-like coupling |U_e4|^2. Assumes \sum_{\ell} |U_\ell 4|^2 = 1.
	   -m
	      Muon-like coupling |U_mu4|^2. Assumes \sum_{\ell} |U_\ell 4|^2 = 1.

	   -f
	      Path to (non-standard) input flux file
	      If user does not give this input, search from suite of standard fluxes
	      to be included with this application

	   -E
	      Energy range for flux. Can be a comma-separated list of values. See gevgen -e syntax.

           -g 
              Input 'geometry'.
              This option can be used to specify any of:
              1 > A ROOT file containing a ROOT/GEANT geometry description
                  [Examples] 
                  - To use the master volume from the ROOT geometry stored 
                    in the laguna-lbno.root file, type:
                    '-g /some/path/laguna-lbno.root'
              2 > A mix of target materials, each with its corresponding weight,
                  typed as a comma-separated list of nuclear PDG codes (in the
                  std PDG2006 convention: 10LZZZAAAI) with the weight fractions
                  in brackets, eg code1[fraction1],code2[fraction2],...
                  If that option is used (no detailed input geometry description) 
                  then the interaction vertices are distributed in the detector
                  by the detector MC.
                  [Examples] 
                  - To use a target mix of 88.9% O16 and 11.1% Hydrogen type:
                    '-g 1000080160[0.889],1000010010[0.111]'
           -L 
              Input geometry length units, eg 'm', 'cm', 'mm', ...
              [default: 'mm']
           -D 
              Input geometry density units, eg 'g_cm3', 'clhep_def_density_unit',... 
              [default: 'g_cm3']
           -t 
              Input 'top volume' for event generation.
              The option be used to force event generation in given sub-detector.
              [default: the 'master volume' of the input geometry]
              You can also use the -t option to switch generation on/off at
              multiple volumes as, for example, in:
              `-t +Vol1-Vol2+Vol3-Vol4',
              `-t "+Vol1 -Vol2 +Vol3 -Vol4"',
              `-t -Vol2-Vol4+Vol1+Vol3',
              `-t "-Vol2 -Vol4 +Vol1 +Vol3"'m
              where:
              "+Vol1" and "+Vol3" tells GENIE to `switch on'  Vol1 and Vol3, while
              "-Vol2" and "-Vol4" tells GENIE to `switch off' Vol2 and Vol4.
              If the very first character is a '+', GENIE will neglect all volumes
              except the ones explicitly turned on. Vice versa, if the very first
              character is a `-', GENIE will keep all volumes except the ones
              explicitly turned off (feature contributed by J.Holeczek).
           -o 
              Sets the prefix of the output event file. 
              The output filename is built as: 
              [prefix].[run_number].[event_tree_format].[file_format]
              The default output filename is: 
              gntp.[run_number].ghep.root
              This cmd line arguments lets you override 'gntp'
           --seed
              Random number seed.

\author  John Plows <komninos-john.plows \at physics.ox.ac.uk>
         University of Oxford
              
\created February 9th, 2022
             
\cpright ???

*/
//_________________________________________________________________________________________

#include <cassert>
#include <cstdlib>
#include <string> 
#include <vector>
#include <sstream>

#include <TSystem.h> 

#include "Algorithm/AlgFactory.h"
#include "EVGCore/EventRecord.h"
#include "EVGCore/EventGeneratorI.h"
#include "EVGCore/EventRecordVisitorI.h"
#include "EVGDrivers/GMCJMonitor.h"
#include "Messenger/Messenger.h"
#include "Ntuple/NtpWriter.h"
#include "Numerical/RandomGen.h"
#include "PDG/PDGCodeList.h"
#include "PDG/PDGCodes.h"
#include "PDG/PDGUtils.h"
#include "PDG/PDGLibrary.h"
#include "SimpleHNL/DummyHNLInteractionListGenerator.h"
#include "SimpleHNL/FluxReader.h"
#include "SimpleHNL/HNLDecayer.h"
#include "SimpleHNL/SimpleHNL.h"
#include "Utils/StringUtils.h"
#include "Utils/UnitUtils.h"
#include "Utils/PrintUtils.h"
#include "Utils/AppInit.h"
#include "Utils/RunOpt.h"
#include "Utils/CmdLnArgParser.h"

#ifdef __GENIE_FLUX_DRIVERS_ENABLED__
#ifdef __GENIE_GEOM_DRIVERS_ENABLED__
#define __CAN_GENERATE_EVENTS_USING_A_FLUX_OR_TGTMIX__
#include "FluxDrivers/GCylindTH1Flux.h"
#include "FluxDrivers/GMonoEnergeticFlux.h"
#include "Geo/PointGeomAnalyzer.h"
#endif
#endif

using std::string;
using std::vector;
using std::ostringstream;

using namespace genie;

// function prototypes
void  GetCommandLineArgs ( int argc, char ** argv );
void  PrintSyntax        ( void );

#ifdef __CAN_GENERATE_EVENTS_USING_A_FLUX_OR_TGTMIX__
void            GenerateEventsUsingFluxOrTgtMix();
GeomAnalyzerI * GeomDriver              (void);
GFluxI *        FluxDriver              (void);
GFluxI *        MonoEnergeticFluxDriver (void);
GFluxI *        TH1FluxDriver           (void);
#endif

void  AddHNLToPDGLibrary( int pdgc, double mHNL, double Ue42, double Um42 );
int   SelectInitState    ( void ); // how am I gonna define this? 1 HNL?
const EventRecordVisitorI * HNLDecayGenerator ( void );

//
string          kDefOptGeomLUnits    = "mm";    // default geometry length units
string          kDefOptGeomDUnits    = "g_cm3"; // default geometry density units
NtpMCFormat_t   kDefOptNtpFormat     = kNFGHEP; // default event tree format   
string          kDefOptEvFilePrefix  = "gntp";
string          kDefGENIELocation    = std::getenv("GENIE"); // GENIE location
string          kDefOptFluxSpecPath  = "/data/flux/HNL/FHC"; // where in ${GENIE} to look for HNL fluxes
string          kDefOptFluxFilePath  = kDefGENIELocation + kDefOptFluxSpecPath;

//
Long_t             gOptRunNu         = 1000;                // run number
int                gOptNev           = 10;                  // number of events to generate

int                gOptCpL           = 14;                  // co-produced lepton PDG
int                gOptHNLPdgCode    = 1900;                // pdg code. Set for now.
double             gOptHNLMass       = 0.255;               // HNL mass
int                gOptHNLKind       = 2;                   // HNL kind. 0 = nu, 1 = nubar, 2 = mix
bool               gOptIsMajorana    = false;               // Is Majorana? True ==> HNL kind set to 0
double             gOptECoupling     = 1.0;                 // |U_e4|^2
double             gOptMuCoupling    = 1.0;                 // |U_mu4|^2

string             gOptFluxSpecPath  = kDefOptFluxSpecPath;
string             gOptFluxFilePath  = kDefOptFluxFilePath; // path to flux files
string             gOptEvFilePrefix  = kDefOptEvFilePrefix; // event file prefix
double             gOptNuEnergy      = 0.0;                 // low-edge of energy range  
double             gOptNuEnergyRange = -1.0;                // width of energy range
bool               gOptDoMasterMixing = false;              // ignore HNL type discrimination

bool               gOptUsingRootGeom = false;               // using root geom or target mix?
map<int,double>    gOptTgtMix;                              // target mix  (tgt pdg -> wght frac) / if not using detailed root geom
string             gOptRootGeom;                         // input ROOT file with realistic detector geometry
string             gOptRootGeomTopVol = "";              // input geometry top event generation volume 
double             gOptGeomLUnits = 0;                   // input geometry length units 
double             gOptGeomDUnits = 0;                   // input geometry density units 

long int           gOptRanSeed = -1;                     // random number seed

//_________________________________________________________________________________________
int main(int argc, char ** argv)
{
  // Parse command line arguments
  GetCommandLineArgs(argc,argv);

  // Init messenger and random number seed
  utils::app_init::MesgThresholds(RunOpt::Instance()->MesgThresholdFiles());
  utils::app_init::RandGen(gOptRanSeed);
  TRandom3 * rng3 = new TRandom3(0); // RETHERE change to GENIE rng!!

  // Initialize an Ntuple Writer to save GHEP records into a TTree
  NtpWriter ntpw(kDefOptNtpFormat, gOptRunNu);
  ntpw.CustomizeFilenamePrefix(gOptEvFilePrefix);
  ntpw.Initialize();

  // add another few branches. Mass, couplings, Majorana, type!
  ntpw.EventTree()->Branch("hnl_mass", &gOptHNLMass, "gOptHNLMass/D");
  ntpw.EventTree()->Branch("hnl_coup_e", &gOptECoupling, "gOptECoupling/D");
  ntpw.EventTree()->Branch("hnl_coup_mu", &gOptMuCoupling, "gOptMuCoupling/D");
  ntpw.EventTree()->Branch("hnl_ismaj", &gOptIsMajorana, "gOptIsMajorana/I");
  ntpw.EventTree()->Branch("hnl_type", &gOptHNLKind, "gOptHNLKind/I");

  // Create a MC job monitor for a periodically updated status file
  GMCJMonitor mcjmonitor(gOptRunNu);
  mcjmonitor.SetRefreshRate(RunOpt::Instance()->MCJobStatusRefreshRate());

  // Set GHEP print level
  GHepRecord::SetPrintLevel(RunOpt::Instance()->EventRecordPrintLevel());

  // Step 0: Get the HNL event generator
  // WIP!!!
  const EventRecordVisitorI * mcgen = HNLDecayGenerator();
  LOG("gevgen_hnl", pNOTICE)
    << " *** Got event generator! Good!";

  // Step 1: Seek out the fluxes
  // grab '''path''' but numu + numubar + nue + nuebar

  GFluxI * ff = TH1FluxDriver(); // creates an "input_flux.root" file with flux inside

  // ask the TH1FluxDriver which flux it used
  TFile f("./input-flux.root", "READ");
  //TH1D * spectrum = (TH1D *) f.Get("input_flux");
  TDirectory *baseDir = f.GetDirectory("");
  std::string fluxName = std::string( "spectrum" );
  assert( baseDir->GetListOfKeys()->Contains( fluxName.c_str() ) );
  TH1D * spectrum = ( TH1D * ) baseDir->Get( fluxName.c_str() );
  assert( spectrum );
  
  LOG("gevgen_hnl", pNOTICE)
    << " *** Flux routine executed! Good!";

  // Step 2: The event loop

  int ievent = 0;
  int dpdg = genie::kPdgHNL; int typeMod = 1;
  
  while (1)
  {
     if(ievent == gOptNev) break;

     LOG("gevgen_hnl", pNOTICE)
          << " *** Generating event............ " << ievent;

     // decide if this is nu / nubar. Does not matter if Majorana.
     if( !gOptIsMajorana ){
       if( gOptHNLKind == 0 ) typeMod = 1;
       else if( gOptHNLKind == 1 ) typeMod = -1;
       else{ // decide dynamically based on integrated fluxes
	 double athrow = rng3->Uniform( 0.0, 1.0 );
	 std::string integralsName = std::string( "hIntegrals" );
	 TH1D * hIntegrals = ( TH1D * ) baseDir->Get( integralsName.c_str() );
	 double posint = hIntegrals->GetBinContent(1) + hIntegrals->GetBinContent(3);
	 double negint = hIntegrals->GetBinContent(2) + hIntegrals->GetBinContent(4);
	 typeMod = ( athrow < posint / ( posint + negint ) ) ? 1 : -1;
	 
	 LOG( "gevgen_hnl", pDEBUG )
	   << "posint, negint, throw, typeMod = " << posint << ", " << negint << ", " << athrow << ", " << typeMod;
       }
     }

     dpdg *= typeMod;

     EventRecord * event = new EventRecord;
     int HNLprobe = SelectInitState() * typeMod;

     LOG( "gevgen_hnl", pDEBUG )
       << "HNLprobe = " << HNLprobe;

     // select decay mode
     // RETHERE force N --> pi + \ell
     int decay = -1;

     // RETHERE assuming all these HNL have K+- parent. This is wrong 
     // (but not very wrong for interesting masses)
     LOG("gevgen_hnl", pDEBUG)
       << " Building SimpleHNL object ";
     genie::HNL::SimpleHNL sh( "HNL", ievent, dpdg, genie::kPdgKP, 
			       gOptHNLMass, gOptECoupling, gOptMuCoupling, 0.0, false );
     
     LOG("gevgen_hnl", pDEBUG)
       << " Creating interesting channels vector ";
     std::vector< genie::HNL::enums::HNLDecay_t > * intChannels = new std::vector< genie::HNL::enums::HNLDecay_t >();
     intChannels->emplace_back( genie::HNL::enums::kPiE );
     intChannels->emplace_back( genie::HNL::enums::kPiMu );

     LOG("gevgen_hnl", pDEBUG)
       << " Getting valid channels ";
     const std::map< genie::HNL::enums::HNLDecay_t, double > gammaMap = sh.GetValidChannels();

     genie::HNL::enums::HNLDecay_t pimuDecay = genie::HNL::enums::kPiMu;
     auto pimuMapG  = gammaMap.find( pimuDecay );
     double pimuPG  = pimuMapG->second;

     genie::HNL::enums::HNLDecay_t pieDecay =  genie::HNL::enums::kPiE;
     auto pieMapG  = gammaMap.find( pieDecay );
     double piePG  = pieMapG->second;

     LOG("gevgen_hnl", pDEBUG)
       << "\n\n !!! ------------------------------------------- "
       << "\n !!! Here are the gammas of the interesting channels: "
       << "\n !!! Channel: pi mu . Gamma = " << pimuPG
       << "\n !!! Channel: pi e  . Gamma = " << piePG
       << "\n !!! ------------------------------------------- \n";

     LOG("gevgen_hnl", pDEBUG)
       << " Setting interesting channels map ";
     std::map< genie::HNL::enums::HNLDecay_t, double > intMap =
       genie::HNL::Selector::SetInterestingChannels( (*intChannels), gammaMap );
     
     LOG("gevgen_hnl", pDEBUG)
       << " Telling SimpleHNL about interesting channels ";
     sh.SetInterestingChannels( intMap );

     // get probability that channels in intChannels will be selected
     LOG("gevgen_hnl", pDEBUG)
       << " Building probablilities of interesting channels ";
     std::map< genie::HNL::enums::HNLDecay_t, double > PMap = 
       genie::HNL::Selector::GetProbabilities( intMap );

     // I want to see what these probabilities are.
     
     //genie::HNL::enums::HNLDecay_t pimuDecay = genie::HNL::enums::kPiMu;
     auto pimuMap  = PMap.find( pimuDecay );
     double pimuP  = pimuMap->second;

     //genie::HNL::enums::HNLDecay_t pieDecay =  genie::HNL::enums::kPiE;
     auto pieMap  = PMap.find( pieDecay );
     double pieP  = pieMap->second;

     LOG("gevgen_hnl", pDEBUG)
       << "\n\n !!! ------------------------------------------- "
       << "\n !!! Here are the probabilities of the interesting channels: "
       << "\n !!! Channel: pi mu . Prob = " << pimuP
       << "\n !!! Channel: pi e  . Prob = " << pieP
       << "\n !!! ------------------------------------------- \n";

     LOG("gevgen_hnl", pDEBUG)
       << "Doing random throw";
     
     // now do a random throw
     double ranThrow = rng3->Uniform( 0., 1. ); // HNL's fate is sealed.

     LOG("gevgen_hnl", pDEBUG)
       << "Random throw = " << ranThrow;

     genie::HNL::enums::HNLDecay_t selectedDecayChan =
       genie::HNL::Selector::SelectChannelInclusive( PMap, ranThrow );

     decay = ( int ) selectedDecayChan;

     LOG("gevgen_hnl", pDEBUG)
       << "Selected decay = " << decay;

     assert( decay == 0 || decay == 1 ); //RETHERE

     //int decay  = (int) genie::HNL::enums::kPiMu; // force N --> pi + mu.

     // select energy and build 4-momentum
     double EHNL = spectrum->GetRandom();
     
     double PHNL = std::sqrt( EHNL*EHNL - gOptHNLMass * gOptHNLMass );

     TLorentzVector p4HNL( 0.0, 0.0, PHNL, EHNL );

     // RETHERE this should not be NDecay (that tells app that we actually have NucleonDecay. We don't. RETHERE)
     Interaction * interaction = Interaction::HNLDecay(HNLprobe,decay,p4HNL);
     event->AttachSummary(interaction);

     // Simulate decay     
     mcgen->ProcessEventRecord(event);

     LOG("gevgen_hnl", pINFO)
         << "Generated event: " << *event;

     // Add event at the output ntuple, refresh the mc job monitor & clean-up
     ntpw.AddEventRecord(ievent, event);
     mcjmonitor.Update(ievent,event);
     delete event;

     ievent++;
  } // event loop

  LOG("gevgen_hnl", pDEBUG)
    << "Event loop finished.";

  // Save the generated event tree & close the output file
  ntpw.Save();

  LOG("gevgen_hnl", pNOTICE) << "Done!";

  return 0;
}
//_________________________________________________________________________________________
// This is supposed to resolve the correct flux file
// Open question: Do I want to invoke gevgen from within here? I'd argue not.
//............................................................................
#ifdef __CAN_GENERATE_EVENTS_USING_A_FLUX_OR_TGTMIX__
GFluxI * TH1FluxDriver(void)
{
  //
  //
  flux::GCylindTH1Flux * flux = new flux::GCylindTH1Flux;
  TH1D * spectrum = 0;

  int flux_entries = 100000;

  double emin = gOptNuEnergy;
  double emax = gOptNuEnergy+gOptNuEnergyRange;
  double de   = gOptNuEnergyRange;

  // read in mass of HNL and decide which fluxes to use
  
  assert(gOptHNLMass >= 0.0);
  assert(gOptHNLMass < 0.5); // mass is in GeV! Less than m_K0 ~= 0.497 GeV

  if(gOptHNLMass == 0.0){
    LOG("gevgen_hnl", pERROR) 
      << "You have picked a mass-0 HNL. You really should be using the standard GENIE executables that deal with SM nu."
      << "\nFunctionality currently not supported, exiting.";
    exit(0);
  }

  // select coupling configuration & mass point
  string coup = genie::HNL::FluxReader::selectCoup( gOptECoupling, gOptMuCoupling, 0.0 );

  LOG("gevgen_hnl", pDEBUG)
    << "Couplings inserted: e: " << gOptECoupling << ", mu: " << gOptMuCoupling
    << " ==> coupling configuration = " << coup.c_str();

  int closest_masspoint = genie::HNL::FluxReader::selectMass( gOptHNLMass );

  LOG("gevgen_hnl", pDEBUG)
    << "Mass inserted: " << gOptHNLMass << " GeV ==> mass point " << closest_masspoint;
  LOG("gevgen_hnl", pDEBUG)
    << "Using fluxes in base path " << gOptFluxFilePath.c_str();
  
  genie::HNL::FluxReader::selectFile( gOptFluxFilePath, gOptECoupling, gOptMuCoupling, 0., gOptHNLMass );
  string finPath = genie::HNL::FluxReader::fPath;
  LOG("gevgen_hnl", pDEBUG)
    << "Looking for fluxes in " << finPath.c_str();
  assert( !gSystem->AccessPathName( finPath.c_str()) );

  // extract specified flux histogram from input root file

  string hFluxName = Form( "hHNLFluxCenterAcc_%d", closest_masspoint );

  TH1F *hfluxAllMu    = genie::HNL::FluxReader::getFluxHist1F( finPath, hFluxName, genie::HNL::enums::kAll, genie::HNL::enums::kNumu );
  TH1F *hfluxAllMubar = genie::HNL::FluxReader::getFluxHist1F( finPath, hFluxName, genie::HNL::enums::kAll, genie::HNL::enums::kNumubar );
  TH1F *hfluxAllE     = genie::HNL::FluxReader::getFluxHist1F( finPath, hFluxName, genie::HNL::enums::kAll, genie::HNL::enums::kNue );
  TH1F *hfluxAllEbar  = genie::HNL::FluxReader::getFluxHist1F( finPath, hFluxName, genie::HNL::enums::kAll, genie::HNL::enums::kNuebar );

  assert(hfluxAllMu);
  assert(hfluxAllMubar);
  assert(hfluxAllE);
  assert(hfluxAllEbar);

  LOG("gevgen_hnl", pDEBUG)
    << "The histos have entries and max: "
    << "\nNumu:    " << hfluxAllMu->GetEntries() << " entries with max = " << hfluxAllMu->GetMaximum()
    << "\nNumubar: " << hfluxAllMubar->GetEntries() << " entries with max = " << hfluxAllMubar->GetMaximum()
    << "\nNue:     " << hfluxAllE->GetEntries() << " entries with max = " << hfluxAllE->GetMaximum()
    << "\nNuebar:  " << hfluxAllEbar->GetEntries() << " entries with max = " << hfluxAllEbar->GetMaximum();

  // let's build the mixed flux.
  // RETHERE - allow for graceful selection! Need an option for mix
  
  TH1F * spectrumF = (TH1F*) hfluxAllMu->Clone(0);

  if( gOptDoMasterMixing ){ // build master flux element from all flavours & all parents
    spectrumF->Add( hfluxAllMu, 1.0 );
    spectrumF->Add( hfluxAllMubar, 1.0 );
    spectrumF->Add( hfluxAllE, 1.0 );
    spectrumF->Add( hfluxAllEbar, 1.0 );
  }
  else{
    if( gOptECoupling == 0.0 ){ // no e coupling
      if( gOptIsMajorana || gOptHNLKind == 2 ){
	spectrumF->Add( hfluxAllMu, 1.0 );
	spectrumF->Add( hfluxAllMubar, 1.0 );
      }
      else if( gOptHNLKind == 0 ){
	spectrumF->Add( hfluxAllMu, 1.0 );
      }
      else{
	spectrumF->Add( hfluxAllMubar, 1.0 );
      }
    }
    else if( gOptMuCoupling == 0.0 ){ // no mu coupling
      if( gOptIsMajorana || gOptHNLKind == 2 ){
	spectrumF->Add( hfluxAllE, 1.0 );
	spectrumF->Add( hfluxAllEbar, 1.0 );
      }
      else if( gOptHNLKind == 0 ){
	spectrumF->Add( hfluxAllE, 1.0 );
      }
      else{
	spectrumF->Add( hfluxAllEbar, 1.0 );
      }
    }
    else{ // assumed equal coupling
      if( gOptIsMajorana || gOptHNLKind == 2 ){
	spectrumF->Add( hfluxAllMu, 1.0 );
	spectrumF->Add( hfluxAllMubar, 1.0 );
	spectrumF->Add( hfluxAllE, 1.0 );
	spectrumF->Add( hfluxAllEbar, 1.0 );
      }
      else if( gOptHNLKind == 0 ){
	spectrumF->Add( hfluxAllMu, 1.0 );
	spectrumF->Add( hfluxAllE, 1.0 );
      }
      else{
	spectrumF->Add( hfluxAllMubar, 1.0 );
	spectrumF->Add( hfluxAllEbar, 1.0 );
      }
    }
  }

  LOG( "gevgen_hnl", pDEBUG )
    << "\n\n !!! ------------------------------------------------"
    << "\n !!! Testing flux selection. Options are: "
    << "\n !!! gOptECoupling, gOptMuCoupling = " << gOptECoupling << ", " << gOptMuCoupling
    << "\n !!! gOptHNLKind = " << gOptHNLKind
    << "\n !!! gOptIsMajorana = " << gOptIsMajorana
    << "\n !!! ------------------------------------------------"
    << "\n !!! Flux spectrum has ** " << spectrumF->GetEntries() << " ** entries"
    << "\n !!! Flux spectrum has ** " << spectrumF->GetMaximum() << " ** maximum"
    << "\n !!! ------------------------------------------------ \n";

  // copy into TH1D, *do not use the Copy() function!*
  const int nbins = spectrumF->GetNbinsX();
  spectrum = new TH1D( "s", "s", nbins, spectrumF->GetBinLowEdge(1), 
		       spectrumF->GetBinLowEdge(nbins) + spectrumF->GetBinWidth(nbins) );
  for( Int_t ib = 0; ib <= nbins; ib++ ){
    spectrum->SetBinContent( ib, spectrumF->GetBinContent(ib) );
  }
  
  spectrum->SetNameTitle("spectrum","HNL_flux");
  spectrum->SetDirectory(0);
  for(int ibin = 1; ibin <= hfluxAllMu->GetNbinsX(); ibin++) {
    if(hfluxAllMu->GetBinLowEdge(ibin) + hfluxAllMu->GetBinWidth(ibin) > emax ||
       hfluxAllMu->GetBinLowEdge(ibin) < emin) {
      spectrum->SetBinContent(ibin, 0);
    }
  } // do I want to kill the overflow / underflow bins? Why?
  
  LOG("gevgen_hnl", pNOTICE) << spectrum->GetEntries() << " entries in spectrum";

  // RETHERE, VERY placeholder-y
  // pass this flux to FluxReader to sample from
  genie::HNL::FluxReader::setFluxHisto( spectrum );

  // save input flux

  TFile f("./input-flux.root","RECREATE");
  spectrum->Write();

  // store integrals in histo if not Majorana and mixed flux
  // usual convention: bin 0+1 ==> numu etc
  if( !gOptIsMajorana && gOptHNLKind == 2 ){
    TH1D * hIntegrals = new TH1D( "hIntegrals", "hIntegrals", 4, 0.0, 1.0 );
    hIntegrals->SetBinContent( 1, hfluxAllMu->Integral() );
    hIntegrals->SetBinContent( 2, hfluxAllMubar->Integral() );
    hIntegrals->SetBinContent( 3, hfluxAllE->Integral() );
    hIntegrals->SetBinContent( 4, hfluxAllEbar->Integral() );

    hIntegrals->SetDirectory(0);
    hIntegrals->Write();

    LOG( "gevgen_hnl", pDEBUG )
      << "\n\nIntegrals asked for and stored. Here are their values by type:"
      << "\nNumu: " << hfluxAllMu->Integral()
      << "\nNumubar: " << hfluxAllMubar->Integral()
      << "\nNue: " << hfluxAllE->Integral()
      << "\nNuebar: " << hfluxAllEbar->Integral() << "\n\n";
  }

  f.Close();
  LOG("gevgen_hnl", pDEBUG) 
    << "Written spectrum to ./input-flux.root";

  // before doing anything else, add HNL pdg code to PDGLibrary
  // otherwise the FluxDriver won't play ball
  AddHNLToPDGLibrary( gOptHNLPdgCode, gOptHNLMass, gOptECoupling, gOptMuCoupling);
  
  LOG("gevgen_hnl", pDEBUG) 
    << "Added HNL with |PDG code| " << gOptHNLPdgCode
    << " and mass " << gOptHNLMass << " GeV/c^{2} to PDGLibrary.";
  /*
  PDGCodeList * pcl( false );
  bool HNLExists = pcl->ExistsInPDGLibrary( gOptHNLPdgCode );
  if( !HNLExists ){
    AddHNLToPDGLibrary( gOptHNLPdgCode, gOptHNLMass, gOptECoupling, gOptMuCoupling);
    LOG("gevgen_hnl", pDEBUG) 
      << "Added HNL with PDG code " << gOptHNLPdgCode << " to PDGLibrary.";
  }
  else{
    LOG("gevgen_hnl", pDEBUG) 
      << "HNL with PDG code " << gOptHNLPdgCode << " exists in PDGLibrary.";
  }
  */

  // gevgen has these firing exactly on "z" (==beam?) direction at centre
  // let's keep this code for now before tinkering - FluxReader has capability to generate momenta
  // given input sample from fluxes

  TVector3 bdir (0.0,0.0,1.0);
  TVector3 bspot(0.0,0.0,1.0);

  flux->SetNuDirection      (bdir);
  flux->SetBeamSpot         (bspot);
  flux->SetTransverseRadius (-1);
  flux->AddEnergySpectrum   (gOptHNLPdgCode, spectrum);

  GFluxI * flux_driver = dynamic_cast<GFluxI *>(flux);
  return flux_driver;
}
//............................................................................
#endif // #ifdef __CAN_GENERATE_EVENTS_USING_A_FLUX_OR_TGTMIX__
//_________________________________________________________________________________________
void AddHNLToPDGLibrary( int pdgc, double mHNL, double Ue42, double Um42 )
{
  PDGLibrary *pdglib = PDGLibrary::Instance();
  pdglib->AddSimpleHNL( pdgc, mHNL, Ue42, Um42 );
}
//_________________________________________________________________________________________
const EventRecordVisitorI * HNLDecayGenerator(void)
{
  string sname   = "genie::EventGenerator";
  string sconfig = "HNLDecay";
  AlgFactory *algf = AlgFactory::Instance();
  const EventRecordVisitorI * mcgen = 
    dynamic_cast<const EventRecordVisitorI *> (algf->GetAlgorithm(sname,sconfig));
  if(!mcgen) {
    LOG("gevgen_hnl", pFATAL) << "Couldn't instantiate the HNL decay generator";
    exit(1);
  }
  return mcgen;
}
//_________________________________________________________________________________________
int SelectInitState(void){
  int dpdg = genie::kPdgHNL; // RETHERE fix this!
  
  return dpdg; // I return one HNL. This is WAY simple.
}
//_________________________________________________________________________________________
void GetCommandLineArgs(int argc, char ** argv)
{
  LOG("gevgen_hnl", pINFO) << "Parsing command line arguments";

  // Common run options. 
  RunOpt::Instance()->ReadFromCommandLine(argc,argv);

  // Parse run options for this app

  CmdLnArgParser parser(argc,argv);

  // help?
  bool help = parser.OptionExists('h');
  if(help) {
    PrintSyntax();
    exit(0);
  }

  // run number
  if( parser.OptionExists('r') ) {
    LOG("gevgen_hnl", pDEBUG) << "Reading MC run number";
    gOptRunNu = parser.ArgAsLong('r');
  } else {
    LOG("gevgen_hnl", pDEBUG) << "Unspecified run number - Using default";
    gOptRunNu = 1000;
  } //-r


  // number of events
  if( parser.OptionExists('n') ) {
    LOG("gevgen_hnl", pDEBUG) 
        << "Reading number of events to generate";
    gOptNev = parser.ArgAsInt('n');
  } else {
    LOG("gevgen_hnl", pFATAL) 
        << "You need to specify the number of events";
    PrintSyntax();
    exit(0);
  } //-n


  // co-produced lepton PDG
  if( parser.OptionExists('c') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading co-produced lepton PDG";
    gOptCpL = parser.ArgAsInt('c');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified co-produced lepton PDG - using default";
    gOptCpL = 14;
  } //-c

  // HNL mass
  if( parser.OptionExists('M') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading HNL mass";
    gOptHNLMass = parser.ArgAsDouble('M');
  } else {
    LOG("gevgen_hnl", pFATAL)
      << "You need to specify the HNL mass";
    PrintSyntax();
    exit(0);
  } //-M

  // HNL kind
  if( parser.OptionExists('k') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading HNL kind";
    gOptHNLKind = parser.ArgAsInt('k');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified HNL kind - using default";
    gOptHNLKind = 2;
  } //-k

  // is Majorana?
  if( parser.OptionExists('j') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading isMajorana";
    gOptIsMajorana = parser.ArgAsInt('j');
    if( gOptIsMajorana == true ) {
      LOG("gevgen_hnl", pDEBUG)
	<< "HNL is Majorana - setting HNL kind to default mixed state"
	<< "\n This overrides the -k setting!";
      gOptHNLKind = 2;
    }
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified isMajorana - using default";
    gOptIsMajorana = false;
  } //-j

  // do master mixing?
  if( parser.OptionExists('q') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading doMasterMixing";
    gOptDoMasterMixing = parser.ArgAsInt('q');
    if( gOptDoMasterMixing == true ) {
      LOG("gevgen_hnl", pDEBUG)
	<< "Using master mixing. All flavours together will be sampled.";
    } else {
      LOG("gevgen_hnl", pDEBUG)
	<< "Not doing master mixing.";
    }
  } //-q

  // |U_e4|^2
  if( parser.OptionExists('e') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading eCoupling";
    gOptECoupling = parser.ArgAsDouble('e');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified eCoupling - using default";
    gOptECoupling = 1.0;
  } //-e

  // |U_mu4|^2
  if( parser.OptionExists('m') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading muCoupling";
    gOptMuCoupling = parser.ArgAsDouble('m');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified muCoupling - using default";
    gOptMuCoupling = 1.0;
  } //-m

  // flux file path
  if( parser.OptionExists('f') ) {
    LOG("gevgen_hnl", pDEBUG)
      << "Reading path to flux files";
    // TODO: check that flux files exist, throw exception if not!
    gOptFluxSpecPath = parser.ArgAsString('f');
    gOptFluxFilePath = kDefGENIELocation + '/' + gOptFluxSpecPath;
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified path to flux files - using default";
    gOptFluxFilePath = kDefOptFluxFilePath;
  } //-f

  //
  // energy range
  //

  // neutrino energy
  if( parser.OptionExists('E') ) {
    LOG("gevgen_hnl", pINFO) << "Reading neutrino energy";
    string nue = parser.ArgAsString('E');

    // is it just a value or a range (comma separated set of values)
    if(nue.find(",") != string::npos) {
       // split the comma separated list
       vector<string> nurange = utils::str::Split(nue, ",");
       assert(nurange.size() == 2);   
       double emin = atof(nurange[0].c_str());
       double emax = atof(nurange[1].c_str());
       assert(emax>emin && emin>=0);
       gOptNuEnergy      = emin;
       gOptNuEnergyRange = emax-emin;
    } else {
       gOptNuEnergy       = atof(nue.c_str());
       gOptNuEnergyRange = -1;
    }
  } else {
    LOG("gevgen_hnl", pFATAL) << "Unspecified neutrino energy - Exiting";
    PrintSyntax();
    exit(1);
  } //-E

  //
  // geometry
  //

  string geom = "";
  string lunits, dunits;
  if( parser.OptionExists('g') ) {
    LOG("gevgen_hnl", pDEBUG) << "Getting input geometry";
    geom = parser.ArgAsString('g');

    // is it a ROOT file that contains a ROOT geometry?
    bool accessible_geom_file = 
            ! (gSystem->AccessPathName(geom.c_str()));
    if (accessible_geom_file) {
      gOptRootGeom      = geom;
      gOptUsingRootGeom = true;
    }                 
  } else {
      LOG("gevgen_hnl", pFATAL) 
        << "No geometry option specified - Exiting";
      PrintSyntax();
      exit(1);
  } //-g

  if(gOptUsingRootGeom) {
     // using a ROOT geometry - get requested geometry units

     // legth units:
     if( parser.OptionExists('L') ) {
        LOG("gevgen_hnl", pDEBUG) 
           << "Checking for input geometry length units";
        lunits = parser.ArgAsString('L');
     } else {
        LOG("gevgen_hnl", pDEBUG) << "Using default geometry length units";
        lunits = kDefOptGeomLUnits;
     } // -L
     // density units:
     if( parser.OptionExists('D') ) {
        LOG("gevgen_hnl", pDEBUG) 
           << "Checking for input geometry density units";
        dunits = parser.ArgAsString('D');
     } else {
        LOG("gevgen_hnl", pDEBUG) << "Using default geometry density units";
        dunits = kDefOptGeomDUnits;
     } // -D 
     gOptGeomLUnits = utils::units::UnitFromString(lunits);
     gOptGeomDUnits = utils::units::UnitFromString(dunits);

     // check whether an event generation volume name has been 
     // specified -- default is the 'top volume'
     if( parser.OptionExists('t') ) {
        LOG("gevgen_hnl", pDEBUG) << "Checking for input volume name";
        gOptRootGeomTopVol = parser.ArgAsString('t');
     } else {
        LOG("gevgen_hnl", pDEBUG) << "Using the <master volume>";
     } // -t 

  } // using root geom?

  else {
    // User has specified a target mix.
    // Decode the list of target pdf codes & their corresponding weight fraction
    // (specified as 'pdg_code_1[fraction_1],pdg_code_2[fraction_2],...')
    // See documentation on top section of this file.
    //
    gOptTgtMix.clear();
    vector<string> tgtmix = utils::str::Split(geom,",");
    if(tgtmix.size()==1) {
         int    pdg = atoi(tgtmix[0].c_str());
         double wgt = 1.0;
         gOptTgtMix.insert(map<int, double>::value_type(pdg, wgt));    
    } else {
      vector<string>::const_iterator tgtmix_iter = tgtmix.begin();
      for( ; tgtmix_iter != tgtmix.end(); ++tgtmix_iter) {
         string tgt_with_wgt = *tgtmix_iter;
         string::size_type open_bracket  = tgt_with_wgt.find("[");
         string::size_type close_bracket = tgt_with_wgt.find("]");
         if (open_bracket ==string::npos || 
             close_bracket==string::npos) 
         {
             LOG("gevgen_hnl", pFATAL) 
                << "You made an error in specifying the target mix"; 
             PrintSyntax();
             exit(1);
         }
         string::size_type ibeg = 0;
         string::size_type iend = open_bracket;
         string::size_type jbeg = open_bracket+1;
         string::size_type jend = close_bracket;
         int    pdg = atoi(tgt_with_wgt.substr(ibeg,iend-ibeg).c_str());
         double wgt = atof(tgt_with_wgt.substr(jbeg,jend-jbeg).c_str());
         LOG("gevgen_hnl", pDEBUG) 
            << "Adding to target mix: pdg = " << pdg << ", wgt = " << wgt;
         gOptTgtMix.insert(map<int, double>::value_type(pdg, wgt));

      }// tgtmix_iter
    } // >1 materials in mix
  } // using tgt mix?

  // event file prefix
  if( parser.OptionExists('o') ) {
    LOG("gevgen_hnl", pDEBUG) << "Reading the event filename prefix";
    gOptEvFilePrefix = parser.ArgAsString('o');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Will set the default event filename prefix";
    gOptEvFilePrefix = kDefOptEvFilePrefix;
  } //-o


  // random number seed
  if( parser.OptionExists("seed") ) {
    LOG("gevgen_hnl", pINFO) << "Reading random number seed";
    gOptRanSeed = parser.ArgAsLong("seed");
  } else {
    LOG("gevgen_hnl", pINFO) << "Unspecified random number seed - Using default";
    gOptRanSeed = -1;
  }

  //
  // >>> print the command line options
  //

  PDGLibrary * pdglib = PDGLibrary::Instance();

  ostringstream gminfo;
  if (gOptUsingRootGeom) {
    gminfo << "Using ROOT geometry - file: " << gOptRootGeom
           << ", top volume: "
           << ((gOptRootGeomTopVol.size()==0) ? "<master volume>" : gOptRootGeomTopVol)
           << ", length  units: " << lunits
           << ", density units: " << dunits;
  } else {
    gminfo << "Using target mix - ";
    map<int,double>::const_iterator iter;
    for(iter = gOptTgtMix.begin(); iter != gOptTgtMix.end(); ++iter) {
          int    pdg_code = iter->first;
          double wgt      = iter->second;
          TParticlePDG * p = pdglib->Find(pdg_code);
          if(p) {
            string name = p->GetName();
            gminfo << "(" << name << ") -> " << 100*wgt << "% / ";
          }//p?
    }
  }

  LOG("gevgen_hnl", pNOTICE)
     << "\n\n"
     << utils::print::PrintFramedMesg("gevgen_hnl job configuration");

  LOG("gevgen_hnl", pNOTICE) 
     << "\n @@ Run number: " << gOptRunNu
     << "\n @@ Random number seed: " << gOptRanSeed
     << "\n @@ Geometry      $ " << gminfo.str()
     << "\n @@ Statistics    $ " << gOptNev << " events";

  //
  // Temporary warnings...
  //
  if(gOptUsingRootGeom) {
     LOG("gevgen_hnl", pWARN) 
        << "\n ** ROOT geometries not supported yet in the HNL mode"
        << "\n ** (they will be in the very near future)"
        << "\n ** Please specify a `target mix' instead.";
     gAbortingInErr = true;
     exit(1);
  }
}
//_________________________________________________________________________________________
void PrintSyntax(void)
{
  LOG("gevgen_hnl", pFATAL) 
   << "\n **Syntax**"
   << "\n gevgen_hnl [-h] "
   << "\n            [-r run#]"
   << "\n             -n n_of_events"
   << "\n            [-c coproduced_lepton_pdg]"
   << "\n             -M HNL_mass"
   << "\n            [-k HNL_kind]"
   << "\n            [-j isMajorana]"
   << "\n            [-q doMasterMixing]"
   << "\n            [-e eCoupling]"
   << "\n            [-m muCoupling]"
   << "\n            [-f path/to/flux/file]"
   << "\n             -E energy_range"
   << "\n             -g geometry"
   << "\n            [-t top_volume_name_at_geom]"
   << "\n            [-L length_units_at_geom]"
   << "\n            [-D density_units_at_geom]"
   << "\n            [-o output_event_file_prefix]"
   << "\n            [--seed random_number_seed]"
   << "\n            [--message-thresholds xml_file]"
   << "\n            [--event-record-print-level level]"
   << "\n            [--mc-job-status-refresh-rate  rate]"
   << "\n"
   << " Please also look at the source code: $GENIE/src/Apps/gHNLEvGen.cxx"
   << "\n";
}
