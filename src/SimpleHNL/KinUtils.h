//----------------------------------------------------------------------------
/*!

\namespace  genie::HNL::utils

\brief      Useful kinematic functions

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    January 11th, 2022

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------

#ifndef JKINUTILS_H
#define JKINUTILS_H

// -- GENIE includes
#include "Messenger/Messenger.h"

namespace genie{
namespace HNL {

    namespace utils {

	inline double MassX( double m1, double m2 ) {
	    if( m2 <= 0. || m1 < 0.) { LOG( "SimpleHNL", pERROR ) << "BRFunctions::MassX:: Illegal masses m1 = " << m1 << ", m2 = " << m2; exit( 3 ); }
	    return m1 / m2;
	}
	
	inline double Kallen( double x, double y, double z ) {
	    return x*x + y*y + z*z - 2. * ( x*y + y*z + z*x );
	}
	
    } // namespace utils

} //namespace HNL
} //namespace genie

#endif // #ifndef JKINUTILS_H
