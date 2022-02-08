//-------------------------------------------------------------------
/*!

\namespace  genie::HNL::MINERvAGeom

\brief      Basic geometry constants defining MINERvA position + coords

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    January 20th, 2022

\cpright    ??? - TBD  

 */
//-------------------------------------------------------------------

#ifndef JMINERVAGEOM_H
#define JMINERVAGEOM_H

// -- C++ includes
#include <vector>

// -- GENIE includes

#include "Conventions/Units.h"

namespace genie {
namespace HNL {

  namespace MINERvAGeom {

    // placeholders! placeholders, placeholders
    // defines MINERvA centre (centre of tracker) in MINERvA coords
    const double MINx = 0.0 * genie::units::m;
    const double MINy = 0.0 * genie::units::m;
    const double MINz = 2.5 * genie::units::m;

    inline std::vector< double > * GetMINERvACentre( ){
      std::vector< double > * thisVec = new std::vector< double >;
      thisVec->emplace_back( MINx );
      thisVec->emplace_back( MINy );
      thisVec->emplace_back( MINz );

      return (thisVec);
    }

  } // namespace MINERvAGeom

} // namespace HNL
} // namespace genie

#endif // #ifndef JMINERVAGEOM_H
