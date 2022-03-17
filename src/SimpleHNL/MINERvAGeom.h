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

#include "Conventions/Constants.h"
#include "Conventions/Units.h"
#include "Messenger/Messenger.h"

namespace genie {
namespace HNL {

  namespace MINERvAGeom {

    // defines MINERvA centre (centre of tracker) in MINERvA coords
    const double MINtheta = 60.0 * genie::constants::kPi / 180.0;
    const double MINslope = 1.0 / std::tan( MINtheta );

    const double MINx = 0.0; //m
    const double MINy = 0.0;
    const double MINu = MINx * std::cos( MINtheta ) - MINy * std::sin( MINtheta );
    const double MINU = MINx * std::sin( MINtheta ) + MINy * std::cos( MINtheta );
    const double MINv = MINx * std::cos( -MINtheta ) - MINy * std::sin( -MINtheta );
    const double MINV = MINx * std::sin( -MINtheta ) + MINy * std::cos( -MINtheta );
    const double MINz = 7.201;

    const double MINlen  = 2.442; // m
    const double MINapo  = 0.850; // m
    const double MINside = 2.0 / std::sqrt(3.0) * MINapo;
    
    const double MINboxx = 0.0;
    const double MINboxy = 0.0;
    const double MINboxz = 2.0;

    // define a box of length 2m centred around... the MINERvA centre.
    const double MINboxlenx = 2.0; // dummy
    const double MINboxleny = 2.0;
    const double MINboxlenz = 2.0;

    inline std::vector< double > * GetMINERvACentre( ){
      std::vector< double > * thisVec = new std::vector< double >;
      thisVec->emplace_back( MINx );
      thisVec->emplace_back( MINy );
      thisVec->emplace_back( MINz );

      return (thisVec);
    }

    // figure out where HNL enters/exits various points in detector
    std::vector< double > * GetEntryPointIDBox( const std::vector< double > * prodVtx, const std::vector< double > * momVec );
    std::vector< double > * GetExitPointIDBox( const std::vector< double > * prodVtx, const std::vector< double > * momVec );

    std::vector< double > * GetEntryPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec );
    std::vector< double > * GetExitPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec );

  } // namespace MINERvAGeom

} // namespace HNL
} // namespace genie

#endif // #ifndef JMINERVAGEOM_H
