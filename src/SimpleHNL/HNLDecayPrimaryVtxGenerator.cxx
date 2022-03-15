//____________________________________________________________________________
/*
  Implementation file for HNLDecayPrimaryVtxGenerator.h

*/
//____________________________________________________________________________

#include "Algorithm/AlgFactory.h"
#include "Conventions/Controls.h"
#include "Conventions/Constants.h"
#include "Conventions/GMode.h"
#include "Interaction/Target.h"
#include "Messenger/Messenger.h"
#include "Numerical/RandomGen.h"
#include "EVGCore/EVGThreadException.h"
#include "GHEP/GHepRecord.h"
#include "GHEP/GHepParticle.h"
#include "PDG/PDGCodes.h"
#include "PDG/PDGUtils.h"
#include "PDG/PDGLibrary.h"
#include "Utils/NuclearUtils.h"
#include "Utils/PrintUtils.h"
#include "SimpleHNL/HNLDecayPrimaryVtxGenerator.h"

#include "Interfaces/NuclearModelI.h"
//#include "NucleonDecay/NucleonDecayUtils.h"
#include "SimpleHNL/Enums.h"

using namespace genie;

//____________________________________________________________________________
HNLDecayPrimaryVtxGenerator::HNLDecayPrimaryVtxGenerator() :
EventRecordVisitorI("genie::HNLDecayPrimaryVtxGenerator")
{

}
//____________________________________________________________________________
HNLDecayPrimaryVtxGenerator::HNLDecayPrimaryVtxGenerator(
  string config) :
EventRecordVisitorI("genie::HNLDecayPrimaryVtxGenerator",config)
{

}
//____________________________________________________________________________
HNLDecayPrimaryVtxGenerator::~HNLDecayPrimaryVtxGenerator() 
{

}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::ProcessEventRecord(
		     GHepRecord * event ) const
{
  Interaction * interaction = event->Summary();
  //fCurrInitStatePdg = interaction->InitState().Tgt().Pdg();
  fCurrInitStatePdg = interaction->InitState().ProbePdg();
  fCurrDecayMode = (genie::HNL::enums::HNLDecay_t) interaction->ExclTag().DecayMode();
  XclsTag exclTag = interaction->ExclTag();
  exclTag.SetHNL();
  interaction->SetExclTag(exclTag);
  //fCurrDecayedHNL = interaction->InitState().Tgt().HitNucPdg();

  LOG("SimpleHNL", pNOTICE)
    << "Simulating decay with fCurrDecayMode = " << fCurrDecayMode 
    << " for an initial state with code: " << fCurrInitStatePdg;

  //fNucleonIsBound = (pdg::IonPdgCodeToA(fCurrInitStatePdg) > 1);

  double EHNL = interaction->InitState().ProbeE(kRfLab);

  this->AddInitialState(event);
  this->GenerateDecayedHNLPosition(event);
  //this->GenerateFermiMomentum(event);
  this->GenerateDecayProducts(event, EHNL);
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::GetEnergyFromFlux() const
{
  if( fEnergy != 0.0 ) return;
  if( genie::HNL::FluxReader::fMasterFlux ){
    fEnergy = genie::HNL::FluxReader::getEFromMaster();
    return;
  }
  
  LOG("SimpleHNL", pERROR)
    << "No master flux set in FluxReader. Things would go wrong. Exiting!";
  exit(1);
  
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::AddInitialState(
	          GHepRecord * event) const
{
//
// Add initial state in the event record.
//
// An HNL is always free, so the event record is initialised thus:
//    id: 0, HNL (kIStInitialState)
//    |
//    |---> id: 1, hadron (kIStStableFinalState)
//    |
//    |---> id: 2, charged lepton (kIStStableFinalState)
//
// I am starting with only 2-body decays N --> pi \ell. This will (should!) change.
//

  TLorentzVector v4(0,0,0,0);

  // if couplings haven't been set, set them!
  if( fUe42 == -1.0 && fUm42 == -1.0 ){
    // read couplings as "vertex coordinates" from event
    SetHNLCouplings( event->Vertex()->X(), event->Vertex()->Y() );
  }

  // let's query *where* the HNL decayed from.
  // RETHERE - perhaps should return to GCylindTH1Flux-like implementation?
  if( !fProdVtxHist || fProdVtxHist == 0 ){
    std::string pvPath = "data/flux/HNL/HNL_vertex_positions.root";
    std::string pvName = "hHNLVtxPos";
    fProdVtxHist = genie::HNL::FluxReader::getFluxHist3D( pvPath, pvName,
							  genie::HNL::enums::kAll,
							  genie::HNL::enums::kNumu ); // last 2 dummy args! Gotta refactor this
  }
  assert( fProdVtxHist );
  LOG( "SimpleHNL", pDEBUG )
    << "Found production vertex histo with " << fProdVtxHist->GetEntries() << " entries. Good!";

  GHepStatus_t stis = kIStInitialState;
  GHepStatus_t stdc = kIStDecayedState;
  GHepStatus_t stfs = kIStStableFinalState;

  // Initial state knows about an HNL
  int ipdg = fCurrInitStatePdg;

  // add initial HNL
  double mn  = PDGLibrary::Instance()->Find(ipdg)->Mass();
  TLorentzVector p4i(0,0,0,mn);
  Interaction * interaction = event->Summary();
  TLorentzVector * p4HNL = interaction->InitState().GetProbeP4( kRfLab );
  
  event->AddParticle(ipdg,stis,-1,-1,-1,-1, *p4HNL, v4);

  LOG( "SimpleHNL", pNOTICE )
    << "Added initial state.";
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::GenerateDecayedHNLPosition(
  GHepRecord * event) const
{
  TLorentzVector v4(0,0,0,0);

  std::vector< double > * prodVtx = genie::HNL::FluxReader::generateVtx3X( fProdVtxHist );
  LOG( "SimpleHNL", pDEBUG )
    << "Production vertex at: ( " << prodVtx->at(0) << ", " << prodVtx->at(1) << ", " << prodVtx->at(2) << ") [cm]";
  
  /*
  std::vector< double > * dummyProdVtx = new std::vector< double >();
  dummyProdVtx->emplace_back( 0.0 );
  dummyProdVtx->emplace_back( 0.0 );
  const double gSigma = 2.0; // deg
  dummyProdVtx->emplace_back( -100.0 / std::tan( gSigma * genie::constants::kPi / 180.0 ) ); //cm

  LOG( "SimpleHNL", pDEBUG )
    << "Dummy production vertex at: ( " << dummyProdVtx->at(0) << ", " << dummyProdVtx->at(1) << ", " << dummyProdVtx->at(2) << " ) [cm]";
  */

  Interaction * interaction = event->Summary();
  TLorentzVector * p4HNL = interaction->InitState().GetProbeP4( kRfLab );
  
  std::vector< double > * p3HNL = new std::vector< double >();
  p3HNL->emplace_back( p4HNL->Px() );
  p3HNL->emplace_back( p4HNL->Py() );
  p3HNL->emplace_back( p4HNL->Pz() );

  LOG( "SimpleHNL", pDEBUG )
    << "Momentum vector reads ( " << p3HNL->at(0) << ", " 
    << p3HNL->at(1) << ", " << p3HNL->at(2) << " ) [GeV/c]";

  // let's find out if this intersects the ID.
  std::vector< double > * entryPoint = genie::HNL::MINERvAGeom::GetEntryPointID( prodVtx, p3HNL );
  std::vector< double > * exitPoint = 0;

  bool didEnterID = ( entryPoint->at(3) >= -100.0 );

  int nTries = 1; // how many tries did it take to get an HNL that enters the detector?
  while( !didEnterID ){
    nTries++;
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL would not enter the detector. Generating new production vertex...";
    prodVtx = genie::HNL::FluxReader::generateVtx3X( fProdVtxHist );
    entryPoint = genie::HNL::MINERvAGeom::GetEntryPointID( prodVtx, p3HNL );
    didEnterID = ( entryPoint->at(3) >= -100.0 );
  }
  LOG( "SimpleHNL", pDEBUG )
    << "It took " << nTries << " tries to make a detector-intersecting trajectory.";

  if( didEnterID ) exitPoint = genie::HNL::MINERvAGeom::GetExitPointID( prodVtx, p3HNL );
  bool didExitID = didEnterID;
  if( didEnterID ) didExitID *= ( exitPoint->at(3) >= -100.0 );

  assert( !didEnterID || ( didEnterID && didExitID ) ); // either you don't hit the ID, or you enter and exit.

  // create a SimpleHNL object to use Stepper's PropagateTilDecay function
  // This uniquely determines *where* the decay vertex is
  
  genie::HNL::SimpleHNL sh = genie::HNL::SimpleHNL( "HNL", -1, genie::kPdgHNL, genie::kPdgKP, p4HNL->M(), fUe42, fUm42, 0.0, false );
  std::vector< double > prod4Vtx = { 0.0, prodVtx->at(0), prodVtx->at(1), prodVtx->at(2) };
  std::vector< double > prod4P = { p4HNL->E(), p4HNL->Px(), p4HNL->Py(), p4HNL->Pz() };
  
  sh.SetProdVtx( prod4Vtx );
  sh.Set4Momentum( prod4P );
  
  std::vector< double > dec4VX = genie::HNL::Selector::PropagateTilDecay( sh ); // decay vertex set here
  TLorentzVector dec4V( dec4VX.at(1), dec4VX.at(2), dec4VX.at(3), dec4VX.at(0) );
  event->SetVertex( dec4V );

  LOG( "SimpleHNL", pNOTICE ) 
    << "Generated HNL decay vertex position at \n(x,y,z,t)  = ( "
    << dec4V.Px() << ", " << dec4V.Py() << ", " << dec4V.Pz() << ", " << dec4V.E() << " ) [cm, ns]"
    << "\n(x,y,z,t) != ( " << dec4VX.at(1) << ", " << dec4VX.at(2) << ", " << dec4VX.at(3) << ", " << dec4VX.at(0) << " ) [cm, ns]";

  double distBeforeDet = 0.0, distInsideDet = 0.0;
  double timeBeforeDet = 0.0, timeInsideDet = 0.0;
  double restBeforeDet = 0.0, restInsideDet = 0.0;

  double weight = 1.0;

  if( didEnterID ){
    // find out distance between production vertex and entry/exit points
    distBeforeDet = std::sqrt( std::pow( (prodVtx->at(0) - entryPoint->at(0)*100.0), 2.0 ) +
			       std::pow( (prodVtx->at(1) - entryPoint->at(1)*100.0), 2.0 ) +
			       std::pow( (prodVtx->at(2) - entryPoint->at(2)*100.0), 2.0 ) ); // cm
    distInsideDet = std::sqrt( std::pow( (exitPoint->at(0)*100.0 - entryPoint->at(0)*100.0), 2.0 ) +
			       std::pow( (exitPoint->at(1)*100.0 - entryPoint->at(1)*100.0), 2.0 ) +
			       std::pow( (exitPoint->at(2)*100.0 - entryPoint->at(2)*100.0), 2.0 ) ); // cm
    timeBeforeDet = distBeforeDet / sh.GetBeta() * genie::units::cm / 
      ( genie::units::ns * genie::constants::kLightSpeed ); // lab-frame ToF
    timeInsideDet = distInsideDet / sh.GetBeta() * genie::units::cm / 
      ( genie::units::ns * genie::constants::kLightSpeed );
    restBeforeDet = timeBeforeDet / sh.GetGamma();
    restInsideDet = timeInsideDet / sh.GetGamma();
    
    LOG( "SimpleHNL", pDEBUG )
      << "distBeforeDet, distInsideDet = " << distBeforeDet << ", " << distInsideDet << " [cm]";
    
    LOG( "SimpleHNL", pDEBUG )
      << "\nBefore entering detector this HNL travelled \nfrom ( " << prodVtx->at(0) << ", "
      << prodVtx->at(1) << ", " << prodVtx->at(2) << " ) to ( " << entryPoint->at(0)*100.0 << ", " 
      << entryPoint->at(1)*100.0 << ", " << entryPoint->at(2)*100.0 
      << " ) [cm] \nwith beta = " << sh.GetBeta()
      << ", giving time-of-flight = " << timeBeforeDet << " [ns] (LAB)"
      << " = " << restBeforeDet << " [ns] (REST)";
    
    LOG( "SimpleHNL", pDEBUG )
      << "\nAfter  entering detector this HNL travelled \nfrom ( " << entryPoint->at(0)*100.0 << ", "
      << entryPoint->at(1)*100.0 << ", " << entryPoint->at(2)*100.0 
      << " ) to ( " << exitPoint->at(0)*100.0 << ", " 
      << exitPoint->at(1)*100.0 << ", " << exitPoint->at(2)*100.0
      << " ) [cm] \nwith beta = " << sh.GetBeta()
      << ", giving time-of-flight = " << timeInsideDet << " [ns] (LAB)"
      << " = " << restInsideDet << " [ns] (REST)";

    // calculate weight from this decay
    double totalWidth = genie::HNL::Selector::GetTotalDecayWidth( sh.GetValidChannels() ); // GeV
    totalWidth *= genie::units::GeV * genie::units::ns; // ns^{-1}
    LOG( "SimpleHNL", pDEBUG )
      << "From " << (sh.GetValidChannels()).size() << " channels the total width in ns^{-1} is: "
      << totalWidth;
    weight = std::exp( -totalWidth * restBeforeDet ); // probability to survive until detector
    double survProb = weight;
    LOG( "SimpleHNL", pDEBUG )
      << "Survival probability with beta, gamma, Gamma, d = " << sh.GetBeta() << ", "
      << sh.GetGamma() << ", " << totalWidth << ", " << distBeforeDet 
      << " is: " << survProb;
    weight *= ( 1.0 - std::exp( -totalWidth * restInsideDet ) ); // probability to decay in detector
    double decayProb = weight / survProb;
    LOG( "SimpleHNL", pDEBUG )
      << "Decay probability with beta, gamma, Gamma, l = " << sh.GetBeta() << ", "
      << sh.GetGamma() << ", " << totalWidth << ", " << distInsideDet
      << " is : " << decayProb;
  }

  LOG( "SimpleHNL", pDEBUG )
    << "Setting weight = " << weight;
  event->SetWeight( weight );

  return;
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::GenerateDecayProducts(
			GHepRecord * event, double EHNL ) const
{
  LOG("SimpleHNL", pINFO) << "Generating decay...";

  /*
  PDGCodeList pdgv = utils::nucleon_decay::DecayProductList(fCurrDecayMode, fCurrDecayedNucleon);
  LOG("NucleonDecay", pINFO) << "Decay product IDs: " << pdgv;
  assert ( pdgv.size() >  1);
  */

  // Step 0: Manually put the decay products into a PDGCodeList based on decay mode

  PDGCodeList pdgv( false );
  int typeMod = ( fCurrInitStatePdg > 0 ) ? 1 : -1;

  // vector of known (i.e. implemented) decays
  std::vector< genie::HNL::enums::HNLDecay_t > knownDecays;
  knownDecays.emplace_back( genie::HNL::enums::kPiMu );
  knownDecays.emplace_back( genie::HNL::enums::kPiE );
  knownDecays.emplace_back( genie::HNL::enums::kPi0Nu );

  bool decayIsKnown = ( std::find( std::begin( knownDecays ), std::end( knownDecays ), fCurrDecayMode )
			!= std::end( knownDecays ) ) ;
  if( !decayIsKnown ){
    LOG( "SimpleHNL", pFATAL )
      << "Unknown decay! I will crash now, and you should either implement this decay or switch it off.";
  }
  assert( decayIsKnown );
  
  if( fCurrDecayMode == genie::HNL::enums::kPiMu || fCurrDecayMode == genie::HNL::enums::kPiE ){
    pdgv.push_back( typeMod * genie::kPdgPiP ); // all 2 decay modes do this
  }
  else if( fCurrDecayMode == genie::HNL::enums::kPi0Nu ){
    pdgv.push_back( genie::kPdgPi0 ); // pi0 is its own antiparticle
  }
  
  if( fCurrDecayMode == genie::HNL::enums::kPiMu ) pdgv.push_back( typeMod * genie::kPdgMuon );
  else if( fCurrDecayMode == genie::HNL::enums::kPiE ) pdgv.push_back( typeMod * genie::kPdgElectron );
  else if( fCurrDecayMode == genie::HNL::enums::kPi0Nu ) pdgv.push_back( typeMod * genie::kPdgNuMu );

  //assert( fCurrDecayMode == genie::HNL::enums::kPiMu ||
  //	  fCurrDecayMode == genie::HNL::enums::kPiE ); // force 2-body decay

  //I *could* do this, or I could actually implement the custom 3-body decays
  //inside SimpleHNL.
  //LOG("NucleonDecay", pINFO) << "Performing a phase space decay...";
  LOG("SimpleHNL", pINFO)
    << "Performing the decay...";

  // Step 1: Get the decay product masses

  vector<int>::const_iterator pdg_iter;
  int i = 0;
  double * mass = new double[pdgv.size()];
  double   sum  = 0;
  for(pdg_iter = pdgv.begin(); pdg_iter != pdgv.end(); ++pdg_iter) {
    int pdgc = *pdg_iter;
    double m = PDGLibrary::Instance()->Find(pdgc)->Mass();
    mass[i++] = m;
    sum += m;
  }

  LOG("SimpleHNL", pINFO)  
    << "Decaying N = " << pdgv.size() << " particles / total mass = " << sum;

  int decayed_HNL_id = 0;
  GHepParticle * decayed_HNL = event->Particle(decayed_HNL_id);
  assert(decayed_HNL);
  TLorentzVector * p4d = decayed_HNL->GetP4(); // should be (M,\vec{0})...
  TLorentzVector * v4d = decayed_HNL->GetX4(); // should ve \vec{0} \in R^4...

  LOG("SimpleHNL", pINFO) 
    << "Decaying system p4 = " << utils::print::P4AsString(p4d);

  // Set the decay
  bool permitted = fPhaseSpaceGenerator.SetDecay(*p4d, pdgv.size(), mass);
  if(!permitted) {
     LOG("SimpleHNL", pERROR) 
       << " *** Phase space decay is not permitted \n"
       << " Total particle mass = " << sum << "\n"
       << " Decaying system p4 = " << utils::print::P4AsString(p4d);
     // clean-up 
     delete [] mass;
     delete p4d;
     delete v4d; 
     // throw exception
     genie::exceptions::EVGThreadException exception;
     exception.SetReason("Decay not permitted kinematically");
     exception.SwitchOnFastForward();
     throw exception;
  }

  LOG("SimpleHNL", pINFO)
    << "Decay permitted. Continuing";

  // Step 2: Actually do the decay. 
  // NucleonDecay's solution is the TGenPhaseSpace generator
  // For now, just add 2-body decays & use SimpleHNL kinematics
  // from the genie::HNL::decayKinematics namespace

  double mN = p4d->M();
  assert( mN >= 0.0 );
  double ml = -1.0, mh = -1.0;
  int pdgh = -1, pdgl = -1;
  
  if( fCurrDecayMode == genie::HNL::enums::kPiMu || fCurrDecayMode == genie::HNL::enums::kPiE ){
    mh = genie::constants::kPionMass; pdgh = typeMod * genie::kPdgPiP;
  }
  else if( fCurrDecayMode == genie::HNL::enums::kPi0Nu ){
    mh = genie::constants::kPi0Mass; pdgh = genie::kPdgPi0;
  }

  if( fCurrDecayMode == genie::HNL::enums::kPiMu ){ 
    ml = genie::constants::kMuonMass; pdgl = typeMod * genie::kPdgMuon;
  }
  else if( fCurrDecayMode == genie::HNL::enums::kPiE ){ 
    ml = genie::constants::kElectronMass; pdgl = typeMod * genie::kPdgElectron; 
  }
  else if( fCurrDecayMode == genie::HNL::enums::kPi0Nu ){
    ml = 0.0; pdgl = typeMod * genie::kPdgNuMu;
  }

  double Eh = 0.0, El = 0.0;
  //double thetaPol = 0.0; //angle wrt HNL polarisation
  // assume isotropic for now, //RETHERE to sample Pol from flux & enforce polarised decay

  genie::HNL::SimpleHNL sh = genie::HNL::SimpleHNL( "HNL", decayed_HNL_id, typeMod * genie::kPdgHNL, typeMod * genie::kPdgKP, mN, fUe42, fUm42, 0.0, false ); // RETHERE - find a way to propagate couplings into here!

  genie::HNL::decayKinematics::TwoBodyEnergies( mN, mh, ml, Eh, El );
  
  //genie::HNL::decayKinematics::TwoBodyAngle( sh, mh, ml, thetaPol ); 
  // causes crash. Will investigate. Let's randomise for now!

  LOG("SimpleHNL", pINFO)
    << "Two body kinematics done.";

  // also assume isotropic phi
  TRandom3 *rand = new TRandom3(0); // gotta move to Numerical/RandomGen
  double thetaPol = rand->Uniform( 0.0, genie::constants::kPi );
  double phi = rand->Uniform( 0.0, 2.0 * genie::constants::kPi );

  double p3h = std::sqrt( Eh*Eh - mh*mh );
  TLorentzVector p4h( p3h*std::sin(thetaPol)*std::cos(phi),
		      p3h*std::sin(thetaPol)*std::sin(phi),
		      p3h*std::cos(thetaPol),
		      Eh );

  double p3l = std::sqrt( El*El - ml*ml );
  TLorentzVector p4l( -p3l*std::sin(thetaPol)*std::cos(phi),
		      -p3l*std::sin(thetaPol)*std::sin(phi),
		      -p3l*std::cos(thetaPol),
		      El );

  std::map< int, TLorentzVector > pdgMap;

  pdgMap.insert( std::pair< int, TLorentzVector >( pdgh, p4h ) );
  pdgMap.insert( std::pair< int, TLorentzVector >( pdgl, p4l ) );

  LOG("SimpleHNL", pDEBUG) 
    << "Pion: pdg = " << pdgh << ", mass " << mh << ", energy " << Eh << ", mom " << p3h
    << "\n      px = " << p4h.Px() << ", py = " << p4h.Py() << ", pz = " << p4h.Pz();

  LOG("SimpleHNL", pDEBUG) 
    << "Lepton: pdg = " << pdgl << ", mass " << ml << ", energy " << El << ", mom " << p3l
    << "\n      px = " << p4l.Px() << ", py = " << p4l.Py() << ", pz = " << p4l.Pz();

  LOG("SimpleHNL", pDEBUG)
    << "theta = " << thetaPol << ", phi = " << phi;

  // Step 3: Boost these into the lab frame
  double PHNL = std::sqrt( EHNL*EHNL - mN*mN );

  Interaction * interaction = event->Summary();
  TLorentzVector * p4HNL = interaction->InitState().GetProbeP4( kRfLab );

  double betaMag = PHNL / EHNL;
  TVector3 bHNL( p4HNL->Px() / p4HNL->P() * betaMag,
		 p4HNL->Py() / p4HNL->P() * betaMag, 
		 p4HNL->Pz() / p4HNL->P() * betaMag );
  //TVector3 bHNL( 0.0, 0.0, PHNL / EHNL );

  // Step 4: Insert final state products into a TClonesArray of TMCParticles
  TLorentzVector v4(*v4d); 

  //  int idp = 0;
  for(pdg_iter = pdgv.begin(); pdg_iter != pdgv.end(); ++pdg_iter) {
     int pdgc = *pdg_iter;
     auto it4v = pdgMap.find( pdgc );
     assert( it4v != pdgMap.end() );
     TLorentzVector p4fin = it4v->second;

     p4fin.Boost(bHNL);

     if( std::abs( pdgc ) == genie::kPdgMuon || std::abs( pdgc ) == genie::kPdgElectron ){
       interaction->KinePtr()->SetFSLeptonP4( p4fin );
     }
     else{
       interaction->KinePtr()->SetHadSystP4( p4fin ); //RETHERE look at this!
     }

     LOG("SimpleHNL", pDEBUG)
       << "\n p4 (lab) = ( " << p4fin.E() << ", " << p4fin.Px() << ", " << p4fin.Py() << ", " << p4fin.Pz() << " )";

     // update FS particle count
     interaction->ExclTagPtr()->Reset();

     int nPiP = 0, nPi0 = 0, nPiM = 0;
     if( fCurrDecayMode == genie::HNL::enums::kPiMu || fCurrDecayMode == genie::HNL::enums::kPiE ){
       nPiP = ( typeMod > 0 ) ? 1 : 0;
       nPiM = 1 - nPiP; // either 1/0 or 0/1
     }
     else if( fCurrDecayMode == genie::HNL::enums::kPi0Nu ){
       nPi0 = 1;
     }       
     interaction->ExclTagPtr()->SetNPions( nPiP, nPi0, nPiM );
     interaction->ExclTagPtr()->SetNNucleons( 0, 0 );

     GHepStatus_t ist = kIStStableFinalState;
     event->AddParticle(pdgc, ist, decayed_HNL_id,-1,-1,-1, p4fin, v4);
     // idp++;
     
  }
  
  // kinematics here
  // build 4-vectors of HNL, muon
  TLorentzVector p4kH( 0.0, 0.0, PHNL, EHNL );
  TLorentzVector p4kM( p4l.Px(), p4l.Py(), p4l.Pz(), p4l.E() ); // unboosted
  p4kM.Boost( bHNL );

  TLorentzVector p4kD = p4kH - p4kM;
  double gQ2 = p4kD.M2(); // just M_pion^2 for 2-body case
  interaction->KinePtr()->SetQ2( gQ2, true );
  double gy = p4kM.E() / p4kH.E();
  interaction->KinePtr()->Sety( gy, true );
  double gx = interaction->KinePtr()->x(); // RETHERE do I actually want this?
  interaction->KinePtr()->Setx( gx, true );
  double gt = 0.0; // no interaction ==> no transfer to a nuclear system
  interaction->KinePtr()->Sett( gt, true );
  double gW = mh;
  interaction->KinePtr()->SetW( gW, true ); // should be exactly the pion mass!

  LOG( "SimpleHNL", pDEBUG )
    << "\n\n *******************************************"
    <<   "\n             Kinematics stats: "
    <<   "\n HNL 4-vector = ( " << p4kH.Px() << ", " << p4kH.Py() << ", " << p4kH.Pz() << ", " << p4kH.E() << " )"
    <<   "\n Lep 4-vector = ( " << p4kM.Px() << ", " << p4kM.Py() << ", " << p4kM.Pz() << ", " << p4kM.E() << " )"
    <<   "\n Dif 4-vector = ( " << p4kD.Px() << ", " << p4kD.Py() << ", " << p4kD.Pz() << ", " << p4kD.E() << " )"
    <<   "\n Q2 = " << gQ2
    <<   "\n y  = " << gy
    <<   "\n x  = " << gx
    <<   "\n t  = " << gt
    <<   "\n W  = " << gW
    <<   "\n *******************************************\n\n";

  // also set this cross section to 0
  event->SetDiffXSec( 0.0, kPSfE ); // see src/Conventions/KinePhaseSpace.h for the enum

  // Step 6: Update number of particles in Interaction/XclsTag.{h,cxx} ==> NPiPlus etc!

  LOG("SimpleHNL", pNOTICE)
    << "Cleaning up";

  // Clean-up
  delete [] mass;
  delete p4d;
  delete v4d;
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::Configure(const Registry & config)
{
  Algorithm::Configure(config);   
  this->LoadConfig();
}
//___________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::Configure(string config)
{
  Algorithm::Configure(config);
  this->LoadConfig();
}
//___________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::LoadConfig(void)
{
//  AlgConfigPool * confp = AlgConfigPool::Instance();
//  const Registry * gc = confp->GlobalParameterList();
    
  fNuclModel = 0;
  
  RgKey nuclkey = "NuclearModel";
  fNuclModel = dynamic_cast<const NuclearModelI *> (this->SubAlg(nuclkey));
  assert(fNuclModel);  
}
//___________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::SetHNLCouplings( double Ue42, double Um42 ) const
{
  fUe42 = Ue42;
  fUm42 = Um42;
}
//___________________________________________________________________________
