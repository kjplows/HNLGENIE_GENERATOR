#include "MINERvAGeom.h"

std::vector< double > * genie::HNL::MINERvAGeom::GetEntryPointID( const std::vector< double > * prodVtx,
								  const std::vector< double > * momVec ){
  // very barebones implementation - box centred around ID centre
  // RETHERE - this has *nothing* to do with actual MINERvA geometry!

  std::vector< double > * entryVec = new std::vector< double >();

  const double entryz = MINz - MINlenz / 2.0;

  // line is parametric, solve for t and return point of entry if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm; 
  const double tz   = ( entryz - pvz ) / ppz;

  LOG( "SimpleHNL", pDEBUG )
    << "WOLOLO entryz, pvz, ppz, tz = " << entryz << ", " << pvz << ", " << ppz << ", " << tz;
  
  // define the square at z = entryz = const and check if line intersects this.
  const double xlow  = MINx - MINlenx / 2.0;
  const double ylow  = MINx - MINlenx / 2.0;
  const double xhigh = MINx + MINlenx / 2.0;
  const double yhigh = MINx + MINlenx / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;
  
  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  LOG( "SimpleHNL", pDEBUG)
    << "xt, yt | [xlow, xhigh] | [ylow, yhigh] = " << xt << ", " << yt << " | "
    << "[" << xlow << ", " << xhigh << "]" << " | "
    << "[" << ylow << ", " << yhigh << "]";

  bool didIntersectID = ( xt <= xhigh && xt >= xlow ) && ( yt <= yhigh && yt >= ylow );
  if( didIntersectID ){
    entryVec->emplace_back( xt );
    entryVec->emplace_back( yt );
    entryVec->emplace_back( tz );
    return entryVec;
  }
  else{
    entryVec->emplace_back( -999.9 );
    entryVec->emplace_back( -999.9 );
    entryVec->emplace_back( -999.9 );
  }
  return entryVec;
}

std::vector< double > * genie::HNL::MINERvAGeom::GetExitPointID( const std::vector< double > * prodVtx,
								 const std::vector< double > * momVec ){
  // very barebones implementation - box centred around ID centre
  // RETHERE - this has *nothing* to do with actual MINERvA geometry!
  // TODO: add in side! Flag it if side exit?

  std::vector< double > * exitVec = new std::vector< double >();

  const double exitz = MINz + MINlenz / 2.0; // if exits out the back. Not necessary.

  // line is parametric, solve for t and return point of exit if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm;
  const double tz   = ( exitz - pvz ) / ppz;
  
  // define the square at z = exitz = const and check if line intersects this.
  const double xlow  = MINx - MINlenx / 2.0;
  const double ylow  = MINx - MINlenx / 2.0;
  const double xhigh = MINx + MINlenx / 2.0;
  const double yhigh = MINx + MINlenx / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;
  
  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  bool didIntersectID = ( xt <= xhigh && xt >= xlow ) && ( yt <= yhigh && yt >= ylow );
  if( didIntersectID ){
    exitVec->emplace_back( xt );
    exitVec->emplace_back( yt );
    exitVec->emplace_back( tz );
    return exitVec;
  }
  else{
    exitVec->emplace_back( -999.9 );
    exitVec->emplace_back( -999.9 );
    exitVec->emplace_back( -999.9 );
  }
  return exitVec;
}
