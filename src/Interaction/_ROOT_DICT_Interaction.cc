// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_Interaction

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
#include "Interaction.h"
#include "Kinematics.h"
#include "XclsTag.h"
#include "InitialState.h"
#include "KPhaseSpace.h"
#include "Target.h"
#include "ProcessInfo.h"
#include "InteractionException.h"

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
   static TClass *pairlEgeniecLcLEKineVarcOdoublegR_Dictionary();
   static void pairlEgeniecLcLEKineVarcOdoublegR_TClassManip(TClass*);
   static void *new_pairlEgeniecLcLEKineVarcOdoublegR(void *p = 0);
   static void *newArray_pairlEgeniecLcLEKineVarcOdoublegR(Long_t size, void *p);
   static void delete_pairlEgeniecLcLEKineVarcOdoublegR(void *p);
   static void deleteArray_pairlEgeniecLcLEKineVarcOdoublegR(void *p);
   static void destruct_pairlEgeniecLcLEKineVarcOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<genie::EKineVar,double>*)
   {
      pair<genie::EKineVar,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<genie::EKineVar,double>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<genie::EKineVar,double>", "string", 198,
                  typeid(pair<genie::EKineVar,double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEgeniecLcLEKineVarcOdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(pair<genie::EKineVar,double>) );
      instance.SetNew(&new_pairlEgeniecLcLEKineVarcOdoublegR);
      instance.SetNewArray(&newArray_pairlEgeniecLcLEKineVarcOdoublegR);
      instance.SetDelete(&delete_pairlEgeniecLcLEKineVarcOdoublegR);
      instance.SetDeleteArray(&deleteArray_pairlEgeniecLcLEKineVarcOdoublegR);
      instance.SetDestructor(&destruct_pairlEgeniecLcLEKineVarcOdoublegR);

      ::ROOT::AddClassAlternate("pair<genie::EKineVar,double>","pair<genie::KineVar_t,double>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const pair<genie::EKineVar,double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEgeniecLcLEKineVarcOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<genie::EKineVar,double>*)0x0)->GetClass();
      pairlEgeniecLcLEKineVarcOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEgeniecLcLEKineVarcOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLTarget(void *p = 0);
   static void delete_geniecLcLTarget(void *p);
   static void deleteArray_geniecLcLTarget(void *p);
   static void destruct_geniecLcLTarget(void *p);
   static void streamer_geniecLcLTarget(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::Target*)
   {
      ::genie::Target *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::Target >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::Target", ::genie::Target::Class_Version(), "Target.h", 41,
                  typeid(::genie::Target), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::Target::Dictionary, isa_proxy, 16,
                  sizeof(::genie::Target) );
      instance.SetNew(&new_geniecLcLTarget);
      instance.SetDelete(&delete_geniecLcLTarget);
      instance.SetDeleteArray(&deleteArray_geniecLcLTarget);
      instance.SetDestructor(&destruct_geniecLcLTarget);
      instance.SetStreamerFunc(&streamer_geniecLcLTarget);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::Target*)
   {
      return GenerateInitInstanceLocal((::genie::Target*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::Target*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLInitialState(void *p = 0);
   static void delete_geniecLcLInitialState(void *p);
   static void deleteArray_geniecLcLInitialState(void *p);
   static void destruct_geniecLcLInitialState(void *p);
   static void streamer_geniecLcLInitialState(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InitialState*)
   {
      ::genie::InitialState *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::InitialState >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::InitialState", ::genie::InitialState::Class_Version(), "InitialState.h", 42,
                  typeid(::genie::InitialState), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::InitialState::Dictionary, isa_proxy, 16,
                  sizeof(::genie::InitialState) );
      instance.SetNew(&new_geniecLcLInitialState);
      instance.SetDelete(&delete_geniecLcLInitialState);
      instance.SetDeleteArray(&deleteArray_geniecLcLInitialState);
      instance.SetDestructor(&destruct_geniecLcLInitialState);
      instance.SetStreamerFunc(&streamer_geniecLcLInitialState);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InitialState*)
   {
      return GenerateInitInstanceLocal((::genie::InitialState*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InitialState*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLProcessInfo(void *p = 0);
   static void *newArray_geniecLcLProcessInfo(Long_t size, void *p);
   static void delete_geniecLcLProcessInfo(void *p);
   static void deleteArray_geniecLcLProcessInfo(void *p);
   static void destruct_geniecLcLProcessInfo(void *p);
   static void streamer_geniecLcLProcessInfo(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::ProcessInfo*)
   {
      ::genie::ProcessInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::ProcessInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::ProcessInfo", ::genie::ProcessInfo::Class_Version(), "ProcessInfo.h", 41,
                  typeid(::genie::ProcessInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::ProcessInfo::Dictionary, isa_proxy, 16,
                  sizeof(::genie::ProcessInfo) );
      instance.SetNew(&new_geniecLcLProcessInfo);
      instance.SetNewArray(&newArray_geniecLcLProcessInfo);
      instance.SetDelete(&delete_geniecLcLProcessInfo);
      instance.SetDeleteArray(&deleteArray_geniecLcLProcessInfo);
      instance.SetDestructor(&destruct_geniecLcLProcessInfo);
      instance.SetStreamerFunc(&streamer_geniecLcLProcessInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::ProcessInfo*)
   {
      return GenerateInitInstanceLocal((::genie::ProcessInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::ProcessInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLKinematics(void *p = 0);
   static void delete_geniecLcLKinematics(void *p);
   static void deleteArray_geniecLcLKinematics(void *p);
   static void destruct_geniecLcLKinematics(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::Kinematics*)
   {
      ::genie::Kinematics *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::Kinematics >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::Kinematics", ::genie::Kinematics::Class_Version(), "Kinematics.h", 40,
                  typeid(::genie::Kinematics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::Kinematics::Dictionary, isa_proxy, 4,
                  sizeof(::genie::Kinematics) );
      instance.SetNew(&new_geniecLcLKinematics);
      instance.SetDelete(&delete_geniecLcLKinematics);
      instance.SetDeleteArray(&deleteArray_geniecLcLKinematics);
      instance.SetDestructor(&destruct_geniecLcLKinematics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::Kinematics*)
   {
      return GenerateInitInstanceLocal((::genie::Kinematics*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::Kinematics*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLXclsTag(void *p = 0);
   static void *newArray_geniecLcLXclsTag(Long_t size, void *p);
   static void delete_geniecLcLXclsTag(void *p);
   static void deleteArray_geniecLcLXclsTag(void *p);
   static void destruct_geniecLcLXclsTag(void *p);
   static void streamer_geniecLcLXclsTag(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::XclsTag*)
   {
      ::genie::XclsTag *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::XclsTag >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::XclsTag", ::genie::XclsTag::Class_Version(), "XclsTag.h", 37,
                  typeid(::genie::XclsTag), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::XclsTag::Dictionary, isa_proxy, 16,
                  sizeof(::genie::XclsTag) );
      instance.SetNew(&new_geniecLcLXclsTag);
      instance.SetNewArray(&newArray_geniecLcLXclsTag);
      instance.SetDelete(&delete_geniecLcLXclsTag);
      instance.SetDeleteArray(&deleteArray_geniecLcLXclsTag);
      instance.SetDestructor(&destruct_geniecLcLXclsTag);
      instance.SetStreamerFunc(&streamer_geniecLcLXclsTag);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::XclsTag*)
   {
      return GenerateInitInstanceLocal((::genie::XclsTag*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::XclsTag*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLKPhaseSpace(void *p = 0);
   static void *newArray_geniecLcLKPhaseSpace(Long_t size, void *p);
   static void delete_geniecLcLKPhaseSpace(void *p);
   static void deleteArray_geniecLcLKPhaseSpace(void *p);
   static void destruct_geniecLcLKPhaseSpace(void *p);
   static void streamer_geniecLcLKPhaseSpace(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::KPhaseSpace*)
   {
      ::genie::KPhaseSpace *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::KPhaseSpace >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::KPhaseSpace", ::genie::KPhaseSpace::Class_Version(), "KPhaseSpace.h", 34,
                  typeid(::genie::KPhaseSpace), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::KPhaseSpace::Dictionary, isa_proxy, 16,
                  sizeof(::genie::KPhaseSpace) );
      instance.SetNew(&new_geniecLcLKPhaseSpace);
      instance.SetNewArray(&newArray_geniecLcLKPhaseSpace);
      instance.SetDelete(&delete_geniecLcLKPhaseSpace);
      instance.SetDeleteArray(&deleteArray_geniecLcLKPhaseSpace);
      instance.SetDestructor(&destruct_geniecLcLKPhaseSpace);
      instance.SetStreamerFunc(&streamer_geniecLcLKPhaseSpace);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::KPhaseSpace*)
   {
      return GenerateInitInstanceLocal((::genie::KPhaseSpace*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::KPhaseSpace*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLInteraction(void *p = 0);
   static void delete_geniecLcLInteraction(void *p);
   static void deleteArray_geniecLcLInteraction(void *p);
   static void destruct_geniecLcLInteraction(void *p);
   static void streamer_geniecLcLInteraction(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::Interaction*)
   {
      ::genie::Interaction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::Interaction >(0);
      static ::ROOT::TGenericClassInfo 
         instance("genie::Interaction", ::genie::Interaction::Class_Version(), "", 58,
                  typeid(::genie::Interaction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::Interaction::Dictionary, isa_proxy, 16,
                  sizeof(::genie::Interaction) );
      instance.SetNew(&new_geniecLcLInteraction);
      instance.SetDelete(&delete_geniecLcLInteraction);
      instance.SetDeleteArray(&deleteArray_geniecLcLInteraction);
      instance.SetDestructor(&destruct_geniecLcLInteraction);
      instance.SetStreamerFunc(&streamer_geniecLcLInteraction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::Interaction*)
   {
      return GenerateInitInstanceLocal((::genie::Interaction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::Interaction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr Target::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Target::Class_Name()
{
   return "genie::Target";
}

//______________________________________________________________________________
const char *Target::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Target*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Target::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Target*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Target::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Target*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Target::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Target*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr InitialState::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *InitialState::Class_Name()
{
   return "genie::InitialState";
}

//______________________________________________________________________________
const char *InitialState::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::InitialState*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int InitialState::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::InitialState*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *InitialState::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::InitialState*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *InitialState::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::InitialState*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr ProcessInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ProcessInfo::Class_Name()
{
   return "genie::ProcessInfo";
}

//______________________________________________________________________________
const char *ProcessInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::ProcessInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ProcessInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::ProcessInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProcessInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::ProcessInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProcessInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::ProcessInfo*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr Kinematics::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Kinematics::Class_Name()
{
   return "genie::Kinematics";
}

//______________________________________________________________________________
const char *Kinematics::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Kinematics*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Kinematics::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Kinematics*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Kinematics::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Kinematics*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Kinematics::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Kinematics*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr XclsTag::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *XclsTag::Class_Name()
{
   return "genie::XclsTag";
}

//______________________________________________________________________________
const char *XclsTag::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::XclsTag*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int XclsTag::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::XclsTag*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *XclsTag::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::XclsTag*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *XclsTag::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::XclsTag*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr KPhaseSpace::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *KPhaseSpace::Class_Name()
{
   return "genie::KPhaseSpace";
}

//______________________________________________________________________________
const char *KPhaseSpace::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::KPhaseSpace*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int KPhaseSpace::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::KPhaseSpace*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *KPhaseSpace::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::KPhaseSpace*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *KPhaseSpace::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::KPhaseSpace*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace genie {
//______________________________________________________________________________
atomic_TClass_ptr Interaction::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Interaction::Class_Name()
{
   return "genie::Interaction";
}

//______________________________________________________________________________
const char *Interaction::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Interaction*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Interaction::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::Interaction*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Interaction::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Interaction*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Interaction::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::Interaction*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEgeniecLcLEKineVarcOdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<genie::EKineVar,double> : new pair<genie::EKineVar,double>;
   }
   static void *newArray_pairlEgeniecLcLEKineVarcOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<genie::EKineVar,double>[nElements] : new pair<genie::EKineVar,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEgeniecLcLEKineVarcOdoublegR(void *p) {
      delete ((pair<genie::EKineVar,double>*)p);
   }
   static void deleteArray_pairlEgeniecLcLEKineVarcOdoublegR(void *p) {
      delete [] ((pair<genie::EKineVar,double>*)p);
   }
   static void destruct_pairlEgeniecLcLEKineVarcOdoublegR(void *p) {
      typedef pair<genie::EKineVar,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<genie::EKineVar,double>

namespace genie {
//______________________________________________________________________________
void Target::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::Target.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::Target thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fZ;
      R__b >> fA;
      R__b >> fTgtPDG;
      R__b >> fHitNucPDG;
      R__b >> fHitQrkPDG;
      R__b >> fHitSeaQrk;
      R__b >> fHitNucP4;
      R__b >> fHitNucRad;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fZ;
      R__b << fA;
      R__b << fTgtPDG;
      R__b << fHitNucPDG;
      R__b << fHitQrkPDG;
      R__b << fHitSeaQrk;
      R__b << fHitNucP4;
      R__b << fHitNucRad;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLTarget(void *p) {
      return  p ? new(p) ::genie::Target( (TRootIOCtor *)nullptr ) : new ::genie::Target( (TRootIOCtor *)nullptr );
   }
   // Wrapper around operator delete
   static void delete_geniecLcLTarget(void *p) {
      delete ((::genie::Target*)p);
   }
   static void deleteArray_geniecLcLTarget(void *p) {
      delete [] ((::genie::Target*)p);
   }
   static void destruct_geniecLcLTarget(void *p) {
      typedef ::genie::Target current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLTarget(TBuffer &buf, void *obj) {
      ((::genie::Target*)obj)->::genie::Target::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::Target

namespace genie {
//______________________________________________________________________________
void InitialState::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::InitialState.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::InitialState thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fProbePdg;
      R__b >> fTgt;
      R__b >> fProbeP4;
      R__b >> fTgtP4;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fProbePdg;
      R__b << fTgt;
      R__b << fProbeP4;
      R__b << fTgtP4;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInitialState(void *p) {
      return  p ? new(p) ::genie::InitialState( (TRootIOCtor *)nullptr ) : new ::genie::InitialState( (TRootIOCtor *)nullptr );
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInitialState(void *p) {
      delete ((::genie::InitialState*)p);
   }
   static void deleteArray_geniecLcLInitialState(void *p) {
      delete [] ((::genie::InitialState*)p);
   }
   static void destruct_geniecLcLInitialState(void *p) {
      typedef ::genie::InitialState current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLInitialState(TBuffer &buf, void *obj) {
      ((::genie::InitialState*)obj)->::genie::InitialState::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::InitialState

namespace genie {
//______________________________________________________________________________
void ProcessInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::ProcessInfo.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::ProcessInfo thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      void *ptr_fScatteringType = (void*)&fScatteringType;
      R__b >> *reinterpret_cast<Int_t*>(ptr_fScatteringType);
      void *ptr_fInteractionType = (void*)&fInteractionType;
      R__b >> *reinterpret_cast<Int_t*>(ptr_fInteractionType);
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << (Int_t)fScatteringType;
      R__b << (Int_t)fInteractionType;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLProcessInfo(void *p) {
      return  p ? new(p) ::genie::ProcessInfo : new ::genie::ProcessInfo;
   }
   static void *newArray_geniecLcLProcessInfo(Long_t nElements, void *p) {
      return p ? new(p) ::genie::ProcessInfo[nElements] : new ::genie::ProcessInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLProcessInfo(void *p) {
      delete ((::genie::ProcessInfo*)p);
   }
   static void deleteArray_geniecLcLProcessInfo(void *p) {
      delete [] ((::genie::ProcessInfo*)p);
   }
   static void destruct_geniecLcLProcessInfo(void *p) {
      typedef ::genie::ProcessInfo current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLProcessInfo(TBuffer &buf, void *obj) {
      ((::genie::ProcessInfo*)obj)->::genie::ProcessInfo::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::ProcessInfo

namespace genie {
//______________________________________________________________________________
void Kinematics::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::Kinematics.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(genie::Kinematics::Class(),this);
   } else {
      R__b.WriteClassBuffer(genie::Kinematics::Class(),this);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLKinematics(void *p) {
      return  p ? new(p) ::genie::Kinematics( (TRootIOCtor *)nullptr ) : new ::genie::Kinematics( (TRootIOCtor *)nullptr );
   }
   // Wrapper around operator delete
   static void delete_geniecLcLKinematics(void *p) {
      delete ((::genie::Kinematics*)p);
   }
   static void deleteArray_geniecLcLKinematics(void *p) {
      delete [] ((::genie::Kinematics*)p);
   }
   static void destruct_geniecLcLKinematics(void *p) {
      typedef ::genie::Kinematics current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::Kinematics

namespace genie {
//______________________________________________________________________________
void XclsTag::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::XclsTag.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::XclsTag thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fIsCharmEvent;
      R__b >> fCharmedHadronPdg;
      R__b >> fIsStrangeEvent;
      R__b >> fStrangeHadronPdg;
      R__b >> fNProtons;
      R__b >> fNNeutrons;
      R__b >> fNPi0;
      R__b >> fNPiPlus;
      R__b >> fNPiMinus;
      void *ptr_fResonance = (void*)&fResonance;
      R__b >> *reinterpret_cast<Int_t*>(ptr_fResonance);
      R__b >> fDecayMode;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fIsCharmEvent;
      R__b << fCharmedHadronPdg;
      R__b << fIsStrangeEvent;
      R__b << fStrangeHadronPdg;
      R__b << fNProtons;
      R__b << fNNeutrons;
      R__b << fNPi0;
      R__b << fNPiPlus;
      R__b << fNPiMinus;
      R__b << (Int_t)fResonance;
      R__b << fDecayMode;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLXclsTag(void *p) {
      return  p ? new(p) ::genie::XclsTag : new ::genie::XclsTag;
   }
   static void *newArray_geniecLcLXclsTag(Long_t nElements, void *p) {
      return p ? new(p) ::genie::XclsTag[nElements] : new ::genie::XclsTag[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLXclsTag(void *p) {
      delete ((::genie::XclsTag*)p);
   }
   static void deleteArray_geniecLcLXclsTag(void *p) {
      delete [] ((::genie::XclsTag*)p);
   }
   static void destruct_geniecLcLXclsTag(void *p) {
      typedef ::genie::XclsTag current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLXclsTag(TBuffer &buf, void *obj) {
      ((::genie::XclsTag*)obj)->::genie::XclsTag::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::XclsTag

namespace genie {
//______________________________________________________________________________
void KPhaseSpace::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::KPhaseSpace.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::KPhaseSpace thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fInteraction;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fInteraction;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLKPhaseSpace(void *p) {
      return  p ? new(p) ::genie::KPhaseSpace : new ::genie::KPhaseSpace;
   }
   static void *newArray_geniecLcLKPhaseSpace(Long_t nElements, void *p) {
      return p ? new(p) ::genie::KPhaseSpace[nElements] : new ::genie::KPhaseSpace[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLKPhaseSpace(void *p) {
      delete ((::genie::KPhaseSpace*)p);
   }
   static void deleteArray_geniecLcLKPhaseSpace(void *p) {
      delete [] ((::genie::KPhaseSpace*)p);
   }
   static void destruct_geniecLcLKPhaseSpace(void *p) {
      typedef ::genie::KPhaseSpace current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLKPhaseSpace(TBuffer &buf, void *obj) {
      ((::genie::KPhaseSpace*)obj)->::genie::KPhaseSpace::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::KPhaseSpace

namespace genie {
//______________________________________________________________________________
void Interaction::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::Interaction.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::genie::Interaction thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fInitialState;
      R__b >> fProcInfo;
      R__b >> fKinematics;
      R__b >> fExclusiveTag;
      R__b >> fKinePhSp;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fInitialState;
      R__b << fProcInfo;
      R__b << fKinematics;
      R__b << fExclusiveTag;
      R__b << fKinePhSp;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace genie
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInteraction(void *p) {
      return  p ? new(p) ::genie::Interaction( (TRootIOCtor *)nullptr ) : new ::genie::Interaction( (TRootIOCtor *)nullptr );
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInteraction(void *p) {
      delete ((::genie::Interaction*)p);
   }
   static void deleteArray_geniecLcLInteraction(void *p) {
      delete [] ((::genie::Interaction*)p);
   }
   static void destruct_geniecLcLInteraction(void *p) {
      typedef ::genie::Interaction current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_geniecLcLInteraction(TBuffer &buf, void *obj) {
      ((::genie::Interaction*)obj)->::genie::Interaction::Streamer(buf);
   }
} // end of namespace ROOT for class ::genie::Interaction

namespace ROOT {
   static TClass *maplEgeniecLcLEKineVarcOdoublegR_Dictionary();
   static void maplEgeniecLcLEKineVarcOdoublegR_TClassManip(TClass*);
   static void *new_maplEgeniecLcLEKineVarcOdoublegR(void *p = 0);
   static void *newArray_maplEgeniecLcLEKineVarcOdoublegR(Long_t size, void *p);
   static void delete_maplEgeniecLcLEKineVarcOdoublegR(void *p);
   static void deleteArray_maplEgeniecLcLEKineVarcOdoublegR(void *p);
   static void destruct_maplEgeniecLcLEKineVarcOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<genie::EKineVar,double>*)
   {
      map<genie::EKineVar,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<genie::EKineVar,double>));
      static ::ROOT::TGenericClassInfo 
         instance("map<genie::EKineVar,double>", -2, "map", 99,
                  typeid(map<genie::EKineVar,double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEgeniecLcLEKineVarcOdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(map<genie::EKineVar,double>) );
      instance.SetNew(&new_maplEgeniecLcLEKineVarcOdoublegR);
      instance.SetNewArray(&newArray_maplEgeniecLcLEKineVarcOdoublegR);
      instance.SetDelete(&delete_maplEgeniecLcLEKineVarcOdoublegR);
      instance.SetDeleteArray(&deleteArray_maplEgeniecLcLEKineVarcOdoublegR);
      instance.SetDestructor(&destruct_maplEgeniecLcLEKineVarcOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<genie::EKineVar,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<genie::EKineVar,double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEgeniecLcLEKineVarcOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<genie::EKineVar,double>*)0x0)->GetClass();
      maplEgeniecLcLEKineVarcOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void maplEgeniecLcLEKineVarcOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEgeniecLcLEKineVarcOdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<genie::EKineVar,double> : new map<genie::EKineVar,double>;
   }
   static void *newArray_maplEgeniecLcLEKineVarcOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<genie::EKineVar,double>[nElements] : new map<genie::EKineVar,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEgeniecLcLEKineVarcOdoublegR(void *p) {
      delete ((map<genie::EKineVar,double>*)p);
   }
   static void deleteArray_maplEgeniecLcLEKineVarcOdoublegR(void *p) {
      delete [] ((map<genie::EKineVar,double>*)p);
   }
   static void destruct_maplEgeniecLcLEKineVarcOdoublegR(void *p) {
      typedef map<genie::EKineVar,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<genie::EKineVar,double>

namespace {
  void TriggerDictionaryInitialization_libGInteraction_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"Interaction",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/Interaction",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/Interaction",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/Interaction/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGInteraction dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{enum  __attribute__((annotate("$clingAutoload$Conventions/KineVar.h")))  __attribute__((annotate("$clingAutoload$Interaction/Kinematics.h"))) EKineVar : unsigned int;}
namespace std{template <typename _T1, typename _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/Target.h")))  __attribute__((annotate("$clingAutoload$Interaction/InitialState.h")))  Target;}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/InitialState.h")))  InitialState;}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/ProcessInfo.h")))  ProcessInfo;}
namespace std{template <typename _Tp = void> struct __attribute__((annotate("$clingAutoload$bits/stl_function.h")))  __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/Kinematics.h")))  Kinematics;}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/XclsTag.h")))  XclsTag;}
namespace genie{class __attribute__((annotate("$clingAutoload$Interaction/KPhaseSpace.h")))  KPhaseSpace;}
namespace genie{class Interaction;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGInteraction dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::Interaction

\brief    Summary information for an interaction.

          It is a container of an InitialState, a ProcessInfo, an XclsTag
          and a Kinematics object.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  April 25, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INTERACTION_H_
#define _INTERACTION_H_

#include <ostream>
#include <string>

#include <TObject.h>

#include "Conventions/RefFrame.h"
#include "Interaction/InitialState.h"
#include "Interaction/ProcessInfo.h"
#include "Interaction/Kinematics.h"
#include "Interaction/XclsTag.h"
#include "Interaction/KPhaseSpace.h"

using std::ostream;
using std::string;

class TRootIOCtor;

namespace genie {

const UInt_t kISkipProcessChk      = 1<<17; ///< if set, skip process validity checks
const UInt_t kISkipKinematicChk    = 1<<16; ///< if set, skip kinematic validity checks
const UInt_t kIAssumeFreeNucleon   = 1<<15; ///<
const UInt_t kIAssumeFreeElectron  = 1<<15; ///<
const UInt_t kINoNuclearCorrection = 1<<14; ///< if set, inhibit nuclear corrections 

class Interaction;
ostream & operator << (ostream & stream, const Interaction & i); 

class Interaction : public TObject {

public:
  using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
  using TObject::Copy;  // 

  Interaction();
  Interaction(const InitialState & init, const ProcessInfo & proc);
  Interaction(const Interaction & i);
  Interaction(TRootIOCtor*);
 ~Interaction();

  // Methods accessing aggregate/owned objects holding interaction information
  const InitialState & InitState     (void) const { return *fInitialState; }
  const ProcessInfo &  ProcInfo      (void) const { return *fProcInfo;     }
  const Kinematics &   Kine          (void) const { return *fKinematics;   }
  const XclsTag &      ExclTag       (void) const { return *fExclusiveTag; }
  const KPhaseSpace &  PhaseSpace    (void) const { return *fKinePhSp;     }
  InitialState *       InitStatePtr  (void) const { return fInitialState;  }
  ProcessInfo *        ProcInfoPtr   (void) const { return fProcInfo;      }
  Kinematics *         KinePtr       (void) const { return fKinematics;    }
  XclsTag *            ExclTagPtr    (void) const { return fExclusiveTag;  }
  KPhaseSpace *        PhaseSpacePtr (void) const { return fKinePhSp;      }

  // Methods to set interaction's properties
  void SetInitState (const InitialState & init);
  void SetProcInfo  (const ProcessInfo &  proc);
  void SetKine      (const Kinematics &   kine);
  void SetExclTag   (const XclsTag &      xcls);

  // Get the final state primary lepton and recoil nucleon (if) uniquely
  // determined for the specified interaction
  int            FSPrimLeptonPdg  (void) const; ///< final state primary lepton pdg
  int            RecoilNucleonPdg (void) const; ///< recoil nucleon pdg
  TParticlePDG * FSPrimLepton     (void) const; ///< final state primaru lepton
  TParticlePDG * RecoilNucleon    (void) const; ///< recoil nucleon 

  // Copy, reset, print itself and build string code
  void   Reset    (void);
  void   Copy     (const Interaction & i);
  string AsString (void) const;
  void   Print    (ostream & stream) const;

  // Overloaded operators
  Interaction &    operator =  (const Interaction & i);                   ///< copy
  friend ostream & operator << (ostream & stream, const Interaction & i); ///< print

  // Use the "Named Constructor" C++ idiom for fast creation of typical interactions
  static Interaction * DISCC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * DISCC     (int tgt, int nuc, int qrk, bool sea, int probe, double E=0);
  static Interaction * DISCC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * DISCC     (int tgt, int nuc, int qrk, bool sea, int probe, const TLorentzVector & p4probe);
  static Interaction * DISNC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * DISNC     (int tgt, int nuc, int qrk, bool sea, int probe, double E=0);
  static Interaction * DISNC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * DISNC     (int tgt, int nuc, int qrk, bool sea, int probe, const TLorentzVector & p4probe);
  static Interaction * DISEM     (int tgt, int nuc, int probe, double E=0);
  static Interaction * DISEM     (int tgt, int nuc, int qrk, bool sea, int probe, double E=0);
  static Interaction * DISEM     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * DISEM     (int tgt, int nuc, int qrk, bool sea, int probe, const TLorentzVector & p4probe);
  static Interaction * QELCC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * QELCC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * QELNC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * QELNC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * QELEM     (int tgt, int nuc, int probe, double E=0);
  static Interaction * QELEM     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * IBD       (int tgt, int nuc, int probe, double E=0);
  static Interaction * IBD       (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * RESCC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * RESCC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * RESNC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * RESNC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * RESEM     (int tgt, int nuc, int probe, double E=0);
  static Interaction * RESEM     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * DFRCC     (int tgt, int nuc, int probe, double E=0);
  static Interaction * DFRCC     (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * COHCC     (int tgt, int probe, double E=0);
  static Interaction * COHCC     (int tgt, int probe, const TLorentzVector & p4probe);
  static Interaction * COHNC     (int tgt, int probe, double E=0);
  static Interaction * COHNC     (int tgt, int probe, const TLorentzVector & p4probe);
  static Interaction * COHEl     (int tgt, int probe, double E=0);
  static Interaction * COHEl     (int tgt, int probe, const TLorentzVector & p4probe);
  static Interaction * IMD       (int tgt, double E=0);
  static Interaction * IMD       (int tgt, const TLorentzVector & p4probe);
  static Interaction * AMNuGamma (int tgt, int nuc, int probe, double E=0);
  static Interaction * AMNuGamma (int tgt, int nuc, int probe, const TLorentzVector & p4probe);
  static Interaction * MECCC     (int tgt, int nuccluster, int probe, double E=0);
  static Interaction * MECCC     (int tgt, int nuccluster, int probe, const TLorentzVector & p4probe);
  static Interaction * MECCC     (int tgt, int probe, double E=0);
  static Interaction * MECCC     (int tgt, int probe, const TLorentzVector & p4probe);
  static Interaction * MECNC     (int tgt, int nuccluster, int probe, double E=0);
  static Interaction * MECNC     (int tgt, int nuccluster, int probe, const TLorentzVector & p4probe);
  static Interaction * MECEM     (int tgt, int nuccluster, int probe, double E=0);
  static Interaction * MECEM     (int tgt, int nuccluster, int probe, const TLorentzVector & p4probe);
  static Interaction * GLR       (int tgt, double E=0);
  static Interaction * GLR       (int tgt, const TLorentzVector & p4probe);
  static Interaction * NDecay    (int tgt, int decay_mode=-1, int decayed_nucleon = 0);
  static Interaction * NOsc      (int tgt, int annihilation_mode=-1);
  static Interaction * ASK       (int tgt, int probe, double E=0);
  static Interaction * ASK       (int tgt, int probe, const TLorentzVector & p4probe);

private:

  // Methods for Interaction initialization and clean up
  void Init    (void);
  void CleanUp (void);

  // Utility method for "named ctor"
  static Interaction * Create(int tgt, int probe, ScatteringType_t st, InteractionType_t it);

  // Private data members
  InitialState * fInitialState;  ///< Initial State info
  ProcessInfo *  fProcInfo;      ///< Process info (scattering, weak current,...)
  Kinematics *   fKinematics;    ///< kinematical variables
  XclsTag *      fExclusiveTag;  ///< Additional info for exclusive channels
  KPhaseSpace *  fKinePhSp;      ///< Kinematic phase space
  
ClassDef(Interaction,2)
};

}      // genie namespace

#endif // _INTERACTION_H_
//____________________________________________________________________________
/*!

\class    genie::Kinematics

\brief    Generated/set kinematical variables for an event

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 08, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_

#include <map>
#include <iostream>

#include <TObject.h>

#include "Conventions/KineVar.h"

using std::map;
using std::ostream;

class TRootIOCtor;
class TLorentzVector;

namespace genie {

class Kinematics;
ostream & operator << (ostream & stream, const Kinematics & kine);

class Kinematics : public TObject {

public:
  using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
  using TObject::Copy;

  Kinematics();
  Kinematics(const Kinematics & kv);
  Kinematics(TRootIOCtor*);
 ~Kinematics();

  double x       (bool selected=false) const;
  double y       (bool selected=false) const;
  double Q2      (bool selected=false) const;
  double q2      (bool selected=false) const;
  double W       (bool selected=false) const;
  double t       (bool selected=false) const;
  double Logx    (bool selected=false) const;
  double Logy    (bool selected=false) const;
  double LogQ2   (bool selected=false) const;
  double LogW    (bool selected=false) const;
  double Log10x  (bool selected=false) const;
  double Log10y  (bool selected=false) const;
  double Log10Q2 (bool selected=false) const;
  double Log10W  (bool selected=false) const;

  const TLorentzVector & FSLeptonP4(void) const { return *fP4Fsl;     }
  const TLorentzVector & HadSystP4 (void) const { return *fP4HadSyst; }

  void   Setx  (double x,  bool selected=false);
  void   Sety  (double y,  bool selected=false);
  void   SetQ2 (double Q2, bool selected=false);
  void   Setq2 (double q2, bool selected=false);
  void   SetW  (double W,  bool selected=false);
  void   Sett  (double t,  bool selected=false);

  void   SetFSLeptonP4 (const TLorentzVector & p4);
  void   SetFSLeptonP4 (double px, double py, double pz, double E);
  void   SetHadSystP4  (const TLorentzVector & p4);
  void   SetHadSystP4  (double px, double py, double pz, double E);

  bool   KVSet(KineVar_t kv) const;
  double GetKV(KineVar_t kv) const;
  void   SetKV(KineVar_t kv, double value);

  void ClearRunningValues    (void);
  void UseSelectedKinematics (void);

  //-- Copy, reset, compare and print itself
  void Reset (void);
  void Copy  (const Kinematics & kine);
  void Print (ostream & stream) const;

  Kinematics &     operator =  (const Kinematics & kine);
  friend ostream & operator << (ostream & stream, const Kinematics & kine);

private:

  void Init    (void); ///< initialize 
  void CleanUp (void); ///< clean-up 

  //-- Private data members

  map<KineVar_t, double> fKV;        ///< selected kinematics
  TLorentzVector *       fP4Fsl;     ///< generated final state primary lepton 4-p  (LAB)
  TLorentzVector *       fP4HadSyst; ///< generated final state hadronic system 4-p (LAB)

ClassDef(Kinematics,2)
};

}       // genie namespace

#endif  // _KINEMATICS_H_
//____________________________________________________________________________
/*!

\class    genie::XclsTag

\brief    Contains minimal information for tagging exclusive processes.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  December 08, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//___________________________________________________________________________

#ifndef _FINAL_STATE_H_
#define _FINAL_STATE_H_

#include <iostream>
#include <string>

#include <TObject.h>

#include "BaryonResonance/BaryonResonance.h"

using std::ostream;
using std::string;

namespace genie {

class XclsTag;
ostream & operator << (ostream& stream, const XclsTag & xcls); 

class XclsTag : public TObject {
  
public:
  using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
  using TObject::Copy;

  XclsTag();
  XclsTag(const XclsTag & xcls);
 ~XclsTag();

  // Getting exclusive intermediate and/or final state information
  bool IsCharmEvent       (void) const { return fIsCharmEvent;     }
  bool IsInclusiveCharm   (void) const;
  int  CharmHadronPdg     (void) const { return fCharmedHadronPdg; }
  bool IsStrangeEvent     (void) const { return fIsStrangeEvent;   }
  bool IsInclusiveStrange (void) const;
  int  StrangeHadronPdg   (void) const {return fStrangeHadronPdg;  }
  int  NProtons           (void) const { return fNProtons;  }
  int  NNeutrons          (void) const { return fNNeutrons; }
  int  NPi0               (void) const { return fNPi0;      }
  int  NPiPlus            (void) const { return fNPiPlus;   }
  int  NPiMinus           (void) const { return fNPiMinus;  }
  int  NNucleons          (void) const { return fNNeutrons + fNProtons;       }
  int  NPions             (void) const { return fNPi0 + fNPiPlus + fNPiMinus; }
  bool KnownResonance     (void) const { return (fResonance != kNoResonance); }
  Resonance_t Resonance   (void) const { return fResonance; }
  int  DecayMode          (void) const { return fDecayMode; }

  // Ssetting exclusive final state information
  void SetCharm       (int charm_pdgc = 0);
  void SetStrange     (int strange_pdgc = 0);
  void SetNPions      (int npi_plus, int npi_0, int npi_minus);
  void SetNNucleons   (int np, int nn);
  void SetNProtons    (int np) { fNProtons  = np; }
  void SetNNeutrons   (int nn) { fNNeutrons = nn; }
  void UnsetCharm     (void);
  void UnsetStrange   (void);
  void ResetNPions    (void);
  void ResetNNucleons (void);
  void SetResonance   (Resonance_t res);
  void SetDecayMode   (int decay_mode);

  // Copy, reset, print itself and build string code
  void   Reset    (void);                          ///< reset object
  void   Copy     (const XclsTag & xcls);          ///< copy input XclsTag object
  string AsString (void) const;                    ///< pack into a string code
  void   Print    (ostream & stream) const;        ///< print

  XclsTag &        operator =  (const XclsTag & xcls);                  ///< copy
  friend ostream & operator << (ostream& stream, const XclsTag & xcls); ///< print

private:

  // Private data members
  bool        fIsCharmEvent;     ///< true if we have charm production
  int         fCharmedHadronPdg; ///< charmed hadron pdg-code
  bool        fIsStrangeEvent;   ///< true if we have strange production
  int         fStrangeHadronPdg; ///< strange hadron pdg-code
  int         fNProtons;         ///< # of p's in the hadronic system after this Xcls reaction (before FSI)
  int         fNNeutrons;        ///< # of n's in the hadronic system after this Xcls reaction (before FSI)
  int         fNPi0;             ///< # of pi^0's in the hadronic system after this Xcls reaction (before FSI)
  int         fNPiPlus;          ///< # of pi^+'s in the hadronic system after this Xcls reaction (before FSI)
  int         fNPiMinus;         ///< # of pi^-'s in the hadronic system after this Xcls reaction (before FSI)
  Resonance_t fResonance;        ///< baryon resonance excited by probe
  int         fDecayMode;

ClassDef(XclsTag,3)
};

}      // namespace

#endif // _FINAL_STATE_H_
//____________________________________________________________________________
/*!

\class    genie::InitialState

\brief    Initial State information

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 02, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INITIAL_STATE_H_
#define _INITIAL_STATE_H_

#include <iostream>
#include <string>

#include <TParticlePDG.h>
#include <TLorentzVector.h>
#include <TObject.h>

#include "Conventions/RefFrame.h"
#include "Interaction/Target.h"

using std::ostream;
using std::string;

class TRootIOCtor;

namespace genie {

class InitialState;
ostream & operator << (ostream & stream, const InitialState & i); 

class InitialState : public TObject {

using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
using TObject::Compare;
using TObject::Copy;

public:
  InitialState();
  InitialState(int tgt_pdgc, int probe_pdgc);
  InitialState(int Z, int A, int probe_pdgc);
  InitialState(const Target & tgt, int probe_pdgc);
  InitialState(const InitialState & initial_state);
  InitialState(TRootIOCtor*);
 ~InitialState();

  TParticlePDG *   Probe      (void) const;
  int              ProbePdg   (void) const { return fProbePdg; }
  int              TgtPdg     (void) const;
  const Target &   Tgt        (void) const { return *fTgt; }
  Target *         TgtPtr     (void) const { return  fTgt; }
  TLorentzVector * GetTgtP4   (RefFrame_t rf = kRfLab) const;
  TLorentzVector * GetProbeP4 (RefFrame_t rf = kRfHitNucRest) const;
  double           ProbeE     (RefFrame_t rf) const;
  double           CMEnergy   () const; ///< centre-of-mass energy (sqrt s)

  void SetPdgs     (int tgt_pdgc, int probe_pdgc);
  void SetProbePdg (int pdg_code);
  void SetTgtPdg   (int pdg_code);
  void SetTgtP4    (const TLorentzVector & P4); // in LAB-frame
  void SetProbeP4  (const TLorentzVector & P4); // in LAB-frame
  void SetProbeE   (double E);                  // in LAB-frame (0,0,E,E)

  bool IsNuP    (void) const; ///< is neutrino      + proton?
  bool IsNuN    (void) const; ///< is neutrino      + neutron?
  bool IsNuBarP (void) const; ///< is anti-neutrino + proton?
  bool IsNuBarN (void) const; ///< is anti-neutrino + neutron?

  //-- Copy, reset, compare, print itself and build string code
  void   Reset    (void);
  void   Copy     (const InitialState & init_state);
  bool   Compare  (const InitialState & init_state) const;
  string AsString (void) const;
  void   Print    (ostream & stream) const;

  //-- Overloaded operators
  bool             operator == (const InitialState & i) const;             ///< equal?
  InitialState &   operator =  (const InitialState & i);                   ///< copy
  friend ostream & operator << (ostream & stream, const InitialState & i); ///< print

private:

  //-- Methods for InitialState initialization and clean up
  void Init       (void);
  void Init       (int target_pdgc, int probe_pdgc);
  void CleanUp    (void);

  //-- Private data members
  int              fProbePdg; ///< probe PDG code
  Target *         fTgt;      ///< nuclear target
  TLorentzVector * fProbeP4;  ///< probe 4-momentum in LAB-frame
  TLorentzVector * fTgtP4;    ///< nuclear target 4-momentum in LAB-frame

ClassDef(InitialState,1)
};

}      // namespace

#endif // _INITIAL_STATE_H_
//____________________________________________________________________________
/*!

\class    genie::KPhaseSpace

\brief    Kinematical phase space 

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 06, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _KINEMATIC_PHASE_SPACE_H_
#define _KINEMATIC_PHASE_SPACE_H_

#include <cassert>

#include <TObject.h>

#include "Conventions/KineVar.h"
//#include "Interaction/KPhaseSpaceCut.h"
#include "Utils/Range1.h"

namespace genie {

class Interaction;

class KPhaseSpace : public TObject {

public:
  KPhaseSpace (void);
  KPhaseSpace (const Interaction * in);
 ~KPhaseSpace (void);

  void UseInteraction(const Interaction * in);

  //! Energy threshold
  double Threshold(void) const;

  //! Checks whether the interaction is above the energy threshold
  bool IsAboveThreshold(void) const;

  //! Check whether the current kinematics is in the allowed phase space
  bool IsAllowed (void) const;

  //! Return the kinematical variable limits
  Range1D_t  Limits  (KineVar_t kvar) const;
  double     Minimum (KineVar_t kvar) const;
  double     Maximum (KineVar_t kvar) const;

  Range1D_t  WLim    (void) const;  ///< W  limits
  Range1D_t  Q2Lim_W (void) const;  ///< Q2 limits @ fixed W
  Range1D_t  q2Lim_W (void) const;  ///< q2 limits @ fixed W
  Range1D_t  Q2Lim   (void) const;  ///< Q2 limits
  Range1D_t  q2Lim   (void) const;  ///< q2 limits
  Range1D_t  XLim    (void) const;  ///< x  limits
  Range1D_t  YLim    (void) const;  ///< y  limits
  Range1D_t  YLim_X  (void) const;  ///< y  limits @ fixed x
  Range1D_t  YLim    (double xsi) const;  ///< y  limits (COH)
  Range1D_t  YLim_X  (double xsi) const;  ///< y  limits @ fixed x (COH)
  Range1D_t  TLim    (void) const;  ///< t  limits

  static double GetTMaxDFR();

private:
  void Init(void);

  const Interaction * fInteraction;

ClassDef(KPhaseSpace,2)
};

}      // genie namespace
#endif // _KINE_PHASE_SPACE_H_

//____________________________________________________________________________
/*!

\class    genie::Target

\brief    A Neutrino Interaction Target. Is a transparent encapsulation of
          quite different physical systems such as a nuclear target, a
          'spectator' nuclear target with a Hit nucleon, a free nucleon or
          a free particle (eg a e- target in the inverse muon decay reaction)

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _TARGET_H_
#define _TARGET_H_

#include <ostream>
#include <string>

#include <TLorentzVector.h>
#include <TObject.h>

using std::ostream;
using std::string;

class TRootIOCtor;

namespace genie {

class Target;
ostream & operator << (ostream & stream, const Target & t); 

class Target : public TObject {

using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
using TObject::Compare;
using TObject::Copy;

public:
  Target();
  Target(int pdgc);
  Target(int Z, int A);
  Target(int Z, int A, int hit_nucleon_pdgc);
  Target(const Target & tgt);
  Target(TRootIOCtor*);
 ~Target();

  //-- Set target properties

  void SetId                  (int pdgc);
  void SetId                  (int Z, int A);
  void SetHitNucPdg           (int pdgc);
  void SetHitNucP4            (const TLorentzVector & p4);
  void SetHitNucPosition        (double r);
  void SetHitQrkPdg           (int pdgc);
  void SetHitSeaQrk           (bool tf);
  void ForceHitNucOnMassShell (void);

  //-- Query target information

  int    Z              (void) const { return fZ;      }
  int    N              (void) const { return fA-fZ;   }
  int    A              (void) const { return fA;      }
  int    Pdg            (void) const { return fTgtPDG; }
  double Mass           (void) const;
  double Charge         (void) const;
  bool   IsFreeNucleon  (void) const;
  bool   IsProton       (void) const;
  bool   IsNeutron      (void) const;
  bool   IsNucleus      (void) const;
  bool   IsParticle     (void) const;
  bool   IsValidNucleus (void) const;
  bool   HitNucIsSet    (void) const;
  bool   HitQrkIsSet    (void) const;
  bool   HitSeaQrk      (void) const;
  bool   IsEvenEven     (void) const;
  bool   IsEvenOdd      (void) const;
  bool   IsOddOdd       (void) const;
  int    HitNucPdg      (void) const;
  int    HitQrkPdg      (void) const;
  double HitNucMass     (void) const;
  double HitNucPosition (void) const { return fHitNucRad; }

  const TLorentzVector & HitNucP4    (void) const { return *this->HitNucP4Ptr(); }
  TLorentzVector *       HitNucP4Ptr (void) const;
  
  //-- Copy, reset, compare, print itself and build string code
  void   Reset    (void);
  void   Copy     (const Target & t);
  bool   Compare  (const Target & t) const;
  string AsString (void) const;
  void   Print    (ostream & stream) const;

  bool             operator == (const Target & t) const;             ///< equal?
  Target &         operator =  (const Target & t);                   ///< copy
  friend ostream & operator << (ostream & stream, const Target & t); ///< print

private:

  //-- Methods for Target initialization and clean up
  void Init    (void);
  void CleanUp (void);

  //-- Methods assuring nucleus & hit nucleon validity
  void ForceNucleusValidity (void);
  bool ForceHitNucValidity  (void);
  void AutoSetHitNuc        (void);

  //-- Private data members
  int  fZ;                    ///< nuclear target Z
  int  fA;                    ///< nuclear target A
  int  fTgtPDG;               ///< nuclear target PDG code
  int  fHitNucPDG;            ///< hit nucleon PDG code
  int  fHitQrkPDG;            ///< hit quark PDG code
  bool fHitSeaQrk;            ///< hit quark from sea?
  TLorentzVector * fHitNucP4; ///< hit nucleon 4p
  double fHitNucRad;          ///< hit nucleon position

ClassDef(Target,2)
};

}      // genie namespace

#endif // _TARGET_H_

//____________________________________________________________________________
/*!

\class    genie::ProcessInfo

\brief    A class encapsulating an enumeration of interaction types (EM,
          Weak-CC, Weak-NC) and scattering types (Elastic, Quasi Elastic,
          Deep Inelastic, Resonant Single Pion Production, Coherent Pion
          Production).

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  May 04, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PROCESS_INFO_H_
#define _PROCESS_INFO_H_

#include <iostream>
#include <string>

#include <TObject.h>

#include "Interaction/InteractionType.h"
#include "Interaction/ScatteringType.h"

using std::ostream;
using std::string;

namespace genie {

class ProcessInfo;
ostream & operator << (ostream& stream, const ProcessInfo & proc);

class ProcessInfo : public TObject {

public:
  using TObject::Print; // suppress clang 'hides overloaded virtual function [-Woverloaded-virtual]' warnings
  using TObject::Copy;
  using TObject::Compare;

  ProcessInfo();
  ProcessInfo(ScatteringType_t sc_type, InteractionType_t  int_type);
  ProcessInfo(const ProcessInfo & proc);
 ~ProcessInfo();

  // Set process information
  void Set(ScatteringType_t sc_type, InteractionType_t  int_type);

  // Query for process information
  bool IsQuasiElastic      (void) const;
  bool IsDeepInelastic     (void) const;
  bool IsResonant          (void) const;
  bool IsCoherent          (void) const;
  bool IsCoherentElas      (void) const;
  bool IsSingleKaon        (void) const;
  bool IsElectronScattering(void) const;
  bool IsNuElectronElastic (void) const;
  bool IsInverseMuDecay    (void) const;
  bool IsIMDAnnihilation   (void) const;
  bool IsInverseBetaDecay  (void) const;
  bool IsGlashowResonance  (void) const;
  bool IsAMNuGamma         (void) const;
  bool IsMEC               (void) const;
  bool IsDiffractive       (void) const;
  bool IsEM                (void) const;
  bool IsWeak              (void) const;
  bool IsWeakCC            (void) const;
  bool IsWeakNC            (void) const;
  bool IsWeakMix           (void) const;

  // Get scattering and interaction type enumerations
  ScatteringType_t  ScatteringTypeId  (void) const;
  InteractionType_t InteractionTypeId (void) const;

  // Get scattering and interaction types as strings
  string ScatteringTypeAsString  (void) const;
  string InteractionTypeAsString (void) const;

  // Copy, reset, compare, print itself and build string code
  void   Reset    (void);
  void   Copy     (const ProcessInfo & proc);
  bool   Compare  (const ProcessInfo & proc) const;
  string AsString (void) const;
  void   Print    (ostream & stream) const;

  bool             operator == (const ProcessInfo & proc) const;
  ProcessInfo &    operator =  (const ProcessInfo & proc);
  friend ostream & operator << (ostream& stream, const ProcessInfo & proc);

private:

  ScatteringType_t  fScatteringType;  ///< scattering type  (QEL, RES, DIS, ...)
  InteractionType_t fInteractionType; ///< interaction type (Weak CC/NC, E/M, ...)

ClassDef(ProcessInfo,1)
};

}        // genie namespace

#endif   // _PROCESS_INFO_H_
//____________________________________________________________________________
/*!

\class    genie::exceptions::InteractionException

\brief    Exception used inside Interaction classes.

\author   Jeremy Wolcott <jwolcott \at fnal.gov>
          Tufts University

\created  July 15, 2016

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef INTERACTIONEXCEPTION_H_
#define INTERACTIONEXCEPTION_H_

#include <exception>
#include <iostream>
#include <string>

namespace genie
{
  namespace exceptions
  {
    class InteractionException : public std::exception
    {
      public:
        InteractionException ();
        InteractionException (const std::string & reason);
        ~InteractionException() throw() {};

        void                Print       (std::ostream & stream) const;
        const std::string & ShowReason  ()                      const { return fReason;     }

        // from std::exception
        const char * what  () const throw()  { return this->fReason.c_str(); };

        friend std::ostream & operator << (std::ostream & stream, const InteractionException & exception);

      private:
        std::string fReason;
    }; /* class InteractionException */

  } /* namespace exceptions */
} /* namespace genie */

std::ostream & operator<< (std::ostream& stream, const genie::exceptions::InteractionException & exc);

#endif /* INTERACTIONEXCEPTION_H_ */

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::InitialState", payloadCode, "@",
"genie::Interaction", payloadCode, "@",
"genie::KPhaseSpace", payloadCode, "@",
"genie::Kinematics", payloadCode, "@",
"genie::ProcessInfo", payloadCode, "@",
"genie::Target", payloadCode, "@",
"genie::XclsTag", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGInteraction",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGInteraction_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGInteraction_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGInteraction() {
  TriggerDictionaryInitialization_libGInteraction_Impl();
}
