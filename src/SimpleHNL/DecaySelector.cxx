//----------------------------------------------------------------------------
// Implementation file for DecaySelector.h
// Author: John Plows <komninos-john.plows@physics.ox.ac.uk>
// 09/Dec/2021
//----------------------------------------------------------------------------
// TODO: bound checking, consistency with scores (final entry == 1 ?)
//       Add in N --> pi pi0 ell and N --> pi0 pi0 nu decays!!
//----------------------------------------------------------------------------

#include "DecaySelector.h"

//using namespace ::genie::HNL::Selector;

// Takes parameter space, outputs all available channels + widths
std::map< ghe::HNLDecay_t, double > genie::HNL::Selector::GetValidChannelWidths( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana ){

    std::map< ghe::HNLDecay_t, double > allChannels;

    // invisible decay is always possible
    double GINV = genie::HNL::Selector::DWidth_Invisible( M, Ue42, Umu42, Ut42 );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kNuNuNu, GINV ) );

    // nu-e-e is next lightest
    if( M < 2.0 * gc::kElectronMass ) return allChannels;

    double GNEE = genie::HNL::Selector::DWidth_SameLepton( M, Ue42, Umu42, Ut42, gc::kElectronMass, false );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kNuEE, GNEE ) );

    // nu-e-mu is next lightest
    if( M < gc::kElectronMass + gc::kMuonMass ) return allChannels;

    double GNEM = genie::HNL::Selector::DWidth_DiffLepton( M, Ue42, Umu42, IsMajorana ); 
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kNuMuE, GNEM ) );

    // pi0-nu is next lightest
    if( M < gc::kPi0Mass ) return allChannels;

    double GP0N = genie::HNL::Selector::DWidth_PiZeroAndNu( M, Ue42, Umu42, Ut42 );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPi0Nu, GP0N ) );

    // pi-e is next lightest
    if( M < gc::kPionMass + gc::kElectronMass ) return allChannels;

    double GPIE = genie::HNL::Selector::DWidth_PiAndLepton( M, Ue42, gc::kElectronMass );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPiE, GPIE) );

    // nu-mu-mu is next lightest
    if( M < 2.0 * gc::kMuonMass ) return allChannels;

    double GNMM = genie::HNL::Selector::DWidth_SameLepton( M, Ue42, Umu42, Ut42, gc::kMuonMass, false );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kNuMuMu, GNMM ) );

    // pi-mu is next lightest
    if( M < gc::kPionMass + gc::kMuonMass ) return allChannels;

    double GPIM = genie::HNL::Selector::DWidth_PiAndLepton( M, Umu42, gc::kMuonMass );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPiMu, GPIM ) );

    // pi0-pi0-nu is next lightest
    if( M < 2.0 * gc::kPi0Mass ) return allChannels;

    double GP02 = genie::HNL::Selector::DWidth_Pi0Pi0Nu( 1.0 ); //RETHERE: GOTTA IMPLEMENT
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPi0Pi0Nu, GP02 ) );

    // pi-pi0-e is next lightest
    if( M < gc::kPionMass + gc::kPi0Mass + gc::kElectronMass ) return allChannels;

    double GP0E = genie::HNL::Selector::DWidth_PiPi0Ell( M, gc::kElectronMass, Ue42, Umu42, Ut42, true );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPiPi0E, GP0E ) );

    // pi-pi0-mu is next lightest
    if( M < gc::kPionMass + gc::kPi0Mass + gc::kMuonMass ) return allChannels;

    double GP0M = genie::HNL::Selector::DWidth_PiPi0Ell( M, gc::kMuonMass, Ue42, Umu42, Ut42, false );
    allChannels.insert( std::pair< ghe::HNLDecay_t, double >( ghe::kPiPi0Mu, GP0M ) );

    //all done! Return
    return allChannels;
}

// Calculates the *total* decay width from all the valid channels
double genie::HNL::Selector::GetTotalDecayWidth( std::map< ghe::HNLDecay_t, double > gammaMap ) {
    
    double totGamma = 0.0;

    for( std::map< ghe::HNLDecay_t, double >::iterator it = gammaMap.begin(); it != gammaMap.end(); ++it ){ totGamma += (*it).second; }
    return totGamma;
}

// Returns lifetime of particle with mass and couplings
double genie::HNL::Selector::CalcCoMLifetime( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana ){

    std::map< ghe::HNLDecay_t, double > allChannels = genie::HNL::Selector::GetValidChannelWidths( M, Ue42, Umu42, Ut42, IsMajorana );
    double totGamma = genie::HNL::Selector::GetTotalDecayWidth( allChannels );
    return 1.0 / totGamma;
}

// let's pick the interesting channels
std::map< ghe::HNLDecay_t, double > genie::HNL::Selector::SetInterestingChannels( std::vector< ghe::HNLDecay_t > intChannels, std::map< ghe::HNLDecay_t, double > gammaMap ){

    std::map< ghe::HNLDecay_t, double > interestingMap;

    for( std::vector< ghe::HNLDecay_t >::iterator it = intChannels.begin(); it != intChannels.end(); ++it ){
	ghe::HNLDecay_t decType = (*it);
	double gamma = gammaMap.find( (*it) )->second;
	interestingMap.insert( std::pair< ghe::HNLDecay_t, double >( decType, gamma ) );
    }
    return interestingMap;
} // this is now a reduced map with only the channels we want to decay HNL to

// and transform decay widths to branching ratios (probabilities)
std::map< ghe::HNLDecay_t, double > genie::HNL::Selector::GetProbabilities( std::map< ghe::HNLDecay_t, double >  gammaMap ){

    double totGamma = GetTotalDecayWidth( gammaMap );
    std::map< ghe::HNLDecay_t, double > Pmap;

    // P = Gamma(channel)/Gamma(tot)
    for( std::map< ghe::HNLDecay_t, double >::iterator it = gammaMap.begin(); it != gammaMap.end(); ++it ){
	Pmap.insert( std::pair< ghe::HNLDecay_t, double >( (*it).first, (*it).second / totGamma ) );
    }
    return Pmap;
}

// choose a particular channel to decay to
ghe::HNLDecay_t genie::HNL::Selector::SelectChannelInclusive( std::map< ghe::HNLDecay_t, double > Pmap, double ranThrow ){

    // in inclusive method, decay is factorised in three parts:
    // a) Decay vertex placement
    // b) Decay product selection: construct 
    // c) Decay product kinematics
    // This method does only b)

    // first get P(all interesting channels)
    double PInt = 0.0, all_before = 0.0;
    ghe::HNLDecay_t selectedChannel = ghe::kInit;
    
    for( std::map< ghe::HNLDecay_t, double >::iterator it = Pmap.begin(); it != Pmap.end(); ++it ){ PInt += (*it).second; }

    // compare ranThrow to P(channel)/PInt + all_before
    // if all_before + P(channel)/PInt >= ranThrow then select this channel
    // don't break, check if scores add up to 1!
    for( std::map< ghe::HNLDecay_t, double >::iterator it = Pmap.begin(); it != Pmap.end(); ++it ){
	double modP = (*it).second / PInt;
	if( all_before < ranThrow &&
	    all_before + modP >= ranThrow ) selectedChannel = (*it).first;
	all_before += modP;
    }
    // TODO all_before == 1?

    return selectedChannel;
}
