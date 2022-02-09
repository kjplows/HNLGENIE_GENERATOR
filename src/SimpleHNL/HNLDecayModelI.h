//____________________________________________________________________________
/*!

\class    genie::HNLDecayModelI

\brief    Pure abstract base class. Defines the HNLDecayModelI interface to be
          implemented by only the HNL decayer.
	  This is done to avoid conflicts with the DecayModelI interface of the `Decay` package
	  but the interface is identical.

\author   John Plows <komninos-john.plows \at physics.ox.ac.uk>
          University of Oxford

\created  February 8, 2022

\cpright  ???
*/
//____________________________________________________________________________

#ifndef _JHNLDECAY_MODEL_I_H_
#define _JHNLDECAY_MODEL_I_H_

class TDecayChannel;

#include "Algorithm/Algorithm.h"
#include "Decay/DecayerInputs.h"

namespace genie {

class HNLDecayModelI : public Algorithm {

public:

  virtual ~HNLDecayModelI();

  //
  // define the HNLDecayModelI interface
  //

  //! can this particle be decayed?
  virtual bool IsHandled  (int pdgc) const = 0; 

  //! decayer initialization
  virtual void Initialize (void) const = 0; 

  //! return a TClonesArray of TMCParticle objects (NOTE: all TMCParticle units in GeV^n [hbar=c=1])
  virtual TClonesArray * Decay (const DecayerInputs_t & inp) const = 0; 

  //! last decay weight
  virtual double Weight(void) const = 0; 

  //! inhibit input decay channel for the input particle (inhibit all decays if dc is null)
  virtual void InhibitDecay(int pdgc, TDecayChannel * dc = 0) const = 0;

  //! clear inhibit flags & re-enable all decay channel (enable all if dc is null)
  virtual void UnInhibitDecay(int pdgc, TDecayChannel * dc = 0) const = 0;

protected:

  HNLDecayModelI();
  HNLDecayModelI(string name);
  HNLDecayModelI(string name, string config);
};

}         // genie namespace

#endif    // _JHNLDECAY_MODEL_I_H_
