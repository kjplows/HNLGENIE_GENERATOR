//____________________________________________________________________________
/*!

\class    genie::DummyHNLInteractionListGenerator

\brief    

\author   John Plows <komninos-john.plows \at physics.ox.ac.uk>
          University of Oxford

\created  February 9th, 2022

\cpright  ???
*/
//____________________________________________________________________________

#ifndef _JDUMMY_HNL_INTERACTION_LIST_GENERATOR_H_
#define _JDUMMY_HNL_INTERACTION_LIST_GENERATOR_H_

#include "EVGCore/InteractionListGeneratorI.h"

namespace genie {

class DummyHNLInteractionListGenerator : public InteractionListGeneratorI {

public :
  DummyHNLInteractionListGenerator();
  DummyHNLInteractionListGenerator(string config);
 ~DummyHNLInteractionListGenerator();

  // implement the InteractionListGeneratorI interface
  InteractionList * CreateInteractionList(const InitialState & init) const;
};

}      // genie namespace
#endif // _JDUMMY_HNL_INTERACTION_LIST_GENERATOR_H_
