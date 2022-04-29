#include "MINERvAGeom.h"
#include "Messenger/Messenger.h"

std::vector< double > * genie::HNL::HNLMINERvAGeom::GetEntryPointIDBox( const std::vector< double > * prodVtx,
									const std::vector< double > * momVec ){
  // very barebones implementation - box centred around ID centre
  // RETHERE - this has *nothing* to do with actual MINERvA geometry!

  std::vector< double > * entryVec = new std::vector< double >();

  const double entryz = MINboxz - MINboxlenz / 2.0;

  // line is parametric, solve for t and return point of entry if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm; 
  const double tz   = ( entryz - pvz ) / ppz;

  LOG( "SimpleHNL", pDEBUG )
    << "entryz, pvz, ppz, tz = " << entryz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";
  
  // define the square at z = entryz = const and check if line intersects this.
  const double xlow  = MINboxx - MINboxlenx / 2.0;
  const double ylow  = MINboxy - MINboxleny / 2.0;
  const double zlow  = MINboxz - MINboxlenz / 2.0;
  const double xhigh = MINboxx + MINboxlenx / 2.0;
  const double yhigh = MINboxy + MINboxleny / 2.0;
  const double zhigh = MINboxz + MINboxlenz / 2.0;

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
  const double entryx = MINboxx + ppxMod * MINboxlenx / 2.0;
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
  const double entryy = MINboxy + ppyMod * MINboxleny / 2.0;
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
    << "This HNL does not enter the ID.";
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );

  return entryVec;
}

std::vector< double > * genie::HNL::HNLMINERvAGeom::GetExitPointIDBox( const std::vector< double > * prodVtx,
								    const std::vector< double > * momVec ){
  // very barebones implementation - box centred around ID centre
  // RETHERE - this has *nothing* to do with actual MINERvA geometry!

  std::vector< double > * exitVec = new std::vector< double >();

  const double exitz = MINboxz + MINboxlenz / 2.0; // if exits out the back.

  // line is parametric, solve for t and return point of exit if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm;
  const double tz   = ( exitz - pvz ) / ppz;

  LOG( "SimpleHNL", pDEBUG )
    << "exitz, pvz, ppz, tz = " << exitz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";
  
  // define the square at z = exitz = const and check if line intersects this.
  const double xlow  = MINboxx - MINboxlenx / 2.0;
  const double ylow  = MINboxy - MINboxleny / 2.0;
  const double zlow  = MINboxz - MINboxlenz / 2.0;
  const double xhigh = MINboxx + MINboxlenx / 2.0;
  const double yhigh = MINboxy + MINboxleny / 2.0;
  const double zhigh = MINboxz + MINboxlenz / 2.0;

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
  const double exitx = MINboxx + ppxMod * MINboxlenx / 2.0;
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
  const double exity = MINboxy + ppyMod * MINboxleny / 2.0;
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

std::vector< double > * genie::HNL::HNLMINERvAGeom::GetEntryPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec ){
  // checks against a hexagonal FV of ID size

  std::vector< double > * entryVec = new std::vector< double >();

  const double entryz = MINz - MINlen / 2.0;

  // line is parametric, solve for t and return point of entry if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm; 
  const double tz   = ( entryz - pvz ) / ppz;

  LOG( "SimpleHNL", pDEBUG )
    << "entryz, pvz, ppz, tz = " << entryz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";

  // there are now 3+1 pairs of sides to compare against
  // define sides of 'coord' = const
  const double rlow  = MINapo;
  const double rhigh = 2.0 * MINapo / std::tan( MINtheta );
  const double zlow  = MINz - MINlen / 2.0;
  const double zhigh = MINz + MINlen / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;

  const double pvu = pvx * std::cos( MINtheta ) - pvy * std::sin( MINtheta ); // u coord
  const double pvU = pvx * std::sin( MINtheta ) + pvy * std::cos( MINtheta ); // perp u coord
  const double ppu = ppx * std::cos( MINtheta ) - ppy * std::sin( MINtheta );
  const double ppU = ppx * std::sin( MINtheta ) + ppy * std::cos( MINtheta );

  const double pvv = pvx * std::cos( -MINtheta ) - pvy * std::sin( -MINtheta ); // v coord
  const double pvV = pvx * std::sin( -MINtheta ) + pvy * std::cos( -MINtheta ); // perp v coord
  const double ppv = ppx * std::cos( -MINtheta ) - ppy * std::sin( -MINtheta );
  const double ppV = ppx * std::sin( -MINtheta ) + ppy * std::cos( -MINtheta );

  LOG( "SimpleHNL", pDEBUG )
    << "pvx, pvy, ppx, ppy = " << pvx << ", " << pvy << " [m] , " << ppx << ", " << ppy << " [GeV / GeV]";

  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  const double ut = xt * std::cos( MINtheta ) - yt * std::sin( MINtheta );
  const double vt = xt * std::cos( -MINtheta ) - yt * std::sin( -MINtheta );

  // check if point is in apothem
  
  bool didIntersectID = ( ( std::abs( xt ) <= MINapo ) &&
			  ( std::abs( ut ) <= MINapo ) &&
			  ( std::abs( vt ) <= MINapo ) );
  
  LOG( "SimpleHNL", pDEBUG )
    << "\nxt, yt = " << xt << ", " << yt
    << "\nut, vt " << ut << ", " << vt
    << "\n|xt|, |ut|, |vt| = " << std::abs( xt ) << ", " << std::abs( ut ) << ", " << std::abs( vt ) << " | MINapo = " << MINapo
    << "\ndidIntersectID = " << didIntersectID;

  if( didIntersectID ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters the front of the ID at ( "
      << xt << ", " << yt << ", " << entryz << " ) [m]";

    entryVec->emplace_back( xt );
    entryVec->emplace_back( yt );
    entryVec->emplace_back( entryz );
    entryVec->emplace_back( 0.0 ); // enters the front
    return entryVec;
  }

  // check to see if entered from x side
  const int ppxMod = ( ppx > 0 ) ? 1 : -1;
  const int ppuMod = ( ppu > 0 ) ? 1 : -1;
  const int ppvMod = ( ppv > 0 ) ? 1 : -1;

  // check x=const
  const double entryx = MINx + ppxMod * MINapo;
  const double tx = ( entryx - pvx ) / ppx;
  const double yxt = pvy + tx * ppy;
  const double zxt = pvz + tx * ppz;

  bool didEnterx = ( std::abs( yxt ) <= MINside / 2.0 ) && ( zxt <= zhigh && zxt >= zlow );

  if( didEnterx ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters out the x=const ( = " << entryx << " ) side of the ID at ( "
      << entryx << ", " << yxt << ", " << zxt << " ) [m]"
      << "\nwith tx = " << tx << " [m]";

    entryVec->emplace_back( entryx );
    entryVec->emplace_back( yxt );
    entryVec->emplace_back( zxt );
    entryVec->emplace_back( ppxMod * 1.0 ); // enters one of the two x faces
    return entryVec;
  }

  // check u=const
  const double entryu = MINu + ppuMod * MINapo;
  const double tu = ( entryu - pvu ) / ppu;
  const double Uut = pvU + tu * ppU;
  // go back: (u,U) |--> (x,y)
  const double xut = entryu * std::cos( -MINtheta ) - Uut * std::sin( -MINtheta );
  const double yut = entryu * std::sin( -MINtheta ) + Uut * std::cos( -MINtheta );
  const double zut = pvz + tu * ppz;

  bool didEnteru = ( std::abs( Uut ) <= MINside / 2.0 ) && ( zut <= zhigh && zut >= zlow );

  if( didEnteru ){
    
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters out the u=const ( = " << entryu << " ) side of the ID at ( "
      << xut << ", " << yut << ", " << zut << " ) [m]"
      << "\nwith tu = " << tu << " [m]";

    entryVec->emplace_back( xut );
    entryVec->emplace_back( yut );
    entryVec->emplace_back( zut );
    entryVec->emplace_back( ppuMod * 2.0 ); // enters one of the two u faces
    return entryVec;
  }

  // check v=const
  const double entryv = MINv + ppvMod * MINapo;
  const double tv = ( entryv - pvv ) / ppv;
  const double Vvt = pvV + tv * ppV;
  // go back: (v,V) |--> (x,y)
  const double xvt = entryv * std::cos( MINtheta ) - Vvt * std::sin( MINtheta );
  const double yvt = entryv * std::sin( MINtheta ) + Vvt * std::cos( MINtheta );
  const double zvt = pvz + tv * ppz;

  bool didEnterv = ( std::abs( Vvt ) <= MINside / 2.0 ) && ( zvt <= zhigh && zvt >= zlow );

  if( didEnterv ){
    
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL enters out the v=const ( = " << entryv << " ) side of the ID at ( "
      << xvt << ", " << yvt << ", " << zvt << " ) [m]"
      << "\nwith tv = " << tv << " [m]";

    entryVec->emplace_back( xvt );
    entryVec->emplace_back( yvt );
    entryVec->emplace_back( zvt );
    entryVec->emplace_back( ppvMod * 3.0 ); // enters one of the two v faces
    return entryVec;
  }

  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );
  entryVec->emplace_back( -999.9 );

  return entryVec;
}

std::vector< double > * genie::HNL::HNLMINERvAGeom::GetExitPointID( const std::vector< double > * prodVtx, const std::vector< double > * momVec ){
  // checks against a hexagonal FV of ID size

  std::vector< double > * exitVec = new std::vector< double >();

  const double exitz = MINz + MINlen / 2.0; // if exits out the back.

  // line is parametric, solve for t and return point of exit if there is a solution
  const double pvz  = prodVtx->at(2) * genie::units::cm / genie::units::m;
  const double ppm2 = momVec->at(0)*momVec->at(0) + momVec->at(1)*momVec->at(1) + momVec->at(2)*momVec->at(2);
  const double ppm  = std::sqrt( ppm2 ); // get unit vector
  const double ppz  = momVec->at(2) / ppm; 
  const double tz   = ( exitz - pvz ) / ppz;

  LOG( "SimpleHNL", pDEBUG )
    << "exitz, pvz, ppz, tz = " << exitz << ", " << pvz << " [m], " << ppz << " [GeV/GeV], " << tz << " [m]";

  // there are now 3+1 pairs of sides to compare against
  // define sides of 'coord' = const
  const double rlow  = MINapo;
  const double rhigh = 2.0 * MINapo / std::tan( MINtheta );
  const double zlow  = MINz - MINlen / 2.0;
  const double zhigh = MINz + MINlen / 2.0;

  const double pvx = prodVtx->at(0) * genie::units::cm / genie::units::m;
  const double pvy = prodVtx->at(1) * genie::units::cm / genie::units::m;
  const double ppx = momVec->at(0) / ppm;
  const double ppy = momVec->at(1) / ppm;

  const double pvu = pvx * std::cos( MINtheta ) - pvy * std::sin( MINtheta ); // u coord
  const double pvU = pvx * std::sin( MINtheta ) + pvy * std::cos( MINtheta ); // perp u coord
  const double ppu = ppx * std::cos( MINtheta ) - ppy * std::sin( MINtheta );
  const double ppU = ppx * std::sin( MINtheta ) + ppy * std::cos( MINtheta );

  const double pvv = pvx * std::cos( -MINtheta ) - pvy * std::sin( -MINtheta ); // v coord
  const double pvV = pvx * std::sin( -MINtheta ) + pvy * std::cos( -MINtheta ); // perp v coord
  const double ppv = ppx * std::cos( -MINtheta ) - ppy * std::sin( -MINtheta );
  const double ppV = ppx * std::sin( -MINtheta ) + ppy * std::cos( -MINtheta );

  LOG( "SimpleHNL", pDEBUG )
    << "pvx, pvy, ppx, ppy = " << pvx << ", " << pvy << " [m] , " << ppx << ", " << ppy << " [GeV / GeV]";

  const double xt = pvx + tz * ppx;
  const double yt = pvy + tz * ppy;

  const double ut = xt * std::cos( MINtheta ) - yt * std::sin( MINtheta );
  const double vt = xt * std::cos( -MINtheta ) - yt * std::sin( -MINtheta );

  // check if point is in apothem

  bool didIntersectID = ( ( std::abs( xt ) <= MINapo ) &&
			  ( std::abs( ut ) <= MINapo ) &&
			  ( std::abs( vt ) <= MINapo ) );

  LOG( "SimpleHNL", pDEBUG )
    << "\nxt, yt = " << xt << ", " << yt
    << "\nut, vt " << ut << ", " << vt
    << "\n|xt|, |ut|, |vt| = " << std::abs( xt ) << ", " << std::abs( ut ) << ", " << std::abs( vt ) << " | MINapo = " << MINapo
    << "\ndidIntersectID = " << didIntersectID;

  if( didIntersectID ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits the front of the ID at ( "
      << xt << ", " << yt << ", " << exitz << " ) [m]";

    exitVec->emplace_back( xt );
    exitVec->emplace_back( yt );
    exitVec->emplace_back( exitz );
    exitVec->emplace_back( 0.0 ); // exits the front
    return exitVec;
  }

  // check to see if exited from x side
  const int ppxMod = ( ppx > 0 ) ? 1 : -1;
  const int ppuMod = ( ppu > 0 ) ? 1 : -1;
  const int ppvMod = ( ppv > 0 ) ? 1 : -1;

  // check x=const
  const double exitx = MINx + ppxMod * MINapo;
  const double tx = ( exitx - pvx ) / ppx;
  const double yxt = pvy + tx * ppy;
  const double zxt = pvz + tx * ppz;

  bool didExitx = ( std::abs( yxt ) <= MINside / 2.0 ) && ( zxt <= zhigh && zxt >= zlow );

  LOG( "SimpleHNL", pDEBUG )
    << "Checking *x* with:"
    << "\npvx = " << pvx << " [m]"
    << "\nppx (ppxMod) = " << ppx << " [GeV/GeV] (" << ppxMod << ")"
    << "\nexitx, tx, yxt, zxt = " << exitx << ", " << tx << ", " << yxt << ", " << zxt << " [m]"
    << "\n|yxt| = " << std::abs( yxt ) << " | MINside / 2.0 = " << MINside / 2.0  << " [m]"
    << "\nzxt, [zlow, zhigh] = " << zxt << ", [ " << zlow << ", " << zhigh << " ] [m]"
    << "\n==> didExitx = " << didExitx;

  if( didExitx ){
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the x=const ( = " << exitx << " ) side of the ID at ( "
      << exitx << ", " << yxt << ", " << zxt << " ) [m]"
      << "\nwith tx = " << tx << " [m]";

    exitVec->emplace_back( exitx );
    exitVec->emplace_back( yxt );
    exitVec->emplace_back( zxt );
    exitVec->emplace_back( ppxMod * 1.0 ); // exits one of the two x faces
    return exitVec;
  }

  // check u=const
  const double exitu = MINu + ppuMod * MINapo;
  const double tu = ( exitu - pvu ) / ppu;
  const double Uut = pvU + tu * ppU;
  // go back: (u,U) |--> (x,y)
  const double xut = exitu * std::cos( -MINtheta ) - Uut * std::sin( -MINtheta );
  const double yut = exitu * std::sin( -MINtheta ) + Uut * std::cos( -MINtheta );
  const double zut = pvz + tu * ppz;

  bool didExitu = ( std::abs( Uut ) <= MINside / 2.0 ) && ( zut <= zhigh && zut >= zlow );

  LOG( "SimpleHNL", pDEBUG )
    << "Checking *u* with:"
    << "\npvu = " << pvu << " [m]"
    << "\nppu (ppuMod) = " << ppu << " [GeV/GeV] (" << ppuMod << ")"
    << "\nexitu, tu, xut, yut, zut = " << exitu << ", " << tu << ", "
    << xut << ", " << yut << ", " << zut << " [m]"
    << "\n|yut| = " << std::abs( yut ) << " | MINside / 2.0 = " << MINside / 2.0  << " [m]"
    << "\nzut, [zlow, zhigh] = " << zut << ", [ " << zlow << ", " << zhigh << " ] [m]"
    << "\n==> didExitu = " << didExitu;

  if( didExitu ){
    
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the u=const ( = " << exitu << " ) side of the ID at ( "
      << xut << ", " << yut << ", " << zut << " ) [m]"
      << "\nwith tu = " << tu << " [m]";

    exitVec->emplace_back( xut );
    exitVec->emplace_back( yut );
    exitVec->emplace_back( zut );
    exitVec->emplace_back( ppuMod * 2.0 ); // exits one of the two u faces
    return exitVec;
  }

  // check v=const
  const double exitv = MINv + ppvMod * MINapo;
  const double tv = ( exitv - pvv ) / ppv;
  const double Vvt = pvV + tv * ppV;
  // go back: (v,V) |--> (x,y)
  const double xvt = exitv * std::cos( MINtheta ) - Vvt * std::sin( MINtheta );
  const double yvt = exitv * std::sin( MINtheta ) + Vvt * std::cos( MINtheta );
  const double zvt = pvz + tv * ppz;

  bool didExitv = ( std::abs( Vvt ) <= MINside / 2.0 ) && ( zvt <= zhigh && zvt >= zlow );
  
  LOG( "SimpleHNL", pDEBUG )
    << "Checking *v* with:"
    << "\npvv = " << pvv << " [m]"
    << "\nppv (ppvMod) = " << ppv << " [GeV/GeV] (" << ppvMod << ")"
    << "\nexitv, tv, xvt, yvt, zvt = " << exitv << ", " << tv << ", "
    << xvt << ", " << yvt << ", " << zvt << " [m]"
    << "\n|yvt| = " << std::abs( yvt ) << " | MINside / 2.0 = " << MINside / 2.0  << " [m]"
    << "\nzvt, [zlow, zhigh] = " << zvt << ", [ " << zlow << ", " << zhigh << " ] [m]"
    << "\n==> didExitv = " << didExitv;

  if( didExitv ){
    
    LOG( "SimpleHNL", pDEBUG )
      << "This HNL exits out the v=const ( = " << exitv << " ) side of the ID at ( "
      << xvt << ", " << yvt << ", " << zvt << " ) [m]"
      << "\nwith tv = " << tv << " [m]";

    exitVec->emplace_back( xvt );
    exitVec->emplace_back( yvt );
    exitVec->emplace_back( zvt );
    exitVec->emplace_back( ppvMod * 3.0 ); // exits one of the two v faces
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
