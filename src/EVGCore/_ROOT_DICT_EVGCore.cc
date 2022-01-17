// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_EVGCore

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
#include "InteractionGeneratorMap.h"
#include "EventRecordVisitorI.h"
#include "GVldContext.h"
#include "PhysInteractionSelector.h"
#include "EventRecord.h"
#include "ToyInteractionSelector.h"
#include "EVGThreadException.h"
#include "EventGeneratorListAssembler.h"
#include "RunningThreadInfo.h"
#include "InteractionListGeneratorI.h"
#include "XSecAlgorithmMap.h"
#include "EventGenerator.h"
#include "EventGeneratorList.h"
#include "InteractionListAssembler.h"
#include "InteractionList.h"
#include "InteractionSelectorI.h"
#include "EventGeneratorI.h"

// Header files passed via #pragma extra_include

namespace genie {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "Conventions/RefFrame.h", 22,
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
   static TClass *geniecLcLInteractionGeneratorMap_Dictionary();
   static void geniecLcLInteractionGeneratorMap_TClassManip(TClass*);
   static void *new_geniecLcLInteractionGeneratorMap(void *p = 0);
   static void *newArray_geniecLcLInteractionGeneratorMap(Long_t size, void *p);
   static void delete_geniecLcLInteractionGeneratorMap(void *p);
   static void deleteArray_geniecLcLInteractionGeneratorMap(void *p);
   static void destruct_geniecLcLInteractionGeneratorMap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InteractionGeneratorMap*)
   {
      ::genie::InteractionGeneratorMap *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InteractionGeneratorMap));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InteractionGeneratorMap", "", 50,
                  typeid(::genie::InteractionGeneratorMap), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInteractionGeneratorMap_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InteractionGeneratorMap) );
      instance.SetNew(&new_geniecLcLInteractionGeneratorMap);
      instance.SetNewArray(&newArray_geniecLcLInteractionGeneratorMap);
      instance.SetDelete(&delete_geniecLcLInteractionGeneratorMap);
      instance.SetDeleteArray(&deleteArray_geniecLcLInteractionGeneratorMap);
      instance.SetDestructor(&destruct_geniecLcLInteractionGeneratorMap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InteractionGeneratorMap*)
   {
      return GenerateInitInstanceLocal((::genie::InteractionGeneratorMap*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InteractionGeneratorMap*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInteractionGeneratorMap_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InteractionGeneratorMap*)0x0)->GetClass();
      geniecLcLInteractionGeneratorMap_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInteractionGeneratorMap_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLEventRecordVisitorI_Dictionary();
   static void geniecLcLEventRecordVisitorI_TClassManip(TClass*);
   static void delete_geniecLcLEventRecordVisitorI(void *p);
   static void deleteArray_geniecLcLEventRecordVisitorI(void *p);
   static void destruct_geniecLcLEventRecordVisitorI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventRecordVisitorI*)
   {
      ::genie::EventRecordVisitorI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::EventRecordVisitorI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventRecordVisitorI", "", 114,
                  typeid(::genie::EventRecordVisitorI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLEventRecordVisitorI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::EventRecordVisitorI) );
      instance.SetDelete(&delete_geniecLcLEventRecordVisitorI);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventRecordVisitorI);
      instance.SetDestructor(&destruct_geniecLcLEventRecordVisitorI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventRecordVisitorI*)
   {
      return GenerateInitInstanceLocal((::genie::EventRecordVisitorI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventRecordVisitorI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLEventRecordVisitorI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::EventRecordVisitorI*)0x0)->GetClass();
      geniecLcLEventRecordVisitorI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLEventRecordVisitorI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLGVldContext_Dictionary();
   static void geniecLcLGVldContext_TClassManip(TClass*);
   static void *new_geniecLcLGVldContext(void *p = 0);
   static void *newArray_geniecLcLGVldContext(Long_t size, void *p);
   static void delete_geniecLcLGVldContext(void *p);
   static void deleteArray_geniecLcLGVldContext(void *p);
   static void destruct_geniecLcLGVldContext(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::GVldContext*)
   {
      ::genie::GVldContext *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::GVldContext));
      static ::ROOT::TGenericClassInfo 
         instance("genie::GVldContext", "", 172,
                  typeid(::genie::GVldContext), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLGVldContext_Dictionary, isa_proxy, 0,
                  sizeof(::genie::GVldContext) );
      instance.SetNew(&new_geniecLcLGVldContext);
      instance.SetNewArray(&newArray_geniecLcLGVldContext);
      instance.SetDelete(&delete_geniecLcLGVldContext);
      instance.SetDeleteArray(&deleteArray_geniecLcLGVldContext);
      instance.SetDestructor(&destruct_geniecLcLGVldContext);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::GVldContext*)
   {
      return GenerateInitInstanceLocal((::genie::GVldContext*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::GVldContext*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLGVldContext_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::GVldContext*)0x0)->GetClass();
      geniecLcLGVldContext_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLGVldContext_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLInteractionSelectorI_Dictionary();
   static void geniecLcLInteractionSelectorI_TClassManip(TClass*);
   static void delete_geniecLcLInteractionSelectorI(void *p);
   static void deleteArray_geniecLcLInteractionSelectorI(void *p);
   static void destruct_geniecLcLInteractionSelectorI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InteractionSelectorI*)
   {
      ::genie::InteractionSelectorI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InteractionSelectorI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InteractionSelectorI", "InteractionSelectorI.h", 32,
                  typeid(::genie::InteractionSelectorI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInteractionSelectorI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InteractionSelectorI) );
      instance.SetDelete(&delete_geniecLcLInteractionSelectorI);
      instance.SetDeleteArray(&deleteArray_geniecLcLInteractionSelectorI);
      instance.SetDestructor(&destruct_geniecLcLInteractionSelectorI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InteractionSelectorI*)
   {
      return GenerateInitInstanceLocal((::genie::InteractionSelectorI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InteractionSelectorI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInteractionSelectorI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InteractionSelectorI*)0x0)->GetClass();
      geniecLcLInteractionSelectorI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInteractionSelectorI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPhysInteractionSelector_Dictionary();
   static void geniecLcLPhysInteractionSelector_TClassManip(TClass*);
   static void *new_geniecLcLPhysInteractionSelector(void *p = 0);
   static void *newArray_geniecLcLPhysInteractionSelector(Long_t size, void *p);
   static void delete_geniecLcLPhysInteractionSelector(void *p);
   static void deleteArray_geniecLcLPhysInteractionSelector(void *p);
   static void destruct_geniecLcLPhysInteractionSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PhysInteractionSelector*)
   {
      ::genie::PhysInteractionSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PhysInteractionSelector));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PhysInteractionSelector", "", 228,
                  typeid(::genie::PhysInteractionSelector), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPhysInteractionSelector_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PhysInteractionSelector) );
      instance.SetNew(&new_geniecLcLPhysInteractionSelector);
      instance.SetNewArray(&newArray_geniecLcLPhysInteractionSelector);
      instance.SetDelete(&delete_geniecLcLPhysInteractionSelector);
      instance.SetDeleteArray(&deleteArray_geniecLcLPhysInteractionSelector);
      instance.SetDestructor(&destruct_geniecLcLPhysInteractionSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PhysInteractionSelector*)
   {
      return GenerateInitInstanceLocal((::genie::PhysInteractionSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PhysInteractionSelector*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPhysInteractionSelector_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PhysInteractionSelector*)0x0)->GetClass();
      geniecLcLPhysInteractionSelector_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPhysInteractionSelector_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLEventRecord(void *p = 0);
   static void *newArray_geniecLcLEventRecord(Long_t size, void *p);
   static void delete_geniecLcLEventRecord(void *p);
   static void deleteArray_geniecLcLEventRecord(void *p);
   static void destruct_geniecLcLEventRecord(void *p);
   static void streamer_geniecLcLEventRecord(TBuffer &buf, void *obj);
   static Long64_t merge_geniecLcLEventRecord(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventRecord*)
   {
      ::genie::EventRecord *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::EventRecord >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventRecord", ::genie::EventRecord::Class_Version(), "", 291,
                  typeid(::genie::EventRecord), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::EventRecord::Dictionary, isa_proxy, 16,
                  sizeof(::genie::EventRecord) );
      instance.SetNew(&new_geniecLcLEventRecord);
      instance.SetNewArray(&newArray_geniecLcLEventRecord);
      instance.SetDelete(&delete_geniecLcLEventRecord);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventRecord);
      instance.SetDestructor(&destruct_geniecLcLEventRecord);
      instance.SetStreamerFunc(&streamer_geniecLcLEventRecord);
      instance.SetMerge(&merge_geniecLcLEventRecord);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventRecord*)
   {
      return GenerateInitInstanceLocal((::genie::EventRecord*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventRecord*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLToyInteractionSelector_Dictionary();
   static void geniecLcLToyInteractionSelector_TClassManip(TClass*);
   static void *new_geniecLcLToyInteractionSelector(void *p = 0);
   static void *newArray_geniecLcLToyInteractionSelector(Long_t size, void *p);
   static void delete_geniecLcLToyInteractionSelector(void *p);
   static void deleteArray_geniecLcLToyInteractionSelector(void *p);
   static void destruct_geniecLcLToyInteractionSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::ToyInteractionSelector*)
   {
      ::genie::ToyInteractionSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::ToyInteractionSelector));
      static ::ROOT::TGenericClassInfo 
         instance("genie::ToyInteractionSelector", "", 349,
                  typeid(::genie::ToyInteractionSelector), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLToyInteractionSelector_Dictionary, isa_proxy, 0,
                  sizeof(::genie::ToyInteractionSelector) );
      instance.SetNew(&new_geniecLcLToyInteractionSelector);
      instance.SetNewArray(&newArray_geniecLcLToyInteractionSelector);
      instance.SetDelete(&delete_geniecLcLToyInteractionSelector);
      instance.SetDeleteArray(&deleteArray_geniecLcLToyInteractionSelector);
      instance.SetDestructor(&destruct_geniecLcLToyInteractionSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::ToyInteractionSelector*)
   {
      return GenerateInitInstanceLocal((::genie::ToyInteractionSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::ToyInteractionSelector*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLToyInteractionSelector_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::ToyInteractionSelector*)0x0)->GetClass();
      geniecLcLToyInteractionSelector_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLToyInteractionSelector_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLEventGeneratorListAssembler_Dictionary();
   static void geniecLcLEventGeneratorListAssembler_TClassManip(TClass*);
   static void *new_geniecLcLEventGeneratorListAssembler(void *p = 0);
   static void *newArray_geniecLcLEventGeneratorListAssembler(Long_t size, void *p);
   static void delete_geniecLcLEventGeneratorListAssembler(void *p);
   static void deleteArray_geniecLcLEventGeneratorListAssembler(void *p);
   static void destruct_geniecLcLEventGeneratorListAssembler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventGeneratorListAssembler*)
   {
      ::genie::EventGeneratorListAssembler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::EventGeneratorListAssembler));
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventGeneratorListAssembler", "", 467,
                  typeid(::genie::EventGeneratorListAssembler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLEventGeneratorListAssembler_Dictionary, isa_proxy, 0,
                  sizeof(::genie::EventGeneratorListAssembler) );
      instance.SetNew(&new_geniecLcLEventGeneratorListAssembler);
      instance.SetNewArray(&newArray_geniecLcLEventGeneratorListAssembler);
      instance.SetDelete(&delete_geniecLcLEventGeneratorListAssembler);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventGeneratorListAssembler);
      instance.SetDestructor(&destruct_geniecLcLEventGeneratorListAssembler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventGeneratorListAssembler*)
   {
      return GenerateInitInstanceLocal((::genie::EventGeneratorListAssembler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventGeneratorListAssembler*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLEventGeneratorListAssembler_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::EventGeneratorListAssembler*)0x0)->GetClass();
      geniecLcLEventGeneratorListAssembler_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLEventGeneratorListAssembler_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLRunningThreadInfo_Dictionary();
   static void geniecLcLRunningThreadInfo_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::RunningThreadInfo*)
   {
      ::genie::RunningThreadInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::RunningThreadInfo));
      static ::ROOT::TGenericClassInfo 
         instance("genie::RunningThreadInfo", "", 515,
                  typeid(::genie::RunningThreadInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLRunningThreadInfo_Dictionary, isa_proxy, 0,
                  sizeof(::genie::RunningThreadInfo) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::RunningThreadInfo*)
   {
      return GenerateInitInstanceLocal((::genie::RunningThreadInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::RunningThreadInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLRunningThreadInfo_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::RunningThreadInfo*)0x0)->GetClass();
      geniecLcLRunningThreadInfo_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLRunningThreadInfo_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLInteractionListGeneratorI_Dictionary();
   static void geniecLcLInteractionListGeneratorI_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InteractionListGeneratorI*)
   {
      ::genie::InteractionListGeneratorI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InteractionListGeneratorI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InteractionListGeneratorI", "", 588,
                  typeid(::genie::InteractionListGeneratorI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInteractionListGeneratorI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InteractionListGeneratorI) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InteractionListGeneratorI*)
   {
      return GenerateInitInstanceLocal((::genie::InteractionListGeneratorI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InteractionListGeneratorI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInteractionListGeneratorI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InteractionListGeneratorI*)0x0)->GetClass();
      geniecLcLInteractionListGeneratorI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInteractionListGeneratorI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLXSecAlgorithmMap_Dictionary();
   static void geniecLcLXSecAlgorithmMap_TClassManip(TClass*);
   static void *new_geniecLcLXSecAlgorithmMap(void *p = 0);
   static void *newArray_geniecLcLXSecAlgorithmMap(Long_t size, void *p);
   static void delete_geniecLcLXSecAlgorithmMap(void *p);
   static void deleteArray_geniecLcLXSecAlgorithmMap(void *p);
   static void destruct_geniecLcLXSecAlgorithmMap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::XSecAlgorithmMap*)
   {
      ::genie::XSecAlgorithmMap *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::XSecAlgorithmMap));
      static ::ROOT::TGenericClassInfo 
         instance("genie::XSecAlgorithmMap", "", 651,
                  typeid(::genie::XSecAlgorithmMap), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLXSecAlgorithmMap_Dictionary, isa_proxy, 0,
                  sizeof(::genie::XSecAlgorithmMap) );
      instance.SetNew(&new_geniecLcLXSecAlgorithmMap);
      instance.SetNewArray(&newArray_geniecLcLXSecAlgorithmMap);
      instance.SetDelete(&delete_geniecLcLXSecAlgorithmMap);
      instance.SetDeleteArray(&deleteArray_geniecLcLXSecAlgorithmMap);
      instance.SetDestructor(&destruct_geniecLcLXSecAlgorithmMap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::XSecAlgorithmMap*)
   {
      return GenerateInitInstanceLocal((::genie::XSecAlgorithmMap*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::XSecAlgorithmMap*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLXSecAlgorithmMap_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::XSecAlgorithmMap*)0x0)->GetClass();
      geniecLcLXSecAlgorithmMap_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLXSecAlgorithmMap_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLEventGeneratorI_Dictionary();
   static void geniecLcLEventGeneratorI_TClassManip(TClass*);
   static void delete_geniecLcLEventGeneratorI(void *p);
   static void deleteArray_geniecLcLEventGeneratorI(void *p);
   static void destruct_geniecLcLEventGeneratorI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventGeneratorI*)
   {
      ::genie::EventGeneratorI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::EventGeneratorI));
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventGeneratorI", "EventGeneratorI.h", 39,
                  typeid(::genie::EventGeneratorI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLEventGeneratorI_Dictionary, isa_proxy, 0,
                  sizeof(::genie::EventGeneratorI) );
      instance.SetDelete(&delete_geniecLcLEventGeneratorI);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventGeneratorI);
      instance.SetDestructor(&destruct_geniecLcLEventGeneratorI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventGeneratorI*)
   {
      return GenerateInitInstanceLocal((::genie::EventGeneratorI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventGeneratorI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLEventGeneratorI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::EventGeneratorI*)0x0)->GetClass();
      geniecLcLEventGeneratorI_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLEventGeneratorI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLEventGenerator_Dictionary();
   static void geniecLcLEventGenerator_TClassManip(TClass*);
   static void *new_geniecLcLEventGenerator(void *p = 0);
   static void *newArray_geniecLcLEventGenerator(Long_t size, void *p);
   static void delete_geniecLcLEventGenerator(void *p);
   static void deleteArray_geniecLcLEventGenerator(void *p);
   static void destruct_geniecLcLEventGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventGenerator*)
   {
      ::genie::EventGenerator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::EventGenerator));
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventGenerator", "", 725,
                  typeid(::genie::EventGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLEventGenerator_Dictionary, isa_proxy, 0,
                  sizeof(::genie::EventGenerator) );
      instance.SetNew(&new_geniecLcLEventGenerator);
      instance.SetNewArray(&newArray_geniecLcLEventGenerator);
      instance.SetDelete(&delete_geniecLcLEventGenerator);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventGenerator);
      instance.SetDestructor(&destruct_geniecLcLEventGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventGenerator*)
   {
      return GenerateInitInstanceLocal((::genie::EventGenerator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventGenerator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLEventGenerator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::EventGenerator*)0x0)->GetClass();
      geniecLcLEventGenerator_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLEventGenerator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLEventGeneratorList_Dictionary();
   static void geniecLcLEventGeneratorList_TClassManip(TClass*);
   static void *new_geniecLcLEventGeneratorList(void *p = 0);
   static void *newArray_geniecLcLEventGeneratorList(Long_t size, void *p);
   static void delete_geniecLcLEventGeneratorList(void *p);
   static void deleteArray_geniecLcLEventGeneratorList(void *p);
   static void destruct_geniecLcLEventGeneratorList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::EventGeneratorList*)
   {
      ::genie::EventGeneratorList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::EventGeneratorList));
      static ::ROOT::TGenericClassInfo 
         instance("genie::EventGeneratorList", "", 799,
                  typeid(::genie::EventGeneratorList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLEventGeneratorList_Dictionary, isa_proxy, 0,
                  sizeof(::genie::EventGeneratorList) );
      instance.SetNew(&new_geniecLcLEventGeneratorList);
      instance.SetNewArray(&newArray_geniecLcLEventGeneratorList);
      instance.SetDelete(&delete_geniecLcLEventGeneratorList);
      instance.SetDeleteArray(&deleteArray_geniecLcLEventGeneratorList);
      instance.SetDestructor(&destruct_geniecLcLEventGeneratorList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::EventGeneratorList*)
   {
      return GenerateInitInstanceLocal((::genie::EventGeneratorList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::EventGeneratorList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLEventGeneratorList_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::EventGeneratorList*)0x0)->GetClass();
      geniecLcLEventGeneratorList_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLEventGeneratorList_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLInteractionListAssembler_Dictionary();
   static void geniecLcLInteractionListAssembler_TClassManip(TClass*);
   static void *new_geniecLcLInteractionListAssembler(void *p = 0);
   static void *newArray_geniecLcLInteractionListAssembler(Long_t size, void *p);
   static void delete_geniecLcLInteractionListAssembler(void *p);
   static void deleteArray_geniecLcLInteractionListAssembler(void *p);
   static void destruct_geniecLcLInteractionListAssembler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InteractionListAssembler*)
   {
      ::genie::InteractionListAssembler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InteractionListAssembler));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InteractionListAssembler", "", 846,
                  typeid(::genie::InteractionListAssembler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInteractionListAssembler_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InteractionListAssembler) );
      instance.SetNew(&new_geniecLcLInteractionListAssembler);
      instance.SetNewArray(&newArray_geniecLcLInteractionListAssembler);
      instance.SetDelete(&delete_geniecLcLInteractionListAssembler);
      instance.SetDeleteArray(&deleteArray_geniecLcLInteractionListAssembler);
      instance.SetDestructor(&destruct_geniecLcLInteractionListAssembler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InteractionListAssembler*)
   {
      return GenerateInitInstanceLocal((::genie::InteractionListAssembler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InteractionListAssembler*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInteractionListAssembler_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InteractionListAssembler*)0x0)->GetClass();
      geniecLcLInteractionListAssembler_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInteractionListAssembler_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLInteractionList_Dictionary();
   static void geniecLcLInteractionList_TClassManip(TClass*);
   static void *new_geniecLcLInteractionList(void *p = 0);
   static void *newArray_geniecLcLInteractionList(Long_t size, void *p);
   static void delete_geniecLcLInteractionList(void *p);
   static void deleteArray_geniecLcLInteractionList(void *p);
   static void destruct_geniecLcLInteractionList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InteractionList*)
   {
      ::genie::InteractionList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InteractionList));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InteractionList", "", 900,
                  typeid(::genie::InteractionList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInteractionList_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InteractionList) );
      instance.SetNew(&new_geniecLcLInteractionList);
      instance.SetNewArray(&newArray_geniecLcLInteractionList);
      instance.SetDelete(&delete_geniecLcLInteractionList);
      instance.SetDeleteArray(&deleteArray_geniecLcLInteractionList);
      instance.SetDestructor(&destruct_geniecLcLInteractionList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InteractionList*)
   {
      return GenerateInitInstanceLocal((::genie::InteractionList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InteractionList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInteractionList_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InteractionList*)0x0)->GetClass();
      geniecLcLInteractionList_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInteractionList_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr EventRecord::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventRecord::Class_Name()
{
   return "genie::EventRecord";
}

//______________________________________________________________________________
const char *EventRecord::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::EventRecord*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventRecord::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::EventRecord*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventRecord::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::EventRecord*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventRecord::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::EventRecord*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInteractionGeneratorMap(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionGeneratorMap : new ::genie::InteractionGeneratorMap;
   }
   static void *newArray_geniecLcLInteractionGeneratorMap(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionGeneratorMap[nElements] : new ::genie::InteractionGeneratorMap[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInteractionGeneratorMap(void *p) {
      delete ((::genie::InteractionGeneratorMap*)p);
   }
   static void deleteArray_geniecLcLInteractionGeneratorMap(void *p) {
      delete [] ((::genie::InteractionGeneratorMap*)p);
   }
   static void destruct_geniecLcLInteractionGeneratorMap(void *p) {
      typedef ::genie::InteractionGeneratorMap current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::InteractionGeneratorMap

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLEventRecordVisitorI(void *p) {
      delete ((::genie::EventRecordVisitorI*)p);
   }
   static void deleteArray_geniecLcLEventRecordVisitorI(void *p) {
      delete [] ((::genie::EventRecordVisitorI*)p);
   }
   static void destruct_geniecLcLEventRecordVisitorI(void *p) {
      typedef ::genie::EventRecordVisitorI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::EventRecordVisitorI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLGVldContext(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GVldContext : new ::genie::GVldContext;
   }
   static void *newArray_geniecLcLGVldContext(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::GVldContext[nElements] : new ::genie::GVldContext[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLGVldContext(void *p) {
      delete ((::genie::GVldContext*)p);
   }
   static void deleteArray_geniecLcLGVldContext(void *p) {
      delete [] ((::genie::GVldContext*)p);
   }
   static void destruct_geniecLcLGVldContext(void *p) {
      typedef ::genie::GVldContext current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::GVldContext

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLInteractionSelectorI(void *p) {
      delete ((::genie::InteractionSelectorI*)p);
   }
   static void deleteArray_geniecLcLInteractionSelectorI(void *p) {
      delete [] ((::genie::InteractionSelectorI*)p);
   }
   static void destruct_geniecLcLInteractionSelectorI(void *p) {
      typedef ::genie::InteractionSelectorI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::InteractionSelectorI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLPhysInteractionSelector(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PhysInteractionSelector : new ::genie::PhysInteractionSelector;
   }
   static void *newArray_geniecLcLPhysInteractionSelector(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PhysInteractionSelector[nElements] : new ::genie::PhysInteractionSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLPhysInteractionSelector(void *p) {
      delete ((::genie::PhysInteractionSelector*)p);
   }
   static void deleteArray_geniecLcLPhysInteractionSelector(void *p) {
      delete [] ((::genie::PhysInteractionSelector*)p);
   }
   static void destruct_geniecLcLPhysInteractionSelector(void *p) {
      typedef ::genie::PhysInteractionSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::PhysInteractionSelector

namespace genie {
//______________________________________________________________________________
void EventRecord::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::EventRecord.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::EventRecord thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      //This works around a msvc bug and should be harmless on other platforms
      typedef genie::GHepRecord baseClass0;
      baseClass0::Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      //This works around a msvc bug and should be harmless on other platforms
      typedef genie::GHepRecord baseClass0;
      baseClass0::Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLEventRecord(void *p) {
      return  p ? new(p) ::genie::EventRecord : new ::genie::EventRecord;
   }
   static void *newArray_geniecLcLEventRecord(Long_t nElements, void *p) {
      return p ? new(p) ::genie::EventRecord[nElements] : new ::genie::EventRecord[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLEventRecord(void *p) {
      delete ((::genie::EventRecord*)p);
   }
   static void deleteArray_geniecLcLEventRecord(void *p) {
      delete [] ((::genie::EventRecord*)p);
   }
   static void destruct_geniecLcLEventRecord(void *p) {
      typedef ::genie::EventRecord current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLEventRecord(TBuffer &buf, void *obj) {
      ((::genie::EventRecord*)obj)->::genie::EventRecord::Streamer(buf);
   }
   // Wrapper around the merge function.
   static Long64_t  merge_geniecLcLEventRecord(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::genie::EventRecord*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::genie::EventRecord

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLToyInteractionSelector(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::ToyInteractionSelector : new ::genie::ToyInteractionSelector;
   }
   static void *newArray_geniecLcLToyInteractionSelector(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::ToyInteractionSelector[nElements] : new ::genie::ToyInteractionSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLToyInteractionSelector(void *p) {
      delete ((::genie::ToyInteractionSelector*)p);
   }
   static void deleteArray_geniecLcLToyInteractionSelector(void *p) {
      delete [] ((::genie::ToyInteractionSelector*)p);
   }
   static void destruct_geniecLcLToyInteractionSelector(void *p) {
      typedef ::genie::ToyInteractionSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::ToyInteractionSelector

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLEventGeneratorListAssembler(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGeneratorListAssembler : new ::genie::EventGeneratorListAssembler;
   }
   static void *newArray_geniecLcLEventGeneratorListAssembler(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGeneratorListAssembler[nElements] : new ::genie::EventGeneratorListAssembler[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLEventGeneratorListAssembler(void *p) {
      delete ((::genie::EventGeneratorListAssembler*)p);
   }
   static void deleteArray_geniecLcLEventGeneratorListAssembler(void *p) {
      delete [] ((::genie::EventGeneratorListAssembler*)p);
   }
   static void destruct_geniecLcLEventGeneratorListAssembler(void *p) {
      typedef ::genie::EventGeneratorListAssembler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::EventGeneratorListAssembler

namespace ROOT {
} // end of namespace ROOT for class ::genie::RunningThreadInfo

namespace ROOT {
} // end of namespace ROOT for class ::genie::InteractionListGeneratorI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLXSecAlgorithmMap(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::XSecAlgorithmMap : new ::genie::XSecAlgorithmMap;
   }
   static void *newArray_geniecLcLXSecAlgorithmMap(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::XSecAlgorithmMap[nElements] : new ::genie::XSecAlgorithmMap[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLXSecAlgorithmMap(void *p) {
      delete ((::genie::XSecAlgorithmMap*)p);
   }
   static void deleteArray_geniecLcLXSecAlgorithmMap(void *p) {
      delete [] ((::genie::XSecAlgorithmMap*)p);
   }
   static void destruct_geniecLcLXSecAlgorithmMap(void *p) {
      typedef ::genie::XSecAlgorithmMap current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::XSecAlgorithmMap

namespace ROOT {
   // Wrapper around operator delete
   static void delete_geniecLcLEventGeneratorI(void *p) {
      delete ((::genie::EventGeneratorI*)p);
   }
   static void deleteArray_geniecLcLEventGeneratorI(void *p) {
      delete [] ((::genie::EventGeneratorI*)p);
   }
   static void destruct_geniecLcLEventGeneratorI(void *p) {
      typedef ::genie::EventGeneratorI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::EventGeneratorI

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLEventGenerator(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGenerator : new ::genie::EventGenerator;
   }
   static void *newArray_geniecLcLEventGenerator(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGenerator[nElements] : new ::genie::EventGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLEventGenerator(void *p) {
      delete ((::genie::EventGenerator*)p);
   }
   static void deleteArray_geniecLcLEventGenerator(void *p) {
      delete [] ((::genie::EventGenerator*)p);
   }
   static void destruct_geniecLcLEventGenerator(void *p) {
      typedef ::genie::EventGenerator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::EventGenerator

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLEventGeneratorList(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGeneratorList : new ::genie::EventGeneratorList;
   }
   static void *newArray_geniecLcLEventGeneratorList(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::EventGeneratorList[nElements] : new ::genie::EventGeneratorList[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLEventGeneratorList(void *p) {
      delete ((::genie::EventGeneratorList*)p);
   }
   static void deleteArray_geniecLcLEventGeneratorList(void *p) {
      delete [] ((::genie::EventGeneratorList*)p);
   }
   static void destruct_geniecLcLEventGeneratorList(void *p) {
      typedef ::genie::EventGeneratorList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::EventGeneratorList

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInteractionListAssembler(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionListAssembler : new ::genie::InteractionListAssembler;
   }
   static void *newArray_geniecLcLInteractionListAssembler(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionListAssembler[nElements] : new ::genie::InteractionListAssembler[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInteractionListAssembler(void *p) {
      delete ((::genie::InteractionListAssembler*)p);
   }
   static void deleteArray_geniecLcLInteractionListAssembler(void *p) {
      delete [] ((::genie::InteractionListAssembler*)p);
   }
   static void destruct_geniecLcLInteractionListAssembler(void *p) {
      typedef ::genie::InteractionListAssembler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::InteractionListAssembler

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInteractionList(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionList : new ::genie::InteractionList;
   }
   static void *newArray_geniecLcLInteractionList(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InteractionList[nElements] : new ::genie::InteractionList[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInteractionList(void *p) {
      delete ((::genie::InteractionList*)p);
   }
   static void deleteArray_geniecLcLInteractionList(void *p) {
      delete [] ((::genie::InteractionList*)p);
   }
   static void destruct_geniecLcLInteractionList(void *p) {
      typedef ::genie::InteractionList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::InteractionList

namespace {
  void TriggerDictionaryInitialization_libGEVGCore_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"EVGCore",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/EVGCore",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/EVGCore",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/EVGCore/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGEVGCore dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class InteractionGeneratorMap;}
namespace genie{class EventRecordVisitorI;}
namespace genie{class GVldContext;}
namespace genie{class __attribute__((annotate("$clingAutoload$EVGCore/InteractionSelectorI.h")))  InteractionSelectorI;}
namespace genie{class PhysInteractionSelector;}
namespace genie{class EventRecord;}
namespace genie{class ToyInteractionSelector;}
namespace genie{class EventGeneratorListAssembler;}
namespace genie{class RunningThreadInfo;}
namespace genie{class InteractionListGeneratorI;}
namespace genie{class XSecAlgorithmMap;}
namespace genie{class __attribute__((annotate("$clingAutoload$EVGCore/EventGeneratorI.h")))  EventGeneratorI;}
namespace genie{class EventGenerator;}
namespace genie{class EventGeneratorList;}
namespace genie{class InteractionListAssembler;}
namespace genie{class InteractionList;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGEVGCore dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class   genie::InteractionGeneratorMap

\brief   An Interaction -> EventGeneratorI associative container. 
         The container is being built for the loaded EventGeneratorList and for 
         the input InitialState object and is being used to locate the generator
         that can generate aany given interaction.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created January 23, 2006

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_GENERATOR_MAP_H_
#define _INTERACTION_GENERATOR_MAP_H_

#include <map>
#include <string>
#include <ostream>

#include "Interaction/Interaction.h"

using std::map;
using std::string;
using std::ostream;

namespace genie {

class InteractionGeneratorMap;
class EventGeneratorI;
class InteractionList;
class InitialState;
class EventGeneratorList;

ostream & operator << (ostream & stream, const InteractionGeneratorMap & xsmap);

class InteractionGeneratorMap : public map<string, const EventGeneratorI *> {

public :
  InteractionGeneratorMap();
  InteractionGeneratorMap(const InteractionGeneratorMap & igmap);
  ~InteractionGeneratorMap();

  void UseGeneratorList (const EventGeneratorList * list);
  void BuildMap         (const InitialState & init_state);

  const EventGeneratorI * FindGenerator      (const Interaction * in) const;
  const InteractionList & GetInteractionList (void) const;

  void Reset (void);
  void Copy  (const InteractionGeneratorMap & xsmap);
  void Print (ostream & stream) const;

  InteractionGeneratorMap & operator =  (const InteractionGeneratorMap & xsmap);
  friend ostream & operator << (ostream & stream, const InteractionGeneratorMap & xsmap);

private:

  void Init    (void);
  void CleanUp (void);

  const EventGeneratorList * fEventGeneratorList;

  InitialState *    fInitState;
  InteractionList * fInteractionList;
};

}      // genie namespace

#endif // _INTERACTION_GENERATOR_MAP_H_
//____________________________________________________________________________
/*!

\class   genie::EventRecordVisitorI

\brief   Defines the EventRecordVisitorI interface.
         Concrete implementations of this interface use the 'Visitor' Design
         Pattern to perform an operation on an EventRecord.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created October 04, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVENT_RECORD_VISITOR_I_H_
#define _EVENT_RECORD_VISITOR_I_H_

#include "Algorithm/Algorithm.h"

namespace genie {

class GHepRecord;

class EventRecordVisitorI : public Algorithm {

public :

  virtual ~EventRecordVisitorI();

  //-- define the EventRecordVisitorI interface

  virtual void ProcessEventRecord(GHepRecord * event_rec) const = 0;

protected :

  EventRecordVisitorI();
  EventRecordVisitorI(string name);
  EventRecordVisitorI(string name, string config);
};

}      // genie namespace

#endif // _EVENT_RECORD_VISITOR_I_H_
//____________________________________________________________________________
/*!

\class   genie::GVldContext

\brief   Validity Context for an Event Generator

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created November 20, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _GENERATOR_VALIDITY_CONTEXT_H_
#define _GENERATOR_VALIDITY_CONTEXT_H_

#include <string>
#include <iostream>

#include "Interaction/ScatteringType.h"
#include "Interaction/InteractionType.h"

using std::string;
using std::ostream;

namespace genie {

class GVldContext;
class Interaction;

ostream & operator<< (ostream & stream, const GVldContext & vldc);

class GVldContext {

public :
  GVldContext();
 ~GVldContext();

  void   Decode  (string encoded_values);

  double Emin    (void) const { return fEmin; }
  double Emax    (void) const { return fEmax; }
  
  void   Print   (ostream & stream) const;
 
  friend ostream & operator<< (ostream & stream, const GVldContext & vldc);

private:

  void Init(void);

  void DecodeENERGY (string encoded_values);
    
  double fEmin;  // min probe energy in validity range
  double fEmax;  // max probe energy in validity range
};

}      // genie namespace

#endif // _GENERATOR_VALIDITY_CONTEXT_H_
//____________________________________________________________________________
/*!

\class   genie::PhysInteractionSelector

\brief   Selects interactions to be generated

         Is a concrete implementation of the InteractionSelectorI interface.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created January 25, 2005

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PHYS_INTERACTION_SELECTOR_H_
#define _PHYS_INTERACTION_SELECTOR_H_

#include "EVGCore/InteractionSelectorI.h"

namespace genie {

class PhysInteractionSelector : public InteractionSelectorI {

public :
  PhysInteractionSelector();
  PhysInteractionSelector(string config);
  ~PhysInteractionSelector();

  //! implement the InteractionSelectorI interface
  EventRecord * SelectInteraction
     (const InteractionGeneratorMap * igmp, const TLorentzVector & p4) const;

  //! override the Algorithm::Configure methods to load configuration
  //! data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

private:
  void LoadConfigData (void);

  bool fUseSplines;
};

}      // genie namespace

#endif // _PHYS_INTERACTION_SELECTOR_H_
//____________________________________________________________________________
/*!

\class   genie::EventRecord

\brief   Generated Event Record. It is a GHepRecord object that can accept /
         be visited by EventRecordVisitorI objects (event generation modules).
         All the other important container manipulation methods are defined
         at the base GHepRecord record.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created October 1, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVENT_RECORD_H_
#define _EVENT_RECORD_H_

#include <ostream>

#include "GHEP/GHepRecord.h"

using std::ostream;

namespace genie {

class EventRecord;
class EventRecordVisitorI;

ostream & operator<< (ostream& stream, const EventRecord & event);

class EventRecord : public GHepRecord {

public :
  using GHepRecord::Copy; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
  using GHepRecord::Print;

  EventRecord();
  EventRecord(int size);
  EventRecord(const EventRecord & record);
  ~EventRecord();

  void AcceptVisitor (EventRecordVisitorI * visitor);
  void Copy          (const EventRecord & record);
  void Print         (ostream & stream) const;

  friend ostream & operator<< (ostream& stream, const EventRecord & event);

private:

ClassDef(EventRecord, 1)

};

}      // genie namespace

#endif // _EVENT_RECORD_H_
//____________________________________________________________________________
/*!

\class   genie::ToyInteractionSelector

\brief   Generates random interactions.

         This is a 'toy' InteractionSelectorI to be used in event generation
         testing / debugging. Not to be used in event generation for physics
         purposes.

         Is a concrete implementation of the InteractionSelectorI interface.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created December 05, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _TOY_INTERACTION_SELECTOR_H_
#define _TOY_INTERACTION_SELECTOR_H_

#include "EVGCore/InteractionSelectorI.h"

namespace genie {

class ToyInteractionSelector : public InteractionSelectorI {

public :
  ToyInteractionSelector();
  ToyInteractionSelector(string config);
  ~ToyInteractionSelector();

  //! implement the InteractionSelectorI interface
  EventRecord * SelectInteraction
    (const InteractionGeneratorMap * igmp, const TLorentzVector & p4) const;
};

}      // genie namespace

#endif // _TOY_INTERACTION_SELECTOR_H_
//____________________________________________________________________________
/*!

\class   genie::exceptions::EVGThreadException

\brief   An exception thrown by EventRecordVisitorI when the normal processing
         sequence has to be disrupted (fast-fwd at the end or step-back)

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created September 27, 2005

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVG_THREAD_EXCEPTION_H_
#define _EVG_THREAD_EXCEPTION_H_

#include <string>
#include <ostream>

#include <TMath.h>

using std::string;
using std::ostream;

namespace genie {
namespace exceptions {

class Interaction;

class EVGThreadException {

public :

  EVGThreadException();
  EVGThreadException(const EVGThreadException & exception);
  ~EVGThreadException();

  void   SetReason  (string reason) { fReason     = reason;          }
  void   SwitchOnFastForward (void) { fFastFwd    = true;            }
  void   SwitchOnStepBack    (void) { fStepBack   = true;            }
  void   SetReturnStep (int s)      { fReturnStep = TMath::Max(0,s); }

  string ShowReason  (void) const { return fReason;     }
  bool   FastForward (void) const { return fFastFwd;    }
  bool   StepBack    (void) const { return fStepBack;   }
  int    ReturnStep  (void) const { return fReturnStep; }

  void Init  (void);
  void Copy  (const EVGThreadException & exception);
  void Print (ostream & stream) const;

  friend ostream & operator << (
             ostream & stream, const EVGThreadException & exception);

private:

  bool   fFastFwd;
  bool   fStepBack;
  int    fReturnStep;
  string fReason;
};

}      // exceptions namespace
}      // genie namespace

#endif // _EVG_THREAD_EXCEPTION_H_
//____________________________________________________________________________
/*!

\class   genie::EventGeneratorListAssembler

\brief   Assembles a list of all the EventGeneratorI subclasses that can be
         employed during a neutrino event generation job.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created January 25, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVENT_GENERATOR_LIST_ASSEMBLER_H_
#define _EVENT_GENERATOR_LIST_ASSEMBLER_H_

#include "Algorithm/Algorithm.h"

namespace genie {

class EventGeneratorList;
class EventGeneratorI;

class EventGeneratorListAssembler : public Algorithm {

public :

  EventGeneratorListAssembler();
  EventGeneratorListAssembler(string config);
  ~EventGeneratorListAssembler();

  EventGeneratorList * AssembleGeneratorList();

private:

  const EventGeneratorI * LoadGenerator(int ip);
};

}      // genie namespace

#endif // _EVENT_GENERATOR_LIST_ASSEMBLER_H_
//____________________________________________________________________________
/*!

\class    genie::RunningThreadInfo

\brief    Keep info on the event generation thread currently on charge.
          This is used so that event generation modules invoked by the thread
	  can see the "bigger picture" and access the cross section model for
	  the thread, look-up info for modules that run before or are scheduled
          to run after etc.
	  
\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 06, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _RUNNING_THREAD_INFO_H_
#define _RUNNING_THREAD_INFO_H_

namespace genie {

class EventGeneratorI;

class RunningThreadInfo
{
public:
  static RunningThreadInfo * Instance(void);

  const EventGeneratorI * RunningThread(void) 
  {   
    return fRunningThread; 
  }
  void UpdateRunningThread(const EventGeneratorI * evg) 
  { 
     fRunningThread = evg; 
  }

private:
  RunningThreadInfo();
  RunningThreadInfo(const RunningThreadInfo & info);
  virtual ~RunningThreadInfo();

  //! self
  static RunningThreadInfo * fInstance;

  //! current thread
  const EventGeneratorI * fRunningThread;

  //! clean
  struct Cleaner {
      void DummyMethodAndSilentCompiler() { }
      ~Cleaner() {
         if (RunningThreadInfo::fInstance !=0) {
            delete RunningThreadInfo::fInstance;
            RunningThreadInfo::fInstance = 0;
         }
      }
  };
  friend struct Cleaner;
};

}      // genie namespace

#endif // _RUNNING_THREAD_INFO_H_
//____________________________________________________________________________
/*!

\class   genie::InteractionListGeneratorI

\brief   Defines the InteractionListGeneratorI interface.
         Concrete implementations of this interface generate a list of all
         Interaction (= event summary) objects that can be generated by
         EventGeneratorI subclasses.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 13, 2005

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_LIST_GENERATOR_I_H_
#define _INTERACTION_LIST_GENERATOR_I_H_

#include "Algorithm/Algorithm.h"

namespace genie {

class InteractionList;
class InitialState;

class InteractionListGeneratorI : public Algorithm {

public :

  //-- define the InteractionListGeneratorI interface

  virtual InteractionList *
                 CreateInteractionList(const InitialState & init) const = 0;

protected :

  InteractionListGeneratorI();
  InteractionListGeneratorI(string name);
  InteractionListGeneratorI(string name, string config);
  ~InteractionListGeneratorI();
};

}      // genie namespace

#endif // _INTERACTION_LIST_GENERATOR_I_H_
//____________________________________________________________________________
/*!

\class   genie::XSecAlgorithmMap

\brief   An Interaction -> XSecAlgorithmI associative container. The container
         is being built for the loaded EventGeneratorList and for the input
         InitialState object.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created January 23, 2006

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _XSEC_ALGORITHM_MAP_H_
#define _XSEC_ALGORITHM_MAP_H_

#include <map>
#include <string>
#include <ostream>

using std::map;
using std::string;
using std::ostream;

namespace genie {

class XSecAlgorithmMap;
class XSecAlgorithmI;
class Interaction;
class InteractionList;
class InitialState;
class EventGeneratorList;

ostream & operator << (ostream & stream, const XSecAlgorithmMap & xsmap);

class XSecAlgorithmMap : public map<string, const XSecAlgorithmI *> {

public :

  XSecAlgorithmMap();
  XSecAlgorithmMap(const XSecAlgorithmMap & xsmap);
  ~XSecAlgorithmMap();

  void UseGeneratorList (const EventGeneratorList * list);
  void BuildMap         (const InitialState & init_state);

  const XSecAlgorithmI *  FindXSecAlgorithm  (const Interaction * in) const;
  const InteractionList & GetInteractionList (void) const;

  void Reset (void);
  void Copy  (const XSecAlgorithmMap & xsmap);
  void Print (ostream & stream) const;

  XSecAlgorithmMap & operator =  (const XSecAlgorithmMap & xsmap);
  friend ostream &   operator << (ostream & stream, const XSecAlgorithmMap & xsmap);

private:

  void Init    (void);
  void CleanUp (void);

  const EventGeneratorList * fEventGeneratorList;

  InitialState *    fInitState;
  InteractionList * fInteractionList;
};

}      // genie namespace

#endif // _XSEC_ALGORITHM_MAP_H_
//____________________________________________________________________________
/*!

\class   genie::EventGenerator

\brief   Encapsulates a full ordered list of (is the aggregate of) concrete
         EventGeneratorI implementations that must act on the EventRecord
         to generate an event. Each of these implementations corresponds to
         a single processing step.

         Is a concrete implementation of the EventGeneratorI interface.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created October 03, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVENT_GENERATOR_H_
#define _EVENT_GENERATOR_H_

#include <vector>

#include "EVGCore/EventGeneratorI.h"
#include "GHEP/GHepRecordHistory.h"

class TStopwatch;
class TBits;

using std::vector;

namespace genie {

class EventGenerator: public EventGeneratorI {

public :
  EventGenerator();
  EventGenerator(string config);
  ~EventGenerator();

  //-- implement the original EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  //-- implement the extensions to the EventRecordVisitorI interface
  const GVldContext &               ValidityContext  (void) const;
  const InteractionListGeneratorI * IntListGenerator (void) const;
  const XSecAlgorithmI *            CrossSectionAlg  (void) const;

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

private:

  void Init       (void);
  void LoadConfig (void);

  //-- private data members
  vector<const EventRecordVisitorI *> * fEVGModuleVec;   ///< list of modules
  vector<double> *                      fEVGTime;        ///< module timing info
  const XSecAlgorithmI *                fXSecModel;      ///< xsec model for events handled by thread
  const InteractionListGeneratorI *     fIntListGen;     ///< generates list of handled interactions
  GVldContext *                         fVldContext;     ///< validity context
  TStopwatch *                          fWatch;          ///< stopwatch for module timing
  TBits *                               fFiltUnphysMask; ///< mask for allowing unphysical events to pass through (if requested)
  mutable GHepRecordHistory             fRecHistory;     ///< event record history 
};

}      // genie namespace

#endif // _EVENT_GENERATOR_H_
//____________________________________________________________________________
/*!

\class   genie::EventGeneratorList

\brief   A vector of EventGeneratorI objects

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created January 25, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _EVENT_GENERATOR_LIST_H_
#define _EVENT_GENERATOR_LIST_H_

#include <vector>
#include <ostream>

using std::vector;
using std::ostream;

namespace genie {

class EventGeneratorList;
class EventGeneratorI;

ostream & operator << (ostream & stream, const EventGeneratorList & evgl);

class EventGeneratorList : public vector<const EventGeneratorI *> {

public :

  EventGeneratorList();
  ~EventGeneratorList();

  void Print(ostream & stream) const;

  friend ostream & operator << (ostream & stream, const EventGeneratorList & evgl);
};

}      // genie namespace

#endif // _EVENT_GENERATOR_LIST_H_
//____________________________________________________________________________
/*!

\class   genie::InteractionListAssembler

\brief   Assembles a list of all interactions that can be generated during a
         neutrino event generation job by querying each EventGeneratorI
         subclass employed in that job for its interaction list.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 16, 2005

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_LIST_ASSEMBLER_H_
#define _INTERACTION_LIST_ASSEMBLER_H_

#include "Algorithm/Algorithm.h"

namespace genie {

class InteractionList;
class EventGeneratorList;
class InitialState;

class InteractionListAssembler : public Algorithm {

public :

  InteractionListAssembler();
  InteractionListAssembler(string config);
  ~InteractionListAssembler();

  void              SetGeneratorList        (EventGeneratorList * evglist);
  InteractionList * AssembleInteractionList (const InitialState & init) const;

private:

  EventGeneratorList * fEventGeneratorList;
};

}      // genie namespace

#endif // _INTERACTION_LIST_ASSEMBLER_H_
//____________________________________________________________________________
/*!

\class   genie::InteractionList

\brief   A vector of Interaction objects.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created May 13, 2005

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_LIST_H_
#define _INTERACTION_LIST_H_

#include <vector>
#include <ostream>

using std::vector;
using std::ostream;

namespace genie {

class Interaction;
class InteractionList;

ostream & operator << (ostream & stream, const InteractionList & intl);

class InteractionList : public vector<Interaction *> {

public :
  InteractionList();
  InteractionList(const InteractionList & intl);
  ~InteractionList();

  void Reset  (void);
  void Append (const InteractionList & intl);
  void Copy   (const InteractionList & intl);
  void Print  (ostream & stream) const;

  InteractionList & operator =  (const InteractionList & intl);
  friend ostream &  operator << (ostream & stream, const InteractionList & intl);
};

}      // genie namespace

#endif // _INTERACTION_LIST_H_
//____________________________________________________________________________
/*!

\class   genie::InteractionSelectorI

\brief   Defines the InteractionSelectorI interface to be implemented by
         algorithms selecting interactions to be generated.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created December 05, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_SELECTOR_I_H_
#define _INTERACTION_SELECTOR_I_H_

#include "Algorithm/Algorithm.h"

class TLorentzVector;

namespace genie {

class InteractionGeneratorMap;
class EventRecord;

class InteractionSelectorI : public Algorithm {

public :
  virtual ~InteractionSelectorI();

  //!  Define the InteractionSelectorI interface
  virtual EventRecord * SelectInteraction
    (const InteractionGeneratorMap * igmp, const TLorentzVector & p4) const = 0;

protected:
  InteractionSelectorI();
  InteractionSelectorI(string name);
  InteractionSelectorI(string name, string config);
};

}      // genie namespace

#endif // _INTERACTION_SELECTOR_I_H_
//____________________________________________________________________________
/*!

\class   genie::EventGeneratorI

\brief   Defines the EventGeneratorI interface.

         The concrete implementations of this interface are Event Record
         Visitors (subclasses of the EventRecordVisitorI pABC) that,
         additionally, declare a 'Validity Context'. \n

         The declared validity context is used for selecting the appropriate
         concrete EventGeneratorI to generate the interacion at hand using
         the 'chain-of-responsibility' design pattern.

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab

\created November 22, 2004

\cpright Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________


#ifndef _EVENT_GENERATOR_I_H_
#define _EVENT_GENERATOR_I_H_

#include "EVGCore/EventRecordVisitorI.h"
#include "EVGCore/GVldContext.h"

namespace genie {

class InteractionListGeneratorI;
class XSecAlgorithmI;

class EventGeneratorI: public EventRecordVisitorI {

public :

  virtual ~EventGeneratorI();

  //-- define an extension to the public EventRecordVisitorI interface
  virtual const GVldContext &               ValidityContext  (void) const = 0;
  virtual const InteractionListGeneratorI * IntListGenerator (void) const = 0;
  virtual const XSecAlgorithmI *            CrossSectionAlg  (void) const = 0;

protected:

  //-- dummy ctors & dtor
  EventGeneratorI();
  EventGeneratorI(string name);
  EventGeneratorI(string name, string config);
};

}      // genie namespace

#endif // _EVENT_GENERATOR_I_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::EventGenerator", payloadCode, "@",
"genie::EventGeneratorI", payloadCode, "@",
"genie::EventGeneratorList", payloadCode, "@",
"genie::EventGeneratorListAssembler", payloadCode, "@",
"genie::EventRecord", payloadCode, "@",
"genie::EventRecordVisitorI", payloadCode, "@",
"genie::GVldContext", payloadCode, "@",
"genie::InteractionGeneratorMap", payloadCode, "@",
"genie::InteractionList", payloadCode, "@",
"genie::InteractionListAssembler", payloadCode, "@",
"genie::InteractionListGeneratorI", payloadCode, "@",
"genie::InteractionSelectorI", payloadCode, "@",
"genie::PhysInteractionSelector", payloadCode, "@",
"genie::RunningThreadInfo", payloadCode, "@",
"genie::ToyInteractionSelector", payloadCode, "@",
"genie::XSecAlgorithmMap", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGEVGCore",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGEVGCore_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGEVGCore_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGEVGCore() {
  TriggerDictionaryInitialization_libGEVGCore_Impl();
}
