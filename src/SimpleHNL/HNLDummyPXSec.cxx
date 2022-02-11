//____________________________________________________________________________
/*
  Implementation file for HNLDummyPXSec.h

*/
//____________________________________________________________________________

#include "SimpleHNL/HNLDummyPXSec.h"

using namespace genie;

//____________________________________________________________________________
HNLDummyPXSec::HNLDummyPXSec() :
XSecAlgorithmI("genie::HNLDummyPXSec")
{

}
//____________________________________________________________________________
HNLDummyPXSec::HNLDummyPXSec(string config) :
XSecAlgorithmI("genie::HNLDummyPXSec", config)
{

}
//____________________________________________________________________________
HNLDummyPXSec::~HNLDummyPXSec()
{

}
//____________________________________________________________________________
double HNLDummyPXSec::XSec(const Interaction * , KinePhaseSpace_t ) const
{
  return 0;
}
//____________________________________________________________________________
double HNLDummyPXSec::Integral(const Interaction * ) const
{
  return 0;
}
//____________________________________________________________________________
bool HNLDummyPXSec::ValidProcess(const Interaction * ) const
{
  return true;
}
//____________________________________________________________________________
