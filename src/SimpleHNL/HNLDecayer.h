//-------------------------------------------------------------------------
/*!

\class   genie::HNL::HNLDecayer

\brief   Simple HNL decayer 

         Naive HNL decayer class, in the \nuMSM extension paradigm

	 * Reads in HNL flux and generates the following:

	 --> Origin vertex at (z, R, \theta) where:
	 + z      : along beamline (MINERvA coordinates) [ m ]
	 + R      : Transverse separation from beamline  [ m ]
	 + \theta : Polar angle in 2D                    [ rad ]

	 --> Momentum for HNL in Cartesian coordinates

	 * HNL flux is mass- and coupling-dependent so these are SET.

	 * Decay width is calculated according to mass and couplings.

	 * Decay position is calculated by using formula from Coloma et al:
  
	 --> P(decay ; L , dl) = P1(survival ; L) * P2(decay ; dl)
	 + P1(survival ; L) = exp(-\frac{L}{\beta\gamma} * \Gamma_{tot})
	 + P2(decay ; dl) = 1 - exp(-\frac{dl}{\beta\gamma} * \Gamma_{tot})

	 * Decay channel is calculated using transformation method:

	 --> Calculate all valid channels BR
	 --> Throw Uniform() in suitable probability space (1 per HNL)
	 --> Pick corresponding channel
   
	 * Kinematics calculated after channel is picked. 2- or 3-body decays.

	 This is a concrete implementation of DecayModelI

\author  John Plows <komninos-john.plows@physics.ox.ac.uk>

\created January 17th, 2022

\cpright ??? - TBD
  
*/
//-------------------------------------------------------------------------

#ifndef JHNLDECAYER_H
#define JHNLDECAYER_H

// -- C++ includes

//#include <cassert.h>
//#include <string>

// -- ROOT includes

#include <TClonesArray.h>
#include <TDecayChannel.h>
#include <TGenPhaseSpace.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TRandom3.h>

#include <RVersion.h>
#if ROOT_VERSION_CODE >= ROOT_VERSION(5,15,6)
#include <TMCParticle.h>
#else
#include <TMCParticle6.h>
#endif // #if ROOT_VERSION_CODE >= ROOT_VERSION(5,15,6)

// -- GENIE includes

#include "BaryonResonance/BaryonResUtils.h"
#include "Conventions/Constants.h"
#include "Conventions/Controls.h"
#include "Decay/BaryonResonanceDecayer.h"
#include "Decay/DecayModelI.h"
//#include "HNLAuxiliary/DecayKinematics.h"
//#include "HNLAuxiliary/Defaults.h"  
//#include "HNLAuxiliary/Enums.h"     
//#include "HNLAuxiliary/FluxReader.h"
#include "Messenger/Messenger.h"
#include "PDG/PDGLibrary.h"
#include "PDG/PDGUtils.h"
#include "Numerical/RandomGen.h"
#include "Utils/PrintUtils.h"

#include "DecayKinematics.h"
#include "Defaults.h"  
#include "Enums.h"     
#include "FluxReader.h"

namespace genie {
namespace HNL {

    class HNLDecayer : public DecayModelI {

    public:
	HNLDecayer( );
	HNLDecayer( std::string config );
	virtual ~HNLDecayer( );

	bool           IsHandled      (int pdgc)                       const;
	void           Initialize     (void)                           const;
	void           InitializeParticle ( genie::HNL::SimpleHNL sh )         const; // seen or not? idk
	TClonesArray * Decay          (const DecayerInputs_t & inp)    const;
	double         Weight         (void)                           const;
	void           InhibitDecay   (int pdgc, TDecayChannel * dc=0) const;
	void           UnInhibitDecay (int pdgc, TDecayChannel * dc=0) const;

	// need a few flux-reader methods. Either with GENIE or with SimpleHNL?

	// need to ~concretely implement the EventRecordVisitorI interface~
	// NO! Need to interface with UnstableParticleDecayer (see EVGModules/UnstableParticleDecayer)
	// so that the Event Record (see GHEP/GHepRecord.h) will allow me to add particles
	// (see GHEP/GHepParticle.h) to it.
	

	// overload the Algorithm::Configure() methods to load private data
	// members from configuration options
	void Configure(const Registry & config);
	void Configure(string config);

    private:

	void LoadConfig(void);
	TClonesArray * DecayExclusive(int pdgc, TLorentzVector & p, TDecayChannel * ch) const;
	//double FinalStateMass(TDecayChannel * channel) const; //always be M_N

	mutable TGenPhaseSpace fPhaseSpaceGenerator;
	mutable double fWeight;

	mutable genie::HNL::SimpleHNL fSh = genie::HNL::SimpleHNL( "dummy", -1 ); 
	// construct an HNL object that knows its mass + couplings
	// This can also return its own decay channels + widths + do selection

	mutable bool fWeightFluxInput; // false == every vtx location counts as w=1. True == use weighted dist
	mutable bool fIsMajorana;
	mutable bool fIsIsotropicPol; // non-weighted input seems to give isotropic polVec ==> no angular dependence of products in HNL rest frame!
	mutable bool fIsExclusive; // inclusive v exclusive decay mode
	
	mutable double fMass; const double fDefMass = genie::HNL::defaults::HNLDefaultMass;
	mutable double fECoup; const double fDefECoup = genie::HNL::defaults::HNLDefaultECoup;
	mutable double fMuCoup; const double fDefMuCoup = genie::HNL::defaults::HNLDefaultMuCoup; // assuming pseudo-unitarity!
	mutable double fTauCoup; const double fDefTauCoup = genie::HNL::defaults::HNLDefaultTauCoup;
	mutable std::string fCoupConf; 
	mutable genie::HNL::enums::coupIdx_t fCoupIdx; // which coupling configuration?

	mutable TRandom3 *fRng;

    }; // class HNLDecayer

} // namespace HNL
} // namespace genie

#endif // #ifndef JHNLDECAYER_H
