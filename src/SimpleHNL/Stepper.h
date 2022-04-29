//----------------------------------------------------------------------------
/*!

  Steps HNL forward by time-step and determines if it's decayed yet
  If inclusive: just pick position of vertex
  If exclusive: also query which channel ran out first

\namespace  genie::HNL::HNLSelector

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

#include "Enums.h"    
#include "SimpleHNL.h"

namespace genie {
namespace HNL {

    class SimpleHNL;

    namespace HNLSelector {

        extern TRandom3 * fRng;
	extern bool fIsRngInit;
	
	extern std::map< genie::HNL::HNLenums::HNLDecay_t, double > fCounterMap;
	const double fdt = 0.01 * genie::units::nanosecond; // in lab frame

	inline void initRandom( ) { fRng = new TRandom3(0); fIsRngInit = true; }

	// inclusive method stepper
	std::vector< double > PropagateTilDecay( genie::HNL::SimpleHNL sh ); // returns decay 4-vertex

	// exclusive method stepper
	void PropagateAndSelectChannel( genie::HNL::SimpleHNL sh );

	// empty the vector of counters
	void emptyCounters( );

	// populate the vector of counters
	void fillCounters( std::map< genie::HNL::HNLenums::HNLDecay_t, double > gammaMap );

    } // namespace HNLSelector
    
} // namespace HNL
} // namespace genie

#endif // #ifndef JSTEPPER_H
