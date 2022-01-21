//-------------------------------------------------------------------------
/*!

  Implementation for HNLDecayer.h
  John Plows <komninos-john.plows@physics.ox.ac.uk>
  
 */
//-------------------------------------------------------------------------

#include "HNLDecayer.h"

using namespace genie;
using namespace genie::HNL;

/// c'tors
HNLDecayer::HNLDecayer( ) :
    DecayModelI( "genie::HNLDecayer" ) { }

HNLDecayer::HNLDecayer( std::string config ) :
    DecayModelI( "genie::HNLDecayer", config ) { }

HNLDecayer::~HNLDecayer( ) { }

/// isHandled asks if this alg can decay this particle
bool HNLDecayer::IsHandled( int pdgc ) const {
    if( gp::IsGenericHNL( pdgc ) || gp::IsGenericHNLBar( pdgc ) ||
	gp::IsMuHNL( pdgc ) || gp::IsMuHNLBar( pdgc ) ||
	gp::IsEHNL( pdgc ) || gp::IsEHNLBar( pdgc ) ) { return true; }

    LOG( "Decay", pINFO ) <<
	"This algorithm can only decay HNL. Particle with code " << pdgc <<
	" is not an HNL.";

    return false;
}

/// construct the SimpleHNL object
void HNLDecayer::Initialize( void ) const {

    //fCoupConf = std::string( "Placeholder" );

    // detect whether this is mu-coupled or e-coupled or both-coupled
    if( fECoup == 0.0 ){
	if( fMuCoup == 0.0 ){ LOG( "HNLDecayer", pERROR ) << "Both e and mu couplings are zero!";
	    exit(3); }
	else { fCoupConf = std::string( "MuonOnly" ); fCoupIdx = ghe::kMuonIdx; }
    }
    else {
	if( fMuCoup == 0.0 ){ fCoupConf =  std::string( "ElectronOnly" );fCoupIdx = ghe::kElectronIdx; }
	else if( fMuCoup == fECoup ){ fCoupConf = std::string( "EqualCouplings" ); fCoupIdx = ghe::kEqualIdx; }
	else{
	    LOG( "HNLDecayer", pNOTICE ) << "Non-standard coupling configuration: |U_e4|^2 :" <<
		" |U_mu4|^2 = " << fECoup/fMuCoup << " : 1";
	    fCoupConf = std::string( "OtherCouplings" ); fCoupIdx = ghe::kOtherIdx; }
    }
}

/// Every time this is called, a new instance of the HNL is created
/// Is this ever going to be seen by GENIE??
void HNLDecayer::InitializeParticle( gh::SimpleHNL sh ) const {

    double shE = ghf::generateVtxE( sh.GetParentPDG( ), sh.GetHType( ) );
    sh.SetEnergy( shE ); // lab frame!

    std::vector< double > * sh3P = ghf::generateVtx3P( sh.GetParentPDG( ),
						       sh.GetHType( ), shE );
    double sh3Px = sh3P->at( 0 ), sh3Py = sh3P->at( 1 ), sh3Pz = sh3P->at( 2 );
    sh.SetMomentumDirection( sh3Px, sh3Py, sh3Pz );

    std::vector< double > * shX = ghf::generateVtx3X( sh.GetParentPDG( ),
						      sh.GetHType( ) );
    // need to use these! For making the trajectory
    // double shXx = shX->at( 0 ), shXy = shX->at( 1 ), shXz = shX->at( 2 );
    // double shT = ghf::generateVtxT( sh.GetParentPDG( ), sh.GetHType( ) );
    double shT = 0.0; //placeholder
    shX->insert( shX->begin( ), shT ); // make into vector of 4 elements
    sh.SetProdVtx( (*shX) );

    // set polarisation mag + dir
    int lPDG = 0;
    switch( sh.GetHType( ) ){
	case ghe::kNone: 
	    LOG( "HNLDecay", pERROR ) <<
	      "\n *** The SimpleHNL object with name & index = " <<
	      sh.GetName( ) << ", " << sh.GetIndex( ) <<
	      " has unspecified coupling-type `kNone`. Exiting.";
	    exit( 3 ); break;
	case ghe::kNumu: case ghe::kNumubar:
	    lPDG = ( std::abs( sh.GetParentPDG( ) ) != ::genie::kPdgMuon ) ?
		::genie::kPdgMuon : ::genie::kPdgElectron; break;
	case ghe::kNue: case ghe::kNuebar:
	    lPDG = ::genie::kPdgElectron; break;
    }
    double polMag = ghf::generatePolMag( sh.GetParentPDG( ), lPDG );
    sh.SetPolMag( polMag );
    std::vector< double > *polDir = ghf::generatePolDir( sh.GetParentPDG( ), sh.GetHType( ) );
    sh.SetPolarisationDirection( polDir->at(0), polDir->at(1), polDir->at(2) );
    
}

/// Then need to interface with UnstableParticleDecayer
/// implement Decay( ) to ensure stuff gets written into the event record

TClonesArray* HNLDecayer::Decay( const DecayerInputs_t & inp ) const {
    if( ! this->IsHandled( inp.PdgCode ) ) return 0;

    //-- Find the particle in the PDG library & quit if it does not exist
    TParticlePDG * mother = PDGLibrary::Instance( )->Find( inp.PdgCode );

    if( ! mother ) {
	LOG( "HNLDecay", pERROR ) <<
	    "\n *** The particle with PDG-Code = " << inp.PdgCode <<
	    " was not found in PDGLibrary";
	return 0;
    }

    LOG( "HNLDecay", pINFO ) <<
	"Decaying a " << mother->GetName( ) <<
	" with P4 = " << gut::print::P4AsString( inp.P4 );

    //reset previous weight
    fWeight = 1.0;

    // now comes the custom HNL decay part.
    // Initialise an HNL with the correct PDG code & momentum & polarisation
    // As in, build a SimpleHNL that deals with it!
    // Then use the various methods in our namespace to build the products + assign the correct
    // 4-momenta and pass it to ???

    // construct HNL object with the basic properties. Assume it's kaon-produced for now..
    fSh = SimpleHNL( fCoupConf, fCoupIdx, mother->PdgCode( ), genie::kPdgKP,
		     fMass, fECoup, fMuCoup, fTauCoup, fIsMajorana );

    assert( mother->Mass( ) == fMass ); // must match up!

    // now set its instance-specific properties
    InitializeParticle( fSh );

    // we have all the valid channels, the CoM and lab lifetime
    
    // let's find out where this decays
    ghs::PropagateTilDecay( fSh );
    
    // Let's pick pi \ell as the interesting thing, shall we?

    std::vector< ghe::HNLDecay_t > * intChannels = new std::vector< ghe::HNLDecay_t >( ); // un-point!
    ghe::HNLDecay_t piEll = ( fMuCoup == 0.0 ) ? ghe::kPiE : ghe::kPiMu;
    intChannels->emplace_back( piEll );
    const std::map< ghe::HNLDecay_t, double > gammaMap = fSh.GetValidChannels( );
    std::map< ghe::HNLDecay_t, double > intMap = ghs::SetInterestingChannels( (*intChannels), gammaMap );
    fSh.SetInterestingChannels( intMap );

    // transform intMap gammas to probabilities
    // in this case, we have P( N --> pi \ell ) = 1;
    std::map< ghe::HNLDecay_t, double > PMap = ghs::GetProbabilities( intMap );

    // do a random throw
    if( !fRng ) fRng = new TRandom3( );
    double ranThrow = fRng->Uniform( 0., 1. ); // HNL's fate is sealed.

    // decay inclusively -- TODO: add exclusive call here
    /* if( exclusive ) return ... */
    
    // now select decay mode
    ghe::HNLDecay_t selectedDecayChan = ghs::SelectChannelInclusive( PMap, ranThrow );

    const int nd = 2; // 2 daughters for now, RETHERE later
    
    TDecayChannel * ch;
    int daughterPDG[ nd ] = { };
    switch( selectedDecayChan ){
	case ghe::kPiMu:
	    daughterPDG[0] = ::genie::kPdgPiP;
	    daughterPDG[1] = ::genie::kPdgMuon;
	    ch = new TDecayChannel( 0, 0, 1.0, 2, daughterPDG ); // what does MatrixElementCode mean?
	                                                         // also should BR = 1.0? I've chosen!
	    break;
	case ghe::kPiE:
	    daughterPDG[0] = ::genie::kPdgPiP;
	    daughterPDG[1] = ::genie::kPdgElectron;
	    ch = new TDecayChannel( 0, 0, 1.0, 2, daughterPDG );
	    break;
	default: LOG( "HNLDecay", pERROR ) << "\n *** Case " << selectedDecayChan << " is not implemented yet. WIP. "; exit( 3 );
    }

    // now let's do some gosh darn kinematics.
    const double mh = gc::kPionMass;
    const double ml = ( selectedDecayChan == ghe::kPiE ) ? gc::kElectronMass : gc::kMuonMass;

    double Eh = 0.0, El = 0.0, thetaPol = 0.0;
    ghdk::TwoBodyEnergies( fMass, mh, ml, Eh, El );
    ghdk::TwoBodyAngle( fSh, mh, ml, thetaPol ); //assume isotropic polarisation for now, theta* = thetaPol

    // this is in HNL rest frame. Let's make some nice TLorentzVectors and boost them.
    const double rPhi = fRng->Uniform( 0.0, 2.0 * gc::kPi );

    double lx = std::sin( thetaPol ) * std::cos( rPhi ), hx = -lx;
    double ly = std::sin( thetaPol ) * std::sin( rPhi ), hy = -ly;
    double lz = std::cos( thetaPol )                   , hz = -lz;

    const double hP = std::sqrt( Eh*Eh - mh*mh );
    const double lP = std::sqrt( El*El - ml*ml );

    lx *= lP; ly *= lP; lz *= lP;
    hx *= hP; hy *= hP; hz *= hP;

    TLorentzVector l4V, h4V;
    l4V.SetPxPyPzE( lx, ly, lz, El );
    h4V.SetPxPyPzE( hx, hy, hz, Eh );

    // grab HNL 4-momentum lab from DecayerInputs_t
    TLorentzVector NP4 = *(inp.P4); const double ELAB = NP4.E(); const double PLAB = NP4.P();
    TVector3 bVect = NP4.Vect(); bVect *= ( PLAB / ELAB );

    // Boost
    l4V.Boost( bVect ); h4V.Boost( bVect );

    //-- Create the event record
    TClonesArray * particle_list = new TClonesArray("TMCParticle", 1+nd);
    TClonesArray * temp_particle_list = new TClonesArray("TMCParticle", 1+nd);//A temprary record.

    // Add mother to the event record
    const int pdg_code = mother->PdgCode( );
    //TParticlePDG * motherEvRec = PDGLibrary::Instance( )->Find( pdg_code ); // already found mother!
    double mpx = NP4.Px(), mpy = NP4.Py(), mpz = NP4.Pz(), mE = ELAB, mM = mother->Mass( );

    new ( (*temp_particle_list)[0] )
	TMCParticle(11,pdg_code,0,0,0,mpx,mpy,mpz,mE,mM,0,0,0,0,0); //restore mother particle to the temp_particle list. 11 means "this is decaying". See `KS column` in the Pythia 6.4 manual.

    int pdgc[ nd ]; double mass[ nd ];

    for( unsigned int id = 0; id < nd; id++ ){

	int dPDG = ch->DaughterPdgCode( id );
	TParticlePDG * daughter = PDGLibrary::Instance( )->Find( dPDG );
	assert( daughter );

	// for now, binary choice of momentum. Either pi or ell. RETHERE
	double px = ( dPDG == ::genie::kPdgPiP ) ? hx : lx;
	double py = ( dPDG == ::genie::kPdgPiP ) ? hy : ly;
	double pz = ( dPDG == ::genie::kPdgPiP ) ? hz : lz;
	double E  = ( dPDG == ::genie::kPdgPiP ) ? Eh : El;

	pdgc[ id ] = dPDG;
	mass[ id ] = daughter->Mass( ); double M = mass[ id ];

	new ( (*temp_particle_list)[1+id] )
	    TMCParticle(1,pdgc[id],0,0,0,px,py,pz,E,M,0,0,0,0,0);

    } // loop over daughters

    // now set the particle list, set owner (????) and return it.

    particle_list=temp_particle_list;
    //-- Set owner and return
    particle_list->SetOwner(true);
    return particle_list;
}

double HNLDecayer::Weight( void ) const { return fWeight; }

/// need to decide how to implement these.
//  for now just grab (barebones!) implementation from BaryonResonanceDecayer.cxx
//  see PythiaDecayer.cxx and/or GENIE v3 for a more complete implementation
void HNLDecayer::InhibitDecay( int pdgc, TDecayChannel * dc ) const {
    if( ! this->IsHandled( pdgc ) ) return;

    if( ! dc ) return;
}

void HNLDecayer::UnInhibitDecay( int pdgc, TDecayChannel * dc ) const {
    if( ! this->IsHandled( pdgc ) ) return;

    if( ! dc ) return;
}

void HNLDecayer::Configure( const Registry & config ) {
    Algorithm::Configure( config );
    this->LoadConfig( );
}

void HNLDecayer::LoadConfig( void ){

    /// Loads info that uniquely defines an HNL up to species

    fWeightFluxInput = fConfig->GetBoolDef( "weight-flux-input", false );

    fIsMajorana = fConfig->GetBoolDef( "majorana-hnl", false );

    fIsIsotropicPol = fConfig->GetBoolDef( "isotropic-polarisation", false );

    fIsExclusive = fConfig->GetBoolDef( "exclusive-decays", false );

    fMass = fConfig->GetDoubleDef( "hnl-mass", fDefMass );

    fECoup = fConfig->GetDoubleDef( "hnl-e-coupling", fDefECoup );

    fMuCoup = fConfig->GetDoubleDef( "hnl-mu-coupling", fDefMuCoup );

    fTauCoup = fConfig->GetDoubleDef( "hnl-tau-coupling", fDefTauCoup );
    
}
