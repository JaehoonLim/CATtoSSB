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

#include "SSBConverter.h"
#include "SSBCutStep.h"
#include "SSBFillHistogram.h"

//
// constants, enums and typedefs
//
//
// static data member definitions
//
//
// constructors and destructor
//
SSBConverter::SSBConverter(const edm::ParameterSet& iConfig)
:
Save_Channel(        iConfig.getUntrackedParameter< std::string >(              "Save_Channel",       std::string("ALL")    )), 
Save_CutStep(        iConfig.getUntrackedParameter< std::string >(              "Save_CutStep",       std::string("2")      )), 
Save_Inversion(      iConfig.getUntrackedParameter< bool >(                     "Save_Inversion",     false                 )), 

Try_Cut_Trigger(     iConfig.getUntrackedParameter< bool >(                     "Do_Trigger_Cut",     true                  )), 
e_Trigger(           iConfig.getUntrackedParameter< std::vector<std::string> >( "e_Trigger"                                 )),
m_Trigger(           iConfig.getUntrackedParameter< std::vector<std::string> >( "m_Trigger"                                 )),
em_Trigger(          iConfig.getUntrackedParameter< std::vector<std::string> >( "em_Trigger"                                )),

IsolatedMuonID(      iConfig.getUntrackedParameter< std::string >(              "MuonID",             std::string("Tight")  )), 
IsolatedMuonPt(      iConfig.getUntrackedParameter< double >(                   "MuonPt",             26.0                  )),
IsolatedMuonEta(     iConfig.getUntrackedParameter< double >(                   "MuonEta",            2.1                   )),
IsolatedMuonIso(     iConfig.getUntrackedParameter< double >(                   "MuonIso",            0.15                  )),

IsolatedElectronID(  iConfig.getUntrackedParameter< std::string >(              "ElectronID",         std::string("Medium") )), 
IsolatedElectronPt(  iConfig.getUntrackedParameter< double >(                   "ElectronPt",         30.0                  )),
IsolatedElectronEta( iConfig.getUntrackedParameter< double >(                   "ElectronEta",        2.4                   )),

VetoMuonID(          iConfig.getUntrackedParameter< std::string >(              "veto_MuonID",        std::string("Loose")  )), 
VetoMuonPt(          iConfig.getUntrackedParameter< double >(                   "veto_MuonPt",        10.0                  )),
VetoMuonEta(         iConfig.getUntrackedParameter< double >(                   "veto_MuonEta",       2.4                   )),
VetoMuonIso(         iConfig.getUntrackedParameter< double >(                   "veto_MuonIso",       0.25                  )),

VetoElectronID(      iConfig.getUntrackedParameter< std::string >(              "veto_ElectronID",    std::string("Veto")   )), 
VetoElectronPt(      iConfig.getUntrackedParameter< double >(                   "veto_ElectronPt",    10.0                  )),
VetoElectronEta(     iConfig.getUntrackedParameter< double >(                   "veto_ElectronEta",   2.4                   )),

JetID(               iConfig.getUntrackedParameter< std::string >(              "JetID",              std::string("Loose")  )),   
JetPt(               iConfig.getUntrackedParameter< double >(                   "JetPt",              30.0                  )),
JetEta(              iConfig.getUntrackedParameter< double >(                   "JetEta",             2.4                   )),
JetBTag(             iConfig.getUntrackedParameter< std::string >(              "BTag",               std::string("Medium") )),
JetCleaningdR(       iConfig.getUntrackedParameter< double >(                   "CleaningdR",         0.4                   )),

InvariantMass(       iConfig.getUntrackedParameter< double >(                   "InvariantMass",      91.2                  )),
InvariantMassE(      iConfig.getUntrackedParameter< double >(                   "PlusMinus",          15.0                  )),
METPt(               iConfig.getUntrackedParameter< double >(                   "METPt",              0.0                   ))
{
    //now do what ever initialization is needed

    genParInfoTag    = consumes<reco::GenParticleCollection> (iConfig.getParameter<edm::InputTag>("genParTag"));
    genJetInfoTag    = consumes<reco::GenJetCollection>      (iConfig.getParameter<edm::InputTag>("genJetTag"));

    genWeightToken_  = consumes<cat::GenWeights>             (iConfig.getParameter<edm::InputTag>("genWeightLabel"));

    muonToken_       = consumes<cat::MuonCollection>         (iConfig.getParameter<edm::InputTag>("muonTag"));
    electronToken_   = consumes<cat::ElectronCollection>     (iConfig.getParameter<edm::InputTag>("electronTag"));
    jetToken_        = consumes<cat::JetCollection>          (iConfig.getParameter<edm::InputTag>("jetTag"));
    metToken_        = consumes<cat::METCollection>          (iConfig.getParameter<edm::InputTag>("metTag"));

    npvToken_        = consumes<int>                         (iConfig.getParameter<edm::InputTag>("npvTag"));

    for(auto& trig : iConfig.getParameter<std::vector<edm::InputTag>>("triggerBitsTag")) {
        triggerBits_.push_back(consumes<edm::TriggerResults>(trig));
    }
    for(auto& filt : iConfig.getParameter<std::vector<edm::InputTag>>("EventFilterBitsTag")) {
        EventFilterBits_.push_back(consumes<edm::TriggerResults>(filt));
    }

    ssbgeninfor = new SSBGenInfor(iConfig);

    //FIXME:When you change the cut steps
    CutChannelName = {"ee","mm","em"};
    CutStepName = {"0a","0b","0c","1a","1b","2","3","4","5"};

    EventFilter = {"Flag_HBHENoiseFilter", "Flag_HBHENoiseIsoFilter", "Flag_EcalDeadCellTriggerPrimitiveFilter", "Flag_goodVertices", "Flag_eeBadScFilter", "Flag_globalTightHalo2016Filter", "Flag_badPFMuon", "Flag_badChargedHadron"};

    Num_e_Trigger  = e_Trigger.size();
    Num_m_Trigger  = m_Trigger.size();
    Num_em_Trigger = em_Trigger.size();

    if(IsolatedMuonID != "Loose" && IsolatedMuonID != "Medium" && IsolatedMuonID != "Tight" && IsolatedMuonID != "Soft"){
        cout << endl << "MuonID Error"<< endl << endl;
        cerr << endl << "MuonID Error"<< endl << endl;
    }

    if(VetoMuonID != "Loose" && VetoMuonID != "Medium" && VetoMuonID != "Tight" && VetoMuonID != "Soft"){
        cout << endl << "VetoMuonID Error"<< endl << endl;
        cerr << endl << "VetoMuonID Error"<< endl << endl;
    }

    if(IsolatedElectronID == "Loose"){
        IsoCutLowEta  = 0.0994;
        IsoCutHighEta = 0.1070;
    } else if(IsolatedElectronID == "Medium"){
        IsoCutLowEta  = 0.0695;
        IsoCutHighEta = 0.0821;
    } else if(IsolatedElectronID == "Tight"){
        IsoCutLowEta  = 0.0588;
        IsoCutHighEta = 0.0571;
    } else if(IsolatedElectronID == "Veto"){
        IsoCutLowEta  = 0.175;
        IsoCutHighEta = 0.159;
    } else {
        cout << endl << "ElectronID Error"<< endl << endl;
        cerr << endl << "ElectronID Error"<< endl << endl;
        IsoCutLowEta  = 0.0000;
        IsoCutHighEta = 0.0000;
    } 

    if(VetoElectronID == "Loose"){
        VetoCutLowEta  = 0.0994;
        VetoCutHighEta = 0.1070;
    } else if(VetoElectronID == "Medium"){
        VetoCutLowEta  = 0.0695;
        VetoCutHighEta = 0.0821;
    } else if(VetoElectronID == "Tight"){
        VetoCutLowEta  = 0.0588;
        VetoCutHighEta = 0.0571;
    } else if(VetoElectronID == "Veto"){
        VetoCutLowEta  = 0.175;
        VetoCutHighEta = 0.159;
    } else {
        cout << endl << "VetoElectronID Error"<< endl << endl;
        cerr << endl << "VetoElectronID Error"<< endl << endl;
        VetoCutLowEta  = 0.0000;
        VetoCutHighEta = 0.0000;
    } 

    if(JetID != "Loose" && JetID != "Tight"){
        cout << endl << "JetID Error"<< endl << endl;
        cerr << endl << "JetID Error"<< endl << endl;
    }

    if(JetBTag == "Loose")  bDiscCut = 0.460;
    else if(JetBTag == "Medium") bDiscCut = 0.800;
    else if(JetBTag == "Tight")  bDiscCut = 0.935;
    else {
        cout << endl << "BTag Error"<< endl << endl;
        cerr << endl << "BTag Error"<< endl << endl;
        bDiscCut = 1.00;
    }

    for(int i_Channel=0; i_Channel<(int)CutChannelName.size(); ++i_Channel){
        EventInfo[i_Channel] = ssbfs->make<TH1D>(Form("%s_EventInfo",CutChannelName[i_Channel].c_str()),Form("%s Dilepton Event Information",CutChannelName[i_Channel].c_str()),CutStepName.size()+1,-1,CutStepName.size());
        EventInfo[i_Channel]->GetXaxis()->SetBinLabel(1 ,"Number of Inclusive Samples");
        for(int i_SetBinLabel=2; i_SetBinLabel<(int)CutStepName.size()+2; ++i_SetBinLabel){
            EventInfo[i_Channel]->GetXaxis()->SetBinLabel(i_SetBinLabel, CutStepName[i_SetBinLabel-2].c_str());
        }
    }
    GenInfo = ssbfs->make<TH1D>("GenInfo","GenInfo",2,0,2);
    GenInfo->GetXaxis()->SetBinLabel(1,"Number of Events");
    GenInfo->GetXaxis()->SetBinLabel(2,"Sum GenWeight");
}

SSBConverter::~SSBConverter()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
SSBConverter::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    // Initailizing variable 
    ssbtreeManager->InitializeVariables(); 

    Event = -999;
    Run = -999;
    Lumi = -999;
    isData = false;
    ChannelName = "Background";
    FillNTuple = true;
    GenWeight = 1.0;

    Event = iEvent.id().event();
    Run = iEvent.id().run();
    Lumi = iEvent.id().luminosityBlock();
    isData = iEvent.isRealData();

    ssbtreeManager->Fill( "Info_EventNumber", Event  );
    ssbtreeManager->Fill( "Info_RunNumber"  , Run    ); 
    ssbtreeManager->Fill( "Info_Luminosity" , Lumi   ); 
    ssbtreeManager->Fill( "Info_isData"     , isData ); 
    for(int i_Channel=0; i_Channel<(int)CutChannelName.size(); ++i_Channel){
        EventInfo[i_Channel]->Fill(-0.5,1.0);
    }
    GenInfo->Fill(0.5,1.0);

   /////////////////////////////////
   /// Only For MC Samples!!!!!! ///
   /////////////////////////////////

    if (isData == false)
    {

        ///////////////////////
        /// PDF Information ///
        ///////////////////////

        ///////////////////////////////////////////
        /// Generator Level Particle Informaton ///
        ///////////////////////////////////////////
      
        ssbgeninfor->GenPar(iEvent, ssbtreeManager);
        ssbgeninfor->GenJet(iEvent, ssbtreeManager);

        edm::Handle<cat::GenWeights> genWeight;
        iEvent.getByToken(genWeightToken_, genWeight);
        GenWeight = genWeight->genWeight();
        GenInfo->Fill(1,GenWeight);

        ChannelName = ssbgeninfor->ReturnChannel(iEvent);
        if(Save_Channel != "ALL" && ChannelName.find(Save_Channel) == std::string::npos) FillNTuple = false;
        if(Save_Inversion) FillNTuple = !FillNTuple;

    } else {
        ChannelName = "Data";
    }

    if(FillNTuple) {
                                            
    ///////////////////////////////////
    // Primary Vertices Information ///
    ///////////////////////////////////

    numPV = 0;
    edm::Handle<int> Num_PV;
    iEvent.getByToken( npvToken_, Num_PV );
    numPV = (int)*Num_PV;
    ssbtreeManager->Fill( "PV_Count", numPV );

    //////////////////////////
    /// Pileup Information ///
    //////////////////////////

    //////////////////
    ///Event Filter///
    //////////////////

    Cut_Event_Filter = true;
    edm::Handle<edm::TriggerResults> EventFilterBits;                                                                                        
    for(auto EventFilterBits_i : EventFilterBits_) {
    if(!iEvent.getByToken(EventFilterBits_i, EventFilterBits)) continue;
    const edm::TriggerNames &FilterNames = iEvent.triggerNames(*EventFilterBits);
    unsigned int Num_Filter = EventFilterBits->size();

    for(unsigned int Index_Filter = 0; Index_Filter < Num_Filter; ++Index_Filter){
        const string& FilterName = FilterNames.triggerName(Index_Filter); 
        for(unsigned int Index_flag = 0; Index_flag < EventFilter.size(); ++Index_flag){
            if(FilterName.find(EventFilter.at(Index_flag)) != std::string::npos
               && !EventFilterBits->accept(Index_Filter)){
                Cut_Event_Filter = false;
            }
        }    
    }
    } // auto
    ssbtreeManager->Fill( "Cut_Event_Filter", Cut_Event_Filter );

    /////////////////////////
    ///Trigger Information///
    /////////////////////////

    Cut_e_Trigger  = false;
    Cut_m_Trigger  = false;
    Cut_em_Trigger = false;
    edm::Handle<edm::TriggerResults> triggerBits;                                                                                        
    for(auto triggerBits_i : triggerBits_) {
    if(!iEvent.getByToken(triggerBits_i, triggerBits)) continue;
    const edm::TriggerNames &trigNames = iEvent.triggerNames(*triggerBits);
    unsigned int Num_Trigger = triggerBits->size();

    for(unsigned int Index_Trigger = 0; Index_Trigger < Num_Trigger; ++Index_Trigger){
        const string& trigName = trigNames.triggerName(Index_Trigger); 
        for(unsigned int Index_e = 0; Index_e < Num_e_Trigger; ++Index_e){
            if(trigName.find(e_Trigger.at(Index_e)) != std::string::npos
               && triggerBits->accept(Index_Trigger)){
                Cut_e_Trigger = true;
            }
        }    
        for(unsigned int Index_m = 0; Index_m < Num_m_Trigger; ++Index_m){
            if(trigName.find(m_Trigger.at(Index_m)) != std::string::npos
               && triggerBits->accept(Index_Trigger)){
                Cut_m_Trigger = true;
            }
        }
        for(unsigned int Index_em = 0; Index_em < Num_em_Trigger; ++Index_em){
            if(trigName.find(em_Trigger.at(Index_em)) != std::string::npos
               && triggerBits->accept(Index_Trigger)){
                Cut_em_Trigger = true;
            }
        }
    }
    } // auto
    if(!Try_Cut_Trigger){
        Cut_e_Trigger  = true;
        Cut_m_Trigger  = true;
        Cut_em_Trigger = true;
    }
    ssbtreeManager->Fill( "Cut_e_Trigger",  Cut_e_Trigger  );
    ssbtreeManager->Fill( "Cut_m_Trigger",  Cut_m_Trigger  );
    ssbtreeManager->Fill( "Cut_em_Trigger", Cut_em_Trigger );

    ///////////////////////////////
    /////// MET Information ///////
    ///////////////////////////////
    
    Cut_MET = false;

    iEvent.getByToken(metToken_, mets);

    const cat::MET &met = mets->at(0);
    LV_MET.SetPtEtaPhiE(met.pt(), met.eta(), met.phi(), met.energy());
    ssbtreeManager->Fill( "MET" , met.pt(), 0, met.phi(), 0, 0 );
    if(met.pt() > METPt){
        Cut_MET = true;
    }
    ssbtreeManager->Fill( "Cut_MET", Cut_MET );

    /////////////////////////
    /// Muon Information ////
    /////////////////////////

    Num_PlusLepton = 0;
    Num_MinusLepton = 0;
    LV_AllLepton.SetPtEtaPhiE(0,0,0,0);
    Cut_MT_min = true;

    Cut_e_MuonVeto = false;
    Cut_m_MuonVeto = false;
    Cut_m_Charge = true;
    Cut_m_MassVeto = true;

    iEvent.getByToken(muonToken_, muons);

    Index_Muon = 0; 
    Index_IsolatedMuon.clear();
    Num_IsolatedMuon = 0;
    Num_PlusMuon = 0;
    Num_MinusMuon = 0;
    Index_VetoMuon.clear();
    Num_VetoMuon = 0;

    for (const cat::Muon &muon : *muons)
    {

        isIsolatedMuon = false;
        isVetoMuon = false;

        isIsoIDMuon = false;
        isVetoIDMuon = false;

        if(IsolatedMuonID == "Loose")   isIsoIDMuon = muon.isLooseMuon();
        if(IsolatedMuonID == "Medium")  isIsoIDMuon = muon.isMediumMuon();
        if(IsolatedMuonID == "Tight")   isIsoIDMuon = muon.isTightMuon();
        if(IsolatedMuonID == "Soft")    isIsoIDMuon = muon.isSoftMuon();
        //if(IsolatedMuonID == "HightPt") isIsoIDMuon = muon.isHighPtMuon();

        if(VetoMuonID == "Loose")       isVetoIDMuon = muon.isLooseMuon();
        if(VetoMuonID == "Medium")      isVetoIDMuon = muon.isMediumMuon();
        if(VetoMuonID == "Tight")       isVetoIDMuon = muon.isTightMuon();
        if(VetoMuonID == "Soft")        isVetoIDMuon = muon.isSoftMuon();
        //if(VetoMuonID == "HightPt")     isVetoIDMuon = muon.isHighPtMuon();
        // error: 'const class cat::Muon' has no member named 'isHighPtMuon'

        PFIsodbeta04 = muon.relIso(0.4);

        if(isIsoIDMuon && (muon.pt() > IsolatedMuonPt) && (std::abs(muon.eta()) < IsolatedMuonEta) && PFIsodbeta04 < IsolatedMuonIso){
            isIsolatedMuon = true;
            ++Num_IsolatedMuon;
            Index_IsolatedMuon.push_back(Index_Muon);
        }
        if(isVetoIDMuon && (muon.pt() > VetoMuonPt) && (std::abs(muon.eta()) < VetoMuonEta) && PFIsodbeta04 < VetoMuonIso){
            isVetoMuon = true;
            ++Num_VetoMuon;
            Index_VetoMuon.push_back(Index_Muon);
        }

        ssbtreeManager->Fill( "Muon", muon.pt(), muon.eta(), muon.phi(), muon.energy(), Index_Muon );
        ssbtreeManager->Fill( "Muon_Cut_Isolated" , isIsolatedMuon   );
        ssbtreeManager->Fill( "Muon_Cut_Veto"     , isVetoMuon       );
        ssbtreeManager->Fill( "Muon_isIsoID"      , isIsoIDMuon      );
        ssbtreeManager->Fill( "Muon_isVetoID"     , isVetoIDMuon     );
        ssbtreeManager->Fill( "Muon_PFIsodBeta04" , PFIsodbeta04     );
        ssbtreeManager->Fill( "Muon_pdgId"        , muon.pdgId()     );
        ssbtreeManager->Fill( "Muon_Charge"       , muon.charge()    );

        ++Index_Muon;
    } // Muon Loop

    for(int muon_i = 0; muon_i < Num_IsolatedMuon; ++muon_i){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
        if(IsoMuon.charge() > 0) ++Num_PlusMuon;
        if(IsoMuon.charge() < 0) ++Num_MinusMuon;
        ssbtreeManager->Fill( "Cut_Muon", IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy(), muon_i );
        LV_muon.SetPtEtaPhiE(IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy());
        LV_AllLepton += LV_muon;
        //if(sqrt( pow(LV_muon.Et()-LV_MET.Et(),2) + pow(LV_muon.Px()-LV_MET.Px(),2) + pow(LV_muon.Py()-LV_MET.Py(),2) ) < 120) Cut_MT_min = false;
        //if((IsoMuon.bestTrack()->ptError() / IsoMuon.bestTrack()->pt()) > 0.3) Cut_m_Charge = false;
        auto muon_a = std::find(Index_VetoMuon.begin(), Index_VetoMuon.end(), Index_IsolatedMuon.at(muon_i));
        if(muon_a != Index_VetoMuon.end()){
            Index_VetoMuon.erase(muon_a);
        } else {
            std::cout << "Muon? : " << Index_IsolatedMuon.at(muon_i) << "th Muon - Problem with Veto Cut" << endl;
        } 
    }

    Num_VetoMuon = Index_VetoMuon.size();
    if(Num_VetoMuon == 0) {
        Cut_m_MuonVeto = true;
        if(Num_IsolatedMuon == 0) Cut_e_MuonVeto = true;
    }

/*
    for(int muon_i = 0; muon_i < Num_IsolatedMuon; ++muon_i){
        for(int muon_j = 0; muon_j < Num_VetoMuon; ++muon_j){
            const cat::Muon &IsoMuon  = muons->at(Index_IsolatedMuon.at(muon_i));
            const cat::Muon &VetoMuon = muons->at(Index_VetoMuon.at(muon_j));
            LV_Iso.SetPtEtaPhiE(  IsoMuon.pt(),  IsoMuon.eta(),  IsoMuon.phi(),  IsoMuon.energy());
            LV_Veto.SetPtEtaPhiE(VetoMuon.pt(), VetoMuon.eta(), VetoMuon.phi(), VetoMuon.energy());
            LV_Iso += LV_Veto;
            if( (IsoMuon.charge()*VetoMuon.charge()<0) && ((LV_Iso.M()<12) || (LV_Iso.M()>76.2&&LV_Iso.M()<106.2)) ) Cut_m_MassVeto = false;
        }
    }
*/

    ssbtreeManager->Fill( "Muon_Count",     Index_Muon     );
    ssbtreeManager->Fill( "Num_PlusMuon",   Num_PlusMuon   );
    ssbtreeManager->Fill( "Num_MinusMuon",  Num_MinusMuon  );
    ssbtreeManager->Fill( "Cut_m_Charge",   Cut_m_Charge   );
    ssbtreeManager->Fill( "Cut_m_MuonVeto", Cut_m_MuonVeto );
    ssbtreeManager->Fill( "Cut_e_MuonVeto", Cut_e_MuonVeto );
//    ssbtreeManager->Fill( "Cut_m_MassVeto", Cut_m_MassVeto );

    ////////////////////////////
    /////// Electron infor//////
    ////////////////////////////

    Cut_m_ElectronVeto = false;
    Cut_e_ElectronVeto = false;
    Cut_e_Charge = true;
    Cut_e_MassVeto = true;

    iEvent.getByToken(electronToken_, electrons);

    Index_Electron = 0;
    Index_IsolatedElectron.clear();
    Num_IsolatedElectron = 0;
    Num_PlusElectron = 0;
    Num_MinusElectron = 0;
    Index_VetoElectron.clear();
    Num_VetoElectron = 0;

    for (const cat::Electron &electron : *electrons)
    {

        isIsolatedElectron = false;
        isVetoElectron = false;

        isIsoElectronID = false;
        isVetoElectronID = false;
/*
        if(IsolatedElectronID == "Veto")   isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-veto");
        if(IsolatedElectronID == "Loose")  isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-loose");
        if(IsolatedElectronID == "Medium") isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-medium");
        if(IsolatedElectronID == "Tight")  isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-tight");

        if(VetoElectronID == "Veto")   isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-veto");
        if(VetoElectronID == "Loose")  isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-loose");
        if(VetoElectronID == "Medium") isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-medium");
        if(VetoElectronID == "Tight")  isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-tight");
*/
//*
        if(IsolatedElectronID == "Veto")   isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
        if(IsolatedElectronID == "Loose")  isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
        if(IsolatedElectronID == "Medium") isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
        if(IsolatedElectronID == "Tight")  isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");

        if(VetoElectronID == "Veto")   isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
        if(VetoElectronID == "Loose")  isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
        if(VetoElectronID == "Medium") isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
        if(VetoElectronID == "Tight")  isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");
//*/
        PFIsodbeta03 = electron.relIso(0.3);
        SuperClusterEta = electron.scEta();
        PassConversionVeto = electron.passConversionVeto();
        ChargeConsistent = electron.isGsfCtfScPixChargeConsistent();
        // Gaussian Sum Fitter (GSF) Track
        // Combinatorial Track Finder (CTF) Track
        // Silicon Pixel Detector (ScPix)
        // error: 'const class cat::Electron' has no member named 'isGsfScPixChargeConsistent'

        if((SuperClusterEta < 1.4442 && PFIsodbeta03 < IsoCutLowEta) || (SuperClusterEta > 1.566 && PFIsodbeta03 < IsoCutHighEta)){
            if(isIsoElectronID && (electron.pt() > IsolatedElectronPt) && (std::abs(electron.eta()) < IsolatedElectronEta)){
                isIsolatedElectron = true;
                ++Num_IsolatedElectron;
                Index_IsolatedElectron.push_back(Index_Electron);
                if(!ChargeConsistent) Cut_e_Charge = false;
            }
        }
        if((SuperClusterEta < 1.4442 && PFIsodbeta03 < VetoCutLowEta) || (SuperClusterEta > 1.566 && PFIsodbeta03 < VetoCutHighEta)){
            if(isVetoElectronID && (electron.pt() > VetoElectronPt) && (std::abs(electron.eta()) < VetoElectronEta)){
                isVetoElectron = true;
                ++Num_VetoElectron;
                Index_VetoElectron.push_back(Index_Electron);
            }
        }

        ssbtreeManager->Fill( "Elec", electron.pt(), electron.eta(), electron.phi(), electron.energy(), Index_Electron );
        ssbtreeManager->Fill( "Elec_Cut_Isolated" , isIsolatedElectron   );
        ssbtreeManager->Fill( "Elec_Cut_Veto"     , isVetoElectron       );
        ssbtreeManager->Fill( "Elec_isIsoID"      , isIsoElectronID      );
        ssbtreeManager->Fill( "Elec_isVetoID"     , isVetoElectronID     );
        ssbtreeManager->Fill( "Elec_PFIsodBeta03" , PFIsodbeta03         );
        ssbtreeManager->Fill( "Elec_pdgId"        , electron.pdgId()     );
        ssbtreeManager->Fill( "Elec_Charge"       , electron.charge()    );
        ssbtreeManager->Fill( "Elec_Conversion"         , PassConversionVeto     );
        ssbtreeManager->Fill( "Elec_Supercluster_Eta"   , SuperClusterEta        );
        ssbtreeManager->Fill( "Elec_ChargeId_GsfCtfPx"  , ChargeConsistent       );

        ++Index_Electron;
    }

    for(int elec_i = 0; elec_i < Num_IsolatedElectron; ++elec_i){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
        if(IsoElectron.charge() > 0) ++Num_PlusElectron;
        if(IsoElectron.charge() < 0) ++Num_MinusElectron;
        ssbtreeManager->Fill( "Cut_Elec", IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy(), elec_i );
        LV_electron.SetPtEtaPhiE(IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy());
        LV_AllLepton += LV_electron;
        //if(sqrt( pow(LV_electron.Et()-LV_MET.Et(),2) + pow(LV_electron.Px()-LV_MET.Px(),2) + pow(LV_electron.Py()-LV_MET.Py(),2) ) < 120) Cut_MT_min = false;
        auto elec_a = std::find(Index_VetoElectron.begin(), Index_VetoElectron.end(), Index_IsolatedElectron.at(elec_i));
        if(elec_a != Index_VetoElectron.end()){
            Index_VetoElectron.erase(elec_a);
        } else {
            std::cout << "Electron? : " << Index_IsolatedElectron.at(elec_i) << "th Electron - Problem with Veto Cut" << endl;
        } 
    }

    Num_VetoElectron = Index_VetoElectron.size();
    if(Num_VetoElectron == 0) {
        Cut_e_ElectronVeto = true;
        if(Num_IsolatedElectron == 0) Cut_m_ElectronVeto = true;
    }

/*
    for(int elec_i = 0; elec_i < Num_IsolatedElectron; ++elec_i){
        for(int elec_j = 0; elec_j < Num_VetoElectron; ++elec_j){
            const cat::Electron &IsoElectron  = electrons->at(Index_IsolatedElectron.at(elec_i));
            const cat::Electron &VetoElectron = electrons->at(Index_VetoElectron.at(elec_j));
            LV_Iso.SetPtEtaPhiE(  IsoElectron.pt(),  IsoElectron.eta(),  IsoElectron.phi(),  IsoElectron.energy());
            LV_Veto.SetPtEtaPhiE(VetoElectron.pt(), VetoElectron.eta(), VetoElectron.phi(), VetoElectron.energy());
            LV_Iso += LV_Veto;
            if( (IsoElectron.charge()*VetoElectron.charge()<0) && ((LV_Iso.M()<12) || (LV_Iso.M()>76.2&&LV_Iso.M()<106.2)) ) Cut_e_MassVeto = false;
        }
    }
*/

    ssbtreeManager->Fill( "Elec_Count" ,        Index_Electron     );
    ssbtreeManager->Fill( "Num_PlusElectron",   Num_PlusElectron   );
    ssbtreeManager->Fill( "Num_MinusElectron",  Num_MinusElectron  );
    ssbtreeManager->Fill( "Cut_e_Charge",       Cut_e_Charge       );
    ssbtreeManager->Fill( "Cut_e_ElectronVeto", Cut_e_ElectronVeto );
    ssbtreeManager->Fill( "Cut_m_ElectronVeto", Cut_m_ElectronVeto );
//    ssbtreeManager->Fill( "Cut_e_MassVeto",     Cut_e_MassVeto     );

    ///////////////////////////////
    /// All Lepton Information  ///
    ///////////////////////////////

    Cut_ej_ElectronIso = false;
    Cut_mj_MuonIso = false;
    if(Num_IsolatedElectron == 1 && Num_IsolatedMuon == 0) Cut_ej_ElectronIso = true;
    if(Num_IsolatedElectron == 0 && Num_IsolatedMuon == 1) Cut_mj_MuonIso = true;

    Cut_ee_LeptonPair = false;
    Cut_mm_LeptonPair = false;
    Cut_em_LeptonPair = false;
    if(Num_IsolatedElectron == 2 && Num_IsolatedMuon == 0) Cut_ee_LeptonPair = true;
    if(Num_IsolatedElectron == 0 && Num_IsolatedMuon == 2) Cut_mm_LeptonPair = true;
    if(Num_IsolatedElectron == 1 && Num_IsolatedMuon == 1) Cut_em_LeptonPair = true;

    Cut_LeptonMass = false;
    if(LV_AllLepton.M() > InvariantMass+InvariantMassE || LV_AllLepton.M() < InvariantMass-InvariantMassE) Cut_LeptonMass = true;

    Cut_dl_Opposite = false;
    Cut_dl_Same = false;
    Num_PlusLepton = Num_PlusMuon + Num_PlusElectron;
    Num_MinusLepton = Num_MinusMuon + Num_MinusElectron;
    if((LV_AllLepton.M() > 20) && (Num_PlusLepton == 1 && Num_MinusLepton == 1)) Cut_dl_Opposite = true;
    if((LV_AllLepton.M() > 8) && ((Num_PlusLepton == 2 && Num_MinusLepton == 0) || (Num_PlusLepton == 0 && Num_MinusLepton == 2))) Cut_dl_Same = true;

//    ssbtreeManager->Fill( "Cut_ej_ElectronIso", Cut_ej_ElectronIso );
//    ssbtreeManager->Fill( "Cut_mj_MuonIso",     Cut_mj_MuonIso     );
    ssbtreeManager->Fill( "Cut_ee_LeptonPair",  Cut_ee_LeptonPair  );
    ssbtreeManager->Fill( "Cut_mm_LeptonPair",  Cut_mm_LeptonPair  );
    ssbtreeManager->Fill( "Cut_em_LeptonPair",  Cut_em_LeptonPair  );
    ssbtreeManager->Fill( "Cut_LeptonMass",     Cut_LeptonMass     );
    ssbtreeManager->Fill( "Cut_dl_Same",        Cut_dl_Same        );
    ssbtreeManager->Fill( "Cut_dl_Opposite",    Cut_dl_Opposite    );
    ssbtreeManager->Fill( "Num_PlusLepton",     Num_PlusLepton     );
    ssbtreeManager->Fill( "Num_MinusLepton",    Num_MinusLepton    );
    ssbtreeManager->Fill( "Cut_LeptonMass",     Cut_LeptonMass     );
//    ssbtreeManager->Fill( "Cut_MT_min",         Cut_MT_min         );

    /////////////////////////
    /// Jets Information  ///
    /////////////////////////

    Index_Jet = 0;
    Index_Cut_Jet = 0;
    Index_Cut_BJet = 0;
    Num_CleanedJet = 0;
    Num_BJet = 0;
    Index_CleanedJet.clear();
    Index_BJet.clear();
    LV_AllJet.SetPtEtaPhiE(0,0,0,0);
    HT = 0.0;
    HM = 0.0;
 
    iEvent.getByToken(jetToken_, jets);

    for (const cat::Jet &jet : *jets) 
    {

        isJet  = false;
        isCleanedJet = true;
        isBJet = false;

        bDiscriminator     = jet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
        cDiscriminatorCvsL = jet.bDiscriminator("pfCombinedCvsLJetTags");
        cDiscriminatorCvsB = jet.bDiscriminator("pfCombinedCvsBJetTags");
        qgLikelihood       = jet.qgLikelihood();

        if(JetID == "Loose") isJet = jet.LooseId();
        if(JetID == "Tight") isJet = jet.TightId();

        LV_jet.SetPtEtaPhiE(jet.pt(), jet.eta(), jet.phi(), jet.energy());
        for(int muon_i = 0; (muon_i < Num_IsolatedMuon) && isCleanedJet; ++muon_i){
            const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
            LV_muon.SetPtEtaPhiE(IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy());
            if(LV_muon.DeltaR(LV_jet) < JetCleaningdR) isCleanedJet = false;
        }
        for(int elec_i = 0; (elec_i < Num_IsolatedElectron) && isCleanedJet; ++elec_i){
            const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
            LV_electron.SetPtEtaPhiE(IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy());
            if(LV_electron.DeltaR(LV_jet) < JetCleaningdR) isCleanedJet = false;
        }

        if(isJet && isCleanedJet && (jet.pt() > JetPt) && (std::abs(jet.eta()) < JetEta)){
            LV_AllJet += LV_jet;
            HT += LV_jet.Et();
            ssbtreeManager->Fill( "Cut_Jet", jet.pt(), jet.eta(), jet.phi(), jet.energy(), Index_Cut_Jet );
            ssbtreeManager->Fill( "Cut_Jet_Index", Index_Jet );
            Index_CleanedJet.push_back(Index_Jet);
            ++Index_Cut_Jet;
            if(bDiscriminator > bDiscCut) {
                isBJet = true;
                Index_BJet.push_back(Index_Jet);
                ++Index_Cut_BJet;
            }
            ssbtreeManager->Fill( "Cut_Jet_bTag" , isBJet );
        }

        ssbtreeManager->Fill( "Jet", jet.pt(), jet.eta(), jet.phi(), jet.energy(), Index_Jet );
        ssbtreeManager->Fill( "Jet_isJetID",      isJet              );
        ssbtreeManager->Fill( "Jet_isCleanedJet", isCleanedJet       );
        ssbtreeManager->Fill( "Jet_bDisc",        bDiscriminator     );
        ssbtreeManager->Fill( "Jet_cDiscCvsL",    cDiscriminatorCvsL );
        ssbtreeManager->Fill( "Jet_cDiscCvsB",    cDiscriminatorCvsB );
        ssbtreeManager->Fill( "Jet_qgLikelihood", qgLikelihood       );
  
        ++Index_Jet;
    }

    Num_CleanedJet = Index_CleanedJet.size(); // same as Index_Cut_Jet
    Num_BJet       = Index_BJet.size();       // same as Index_Cut_BJet
    ssbtreeManager->Fill( "Jet_Count",      Index_Jet      );
    ssbtreeManager->Fill( "Cut_Jet_Count",  Index_Cut_Jet  );
    ssbtreeManager->Fill( "Cut_BJet_Count", Index_Cut_BJet );
    ssbtreeManager->Fill( "HT",             HT             );
    if(Index_Cut_Jet>0) HM = LV_AllJet.M();
    ssbtreeManager->Fill( "HM",             HM             );

    CutStep(); // CutStep.h

    /// Fill Ntuples at each event
    FillNTuple = false;
    for(int i_Channel=0; i_Channel<(int)CutChannelName.size(); ++i_Channel){
        if(Cut_Step[CutChannelName[i_Channel]][Save_CutStep]) FillNTuple = true;
    }
    if(FillNTuple) ssbtreeManager->FillNtuple();

    FillHistogram(); // SSBFillHistogram.h : after CutStep()

    } // FillNTuple
}


// ------------ method called once each job just before starting event loop  ------------
void 
SSBConverter::beginJob()
{
   ssbtree = ssbfs->make<TTree>("SSBTree", "Tree for Physics Analyses at CMS");
   ssbtreeManager = new SSBTreeManager();
   ssbtreeManager->Book(ssbtree);
   ssbhist = ssbfs->mkdir("SSBHist", "Tree for Physics Analyses at CMS");
   ssbhistManager = new SSBHistManager(CutChannelName,CutStepName);
   ssbhistManager->Book(ssbhist);
   ssbhistManager->InitializeHist();
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SSBConverter::endJob() 
{
    //ssbhistManager->FillHist();
}

// ------------ method called when starting to processes a run  ------------
void 
SSBConverter::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
SSBConverter::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
SSBConverter::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
SSBConverter::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
SSBConverter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(SSBConverter);
