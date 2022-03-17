//----------------------------------------------------------------------------
// Implementation file for DecayKinematics.h
// Author: John Plows <komninos-john.plows@physics.ox.ac.uk>
// 13/Dec/2021
//----------------------------------------------------------------------------
// TODO: Exception in ExtractVar if size(params) != N params in formula
//       Exception in ExtractVar if root not found
//       Spinor-helicity-formalism calcs for dGamma/dcostheta: 2 and 3 body decays
//       Write down TwoBodyAngle using the pdf determined using FeynCalc
//       Finish implementing TwoBodyKinematics:
//         Work out how lab-frame (\hat{x},\hat{y},\hat{z}) are translated to sep axis
//         and write out 2ndary axis to make unique coord system.
//         Ideally I want rest frame (slx,y,z) = (0,0,1) to mean lab frame (0,0,K) etc
//----------------------------------------------------------------------------

#include "DecayKinematics.h"

// extern variables defined here

TRandom3 * genie::HNL::decayKinematics::fRngD;
bool genie::HNL::decayKinematics::fIsRngInitD;

//using namespace genie::HNL::decayKinematics;

void genie::HNL::decayKinematics::initRandom( ){
    fRngD = new TRandom3(0); fIsRngInitD = true; 
}

void genie::HNL::decayKinematics::TwoBodyEnergies( const double mN, const double mh, const double ml,
			    double &Eh, double &El ){
    Eh = ( mN*mN + mh*mh - ml*ml ) / ( 2.0 * mN );
    El = ( mN*mN - mh*mh + ml*ml ) / ( 2.0 * mN );
}

void genie::HNL::decayKinematics::TwoBodyAngle( genie::HNL::SimpleHNL sh, const double mh, const double ml,
			 double &thetaPol ){
    if( mh == genie::constants::kPionMass && ( ml == genie::constants::kElectronMass || ml == genie::constants::kMuonMass ) ){
	// construct differential decay width. Get pol info from sh
	const double M = sh.GetMass( );
	const std::vector< double > theCoups = sh.GetCouplings( );
	const double Ua42 = ( ml == genie::constants::kMuonMass ) ? theCoups.at(1) : theCoups.at(0);
	const double P = sh.GetPolarisationMag( ); // note this is signed! For M --> 0 P --> -1

	double thePreFac = 0.0, theCnstPart = 0.0, thePropPart = 0.0;
	genie::HNL::Selector::Diff1Width_PiAndLepton_CosTheta( M, Ua42, ml, thePreFac, theCnstPart, thePropPart );
	thePropPart *= P;
	// now construct const char * and const double[] for formula & params
	// ExtractVar will deal with this

	const double x1 = -1.0, x2 = 1.0; // cos theta
	const std::string sform = std::string("[0] * ( [1] + [2] * x )");
	const char *formChar = sform.c_str();
	const double params[] = { thePreFac, theCnstPart, thePropPart };
	const std::string name = std::string(" N42EllPi ");

	// cos(thetaPol) sampled from ExtractVar
	const double ctPol = ExtractVarFromDifferentialGamma( name, formChar, x1, x2, params );
	thetaPol = std::acos( ctPol ); // rad, wrt polarisation vector
    }
    else if( mh == genie::constants::kPi0Mass && ml == 0.0 ){
	// do N --> pi0 \nu
    }
    else{
	//raise exception
    }
}

// returns full kinematic information about both products in lab frame
void genie::HNL::decayKinematics::TwoBodyKinematics( genie::HNL::SimpleHNL sh, const double mh, const double ml,
			      double &Eh, double &El,
			      double &slx, double &sly, double &slz,
			      double &shx, double &shy, double &shz ){
    const double mN = sh.GetMass( );
    TwoBodyEnergies( mN, mh, ml, Eh, El );

    double thetaPolEll = 0.0, phiPolEll = 0.0; // wrt polarisation axis
    TwoBodyAngle( sh, mh, ml, thetaPolEll );
    if( !fIsRngInitD ){ initRandom( ); } // assume cylidrical symmetry for phi
    const double phiLow = 0.0, phiHigh = 2.0 * genie::constants::kPi;
    phiPolEll = fRngD->Uniform( phiLow, phiHigh );

    // Cartesian coordinates on unit sphere, wrt polarisation axis
    const double pax = std::sin( thetaPolEll ) * std::cos( phiPolEll );
    const double pay = std::sin( thetaPolEll ) * std::sin( phiPolEll );
    const double paz = std::cos( thetaPolEll );
    
    // convert this to theta wrt separation axis
    // axes first
    const TVector3* sepTAxis = RestFrameAxis( sh );
    std::vector< double > *sepAxis = new std::vector< double >( );
    sepAxis->emplace_back( sepTAxis->X( ) );
    sepAxis->emplace_back( sepTAxis->Y( ) );
    sepAxis->emplace_back( sepTAxis->Z( ) );
    const std::vector< double > *polAxis = sh.GetPolarisationDir( );
    
    // Cartesian coordinates on unit sphere, wrt separation axis
    // r(wrt sep) = r(wrt pol) + r(pol wrt sep)
    slx = pax + polAxis->at(0) - sepAxis->at(0);
    sly = pay + polAxis->at(1) - sepAxis->at(1);
    slz = paz + polAxis->at(2) - sepAxis->at(2);
    double slm = std::sqrt( slx*slx + sly*sly + slz*slz );
    // very much *not* guaranteed to be unit length!

    slx = slx / slm; shx = -slx;
    sly = sly / slm; shy = -sly;
    slz = slz / slm; shz = -slz; //this has same angles wrt -polVec ==> opposite momentum

    delete sepAxis;
}

// define characteristic rest frame axis
const TVector3* genie::HNL::decayKinematics::RestFrameAxis( genie::HNL::SimpleHNL sh ){
    /* We make a choice of axis for reference in rest frame.
       I choose this to be separation vector: decay vtx to detector centre.

       Subtle point: This axis *doesn't define a unique coord system in the rest frame!*
       I have to make an extra choice of axis to reduce to unique axis
    */
    
    const std::vector< double > betaVec     = sh.GetBetaVec( );
    const std::vector< double > dk4V        = sh.GetDecay4VX( );
    const std::vector< double > * minCentre = genie::HNL::MINERvAGeom::GetMINERvACentre( );
	
    const double sx = minCentre->at(0) - dk4V.at(1);
    const double sy = minCentre->at(1) - dk4V.at(2);
    const double sz = minCentre->at(2) - dk4V.at(3);
    const double sm = std::sqrt( sx*sx + sy*sy + sz*sz );

    const TVector3* restAxis = new TVector3( sx/sm, sy/sm, sz/sm );
    return restAxis;
}

// translate TLorentzVector between rest <--> lab frames
TLorentzVector* genie::HNL::decayKinematics::RestToLabFrame( genie::HNL::SimpleHNL sh, TLorentzVector* rest4V ){
    // first, HNL betaVec in lab frame
    const std::vector< double > betaVec = sh.GetBetaVec( );
    const TVector3 * betaTVec = new TVector3( -betaVec.at(0), -betaVec.at(1), -betaVec.at(2) ); // rest --> lab boosts by -beta
    TLorentzVector * lab4V = new TLorentzVector();
    lab4V->SetPxPyPzE( rest4V->Px(), rest4V->Py(), rest4V->Pz(), rest4V->E() );
    lab4V->Boost( *betaTVec );
    delete betaTVec;
    return lab4V;
}

TLorentzVector* genie::HNL::decayKinematics::LabToRestFrame( genie::HNL::SimpleHNL sh, TLorentzVector* lab4V ){
    // first, HNL betaVec in lab frame
    const std::vector< double > betaVec = sh.GetBetaVec( );
    const TVector3 * betaTVec = new TVector3( betaVec.at(0), betaVec.at(1), betaVec.at(2) );     // lab --> rest boosts by +beta
    TLorentzVector * rest4V = new TLorentzVector();
    rest4V->SetPxPyPzE( lab4V->Px(), lab4V->Py(), lab4V->Pz(), lab4V->E() );
    rest4V->Boost( *betaTVec );
    delete betaTVec;
    return rest4V;
}

const double genie::HNL::decayKinematics::ExtractVarFromDifferentialGamma( const std::string name, const char * formChar,
					      const double x1, const double x2,
					      const double params[],
					      const int nSteps ){
    TF1 * varTF1 = new TF1( name.c_str(), formChar, x1, x2 );
    if( params != NULL ){
	int i = 0;
	while( *(params+i) != kEND ){ varTF1->SetParameter( i, *(params+i) ); i++; }
    }

    // we have dG/dv ==> 1/G dG/dv is a pdf on v-space
    const double varInt = varTF1->Integral( x1, x2 );

    if( !fIsRngInitD ) initRandom( );
    const double ranthrow = fRngD->Uniform( );

    // return root of ( \int_{x_{1}}^{x} dv 1/G dG/dv - ranthrow )
    // G = \int_{x_{1}}^{x_{2}} dv dG/dv
    double currentInt = 0.0, prevInt = -1.0;
    double xx = x1, dx = ( x2 - x1 ) / nSteps;
    while( std::abs( currentInt - ranthrow ) < std::abs( prevInt - ranthrow )
	   && xx <= x2 ){
	prevInt = currentInt;
	currentInt += varTF1->Integral( xx, xx + dx ) / varInt; xx += dx; }

    delete varTF1;

    return xx;
}
