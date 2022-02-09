//____________________________________________________________________________
/*
  Implementation file for DummyHNLInteractionGenerator.h
*/
//____________________________________________________________________________

#include "EVGCore/InteractionList.h"
#include "Interaction/Interaction.h"
#include "SimpleHNL/DummyHNLInteractionListGenerator.h"

using namespace genie;

//___________________________________________________________________________
DummyHNLInteractionListGenerator::DummyHNLInteractionListGenerator() :
InteractionListGeneratorI("genie::DummyHNLInteractionListGenerator")
{

}
//___________________________________________________________________________
DummyHNLInteractionListGenerator::DummyHNLInteractionListGenerator(string config):
InteractionListGeneratorI("genie::DummyHNLInteractionListGenerator", config)
{

}
//___________________________________________________________________________
DummyHNLInteractionListGenerator::~DummyHNLInteractionListGenerator()
{

}
//___________________________________________________________________________
InteractionList * DummyHNLInteractionListGenerator::CreateInteractionList(
    const InitialState & /*init_state*/) const
{
  return 0;
}
//___________________________________________________________________________
