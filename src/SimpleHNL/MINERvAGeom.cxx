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
    << "entryz, pvz, ppz, tz = " << entryz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";
  
  // define the square at z = entryz = const and check if line intersects this.
  const double xlow  = MINx - MINlenx / 2.0;
  const double ylow  = MINy - MINleny / 2.0;
  const double zlow  = MINz - MINlenz / 2.0;
  const double xhigh = MINx + MINlenx / 2.0;
  const double yhigh = MINy + MINleny / 2.0;
  const double zhigh = MINz + MINlenz / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;

  LOG( "SimpleHNL", pDEBUG )
    << "pvx, pvy, ppx, ppy = " << pvx << ", " << pvy << " [m] , " << ppx << ", " << ppy << " [GeV / GeV]";
  
  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  LOG( "SimpleHNL", pDEBUG)
    << "xt, yt | [xlow, xhigh] | [ylow, yhigh] = " << xt << ", " << yt << " | "
    << "[" << xlow << ", " << xhigh << "]" << " | "
    << "[" << ylow << ", " << yhigh << "]";

  bool didIntersectID = ( xt <= xhigh && xt >= xlow ) && ( yt <= yhigh && yt >= ylow );
  if( didIntersectID ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters the front of the ID at ( " 
      << xt << ", " << yt << ", " << entryz << " ) [m]";
    
    entryVec->emplace_back( xt );
    entryVec->emplace_back( yt );
    entryVec->emplace_back( entryz );
    entryVec->emplace_back( 0.0 ); //enters the front
    return entryVec;
  }

  // check to see if entered from x side
  const int ppxMod = ( ppx > 0 ) ? 1 : -1;
  const int ppyMod = ( ppy > 0 ) ? 1 : -1;
  
  // check x
  const double entryx = MINx + ppxMod * MINlenx / 2.0;
  const double tx = ( entryx - pvx ) / ppx;
  const double yxt = pvy + tx * ppy;
  const double zxt = pvz + tx * ppz;
  
  bool didEnterX = ( yxt <= yhigh && yxt >= ylow ) && ( zxt <= zhigh && zxt >= zlow );
  
  if( didEnterX ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters out the X side of the ID at ( "
      << entryx << ", " << yxt << ", " << zxt << " ) [m]"
      << "\nwith tx = " << tx << " [m]";

    entryVec->emplace_back( entryx );
    entryVec->emplace_back( yxt );
    entryVec->emplace_back( zxt );
    entryVec->emplace_back( ppxMod * 1.0 ); // enters one of the two x faces
    return entryVec;
  }
    
  // check y
  const double entryy = MINy + ppyMod * MINleny / 2.0;
  const double ty = ( entryy - pvy ) / ppy;
  const double xyt = pvx + ty * ppx;
  const double zyt = pvz + ty * ppz;

  bool didEnterY = ( xyt <= xhigh && xyt >= xlow ) && ( zyt <= zhigh && zyt >= zlow );
  
  if( didEnterY ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters out the Y side of the ID at ( "
      << xyt << ", " << entryy << ", " << zyt << " ) [m]"
      << "\nwith ty = " << ty << " [m]";

    entryVec->emplace_back( xyt );
    entryVec->emplace_back( entryy );
    entryVec->emplace_back( zyt );
    entryVec->emplace_back( ppyMod * 2.0 ); // enters one of the two y faces
    return entryVec;
  }
  
  LOG( "SimpleHNL", pDEBUG )
    << "This HNL does not enter the ID from the front.";
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );

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

  LOG( "SimpleHNL", pDEBUG )
    << "exitz, pvz, ppz, tz = " << exitz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";
  
  // define the square at z = exitz = const and check if line intersects this.
  const double xlow  = MINx - MINlenx / 2.0;
  const double ylow  = MINy - MINleny / 2.0;
  const double zlow  = MINz - MINlenz / 2.0;
  const double xhigh = MINx + MINlenx / 2.0;
  const double yhigh = MINy + MINleny / 2.0;
  const double zhigh = MINz + MINlenz / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;

  LOG( "SimpleHNL", pDEBUG )
    << "EXIT pvx, pvy, ppx, ppy = " << pvx << ", " << pvy << " [m] , " << ppx << ", " << ppy << " [GeV / GeV]";
  
  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  LOG( "SimpleHNL", pDEBUG)
    << "EXIT xt, yt | [xlow, xhigh] | [ylow, yhigh] = " << xt << ", " << yt << " | "
    << "[" << xlow << ", " << xhigh << "]" << " | "
    << "[" << ylow << ", " << yhigh << "]";

  bool didExitBack = ( xt <= xhigh && xt >= xlow ) && ( yt <= yhigh && yt >= ylow );
  if( didExitBack ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the back of the ID at ( "
      << xt << ", " << yt << ", " << exitz << " ) [m]";

    exitVec->emplace_back( xt );
    exitVec->emplace_back( yt );
    exitVec->emplace_back( exitz );
    exitVec->emplace_back( 0.0 ); // does not exit out the side
    return exitVec;
  }

  // check to see if it exits out the side
  const int ppxMod = ( ppx > 0 ) ? 1 : -1;
  const int ppyMod = ( ppy > 0 ) ? 1 : -1;
  
  // check x
  const double exitx = MINx + ppxMod * MINlenx / 2.0;
  const double tx = ( exitx - pvx ) / ppx;
  const double yxt = pvy + tx * ppy;
  const double zxt = pvz + tx * ppz;
  
  bool didExitX = ( yxt <= yhigh && yxt >= ylow ) && ( zxt <= zhigh && zxt >= zlow );
  
  if( didExitX ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the X side of the ID at ( "
      << exitx << ", " << yxt << ", " << zxt << " ) [m]"
      << "\nwith tx = " << tx << " [m]";

    exitVec->emplace_back( exitx );
    exitVec->emplace_back( yxt );
    exitVec->emplace_back( zxt );
    exitVec->emplace_back( ppxMod * 1.0 ); // exits out one of the two x faces
    return exitVec;
  }
    
  // check y
  const double exity = MINy + ppyMod * MINleny / 2.0;
  const double ty = ( exity - pvy ) / ppy;
  const double xyt = pvx + ty * ppx;
  const double zyt = pvz + ty * ppz;

  bool didExitY = ( xyt <= xhigh && xyt >= xlow ) && ( zyt <= zhigh && zyt >= zlow );
  
  if( didExitY ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the Y side of the ID at ( "
      << xyt << ", " << exity << ", " << zyt << " ) [m]"
      << "\nwith ty = " << ty << " [m]";

    exitVec->emplace_back( xyt );
    exitVec->emplace_back( exity );
    exitVec->emplace_back( zyt );
    exitVec->emplace_back( ppyMod * 2.0 ); // exits out one of the two y faces
    return exitVec;
  }

  LOG( "SimpleHNL", pDEBUG )
    << "There's a mistake here - the *trajectory* enters the ID but does not exit it. This is geometrically impossible.";
  exitVec->emplace_back( -999.9 );
  exitVec->emplace_back( -999.9 );
  exitVec->emplace_back( -999.9 );
  exitVec->emplace_back( -999.9 );

  return exitVec;
}
