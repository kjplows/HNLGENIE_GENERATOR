//----------------------------------------------------------------------------
// Implementation file for FluxReader.h
// 10/Jan/2021
//----------------------------------------------------------------------------
// TODO: figure out naming scheme for flux files
//       exceptions + error messages
//       what to do about K0L, mu parents & polarisation??
//       figure out implementation of generateVtxT
//       update HNL name/index/pdg/isMajorana
//----------------------------------------------------------------------------

#include "FluxReader.h"
#include "Messenger/Messenger.h"

using namespace genie::HNL::HNLFluxReader;
using namespace genie::HNL::HNLenums;

/* Input flux files should be organised in the following manner:
   
   fluxRoot/conf/coupling-enum/masspoint.root

   where each masspoint.root contains the following histos, for all + each parent:
   --> TH1D: Flux-at-centre
   --> TH3D: Co-produced lepton 3p (HNL rest frame) (obvious for pi-K-K0L, mu??)
   --> TH3D: HNL 3p (MINERvA frame)

   Example dir structure would be

   fluxRoot----FHC----EqualCouplings----FHC_iso_mp00.root----numu-----(TH1D*)flux
             |      |                 |                    |        |
             --RHC  --MuonOnly        --...                --...    --...
!                    |                 |                    |        |
                    --ElectronOnly    --FHC_iso_mp50.root  --nuebar --(TH3D*)parent3P
 */

// extern variables defined here

std::string genie::HNL::HNLFluxReader::fPath;
genie::HNL::HNLenums::parent_t genie::HNL::HNLFluxReader::fParent;
genie::HNL::HNLenums::nutype_t genie::HNL::HNLFluxReader::fNuType;

double genie::HNL::HNLFluxReader::fmN;
double genie::HNL::HNLFluxReader::fUe;
double genie::HNL::HNLFluxReader::fUm;
double genie::HNL::HNLFluxReader::fUt;

int genie::HNL::HNLFluxReader::fPDG;
int genie::HNL::HNLFluxReader::fParPDG;

bool genie::HNL::HNLFluxReader::fMaj;

TH1D * genie::HNL::HNLFluxReader::fMasterFlux;

std::string genie::HNL::HNLFluxReader::selectCoup( const double Ue42, const double Umu42, const double Ut42 ){
    // I am not sensitive to the tau coupling so only Ue42, Umu42 matter

    std::string theCoups = std::string("Init");
    
    if( Ue42 < 0 || Umu42 < 0 || Ut42 < 0 ){ std::cerr << "genie::HNL::HNLFluxReader: Illegal couplings: e mu t = " << Ue42 << " " << Umu42 << " " << Ut42 << std::endl; exit(3); }
    if( Ue42 + Umu42 == 0.0 ){ std::cerr << "genie::HNL::HNLFluxReader: Warning - HNL has no electron or muon couplings. We aren't sensitive to tau! Exiting" << std::endl; exit(4); }

    if( Ue42 == Umu42 ){ theCoups = std::string("EqualCouplings"); }
    else if( Ue42 == 0.0 ){ theCoups = std::string("MuonOnly"); }
    else if( Umu42 == 0.0 ){ theCoups = std::string("ElectronOnly"); }
    else{ std::cerr << "genie::HNL::HNLFluxReader::selectCoup: Unknown coupling" <<
	    "configuration! Couplings e mu = " << Ue42 << " " << Umu42 << ", exiting" << std::endl; exit(4); }

    fUe = Ue42; fUm = Umu42; fUt = Ut42;

    return theCoups;
}

int genie::HNL::HNLFluxReader::selectMass( const double mN ){
    /// move mass to closest mass hypothesis

    const massHyp_t massesHyp[] = {
	kLight0Hyp,  kLight1Hyp,  kLight2Hyp,  kLight3Hyp,  kLight4Hyp,
	kLight5Hyp,  kLight6Hyp,  kLight7Hyp,  kLight8Hyp,  kLight9Hyp,
	kLightAHyp,  kLightBHyp,  kLightCHyp,  kLightDHyp,  kLightEHyp,
	kLightFHyp,  kLightGHyp,  kLightHHyp,  kLightIHyp,  kLightJHyp,
	kMedium0Hyp, kMedium1Hyp, kMedium2Hyp, kMedium3Hyp, kMedium4Hyp,
	kMedium5Hyp, kMedium6Hyp, kMedium7Hyp, kMedium8Hyp, kMedium9Hyp,
	kHeavy0Hyp,  kHeavy1Hyp,  kHeavy2Hyp,  kHeavy3Hyp,  kHeavy4Hyp,
	kHeavy5Hyp,  kHeavy6Hyp,  kHeavy7Hyp,  kHeavy8Hyp,  kHeavy9Hyp,
	kHeavyAHyp,  kHeavyBHyp,  kHeavyCHyp,  kHeavyDHyp,  kHeavyEHyp,
	kHeavyFHyp,  kHeavyGHyp,  kHeavyHHyp,  kHeavyIHyp,  kHeavyJHyp };
    const int nMasses = sizeof(massesHyp)/sizeof(massesHyp[0]) - 1;

    // ROOTCINT does not like the map for some reason, explicitly declare the masses here instead. Ugh.
    double masses[ nMasses + 1 ] = {
				         1.000 * genie::units::keV,
				        10.000 * genie::units::keV,
				        50.000 * genie::units::keV,
				       100.000 * genie::units::keV,
				         1.000 * genie::units::MeV,
				         5.000 * genie::units::MeV,
				        10.000 * genie::units::MeV,
				        15.000 * genie::units::MeV,
				        20.000 * genie::units::MeV,
				        25.000 * genie::units::MeV,
				        30.000 * genie::units::MeV,
				        33.000 * genie::units::MeV,
					35.000 * genie::units::MeV,
					40.000 * genie::units::MeV,
					45.000 * genie::units::MeV,
					50.000 * genie::units::MeV,
					60.000 * genie::units::MeV,
					70.000 * genie::units::MeV,
					80.000 * genie::units::MeV,
					90.000 * genie::units::MeV,
				       100.000 * genie::units::MeV,
				       114.523 * genie::units::MeV,
				       129.046 * genie::units::MeV,
				       143.569 * genie::units::MeV,
				       158.092 * genie::units::MeV,
				       172.614 * genie::units::MeV,
				       187.137 * genie::units::MeV,
				       201.660 * genie::units::MeV,
				       216.183 * genie::units::MeV,
				       230.706 * genie::units::MeV,
				       245.229 * genie::units::MeV,
				       260.983 * genie::units::MeV,
				       276.738 * genie::units::MeV,
				       292.492 * genie::units::MeV,
				       308.246 * genie::units::MeV,
				       324.001 * genie::units::MeV,
				       339.755 * genie::units::MeV,
				       355.510 * genie::units::MeV,
				       371.264 * genie::units::MeV,
				       387.019 * genie::units::MeV,
				       397.434 * genie::units::MeV,
				       407.948 * genie::units::MeV,
				       418.626 * genie::units::MeV,
				       428.978 * genie::units::MeV,
				       439.493 * genie::units::MeV,
				       450.007 * genie::units::MeV,
				       460.622 * genie::units::MeV,
				       471.137 * genie::units::MeV,
				       481.652 * genie::units::MeV,
				       492.166 * genie::units::MeV
    };
    // because masses are kept in a *map*, gotta build array of the second elements!
    /*
    for( int i = 0; i <= nMasses; i++ ){
      massHyp_t thisHyp = massesHyp[i];
      std::map< HNLenums::massHyp_t, double > massHypMap =  HNLenums::BuildMassHypMap();
      auto pos = massHypMap.find( thisHyp );
      masses[i] = pos->second;
      LOG("SimpleHNL", pINFO) 
	<< "At position " << i << " the mass hypothesis is " << masses[i];
    }
    */

    if( mN < 0.0 || mN > masses[ nMasses ] ){
	std::cerr << "genie::HNL::HNLFluxReader::selectMass: Illegal mass mN = " <<
	    mN << std::endl; exit(3); }

    int mp = -1; fmN = 0.0;
    if( mN >= masses[ nMasses ] ){ mp = nMasses; fmN = masses[ nMasses ]; }
    while( masses[ mp + 1 ] < mN && mp < nMasses ){ mp++; } // decide interval
    
    // generally decide mass + point by closest endpoint in interval
    const double dLeft  = std::abs( mN - masses[ mp ] );
    const double dRight = masses[ mp + 1 ] - mN;

    LOG("SimpleHNL", pDEBUG)
     << "Stats:"
     << "\n Input mass: " << mN 
     << "\n Choice interval: [ " << masses[mp] << ", " << masses[mp+1] << " ] " 
     << "\n Left and right distance: " << dLeft << ", " << dRight
     << "\n Chosen point: " << ( ( dLeft < dRight ) ? mp : mp + 1 ) << " ( "
     << ( ( dLeft < dRight ) ? "LEFT )" : "RIGHT )" );

    fmN = ( dLeft < dRight ) ? masses[ mp ] : masses[ mp + 1 ];
    mp  = ( dLeft < dRight ) ? mp : mp + 1;

    return mp;
    
}

void genie::HNL::HNLFluxReader::selectFile( const std::string strconf,
					 const double Ue42, const double Umu42, const double Ut42,
					 const double mN ){
    std::string filePath = std::string( "" );
    filePath.append( strconf + "/" );
    filePath.append( selectCoup( Ue42, Umu42, Ut42 ) + "/" );
    const int mp = selectMass( mN );
    filePath.append( Form( "mp%02d", mp ) );
    filePath.append( ".root" );
    fPath = filePath;
}

void genie::HNL::HNLFluxReader::selectParent( const int parPDG ){
    fParent = kNoPar; fParPDG = parPDG;
    
    if( std::abs( parPDG ) == ::genie::kPdgPiP ) fParent = kPion;
    else if( std::abs( parPDG ) == ::genie::kPdgKP ) fParent = kKaon;
    else if( std::abs( parPDG ) == ::genie::kPdgMuon ) fParent = kMuon;
    else if( std::abs( parPDG ) == ::genie::kPdgK0L ) fParent = kNeuk;
    else{ LOG( "SimpleHNL", pERROR ) << 
	  "genie::HNL::HNLFluxReader::selectFile: Unknown parent with PDG code " <<
	  parPDG; exit( 3 ); }
}

void genie::HNL::HNLFluxReader::selectNuType( const int hType ){
    fNuType = kNone;
    if( hType == 1 ){ fNuType == kNumu; }
    else if( hType == 2 ){ fNuType == kNumubar; }
    else if( hType == 3 ){ fNuType == kNue; }
    else if( hType == 4 ){ fNuType == kNuebar; }
}

TH1F * genie::HNL::HNLFluxReader::getFluxHist1F( std::string fin, std::string hName,
					      parent_t par, nutype_t HType ){
    // flux file contains 4 dirs: numu, numubar, nue, nuebar. Each has flux + helper hists
    TFile *f = TFile::Open( fin.c_str() );

    // descend into dir first!
    TDirectory *baseDir = f->GetDirectory( "" );
    std::string strType;
    switch( HType ){
	case kNumu:    strType = std::string( "numu" ); break;
	case kNumubar: strType = std::string( "numubar" ); break;
	case kNue:     strType = std::string( "nue" ); break;
	case kNuebar:  strType = std::string( "nuebar" ); break;
    }
    TDirectory *deepDir = baseDir->GetDirectory( strType.c_str( ) );
    if( deepDir == NULL ){ std::cerr << "genie::HNL::HNLFluxReader::getFluxHist:" <<
	    " Could not find " << "directory with name \"" << strType.c_str() <<
	    "\". Exiting" << std::endl;
	exit(3); }

    // construct standardised name
    std::string strHist = std::string( hName.c_str( ) );
    switch( par ){
	case kAll:  strHist.append("_all"); break;
	case kPion: strHist.append("_pion"); break;
	case kKaon: strHist.append("_kaon"); break;
	case kMuon: strHist.append("_muon"); break;
	case kNeuk: strHist.append("_neuk"); break;
    }
    if( !( deepDir->GetListOfKeys()->Contains( strHist.c_str() ) ) ){
	std::cerr << "genie::HNL::HNLFluxReader::getFluxHist: Could not find histogram " <<
	    " with name \"" << strHist.c_str() << "\" in path\n" <<
	    deepDir->GetPath() << " . Exiting" << std::endl; exit(3); }
    
    TH1F * histPtr = dynamic_cast< TH1F* >( deepDir->Get( strHist.c_str() ) );

    return histPtr;
}

// overloaded method, linker likes it better this way
TH3D * genie::HNL::HNLFluxReader::getFluxHist3D( std::string fin, std::string hName,
					      parent_t par, nutype_t HType ){
    TFile *f = TFile::Open( fin.c_str() );

    // descend into dir first!
    TDirectory *baseDir = f->GetDirectory( "" );
    std::string strType = std::string( "dummy" );
    /*
    switch( HType ){
	case kNumu:    strType = std::string( "numu" ); break;
	case kNumubar: strType = std::string( "numubar" ); break;
	case kNue:     strType = std::string( "nue" ); break;
	case kNuebar:  strType = std::string( "nuebar" ); break;
    }
    */
    TDirectory *deepDir = baseDir;
      //baseDir->GetDirectory( strType.c_str( ) );
    if( deepDir == NULL ){ std::cerr << "genie::HNL::HNLFluxReader::getFluxHist:" <<
	    " Could not find " << "directory with name \"" << strType.c_str() <<
	    "\". Exiting" << std::endl;
	exit(3); }

    // construct standardised name
    std::string strHist = std::string( hName.c_str( ) );
    /*
    switch( par ){
	case kAll:  strHist.append("_all"); break;
	case kPion: strHist.append("_pion"); break;
	case kKaon: strHist.append("_kaon"); break;
	case kMuon: strHist.append("_muon"); break;
	case kNeuk: strHist.append("_neuk"); break;
    }
    */
    if( !( deepDir->GetListOfKeys()->Contains( strHist.c_str() ) ) ){
	std::cerr << "genie::HNL::HNLFluxReader::getFluxHist: Could not find histogram " <<
	    " with name \"" << strHist.c_str() << "\" in path\n" <<
	    deepDir->GetPath() << " . Exiting" << std::endl; exit(3); }

    TH3D * histPtr = dynamic_cast< TH3D* >( deepDir->Get( strHist.c_str() ) );

    return histPtr;
}

double genie::HNL::HNLFluxReader::generatePolMag( const int lPDG, const int parPDG ){
    /* Assumes 2-body decay. 
       If parent is neuk then assume we have kaon polarisation
       If parent is muon then assume we have pion polarisation
     */
    // Uses 2-body polarisation magnitude from Levy, arXiv:1805.06419

    double mpar = 0.0, ml = 0.0;

    if( std::abs( lPDG ) == ::genie::kPdgElectron ){ ml = genie::constants::kElectronMass; }
    else if( std::abs( lPDG ) == ::genie::kPdgMuon ){ ml = genie::constants::kMuonMass; }
    else{ std::cerr << "genie::HNL::HNLFluxReader::generatePolMag: Unknown lepton PDG = " <<
	    lPDG << std::endl; exit(3); }

    if( std::abs( parPDG ) == ::genie::kPdgPiP ){ mpar = genie::constants::kPionMass; }
    else if( std::abs( parPDG ) == ::genie::kPdgKP ){ mpar = genie::constants::kKaonMass; }
    else if( std::abs( parPDG ) == ::genie::kPdgMuon ){
	mpar = genie::constants::kPionMass;
	std::cout << "genie::HNL::HNLFluxReader::generatePolMag: WARNING: \n" <<
	    "Muon parent requested, changing polarisation to pion equivalent. \n" <<
	    "Also note that the lepton will be set to electron. \n" <<
	    "This is very crude, unphysical behaviour, and it should be fixed." <<
	    std::endl; } //! RETHERE
    else if( std::abs( parPDG ) == ::genie::kPdgK0L ){
	mpar = genie::constants::kKaonMass;
	std::cout << "genie::HNL::HNLFluxReader::generatePolMag: WARNING: \n" <<
	    "Neuk parent requested, changing polarisation to kaon equivalent. \n" <<
	    "This is very crude, unphysical behaviour, and it should be fixed." <<
	    std::endl; } //! RETHERE
    else{ std::cerr << "genie::HNL::HNLFluxReader::generatePolMag: Unknown parent PDG = " <<
	    parPDG << std::endl; exit(3); }

    double num = ( ml*ml - fmN*fmN ) *
	std::sqrt( genie::HNL::HNLutils::Kallen( mpar*mpar, fmN*fmN, ml*ml ) );
    double den = mpar*mpar * ( ml*ml + fmN*fmN ) -
	std::pow( ml*ml - fmN*fmN , 2.0 );

    if( std::abs( num / den ) > 1.0 ){ std::cerr << "genie::HNL::HNLFluxReader::" <<
	    "generatePolMag: Warning: Polarisation magnitude over 1.0 . Setting to 1.0 ." <<
	    std::endl;
	num *= std::abs( den / num ); }

    return num / den;
}

std::vector< double > * genie::HNL::HNLFluxReader::generatePolDir( const int parPDG, const int HType ){
    // coproduced lepton is always mu/e if HType == nu{mu/e}(bar)
    // and always e if parPDG == mu

    // first, select parent, nutype and load histo
    std::string polHistName = std::string("polHist");
    selectParent( parPDG );
    selectNuType( HType );
    TH3D * polHist = getFluxHist3D( fPath, polHistName, fParent, fNuType );

    // now get random.
    // polHist will be unit vector components, i.e. on the unit sphere
    double ux = 0.0, uy = 0.0, uz = 0.0;
    polHist->GetRandom3( ux, uy, uz );

    std::vector< double > * polDir = new std::vector< double >( );
    polDir->emplace_back( ux );
    polDir->emplace_back( uy );
    polDir->emplace_back( uz );

    delete polHist;
    return polDir;
}

double genie::HNL::HNLFluxReader::generateVtxT( const int parPDG, const int HType ){
  LOG( "SimpleHNL", pDEBUG ) << "genie::HNL::HNLFluxReader::generateVtxT:: Dummy method! WIP";
  return 0.0;
}
// need to think about this more!

std::vector< double > * genie::HNL::HNLFluxReader::generateVtx3X( const int parPDG, const int HType ){
    // first, select parent, nutype and load histo
    std::string vtxHistName = std::string("vtxHist");
    selectParent( parPDG );
    selectNuType( HType );
    TH3D * vtxHist = getFluxHist3D( fPath, vtxHistName, fParent, fNuType );

    // now get random.
    double ux = 0.0, uy = 0.0, uz = 0.0;
    vtxHist->GetRandom3( ux, uy, uz );

    std::vector< double > * vtxDir = new std::vector< double >( );
    vtxDir->emplace_back( ux );
    vtxDir->emplace_back( uy );
    vtxDir->emplace_back( uz );

    delete vtxHist;
    return vtxDir;
}

std::vector< double > * genie::HNL::HNLFluxReader::generateVtx3X( TH3D * vtxHist ){
  double ux = 0.0, uy = 0.0, uz = 0.0;
  vtxHist->GetRandom3( ux, uy, uz );
  
  std::vector< double > * vtxDir = new std::vector< double >( );
  vtxDir->emplace_back( ux );
  vtxDir->emplace_back( uy );
  vtxDir->emplace_back( uz );

  return vtxDir;
}

double genie::HNL::HNLFluxReader::generateVtxE( const int parPDG, const int HType ){
    // first, select parent, nutype and load histo
    std::string eneHistName = std::string("eneHist");
    selectParent( parPDG );
    selectNuType( HType );
    TH1F * eneHist = getFluxHist1F( fPath, eneHistName, fParent, fNuType );

    // now get random.
    double E = eneHist->GetRandom( );

    delete eneHist;
    return E;
}

std::vector< double > * genie::HNL::HNLFluxReader::generateVtx3P( const int parPDG, const int HType,
							       const double inE ){
    // first, select parent, nutype and load histo
    std::string momHistName = std::string("momHist");
    selectParent( parPDG );
    selectNuType( HType );
    TH3D * momHist = getFluxHist3D( fPath, momHistName, fParent, fNuType );

    // now get random.
    // momHist will be unit vector components, i.e. on the unit sphere
    // magnitude will be given by relativistic dispersion
    double ux = 0.0, uy = 0.0, uz = 0.0;
    momHist->GetRandom3( ux, uy, uz );

    const double E = ( inE > 0.0 ) ? inE : generateVtxE( parPDG, HType );
    const double P = std::sqrt( E*E - fmN*fmN );
    ux *= P; uy *= P; uz *= P;

    std::vector< double > * momVec = new std::vector< double >( );
    momVec->emplace_back( ux );
    momVec->emplace_back( uy );
    momVec->emplace_back( uz );

    delete momHist;
    return momVec;
}

genie::HNL::SimpleHNL genie::HNL::HNLFluxReader::generateHNL( ){
  return genie::HNL::SimpleHNL( "HNL", 0, genie::kPdgHNL, ::genie::kPdgKP, fmN, fUe, fUm, fUt, false );
}

genie::HNL::SimpleHNL genie::HNL::HNLFluxReader::generateHNL( const int PDG, const int parPDG,
							   const double mN, const double Ue42,
							   const double Umu42, const double Ut42 ){
    return genie::HNL::SimpleHNL( "HNL", 0, PDG, parPDG, mN, Ue42, Umu42, Ut42, false );
}

void genie::HNL::HNLFluxReader::setFluxInfo( genie::HNL::SimpleHNL sh ){
    const int shPDG    = sh.GetPDG( ); fPDG = shPDG;
    const int shParPDG = sh.GetParentPDG( ); fParPDG = shParPDG;

    switch( shParPDG ){
	case ::genie::kPdgPiP:  fParent = kPion; break;
	case ::genie::kPdgKP:   fParent = kKaon; break;
	case ::genie::kPdgMuon: fParent = kMuon; break;
	case ::genie::kPdgK0L:  fParent = kNeuk; break;
    }

    switch( shPDG ){
	case kPdgHMu:    fNuType = kNumu; break;
	case kPdgHMubar: fNuType = kNumubar; break;
	case kPdgHE:     fNuType = kNue; break;
	case kPdgHEbar:  fNuType = kNuebar; break;
    }
    
    const double E = generateVtxE( fParent, fNuType );
    sh.SetEnergy( E );

    const double mN = sh.GetMass( );
    const double P = std::sqrt( E*E - mN*mN );
    std::vector< double > * momVec = generateVtx3P( fParPDG, fNuType, E );
    double upx = momVec->at(0) / P;
    double upy = momVec->at(1) / P;
    double upz = momVec->at(2) / P;
    sh.SetMomentumDirection( upx, upy, upz );

    int lPDG = 0;
    if( fParPDG == ::genie::kPdgMuon ) lPDG = ::genie::kPdgElectron;
    else if( fNuType == kNue || fNuType == kNuebar ) lPDG = ::genie::kPdgElectron;
    else lPDG = ::genie::kPdgMuon;

    const double polMag = generatePolMag( lPDG, fParPDG );
    std::vector< double > * polDir = generatePolDir( fParPDG, fNuType );
    sh.SetPolMag( polMag );
    sh.SetPolarisationDirection( polDir->at(0), polDir->at(1), polDir->at(2) );

    const double vtxT = generateVtxT( fParPDG, fNuType );
    std::vector< double > * vtx3X = generateVtx3X( fParPDG, fNuType );
    std::vector< double > * vtx4X = new std::vector< double >( );
    vtx4X->emplace_back( vtxT );
    vtx4X->emplace_back( vtx3X->at(0) );
    vtx4X->emplace_back( vtx3X->at(1) );
    vtx4X->emplace_back( vtx3X->at(2) );
    sh.SetProdVtx( (*vtx4X) );

    delete vtx3X;
    delete vtx4X;
}
