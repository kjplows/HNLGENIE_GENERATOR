//----------------------------------------------------------------------------
/*!

  Provides the typedef for the allowed decay channels

\namespace  genie::HNL::Selector

\brief      Typedef enum HNL decay channels

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 9th, 2021

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------
/*
  TODO: Check if the Majorana channels need their own processes!
*/
//----------------------------------------------------------------------------

#ifndef JDECAYCHANNELS_H
#define JDECAYCHANNELS_H

namespace genie {
namespace HNL {

    namespace Selector {
	
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
	
    } // namespace Selector

} // namespace HNL
} // namespace genie

#endif // #ifndef JDECAYCHANNELS_H
