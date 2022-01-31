//-------------------------------------------------------------------
/*!

  There are two- and three- body decays. Plus we have to take the 
  HNL polarisation into account.
  All kinematics calc'ed in rest frame of HNL.

  Note: We now have *three* frames to work with:
  a) Lab  frame
  b) Rest frame: determined by HNL \vec{\beta}
  c) Pol  frame: determined by HNL parent \vec{\beta} (if 2-body prod)

\namespace  genie::HNL::decayKinematics

\brief      Rest-frame kinematics for HNL decay products

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 9th, 2021

\cpright    ??? - TBD

 */
//-------------------------------------------------------------------
// TODO: 1) Streamline calculators. All functions are currently
//          "calculators", i.e. void. Do I want better return types?
//       2) Rigorous kinematics. Do the calcs yourself.
//       3) Figure out where to declare the detector centre. (in MINERvA coords)
//-------------------------------------------------------------------

#ifndef JDECAYKINEMATICS_H
#define JDECAYKINEMATICS_H

// -- C++ includes

#include <map>

// -- ROOT includes

#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

// -- GENIE includes

#include "Conventions/Constants.h"
#include "Conventions/Units.h"

#include "BRFunctions.h"
#include "Enums.h"    
#include "MINERvAGeom.h"
#include "SimpleHNL.h"

//#include "HNLAuxiliary/Enums.h"
//#include "HNLAuxiliary/MINERvAGeom.h"
//#include "HNLAuxiliary/SimpleHNL.h"

namespace gu   = ::genie::units;
namespace gc   = ::genie::constants;
namespace gh   = ::genie::HNL;
namespace ghe  = ::genie::HNL::enums;
namespace ghm  = ::genie::HNL::MINERvAGeom;
namespace ghs  = ::genie::HNL::Selector;

namespace genie {
namespace HNL {

    class SimpleHNL;

    namespace decayKinematics {

      namespace ghdk = ::genie::HNL::decayKinematics;

	// generic 2-body decay N --> \pi \ell   
	void TwoBodyEnergies( const double mN, const double mh, const double ml,
			      double &Eh, double &El );
	void TwoBodyAngle( SimpleHNL sh, const double mh, const double ml,
			   double &thetaPol ); // wrt polarisation vector
	// TwoBodyKinematics is responsible for deciding (theta, phi) in rest frame
	// as well as in lab frame!
	void TwoBodyKinematics( SimpleHNL sh, const double mh, const double ml,
				double &Eh, double &El,
				double &slx, double &sly, double &slz,
				double &shx, double &shy, double &shz ); // HNL rest frame

	// no such thing as generic 3-body decay.
	// Either N --> \nu_{j} + \ell_{i} \ell_{j}\bar or N --> \nu + \ell \ell\bar
	// or one of the pion routes
	void ThreeBodyEnergies( );
	void ThreeBodyAngleLep1( );
	void ThreeBodyAngleLep2( );

	void ThreeBodyKinematics( );
    
	// emission angles of product wrt HNL polarisation vector
	const double RestTheta( const double mN, const double pol,
				const ghe::HNLDecay_t chan, const double m1 );
	const double RestPhi( const double mN, const double pol,
			      const ghe::HNLDecay_t chan, const double m1 );
                              //assume cylindrical symmetry ?

	// define characteristic axis in rest frame: r(MIN centre) - r(HNL decay)
	const TVector3* RestFrameAxis( SimpleHNL sh );
	
	// translate to lab / rest frame coords
	TLorentzVector* RestToLabFrame( SimpleHNL sh, TLorentzVector* rest4V );
	TLorentzVector* LabToRestFrame( SimpleHNL sh, TLorentzVector* lab4V );

	const int defSteps = 10000;

	// obtain <variable> from its single differential decay width
	// pass formula as char and construct TF1
	const double ExtractVarFromDifferentialGamma( const std::string name,
						      const char * formChar,
						      const double x1, const double x2,
						      const double params[] = NULL,
						      const int nSteps = defSteps );

	const double kEND     = -1234.56789; // special number signalling param array end

	extern TRandom3 * fRngD;
	extern bool fIsRngInitD;

	void initRandom( );
	
    } //namespace decayKinematics

} //namespace HNL
} //namespace genie

#endif // #ifndef JDECAYKINEMATICS_H
