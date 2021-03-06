//----------------------------------------------------------------------------
/*!

  All enums used in the HNL simulation (should) live here.

\namespace  genie::HNL::enums

\brief      Typedef enums

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    January 10th, 2022

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------
/*
  TODO: @channels: Check if the Majorana channels need their own processes!
*/
//----------------------------------------------------------------------------

#ifndef JENUMS_H
#define JENUMS_H

// -- C++ includes

#include <map>

// -- GENIE includes

#include "Conventions/Units.h"

namespace genie {

namespace HNL {

    namespace HNLenums {

	/// The HNL decay channels
	typedef enum t_HNLDecay {
	    
	    kInit          = -1, // dummy to initialise HNLDecay_t with
	    kPiMu          = 0,  // N --> \pi^{\pm} \mu^{\mp}
	    kPiE           = 1,  // N --> \pi^{\pm}   e^{\mp}
	    kPi0Nu         = 2,  // N --> \pi^{0}   \nu (any kind)
	    kNuNuNu        = 3,  // N --> 3 nus. Summed over all flavours
	    kNuMuMu        = 4,  // N --> nu_{a}    \mu^{\mp} \mu^{\pm}. W and Z interfere
	    kNuEE          = 5,  // N --> nu_{a}      e^{\mp}   e^{\pm}. W and Z interfere
	    kNuMuE         = 6,  // N --> nu_{\mu/e}  e^{\mp} \mu^{\pm}. Only W. Summed over nue and numu
	    kPiPi0E        = 7,  // N --> \pi^{\pm} \pi^{0}   e^{\mp}
	    kPiPi0Mu       = 8,  // N --> \pi^{\pm} \pi^{0} \mu^{\mp}
	    kPi0Pi0Nu      = 9,  // N --> \pi^{0}   \pi^{0} \nu (any kind)
	    kOther         = 99  // unknown decay 
	    
	} HNLDecay_t;

	/* // can't use strings in enum!
	/// Coupling configurations
	typedef enum t_coup {

	    kInit     = std::string("Init"),            // dummy for initialisation
	    kEqual    = std::string("EqualCouplings"),  // |U_e4|^2 : |U_mu4|^2 = 1:1
	    kMuon     = std::string("MuonOnly"),        // |U_e4|^2 : |U_mu4|^2 = 0:1
	    kElectron = std::string("ElectronOnly"),    // |U_e4|^2 : |U_mu4|^2 = 1:0
	    kOther    = std::string("OtherCouplings")   // Different ratio of e to mu
	    
	} coup_t;
	*/

	/// Coupling configuration indices
	typedef enum t_coupIdx {

	    kInitIdx     = -1,
	    kEqualIdx    = 0,
	    kMuonIdx     = 1,
	    kElectronIdx = 2,
	    kOtherIdx    = 3

	} coupIdx_t;

	/// mass points - 20 light + 10 medium + 20 heavy
	typedef enum t_massHyp {

	    kInitHyp    = 0,   // dummy for initialisation
	    kLight0Hyp  = 1,  
	    kLight1Hyp  = 2,  
	    kLight2Hyp  = 3,  
	    kLight3Hyp  = 4,  
	    kLight4Hyp  = 5,  
	    kLight5Hyp  = 6,  
	    kLight6Hyp  = 7,  
	    kLight7Hyp  = 8,  
	    kLight8Hyp  = 9,  
	    kLight9Hyp  = 10, 
	    kLightAHyp  = 11, 
	    kLightBHyp  = 12,  // pi --> N + mu threshold
	    kLightCHyp  = 13, 
	    kLightDHyp  = 14, 
	    kLightEHyp  = 15, 
	    kLightFHyp  = 16, 
	    kLightGHyp  = 17, 
	    kLightHHyp  = 18, 
	    kLightIHyp  = 19, 
	    kLightJHyp  = 20, 
	    kMedium0Hyp = 21, 
	    kMedium1Hyp = 22, 
	    kMedium2Hyp = 23,  // pi --> N + e threshold
	    kMedium3Hyp = 24, 
	    kMedium4Hyp = 25, 
	    kMedium5Hyp = 26, 
	    kMedium6Hyp = 27, 
	    kMedium7Hyp = 28, 
	    kMedium8Hyp = 29, 
	    kMedium9Hyp = 30, 
	    kHeavy0Hyp  = 31,  // N --> pi + mu threshold
	    kHeavy1Hyp  = 32, 
	    kHeavy2Hyp  = 33, 
	    kHeavy3Hyp  = 34, 
	    kHeavy4Hyp  = 35, 
	    kHeavy5Hyp  = 36, 
	    kHeavy6Hyp  = 37, 
	    kHeavy7Hyp  = 38, 
	    kHeavy8Hyp  = 39, 
	    kHeavy9Hyp  = 40,  // K --> N + mu threshold
	    kHeavyAHyp  = 41, 
	    kHeavyBHyp  = 42, 
	    kHeavyCHyp  = 43, 
	    kHeavyDHyp  = 44, 
	    kHeavyEHyp  = 45, 
	    kHeavyFHyp  = 46, 
	    kHeavyGHyp  = 47, 
	    kHeavyHHyp  = 48, 
	    kHeavyIHyp  = 49, 
	    kHeavyJHyp  = 50   // M > 493 depends on D which we do not model

	} massHyp_t;

	//std::map< massHyp_t, double > massHypMap; 
	//std::map< massHyp_t, double > BuildMassHypMap(void);

	typedef enum t_parent {

	    kNoPar = -1,
	    kAll   = 0,
	    kPion  = 1,
	    kKaon  = 2,
	    kMuon  = 3,
	    kNeuk  = 4
	    
	} parent_t;

	typedef enum t_nutype {

	    kNone = -1,
	    kNumu = 1,
	    kNumubar = 2,
	    kNue = 3,
	    kNuebar = 4
	    
	} nutype_t;

	typedef enum t_HNLPDG {

	    kPdgHMu = 1914,
	    kPdgHMubar = -1914,
	    kPdgHE = 1912,
	    kPdgHEbar = -1912

	} HNLPDG_t;

    } // namespace HNLenums

} // namespace HNL
} // namespace genie

#endif // #ifndef JENUMS_H
