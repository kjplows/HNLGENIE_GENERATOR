//----------------------------------------------------------------------------
/*!

  Steps HNL forward by time-step and determines if it's decayed yet
  If inclusive: just pick position of vertex
  If exclusive: also query which channel ran out first

\namespace  genie::HNL::Selector

\brief      Vertex position calculator

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 10th, 2021

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------

#ifndef JSTEPPER_H
#define JSTEPPER_H

// -- ROOT includes

#include "TRandom3.h"

// -- GENIE includes

#include "Conventions/Constants.h"
#include "Conventions/Units.h"
//#include "HNLAuxiliary/Enums.h"    
//#include "HNLAuxiliary/SimpleHNL.h"
#include "Messenger/Messenger.h"

#include "Enums.h"    
#include "SimpleHNL.h"

namespace gu  = ::genie::units;
namespace gc  = ::genie::constants;
namespace gh  = ::genie::HNL;
namespace ghe = ::genie::HNL::enums;

namespace genie {
namespace HNL {

    class SimpleHNL;

    namespace Selector {

	extern TRandom3 * fRng;
	extern bool fIsRngInit;
	
	extern std::map< ghe::HNLDecay_t, double > fCounterMap;
	const double fdt = 0.01 * gu::nanosecond; // in lab frame

	inline void initRandom( ) { fRng = new TRandom3(0); fIsRngInit = true; }

	// inclusive method stepper
	void PropagateTilDecay( gh::SimpleHNL sh ); // step 1/3, see Selector.h for 2/3

	// exclusive method stepper
	void PropagateAndSelectChannel( gh::SimpleHNL sh );

	// empty the vector of counters
	void emptyCounters( );

	// populate the vector of counters
	void fillCounters( std::map< ghe::HNLDecay_t, double > gammaMap );

    } // namespace Selector
    
} // namespace HNL
} // namespace genie

#endif // #ifndef JSTEPPER_H
