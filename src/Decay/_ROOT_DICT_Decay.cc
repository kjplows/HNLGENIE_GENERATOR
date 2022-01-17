// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_Decay

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "PythiaDecayer.h"
#include "DecayModelI.h"
#include "BaryonResonanceDecayer.h"

// Header files passed via #pragma extra_include

namespace genie {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "Algorithm/AlgStatus.h", 26,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &genie_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *genie_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *geniecLcLDecayModelI_Dictionary();
   static void geniecLcLDecayModelI_TClassManip(TClass*);
   static void delete_geniecLcLDecayModelI(void *p);
   static void deleteArray_geniecLcLDecayModelI(void *p);
   static void destruct_geniecLcLDecayModelI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::DecayModelI*)
   {
      ::genie::DecayModelI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::DecayModelI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::DecayModelI", "DecayModelI.h", 31,
                  typeid(::genie::DecayModelI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLDecayModelI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::DecayModelI) );
      instance.SetDelete(&delete_geniecLcLDecayModelI);
      instance.SetDeleteArray(&deleteArray_geniecLcLDecayModelI);
      instance.SetDestructor(&destruct_geniecLcLDecayModelI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::DecayModelI*)
   {
      return GenerateInitInstanceLocal((::genie::DecayModelI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::DecayModelI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLDecayModelI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::DecayModelI*)0x0)->GetClass();
      geniecLcLDecayModelI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLDecayModelI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPythiaDecayer_Dictionary();
   static void geniecLcLPythiaDecayer_TClassManip(TClass*);
   static void *new_geniecLcLPythiaDecayer(void *p = 0);
   static void *newArray_geniecLcLPythiaDecayer(Long_t size, void *p);
   static void delete_geniecLcLPythiaDecayer(void *p);
   static void deleteArray_geniecLcLPythiaDecayer(void *p);
   static void destruct_geniecLcLPythiaDecayer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PythiaDecayer*)
   {
      ::genie::PythiaDecayer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PythiaDecayer));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PythiaDecayer", "", 35,
                  typeid(::genie::PythiaDecayer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPythiaDecayer_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PythiaDecayer) );
      instance.SetNew(&new_geniecLcLPythiaDecayer);
      instance.SetNewArray(&newArray_geniecLcLPythiaDecayer);
      instance.SetDelete(&delete_geniecLcLPythiaDecayer);
      instance.SetDeleteArray(&deleteArray_geniecLcLPythiaDecayer);
      instance.SetDestructor(&destruct_geniecLcLPythiaDecayer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PythiaDecayer*)
   {
      return GenerateInitInstanceLocal((::genie::PythiaDecayer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PythiaDecayer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPythiaDecayer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PythiaDecayer*)0x0)->GetClass();
      geniecLcLPythiaDecayer_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPythiaDecayer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLBaryonResonanceDecayer_Dictionary();
   static void geniecLcLBaryonResonanceDecayer_TClassManip(TClass*);
   static void *new_geniecLcLBaryonResonanceDecayer(void *p = 0);
   static void *newArray_geniecLcLBaryonResonanceDecayer(Long_t size, void *p);
   static void delete_geniecLcLBaryonResonanceDecayer(void *p);
   static void deleteArray_geniecLcLBaryonResonanceDecayer(void *p);
   static void destruct_geniecLcLBaryonResonanceDecayer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::BaryonResonanceDecayer*)
   {
      ::genie::BaryonResonanceDecayer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::BaryonResonanceDecayer));
      static ::ROOT::TGenericClassInfo 
         instance("genie::BaryonResonanceDecayer", "", 175,
                  typeid(::genie::BaryonResonanceDecayer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLBaryonResonanceDecayer_Dictionary, isa_proxy, 0,
                  sizeof(::genie::BaryonResonanceDecayer) );
      instance.SetNew(&new_geniecLcLBaryonResonanceDecayer);
      instance.SetNewArray(&newArray_geniecLcLBaryonResonanceDecayer);
      instance.SetDelete(&delete_geniecLcLBaryonResonanceDecayer);
      instance.SetDeleteArray(&deleteArray_geniecLcLBaryonResonanceDecayer);
      instance.SetDestructor(&destruct_geniecLcLBaryonResonanceDecayer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::BaryonResonanceDecayer*)
   {
      return GenerateInitInstanceLocal((::genie::BaryonResonanceDecayer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::BaryonResonanceDecayer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLBaryonResonanceDecayer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::BaryonResonanceDecayer*)0x0)->GetClass();
      geniecLcLBaryonResonanceDecayer_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLBaryonResonanceDecayer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLDecayModelI(void *p) {
      delete ((::genie::DecayModelI*)p);
   }
   static void deleteArray_geniecLcLDecayModelI(void *p) {
      delete [] ((::genie::DecayModelI*)p);
   }
   static void destruct_geniecLcLDecayModelI(void *p) {
      typedef ::genie::DecayModelI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::DecayModelI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLPythiaDecayer(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PythiaDecayer : new ::genie::PythiaDecayer;
   }
   static void *newArray_geniecLcLPythiaDecayer(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PythiaDecayer[nElements] : new ::genie::PythiaDecayer[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLPythiaDecayer(void *p) {
      delete ((::genie::PythiaDecayer*)p);
   }
   static void deleteArray_geniecLcLPythiaDecayer(void *p) {
      delete [] ((::genie::PythiaDecayer*)p);
   }
   static void destruct_geniecLcLPythiaDecayer(void *p) {
      typedef ::genie::PythiaDecayer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::PythiaDecayer

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLBaryonResonanceDecayer(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::BaryonResonanceDecayer : new ::genie::BaryonResonanceDecayer;
   }
   static void *newArray_geniecLcLBaryonResonanceDecayer(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::BaryonResonanceDecayer[nElements] : new ::genie::BaryonResonanceDecayer[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLBaryonResonanceDecayer(void *p) {
      delete ((::genie::BaryonResonanceDecayer*)p);
   }
   static void deleteArray_geniecLcLBaryonResonanceDecayer(void *p) {
      delete [] ((::genie::BaryonResonanceDecayer*)p);
   }
   static void destruct_geniecLcLBaryonResonanceDecayer(void *p) {
      typedef ::genie::BaryonResonanceDecayer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::BaryonResonanceDecayer

namespace {
  void TriggerDictionaryInitialization_libGDecay_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"Decay",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/Decay",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/Decay",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/Decay/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGDecay dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class __attribute__((annotate("$clingAutoload$Decay/DecayModelI.h")))  DecayModelI;}
namespace genie{class PythiaDecayer;}
namespace genie{class BaryonResonanceDecayer;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGDecay dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::PythiaDecayer

\brief    Interface to PYTHIA particle decayer. \n
          The PythiaDecayer is a concrete implementation of the DecayModelI
          interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  June 20, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PYTHIA_DECAYER_I_H_
#define _PYTHIA_DECAYER_I_H_

#include <TPythia6.h>

#include "Decay/DecayModelI.h"

namespace genie {

class PythiaDecayer : public DecayModelI {

public:

  PythiaDecayer();
  PythiaDecayer(string config);
  virtual ~PythiaDecayer();

  // implement the DecayModelI interface  
  bool           IsHandled      (int pdgc)                      const;
  void           Initialize     (void)                          const;
  TClonesArray * Decay          (const DecayerInputs_t & inp)   const;
  double         Weight         (void)                          const;
  void           InhibitDecay   (int pdg, TDecayChannel * dc=0) const;
  void           UnInhibitDecay (int pdg, TDecayChannel * dc=0) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void   LoadConfig             (void);
  double SumBR                  (int kc) const;
  int    FindPythiaDecayChannel (int kc, TDecayChannel* dc) const;
  bool   MatchDecayChannels     (int ichannel, TDecayChannel * dc) const;

  mutable TPythia6 * fPythia;  ///< PYTHIA6 wrapper class
  mutable double fWeight;
//bool fForceDecay;
};

}         // genie namespace

#endif    // _PYTHIA_DECAYER_H_
//____________________________________________________________________________
/*!

\class    genie::DecayModelI

\brief    Pure abstract base class. Defines the DecayModelI interface to be
          implemented by any algorithmic class decaying a particle.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  June 20, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE 
*/
//____________________________________________________________________________


#ifndef _DECAY_MODEL_I_H_
#define _DECAY_MODEL_I_H_

class TDecayChannel;

#include "Algorithm/Algorithm.h"
#include "Decay/DecayerInputs.h"

namespace genie {

class DecayModelI : public Algorithm {

public:

  virtual ~DecayModelI();

  //
  // define the DecayModelI interface
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

  DecayModelI();
  DecayModelI(string name);
  DecayModelI(string name, string config);
};

}         // genie namespace

#endif    // _DECAY_MODEL_I_H_
//____________________________________________________________________________
/*!

\class    genie::BaryonResonanceDecayer

\brief    Baryon resonance decayer.

          A simple decayer based on resonance's branching fractions (BRs) and
          an N-body phase space generator. Since the resonance can be produced
          off-shell, decay channels with total-mass > W are suppressed. \n

          Is a concrete implementation of the DecayModelI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  November 27, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _BARYON_RESONANCE_DECAYER_H_
#define _BARYON_RESONANCE_DECAYER_H_

#include <TGenPhaseSpace.h>
#include <TLorentzVector.h>

#include "Decay/DecayModelI.h"

namespace genie {

class BaryonResonanceDecayer : public DecayModelI {

public:
  BaryonResonanceDecayer();
  BaryonResonanceDecayer(string config);
  virtual ~BaryonResonanceDecayer();

  // implement the DecayModelI interface
  bool           IsHandled      (int pdgc)                      const;
  void           Initialize     (void)                          const;
  TClonesArray * Decay          (const DecayerInputs_t & inp)   const;
  double         Weight         (void)                          const;
  void           InhibitDecay   (int pdg, TDecayChannel * dc=0) const;
  void           UnInhibitDecay (int pdg, TDecayChannel * dc=0) const;
 
  //libo did
  double DealsDeltaNGamma(int id_mother, int ichannel, double W) const;


  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void           LoadConfig     (void);
  TClonesArray * DecayExclusive (int pdgc, TLorentzVector & p, TDecayChannel * ch) const;
  double         FinalStateMass (TDecayChannel * channel) const;

  mutable TGenPhaseSpace fPhaseSpaceGenerator;
  mutable double         fWeight;

  bool fGenerateWeighted;
};

}         // genie namespace

#endif    // _BARYON_RESONANCE_DECAYER_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::BaryonResonanceDecayer", payloadCode, "@",
"genie::DecayModelI", payloadCode, "@",
"genie::PythiaDecayer", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGDecay",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGDecay_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGDecay_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGDecay() {
  TriggerDictionaryInitialization_libGDecay_Impl();
}
