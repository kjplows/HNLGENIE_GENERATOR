// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_PDG

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
#include "PDGLibrary.h"
#include "PDGUtils.h"
#include "PDGCodeList.h"

// Header files passed via #pragma extra_include

namespace genie {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "", 30,
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

namespace genie {
   namespace pdg {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *geniecLcLpdg_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie::pdg", 0 /*version*/, "", 91,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &geniecLcLpdg_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *geniecLcLpdg_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static TClass *geniecLcLPDGLibrary_Dictionary();
   static void geniecLcLPDGLibrary_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PDGLibrary*)
   {
      ::genie::PDGLibrary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PDGLibrary));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PDGLibrary", "", 32,
                  typeid(::genie::PDGLibrary), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPDGLibrary_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PDGLibrary) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PDGLibrary*)
   {
      return GenerateInitInstanceLocal((::genie::PDGLibrary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PDGLibrary*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPDGLibrary_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PDGLibrary*)0x0)->GetClass();
      geniecLcLPDGLibrary_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPDGLibrary_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPDGCodeList_Dictionary();
   static void geniecLcLPDGCodeList_TClassManip(TClass*);
   static void *new_geniecLcLPDGCodeList(void *p = 0);
   static void *newArray_geniecLcLPDGCodeList(Long_t size, void *p);
   static void delete_geniecLcLPDGCodeList(void *p);
   static void deleteArray_geniecLcLPDGCodeList(void *p);
   static void destruct_geniecLcLPDGCodeList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PDGCodeList*)
   {
      ::genie::PDGCodeList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PDGCodeList));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PDGCodeList", "", 190,
                  typeid(::genie::PDGCodeList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPDGCodeList_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PDGCodeList) );
      instance.SetNew(&new_geniecLcLPDGCodeList);
      instance.SetNewArray(&newArray_geniecLcLPDGCodeList);
      instance.SetDelete(&delete_geniecLcLPDGCodeList);
      instance.SetDeleteArray(&deleteArray_geniecLcLPDGCodeList);
      instance.SetDestructor(&destruct_geniecLcLPDGCodeList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PDGCodeList*)
   {
      return GenerateInitInstanceLocal((::genie::PDGCodeList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PDGCodeList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPDGCodeList_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PDGCodeList*)0x0)->GetClass();
      geniecLcLPDGCodeList_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPDGCodeList_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
} // end of namespace ROOT for class ::genie::PDGLibrary

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLPDGCodeList(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PDGCodeList : new ::genie::PDGCodeList;
   }
   static void *newArray_geniecLcLPDGCodeList(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PDGCodeList[nElements] : new ::genie::PDGCodeList[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLPDGCodeList(void *p) {
      delete ((::genie::PDGCodeList*)p);
   }
   static void deleteArray_geniecLcLPDGCodeList(void *p) {
      delete [] ((::genie::PDGCodeList*)p);
   }
   static void destruct_geniecLcLPDGCodeList(void *p) {
      typedef ::genie::PDGCodeList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::PDGCodeList

namespace {
  void TriggerDictionaryInitialization_libGPDG_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"PDG",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/PDG",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/PDG",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/PDG/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGPDG dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class PDGLibrary;}
namespace genie{class PDGCodeList;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGPDG dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::PDGLibrary

\brief    Singleton class to load & serve a TDatabasePDG.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 06, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PDG_LIBRARY_H_
#define _PDG_LIBRARY_H_

#include <TDatabasePDG.h>
#include <TParticlePDG.h>

namespace genie {

class PDGLibrary 
{
public:

  static PDGLibrary * Instance(void);

  TDatabasePDG * DBase (void);
  TParticlePDG * Find  (int pdgc);

private:

  PDGLibrary();
  PDGLibrary(const PDGLibrary & config_pool);
  virtual ~PDGLibrary();

  bool LoadDBase(void);

  static PDGLibrary * fInstance;
  TDatabasePDG      * fDatabasePDG;
  
  struct Cleaner {
      void DummyMethodAndSilentCompiler() { }
      ~Cleaner() {
         if (PDGLibrary::fInstance !=0) {
            delete PDGLibrary::fInstance;
            PDGLibrary::fInstance = 0;
         }
      }
  };
  friend struct Cleaner;
};

}      // genie namespace

#endif // _PDG_LIBRARY_H_
//____________________________________________________________________________
/*!

\namespace genie::pdg

\brief     Utilities for improving the code readability when using PDG codes.

\author    Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
           University of Liverpool & STFC Rutherford Appleton Lab

\created   May 06, 2004

\cpright   Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
           For the full text of the license visit http://copyright.genie-mc.org
           or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PDG_UTILS_H_
#define _PDG_UTILS_H_

namespace genie {

namespace pdg
{
  bool IsPseudoParticle   (int pdgc);
  bool IsIon              (int pdgc);
  bool IsParticle         (int pdgc); ///< not ion or pseudo-particle

  int  IonPdgCodeToZ      (int pdgc);
  int  IonPdgCodeToA      (int pdgc);
  int  IonPdgCode         (int A, int Z);
  int  IonPdgCode         (int A, int Z, int L, int I);
  
  bool IsLepton           (int pdgc);
  bool IsNeutralLepton    (int pdgc);
  bool IsChargedLepton    (int pdgc);

  bool IsNeutrino         (int pdgc);
  bool IsAntiNeutrino     (int pdgc);
  bool IsNegChargedLepton (int pdgc);
  bool IsPosChargedLepton (int pdgc);

  bool IsNuE              (int pdgc);
  bool IsNuMu             (int pdgc);
  bool IsNuTau            (int pdgc);
  bool IsAntiNuE          (int pdgc);
  bool IsAntiNuMu         (int pdgc);
  bool IsAntiNuTau        (int pdgc);
  
  bool IsElectron         (int pdgc);
  bool IsPositron         (int pdgc);
  bool IsMuon             (int pdgc);
  bool IsAntiMuon         (int pdgc);
  bool IsTau              (int pdgc);
  bool IsAntiTau          (int pdgc);
  
  bool IsDiQuark          (int pdgc);
  bool IsQuark            (int pdgc);
  bool IsUQuark           (int pdgc);
  bool IsDQuark           (int pdgc);
  bool IsSQuark           (int pdgc);
  bool IsCQuark           (int pdgc);
  bool IsAntiQuark        (int pdgc);
  bool IsAntiUQuark       (int pdgc);
  bool IsAntiDQuark       (int pdgc);
  bool IsAntiSQuark       (int pdgc);
  bool IsAntiCQuark       (int pdgc);
  
  bool IsKaon             (int pdgc);
  bool IsPion             (int pdgc);
  bool IsProton           (int pdgc);
  bool IsNeutron          (int pdgc);
  bool IsNucleon          (int pdgc);
  bool IsNeutronOrProton  (int pdgc);
  bool IsHadron           (int pdgc);
  bool IsBaryonResonance  (int pdgc);
  bool Is2NucleonCluster  (int pdgc);
  
  int  SwitchProtonNeutron    (int pdgc);
  int  ModifyNucleonCluster   (int pdgc, int dQ);
  int  Neutrino2ChargedLepton (int pdgc);

  int  GeantToPdg (int geant_code);

}      // pdg namespace
}      // genie namespace

#endif // _PDG_UTILS_H_
//____________________________________________________________________________
/*!

\class   genie::PDGCodeList

\brief   A list of PDG codes

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 13, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PDG_CODE_LIST_H_
#define _PDG_CODE_LIST_H_

#include <vector>
#include <ostream>

using std::vector;
using std::ostream;

namespace genie {

class PDGCodeList;
ostream & operator << (ostream & stream, const PDGCodeList & list);

class PDGCodeList : public vector<int> {

public :

  PDGCodeList(bool allowdup=false);
  PDGCodeList(size_type n, bool allowdup=false);
  PDGCodeList(const PDGCodeList & list);
  ~PDGCodeList();

  //! override the vector<int> insertion methods to explicitly check for
  //! PDG code validity and that no PDG code is listed more than once
  void push_back  (int pdg_code);
  void insert     (iterator pos, size_type n, const int& x);

  //! PDG code checks used by PDGCodeList
  bool CheckPDGCode        (int pdg_code) const;
  bool ExistsInPDGLibrary  (int pdg_code) const;
  bool ExistsInPDGCodeList (int pdg_code) const;

  //! copy / print
  void Copy  (const PDGCodeList & list);
  void Print (ostream & stream) const;

  //! check state
  bool DuplEntriesAllowed(void) const { return fAllowDuplicateEntries; }

  //! overloaded operators
  PDGCodeList &    operator =  (const PDGCodeList & list);
  friend ostream & operator << (ostream & stream, const PDGCodeList & list);

private:

  bool fAllowDuplicateEntries; ///< allow duplicate entries in the list?
};

}      // genie namespace

#endif // _PDG_CODE_LIST_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::PDGCodeList", payloadCode, "@",
"genie::PDGLibrary", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGPDG",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGPDG_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGPDG_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGPDG() {
  TriggerDictionaryInitialization_libGPDG_Impl();
}
