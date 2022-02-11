//____________________________________________________________________________
/*!

\class    genie::HNLDummyPXSec

\brief    

\author   

\created  Feb 11, 2022

\cpright  ???
*/
//____________________________________________________________________________

#ifndef _JHNL_DUMMY_PXSEC_H_
#define _JHNL_DUMMY_PXSEC_H_

#include "Base/XSecAlgorithmI.h"

namespace genie {

class HNLDummyPXSec : public XSecAlgorithmI {

public:
  HNLDummyPXSec();
  HNLDummyPXSec(string config);
 ~HNLDummyPXSec();

  // XSecAlgorithmI interface implementation
  double XSec            (const Interaction * i, KinePhaseSpace_t k) const;
  double Integral        (const Interaction * i) const;
  bool   ValidProcess    (const Interaction * i) const;
};

}       // genie namespace
#endif  // #ifndef _JHNL_DUMMY_PXSEC_H
