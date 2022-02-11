//____________________________________________________________________________
/*!

\class    genie::HNLDecayPrimaryVtxGenerator

\brief    Utilities for simulating HNL decay

\author   John Plows <komninos-john.plows \at physics.ox.ac.uk>
          University of Oxford

\created  February 11th, 2022

\cpright  ???
*/
//____________________________________________________________________________

#ifndef _JHNL_DECAY_PRIMARY_VTX_GENERATOR_H_
#define _JHNL_DECAY_PRIMARY_VTX_GENERATOR_H_

#include <TGenPhaseSpace.h>

#include "EVGCore/EventRecordVisitorI.h"
//#include "NucleonDecay/NucleonDecayMode.h"
#include "PDG/PDGCodeList.h"
#include "SimpleHNL/DecayKinematics.h"
#include "SimpleHNL/Enums.h"
#include "SimpleHNL/FluxReader.h"
#include "SimpleHNL/SimpleHNL.h"

namespace genie {

class NuclearModelI;

class HNLDecayPrimaryVtxGenerator: public EventRecordVisitorI {

public:
  HNLDecayPrimaryVtxGenerator();
  HNLDecayPrimaryVtxGenerator(string config);
 ~HNLDecayPrimaryVtxGenerator();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord (GHepRecord * event) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

   void LoadConfig                     (void);
   void AddInitialState                (GHepRecord * event) const;
   void GenerateDecayedHNLPosition     (GHepRecord * event) const;
   //void GenerateFermiMomentum          (GHepRecord * event) const;
   void GenerateDecayProducts          (GHepRecord * event) const;

   mutable int                           fCurrInitStatePdg;
   mutable genie::HNL::enums::HNLDecay_t fCurrDecayMode;
   mutable int                           fCurrDecayedHNL;
//mutable bool                          fNucleonIsBound;
   mutable TGenPhaseSpace                fPhaseSpaceGenerator;

   const NuclearModelI * fNuclModel;
};

} // genie namespace

#endif // _JHNL_DECAY_PRIMARY_VTX_GENERATOR_H_
