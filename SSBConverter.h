// -*- C++ -*-
//
// Package:    SSBConverter
// Class:      SSBConverter
// 
/**\class SSBConverter SSBConverter.cc CMSAnalyses/SSBAnalyzer/plugins/SSBConverter.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Seungkyu Ha, Sehwook Lee, Suyoung Choi, Jaehoon Lim, 588 R-004, +41227678602
//         Created:  Mon Aug 29 14:43:11 CEST 2016
// $Id$
//
//

#ifndef SSBConverter_h
#define SSBConverter_h

// system include files
#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// needed for TFileService
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

// needed for trigger 
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"

// Cat
#include "CATTools/DataFormats/interface/Muon.h"
#include "CATTools/DataFormats/interface/Electron.h"
#include "CATTools/DataFormats/interface/Jet.h"
#include "CATTools/DataFormats/interface/MET.h"

// root
#include "TTree.h"
#include "TH1.h"
#include "TLorentzVector.h"

// Managing Tree
#include "SSBTreeManager.h"
// Generated Level Information
#include "SSBGenInfor.h"

using namespace std;

class SSBTreeManager;
class SSBGenInfor;
 
class SSBConverter : public edm::EDAnalyzer {

   public:
      explicit SSBConverter(const edm::ParameterSet&);
      ~SSBConverter();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      virtual void cutstep();
      // ----------member data ---------------------------
     
      // Input from python
      std::string              Save_Channel;
      bool                     Save_Inversion;

      bool                     Try_Cut_Trigger;
      std::vector<std::string> e_Trigger;
      std::vector<std::string> m_Trigger;
      std::vector<std::string> em_Trigger;

      std::string              IsolatedMuonID;
      double                   IsolatedMuonPt;
      double                   IsolatedMuonEta;
      double                   IsolatedMuonIso;

      std::string              IsolatedElectronID;
      double                   IsolatedElectronPt;
      double                   IsolatedElectronEta;

      std::string              VetoMuonID;
      double                   VetoMuonPt;
      double                   VetoMuonEta;
      double                   VetoMuonIso;

      std::string              VetoElectronID;
      double                   VetoElectronPt;
      double                   VetoElectronEta;

      std::string              JetID;
      double                   JetPt;
      double                   JetEta;
      std::string              JetBTag;
      double                   JetCleaningdR;

      double                   InclusiveMass;
      double                   InclusiveMassE;
      double                   METPt;

      edm::EDGetTokenT<reco::GenParticleCollection> genParInfoTag;
      edm::EDGetTokenT<reco::GenJetCollection>      genJetInfoTag;
      edm::EDGetTokenT<cat::MuonCollection>         muonToken_;
      edm::EDGetTokenT<cat::ElectronCollection>     electronToken_;
      edm::EDGetTokenT<cat::JetCollection>          jetToken_;
      edm::EDGetTokenT<cat::METCollection>          metToken_;
      edm::EDGetTokenT<int>                         npvToken_;
      edm::EDGetTokenT<edm::TriggerResults>         triggerBits_;

      // variables for NTuple
      TTree* ssbtree;
      SSBTreeManager* ssbtreeManager;
      edm::Service<TFileService> ssbfs;
      TH1F* ejets_EventInfo;
      TH1F* mjets_EventInfo;
      bool FillNTuple;

      // variables for Event info.
      SSBGenInfor* ssbgeninfor;
      int Event;
      int Run;
      int Lumi;
      bool isData;
      std::string ChannelName;

      // variables for Trigger
      unsigned int Num_e_Trigger;
      unsigned int Num_m_Trigger;
      unsigned int Num_em_Trigger;

      // variables for Cut Flag
      bool Cut_e_Trigger;
      bool Cut_m_Trigger;
      bool Cut_em_Trigger;

      bool Cut_m_MuonVeto;
      bool Cut_e_MuonVeto;

      bool Cut_e_ElectronVeto;
      bool Cut_m_ElectronVeto;

      bool Cut_LeptonMass;
      bool Cut_MET;

      bool Cut_ej_ElectronIso;
      bool Cut_ej_Step1;
      bool Cut_ej_Step2a;
      bool Cut_ej_Step2b;

      bool Cut_mj_MuonIso;
      bool Cut_mj_Step1;
      bool Cut_mj_Step2a;
      bool Cut_mj_Step2b;

      int Num_PlusLepton;
      int Num_MinusLepton;

      // variables for Muons 
      int Index_Muon;
      int Num_IsolatedMuon;
      int Num_PlusMuon;
      int Num_MinusMuon;
      int Num_VetoMuon;
      bool isIsolatedMuon;
      bool isVetoMuon;
      bool isIsoIDMuon;
      bool isVetoIDMuon;
      double PFIsodbeta04;
      std::vector<int> Index_IsolatedMuon;
      std::vector<int> Index_VetoMuon;

      // variables for Electrons
      int Index_Electron;
      int Num_IsolatedElectron;
      int Num_PlusElectron;
      int Num_MinusElectron;
      int Num_VetoElectron;
      bool isIsolatedElectron;
      bool isVetoElectron;
      bool isIsoElectronID;
      bool isVetoElectronID;
      double PFIsodbeta03;
      double IsoCutLowEta;
      double IsoCutHighEta;
      double VetoCutLowEta;
      double VetoCutHighEta;
      double SuperClusterEta;
      bool PassConversionVeto;
      bool ChargeConsistent;
      std::vector<int> Index_IsolatedElectron;
      std::vector<int> Index_VetoElectron;

      // variables for Jets
      int Index_Jet;
      int Index_Cut_Jet;
      int Index_Cut_BJet;
      bool isJet;
      bool isCleanedJet;
      bool isBJet;
      double bDiscriminator;
      double bDiscCut;
      double cDiscriminatorCvsL;
      double cDiscriminatorCvsB;
      TLorentzVector LV_jet;
      TLorentzVector LV_electron;
      TLorentzVector LV_muon;
      TLorentzVector LV_AllLepton;

      // variables for MET

};

#endif
