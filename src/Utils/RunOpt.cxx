//____________________________________________________________________________
/*
 Copyright (c) 2003-2017, GENIE Neutrino MC Generator Collaboration
 For the full text of the license visit http://copyright.genie-mc.org
 or see $GENIE/LICENSE

 Author: Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab 

 For the class documentation see the corresponding header file.

 Important revisions after version 2.0.0 :
 @ Jan 29, 2013 - CA
   Added in preparartion for v2.8.0, when use of env. vars was phased out.

*/
//____________________________________________________________________________

#include <iostream>

#include <TMath.h>
#include <TBits.h>

#include "GHEP/GHepFlags.h"
#include "Utils/CmdLnArgParser.h"
#include "Utils/RunOpt.h"
#include "Messenger/Messenger.h"

using std::cout;
using std::endl;

namespace genie {

//____________________________________________________________________________
ostream & operator << (ostream & stream, const RunOpt & opt)
{
  opt.Print(stream);
  return stream;
}
//____________________________________________________________________________
RunOpt * RunOpt::fInstance = 0;
//____________________________________________________________________________
RunOpt::RunOpt()
{
  fInstance = 0;

  this->Init();
}
//____________________________________________________________________________
RunOpt::~RunOpt()
{
  fInstance = 0;
}
//____________________________________________________________________________
RunOpt * RunOpt::Instance()
{
  if(fInstance == 0) {
    static RunOpt::Cleaner cleaner;
    cleaner.DummyMethodAndSilentCompiler();
    fInstance = new RunOpt;
  }
  return fInstance;
}
//____________________________________________________________________________
void RunOpt::Init(void)
{
  fEnableBareXSecPreCalc = true;
  fCacheFile = "";
  fMesgThresholds = "";
  fUnphysEventMask = new TBits(GHepFlags::NFlags());
//fUnphysEventMask->ResetAllBits(true);
  for(unsigned int i = 0; i < GHepFlags::NFlags(); i++) {
   fUnphysEventMask->SetBitNumber(i, true);
  }
  fMCJobStatusRefreshRate = 50;
  fEventRecordPrintLevel  = 3;
  fEventGeneratorList     = "Default";
  fTune                   = "Default";
}
//____________________________________________________________________________
void RunOpt::ReadFromCommandLine(int argc, char ** argv)
{
  CmdLnArgParser parser(argc,argv);

  if( parser.OptionExists("enable-bare-xsec-pre-calc") ) {
    fEnableBareXSecPreCalc = true;
  } else 
  if( parser.OptionExists("disable-bare-xsec-pre-calc") ) {
    fEnableBareXSecPreCalc = false;
  }

  if( parser.OptionExists("cache-file") ) {
    fCacheFile = parser.ArgAsString("cache-file");
  }

  if( parser.OptionExists("message-thresholds") ) {
    fMesgThresholds = parser.ArgAsString("message-thresholds");
  }

  if( parser.OptionExists("event-record-print-level") ) {
    fEventRecordPrintLevel = parser.ArgAsInt("event-record-print-level");
  }

  if( parser.OptionExists("mc-job-status-refresh-rate") ) {
    fMCJobStatusRefreshRate = TMath::Max(
        1, parser.ArgAsInt("mc-job-status-refresh-rate"));
  }

  if( parser.OptionExists("event-generator-list") ) {
    fEventGeneratorList = parser.ArgAsString("event-generator-list");
  }

  if( parser.OptionExists("tune") ) {
    LOG("RunOpt", pWARN) 
       << "--tune argument is dummy. "
       << "A single (\"Default\") tune is supported for this version of GENIE";
  //fTune = parser.ArgAsString("tune");
  }

  if( parser.OptionExists("unphysical-event-mask") ) {
    const char * bitfield = 
       parser.ArgAsString("unphysical-event-mask").c_str();
    unsigned int n = GHepFlags::NFlags();
    unsigned int i = 0;
    while(i < n) {
        bool flag = (bitfield[i]=='1');
        fUnphysEventMask->SetBitNumber(n-1-i,flag);
        i++;
     }//i
  }

}
//____________________________________________________________________________
void RunOpt::Print(ostream & stream) const
{
  stream << "Global running options:";
  stream << "\n GENIE tune: " << fTune;
  stream << "\n Event generator list: " << fEventGeneratorList;
  stream << "\n User-specified message thresholds : " << fMesgThresholds;
  stream << "\n Cache file : " << fCacheFile;
  stream << "\n Unphysical event mask (bits: "
         << GHepFlags::NFlags()-1 << " -> 0) : " << *fUnphysEventMask;
  stream << "\n Event record print level : " << fEventRecordPrintLevel;
  stream << "\n MC job status file refresh rate: " << fMCJobStatusRefreshRate;
  stream << "\n Pre-calculate all free-nucleon cross-sections? : " 
         << ((fEnableBareXSecPreCalc) ? "Yes" : "No");

  stream << "\n";
}
//___________________________________________________________________________

} // genie namespace


