//----------------------------------------------------------------------------
/*!

  Handles the inclusive-type transformation selection
  Assumes pseudounitarity (|U_{e4}|^{2} + |U_{\mu 4}|^{2} = 1) to conserve stats
  and also to be consistent with the fluxes read in from dk2nu
  
  Will have to upscale POT by factor (|U_{e4}|^{2} + |U_{\mu4}^{2}|)^{-2} later!

\namespace  genie::HNL::HNLSelector

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

// -- C++ includes
#include <map>

// -- ROOT includes
#include "TRandom3.h"

// -- GENIE includes
#include "Conventions/Constants.h"

#include "BRFunctions.h"
#include "Enums.h"

namespace genie {
namespace HNL {

    namespace HNLSelector {

      // only need to calculate decay widths once! Store them in this array
      static double fDecayGammas[] = {-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0};
	
	// valid channels with widths
	std::map< genie::HNL::HNLenums::HNLDecay_t, double > GetValidChannelWidths( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana = false );
	// derived
	double GetTotalDecayWidth( std::map< genie::HNL::HNLenums::HNLDecay_t, double > gammaMap );
	double CalcCoMLifetime( const double M, const double Ue42, const double Umu42, const double Ut42, const bool IsMajorana = false );

	// now choose channels you're interested in seeing
	std::map< genie::HNL::HNLenums::HNLDecay_t, double > SetInterestingChannels( std::vector< genie::HNL::HNLenums::HNLDecay_t > intChannels, std::map< genie::HNL::HNLenums::HNLDecay_t, double > gammaMap );

	// transform widths to probabilities (marginalised over all interesting!)
	std::map< genie::HNL::HNLenums::HNLDecay_t, double > GetProbabilities( std::map< genie::HNL::HNLenums::HNLDecay_t, double > gammaMap );

	// make a choice from interesting channels
	// This is the inclusive method - see messages to Xianguo, Dec 9th 2021
	genie::HNL::HNLenums::HNLDecay_t SelectChannelInclusive( std::map< genie::HNL::HNLenums::HNLDecay_t, double > Pmap, double ranThrow );
	    
    } // namespace HNLSelector

} // namespace HNL
} // namespace genie

#endif // #ifndef JDEDCAYSELECTOR_H
