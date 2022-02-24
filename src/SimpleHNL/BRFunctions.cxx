#include "BRFunctions.h"

// Get Coloma et al's form factor functions
double genie::HNL::Selector::GetColomaF1( double x ) {
  if( x < 0. || x > 0.5 ) { LOG( "SimpleHNL", pERROR ) << "BRFunctions::GetColomaF1:: Illegal x = " << x; exit( 3 ); }
  if( x == 0.5 ) return 0.;
  int i = x/genie::HNL::Selector::PARTWIDTH;
  if( x - i*genie::HNL::Selector::PARTWIDTH ==0 ) return genie::HNL::Selector::ColomaF1[i];
  return 1./2. * ( genie::HNL::Selector::ColomaF1[i] + genie::HNL::Selector::ColomaF1[i+1] );
}

double genie::HNL::Selector::GetColomaF2( double x ) {
  if( x < 0. || x > 0.5 ) { LOG( "SimpleHNL", pERROR ) << "BRFunctions::GetColomaF2:: Illegal x = " << x; exit( 3 ); }
  if( x == 0.5 ) return 0.;
  int i = x/genie::HNL::Selector::PARTWIDTH;
  if( x - i*genie::HNL::Selector::PARTWIDTH==0 ) return genie::HNL::Selector::ColomaF2[i];
  return 1./2. * ( genie::HNL::Selector::ColomaF2[i] + genie::HNL::Selector::ColomaF2[i+1] );
}

// total decay widths, various channels
double genie::HNL::Selector::DWidth_PiZeroAndNu( const double M, const double Ue42, const double Umu42, const double Ut42 ) {
  const double x       = genie::HNL::utils::MassX( mPi0, M );
  const double preFac  = GF2 * M*M*M / ( 32. * pi );
  const double kinPart = ( 1. - x*x ) * ( 1. - x*x );
  return preFac * ( Ue42 + Umu42 + Ut42 ) * fpi2 * kinPart;
}

double genie::HNL::Selector::DWidth_PiAndLepton( const double M, const double Ua42, const double ma ) {
  const double xPi     = genie::HNL::utils::MassX( mPi, M );
  const double xLep    = genie::HNL::utils::MassX( ma, M );
  const double preFac  = GF2 * M*M*M / ( 16. * pi );
  const double kalPart = TMath::Sqrt( genie::HNL::utils::Kallen( 1, xPi*xPi, xLep*xLep ) );
  const double othPart = 1. - xPi*xPi - xLep*xLep * ( 2. + xPi*xPi - xLep*xLep );

  /*
    LOG("SimpleHNL", pDEBUG)
    << "\n\n!!! Pi and lepton stats: "
    << "\n!!! M, Ua42, ma = " << M << ", " << Ua42 << ", " << ma
    << "\n!!! xPi = " << xPi
    << "\n!!! xLep = " << xLep
    << "\n!!! preFac = " << preFac
    << "\n!!! kalPart = " << kalPart
    << "\n!!! othPart = " << othPart << "\n\n";
  */

  return preFac * fpi2 * Ua42 * Vud2 * kalPart * othPart;
}

double genie::HNL::Selector::DWidth_Invisible( const double M, const double Ue42, const double Umu42, const double Ut42 ) {
  const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
  return preFac * ( Ue42 + Umu42 + Ut42 );
}

double genie::HNL::Selector::DWidth_SameLepton( const double M, const double Ue42, const double Umu42, const double Ut42, const double mb, bool bIsMu ) {
  const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
  const double x      = genie::HNL::utils::MassX( mb, M );
  const double f1     = GetColomaF1( x );
  const double f2     = GetColomaF2( x );
  const double C1Part = ( Ue42 + Umu42 + Ut42 ) * f1 * BR_C1;
  const double C2Part = ( Ue42 + Umu42 + Ut42 ) * f2 * BR_C2;
  const double D1Part = bIsMu ? 2. * s2w * Umu42 * f1 : 2. * s2w * Ue42 * f1;
  const double D2Part = bIsMu ? s2w * Umu42 * f2 : s2w * Ue42 * f2;
  return preFac * ( C1Part + C2Part + D1Part + D2Part );
}

double genie::HNL::Selector::DWidth_DiffLepton( const double M, const double Ua42, const double Ub42, const int IsMajorana ) {
  const double preFac = GF2 * TMath::Power( M, 5. ) / ( 192. * pi*pi*pi );
  const double x = genie::HNL::utils::MassX( mMu, M );
  const double kinPol = 1. - 8. * x*x + 8. * TMath::Power( x, 6. ) - TMath::Power( x, 8. );
  const double kinLn  = -12. * TMath::Power( x, 4. ) * TMath::Log( x*x );
  const double kinPart = kinPol + kinLn;
  const double coupPart = IsMajorana ? Ua42 : Ua42 + Ub42; // 2nd diagram in Majorana case!
  return preFac * kinPart * coupPart;
}

double genie::HNL::Selector::DWidth_PiPi0Ell( const double M, const double ml,
					      const double Ue42, const double Umu42, const double Ut42,
					      const bool isElectron){ return 0.0; }
/*{
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
	    
  } */ //RETHERE must validate this!

double genie::HNL::Selector::DWidth_Pi0Pi0Nu( const double dummyArg ){ return 0.0; } //dummy!

// differential decay width for HNL channels!

void genie::HNL::Selector::Diff1Width_PiAndLepton_CosTheta( const double M, const double Ua42,
							    const double ml,
							    double &thePreFac, 
							    double &theCnstPart,
							    double &thePropPart ) {
  const double preFac   = 1. / ( 32.0 * pi * M*M*M );
  const double sqrKal   = std::sqrt( genie::HNL::utils::Kallen( M*M, mPi*mPi, ml*ml ) );
  const double formPart = fpi2 * Ua42 * Vud2 * GF2;
  const double parConst = std::pow( ( M*M - ml*ml ), 2.0 ) - mPi*mPi*( M*M + ml*ml );
  const double parCoeff = -1.0 * ( M*M - ml*ml ) * std::sqrt( genie::HNL::utils::Kallen( M*M, mPi*mPi, ml*ml ) );
  
  thePreFac   = preFac * sqrKal * formPart;
  theCnstPart = parConst;
  thePropPart = parCoeff; // modulo |P| * cos(theta)
}

// formula for N --> pi pi0 ell decay rate
double genie::HNL::Selector::PiPi0EllForm( double *x, double *par ){
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
