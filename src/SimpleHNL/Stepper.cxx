//----------------------------------------------------------------------------
// Implementation file for Stepper.h
// Author: John Plows <komninos-john.plows@physics.ox.ac.uk>
// 10/Dec/2021
//----------------------------------------------------------------------------

#include "Stepper.h"

// empty the vector of counters
void emptyCounters( ){
    while( fCounterMap.size() > 0 ){ fCounterMap.erase( fCounterMap.begin() ); }
}

// populate the vector of counters
void fillCounters( std::map< ghe::HNLDecay_t, double > gammaMap ){
	    if( fCounterMap.size() > 0 ) emptyCounters( );
	    if( !fIsRngInit ) initRandom( );
	    
	    for( std::map< ghe::HNLDecay_t, double >::iterator
		     it = gammaMap.begin(); it != gammaMap.end(); ++it )
	      { fCounterMap.insert( std::pair< ghe::HNLDecay_t, double > (
				      (*it).first, fRng->Uniform() ) ); }
	}

// inclusive method
void ghs::PropagateTilDecay( gh::SimpleHNL sh ){

    const std::vector< double > V0X = sh.GetOrigin4VX();
    const std::vector< double > V0P = sh.Get4VP();

    const double COMlifetime = sh.GetCoMLifetime( );
    const double LABlifetime = sh.GetLifetime( );
    
    // Get seed
    if( !fIsRngInit ) initRandom( );
    double ranthrow = fRng->Uniform( );

    // Exponential decay <-> N = floor( tau * ln( seed^(-1) ) / dt )
    const double t1 = std::floor( LABlifetime *
				  std::log( 1.0 / ranthrow ) /
				  fdt ) * fdt;
    const std::vector< double > betaVec  = sh.GetBetaVec( );
    const std::vector< double > origin4V = sh.GetOrigin4VX( );
    std::vector< double > decay4V; decay4V.emplace_back( origin4V.at(0) + t1 );
    decay4V.emplace_back( origin4V.at(1) + betaVec.at(1) * t1 * gc::kLightSpeed );
    decay4V.emplace_back( origin4V.at(2) + betaVec.at(2) * t1 * gc::kLightSpeed );
    decay4V.emplace_back( origin4V.at(3) + betaVec.at(3) * t1 * gc::kLightSpeed );

    sh.SetDecayVtx( decay4V );
}

// Exclusive stepper
void ghs::PropagateAndSelectChannel( gh::SimpleHNL sh ){

    const double COMlifetime = sh.GetCoMLifetime( );
    const double LABlifetime = sh.GetLifetime( );

    // first get the valid and the interesting channels with their widths
    const std::map< ghe::HNLDecay_t, double > ValidMap = sh.GetValidChannels( );
    const std::map< ghe::HNLDecay_t, double > InterestingMap = sh.GetInterestingChannels( );

    // TODO: exception for empty map!
    const int vSize = ValidMap.size();
    if( vSize == 0 ){ std::cerr << "genie::HNL::Selector::PropagateAndSelectChannel:: " <<
	    "\nNo valid channels!! This HNL cannot decay, which is bogus." <<
	    "\nExiting." << std::endl; exit(1); }
    
    const int iSize = InterestingMap.size( );
    if( iSize == 0 ){ std::cerr << "genie::HNL::Selector::PropagateAndSelectChannel::" <<
	    "\nNo interesting channels!! This HNL is invisible." <<
	    "\nExiting." << std::endl; exit(1); }
    
    // ensure vector of counters is empty, then fill
    emptyCounters( );
    fillCounters( ValidMap ); // we will ignore those counters 
    
    // build map of *when* each valid channel would decay, if it were alone
    std::map< ghe::HNLDecay_t, double > timeMap, tIntMap;

    for( std::map< ghe::HNLDecay_t, double >::iterator it = fCounterMap.begin();
	 it != fCounterMap.end(); ++it ){
	// Exponential decay <-> N = floor( tau * ln( seed^(-1) ) / dt )
	const double tmpT = std::floor( LABlifetime *
					std::log( 1.0 / (*it).second ) /
					fdt ) * fdt;
	timeMap.insert( std::pair< ghe::HNLDecay_t, double >( (*it).first, tmpT ) );

	// only insert in tIntMap if we have an interesting channel!
	if( InterestingMap.find( (*it).first ) != InterestingMap.end() ){
	    tIntMap.insert( std::pair< ghe::HNLDecay_t, double >( (*it).first, tmpT ) ); }
    }

    // first channel wins.
    double t1 = 99999.99, t2 = 99999.99; ghe::HNLDecay_t c1;
    for( std::map< ghe::HNLDecay_t, double >::iterator it = timeMap.begin();
	 it != timeMap.end(); ++it ){
	if( (*it).second < t1 ){ t1 = (*it).second; } } // t1 from all valid times
    for( std::map< ghe::HNLDecay_t, double >::iterator it = tIntMap.begin();
	 it != tIntMap.end(); ++it ){
	if( (*it).second < t2 ){ t2 = (*it).second; c1 = (*it).first; } } // c1 interesting

    const std::vector< double > betaVec  = sh.GetBetaVec( );
    const std::vector< double > origin4V = sh.GetOrigin4VX( );
    std::vector< double > decay4V; decay4V.emplace_back( origin4V.at(0) + t1 );
    decay4V.emplace_back( origin4V.at(1) + betaVec.at(1) * t1 * gc::kLightSpeed );
    decay4V.emplace_back( origin4V.at(2) + betaVec.at(2) * t1 * gc::kLightSpeed );
    decay4V.emplace_back( origin4V.at(3) + betaVec.at(3) * t1 * gc::kLightSpeed );

    sh.SetDecayVtx( decay4V ); sh.SetDecayMode( c1 );
}
