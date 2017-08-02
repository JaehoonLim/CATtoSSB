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
#include "CATTools/DataFormats/interface/GenWeights.h"

// root
#include "TTree.h"
#include "TH1.h"
#include "TLorentzVector.h"

// Managing Tree
#include "SSBTreeManager.h"
// Generated Level Information
#include "SSBGenInfor.h"
// Managing Tree
#include "SSBHistManager.h"
// Lepton Scale Factor
#include "SSBSF.h"

using namespace std;
using namespace cat;

class SSBGenInfor;
class SSBTreeManager;
class SSBHistManager;
class ScaleFactorEvaluator; 
 
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

      virtual void CutStep();
      virtual void FillHistogram();
      // ----------member data ---------------------------
     
      // Input from python
      bool                     debugcout;

      std::string              Save_Channel;
      std::string              Save_CutStep;
      bool                     Save_Inversion;

      std::string              Channel;

      std::vector<std::string> CutStepName;
      std::vector<std::string> CutChannelName;

      std::vector<std::string> EventFilter;

      bool                     Try_Cut_Trigger;
      std::vector<std::string> e_Trigger;
      std::vector<std::string> m_Trigger;
      std::vector<std::string> em_Trigger;

      std::string              IsolatedMuonID;
      double                   IsolatedMuonPt;
      double                   IsolatedMuonEta;
      double                   IsolatedMuonIso;
      bool                     IsolatedMuonMultiIso;
      double                   IsolatedMuonMiniIso;
      double                   IsolatedMuonPtRatio;
      double                   IsolatedMuonPtRel;

      std::string              IsolatedElectronID;
      double                   IsolatedElectronPt;
      double                   IsolatedElectronEta;
      std::string              IsolatedElectronIso;
      bool                     IsolatedElectronMultiIso;
      double                   IsolatedElectronMiniIso;
      double                   IsolatedElectronPtRatio;
      double                   IsolatedElectronPtRel;

      bool                     Try_Cut_Additional;
      bool                     TightLooseMethod;
      std::string              AdditionalMuonID;
      double                   AdditionalMuonPt;
      double                   AdditionalMuonEta;
      double                   AdditionalMuonIso;
      bool                     AdditionalMuonMultiIso;
      double                   AdditionalMuonMiniIso;
      double                   AdditionalMuonPtRatio;
      double                   AdditionalMuonPtRel;

      std::string              AdditionalElectronID;
      double                   AdditionalElectronPt;
      double                   AdditionalElectronEta;
      std::string              AdditionalElectronIso;
      bool                     AdditionalElectronMultiIso;
      double                   AdditionalElectronMiniIso;
      double                   AdditionalElectronPtRatio;
      double                   AdditionalElectronPtRel;

      std::string              VetoMuonID;
      double                   VetoMuonPt;
      double                   VetoMuonEta;
      double                   VetoMuonIso;
      bool                     VetoMuonMultiIso;
      double                   VetoMuonMiniIso;
      double                   VetoMuonPtRatio;
      double                   VetoMuonPtRel;

      std::string              VetoElectronID;
      double                   VetoElectronPt;
      double                   VetoElectronEta;
      std::string              VetoElectronIso;
      bool                     VetoElectronMultiIso;
      double                   VetoElectronMiniIso;
      double                   VetoElectronPtRatio;
      double                   VetoElectronPtRel;

      std::string              JetID;
      double                   JetPt;
      double                   JetEta;
      std::string              JetBTag;
      double                   JetCleaningdR;

      double                   InvariantMass;
      double                   InvariantMassE;
      double                   METPt;

      edm::EDGetTokenT<reco::GenParticleCollection> genParInfoTag;
      edm::EDGetTokenT<reco::GenJetCollection>      genJetInfoTag;
      edm::EDGetTokenT<cat::GenWeights>             genWeightToken_;
      edm::EDGetTokenT<int>                         lumiMaskToken_;
      edm::EDGetTokenT<cat::MuonCollection>         muonToken_;
      edm::EDGetTokenT<cat::ElectronCollection>     electronToken_;
      edm::EDGetTokenT<cat::JetCollection>          jetToken_;
      edm::EDGetTokenT<cat::METCollection>          metToken_;
      edm::EDGetTokenT<int>                         npvToken_;
      edm::EDGetTokenT<float>                       PUWeightToken_;
      std::vector<edm::EDGetTokenT<edm::TriggerResults>>         triggerBits_;
      std::vector<edm::EDGetTokenT<edm::TriggerResults>>         EventFilterBits_;

      // variables for NTuple
      TTree* ssbtree;
      SSBTreeManager* ssbtreeManager;
      TFileDirectory ssbhist;
      SSBHistManager* ssbhistManager;
      edm::Service<TFileService> ssbfs;
      TH1D* EventInfo[20];
      TH1D* GenInfo;
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
      bool Cut_Event_Filter;

      bool Cut_e_Trigger;
      bool Cut_m_Trigger;
      bool Cut_em_Trigger;

      bool Cut_e_MuonVeto;
      bool Cut_m_MuonVeto;

      bool Cut_e_ElectronVeto;
      bool Cut_m_ElectronVeto;

      bool Cut_e_Charge;
      bool Cut_m_Charge;

      //bool Cut_e_MassVeto;
      //bool Cut_m_MassVeto;

      bool Cut_LeptonMass;
      bool Cut_MET;
      //bool Cut_MT_min;

      bool Cut_ej_ElectronIso;
      bool Cut_ej_Step0c;
      bool Cut_ej_Step1;
      bool Cut_ej_Step2a;
      bool Cut_ej_Step2b;

      bool Cut_mj_MuonIso;
      bool Cut_mj_Step0c;
      bool Cut_mj_Step1;
      bool Cut_mj_Step2a;
      bool Cut_mj_Step2b;

      int Num_PlusLepton;
      int Num_MinusLepton;

      bool Cut_ee_LeptonPair;
      bool Cut_mm_LeptonPair;
      bool Cut_em_LeptonPair;
      bool Cut_dl_Opposite;
      bool Cut_dl_Same;

      bool Cut_ee_TL;
      bool Cut_mm_TL;
      bool Cut_em_TL;

      int TriLepton_First;
      int TriLepton_Second;
      int TriLepton_Third;
      int TriLepton_Other;

      bool Cut_Tri_ee;
      bool Cut_Tri_mm;
      bool Cut_Tri_em;
      bool Cut_Tri_First_Opposite;
      bool Cut_Tri_First_Same;
      bool Cut_Tri_First_Zmass;
      bool Cut_Tri_ExactlyThree;
      bool Cut_Tri_add_e;
      bool Cut_Tri_add_m;
      bool Cut_Tri_add_Charge;
      bool Cut_Tri_Second_Zmass;
      int Num_OppositeLepton;
      bool Cut_SUSY_SRZ;

      std::map<std::string,std::map<std::string,bool>> Cut_Step;

      // variables for Muons 
      edm::Handle<cat::MuonCollection> muons;
      int Index_Muon;
      int Num_IsolatedMuon;
      int Num_PlusMuon;
      int Num_MinusMuon;
      int Num_AdditionalMuon;
      int Num_VetoMuon;
      bool isIsolatedMuon;
      bool isAdditionalMuon;
      bool isVetoMuon;
      bool isIsoIDMuon;
      bool isAddIDMuon;
      bool isVetoIDMuon;
      double PFIsodbeta04;
      double muon_ClosestdR;
      double muon_Pt_rel;
      double muon_Pt_ratio;
      float MuonPtError;
      std::vector<int> Index_IsolatedMuon;
      std::vector<int> Index_AdditionalMuon;
      std::vector<int> Index_VetoMuon;
      double SF_Muon;
      double MT_Muon;
      std::vector<double> vSF_Muon;
      std::vector<double> v_Muon_Iso03;
      std::vector<double> v_Muon_Iso04;
      std::vector<double> v_Muon_miniIso;
      std::vector<double> v_Muon_Pt_rel;
      std::vector<double> v_Muon_Pt_ratio;

      // variables for Electrons
      edm::Handle<cat::ElectronCollection> electrons;
      int Index_Electron;
      int Num_IsolatedElectron;
      int Num_PlusElectron;
      int Num_MinusElectron;
      int Num_AdditionalElectron;
      int Num_VetoElectron;
      bool isIsolatedElectron;
      bool isAdditionalElectron;
      bool isVetoElectron;
      bool isIsoElectronID;
      bool isAddElectronID;
      bool isVetoElectronID;
      double PFIsodbeta03;
      double electron_ClosestdR;
      double electron_Pt_rel;
      double electron_Pt_ratio;
      double IsoCutLowEta;
      double IsoCutHighEta;
      double AddCutLowEta;
      double AddCutHighEta;
      double VetoCutLowEta;
      double VetoCutHighEta;
      double SuperClusterEta;
      bool PassConversionVeto;
      bool ChargeConsistent;
      std::vector<int> Index_IsolatedElectron;
      std::vector<int> Index_AdditionalElectron;
      std::vector<int> Index_VetoElectron;
      double SF_Electron;
      double MT_Electron;
      std::vector<double> vSF_Elec;
      std::vector<double> v_Elec_Iso03;
      std::vector<double> v_Elec_Iso04;
      std::vector<double> v_Elec_miniIso;
      std::vector<double> v_Elec_Pt_rel;
      std::vector<double> v_Elec_Pt_ratio;

      // variables for Jets
      edm::Handle<cat::JetCollection> jets;
      int Index_Jet;
      int Index_Cut_Jet;
      int Index_Cut_BJet;
      int Num_CleanedJet;
      int Num_BJet;
      bool isJet;
      bool isCleanedJet;
      bool isBJet;
      double bDiscriminator;
      double bDiscCut;
      double cDiscriminatorCvsL;
      double cDiscriminatorCvsB;
      double qgLikelihood;
      TLorentzVector LV_jet;
      TLorentzVector LV_electron;
      TLorentzVector LV_muon;
      TLorentzVector LV_AllJet;
      TLorentzVector LV_MET;
      TLorentzVector LV_Iso;
      TLorentzVector LV_Veto;
      std::vector<int> Index_CleanedJet;
      std::vector<int> Index_BJet;

      // other variables
      double GenWeight;
      double PileUpWeight;
      double LeptonWeight;
      double AddLeptonWeight;
      edm::Handle<cat::METCollection> mets;
      int numPV;
      double HT;
      double HM;
      double AllLeptonMass;
      double DiLeptonMass1;
      double DiLeptonMass2;
      double DiLeptonMass3;
      double DiLeptonMassOther;

      ScaleFactorEvaluator *MuonSFEval;
      ScaleFactorEvaluator *ElectronSFEval;

      TLorentzVector LV_AllLepton;
      TLorentzVector LV_Tri_First;
      TLorentzVector LV_Tri_Second;
      TLorentzVector LV_Tri_Third;
      TLorentzVector LV_Tri_Other;
      TLorentzVector LV_Tri_Dilepton1;
      TLorentzVector LV_Tri_Dilepton2;
      TLorentzVector LV_Tri_Dilepton3;
      TLorentzVector LV_Tri_DileptonOther;
/*
   string TriID[4]        = {"MMM","TMM","TTM","TTT"};
   double Elec_IsoHigh[3] = {0.1590,0.1070,0.0821};
   double Elec_IsoLow[3]  = {0.1750,0.0994,0.0695};
   double Muon_Iso[3]     = {0.25,  0.20,  0.15  };
   double Lep_Pt[3]       = {10,    20,    30    };

   int    Cut1[10]        = {0,1,1,1,2,2,2,2,2,2};
   int    Cut2[10]        = {0,0,1,1,0,1,1,2,2,2};
   int    Cut3[10]        = {0,0,0,1,0,0,1,0,1,2};

   int    CutTest[4][10][10][3];
   float  pt = 0.0;
   double sceta = 0.0;
   double lep_iso = 0.0;
   bool   CutID1 = false;
   bool   CutID2 = false;
   bool   CutID3 = false;
*/

};

#endif
