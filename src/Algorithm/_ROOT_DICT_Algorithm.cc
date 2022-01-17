// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_Algorithm

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
#include "AlgId.h"
#include "Algorithm.h"
#include "AlgFactory.h"
#include "AlgConfigPool.h"

// Header files passed via #pragma extra_include

namespace genie {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "", 35,
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
   static TClass *geniecLcLAlgId_Dictionary();
   static void geniecLcLAlgId_TClassManip(TClass*);
   static void *new_geniecLcLAlgId(void *p = 0);
   static void *newArray_geniecLcLAlgId(Long_t size, void *p);
   static void delete_geniecLcLAlgId(void *p);
   static void deleteArray_geniecLcLAlgId(void *p);
   static void destruct_geniecLcLAlgId(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::AlgId*)
   {
      ::genie::AlgId *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::AlgId));
      static ::ROOT::TGenericClassInfo 
         instance("genie::AlgId", "", 40,
                  typeid(::genie::AlgId), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgId_Dictionary, isa_proxy, 0,
                  sizeof(::genie::AlgId) );
      instance.SetNew(&new_geniecLcLAlgId);
      instance.SetNewArray(&newArray_geniecLcLAlgId);
      instance.SetDelete(&delete_geniecLcLAlgId);
      instance.SetDeleteArray(&deleteArray_geniecLcLAlgId);
      instance.SetDestructor(&destruct_geniecLcLAlgId);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::AlgId*)
   {
      return GenerateInitInstanceLocal((::genie::AlgId*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::AlgId*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgId_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::AlgId*)0x0)->GetClass();
      geniecLcLAlgId_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgId_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLAlgStatus_Dictionary();
   static void geniecLcLAlgStatus_TClassManip(TClass*);
   static void *new_geniecLcLAlgStatus(void *p = 0);
   static void *newArray_geniecLcLAlgStatus(Long_t size, void *p);
   static void delete_geniecLcLAlgStatus(void *p);
   static void deleteArray_geniecLcLAlgStatus(void *p);
   static void destruct_geniecLcLAlgStatus(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::AlgStatus*)
   {
      ::genie::AlgStatus *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::AlgStatus));
      static ::ROOT::TGenericClassInfo 
         instance("genie::AlgStatus", "AlgStatus.h", 37,
                  typeid(::genie::AlgStatus), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgStatus_Dictionary, isa_proxy, 0,
                  sizeof(::genie::AlgStatus) );
      instance.SetNew(&new_geniecLcLAlgStatus);
      instance.SetNewArray(&newArray_geniecLcLAlgStatus);
      instance.SetDelete(&delete_geniecLcLAlgStatus);
      instance.SetDeleteArray(&deleteArray_geniecLcLAlgStatus);
      instance.SetDestructor(&destruct_geniecLcLAlgStatus);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::AlgStatus*)
   {
      return GenerateInitInstanceLocal((::genie::AlgStatus*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::AlgStatus*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgStatus_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::AlgStatus*)0x0)->GetClass();
      geniecLcLAlgStatus_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgStatus_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLAlgCmp_Dictionary();
   static void geniecLcLAlgCmp_TClassManip(TClass*);
   static void *new_geniecLcLAlgCmp(void *p = 0);
   static void *newArray_geniecLcLAlgCmp(Long_t size, void *p);
   static void delete_geniecLcLAlgCmp(void *p);
   static void deleteArray_geniecLcLAlgCmp(void *p);
   static void destruct_geniecLcLAlgCmp(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::AlgCmp*)
   {
      ::genie::AlgCmp *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::AlgCmp));
      static ::ROOT::TGenericClassInfo 
         instance("genie::AlgCmp", "AlgCmp.h", 38,
                  typeid(::genie::AlgCmp), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgCmp_Dictionary, isa_proxy, 0,
                  sizeof(::genie::AlgCmp) );
      instance.SetNew(&new_geniecLcLAlgCmp);
      instance.SetNewArray(&newArray_geniecLcLAlgCmp);
      instance.SetDelete(&delete_geniecLcLAlgCmp);
      instance.SetDeleteArray(&deleteArray_geniecLcLAlgCmp);
      instance.SetDestructor(&destruct_geniecLcLAlgCmp);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::AlgCmp*)
   {
      return GenerateInitInstanceLocal((::genie::AlgCmp*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::AlgCmp*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgCmp_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::AlgCmp*)0x0)->GetClass();
      geniecLcLAlgCmp_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgCmp_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLAlgorithm_Dictionary();
   static void geniecLcLAlgorithm_TClassManip(TClass*);
   static void delete_geniecLcLAlgorithm(void *p);
   static void deleteArray_geniecLcLAlgorithm(void *p);
   static void destruct_geniecLcLAlgorithm(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::Algorithm*)
   {
      ::genie::Algorithm *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::Algorithm));
      static ::ROOT::TGenericClassInfo 
         instance("genie::Algorithm", "", 124,
                  typeid(::genie::Algorithm), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgorithm_Dictionary, isa_proxy, 0,
                  sizeof(::genie::Algorithm) );
      instance.SetDelete(&delete_geniecLcLAlgorithm);
      instance.SetDeleteArray(&deleteArray_geniecLcLAlgorithm);
      instance.SetDestructor(&destruct_geniecLcLAlgorithm);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::Algorithm*)
   {
      return GenerateInitInstanceLocal((::genie::Algorithm*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::Algorithm*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgorithm_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::Algorithm*)0x0)->GetClass();
      geniecLcLAlgorithm_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgorithm_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLAlgFactory_Dictionary();
   static void geniecLcLAlgFactory_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::AlgFactory*)
   {
      ::genie::AlgFactory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::AlgFactory));
      static ::ROOT::TGenericClassInfo 
         instance("genie::AlgFactory", "", 245,
                  typeid(::genie::AlgFactory), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgFactory_Dictionary, isa_proxy, 0,
                  sizeof(::genie::AlgFactory) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::AlgFactory*)
   {
      return GenerateInitInstanceLocal((::genie::AlgFactory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::AlgFactory*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgFactory_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::AlgFactory*)0x0)->GetClass();
      geniecLcLAlgFactory_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgFactory_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLAlgConfigPool_Dictionary();
   static void geniecLcLAlgConfigPool_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::AlgConfigPool*)
   {
      ::genie::AlgConfigPool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::AlgConfigPool));
      static ::ROOT::TGenericClassInfo 
         instance("genie::AlgConfigPool", "", 342,
                  typeid(::genie::AlgConfigPool), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLAlgConfigPool_Dictionary, isa_proxy, 0,
                  sizeof(::genie::AlgConfigPool) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::AlgConfigPool*)
   {
      return GenerateInitInstanceLocal((::genie::AlgConfigPool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::AlgConfigPool*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLAlgConfigPool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::AlgConfigPool*)0x0)->GetClass();
      geniecLcLAlgConfigPool_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLAlgConfigPool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLAlgId(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgId : new ::genie::AlgId;
   }
   static void *newArray_geniecLcLAlgId(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgId[nElements] : new ::genie::AlgId[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLAlgId(void *p) {
      delete ((::genie::AlgId*)p);
   }
   static void deleteArray_geniecLcLAlgId(void *p) {
      delete [] ((::genie::AlgId*)p);
   }
   static void destruct_geniecLcLAlgId(void *p) {
      typedef ::genie::AlgId current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::AlgId

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLAlgStatus(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgStatus : new ::genie::AlgStatus;
   }
   static void *newArray_geniecLcLAlgStatus(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgStatus[nElements] : new ::genie::AlgStatus[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLAlgStatus(void *p) {
      delete ((::genie::AlgStatus*)p);
   }
   static void deleteArray_geniecLcLAlgStatus(void *p) {
      delete [] ((::genie::AlgStatus*)p);
   }
   static void destruct_geniecLcLAlgStatus(void *p) {
      typedef ::genie::AlgStatus current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::AlgStatus

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLAlgCmp(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgCmp : new ::genie::AlgCmp;
   }
   static void *newArray_geniecLcLAlgCmp(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::AlgCmp[nElements] : new ::genie::AlgCmp[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLAlgCmp(void *p) {
      delete ((::genie::AlgCmp*)p);
   }
   static void deleteArray_geniecLcLAlgCmp(void *p) {
      delete [] ((::genie::AlgCmp*)p);
   }
   static void destruct_geniecLcLAlgCmp(void *p) {
      typedef ::genie::AlgCmp current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::AlgCmp

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLAlgorithm(void *p) {
      delete ((::genie::Algorithm*)p);
   }
   static void deleteArray_geniecLcLAlgorithm(void *p) {
      delete [] ((::genie::Algorithm*)p);
   }
   static void destruct_geniecLcLAlgorithm(void *p) {
      typedef ::genie::Algorithm current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::Algorithm

namespace ROOT {
} // end of namespace ROOT for class ::genie::AlgFactory

namespace ROOT {
} // end of namespace ROOT for class ::genie::AlgConfigPool

namespace {
  void TriggerDictionaryInitialization_libGAlgorithm_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"Algorithm",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/Algorithm",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/Algorithm",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/Algorithm/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGAlgorithm dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class AlgId;}
namespace genie{class __attribute__((annotate("$clingAutoload$Algorithm/AlgStatus.h")))  AlgStatus;}
namespace genie{class __attribute__((annotate("$clingAutoload$Algorithm/AlgCmp.h")))  AlgCmp;}
namespace genie{class Algorithm;}
namespace genie{class AlgFactory;}
namespace genie{class AlgConfigPool;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGAlgorithm dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::AlgId

\brief    Algorithm ID (algorithm name + configuration set name)

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  October 20, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _ALGID_H_
#define _ALGID_H_

#include <string>
#include <iostream>

#include "Registry/RegistryItemTypeDef.h"

using std::string;
using std::ostream;

namespace genie {

class AlgId;
ostream & operator << (ostream & stream, const AlgId & alg);

class AlgId {

public:

  AlgId();
  AlgId(string name, string config);
  AlgId(const AlgId & id);
  AlgId(const RgAlg & registry_item);
 ~AlgId();

  string Name   (void) const { return fName;   }
  string Config (void) const { return fConfig; }
  string Key    (void) const { return fKey;    }

  void   SetId     (string name, string config="");
  void   SetName   (string name);
  void   SetConfig (string config);
  void   Copy      (const AlgId & id);
  void   Copy      (const RgAlg & registry_item);
  void   Print     (ostream & stream) const;

  friend ostream & operator << (ostream & stream, const AlgId & alg);

private:

  void Init      (void);
  void UpdateKey (void);

  string fName;   ///< Algorithm name (including namespaces)
  string fConfig; ///< Configuration set name
  string fKey;    ///< Unique key: namespace::alg_name/alg_config
};

}       // genie namespace

#endif  // _ALGID_H_
//____________________________________________________________________________
/*!

\class    genie::Algorithm

\brief    Algorithm abstract base class.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 02, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <string>
#include <iostream>
#include <cassert>
#include <map>

#include "Algorithm/AlgStatus.h"
#include "Algorithm/AlgCmp.h"
#include "Algorithm/AlgId.h"
#include "Registry/Registry.h"
#include "Registry/RegistryItemTypeDef.h"

using std::string;
using std::ostream;
using std::map;

namespace genie {

class Algorithm;

ostream & operator << (ostream & stream, const Algorithm & alg);

typedef map <string, Algorithm *>                 AlgMap;
typedef map <string, Algorithm *>::iterator       AlgMapIter;
typedef map <string, Algorithm *>::const_iterator AlgMapConstIter;
typedef pair<string, Algorithm *>                 AlgMapPair;

class Algorithm {

public:
  virtual ~Algorithm();

  //! Configure the algorithm
  virtual void Configure (const Registry & config);  

  //! Configure the algorithm 
  virtual void Configure (string config);            

  //! Lookup configuration from the config pool
  virtual void FindConfig (void);   

  //! Get configuration registry
  virtual const Registry & GetConfig(void) const { return *fConfig; }

  //! Get a writeable version of an owned configuration Registry.
  Registry * GetOwnedConfig(void);

  //! Get algorithm ID
  virtual const AlgId & Id(void) const { return fID; }

  //! Get algorithm status
  virtual AlgStatus_t GetStatus(void) const { return fStatus; }

  //! Allow reconfigration after initializaton?
  //! Algorithms may opt-out, if reconfiguration is not necessary, 
  //! to improve event reweighting speed.
  virtual bool AllowReconfig(void) const { return fAllowReconfig; }

  //! Compare with input algorithm
  virtual AlgCmp_t Compare(const Algorithm * alg) const;

  //! Set algorithm ID
  virtual void SetId(const AlgId & id);
  virtual void SetId(string name,  string config);

  //! Access the sub-algorithm pointed to by the input key, either from the 
  //! local pool or from AlgFactory's pool
  const Algorithm * SubAlg(const RgKey & registry_key) const;

  //! Clone the configuration registry looked up from the configuration pool
  //! and take its ownership
  void AdoptConfig (void);

  //! Take ownership of the algorithms subtructure (sub-algorithms,...)
  //! by copying them from the AlgFactory pool to the local pool
  //! Also bring all the configuration variables to the top level config Registry.
  //! This can be used to group together a series of algorithms & their
  //! configurations and extract (a clone of) this group from the shared 
  //! pools. Having a series of algorithms/configurations behaving as a
  //! monolithic block, with a single point of configuration (the top level)
  //! is to be used when bits & pieces of GENIE are used in isolation for
  //! data fitting or reweighting
  void AdoptSubstructure (void);

  //! Print algorithm info
  virtual void Print(ostream & stream) const;
  friend ostream & operator << (ostream & stream, const Algorithm & alg);

protected:
  Algorithm();
  Algorithm(string name);
  Algorithm(string name, string config);

  void Initialize         (void);
  void DeleteConfig       (void);
  void DeleteSubstructure (void);

  bool         fAllowReconfig; ///<
  bool         fOwnsConfig;    ///< true if it owns its config. registry
  bool         fOwnsSubstruc;  ///< true if it owns its substructure (sub-algs,...)
  AlgId        fID;            ///< algorithm name and configuration set
  Registry *   fConfig;        ///< config. (either owned or pointing to config pool)
  AlgStatus_t  fStatus;        ///< algorithm execution status
  AlgMap *     fOwnedSubAlgMp; ///< local pool for owned sub-algs (taken out of the factory pool)
};

}       // genie namespace
#endif  // _ALGORITHM_H_
//____________________________________________________________________________
/*!

\class    genie::AlgFactory

\brief    The GENIE Algorithm Factory.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 12, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _ALG_FACTORY_H_
#define _ALG_FACTORY_H_

#include <map>
#include <string>
#include <iostream>

#include "Algorithm/AlgId.h"

using std::map;
using std::pair;
using std::string;
using std::ostream;

namespace genie {

class Algorithm;
class AlgFactory;

ostream & operator << (ostream & stream, const genie::AlgFactory & algf);

class AlgFactory {

public:
  static AlgFactory * Instance();

  //! Instantiates, configures and returns a pointer to the specified algorithm.
  //! The algorithm is placed at the AlgFactory pool (is owned by the factory)
  //! from where it will be looked up at subsequent calls.
  const Algorithm * GetAlgorithm (const AlgId & algid);
  const Algorithm * GetAlgorithm (string name, string conf="Default");

  //! Like GetAlgorithm() but the algorithm is not placed at the AlgFactory pool
  //! and its ownership is transfered to the caller
  Algorithm * AdoptAlgorithm (const AlgId & algid) const;
  Algorithm * AdoptAlgorithm (string name, string conf="Default") const;

  //! Forces a reconfiguration of all algorithms kept at the factory pool.
  //! The algorithms look up their nominal configuration from the config pool.
  //! Use that to propagate modifications made directly at the config pool.
  void ForceReconfiguration(bool ignore_alg_opt_out=false);

  //! print algorithm factory
  void Print(ostream & stream) const;
  friend ostream & operator << (ostream & stream, const AlgFactory & algf);

private:
  AlgFactory();
  AlgFactory(const AlgFactory & alg_factory);
  virtual ~AlgFactory();

  //! method instantiating (based on TClass * TROOT::GetClass(name)) 
  //! & configuring algorithmic objects
  Algorithm * InstantiateAlgorithm(string name, string config) const;

  //! sinleton's self
  static AlgFactory * fInstance;

  //! 'algorithm key' (namespace::name/config) -> 'algorithmic object' map
  map<string, Algorithm *> fAlgPool;

  //! singleton cleaner
  struct Cleaner {
      void DummyMethodAndSilentCompiler() { }
      ~Cleaner() {
         if (AlgFactory::fInstance !=0) {
            delete AlgFactory::fInstance;
            AlgFactory::fInstance = 0;
         }
      }
  };
  friend struct Cleaner;
};

}      // genie namespace

#endif // _ALG_FACTORY_H_
//____________________________________________________________________________
/*!

\class    genie::AlgConfigPool

\brief    A singleton class holding all configuration registries built while
          parsing all loaded XML configuration files. 

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 06, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _ALG_CONFIG_POOL_H_
#define _ALG_CONFIG_POOL_H_

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "Algorithm/Algorithm.h"
#include "Registry/Registry.h"

using std::map;
using std::vector;
using std::string;
using std::ostream;

namespace genie {

class AlgConfigPool;
ostream & operator << (ostream & stream, const AlgConfigPool & cp);

class AlgConfigPool {

public:
  static AlgConfigPool * Instance();

  Registry * FindRegistry (string key)                        const;
  Registry * FindRegistry (string alg_name, string param_set) const;
  Registry * FindRegistry (const Algorithm * algorithm)       const;
  Registry * FindRegistry (const AlgId & algid)               const;

  Registry * GlobalParameterList(void) const;

  const vector<string> & ConfigKeyList (void) const;

  void Print(ostream & stream) const;
  friend ostream & operator << (ostream & stream, const AlgConfigPool & cp);

private:
  AlgConfigPool();
  AlgConfigPool(const AlgConfigPool & config_pool);
  virtual ~AlgConfigPool();

  // methods for loading all algorithm XML configuration files
  string BuildConfigKey      (string alg_name, string param_set) const;
  string BuildConfigKey      (const Algorithm * algorithm) const;
  bool   LoadAlgConfig       (void);
  bool   LoadMasterConfig    (void);
  bool   LoadGlobalParamLists(void);
  bool   LoadSingleAlgConfig (string alg_name, string file_name);
  bool   LoadRegistries      (string key_base, string file_name, string root);
  void   AddConfigParameter  (Registry * r, string pt, string pn, string pv);
  void   AddBasicParameter   (Registry * r, string pt, string pn, string pv);
  void   AddRootObjParameter (Registry * r, string pt, string pn, string pv);

  static AlgConfigPool * fInstance;

  map<string, Registry *> fRegistryPool;  ///< algorithm/param_set -> Registry
  map<string, string>     fConfigFiles;   ///< algorithm -> XML config file
  vector<string>          fConfigKeyList; ///< list of all available configuration keys
  string                  fMasterConfig;  ///< lists config files for all algorithms

  struct Cleaner {
      void DummyMethodAndSilentCompiler() { }
      ~Cleaner() {
         if (AlgConfigPool::fInstance !=0) {
            delete AlgConfigPool::fInstance;
            AlgConfigPool::fInstance = 0;
         }
      }
  };
  friend struct Cleaner;
};

}      // genie namespace

#endif // _ALG_CONFIG_POOL_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::AlgCmp", payloadCode, "@",
"genie::AlgConfigPool", payloadCode, "@",
"genie::AlgFactory", payloadCode, "@",
"genie::AlgId", payloadCode, "@",
"genie::AlgStatus", payloadCode, "@",
"genie::Algorithm", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGAlgorithm",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGAlgorithm_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGAlgorithm_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGAlgorithm() {
  TriggerDictionaryInitialization_libGAlgorithm_Impl();
}
