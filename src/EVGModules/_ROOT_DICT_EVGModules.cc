// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME _ROOT_DICT_EVGModules

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
#include "HadronTransporter.h"
#include "NucBindEnergyAggregator.h"
#include "KineGeneratorWithCache.h"
#include "UnstableParticleDecayer.h"
#include "HadronicSystemGenerator.h"
#include "FermiMover.h"
#include "PrimaryLeptonGenerator.h"
#include "NucDeExcitationSim.h"
#include "InitialStateAppender.h"
#include "VertexGenerator.h"
#include "PauliBlocker.h"

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
   static TClass *geniecLcLHadronTransporter_Dictionary();
   static void geniecLcLHadronTransporter_TClassManip(TClass*);
   static void *new_geniecLcLHadronTransporter(void *p = 0);
   static void *newArray_geniecLcLHadronTransporter(Long_t size, void *p);
   static void delete_geniecLcLHadronTransporter(void *p);
   static void deleteArray_geniecLcLHadronTransporter(void *p);
   static void destruct_geniecLcLHadronTransporter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::HadronTransporter*)
   {
      ::genie::HadronTransporter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::HadronTransporter));
      static ::ROOT::TGenericClassInfo 
         instance("genie::HadronTransporter", "", 33,
                  typeid(::genie::HadronTransporter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLHadronTransporter_Dictionary, isa_proxy, 0,
                  sizeof(::genie::HadronTransporter) );
      instance.SetNew(&new_geniecLcLHadronTransporter);
      instance.SetNewArray(&newArray_geniecLcLHadronTransporter);
      instance.SetDelete(&delete_geniecLcLHadronTransporter);
      instance.SetDeleteArray(&deleteArray_geniecLcLHadronTransporter);
      instance.SetDestructor(&destruct_geniecLcLHadronTransporter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::HadronTransporter*)
   {
      return GenerateInitInstanceLocal((::genie::HadronTransporter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::HadronTransporter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLHadronTransporter_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::HadronTransporter*)0x0)->GetClass();
      geniecLcLHadronTransporter_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLHadronTransporter_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLNucBindEnergyAggregator_Dictionary();
   static void geniecLcLNucBindEnergyAggregator_TClassManip(TClass*);
   static void *new_geniecLcLNucBindEnergyAggregator(void *p = 0);
   static void *newArray_geniecLcLNucBindEnergyAggregator(Long_t size, void *p);
   static void delete_geniecLcLNucBindEnergyAggregator(void *p);
   static void deleteArray_geniecLcLNucBindEnergyAggregator(void *p);
   static void destruct_geniecLcLNucBindEnergyAggregator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::NucBindEnergyAggregator*)
   {
      ::genie::NucBindEnergyAggregator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::NucBindEnergyAggregator));
      static ::ROOT::TGenericClassInfo 
         instance("genie::NucBindEnergyAggregator", "", 92,
                  typeid(::genie::NucBindEnergyAggregator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLNucBindEnergyAggregator_Dictionary, isa_proxy, 0,
                  sizeof(::genie::NucBindEnergyAggregator) );
      instance.SetNew(&new_geniecLcLNucBindEnergyAggregator);
      instance.SetNewArray(&newArray_geniecLcLNucBindEnergyAggregator);
      instance.SetDelete(&delete_geniecLcLNucBindEnergyAggregator);
      instance.SetDeleteArray(&deleteArray_geniecLcLNucBindEnergyAggregator);
      instance.SetDestructor(&destruct_geniecLcLNucBindEnergyAggregator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::NucBindEnergyAggregator*)
   {
      return GenerateInitInstanceLocal((::genie::NucBindEnergyAggregator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::NucBindEnergyAggregator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLNucBindEnergyAggregator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::NucBindEnergyAggregator*)0x0)->GetClass();
      geniecLcLNucBindEnergyAggregator_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLNucBindEnergyAggregator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLKineGeneratorWithCache_Dictionary();
   static void geniecLcLKineGeneratorWithCache_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::KineGeneratorWithCache*)
   {
      ::genie::KineGeneratorWithCache *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::KineGeneratorWithCache));
      static ::ROOT::TGenericClassInfo 
         instance("genie::KineGeneratorWithCache", "", 160,
                  typeid(::genie::KineGeneratorWithCache), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLKineGeneratorWithCache_Dictionary, isa_proxy, 0,
                  sizeof(::genie::KineGeneratorWithCache) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::KineGeneratorWithCache*)
   {
      return GenerateInitInstanceLocal((::genie::KineGeneratorWithCache*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::KineGeneratorWithCache*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLKineGeneratorWithCache_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::KineGeneratorWithCache*)0x0)->GetClass();
      geniecLcLKineGeneratorWithCache_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLKineGeneratorWithCache_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLUnstableParticleDecayer_Dictionary();
   static void geniecLcLUnstableParticleDecayer_TClassManip(TClass*);
   static void *new_geniecLcLUnstableParticleDecayer(void *p = 0);
   static void *newArray_geniecLcLUnstableParticleDecayer(Long_t size, void *p);
   static void delete_geniecLcLUnstableParticleDecayer(void *p);
   static void deleteArray_geniecLcLUnstableParticleDecayer(void *p);
   static void destruct_geniecLcLUnstableParticleDecayer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::UnstableParticleDecayer*)
   {
      ::genie::UnstableParticleDecayer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::UnstableParticleDecayer));
      static ::ROOT::TGenericClassInfo 
         instance("genie::UnstableParticleDecayer", "", 228,
                  typeid(::genie::UnstableParticleDecayer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLUnstableParticleDecayer_Dictionary, isa_proxy, 0,
                  sizeof(::genie::UnstableParticleDecayer) );
      instance.SetNew(&new_geniecLcLUnstableParticleDecayer);
      instance.SetNewArray(&newArray_geniecLcLUnstableParticleDecayer);
      instance.SetDelete(&delete_geniecLcLUnstableParticleDecayer);
      instance.SetDeleteArray(&deleteArray_geniecLcLUnstableParticleDecayer);
      instance.SetDestructor(&destruct_geniecLcLUnstableParticleDecayer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::UnstableParticleDecayer*)
   {
      return GenerateInitInstanceLocal((::genie::UnstableParticleDecayer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::UnstableParticleDecayer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLUnstableParticleDecayer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::UnstableParticleDecayer*)0x0)->GetClass();
      geniecLcLUnstableParticleDecayer_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLUnstableParticleDecayer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLHadronicSystemGenerator_Dictionary();
   static void geniecLcLHadronicSystemGenerator_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::HadronicSystemGenerator*)
   {
      ::genie::HadronicSystemGenerator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::HadronicSystemGenerator));
      static ::ROOT::TGenericClassInfo 
         instance("genie::HadronicSystemGenerator", "", 296,
                  typeid(::genie::HadronicSystemGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLHadronicSystemGenerator_Dictionary, isa_proxy, 0,
                  sizeof(::genie::HadronicSystemGenerator) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::HadronicSystemGenerator*)
   {
      return GenerateInitInstanceLocal((::genie::HadronicSystemGenerator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::HadronicSystemGenerator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLHadronicSystemGenerator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::HadronicSystemGenerator*)0x0)->GetClass();
      geniecLcLHadronicSystemGenerator_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLHadronicSystemGenerator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLFermiMover_Dictionary();
   static void geniecLcLFermiMover_TClassManip(TClass*);
   static void *new_geniecLcLFermiMover(void *p = 0);
   static void *newArray_geniecLcLFermiMover(Long_t size, void *p);
   static void delete_geniecLcLFermiMover(void *p);
   static void deleteArray_geniecLcLFermiMover(void *p);
   static void destruct_geniecLcLFermiMover(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::FermiMover*)
   {
      ::genie::FermiMover *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::FermiMover));
      static ::ROOT::TGenericClassInfo 
         instance("genie::FermiMover", "", 360,
                  typeid(::genie::FermiMover), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLFermiMover_Dictionary, isa_proxy, 0,
                  sizeof(::genie::FermiMover) );
      instance.SetNew(&new_geniecLcLFermiMover);
      instance.SetNewArray(&newArray_geniecLcLFermiMover);
      instance.SetDelete(&delete_geniecLcLFermiMover);
      instance.SetDeleteArray(&deleteArray_geniecLcLFermiMover);
      instance.SetDestructor(&destruct_geniecLcLFermiMover);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::FermiMover*)
   {
      return GenerateInitInstanceLocal((::genie::FermiMover*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::FermiMover*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLFermiMover_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::FermiMover*)0x0)->GetClass();
      geniecLcLFermiMover_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLFermiMover_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPrimaryLeptonGenerator_Dictionary();
   static void geniecLcLPrimaryLeptonGenerator_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PrimaryLeptonGenerator*)
   {
      ::genie::PrimaryLeptonGenerator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PrimaryLeptonGenerator));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PrimaryLeptonGenerator", "", 423,
                  typeid(::genie::PrimaryLeptonGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPrimaryLeptonGenerator_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PrimaryLeptonGenerator) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PrimaryLeptonGenerator*)
   {
      return GenerateInitInstanceLocal((::genie::PrimaryLeptonGenerator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PrimaryLeptonGenerator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPrimaryLeptonGenerator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PrimaryLeptonGenerator*)0x0)->GetClass();
      geniecLcLPrimaryLeptonGenerator_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPrimaryLeptonGenerator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLNucDeExcitationSim_Dictionary();
   static void geniecLcLNucDeExcitationSim_TClassManip(TClass*);
   static void *new_geniecLcLNucDeExcitationSim(void *p = 0);
   static void *newArray_geniecLcLNucDeExcitationSim(Long_t size, void *p);
   static void delete_geniecLcLNucDeExcitationSim(void *p);
   static void deleteArray_geniecLcLNucDeExcitationSim(void *p);
   static void destruct_geniecLcLNucDeExcitationSim(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::NucDeExcitationSim*)
   {
      ::genie::NucDeExcitationSim *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::NucDeExcitationSim));
      static ::ROOT::TGenericClassInfo 
         instance("genie::NucDeExcitationSim", "", 490,
                  typeid(::genie::NucDeExcitationSim), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLNucDeExcitationSim_Dictionary, isa_proxy, 0,
                  sizeof(::genie::NucDeExcitationSim) );
      instance.SetNew(&new_geniecLcLNucDeExcitationSim);
      instance.SetNewArray(&newArray_geniecLcLNucDeExcitationSim);
      instance.SetDelete(&delete_geniecLcLNucDeExcitationSim);
      instance.SetDeleteArray(&deleteArray_geniecLcLNucDeExcitationSim);
      instance.SetDestructor(&destruct_geniecLcLNucDeExcitationSim);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::NucDeExcitationSim*)
   {
      return GenerateInitInstanceLocal((::genie::NucDeExcitationSim*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::NucDeExcitationSim*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLNucDeExcitationSim_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::NucDeExcitationSim*)0x0)->GetClass();
      geniecLcLNucDeExcitationSim_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLNucDeExcitationSim_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLInitialStateAppender_Dictionary();
   static void geniecLcLInitialStateAppender_TClassManip(TClass*);
   static void *new_geniecLcLInitialStateAppender(void *p = 0);
   static void *newArray_geniecLcLInitialStateAppender(Long_t size, void *p);
   static void delete_geniecLcLInitialStateAppender(void *p);
   static void deleteArray_geniecLcLInitialStateAppender(void *p);
   static void destruct_geniecLcLInitialStateAppender(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::InitialStateAppender*)
   {
      ::genie::InitialStateAppender *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::InitialStateAppender));
      static ::ROOT::TGenericClassInfo 
         instance("genie::InitialStateAppender", "", 536,
                  typeid(::genie::InitialStateAppender), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLInitialStateAppender_Dictionary, isa_proxy, 0,
                  sizeof(::genie::InitialStateAppender) );
      instance.SetNew(&new_geniecLcLInitialStateAppender);
      instance.SetNewArray(&newArray_geniecLcLInitialStateAppender);
      instance.SetDelete(&delete_geniecLcLInitialStateAppender);
      instance.SetDeleteArray(&deleteArray_geniecLcLInitialStateAppender);
      instance.SetDestructor(&destruct_geniecLcLInitialStateAppender);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::InitialStateAppender*)
   {
      return GenerateInitInstanceLocal((::genie::InitialStateAppender*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::InitialStateAppender*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLInitialStateAppender_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::InitialStateAppender*)0x0)->GetClass();
      geniecLcLInitialStateAppender_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLInitialStateAppender_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLVertexGenerator_Dictionary();
   static void geniecLcLVertexGenerator_TClassManip(TClass*);
   static void *new_geniecLcLVertexGenerator(void *p = 0);
   static void *newArray_geniecLcLVertexGenerator(Long_t size, void *p);
   static void delete_geniecLcLVertexGenerator(void *p);
   static void deleteArray_geniecLcLVertexGenerator(void *p);
   static void destruct_geniecLcLVertexGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::VertexGenerator*)
   {
      ::genie::VertexGenerator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::VertexGenerator));
      static ::ROOT::TGenericClassInfo 
         instance("genie::VertexGenerator", "", 587,
                  typeid(::genie::VertexGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLVertexGenerator_Dictionary, isa_proxy, 0,
                  sizeof(::genie::VertexGenerator) );
      instance.SetNew(&new_geniecLcLVertexGenerator);
      instance.SetNewArray(&newArray_geniecLcLVertexGenerator);
      instance.SetDelete(&delete_geniecLcLVertexGenerator);
      instance.SetDeleteArray(&deleteArray_geniecLcLVertexGenerator);
      instance.SetDestructor(&destruct_geniecLcLVertexGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::VertexGenerator*)
   {
      return GenerateInitInstanceLocal((::genie::VertexGenerator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::VertexGenerator*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLVertexGenerator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::VertexGenerator*)0x0)->GetClass();
      geniecLcLVertexGenerator_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLVertexGenerator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *geniecLcLPauliBlocker_Dictionary();
   static void geniecLcLPauliBlocker_TClassManip(TClass*);
   static void *new_geniecLcLPauliBlocker(void *p = 0);
   static void *newArray_geniecLcLPauliBlocker(Long_t size, void *p);
   static void delete_geniecLcLPauliBlocker(void *p);
   static void deleteArray_geniecLcLPauliBlocker(void *p);
   static void destruct_geniecLcLPauliBlocker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::PauliBlocker*)
   {
      ::genie::PauliBlocker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::genie::PauliBlocker));
      static ::ROOT::TGenericClassInfo 
         instance("genie::PauliBlocker", "", 644,
                  typeid(::genie::PauliBlocker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &geniecLcLPauliBlocker_Dictionary, isa_proxy, 0,
                  sizeof(::genie::PauliBlocker) );
      instance.SetNew(&new_geniecLcLPauliBlocker);
      instance.SetNewArray(&newArray_geniecLcLPauliBlocker);
      instance.SetDelete(&delete_geniecLcLPauliBlocker);
      instance.SetDeleteArray(&deleteArray_geniecLcLPauliBlocker);
      instance.SetDestructor(&destruct_geniecLcLPauliBlocker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::PauliBlocker*)
   {
      return GenerateInitInstanceLocal((::genie::PauliBlocker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::PauliBlocker*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *geniecLcLPauliBlocker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::genie::PauliBlocker*)0x0)->GetClass();
      geniecLcLPauliBlocker_TClassManip(theClass);
   return theClass;
   }

   static void geniecLcLPauliBlocker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLHadronTransporter(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::HadronTransporter : new ::genie::HadronTransporter;
   }
   static void *newArray_geniecLcLHadronTransporter(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::HadronTransporter[nElements] : new ::genie::HadronTransporter[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLHadronTransporter(void *p) {
      delete ((::genie::HadronTransporter*)p);
   }
   static void deleteArray_geniecLcLHadronTransporter(void *p) {
      delete [] ((::genie::HadronTransporter*)p);
   }
   static void destruct_geniecLcLHadronTransporter(void *p) {
      typedef ::genie::HadronTransporter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::HadronTransporter

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLNucBindEnergyAggregator(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::NucBindEnergyAggregator : new ::genie::NucBindEnergyAggregator;
   }
   static void *newArray_geniecLcLNucBindEnergyAggregator(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::NucBindEnergyAggregator[nElements] : new ::genie::NucBindEnergyAggregator[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLNucBindEnergyAggregator(void *p) {
      delete ((::genie::NucBindEnergyAggregator*)p);
   }
   static void deleteArray_geniecLcLNucBindEnergyAggregator(void *p) {
      delete [] ((::genie::NucBindEnergyAggregator*)p);
   }
   static void destruct_geniecLcLNucBindEnergyAggregator(void *p) {
      typedef ::genie::NucBindEnergyAggregator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::NucBindEnergyAggregator

namespace ROOT {
} // end of namespace ROOT for class ::genie::KineGeneratorWithCache

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLUnstableParticleDecayer(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::UnstableParticleDecayer : new ::genie::UnstableParticleDecayer;
   }
   static void *newArray_geniecLcLUnstableParticleDecayer(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::UnstableParticleDecayer[nElements] : new ::genie::UnstableParticleDecayer[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLUnstableParticleDecayer(void *p) {
      delete ((::genie::UnstableParticleDecayer*)p);
   }
   static void deleteArray_geniecLcLUnstableParticleDecayer(void *p) {
      delete [] ((::genie::UnstableParticleDecayer*)p);
   }
   static void destruct_geniecLcLUnstableParticleDecayer(void *p) {
      typedef ::genie::UnstableParticleDecayer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::UnstableParticleDecayer

namespace ROOT {
} // end of namespace ROOT for class ::genie::HadronicSystemGenerator

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLFermiMover(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::FermiMover : new ::genie::FermiMover;
   }
   static void *newArray_geniecLcLFermiMover(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::FermiMover[nElements] : new ::genie::FermiMover[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLFermiMover(void *p) {
      delete ((::genie::FermiMover*)p);
   }
   static void deleteArray_geniecLcLFermiMover(void *p) {
      delete [] ((::genie::FermiMover*)p);
   }
   static void destruct_geniecLcLFermiMover(void *p) {
      typedef ::genie::FermiMover current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::FermiMover

namespace ROOT {
} // end of namespace ROOT for class ::genie::PrimaryLeptonGenerator

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLNucDeExcitationSim(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::NucDeExcitationSim : new ::genie::NucDeExcitationSim;
   }
   static void *newArray_geniecLcLNucDeExcitationSim(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::NucDeExcitationSim[nElements] : new ::genie::NucDeExcitationSim[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLNucDeExcitationSim(void *p) {
      delete ((::genie::NucDeExcitationSim*)p);
   }
   static void deleteArray_geniecLcLNucDeExcitationSim(void *p) {
      delete [] ((::genie::NucDeExcitationSim*)p);
   }
   static void destruct_geniecLcLNucDeExcitationSim(void *p) {
      typedef ::genie::NucDeExcitationSim current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::NucDeExcitationSim

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLInitialStateAppender(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InitialStateAppender : new ::genie::InitialStateAppender;
   }
   static void *newArray_geniecLcLInitialStateAppender(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::InitialStateAppender[nElements] : new ::genie::InitialStateAppender[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLInitialStateAppender(void *p) {
      delete ((::genie::InitialStateAppender*)p);
   }
   static void deleteArray_geniecLcLInitialStateAppender(void *p) {
      delete [] ((::genie::InitialStateAppender*)p);
   }
   static void destruct_geniecLcLInitialStateAppender(void *p) {
      typedef ::genie::InitialStateAppender current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::InitialStateAppender

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLVertexGenerator(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::VertexGenerator : new ::genie::VertexGenerator;
   }
   static void *newArray_geniecLcLVertexGenerator(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::VertexGenerator[nElements] : new ::genie::VertexGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLVertexGenerator(void *p) {
      delete ((::genie::VertexGenerator*)p);
   }
   static void deleteArray_geniecLcLVertexGenerator(void *p) {
      delete [] ((::genie::VertexGenerator*)p);
   }
   static void destruct_geniecLcLVertexGenerator(void *p) {
      typedef ::genie::VertexGenerator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::VertexGenerator

namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLPauliBlocker(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PauliBlocker : new ::genie::PauliBlocker;
   }
   static void *newArray_geniecLcLPauliBlocker(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::genie::PauliBlocker[nElements] : new ::genie::PauliBlocker[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLPauliBlocker(void *p) {
      delete ((::genie::PauliBlocker*)p);
   }
   static void deleteArray_geniecLcLPauliBlocker(void *p) {
      delete [] ((::genie::PauliBlocker*)p);
   }
   static void destruct_geniecLcLPauliBlocker(void *p) {
      typedef ::genie::PauliBlocker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::PauliBlocker

namespace {
  void TriggerDictionaryInitialization_libGEVGModules_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"EVGModules",
"Types",
"Interfaces",
"GENIE",
"../Types",
"../Interfaces",
"GENIE/EVGModules",
"GENIE/Types",
"GENIE/Interfaces",
"../include",
"../include/GENIE",
"../include/GENIE/EVGModules",
"../include/GENIE/Types",
"../include/GENIE/Interfaces",
"/cvmfs/larsoft.opensciencegrid.org/products/libxml2/v2_9_9/Linux64bit+3.10-2.17-prof/include/libxml2",
"/cvmfs/larsoft.opensciencegrid.org/products/log4cpp/v1_1_3b/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/cvmfs/larsoft.opensciencegrid.org/products/lhapdf/v5_9_1k/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/inuse//Generator/src/",
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+3.10-2.17-e17-prof/include",
"/minerva/app/users/xlu/software/GENIE/v2.12.10/Generator/src/EVGModules/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGEVGModules dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace genie{class HadronTransporter;}
namespace genie{class NucBindEnergyAggregator;}
namespace genie{class KineGeneratorWithCache;}
namespace genie{class UnstableParticleDecayer;}
namespace genie{class HadronicSystemGenerator;}
namespace genie{class FermiMover;}
namespace genie{class PrimaryLeptonGenerator;}
namespace genie{class NucDeExcitationSim;}
namespace genie{class InitialStateAppender;}
namespace genie{class VertexGenerator;}
namespace genie{class PauliBlocker;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGEVGModules dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
//____________________________________________________________________________
/*!

\class    genie::HadronTransporter

\brief    Intranuclear hadronic transport module. 
          It is being used to transfer all hadrons outside the nucleus without
          rescattering -if rescattering is switched off- or to call one of the 
          supported hadron transport MCs -if rescattering is switched on-
         
\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk> STFC, Rutherford Lab

\created  September 14, 2006

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _HADRON_TRANSPORTER_H_
#define _HADRON_TRANSPORTER_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class HadronTransporter : public EventRecordVisitorI {

public :
  HadronTransporter();
  HadronTransporter(string config);
 ~HadronTransporter();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  // override the Algorithm::Configure methods to load configuration
  // data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

private:
  void  LoadConfig                (void);
  void  TransportInTransparentNuc (GHepRecord * ev) const;

  bool  fEnabled;                              ///< hadron transport enabled?
  const EventRecordVisitorI * fHadTranspModel; ///< hadron transport MC to use

};

}      // genie namespace
#endif // _HADRON_TRANSPORTER_H_
//____________________________________________________________________________
/*!

\class    genie::NucBindEnergyAggregator

\brief    A nuclear binding energy 'collector' which visits the event record,
          finds nucleons originating from within a nuclei and subtracts the
          binding energy they had in the nucleus.
          To record this action in the event record a hypothetical BINDINO is
          added to the event record.
          Is a concerete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  November 19, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _NUCLEAR_BINDING_ENERGY_AGGREGATOR_H_
#define _NUCLEAR_BINDING_ENERGY_AGGREGATOR_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class GHepParticle;

class NucBindEnergyAggregator : public EventRecordVisitorI {

public :
  NucBindEnergyAggregator();
  NucBindEnergyAggregator(string config);
 ~NucBindEnergyAggregator();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:
  void LoadConfig (void);
  //GHepParticle * FindMotherNucleus(int ipos, GHepRecord * event_rec) const;

  bool fAllowRecombination; 
};

}      // genie namespace

#endif // _NUCLEAR_BINDING_ENERGY_AGGREGATOR_H_
//____________________________________________________________________________
/*!

\class    genie::KineGeneratorWithCache

\brief    Abstract class. Provides a data caching mechanism for for concrete
          implementations of the EventRecordVisitorI interface, generating
          kinematics and wishing to cache maximum differential xsecs.

          This class provides some common implementation for handling
          (retrieving, creating, searching, adding to) the cache.
          The various super-classes should implement the ComputeMaxXSec(...)
          method for computing the maximum xsec in case it has not already
          being pushed into the cache at a previous iteration.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  December 15, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _KINE_GENERATOR_WITH_CACHE_H_
#define _KINE_GENERATOR_WITH_CACHE_H_

#include <string>

#include "Base/XSecAlgorithmI.h"
#include "EVGCore/EventRecordVisitorI.h"
#include "Utils/Range1.h"

using std::string;

namespace genie {

class CacheBranchFx;
class XSecAlgorithmI;

class KineGeneratorWithCache : public EventRecordVisitorI {

protected:
  KineGeneratorWithCache();
  KineGeneratorWithCache(string name);
  KineGeneratorWithCache(string name, string config);
  ~KineGeneratorWithCache();

  virtual double ComputeMaxXSec (const Interaction * in) const = 0;
  virtual double MaxXSec        (GHepRecord * evrec) const;
  virtual double FindMaxXSec    (const Interaction * in) const;
  virtual void   CacheMaxXSec   (const Interaction * in, double xsec) const;
  virtual double Energy         (const Interaction * in) const;

  virtual CacheBranchFx * AccessCacheBranch (const Interaction * in) const;

  virtual void AssertXSecLimits (const Interaction * in, double xsec, double xsec_max) const;

  mutable const XSecAlgorithmI * fXSecModel;

  double fSafetyFactor;         ///< maxxsec -> maxxsec * safety_factor
  double fMaxXSecDiffTolerance; ///< max{100*(xsec-maxxsec)/.5*(xsec+maxxsec)} if xsec>maxxsec
  double fEMin;                 ///< min E for which maxxsec is cached - forcing explicit calc.
  bool   fGenerateUniformly;    ///< uniform over allowed phase space + event weight?
};

}      // genie namespace

#endif // _KINE_GENERATOR_WITH_CACHE_H_
//____________________________________________________________________________
/*!

\class    genie::UnstableParticleDecayer

\brief    Decays unstable particles found in the generated event record.
          After the interaction vertex generation it visits the event record
          and it decays the unstable particles using an externally specified
          particle decay model. The decay products are added to the event
          record and the status of parent particle is toggled. \n
          Is a concerete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  November 17, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _UNSTABLE_PARTICLE_DECAYER_H_
#define _UNSTABLE_PARTICLE_DECAYER_H_

#include <vector>

#include "EVGCore/EventRecordVisitorI.h"
#include "PDG/PDGCodeList.h"

using std::vector;

namespace genie {

class GHepParticle;
class DecayModelI;

class UnstableParticleDecayer : public EventRecordVisitorI {

public :

  UnstableParticleDecayer();
  UnstableParticleDecayer(string config);
  ~UnstableParticleDecayer();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void  LoadConfig        (void);
  bool  ToBeDecayed       (GHepParticle * particle) const;
  bool  IsUnstable        (GHepParticle * particle) const;
  void  CopyToEventRecord (TClonesArray * dp, GHepRecord * ev, GHepParticle * p,
                           int mother_pos, bool in_nucleus) const;

  bool                           fRunBefHadroTransp;   ///< is invoked before or after hadron transport?
  PDGCodeList                    fParticlesToDecay;    ///< list of particles to be decayed
  PDGCodeList                    fParticlesNotToDecay; ///< list of particles for which decay is inhibited
  vector <const DecayModelI *> * fDecayers;            ///< list of all specified decayers
  mutable const DecayModelI *    fCurrDecayer;         ///< current selected decayer

  //double fMaxLifetime; ///< define "unstable" particle
};

}      // genie namespace

#endif // _UNSTABLE_PARTICLE_DECAYER_H_
//____________________________________________________________________________
/*!

\class    genie::HadronicSystemGenerator

\brief    Abstract class. Is used to pass some commonly recurring methods to
          all concrete implementations of the EventRecordVisitorI interface
          generating the hadronic system for a specific processes (QEL,DIS,
          RES,...)

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  July 16, 2005

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _HADRONIC_SYSTEM_GENERATOR_H_
#define _HADRONIC_SYSTEM_GENERATOR_H_

#include <TLorentzVector.h>
#include <TVector3.h>

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class HadronicSystemGenerator : public EventRecordVisitorI {

public :

  // Do not implement the EventRecordVisitorI interface.
  // Leave it for the concrete subclasses


  // Common methods for all concrete subclasses

  void AddTargetNucleusRemnant  (GHepRecord * event_rec) const;
  void AddFinalHadronicSyst     (GHepRecord * event_rec) const;
  void PreHadronTransportDecays (GHepRecord * event_rec) const;

  TLorentzVector Hadronic4pLAB       (GHepRecord * event_rec) const;
  TLorentzVector MomentumTransferLAB (GHepRecord * event_rec) const;
  TVector3       HCM2LAB             (GHepRecord * event_rec) const;
  int            HadronShowerCharge  (GHepRecord * event_rec) const;
  int            ResonanceCharge     (GHepRecord * event_rec) const;

protected:

  // Abstract base class
  HadronicSystemGenerator();
  HadronicSystemGenerator(string name);
  HadronicSystemGenerator(string name, string config);
 ~HadronicSystemGenerator();

  const EventRecordVisitorI * fPreINukeDecayer;
};

}      // genie namespace

#endif // _HADRONIC_SYSTEM_GENERATOR_H_
//____________________________________________________________________________
/*!

\class    genie::FermiMover

\brief    It visits the event record & computes a Fermi motion momentum for
          initial state nucleons bound in nuclei.
          Is a concrete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  October 08, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _FERMI_MOVER_H_
#define _FERMI_MOVER_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class NuclearModelI;

class FermiMover : public EventRecordVisitorI {

public :
  FermiMover();
  FermiMover(string config);
 ~FermiMover();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void KickHitNucleon          (GHepRecord * evrec) const; ///< give hit nucleon a momentum
  void Emit2ndNucleonFromSRC   (GHepRecord * evrec,
                                const int eject_nucleon_pdg) const;
                                ///^ emit a 2nd nucleon due to short range corellations
  void AddTargetNucleusRemnant (GHepRecord * evrec) const; ///< add a recoiled nucleus remnant

  void LoadConfig (void);

  bool  fKeepNuclOnMassShell;          ///< keep hit bound nucleon on the mass shell?
  bool  fSRCRecoilNucleon;             ///< simulate recoil nucleon due to short range corellation?
  const NuclearModelI *  fNuclModel;   ///< nuclear model
};

}      // genie namespace
#endif // _FERMI_MOVER_H_
//____________________________________________________________________________
/*!

\class    genie::PrimaryLeptonGenerator

\brief    Abstract class. Is used to pass common implementation to concrete
          implementations of the EventRecordVisitorI interface generating the
          primary lepton for a specific processes (QEL,DIS,RES,IMD,...)

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  October 03, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PRIMARY_LEPTON_GENERATOR_H_
#define _PRIMARY_LEPTON_GENERATOR_H_

class TVector3;
class TLorentzVector;

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class PrimaryLeptonGenerator : public EventRecordVisitorI {

public :

  //-- Standard EventRecordVisitorI interface implementation
  virtual void ProcessEventRecord(GHepRecord * evrec) const;

  //-- Common methods for all concrete PrimaryLeptonGenerator-type
  //   EventRecordVisitors
  virtual void     SetPolarization  (GHepRecord * ev) const;
  virtual TVector3 NucRestFrame2Lab (GHepRecord * ev) const;
  virtual void     AddToEventRecord (
              GHepRecord * ev, int pdgc, const TLorentzVector & p4) const;

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string config);

protected:

  //-- Abstract class - Can only be instantiated by its children.
  PrimaryLeptonGenerator();
  PrimaryLeptonGenerator(string name);
  PrimaryLeptonGenerator(string name, string config);
  virtual ~PrimaryLeptonGenerator();

  void LoadConfig(void);

  bool fApplyCoulombCorrection;
};

}      // genie namespace

#endif // _PRIMARY_LEPTON_GENERATOR_H_
//____________________________________________________________________________
/*!

\class    genie::NucDeExcitationSim

\brief    Generates nuclear de-excitation gamma rays

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\ref      16O: 
           H.Ejiri,Phys.Rev.C48,1442(1993); 
           K.Kobayashi et al., Nucl.Phys.B (proc Suppl) 139 (2005)

\created  March 05, 2008

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _NUCLEAR_DEEXCITATION_H_
#define _NUCLEAR_DEEXCITATION_H_

#include <TLorentzVector.h>

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class NucDeExcitationSim : public EventRecordVisitorI {

public :
  NucDeExcitationSim();
  NucDeExcitationSim(string config);
 ~NucDeExcitationSim();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord (GHepRecord * evrec) const;

private:
  void           OxygenTargetSim      (GHepRecord * evrec) const;
  void           AddPhoton            (GHepRecord * evrec, double E0, double t) const;
  double         PhotonEnergySmearing (double E0, double t) const;
  TLorentzVector Photon4P             (double E) const;
};

}      // genie namespace
#endif // _NUCLEAR_DEEXCITATION_H_
//____________________________________________________________________________
/*!

\class    genie::InitialStateAppender

\brief    Appends the initial state information to the event record.
          Is a concerete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  October 04, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _INITIAL_STATE_APPENDER_H_
#define _INITIAL_STATE_APPENDER_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class InitialStateAppender : public EventRecordVisitorI {

public :

  InitialStateAppender();
  InitialStateAppender(string config);
  ~InitialStateAppender();

  //-- implement the EventRecordVisitorI interface

  void ProcessEventRecord(GHepRecord * event_rec) const;

private :

  void AddNeutrino       (GHepRecord * event_rec) const;
  void AddNucleus        (GHepRecord * event_rec) const;
  void AddStruckParticle (GHepRecord * event_rec) const;

};

}      // genie namespace

#endif // _INITIAL_STATE_APPENDER_H_
//____________________________________________________________________________
/*!

\class    genie::VertexGenerator

\brief    

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  June 16, 2007

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _VERTEX_GENERATOR_H_
#define _VERTEX_GENERATOR_H_

#include "EVGCore/EventRecordVisitorI.h"
#include "GHEP/GHepParticle.h"
#include "Interaction/Interaction.h"

namespace genie {

class VertexGenerator : public EventRecordVisitorI {

public :
  VertexGenerator();
  VertexGenerator(string config);
 ~VertexGenerator();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord (GHepRecord * event_rec) const;

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

  //-- Generate the vertex position
  //   public so other classes can reuse this code to generate a position
  TVector3 GenerateVertex(const Interaction * in,double A) const;

private:
  void  LoadConfig (void);

  int    fVtxGenMethod; ///< vtx generation method (0: uniform, 1: according to nuclear density [def])
  double fR0;           ///< parameter controlling nuclear sizes
};

}      // genie namespace
#endif // _VERTEX_GENERATOR_H_
//____________________________________________________________________________
/*!

\class    genie::PauliBlocker

\brief    Examines whether the generated event should be Pauli blocked.
          Is a concerete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  October 08, 2004

\cpright  Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _PAULI_BLOCKER_H_
#define _PAULI_BLOCKER_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class FermiMomentumTable;

class PauliBlocker : public EventRecordVisitorI {

public :
  PauliBlocker();
  PauliBlocker(string config);
 ~PauliBlocker();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

private:
   void LoadModelType(void);

   bool fLFG;
   const FermiMomentumTable * fKFTable;
   string fKFTableName;
};

}      // genie namespace

#endif // _PAULI_BLOCKER_H_

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"genie::FermiMover", payloadCode, "@",
"genie::HadronTransporter", payloadCode, "@",
"genie::HadronicSystemGenerator", payloadCode, "@",
"genie::InitialStateAppender", payloadCode, "@",
"genie::KineGeneratorWithCache", payloadCode, "@",
"genie::NucBindEnergyAggregator", payloadCode, "@",
"genie::NucDeExcitationSim", payloadCode, "@",
"genie::PauliBlocker", payloadCode, "@",
"genie::PrimaryLeptonGenerator", payloadCode, "@",
"genie::UnstableParticleDecayer", payloadCode, "@",
"genie::VertexGenerator", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGEVGModules",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGEVGModules_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGEVGModules_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGEVGModules() {
  TriggerDictionaryInitialization_libGEVGModules_Impl();
}
