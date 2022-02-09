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
	   -e
	      Electron-like coupling |U_e4|^2. Assumes \sum_{\ell} |U_\ell 4|^2 = 1.
	   -m
	      Muon-like coupling |U_mu4|^2. Assumes \sum_{\ell} |U_\ell 4|^2 = 1.

	   -f
	      Path to (non-standard) input flux file
	      If user does not give this input, search from suite of standard fluxes
	      to be included with this application

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
#include "PDG/PDGCodes.h"
#include "PDG/PDGUtils.h"
#include "PDG/PDGLibrary.h"
#include "SimpleHNL/DummyHNLInteractionListGenerator.h"
#include "SimpleHNL/HNLDecayer.h"
#include "SimpleHNL/SimpleHNL.h"
#include "Utils/StringUtils.h"
#include "Utils/UnitUtils.h"
#include "Utils/PrintUtils.h"
#include "Utils/AppInit.h"
#include "Utils/RunOpt.h"
#include "Utils/CmdLnArgParser.h"

using std::string;
using std::vector;
using std::ostringstream;

using namespace genie;

// function prototypes
void  GetCommandLineArgs ( int argc, char ** argv );
void  PrintSyntax        ( void );
int   SelectInitState    ( void ); // how am I gonna define this? 1 HNL?
const EventRecordVisitorI * HNLDecayGenerator ( void );

//
string          kDefOptGeomLUnits   = "mm";    // default geometry length units
string          kDefOptGeomDUnits   = "g_cm3"; // default geometry density units
NtpMCFormat_t   kDefOptNtpFormat    = kNFGHEP; // default event tree format   
string          kDefOptEvFilePrefix = "gntp";
string          kDefOptFluxFilePath = "${GENIE}/data/flux/HNL/";

//
Long_t             gOptRunNu        = 1000;                // run number
int                gOptNev          = 10;                  // number of events to generate
int                gOptCpL          = 14;                  // co-produced lepton PDG
double             gOptHNLMass      = 0.255;               // HNL mass
int                gOptHNLKind      = 2;                   // HNL kind. 0 = nu, 1 = nubar, 2 = mix
bool               gOptIsMajorana   = false;               // Is Majorana? True ==> HNL kind set to 0
double             gOptECoupling    = 1.0;                 // |U_e4|^2
double             gOptMuCoupling   = 1.0;                 // |U_mu4|^2
string             gOptFluxFilePath = kDefOptFluxFilePath; // path to flux files
string             gOptEvFilePrefix = kDefOptEvFilePrefix; // event file prefix
bool               gOptUsingRootGeom = false;              // using root geom or target mix?
map<int,double>    gOptTgtMix;                             // target mix  (tgt pdg -> wght frac) / if not using detailed root geom
string             gOptRootGeom;                           // input ROOT file with realistic detector geometry
string             gOptRootGeomTopVol = "";                // input geometry top event generation volume 
double             gOptGeomLUnits = 0;                     // input geometry length units 
double             gOptGeomDUnits = 0;                     // input geometry density units 
long int           gOptRanSeed = -1;                       // random number seed

//_________________________________________________________________________________________
int main(int argc, char ** argv)
{
  // Parse command line arguments
  GetCommandLineArgs(argc,argv);

  // Init messenger and random number seed
  utils::app_init::MesgThresholds(RunOpt::Instance()->MesgThresholdFiles());
  utils::app_init::RandGen(gOptRanSeed);

  // Initialize an Ntuple Writer to save GHEP records into a TTree
  NtpWriter ntpw(kDefOptNtpFormat, gOptRunNu);
  ntpw.CustomizeFilenamePrefix(gOptEvFilePrefix);
  ntpw.Initialize();

  // Create a MC job monitor for a periodically updated status file
  GMCJMonitor mcjmonitor(gOptRunNu);
  mcjmonitor.SetRefreshRate(RunOpt::Instance()->MCJobStatusRefreshRate());

  // Set GHEP print level
  GHepRecord::SetPrintLevel(RunOpt::Instance()->EventRecordPrintLevel());

  // Step 0: Get the HNL event generator
  // WIP!!!
  // const EventRecordVisitorI * mcgen = HNLDecayGenerator();

  // Event loop
  int ievent = 0;

  // Step cop-out: print a 'Hello World'
  LOG("gevgen_hnl", pNOTICE)
    << " *** Hello world!";
  exit(0);

  // Step 1: Seek out the fluxes
  // grab '''path''' but numu + numubar + nue + nuebar

  // Step 2: Weight + add fluxes

  /*
  while (1)
  {
  // Step 3: Figure out what gets called when, in the event loop.
  
     if(ievent == gOptNev) break;

     LOG("gevgen_hnl", pNOTICE)
          << " *** Generating event............ " << ievent;

     EventRecord * event = new EventRecord;
     int target = SelectInitState();
     int decay  = (int)gOptDecayMode;
     Interaction * interaction = Interaction::NDecay(target,decay,dpdg);
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
  */

  // Save the generated event tree & close the output file
  ntpw.Save();

  LOG("gevgen_hnl", pNOTICE) << "Done!";

  return 0;
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
    gOptFluxFilePath = parser.ArgAsString('f');
  } else {
    LOG("gevgen_hnl", pDEBUG)
      << "Unspecified path to flux files - using default";
    gOptFluxFilePath = kDefOptFluxFilePath;
  } //-f

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
   << "\n            [-e eCoupling]"
   << "\n            [-m muCoupling]"
   << "\n            [-f path/to/flux/file]"
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
//_________________________________________________________________________________________

