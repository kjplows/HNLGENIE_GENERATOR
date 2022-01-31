#include "BRFunctions.h"

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
