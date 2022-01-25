//----------------------------------------------------------------------------
/*!

  Handles the inclusive-type transformation selection
  Assumes pseudounitarity (|U_{e4}|^{2} + |U_{\mu 4}|^{2} = 1) to conserve stats
  and also to be consistent with the fluxes read in from dk2nu
  
  Will have to upscale POT by factor (|U_{e4}|^{2} + |U_{\mu4}^{2}|)^{-2} later!

\namespace  genie::HNL::Selector

\brief      Transformation inclusive-method channel selector

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 9th, 2021

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------
/*
  TODO: Where should I put the Majorana option?
*/
//----------------------------------------------------------------------------

#ifndef JDECAYSELECTOR_H
#define JDECAYSELECTOR_H

#include "TRandom3.h"
#include <map>

namespace genie {
namespace HNL {

    namespace Selector {

	namespace ghe = ::genie::HNL::enums;
	namespace gc  = ::genie::constants; 
	
	// valid channels with widths
	std::map< ghe::HNLDecay_t, double > GetValidChannelWidths( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana = false );
	// derived
	double GetTotalDecayWidth( std::map< ghe::HNLDecay_t, double > gammaMap );
	double CalcCoMLifetime( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana = false );

	// now choose channels you're interested in seeing
	std::map< ghe::HNLDecay_t, double > SetInterestingChannels( std::vector< ghe::HNLDecay_t > intChannels, std::map< ghe::HNLDecay_t, double > gammaMap );

	// transform widths to probabilities (marginalised over all interesting!)
	std::map< ghe::HNLDecay_t, double > GetProbabilities( std::map< ghe::HNLDecay_t, double > gammaMap );

	// make a choice from interesting channels
	// This is the inclusive method - see messages to Xianguo, Dec 9th 2021
	ghe::HNLDecay_t SelectChannelInclusive( std::map< ghe::HNLDecay_t, double > Pmap, double ranThrow );
	    
    } // namespace Selector

} // namespace HNL
} // namespace genie

#endif // #ifndef JDEDCAYSELECTOR_H
