//-------------------------------------------------------------------------
/*!

\namespace   genie::HNL::Defaults

\brief       Default values for HNL parameters

\author      John Plows <komninos-john.plows@physics.ox.ac.uk>

\created     January 18th, 2022

\cpright     ??? - TBD
  
*/
//-------------------------------------------------------------------------

#ifndef JDEFAULTS_H
#define JDEFAULTS_H

// -- GENIE includes

#include "PDG/PDGCodes.h"

namespace genie {
namespace HNL {

    namespace defaults {

	namespace gu = ::genie::units;
	namespace gc = ::genie::constants;

	static const double HNLDefaultMass    = gc::kMuonMass + gc::kPionMass + 10.0 * gu::MeV;
	static const double HNLDefaultECoup   = 0.0;
	static const double HNLDefaultMuCoup  = 1.0;
	static const double HNLDefaultTauCoup = 0.0;

	static const double HNLDefaultPDG    = ::genie::kPdgHNL; // generic HNL pdg code
	static const double HNLDefaultParPDG = ::genie::kPdgKP;  // produced by kaon

    } // namespace defaults

} // namespace HNL
} // namespace genie

#endif // #ifndef JDEFAULTS_H
