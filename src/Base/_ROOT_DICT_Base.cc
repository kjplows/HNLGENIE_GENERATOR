// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_Base

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
#include "DISStructureFunc.h"
#include "XSecIntegratorI.h"
#include "DISStructureFuncModelI.h"
#include "XSecAlgorithmI.h"
#include "QELFormFactors.h"
#include "QELFormFactorsModelI.h"

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
   static TClass *geniecLcLDISStructureFuncModelI_Dictionary();
   static void geniecLcLDISStructureFuncModelI_TClassManip(TClass*);
   static void delete_geniecLcLDISStructureFuncModelI(void *p);
   static void deleteArray_geniecLcLDISStructureFuncModelI(void *p);
   static void destruct_geniecLcLDISStructureFuncModelI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::DISStructureFuncModelI*)
   {
      ::genie::DISStructureFuncModelI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::DISStructureFuncModelI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::DISStructureFuncModelI", "DISStructureFuncModelI.h", 29,
                  typeid(::genie::DISStructureFuncModelI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLDISStructureFuncModelI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::DISStructureFuncModelI) );
      instance.SetDelete(&delete_geniecLcLDISStructureFuncModelI);
      instance.SetDeleteArray(&deleteArray_geniecLcLDISStructureFuncModelI);
      instance.SetDestructor(&destruct_geniecLcLDISStructureFuncModelI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::DISStructureFuncModelI*)
   {
      return GenerateInitInstanceLocal((::genie::DISStructureFuncModelI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::DISStructureFuncModelI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLDISStructureFuncModelI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::DISStructureFuncModelI*)0x0)->GetClass();
      geniecLcLDISStructureFuncModelI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLDISStructureFuncModelI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLDISStructureFunc_Dictionary();
   static void geniecLcLDISStructureFunc_TClassManip(TClass*);
   static void *new_geniecLcLDISStructureFunc(void *p = 0);
   static void *newArray_geniecLcLDISStructureFunc(Long_t size, void *p);
   static void delete_geniecLcLDISStructureFunc(void *p);
   static void deleteArray_geniecLcLDISStructureFunc(void *p);
   static void destruct_geniecLcLDISStructureFunc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::DISStructureFunc*)
   {
      ::genie::DISStructureFunc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::DISStructureFunc));
      static ::ROOT::TGenericClassInfo 
         instance("genie::DISStructureFunc", "", 45,
                  typeid(::genie::DISStructureFunc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLDISStructureFunc_Dictionary, isa_proxy, 0,
                  sizeof(::genie::DISStructureFunc) );
      instance.SetNew(&new_geniecLcLDISStructureFunc);
      instance.SetNewArray(&newArray_geniecLcLDISStructureFunc);
      instance.SetDelete(&delete_geniecLcLDISStructureFunc);
      instance.SetDeleteArray(&deleteArray_geniecLcLDISStructureFunc);
      instance.SetDestructor(&destruct_geniecLcLDISStructureFunc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::DISStructureFunc*)
   {
      return GenerateInitInstanceLocal((::genie::DISStructureFunc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::DISStructureFunc*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLDISStructureFunc_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::DISStructureFunc*)0x0)->GetClass();
      geniecLcLDISStructureFunc_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLDISStructureFunc_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLXSecAlgorithmI_Dictionary();
   static void geniecLcLXSecAlgorithmI_TClassManip(TClass*);
   static void delete_geniecLcLXSecAlgorithmI(void *p);
   static void deleteArray_geniecLcLXSecAlgorithmI(void *p);
   static void destruct_geniecLcLXSecAlgorithmI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::XSecAlgorithmI*)
   {
      ::genie::XSecAlgorithmI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::XSecAlgorithmI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::XSecAlgorithmI", "XSecAlgorithmI.h", 28,
                  typeid(::genie::XSecAlgorithmI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLXSecAlgorithmI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::XSecAlgorithmI) );
      instance.SetDelete(&delete_geniecLcLXSecAlgorithmI);
      instance.SetDeleteArray(&deleteArray_geniecLcLXSecAlgorithmI);
      instance.SetDestructor(&destruct_geniecLcLXSecAlgorithmI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::XSecAlgorithmI*)
   {
      return GenerateInitInstanceLocal((::genie::XSecAlgorithmI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::XSecAlgorithmI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLXSecAlgorithmI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::XSecAlgorithmI*)0x0)->GetClass();
      geniecLcLXSecAlgorithmI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLXSecAlgorithmI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLXSecIntegratorI_Dictionary();
   static void geniecLcLXSecIntegratorI_TClassManip(TClass*);
   static void delete_geniecLcLXSecIntegratorI(void *p);
   static void deleteArray_geniecLcLXSecIntegratorI(void *p);
   static void destruct_geniecLcLXSecIntegratorI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::XSecIntegratorI*)
   {
      ::genie::XSecIntegratorI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::XSecIntegratorI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::XSecIntegratorI", "", 133,
                  typeid(::genie::XSecIntegratorI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLXSecIntegratorI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::XSecIntegratorI) );
      instance.SetDelete(&delete_geniecLcLXSecIntegratorI);
      instance.SetDeleteArray(&deleteArray_geniecLcLXSecIntegratorI);
      instance.SetDestructor(&destruct_geniecLcLXSecIntegratorI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::XSecIntegratorI*)
   {
      return GenerateInitInstanceLocal((::genie::XSecIntegratorI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::XSecIntegratorI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLXSecIntegratorI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::XSecIntegratorI*)0x0)->GetClass();
      geniecLcLXSecIntegratorI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLXSecIntegratorI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLQELFormFactorsModelI_Dictionary();
   static void geniecLcLQELFormFactorsModelI_TClassManip(TClass*);
   static void delete_geniecLcLQELFormFactorsModelI(void *p);
   static void deleteArray_geniecLcLQELFormFactorsModelI(void *p);
   static void destruct_geniecLcLQELFormFactorsModelI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::QELFormFactorsModelI*)
   {
      ::genie::QELFormFactorsModelI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::QELFormFactorsModelI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::QELFormFactorsModelI", "QELFormFactorsModelI.h", 29,
                  typeid(::genie::QELFormFactorsModelI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLQELFormFactorsModelI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::QELFormFactorsModelI) );
      instance.SetDelete(&delete_geniecLcLQELFormFactorsModelI);
      instance.SetDeleteArray(&deleteArray_geniecLcLQELFormFactorsModelI);
      instance.SetDestructor(&destruct_geniecLcLQELFormFactorsModelI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::QELFormFactorsModelI*)
   {
      return GenerateInitInstanceLocal((::genie::QELFormFactorsModelI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::QELFormFactorsModelI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLQELFormFactorsModelI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::QELFormFactorsModelI*)0x0)->GetClass();
      geniecLcLQELFormFactorsModelI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLQELFormFactorsModelI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLQELFormFactors_Dictionary();
   static void geniecLcLQELFormFactors_TClassManip(TClass*);
   static void *new_geniecLcLQELFormFactors(void *p = 0);
   static void *newArray_geniecLcLQELFormFactors(Long_t size, void *p);
   static void delete_geniecLcLQELFormFactors(void *p);
   static void deleteArray_geniecLcLQELFormFactors(void *p);
   static void destruct_geniecLcLQELFormFactors(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::QELFormFactors*)
   {
      ::genie::QELFormFactors *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::QELFormFactors));
      static ::ROOT::TGenericClassInfo 
         instance("genie::QELFormFactors", "", 315,
                  typeid(::genie::QELFormFactors), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLQELFormFactors_Dictionary, isa_proxy, 0,
                  sizeof(::genie::QELFormFactors) );
      instance.SetNew(&new_geniecLcLQELFormFactors);
      instance.SetNewArray(&newArray_geniecLcLQELFormFactors);
      instance.SetDelete(&delete_geniecLcLQELFormFactors);
      instance.SetDeleteArray(&deleteArray_geniecLcLQELFormFactors);
      instance.SetDestructor(&destruct_geniecLcLQELFormFactors);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::QELFormFactors*)
   {
      return GenerateInitInstanceLocal((::genie::QELFormFactors*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::QELFormFactors*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLQELFormFactors_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::QELFormFactors*)0x0)->GetClass();
      geniecLcLQELFormFactors_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLQELFormFactors_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLDISStructureFuncModelI(void *p) {
      delete ((::genie::DISStructureFuncModelI*)p);
   }
   static void deleteArray_geniecLcLDISStructureFuncModelI(void *p) {
      delete [] ((::genie::DISStructureFuncModelI*)p);
   }
   static void destruct_geniecLcLDISStructureFuncModelI(void *p) {
      typedef ::genie::DISStructureFuncModelI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::DISStructureFuncModelI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLDISStructureFunc(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::DISStructureFunc : new ::genie::DISStructureFunc;
   }
   static void *newArray_geniecLcLDISStructureFunc(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::DISStructureFunc[nElements] : new ::genie::DISStructureFunc[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLDISStructureFunc(void *p) {
      delete ((::genie::DISStructureFunc*)p);
   }
   static void deleteArray_geniecLcLDISStructureFunc(void *p) {
      delete [] ((::genie::DISStructureFunc*)p);
   }
   static void destruct_geniecLcLDISStructureFunc(void *p) {
      typedef ::genie::DISStructureFunc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::DISStructureFunc

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLXSecAlgorithmI(void *p) {
      delete ((::genie::XSecAlgorithmI*)p);
   }
   static void deleteArray_geniecLcLXSecAlgorithmI(void *p) {
      delete [] ((::genie::XSecAlgorithmI*)p);
   }
   static void destruct_geniecLcLXSecAlgorithmI(void *p) {
      typedef ::genie::XSecAlgorithmI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::XSecAlgorithmI

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLXSecIntegratorI(void *p) {
      delete ((::genie::XSecIntegratorI*)p);
   }
   static void deleteArray_geniecLcLXSecIntegratorI(void *p) {
      delete [] ((::genie::XSecIntegratorI*)p);
   }
   static void destruct_geniecLcLXSecIntegratorI(void *p) {
      typedef ::genie::XSecIntegratorI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::XSecIntegratorI

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLQELFormFactorsModelI(void *p) {
      delete ((::genie::QELFormFactorsModelI*)p);
   }
   static void deleteArray_geniecLcLQELFormFactorsModelI(void *p) {
      delete [] ((::genie::QELFormFactorsModelI*)p);
   }
   static void destruct_geniecLcLQELFormFactorsModelI(void *p) {
      typedef ::genie::QELFormFactorsModelI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::QELFormFactorsModelI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLQELFormFactors(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::QELFormFactors : new ::genie::QELFormFactors;
   }
   static void *newArray_geniecLcLQELFormFactors(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::QELFormFactors[nElements] : new ::genie::QELFormFactors[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLQELFormFactors(void *p) {
      delete ((::genie::QELFormFactors*)p);
   }
   static void deleteArray_geniecLcLQELFormFactors(void *p) {
      delete [] ((::genie::QELFormFactors*)p);
   }
   static void destruct_geniecLcLQELFormFactors(void *p) {
      typedef ::genie::QELFormFactors current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::QELFormFactors

namespace {
  void TriggerDictionaryInitialization_libGBase_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"Base",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/Base",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/Base",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/Base/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGBase dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class __attribute__((annotate("$clingAutoload$Base/DISStructureFuncModelI.h")))  DISStructureFuncModelI;}
namespace genie{class DISStructureFunc;}
namespace genie{class __attribute__((annotate("$clingAutoload$Base/XSecAlgorithmI.h")))  XSecAlgorithmI;}
namespace genie{class XSecIntegratorI;}
namespace genie{class __attribute__((annotate("$clingAutoload$Base/QELFormFactorsModelI.h")))  QELFormFactorsModelI;}
namespace genie{class QELFormFactors;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGBase dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::DISStructureFunc

\brief    A class holding Deep Inelastic Scattering (DIS) Form Factors
          (invariant structure funstions)

          This class is using the \b Strategy Pattern. \n
          It can accept requests to calculate itself, for a given interaction,
          that it then delegates to the algorithmic object, implementing the
          DISStructureFuncModelI interface, that it finds attached to itself.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 05, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _DIS_STRUCTURE_FUNCTIONS_H_
#define _DIS_STRUCTURE_FUNCTIONS_H_

#include <iostream>

#include "Base/DISStructureFuncModelI.h"
#include "Interaction/Interaction.h"

using std::ostream;

namespace genie {

class DISStructureFunc;
ostream & operator << (ostream & stream, const DISStructureFunc & sf);

class DISStructureFunc {

public:
  DISStructureFunc();
  DISStructureFunc(const DISStructureFunc & form_factors);
  virtual ~DISStructureFunc() { }

  //! Attach an algorithm
  void SetModel  (const DISStructureFuncModelI * model);

  //! Calculate the S/F's for the input interaction using the attached algorithm
  void Calculate (const Interaction * interaction);

  //! Get the computed structure function F1
  double F1 (void) const { return fF1; }

  //! Get the computed structure function F2
  double F2 (void) const { return fF2; }

  //! Get the computed structure function F3
  double F3 (void) const { return fF3; }

  //! Get the computed structure function F4
  double F4 (void) const { return fF4; }

  //! Get the computed structure function F5
  double F5 (void) const { return fF5; }

  //! Get the computed structure function F6
  double F6 (void) const { return fF6; }

  //! Get the attached model
  const DISStructureFuncModelI * Model (void) const {return fModel;}

  void   Reset    (Option_t * opt="");
  void   Copy     (const DISStructureFunc & sf);
  bool   Compare  (const DISStructureFunc & sf) const;
  void   Print    (ostream & stream) const;

  bool               operator == (const DISStructureFunc & sf) const;
  DISStructureFunc & operator =  (const DISStructureFunc & sf);
  friend ostream &   operator << (ostream & stream, const DISStructureFunc & sf);

private:

  double fF1;
  double fF2;
  double fF3;
  double fF4;
  double fF5;
  double fF6;

  const DISStructureFuncModelI * fModel;
};

}       // genie namespace

#endif  // _DIS_STRUCTURE_FUNCTIONS_H_
//____________________________________________________________________________
/*!

\class    genie::XSecIntegratorI

\brief    Cross Section Integrator Interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _XSEC_INTEGRATOR_I_H_
#define _XSEC_INTEGRATOR_I_H_

#include "Algorithm/Algorithm.h"
#include "Base/XSecAlgorithmI.h"
#include "Interaction/Interaction.h"

namespace genie {

class IntegratorI;

 class XSecIntegratorI : public Algorithm {

public:
  virtual ~XSecIntegratorI();

  virtual double Integrate(const XSecAlgorithmI * model, 
                           const Interaction * interaction 
                       /*, const KPhaseSpaceCut * cut=0*/) const= 0;
protected:
  XSecIntegratorI();
  XSecIntegratorI(string name);
  XSecIntegratorI(string name, string config);

  const IntegratorI * fIntegrator; ///< GENIE numerical integrator 

  string fGSLIntgType; ///< name of GSL numerical integrator
  double fGSLRelTol;   ///< required relative tolerance (error)
  int    fGSLMaxEval;  ///< GSL max evaluations
  int    fGSLMinEval;  ///< GSL min evaluations. Ignored by some integrators.
  int    fGSLNCalls;   ///< GSL number of function calls (apply only to MC integratioon methods)
  double fGSLThreshold;///< the threshold for the neutrino energy, above which the initial number of function multiply by fGSLNCallsFactor
  double fGSLNCallsFactor;///< factor that is multiplied by the initial number of function calls when the threshold is reached 
};

}       // genie namespace
#endif  // _XSEC_INTEGRATOR_I_H_
//____________________________________________________________________________
/*!

\class    genie::DISStructureFuncModelI

\brief    Pure Abstract Base Class. Defines the DISStructureFuncModelI
          interface to be implemented by any algorithmic class computing DIS
          structure functions.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _DIS_STRUCTURE_FUNCTIONS_MODEL_I_H_
#define _DIS_STRUCTURE_FUNCTIONS_MODEL_I_H_

#include "Algorithm/Algorithm.h"
#include "Interaction/Interaction.h"

namespace genie {

class DISStructureFuncModelI : public Algorithm {

public:
  virtual ~DISStructureFuncModelI();

  //! Calculate the structure functions F1-F6 for the input interaction
  virtual void Calculate (const Interaction * interaction) const = 0;

  //! Get the computed structure function F1
  virtual double F1 (void) const = 0;

  //! Get the computed structure function F2
  virtual double F2 (void) const = 0;

  //! Get the computed structure function F3
  virtual double F3 (void) const = 0;

  //! Get the computed structure function F4
  virtual double F4 (void) const = 0;

  //! Get the computed structure function F5
  virtual double F5 (void) const = 0;

  //! Get the computed structure function F6
  virtual double F6 (void) const = 0;

protected:
  DISStructureFuncModelI();
  DISStructureFuncModelI(string name);
  DISStructureFuncModelI(string name, string config);
};

}         // genie namespace
#endif    // _DIS_STRUCTURE_FUNCTIONS_MODEL_I_H_
//____________________________________________________________________________
/*!

\class    genie::XSecAlgorithmI

\brief    Cross Section Calculation Interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _XSEC_ALGORITHM_I_H_
#define _XSEC_ALGORITHM_I_H_

#include "Algorithm/Algorithm.h"
#include "Conventions/KinePhaseSpace.h"
#include "Interaction/Interaction.h"

namespace genie {

class XSecAlgorithmI : public Algorithm {

public:
  virtual ~XSecAlgorithmI();

  //! Compute the cross section for the input interaction
  virtual double XSec (const Interaction* i, KinePhaseSpace_t k=kPSfE) const = 0;

  //! Integrate the model over the kinematic phase space available to the
  //! input interaction (kinematical cuts can be included)
  virtual double Integral (const Interaction* i) const = 0;

  //! Can this cross section algorithm handle the input process?
  virtual bool ValidProcess    (const Interaction* i) const = 0;

  //! Is the input kinematical point a physically allowed one?
  virtual bool ValidKinematics (const Interaction* i) const;

protected:
  XSecAlgorithmI();
  XSecAlgorithmI(string name);
  XSecAlgorithmI(string name, string config);
};

}       // genie namespace
#endif  // _XSEC_ALGORITHM_I_H_
//____________________________________________________________________________
/*!

\class    genie::QELFormFactors

\brief    A class holding Quasi Elastic (QEL) Form Factors.

          This class is using the \b Strategy Pattern. \n
          It can accept requests to calculate itself, for a given interaction,
          that it then delegates to the algorithmic object, implementing the
          QELFormFactorsModelI interface, that it finds attached to itself.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  April 20, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _QEL_FORM_FACTORS_H_
#define _QEL_FORM_FACTORS_H_

#include <iostream>

#include "Base/QELFormFactorsModelI.h"
#include "Interaction/Interaction.h"

using std::ostream;

namespace genie {

class QELFormFactors;
ostream & operator << (ostream & stream, const QELFormFactors & ff);

class QELFormFactors {

public:

  QELFormFactors();
  QELFormFactors(const QELFormFactors & form_factors);
  virtual ~QELFormFactors() { }

  //! Attach an algorithm
  void   SetModel  (const QELFormFactorsModelI * model);

  //! Compute the form factors for the input interaction using the attached model
  void   Calculate (const Interaction * interaction);

  //! Get the computed form factor F1V
  double F1V    (void) const { return fF1V;   }

  //! Get the computed form factor xi*F2V
  double xiF2V  (void) const { return fxiF2V; }

  //! Get the computed form factor FA
  double FA     (void) const { return fFA;    }

  //! Get the computed form factor Fp
  double Fp     (void) const { return fFp;    }

  //! Get the attached model
  const QELFormFactorsModelI * Model (void) const {return fModel;}

  void   Reset    (Option_t * opt="");
  void   Copy     (const QELFormFactors & ff);
  bool   Compare  (const QELFormFactors & ff) const;
  void   Print    (ostream & stream) const;

  bool             operator == (const QELFormFactors & ff) const;
  QELFormFactors & operator =  (const QELFormFactors & ff);
  friend ostream & operator << (ostream & stream, const QELFormFactors & ff);

private:

  double fF1V;
  double fxiF2V;
  double fFA;
  double fFp;

  const QELFormFactorsModelI * fModel;
};

}        // genie namespace

#endif   // _QEL_FORM_FACTORS_H_
//____________________________________________________________________________
/*!

\class    genie::QELFormFactorsModelI

\brief    Pure abstract base class. Defines the QELFormFactorsModelI interface
          to be implemented by any algorithmic class computing Quasi-Elastic
          Form Factors.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _QEL_FORM_FACTORS_MODEL_I_H_
#define _QEL_FORM_FACTORS_MODEL_I_H_

#include "Algorithm/Algorithm.h"
#include "Interaction/Interaction.h"

namespace genie {

class QELFormFactorsModelI : public Algorithm {

public:
  virtual ~QELFormFactorsModelI();

  //! Compute the form factor F1V for the input interaction
  virtual double F1V   (const Interaction * interaction) const = 0;

  //! Compute the form factor xi*F2V for the input interaction
  virtual double xiF2V (const Interaction * interaction) const = 0;

  //! Compute the form factor FA for the input interaction
  virtual double FA    (const Interaction * interaction) const = 0;

  //! Compute the form factor Fp for the input interaction
  virtual double Fp    (const Interaction * interaction) const = 0;

protected:
  QELFormFactorsModelI();
  QELFormFactorsModelI(string name);
  QELFormFactorsModelI(string name, string config);
};

}         // genie namespace 
#endif    // _QEL_FORM_FACTORS_MODEL_I_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::DISStructureFunc", payloadCode, "@",
"genie::DISStructureFuncModelI", payloadCode, "@",
"genie::QELFormFactors", payloadCode, "@",
"genie::QELFormFactorsModelI", payloadCode, "@",
"genie::XSecAlgorithmI", payloadCode, "@",
"genie::XSecIntegratorI", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGBase",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGBase_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGBase_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGBase() {
  TriggerDictionaryInitialization_libGBase_Impl();
}
