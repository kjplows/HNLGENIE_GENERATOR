//----------------------------------------------------------------------------
/*!

  Definitions of the auxiliary functions needed
  to calculate the decay widths of HNL to various channels

\namespace  genie::HNL::Selector

\brief      Decay widths of HNL

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 3rd, 2021

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------
// TODO: add in decays to ~pi pi0 ell~ and pi0 pi0 nuell
//       Figure out how to read Ue4, Umu4, Ut4 from config
//----------------------------------------------------------------------------

#ifndef JBRFUNCTIONS_H
#define JBRFUNCTIONS_H

// -- C++ includes
#include <TMath.h>

// -- ROOT includes
#include "TF1.h"
#include "TF2.h"
#include "TMath.h"

// -- GENIE includes
#include "Conventions/Constants.h"
#include "Conventions/Units.h"
#include "Messenger/Messenger.h"

#include "ColomaTables.h"
#include "KinUtils.h"

namespace gc  = ::genie::constants;
namespace gu  = ::genie::units;
namespace ghu = ::genie::HNL::utils;

namespace genie {
namespace HNL {

    namespace Selector {

      namespace ghs = ::genie::HNL::Selector;

	// physical constants, PDG 2021
	static const double s2w = 0.22767; // Weinberg mixing angle consistent with genie kMw, kMz
	static const double GF  = gc::kGF; // GeV^{-2}
	static const double GF2 = GF*GF;
	static const double pi  = gc::kPi;
	static const double fpi = 0.130 * gu::GeV; // GeV
	static const double fpi2 = fpi*fpi;
    
	static const double mPi0 = gc::kPi0Mass;
	static const double mPi  = gc::kPionMass;
	static const double mMu  = gc::kMuonMass;

	static const double Vud  = 0.9737; // PDG 2021
	static const double Vud2 = Vud * Vud;

	// PMNS matrix elements, assumed real
	// using CV values from v5.1 of www.nu-fit.org - accessed Jan 25th 2022
	// using SK-atm data but ignoring correlations!
	static const double Ue1 = 1./2. * ( 0.801 + 0.845 );
	static const double Ue2 = 1./2. * ( 0.513 + 0.579 );
	static const double Ue3 = 1./2. * ( 0.144 + 0.156 );
	static const double Um1 = 1./2. * ( 0.244 + 0.499 );
	static const double Um2 = 1./2. * ( 0.505 + 0.693 );
	static const double Um3 = 1./2. * ( 0.631 + 0.763 );
	static const double Ut1 = 1./2. * ( 0.272 + 0.518 );
	static const double Ut2 = 1./2. * ( 0.471 + 0.669 );
	static const double Ut3 = 1./2. * ( 0.623 + 0.761 );
    
	static const double BR_C1 = 1./4. * ( 1. - 4. * s2w + 8. * s2w * s2w );
	static const double BR_C2 = 1./2. * ( -s2w + 2. * s2w * s2w );

	// kinematic functions

	// placeholder
	static const double Ue4 = 1.0e-2;
	static const double Um4 = 1.0e-2;
	static const double Ut4 = 0.0;

	inline double GetColomaF1( double x ) {
	    if( x < 0. || x > 0.5 ) { LOG( "SimpleHNL", pERROR ) << "BRFunctions::GetColomaF1:: Illegal x = " << x; exit( 3 ); }
	    if( x == 0.5 ) return 0.;
	    int i = x/ghs::PARTWIDTH;
	    if( x - i*ghs::PARTWIDTH ==0 ) return ghs::ColomaF1[i];
	    return 1./2. * ( ghs::ColomaF1[i] + ghs::ColomaF1[i+1] );
	}
    
	inline double GetColomaF2( double x ) {
	    if( x < 0. || x > 0.5 ) { LOG( "SimpleHNL", pERROR ) << "BRFunctions::GetColomaF2:: Illegal x = " << x; exit( 3 ); }
	    if( x == 0.5 ) return 0.;
	    int i = x/ghs::PARTWIDTH;
	    if( x - i*ghs::PARTWIDTH==0 ) return ghs::ColomaF2[i];
	    return 1./2. * ( ghs::ColomaF2[i] + ghs::ColomaF2[i+1] );
	}

	//============================================
	// total decay widths for HNL channels
	//============================================
	
	// N --> pi0 + nu_\alpha
	inline double DWidth_PiZeroAndNu( const double M, const double Ue42, const double Umu42, const double Ut42 ) {
	    const double x       = ghu::MassX( mPi0, M );
	    const double preFac  = GF2 * M*M*M / ( 32. * pi );
	    const double kinPart = ( 1. - x*x ) * ( 1. - x*x );
	    return preFac * ( Ue42 + Umu42 + Ut42 ) * fpi2 * kinPart;
	}
	
	// N --> pi^{\pm} + \ell_{\alpha}
	inline double DWidth_PiAndLepton( const double M, const double Ua42, const double ma ) {
	    const double xPi     = ghu::MassX( mPi, M );
	    const double xLep    = ghu::MassX( ma, M );
	    const double preFac  = GF2 * M*M*M / ( 16. * pi );
	    const double kalPart = TMath::Sqrt( ghu::Kallen( 1, xPi, xLep ) );
	    const double othPart = 1. - xPi*xPi - xLep*xLep * ( 2. + xPi*xPi - xLep*xLep );
	    return preFac * fpi2 * Ua42 * Vud2 * kalPart * othPart;
	}

	// invisible
	inline double DWidth_Invisible( const double M, const double Ue42, const double Umu42, const double Ut42 ) {
	    const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
	    return preFac * ( Ue42 + Umu42 + Ut42 );
	}

	// N --> nu + \ell_{\beta} \ell_{\beta} , \beta = e or mu
	inline double DWidth_SameLepton( const double M, const double Ue42, const double Umu42, const double Ut42, const double mb, bool bIsMu ) {
	    const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
	    const double x      = ghu::MassX( mb, M );
	    const double f1     = GetColomaF1( x );
	    const double f2     = GetColomaF2( x );
	    const double C1Part = ( Ue42 + Umu42 + Ut42 ) * f1 * BR_C1;
	    const double C2Part = ( Ue42 + Umu42 + Ut42 ) * f2 * BR_C2;
	    const double D1Part = bIsMu ? 2. * s2w * Umu42 * f1 : 2. * s2w * Ue42 * f1;
	    const double D2Part = bIsMu ? s2w * Umu42 * f2 : s2w * Ue42 * f2;
	    return preFac * ( C1Part + C2Part + D1Part + D2Part );
	}

	// N --> nu + \ell_{\alpha}^{-} + \ell_{\beta}^{+}, \alpha != \beta, \alpha = e or mu
	// alpha is the "correct" lepton number sign ( Q < 0 for N, Q > 0 for Nbar)
	inline double DWidth_DiffLepton( const double M, const double Ua42, const double Ub42, const double IsMajorana ) {
	    const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
	    const double x = ghu::MassX( mMu, M );
	    const double kinPol = 1. - 8. * x*x + 8. * TMath::Power( x, 6. ) - TMath::Power( x, 8. );
	    const double kinLn  = -12. * TMath::Power( x, 4. ) * TMath::Log( x*x );
	    const double kinPart = kinPol + kinLn;
	    const double coupPart = IsMajorana ? Ua42 : Ua42 + Ub42; // 2nd diagram in Majorana case!
	    return preFac * kinPart * coupPart;
	}

	// formula for N --> pi pi0 ell decay rate
	double PiPi0EllForm( double *x, double *par ){
	    double MN = par[0];
	    double MMu = par[1];
	    double MPi = par[2];
	    double MPi0 = par[3];

	    double Emu = x[0];
	    double Epi = x[1];

	    double ETerm =
		std::sqrt( Emu*Emu - MMu*MMu ) *
		std::sqrt( Epi*Epi - MPi*MPi ) *
		std::sqrt( std::pow( ( MN - Emu - Epi ), 2.0 ) - MPi0*MPi0 ) / ( MN - Emu - Epi );

	    double FracNum1 = MN*MN - 2.0*( MN-Emu-Epi )*MN + MPi0*MPi0;
	    double FracNum2 = MN*MN - 2.0*Emu*MN + 2.0*MMu*MMu;
	    double FracNum3 = MN*MN - MPi0*MPi0;
	    double FracNum4 = MN*MN - 2.0*( MN-Emu-Epi )*MN + MPi0*MPi0 + MMu*MMu - MPi*MPi;
	    double FracNum = FracNum1*FracNum2 - FracNum3*FracNum4;
	    double FracDen = std::pow( MN*MN - 2.0*( MN - Emu - Epi ) * MN + MPi0*MPi0 , 2.0 );

	    return ETerm * FracNum / FracDen;
	}

	// N --> pi^\pm + pi^0 + \ell_{\alpha}^\mp, \alpha = e or mu
	inline double DWidth_PiPi0Ell( const double M, const double ml,
				       const double Ue42, const double Umu42, const double Ut42,
				       const bool isElectron = false ){
	    // because the actual decay width is very hard to integrate onto a full DWidth,
	    // build 2Differential and then integrate numerically
	    // using Simpson's method for 2D.

	    const double preFac = fpi2 * fpi2 * GF2 * GF2 * Vud2 * M / ( 32.0 * pi*pi*pi );
	    const double Ua1 = isElectron ? Ue1 : Um1;
	    const double Ua2 = isElectron ? Ue2 : Um2;
	    const double Ua3 = isElectron ? Ue3 : Um3;
	    const double Ua4 = isElectron ? std::sqrt( Ue42 ) : std::sqrt( Umu42 );
	    // assume all these to be real
	    const double bigMats =
		Ua1 * ( Ue4 * Ue1 + Um4 * Um1 + Ut4 * Ut1 ) +
		Ua2 * ( Ue4 * Ue2 + Um4 * Um2 + Ut4 * Ut2 ) +
		Ua3 * ( Ue4 * Ue3 + Um4 * Um3 + Ut4 * Ut3 );

	    // now limits
	    const double maxMu =
		( ( M - mPi0 ) * ( M - mPi0 ) - mPi*mPi + mMu*mMu ) / ( 2.0 * ( M - mPi0 ) );
	    const double maxPi =
		( ( M - mPi0 ) * ( M - mPi0 ) + mPi*mPi - mMu*mMu ) / ( 2.0 * ( M - mPi0 ) );

	    // gotta put in the formula
	    TF2 * f = new TF2( "f", PiPi0EllForm, mMu, maxMu, mPi, maxPi, 4 );
	    f->SetParameters( 0, M, 1, mMu, 2, mPi, 3, mPi0 );

	    // now we can use composite Simpson, iterating on both axes simultaneously
	    // This is like using Fubini over and over again for sampled Emu ==> integrate
	    // out Epi ==> Simpson again for Emu. Can see more at
	    // https://math.stackexchange.com/questions/1319892/simpsons-rule-for-double-integrals.

	    const int nSteps = 1000 + 1; // more than fine enough, 1k intervals
	    const double hEMu = ( maxMu - mMu ) / ( nSteps - 1 );
	    const double hEPi = ( maxPi - mPi ) / ( nSteps - 1 );
	    const double preSimp = hEMu * hEPi / ( 9.0 * ( nSteps - 1 ) * ( nSteps - 1 ) );

	    double intNow = 0.0;
	    for( int i = 0; i < nSteps; i++ ){
		for( int j = 0; j < nSteps; j++ ){
		    double midW = 0.0;
		    //determine midpoint coefficient for this step
		    if( i % (nSteps - 1) == 0 ){ // edge case i
			if( j % (nSteps - 1) == 0 ){ midW = 1.0; } // edge case j
			else if( j % 2 == 0 ){ midW = 2.0; } // even j
			else{ midW = 4.0; } // odd j
		    }
		    else if( i % (nSteps - 1) == 0 ){ // even i
			if( j % (nSteps - 1) == 0 ){ midW = 2.0; } // edge case j
			else if( j % 2 == 0 ){ midW = 4.0; } // even j
			else{ midW = 8.0; } // odd j
		    }
		    else{ // odd i
			if( j % (nSteps - 1) == 0 ){ midW = 4.0; } // edge case j
			else if( j % 2 == 0 ){ midW = 8.0; } // even j
			else{ midW = 16.0; } // odd j
		    }
		    // finally, evaluate f at this point
		    const double xev  = mPi + i * hEPi;
		    const double yev  = mMu + j * hEMu;
		    const double fev  = f->Eval( xev, yev );

		    // and add to integral
		    intNow += preSimp * midW * fev;
		}
	    }

	    intNow *= preFac * bigMats;

	    return intNow;
	    
	}

	//============================================
	// differential decay widths for HNL channels
	// want to *sample* kinematics from them so not double rtype
	//============================================

	// N --> pi^{\pm} + \ell_{\alpha}
	// d\Gamma / dcos(\theta), \theta = angle between polVec and pl
	inline void Diff1Width_PiAndLepton_CosTheta( const double M, const double Ua42,
						     const double ml,
						     double &thePreFac,
						     double &theCnstPart,
						     double &thePropPart ) {
	    const double preFac   = 1. / ( 32.0 * pi * M*M*M );
	    const double sqrKal   = std::sqrt( ghu::Kallen( M*M, mPi*mPi, ml*ml ) );
	    const double formPart = fpi2 * Ua42 * Vud2 * GF2;
	    const double parConst = std::pow( ( M*M - ml*ml ), 2.0 ) - mPi*mPi*( M*M + ml*ml );
	    const double parCoeff = -1.0 * ( M*M - ml*ml ) * std::sqrt( ghu::Kallen( M*M, mPi*mPi, ml*ml ) );

	    thePreFac   = preFac * sqrKal * formPart;
	    theCnstPart = parConst;
	    thePropPart = parCoeff; // modulo |P| * cos(theta)
	}
    
    } // namespace Selector

} // namespace HNL
} // namespace genie

#endif // #ifndef JBRFUNCTIONS_H
