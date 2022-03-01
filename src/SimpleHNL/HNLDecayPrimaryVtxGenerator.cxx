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
  //fCurrDecayedHNL = interaction->InitState().Tgt().HitNucPdg();

  LOG("SimpleHNL", pNOTICE)
    << "Simulating decay with fCurrDecayMode = " << fCurrDecayMode 
    << " for an initial state with code: " << fCurrInitStatePdg;

  //fNucleonIsBound = (pdg::IonPdgCodeToA(fCurrInitStatePdg) > 1);

  double EHNL = interaction->InitState().ProbeE(kRfLab);

  this->AddInitialState(event, EHNL);
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
	          GHepRecord * event, double EHNL ) const
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
  
  GHepStatus_t stis = kIStInitialState;
  GHepStatus_t stdc = kIStDecayedState;
  GHepStatus_t stfs = kIStStableFinalState;

  // Initial state knows about an HNL
  int ipdg = fCurrInitStatePdg;

  // add initial HNL
  double mn  = PDGLibrary::Instance()->Find(ipdg)->Mass();
  TLorentzVector p4i(0,0,0,mn);

  // boost it to lab frame
  double phnl = std::sqrt( EHNL * EHNL - mn * mn );
  double bhnl = phnl / EHNL;

  TVector3 p3i(0.0,0.0,bhnl);
  TLorentzVector p4iLAB = p4i; p4iLAB.Boost(p3i);

  // RETHERE TODO: maybe want a v4LAB?
  event->AddParticle(ipdg,stis,-1,-1,-1,-1, p4iLAB, v4);

  LOG( "SimpleHNL", pNOTICE )
    << "Added initial state.";
}
//____________________________________________________________________________
void HNLDecayPrimaryVtxGenerator::GenerateDecayedHNLPosition(
  GHepRecord * event) const
{
  // HNL are point particles, so no trouble here.

  LOG( "SimpleHNL", pNOTICE ) 
    << "Generated HNL decay vertex position.";

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

  assert( fCurrDecayMode == genie::HNL::enums::kPiMu ||
	  fCurrDecayMode == genie::HNL::enums::kPiE ); // force 2-body decay

  PDGCodeList pdgv( false );
  
  pdgv.push_back( genie::kPdgPiP ); // all 2 decay modes do this
  
  if( fCurrDecayMode == genie::HNL::enums::kPiMu ) pdgv.push_back( genie::kPdgMuon );
  else pdgv.push_back( genie::kPdgElectron );

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
  double ml = -1.0, mh = genie::constants::kPionMass;
  int pdgl = -1;
  if( fCurrDecayMode == genie::HNL::enums::kPiMu ){ ml = genie::constants::kMuonMass; pdgl = genie::kPdgMuon; }
  else{ ml = genie::constants::kElectronMass; pdgl = genie::kPdgElectron; }

  double Eh = 0.0, El = 0.0;
  //double thetaPol = 0.0; //angle wrt HNL polarisation
  // assume isotropic for now, //RETHERE to sample Pol from flux & enforce polarised decay

  genie::HNL::SimpleHNL sh = genie::HNL::SimpleHNL( "HNL", decayed_HNL_id, genie::kPdgHNL, genie::kPdgKP, mN, 1.0, 1.0, 0.0, false ); // RETHERE - find a way to propagate couplings into here!

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

  pdgMap.insert( std::pair< int, TLorentzVector >( genie::kPdgPiP, p4h ) );
  pdgMap.insert( std::pair< int, TLorentzVector >( pdgl, p4l ) );

  LOG("SimpleHNL", pDEBUG) 
    << "Pion: pdg = " << genie::kPdgPiP << ", mass " << mh << ", energy " << Eh << ", mom " << p3h
    << "\n      px = " << p4h.Px() << ", py = " << p4h.Py() << ", pz = " << p4h.Pz();

  LOG("SimpleHNL", pDEBUG) 
    << "Muon: pdg = " << genie::kPdgMuon << ", mass " << ml << ", energy " << El << ", mom " << p3l
    << "\n      px = " << p4l.Px() << ", py = " << p4l.Py() << ", pz = " << p4l.Pz();

  LOG("SimpleHNL", pDEBUG)
    << "theta = " << thetaPol << ", phi = " << phi;

  // Step 3: Boost these into the lab frame
  double PHNL = std::sqrt( EHNL*EHNL - mN*mN );

  LOG("SimpleHNL", pDEBUG)
    << "EHNL = " << EHNL << ", PHNL = " << PHNL << ", beta = " << PHNL / EHNL;

  TVector3 bHNL( 0.0, 0.0, PHNL / EHNL );

  // Step 4: Insert final state products into a TClonesArray of TMCParticles
  TLorentzVector v4(*v4d); 

  Interaction * interaction = event->Summary();

  //  int idp = 0;
  for(pdg_iter = pdgv.begin(); pdg_iter != pdgv.end(); ++pdg_iter) {
     int pdgc = *pdg_iter;
     auto it4v = pdgMap.find( pdgc );
     assert( it4v != pdgMap.end() );
     TLorentzVector p4fin = it4v->second;

     LOG("SimpleHNL", pDEBUG)
       << "PDG code :" << pdgc
       << "\n p4 (rest) = ( " << p4fin.E() << ", " << p4fin.Px() << ", " << p4fin.Py() << ", " << p4fin.Pz() << " )";

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

     interaction->ExclTagPtr()->SetNPions( 1, 0, 0 ); //RETHERE make this realistic
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
  double gQ2 = p4kD.M2();
  interaction->KinePtr()->SetQ2( gQ2, true );
  double gy = p4kM.E() / p4kH.E();
  interaction->KinePtr()->Sety( gy, true );
  double gx = interaction->KinePtr()->x(); // RETHERE do I actually want this?
  interaction->KinePtr()->Setx( gx, true );
  double gt = 0.0; // no interaction ==> no transfer to a nuclear system
  interaction->KinePtr()->Sett( gt, true );
  double gW = genie::constants::kPionMass;
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

