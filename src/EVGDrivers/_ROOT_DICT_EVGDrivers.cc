// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_EVGDrivers

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
#include "GMCJMonitor.h"
#include "GeomAnalyzerI.h"
#include "GEVGPool.h"
#include "GFluxI.h"
#include "GEVGDriver.h"
#include "GMCJDriver.h"
#include "PathLengthList.h"

// Header files passed via #pragma extra_include

namespace genie {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "", 31,
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
   static TClass *geniecLcLGMCJMonitor_Dictionary();
   static void geniecLcLGMCJMonitor_TClassManip(TClass*);
   static void delete_geniecLcLGMCJMonitor(void *p);
   static void deleteArray_geniecLcLGMCJMonitor(void *p);
   static void destruct_geniecLcLGMCJMonitor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GMCJMonitor*)
   {
      ::genie::GMCJMonitor *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GMCJMonitor));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GMCJMonitor", "", 35,
                  typeid(::genie::GMCJMonitor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGMCJMonitor_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GMCJMonitor) );
      instance.SetDelete(&delete_geniecLcLGMCJMonitor);
      instance.SetDeleteArray(&deleteArray_geniecLcLGMCJMonitor);
      instance.SetDestructor(&destruct_geniecLcLGMCJMonitor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GMCJMonitor*)
   {
      return GenerateInitInstanceLocal((::genie::GMCJMonitor*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GMCJMonitor*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGMCJMonitor_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GMCJMonitor*)0x0)->GetClass();
      geniecLcLGMCJMonitor_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGMCJMonitor_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGeomAnalyzerI_Dictionary();
   static void geniecLcLGeomAnalyzerI_TClassManip(TClass*);
   static void delete_geniecLcLGeomAnalyzerI(void *p);
   static void deleteArray_geniecLcLGeomAnalyzerI(void *p);
   static void destruct_geniecLcLGeomAnalyzerI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GeomAnalyzerI*)
   {
      ::genie::GeomAnalyzerI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GeomAnalyzerI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GeomAnalyzerI", "", 89,
                  typeid(::genie::GeomAnalyzerI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGeomAnalyzerI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GeomAnalyzerI) );
      instance.SetDelete(&delete_geniecLcLGeomAnalyzerI);
      instance.SetDeleteArray(&deleteArray_geniecLcLGeomAnalyzerI);
      instance.SetDestructor(&destruct_geniecLcLGeomAnalyzerI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GeomAnalyzerI*)
   {
      return GenerateInitInstanceLocal((::genie::GeomAnalyzerI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GeomAnalyzerI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGeomAnalyzerI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GeomAnalyzerI*)0x0)->GetClass();
      geniecLcLGeomAnalyzerI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGeomAnalyzerI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGEVGPool_Dictionary();
   static void geniecLcLGEVGPool_TClassManip(TClass*);
   static void *new_geniecLcLGEVGPool(void *p = 0);
   static void *newArray_geniecLcLGEVGPool(Long_t size, void *p);
   static void delete_geniecLcLGEVGPool(void *p);
   static void deleteArray_geniecLcLGEVGPool(void *p);
   static void destruct_geniecLcLGEVGPool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GEVGPool*)
   {
      ::genie::GEVGPool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GEVGPool));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GEVGPool", "", 155,
                  typeid(::genie::GEVGPool), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGEVGPool_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GEVGPool) );
      instance.SetNew(&new_geniecLcLGEVGPool);
      instance.SetNewArray(&newArray_geniecLcLGEVGPool);
      instance.SetDelete(&delete_geniecLcLGEVGPool);
      instance.SetDeleteArray(&deleteArray_geniecLcLGEVGPool);
      instance.SetDestructor(&destruct_geniecLcLGEVGPool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GEVGPool*)
   {
      return GenerateInitInstanceLocal((::genie::GEVGPool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GEVGPool*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGEVGPool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GEVGPool*)0x0)->GetClass();
      geniecLcLGEVGPool_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGEVGPool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGFluxI_Dictionary();
   static void geniecLcLGFluxI_TClassManip(TClass*);
   static void delete_geniecLcLGFluxI(void *p);
   static void deleteArray_geniecLcLGFluxI(void *p);
   static void destruct_geniecLcLGFluxI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GFluxI*)
   {
      ::genie::GFluxI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GFluxI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GFluxI", "", 210,
                  typeid(::genie::GFluxI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGFluxI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GFluxI) );
      instance.SetDelete(&delete_geniecLcLGFluxI);
      instance.SetDeleteArray(&deleteArray_geniecLcLGFluxI);
      instance.SetDestructor(&destruct_geniecLcLGFluxI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GFluxI*)
   {
      return GenerateInitInstanceLocal((::genie::GFluxI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GFluxI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGFluxI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GFluxI*)0x0)->GetClass();
      geniecLcLGFluxI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGFluxI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGEVGDriver_Dictionary();
   static void geniecLcLGEVGDriver_TClassManip(TClass*);
   static void *new_geniecLcLGEVGDriver(void *p = 0);
   static void *newArray_geniecLcLGEVGDriver(Long_t size, void *p);
   static void delete_geniecLcLGEVGDriver(void *p);
   static void deleteArray_geniecLcLGEVGDriver(void *p);
   static void destruct_geniecLcLGEVGDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GEVGDriver*)
   {
      ::genie::GEVGDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GEVGDriver));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GEVGDriver", "", 291,
                  typeid(::genie::GEVGDriver), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGEVGDriver_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GEVGDriver) );
      instance.SetNew(&new_geniecLcLGEVGDriver);
      instance.SetNewArray(&newArray_geniecLcLGEVGDriver);
      instance.SetDelete(&delete_geniecLcLGEVGDriver);
      instance.SetDeleteArray(&deleteArray_geniecLcLGEVGDriver);
      instance.SetDestructor(&destruct_geniecLcLGEVGDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GEVGDriver*)
   {
      return GenerateInitInstanceLocal((::genie::GEVGDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GEVGDriver*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGEVGDriver_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GEVGDriver*)0x0)->GetClass();
      geniecLcLGEVGDriver_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGEVGDriver_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPathLengthList_Dictionary();
   static void geniecLcLPathLengthList_TClassManip(TClass*);
   static void *new_geniecLcLPathLengthList(void *p = 0);
   static void *newArray_geniecLcLPathLengthList(Long_t size, void *p);
   static void delete_geniecLcLPathLengthList(void *p);
   static void deleteArray_geniecLcLPathLengthList(void *p);
   static void destruct_geniecLcLPathLengthList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PathLengthList*)
   {
      ::genie::PathLengthList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PathLengthList));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PathLengthList", "PathLengthList.h", 43,
                  typeid(::genie::PathLengthList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPathLengthList_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PathLengthList) );
      instance.SetNew(&new_geniecLcLPathLengthList);
      instance.SetNewArray(&newArray_geniecLcLPathLengthList);
      instance.SetDelete(&delete_geniecLcLPathLengthList);
      instance.SetDeleteArray(&deleteArray_geniecLcLPathLengthList);
      instance.SetDestructor(&destruct_geniecLcLPathLengthList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PathLengthList*)
   {
      return GenerateInitInstanceLocal((::genie::PathLengthList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PathLengthList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPathLengthList_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PathLengthList*)0x0)->GetClass();
      geniecLcLPathLengthList_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPathLengthList_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGMCJDriver_Dictionary();
   static void geniecLcLGMCJDriver_TClassManip(TClass*);
   static void *new_geniecLcLGMCJDriver(void *p = 0);
   static void *newArray_geniecLcLGMCJDriver(Long_t size, void *p);
   static void delete_geniecLcLGMCJDriver(void *p);
   static void deleteArray_geniecLcLGMCJDriver(void *p);
   static void destruct_geniecLcLGMCJDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GMCJDriver*)
   {
      ::genie::GMCJDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GMCJDriver));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GMCJDriver", "", 417,
                  typeid(::genie::GMCJDriver), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGMCJDriver_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GMCJDriver) );
      instance.SetNew(&new_geniecLcLGMCJDriver);
      instance.SetNewArray(&newArray_geniecLcLGMCJDriver);
      instance.SetDelete(&delete_geniecLcLGMCJDriver);
      instance.SetDeleteArray(&deleteArray_geniecLcLGMCJDriver);
      instance.SetDestructor(&destruct_geniecLcLGMCJDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GMCJDriver*)
   {
      return GenerateInitInstanceLocal((::genie::GMCJDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GMCJDriver*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGMCJDriver_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GMCJDriver*)0x0)->GetClass();
      geniecLcLGMCJDriver_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGMCJDriver_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLGMCJMonitor(void *p) {
      delete ((::genie::GMCJMonitor*)p);
   }
   static void deleteArray_geniecLcLGMCJMonitor(void *p) {
      delete [] ((::genie::GMCJMonitor*)p);
   }
   static void destruct_geniecLcLGMCJMonitor(void *p) {
      typedef ::genie::GMCJMonitor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GMCJMonitor

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLGeomAnalyzerI(void *p) {
      delete ((::genie::GeomAnalyzerI*)p);
   }
   static void deleteArray_geniecLcLGeomAnalyzerI(void *p) {
      delete [] ((::genie::GeomAnalyzerI*)p);
   }
   static void destruct_geniecLcLGeomAnalyzerI(void *p) {
      typedef ::genie::GeomAnalyzerI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GeomAnalyzerI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLGEVGPool(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GEVGPool : new ::genie::GEVGPool;
   }
   static void *newArray_geniecLcLGEVGPool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GEVGPool[nElements] : new ::genie::GEVGPool[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLGEVGPool(void *p) {
      delete ((::genie::GEVGPool*)p);
   }
   static void deleteArray_geniecLcLGEVGPool(void *p) {
      delete [] ((::genie::GEVGPool*)p);
   }
   static void destruct_geniecLcLGEVGPool(void *p) {
      typedef ::genie::GEVGPool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GEVGPool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLGFluxI(void *p) {
      delete ((::genie::GFluxI*)p);
   }
   static void deleteArray_geniecLcLGFluxI(void *p) {
      delete [] ((::genie::GFluxI*)p);
   }
   static void destruct_geniecLcLGFluxI(void *p) {
      typedef ::genie::GFluxI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GFluxI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLGEVGDriver(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GEVGDriver : new ::genie::GEVGDriver;
   }
   static void *newArray_geniecLcLGEVGDriver(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GEVGDriver[nElements] : new ::genie::GEVGDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLGEVGDriver(void *p) {
      delete ((::genie::GEVGDriver*)p);
   }
   static void deleteArray_geniecLcLGEVGDriver(void *p) {
      delete [] ((::genie::GEVGDriver*)p);
   }
   static void destruct_geniecLcLGEVGDriver(void *p) {
      typedef ::genie::GEVGDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GEVGDriver

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLPathLengthList(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PathLengthList : new ::genie::PathLengthList;
   }
   static void *newArray_geniecLcLPathLengthList(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PathLengthList[nElements] : new ::genie::PathLengthList[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLPathLengthList(void *p) {
      delete ((::genie::PathLengthList*)p);
   }
   static void deleteArray_geniecLcLPathLengthList(void *p) {
      delete [] ((::genie::PathLengthList*)p);
   }
   static void destruct_geniecLcLPathLengthList(void *p) {
      typedef ::genie::PathLengthList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::PathLengthList

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLGMCJDriver(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GMCJDriver : new ::genie::GMCJDriver;
   }
   static void *newArray_geniecLcLGMCJDriver(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GMCJDriver[nElements] : new ::genie::GMCJDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLGMCJDriver(void *p) {
      delete ((::genie::GMCJDriver*)p);
   }
   static void deleteArray_geniecLcLGMCJDriver(void *p) {
      delete [] ((::genie::GMCJDriver*)p);
   }
   static void destruct_geniecLcLGMCJDriver(void *p) {
      typedef ::genie::GMCJDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GMCJDriver

namespace {
  void TriggerDictionaryInitialization_libGEVGDrivers_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"EVGDrivers",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/EVGDrivers",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/EVGDrivers",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/EVGDrivers/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGEVGDrivers dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class GMCJMonitor;}
namespace genie{class GeomAnalyzerI;}
namespace genie{class GEVGPool;}
namespace genie{class GFluxI;}
namespace genie{class GEVGDriver;}
namespace genie{class __attribute__((annotate("$clingAutoload$EVGDrivers/PathLengthList.h")))  PathLengthList;}
namespace genie{class GMCJDriver;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGEVGDrivers dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class   genie::GMCJMonitor

\brief   Simple class to create & update MC job status files and env. vars.
         This is used to be able to keep track of an MC job status even when
         all output is suppressed or redirected to /dev/null.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created July 13, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _G_MC_JOB_MONITOR_H_
#define _G_MC_JOB_MONITOR_H_

#include <TStopwatch.h>

namespace genie {

class EventRecord;

class GMCJMonitor {

public :
  GMCJMonitor(Long_t runnu);
 ~GMCJMonitor();

  void SetRefreshRate (int rate);
  void Update (int iev, const EventRecord * event);
  void CustomizeFilename(string filename);

private:

  void Init (void);

  Long_t     fRunNu;       ///< run number
  string     fStatusFile;  ///< name of output status file
  TStopwatch fWatch;       
  double     fCpuTime;     ///< total cpu time so far
  int        fRefreshRate; ///< update output every so many events
};

}      // genie namespace

#endif // _G_MC_JOB_MONITOR_H_
//____________________________________________________________________________
/*!

\class    genie::GeomAnalyzerI

\brief    Defines the GENIE Geometry Analyzer Interface

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  July 13, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _GEOMETRY_ANALYZER_I_H_
#define _GEOMETRY_ANALYZER_I_H_

class TLorentzVector;
class TVector3;

namespace genie {

class PDGCodeList;
class PathLengthList;

class GeomAnalyzerI {

public :

  virtual ~GeomAnalyzerI();

  // define the GeomAnalyzerI interface

  virtual const PDGCodeList &
            ListOfTargetNuclei (void) = 0;

  virtual const PathLengthList & 
            ComputeMaxPathLengths (void) = 0;
  virtual const PathLengthList &
            ComputePathLengths (
              const TLorentzVector & x, const TLorentzVector & p) = 0;
  virtual const TVector3 &
            GenerateVertex (
              const TLorentzVector & x, const TLorentzVector & p, int tgtpdg) = 0;

protected:

  GeomAnalyzerI();
};

}      // genie namespace

#endif // _GEOMETRY_ANALYZER_I_H_
//____________________________________________________________________________
/*!

\class   genie::GEVGPool

\brief   A pool of GEVGDriver objects with an initial state key

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 24, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _GEVG_DRIVER_POOL_H_
#define _GEVG_DRIVER_POOL_H_

#include <map>
#include <string>
#include <ostream>

using std::map;
using std::string;
using std::ostream;

namespace genie {

class GEVGPool;
class GEVGDriver;
class InitialState;

ostream & operator << (ostream & stream, const GEVGPool & pool);

class GEVGPool : public map<string, GEVGDriver *> {

public :

  GEVGPool();
  ~GEVGPool();

  GEVGDriver * FindDriver (const InitialState & init) const;
  GEVGDriver * FindDriver (string init)               const;

  void Print (ostream & stream) const;

  friend ostream & operator << (ostream & stream, const GEVGPool & pool);
};

}      // genie namespace

#endif // _GEVG_DRIVER_POOL_H_
//____________________________________________________________________________
/*!

\class    genie::GFluxI

\brief    GENIE Interface for user-defined flux classes

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 25, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE

 @ Feb 22, 2011 - JD
   Changed the interface by adding the GFluxI::Clear, GFluxI::Index and 
   GFluxI::GenerateWeighted methods needed so that can be used with the new 
   pre-generation of flux interaction probabilities functionality added to
   GMCJDriver. 

*/
//____________________________________________________________________________

#ifndef _G_FLUX_I_H_
#define _G_FLUX_I_H_

#include <TObject.h>

class TLorentzVector;

namespace genie {

class PDGCodeList;

class GFluxI {

public :
  virtual ~GFluxI();

  //
  // define the GFluxI interface:
  //
  virtual const PDGCodeList &    FluxParticles (void) = 0; ///< declare list of flux neutrinos that can be generated (for init. purposes)
  virtual double                 MaxEnergy     (void) = 0; ///< declare the max flux neutrino energy that can be generated (for init. purposes)
  virtual bool                   GenerateNext  (void) = 0; ///< generate the next flux neutrino (return false in err)
  virtual int                    PdgCode       (void) = 0; ///< returns the flux neutrino pdg code
  virtual double                 Weight        (void) = 0; ///< returns the flux neutrino weight (if any)
  virtual const TLorentzVector & Momentum      (void) = 0; ///< returns the flux neutrino 4-momentum 
  virtual const TLorentzVector & Position      (void) = 0; ///< returns the flux neutrino 4-position (note: expect SI rather than physical units)
  virtual bool                   End           (void) = 0; ///< true if no more flux nu's can be thrown (eg reaching end of beam sim ntuples)
  virtual long int               Index         (void) = 0; ///< returns corresponding index for current flux neutrino (e.g. for a flux ntuple returns the current entry number)
  virtual void                   Clear            (Option_t * opt   ) = 0; ///< reset state variables based on opt
  virtual void                   GenerateWeighted (bool gen_weighted) = 0; ///< set whether to generate weighted or unweighted neutrinos

protected:
  GFluxI();
};

}      // genie namespace
#endif // _G_FLUX_I_H_
//____________________________________________________________________________
/*!

\class   genie::GEVGDriver

\brief   GENIE Event Generation Driver.
         A minimalist user interface object for generating neutrino interactions.
         Each such object is configured for a given initial state and it drives all
         relevant GENIE neutrino interaction physics simulation code for that state.
         To set-up MC jobs involving a multitude of possible initial states,
         including arbitrarily complex neutrino flux and detector geometry 
         descriptions, see the GMCJDriver object.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created August 06, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _GEVG_DRIVER_H_
#define _GEVG_DRIVER_H_

#include <ostream>
#include <string>

#include <TLorentzVector.h>
#include <TBits.h>

#include "Utils/Range1.h"

using std::ostream;
using std::string;

namespace genie {

class GEVGDriver;
class EventRecord;
class EventGeneratorList;
class EventGeneratorI;
class InteractionSelectorI;
class InteractionGeneratorMap;
class InteractionList;
class Interaction;
class InitialState;
class Target;
class Spline;

ostream & operator << (ostream & stream, const GEVGDriver & driver);

class GEVGDriver {

public :
  GEVGDriver();
 ~GEVGDriver();

  // Driver options:
  // - Set before calling Configure()
  void UseSplines (void);
  void SetEventGeneratorList(string listname);
  // - Set before GenerateEvent()
  void SetUnphysEventMask(const TBits & mask);

  // Configure the driver
  void Configure (int nu_pdgc, int Z, int A);
  void Configure (const InitialState & init_state);

  // Generate single event
  EventRecord * GenerateEvent (const TLorentzVector & nu4p);

  // Get the list of all interactions that can be simulated for the specified 
  // initial state (depends on which event generation threads were loaded into
  // the event generation driver driver)
  const InteractionList * Interactions(void) const;

  // Get event generator thread list
  const EventGeneratorList * EventGenerators (void) const { return fEvGenList; }

  // Get the event generator that is responsible for generating the input event
  const EventGeneratorI * FindGenerator(const Interaction * interaction) const;

  // Cross section splines for input interaction and for the sum of all
  // simulated interactions for the specified initial state
  const Spline * XSecSumSpline       (void) const { return fXSecSumSpl; }
  const Spline * XSecSpline          (const Interaction * interaction) const;

  // Instruct the driver to create all the splines it needs
  void CreateSplines (int nknots=-1, double emax=-1, bool inLogE=true);

  // Methods used for building the 'total' cross section spline
  double XSecSum             (const TLorentzVector & nup4);
  void   CreateXSecSumSpline (int nk, double Emin, double Emax, bool inlogE=true);

  // Get validity range (combined validity range of loaded evg threads)
  Range1D_t ValidEnergyRange (void) const;

  // Reset, Print etc
  void Reset (void);
  void Print (ostream & stream) const;

  friend ostream & operator << (ostream & stream, const GEVGDriver & driver);

private:

  // Private initialization, configuration & input validation methods
  void Init                         (void);
  void CleanUp                      (void);
  void BuildInitialState            (const InitialState & init_state);
  void BuildGeneratorList           (void);
  void BuildInteractionGeneratorMap (void);
  void BuildInteractionSelector     (void);
  void AssertIsValidInitState       (void) const;

  // Private data members
  InitialState *            fInitState;       ///< initial state information for driver instance
  EventRecord *             fCurrentRecord;   ///< ptr to the event record being processed
  EventGeneratorList *      fEvGenList;       ///< all Event Generators available at this job
  InteractionSelectorI *    fIntSelector;     ///< interaction selector
  InteractionGeneratorMap * fIntGenMap;       ///< interaction -> generator assosiative container
  TBits *                   fUnphysEventMask; ///< controls whether unphysical events are returned
  bool                      fUseSplines;      ///< controls whether xsecs are computed or interpolated
  Spline *                  fXSecSumSpl;      ///< sum{xsec(all interactions | this init state)}
  unsigned int              fNRecLevel;       ///< recursive mode depth counter
  string                    fEventGenList;    ///< list of event generators loaded by this driver (what used to be the $GEVGL setting)
};

}      // genie namespace

#endif // _GENIE_H_
//____________________________________________________________________________
/*!

\class    genie::GMCJDriver

\brief    A GENIE `MC Job Driver'. Can be used for setting up complicated event 
          generation cases involving detailed flux descriptions and detector 
          geometry descriptions.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 25, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _GENIE_MC_JOB_DRIVER_H_
#define _GENIE_MC_JOB_DRIVER_H_

#include <string>
#include <map>

#include <TH1D.h>
#include <TLorentzVector.h>
#include <TFile.h>
#include <TTree.h>
#include <TBits.h>

#include "EVGDrivers/PathLengthList.h"
#include "PDG/PDGCodeList.h"

using std::string;
using std::map;

namespace genie {

class EventRecord;
class GFluxI;
class GeomAnalyzerI;
class GENIE;
class GEVGPool;

class GMCJDriver {

public :
  GMCJDriver();
 ~GMCJDriver();

  // configure MC job
  void SetEventGeneratorList       (string listname);
  void SetUnphysEventMask          (const TBits & mask);
  void UseFluxDriver               (GFluxI * flux);
  void UseGeomAnalyzer             (GeomAnalyzerI * geom);
  void UseSplines                  (bool useLogE = true);
  bool UseMaxPathLengths           (string xml_filename);
  void KeepOnThrowingFluxNeutrinos (bool keep_on);
  void ForceSingleProbScale        (void);
  void PreSelectEvents             (bool preselect = true);
  bool PreCalcFluxProbabilities    (void);
  bool LoadFluxProbabilities       (string filename);
  void SaveFluxProbabilities       (string outfilename);
  void Configure                   (bool calc_prob_scales = true);

  // generate single neutrino event for input flux & geometry
  EventRecord * GenerateEvent (void);

  // info needed for computing the generated sample normalization
  double   GlobProbScale  (void) const { return fGlobPmax;                  }
  long int NFluxNeutrinos (void) const { return (long int) fNFluxNeutrinos; }
  map<int, double> SumFluxIntProbs(void) const { return fSumFluxIntProbs;   }

  // input flux and geometry drivers
  const GFluxI &        FluxDriver      (void) const { return *fFluxDriver;   }
  const GeomAnalyzerI & GeomAnalyzer    (void) const { return *fGeomAnalyzer; }
  GFluxI *              FluxDriverPtr   (void) const { return  fFluxDriver;   } 
  GeomAnalyzerI *       GeomAnalyzerPtr (void) const { return  fGeomAnalyzer; }

private:
 
  // private methods:
  void          InitJob                         (void);
  void          InitEventGeneration             (void);
  void          GetParticleLists                (void);
  void          GetMaxPathLengthList            (void);
  void          GetMaxFluxEnergy                (void);
  void          PopulateEventGenDriverPool      (void);
  void          BootstrapXSecSplines            (void);
  void          BootstrapXSecSplineSummation    (void);
  void          ComputeProbScales               (void);
  EventRecord * GenerateEvent1Try               (void);
  bool          GenerateFluxNeutrino            (void);
  bool          ComputePathLengths              (void);
  double	ComputeInteractionProbabilities (bool use_max_path_length);
  int           SelectTargetMaterial            (double R);
  void          GenerateEventKinematics         (void);
  void          GenerateVertexPosition          (void);
  void          ComputeEventProbability         (void);
  double        InteractionProbability          (double xsec, double pl, int A);
  double        PreGenFluxInteractionProbability(void);

  // private data members:
  GEVGPool *      fGPool;              ///< A pool of GEVGDrivers properly configured event generation drivers / one per init state
  GFluxI *        fFluxDriver;         ///< [input] neutrino flux driver
  GeomAnalyzerI * fGeomAnalyzer;       ///< [input] detector geometry analyzer
  double          fEmax;               ///< [declared by the flux driver] maximum neutrino energy 
  PDGCodeList     fNuList;             ///< [declared by the flux driver] list of neutrino codes 
  PDGCodeList     fTgtList;            ///< [declared by the geom driver] list of target codes 
  PathLengthList  fMaxPathLengths;     ///< [declared by the geom driver] maximum path length list 
  PathLengthList  fCurPathLengths;     ///< [current] path length list for current flux neutrino
  TLorentzVector  fCurVtx;             ///< [current] interaction vertex
  EventRecord *   fCurEvt;             ///< [current] generated event
  int             fSelTgtPdg;          ///< [current] selected target material PDG code
  map<int,double> fCurCumulProbMap;    ///< [current] cummulative interaction probabilities
  double          fNFluxNeutrinos;     ///< [current] number of flux nuetrinos fired by the flux driver so far 
  map<int,TH1D*>  fPmax;               ///< [computed at init] interaction probability scale /neutrino /energy for given geometry
  double          fGlobPmax;           ///< [computed at init] global interaction probability scale for given flux & geometry
  string          fEventGenList;       ///< [config] list of event generators loaded by this driver (what used to be the $GEVGL setting)
  TBits *         fUnphysEventMask;    ///< [config] controls whether unphysical events are returned (what used to be the $GUNPHYSMASK setting)
  string          fMaxPlXmlFilename;   ///< [config] input file with max density-weighted path lengths for all materials
  bool            fUseExtMaxPl;        ///< [config] using external max path length estimate?
  bool            fUseSplines;         ///< [config] compute all needed & not-loaded splines at init
  bool            fUseLogE;            ///< [config] build splines = f(logE) (rather than f(E)) ?
  bool            fKeepThrowingFluxNu; ///< [config] keep firing flux neutrinos till one of them interacts
  bool            fGenerateUnweighted; ///< [config] force single probability scale?
  bool            fPreSelect;          ///< [config] set whether to pre-select events using max interaction paths 
  TFile*          fFluxIntProbFile;    ///< [input] pre-generated flux interaction probability file
  TTree*          fFluxIntTree;        ///< [computed-or-loaded] pre-computed flux interaction probabilities (expected tree name is "gFlxIntProbs")
  double          fBrFluxIntProb;      ///< flux interaction probability (set to branch:"FluxIntProb")
  int             fBrFluxIndex;        ///< corresponding entry in flux input tree (set to address of branch:"FluxEntry")
  double          fBrFluxEnu;          ///< corresponding flux P4 (set to address of branch:"FluxP4") 
  double          fBrFluxWeight;       ///< corresponding flux weight (set to address of branch: "FluxWeight") 
  int             fBrFluxPDG;          ///< corresponding flux pdg code (set to address of branch: "FluxPDG") 
  string          fFluxIntFileName;    ///< whether to save pre-generated flux tree for use in later jobs
  string          fFluxIntTreeName;    ///< name for tree holding flux probabilities 
  map<int, double> fSumFluxIntProbs;   ///< map where the key is flux pdg code and the value is sum of fBrFluxWeight * fBrFluxIntProb for all these flux neutrinos 
};

}      // genie namespace
#endif // _GENIE_MC_JOB_DRIVER_H_
//____________________________________________________________________________
/*!

\class   genie::PathLengthList

\brief   Object to be filled with the neutrino path-length, for all detector
         geometry materials, when starting from a position x and travelling
         along the direction of the neutrino 4-momentum.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 24, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PATH_LENGTH_LIST_H_
#define _PATH_LENGTH_LIST_H_

#include <map>
#include <ostream>
#include <string>

#include "Conventions/XmlParserStatus.h"

class TLorentzVector;

using std::map;
using std::ostream;
using std::string;

namespace genie {

class PathLengthList;
class PDGCodeList;

ostream & operator << (ostream & stream, const PathLengthList & list);

class PathLengthList : public map<int, double> {

public :
  PathLengthList();
  PathLengthList(const PDGCodeList & pdglist);
  PathLengthList(const PathLengthList & plist);
  PathLengthList(const map<int,double> & plist);
 ~PathLengthList();

  void   AddPathLength   (int pdgc, double pl); // path-legth(pdgc) += pl
  void   SetPathLength   (int pdgc, double pl); // path-legth(pdgc)  = pl
  void   SetAllToZero    (void);
  bool   AreAllZero      (void) const;
  void   ScalePathLength (int pdgc, double scale);
  double PathLength      (int pdgc) const;

  XmlParserStatus_t LoadFromXml (string filename);
  void              SaveAsXml   (string filename) const;

  void Copy  (const PathLengthList & plist);
  void Print (ostream & stream) const;

  PathLengthList & operator =  (const PathLengthList & list);
  friend ostream & operator << (ostream & stream, const PathLengthList & list);
};

}      // genie namespace

#endif // _PATH_LENGTH_LIST_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::GEVGDriver", payloadCode, "@",
"genie::GEVGPool", payloadCode, "@",
"genie::GFluxI", payloadCode, "@",
"genie::GMCJDriver", payloadCode, "@",
"genie::GMCJMonitor", payloadCode, "@",
"genie::GeomAnalyzerI", payloadCode, "@",
"genie::PathLengthList", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGEVGDrivers",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGEVGDrivers_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGEVGDrivers_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGEVGDrivers() {
  TriggerDictionaryInitialization_libGEVGDrivers_Impl();
}
