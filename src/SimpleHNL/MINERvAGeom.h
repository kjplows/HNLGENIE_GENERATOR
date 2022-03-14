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
#include <cmath>
#include <vector>

// -- GENIE includes

#include "Conventions/Units.h"
#include "Messenger/Messenger.h"

namespace genie {
namespace HNL {

  namespace MINERvAGeom {

    // placeholders! placeholders, placeholders
    // defines MINERvA centre (centre of tracker) in MINERvA coords
    const double MINx = 0.0;
    const double MINy = 0.0;
    const double MINz = 2.5;

    // define a box of length 2m centred around... the MINERvA centre.
    const double MINlenx = 2.0;
    const double MINleny = 2.0;
    const double MINlenz = 2.0;

    inline std::vector< double > * GetMINERvACentre( ){
      std::vector< double > * thisVec = new std::vector< double >;
      thisVec->emplace_back( MINx );
      thisVec->emplace_back( MINy );
      thisVec->emplace_back( MINz );

      return (thisVec);
    }

    // figure out where HNL enters/exits various points in detector
    std::vector< double > * GetEntryPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec );
    std::vector< double > * GetExitPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec );

  } // namespace MINERvAGeom

} // namespace HNL
} // namespace genie

#endif // #ifndef JMINERVAGEOM_H
