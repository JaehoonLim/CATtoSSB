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
debugcout(             iConfig.getUntrackedParameter< bool >(                     "Debug_cout",         false                 )), 

Save_Channel(          iConfig.getUntrackedParameter< std::vector<std::string> >( "Save_Channel"                              )), 
Save_CutStep(          iConfig.getUntrackedParameter< std::string >(              "Save_CutStep",       std::string("2")      )), 
Save_Inversion(        iConfig.getUntrackedParameter< bool >(                     "Save_Inversion",     false                 )), 
CheckBG(               iConfig.getUntrackedParameter< std::vector<std::string> >( "CheckBG"                                   )), 

Channel(               iConfig.getUntrackedParameter< std::string >(              "Channel",            std::string("FourTop Tri-Lepton")  )), 

Try_Cut_Trigger(       iConfig.getUntrackedParameter< bool >(                     "Do_Trigger_Cut",     true                  )), 
e_Trigger(             iConfig.getUntrackedParameter< std::vector<std::string> >( "e_Trigger"                                 )),
m_Trigger(             iConfig.getUntrackedParameter< std::vector<std::string> >( "m_Trigger"                                 )),
em_Trigger(            iConfig.getUntrackedParameter< std::vector<std::string> >( "em_Trigger"                                )),

IsolatedMuonID(        iConfig.getUntrackedParameter< std::string >(              "MuonID",             std::string("Tight")  )), 
IsolatedMuonPt(        iConfig.getUntrackedParameter< double >(                   "MuonPt",             26.0                  )),
IsolatedMuonEta(       iConfig.getUntrackedParameter< double >(                   "MuonEta",            2.1                   )),
IsolatedMuonIso(       iConfig.getUntrackedParameter< double >(                   "MuonIso",            0.15                  )),
IsolatedMuonMultiIso(  iConfig.getUntrackedParameter< bool >(                     "Do_Muon_MultiIso",   false                 )),
IsolatedMuonMiniIso(   iConfig.getUntrackedParameter< double >(                   "MuonMiniIso",        0.4                   )),
IsolatedMuonPtRatio(   iConfig.getUntrackedParameter< double >(                   "MuonPtRatio",        0.0                   )),
IsolatedMuonPtRel(     iConfig.getUntrackedParameter< double >(                   "MuonPtRel",          0.0                   )),

IsolatedElectronID(    iConfig.getUntrackedParameter< std::string >(              "ElectronID",         std::string("Medium") )), 
IsolatedElectronPt(    iConfig.getUntrackedParameter< double >(                   "ElectronPt",         30.0                  )),
IsolatedElectronEta(   iConfig.getUntrackedParameter< double >(                   "ElectronEta",        2.4                   )),
IsolatedElectronIso(   iConfig.getUntrackedParameter< std::string >(              "ElectronIso",        std::string("Medium") )), 
IsolatedElectronMultiIso(  iConfig.getUntrackedParameter< bool >(                 "Do_Elec_MultiIso",   false                 )),
IsolatedElectronMiniIso(   iConfig.getUntrackedParameter< double >(               "ElectronMiniIso",    0.4                   )),
IsolatedElectronPtRatio(   iConfig.getUntrackedParameter< double >(               "ElectronPtRatio",    0.0                   )),
IsolatedElectronPtRel(     iConfig.getUntrackedParameter< double >(               "ElectronPtRel",      0.0                   )),

Try_Cut_Additional(    iConfig.getUntrackedParameter< bool >(                     "Do_Additional_Cut",  false                 )),
TightLooseMethod(      iConfig.getUntrackedParameter< bool >(                     "Do_TightLoose",      false                 )),
AdditionalMuonID(      iConfig.getUntrackedParameter< std::string >(              "Add_MuonID",         std::string("Tight")  )), 
AdditionalMuonPt(      iConfig.getUntrackedParameter< double >(                   "Add_MuonPt",         26.0                  )),
AdditionalMuonEta(     iConfig.getUntrackedParameter< double >(                   "Add_MuonEta",        2.1                   )),
AdditionalMuonIso(     iConfig.getUntrackedParameter< double >(                   "Add_MuonIso",        0.15                  )),
AdditionalMuonMultiIso(iConfig.getUntrackedParameter< bool >(                     "Do_Add_Muon_MultiIso",   false                 )),
AdditionalMuonMiniIso( iConfig.getUntrackedParameter< double >(                   "Add_MuonMiniIso",    0.4                   )),
AdditionalMuonPtRatio( iConfig.getUntrackedParameter< double >(                   "Add_MuonPtRatio",    0.0                   )),
AdditionalMuonPtRel(   iConfig.getUntrackedParameter< double >(                   "Add_MuonPtRel",      0.0                   )),

AdditionalElectronID(  iConfig.getUntrackedParameter< std::string >(              "Add_ElectronID",     std::string("Medium") )), 
AdditionalElectronPt(  iConfig.getUntrackedParameter< double >(                   "Add_ElectronPt",     30.0                  )),
AdditionalElectronEta( iConfig.getUntrackedParameter< double >(                   "Add_ElectronEta",    2.4                   )),
AdditionalElectronIso( iConfig.getUntrackedParameter< std::string >(              "Add_ElectronIso",    std::string("Medium") )), 
AdditionalElectronMultiIso(  iConfig.getUntrackedParameter< bool >(               "Do_Add_Elec_MultiIso",   false                 )),
AdditionalElectronMiniIso(   iConfig.getUntrackedParameter< double >(             "Add_ElectronMiniIso",0.4                   )),
AdditionalElectronPtRatio(   iConfig.getUntrackedParameter< double >(             "Add_ElectronPtRatio",0.0                   )),
AdditionalElectronPtRel(     iConfig.getUntrackedParameter< double >(             "Add_ElectronPtRel",  0.0                   )),

VetoMuonID(            iConfig.getUntrackedParameter< std::string >(              "veto_MuonID",        std::string("Loose")  )), 
VetoMuonPt(            iConfig.getUntrackedParameter< double >(                   "veto_MuonPt",        10.0                  )),
VetoMuonEta(           iConfig.getUntrackedParameter< double >(                   "veto_MuonEta",       2.4                   )),
VetoMuonIso(           iConfig.getUntrackedParameter< double >(                   "veto_MuonIso",       0.25                  )),
VetoMuonMultiIso(      iConfig.getUntrackedParameter< bool >(                     "Do_veto_Muon_MultiIso",   false                 )),
VetoMuonMiniIso(       iConfig.getUntrackedParameter< double >(                   "veto_MuonMiniIso",    0.4                   )),
VetoMuonPtRatio(       iConfig.getUntrackedParameter< double >(                   "veto_MuonPtRatio",    0.0                   )),
VetoMuonPtRel(         iConfig.getUntrackedParameter< double >(                   "veto_MuonPtRel",      0.0                   )),

VetoElectronID(        iConfig.getUntrackedParameter< std::string >(              "veto_ElectronID",    std::string("Veto")   )), 
VetoElectronPt(        iConfig.getUntrackedParameter< double >(                   "veto_ElectronPt",    10.0                  )),
VetoElectronEta(       iConfig.getUntrackedParameter< double >(                   "veto_ElectronEta",   2.4                   )),
VetoElectronIso(       iConfig.getUntrackedParameter< std::string >(              "veto_ElectronIso",   std::string("Veto")   )), 
VetoElectronMultiIso(  iConfig.getUntrackedParameter< bool >(                     "Do_veto_Elec_MultiIso",   false            )),
VetoElectronMiniIso(   iConfig.getUntrackedParameter< double >(                   "veto_ElectronMiniIso",    0.4              )),
VetoElectronPtRatio(   iConfig.getUntrackedParameter< double >(                   "veto_ElectronPtRatio",    0.0              )),
VetoElectronPtRel(     iConfig.getUntrackedParameter< double >(                   "veto_ElectronPtRel",      0.0              )),

JetID(                 iConfig.getUntrackedParameter< std::string >(              "JetID",              std::string("Loose")  )),   
JetPt(                 iConfig.getUntrackedParameter< double >(                   "JetPt",              30.0                  )),
JetEta(                iConfig.getUntrackedParameter< double >(                   "JetEta",             2.4                   )),
JetBTag(               iConfig.getUntrackedParameter< std::string >(              "BTag",               std::string("Medium") )),
JetCleaningdR(         iConfig.getUntrackedParameter< double >(                   "CleaningdR",         0.4                   )),

InvariantMass(         iConfig.getUntrackedParameter< double >(                   "InvariantMass",      91.2                  )),
InvariantMassE(        iConfig.getUntrackedParameter< double >(                   "PlusMinus",          15.0                  )),
METPt(                 iConfig.getUntrackedParameter< double >(                   "METPt",              0.0                   ))
{
    //now do what ever initialization is needed

    genParInfoTag    = consumes<reco::GenParticleCollection> (iConfig.getParameter<edm::InputTag>("genParTag"));
    genJetInfoTag    = consumes<reco::GenJetCollection>      (iConfig.getParameter<edm::InputTag>("genJetTag"));

    genWeightToken_  = consumes<cat::GenWeights>             (iConfig.getParameter<edm::InputTag>("genWeightTag"));

    lumiMaskToken_   = consumes<int>                         (iConfig.getParameter<edm::InputTag>("lumiMaskTag"));

    muonToken_       = consumes<cat::MuonCollection>         (iConfig.getParameter<edm::InputTag>("muonTag"));
    electronToken_   = consumes<cat::ElectronCollection>     (iConfig.getParameter<edm::InputTag>("electronTag"));
    jetToken_        = consumes<cat::JetCollection>          (iConfig.getParameter<edm::InputTag>("jetTag"));
    metToken_        = consumes<cat::METCollection>          (iConfig.getParameter<edm::InputTag>("metTag"));

    npvToken_        = consumes<int>                         (iConfig.getParameter<edm::InputTag>("npvTag"));
    PUWeightToken_   = consumes<float>                       (iConfig.getParameter<edm::InputTag>("PileUpWeightTag"));

    for(auto& trig : iConfig.getParameter<std::vector<edm::InputTag>>("triggerBitsTag")) {
        triggerBits_.push_back(consumes<edm::TriggerResults>(trig));
    }
    for(auto& filt : iConfig.getParameter<std::vector<edm::InputTag>>("EventFilterBitsTag")) {
        EventFilterBits_.push_back(consumes<edm::TriggerResults>(filt));
    }

    const auto MuonSFParameter = iConfig.getParameter<edm::ParameterSet>("MuonSF");
    MuonSFEval = new ScaleFactorEvaluator();
    MuonSFEval->set(MuonSFParameter.getParameter<std::vector<double>>("pt_bins"),
                   MuonSFParameter.getParameter<std::vector<double>>("eta_bins"),
                   MuonSFParameter.getParameter<std::vector<double>>("values"),
                   MuonSFParameter.getParameter<std::vector<double>>("errors"));
    const auto ElecSFParameter = iConfig.getParameter<edm::ParameterSet>("ElectronSF");
    ElectronSFEval = new ScaleFactorEvaluator();
    ElectronSFEval->set(ElecSFParameter.getParameter<std::vector<double>>("pt_bins"),
                       ElecSFParameter.getParameter<std::vector<double>>("eta_bins"),
                       ElecSFParameter.getParameter<std::vector<double>>("values"),
                       ElecSFParameter.getParameter<std::vector<double>>("errors"));

    ssbgeninfor = new SSBGenInfor(iConfig);

    CutChannelName = {"ee","mm","em"};
    CutStepName = {"0a","0b","0c","1a","1b","2","3","4","5"};
    if(Channel == "FourTop Tri-Lepton"){
        CutChannelName = {"ss_ee_e","os_ee_e","ss_ee_m","os_ee_m","ss_em_e","os_em_e","ss_em_m","os_em_m","ss_mm_e","os_mm_e","ss_mm_m","os_mm_m",
                          "eee","mmm","ss_eem","os_eem","eem","ss_emm","os_emm","emm"};
        CutStepName = {"0a","0b","0c","1","2","3","4","5","6a","6b","7","8","9"};
    }
    if(Channel == "TTbar Di-Lepton"){
        CutStepName = {"0a","0b","0c","1","2","3","4","5"};
    }
    if(Channel == "FourTop SUSY"){
        CutStepName = {"0a","0b","0c","0d","1a","BL","SRW","SR1","SR2","SR3","SR4","SR5","SR6","1b","BL2","SR7","SR8","SRZ"};
    }

    EventFilter = {"Flag_HBHENoiseFilter", "Flag_HBHENoiseIsoFilter", "Flag_EcalDeadCellTriggerPrimitiveFilter", "Flag_goodVertices", "Flag_eeBadScFilter", "Flag_globalTightHalo2016Filter", "Flag_badPFMuon", "Flag_badChargedHadron"};

    Num_e_Trigger  = e_Trigger.size();
    Num_m_Trigger  = m_Trigger.size();
    Num_em_Trigger = em_Trigger.size();

    if(IsolatedMuonID != "Loose" && IsolatedMuonID != "Medium" && IsolatedMuonID != "Tight" && IsolatedMuonID != "Soft"){
        cout << endl << "MuonID Error"<< endl << endl;
        cerr << endl << "MuonID Error"<< endl << endl;
    }

    if(AdditionalMuonID != "Loose" && AdditionalMuonID != "Medium" && AdditionalMuonID != "Tight" && AdditionalMuonID != "Soft"){
        cout << endl << "MuonID Error"<< endl << endl;
        cerr << endl << "MuonID Error"<< endl << endl;
    }

    if(VetoMuonID != "Loose" && VetoMuonID != "Medium" && VetoMuonID != "Tight" && VetoMuonID != "Soft"){
        cout << endl << "VetoMuonID Error"<< endl << endl;
        cerr << endl << "VetoMuonID Error"<< endl << endl;
    }

    if(IsolatedElectronIso == "Loose"){
        IsoCutLowEta  = 0.0994;
        IsoCutHighEta = 0.1070;
    } else if(IsolatedElectronIso == "Medium"){
        IsoCutLowEta  = 0.0695;
        IsoCutHighEta = 0.0821;
    } else if(IsolatedElectronIso == "Tight"){
        IsoCutLowEta  = 0.0588;
        IsoCutHighEta = 0.0571;
    } else if(IsolatedElectronIso == "Veto"){
        IsoCutLowEta  = 0.175;
        IsoCutHighEta = 0.159;
    } else if(IsolatedElectronIso == "TEMP"){
        IsoCutLowEta  = 10.000;
        IsoCutHighEta = 10.000;
    } else {
        cout << endl << "ElectronID Error"<< endl << endl;
        cerr << endl << "ElectronID Error"<< endl << endl;
        IsoCutLowEta  = 0.0000;
        IsoCutHighEta = 0.0000;
    } 

    if(AdditionalElectronIso == "Loose"){
        AddCutLowEta  = 0.0994;
        AddCutHighEta = 0.1070;
    } else if(AdditionalElectronIso == "Medium"){
        AddCutLowEta  = 0.0695;
        AddCutHighEta = 0.0821;
    } else if(AdditionalElectronIso == "Tight"){
        AddCutLowEta  = 0.0588;
        AddCutHighEta = 0.0571;
    } else if(AdditionalElectronIso == "Veto"){
        AddCutLowEta  = 0.175;
        AddCutHighEta = 0.159;
    } else if(AdditionalElectronIso == "TEMP"){
        AddCutLowEta  = 10.000;
        AddCutHighEta = 10.000;
    } else {
        cout << endl << "AddElectronID Error"<< endl << endl;
        cerr << endl << "AddElectronID Error"<< endl << endl;
        AddCutLowEta  = 0.0000;
        AddCutHighEta = 0.0000;
    } 

    if(VetoElectronIso == "Loose"){
        VetoCutLowEta  = 0.0994;
        VetoCutHighEta = 0.1070;
    } else if(VetoElectronIso == "Medium"){
        VetoCutLowEta  = 0.0695;
        VetoCutHighEta = 0.0821;
    } else if(VetoElectronIso == "Tight"){
        VetoCutLowEta  = 0.0588;
        VetoCutHighEta = 0.0571;
    } else if(VetoElectronIso == "Veto"){
        VetoCutLowEta  = 0.175;
        VetoCutHighEta = 0.159;
    } else if(VetoElectronIso == "TEMP"){
        VetoCutLowEta  = 10.000;
        VetoCutHighEta = 10.000;
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

    if(JetBTag == "Loose")  bDiscCut = 0.5426;
    else if(JetBTag == "Medium") bDiscCut = 0.8484;
    else if(JetBTag == "Tight")  bDiscCut = 0.9535;
    else {
        cout << endl << "BTag Error"<< endl << endl;
        cerr << endl << "BTag Error"<< endl << endl;
        bDiscCut = 1.00;
    }

    for(int i_Channel=0; i_Channel<(int)CutChannelName.size(); ++i_Channel){
        EventInfo[i_Channel] = ssbfs->make<TH1D>(Form("%s_EventInfo",CutChannelName[i_Channel].c_str()),Form("%s Event Information",CutChannelName[i_Channel].c_str()),CutStepName.size()+1,-1,CutStepName.size());
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

    if(debugcout) cout << "analyze() Start" << endl;

    // Initailizing variable 
    ssbtreeManager->InitializeVariables(); 

    Event = -999;
    Run = -999;
    Lumi = -999;
    isData = false;
    ChannelName = "Background";
    FillNTuple = false;
    GenWeight = 1.0;
    PileUpWeight = 1.0;
    LeptonWeight = 1.0;
    AddLeptonWeight = 1.0;

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
      
        if(debugcout) cout << "Generator Level Particle Informaton" << endl;
        ssbgeninfor->GenPar(iEvent, ssbtreeManager);
        ssbgeninfor->GenJet(iEvent, ssbtreeManager);

        //////////////////
        /// Gen Weight ///
        //////////////////

        if(debugcout) cout << "Gen Weight" << endl;
        edm::Handle<cat::GenWeights> genWeight;
        iEvent.getByToken(genWeightToken_, genWeight);
        GenWeight = (double)genWeight->genWeight();

        /////////////////////
        /// Pileup Weight ///
        /////////////////////

        if(debugcout) cout << "Pileup Weight" << endl;
        edm::Handle<float> pileupWeight;
        iEvent.getByToken( PUWeightToken_, pileupWeight);
        PileUpWeight = (double)*pileupWeight;

        ChannelName = ssbgeninfor->ReturnChannel(iEvent);

        for(auto Channel_i : Save_Channel){ 
            if(Channel_i == "ALL" || ChannelName.find(Channel_i) != std::string::npos) FillNTuple = true;
        }

        if(Save_Inversion) FillNTuple = !FillNTuple;

    } else {
        ChannelName = "Data";
        FillNTuple = true;
        edm::Handle<int> lumiMask;
        iEvent.getByToken(lumiMaskToken_, lumiMask);
        if (*lumiMask == 0) FillNTuple = false;
    }

    GenInfo->Fill(1,GenWeight);

    if(FillNTuple) {
                                            
    ssbtreeManager->Fill( "GenWeight" , GenWeight );
    ssbtreeManager->Fill( "PileUpWeight", PileUpWeight );

    ////////////////////////////////////
    /// Primary Vertices Information ///
    ////////////////////////////////////

    if(debugcout) cout << "Primary Vertices Information" << endl;
    numPV = 0;
    edm::Handle<int> Num_PV;
    iEvent.getByToken( npvToken_, Num_PV );
    numPV = (int)*Num_PV;
    ssbtreeManager->Fill( "PV_Count", numPV );

    ////////////////////
    /// Event Filter ///
    ////////////////////

    if(debugcout) cout << "Event Filter" << endl;
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

    ///////////////////////////
    /// Trigger Information ///
    ///////////////////////////

    if(debugcout) cout << "Trigger Information" << endl;
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

    ///////////////////////
    /// MET Information ///
    ///////////////////////
    
    if(debugcout) cout << "MET Information" << endl;
    Cut_MET = false;

    iEvent.getByToken(metToken_, mets);
    const cat::MET &met = mets->at(0);
    if(met.pt() != met.pt()){ // Check -NaN
        LV_MET.SetPtEtaPhiE(0, 0, 0, 0);
        ssbtreeManager->Fill( "MET" , 0, 0, 0, 0, 0 );
    } else {
        LV_MET.SetPtEtaPhiE(met.pt(), met.eta(), met.phi(), met.energy());
        ssbtreeManager->Fill( "MET" , met.pt(), 0, met.phi(), 0, 0 );
        if(met.pt() > METPt){
            Cut_MET = true;
        }
    }
    ssbtreeManager->Fill( "Cut_MET", Cut_MET );

    /////////////////////
    /// Lepton Start ////
    /////////////////////

    if(debugcout) cout << "Muon Information" << endl;
    Num_PlusLepton = 0;
    Num_MinusLepton = 0;
    LV_AllLepton.SetPtEtaPhiE(0,0,0,0);
    //Cut_MT_min = true;
    iEvent.getByToken(jetToken_, jets);

    /////////////////////////
    /// Muon Information ////
    /////////////////////////

    vSF_Muon.clear();
    v_Muon_Iso03.clear();
    v_Muon_Iso04.clear();
    v_Muon_miniIso.clear();
    v_Muon_Pt_rel.clear();
    v_Muon_Pt_ratio.clear();

    Cut_e_MuonVeto = false;
    Cut_m_MuonVeto = false;
    Cut_m_Charge = true;
    //Cut_m_MassVeto = true;

    iEvent.getByToken(muonToken_, muons);

    Index_Muon = 0; 
    Index_IsolatedMuon.clear();
    Num_IsolatedMuon = 0;
    Num_PlusMuon = 0;
    Num_MinusMuon = 0;
    Index_AdditionalMuon.clear();
    Num_AdditionalMuon = 0;
    Index_VetoMuon.clear();
    Num_VetoMuon = 0;

    SF_Muon = 1.0;
    MT_Muon = 0.0;

    //memset(CutTest, 0, sizeof(CutTest));

    for (const cat::Muon &muon : *muons)
    {

        isIsolatedMuon = false;
        isAdditionalMuon = false;
        isVetoMuon = false;

        isIsoIDMuon = false;
        isAddIDMuon = false;
        isVetoIDMuon = false;

        if(IsolatedMuonID == "Loose")         isIsoIDMuon = muon.isLooseMuon();
        else if(IsolatedMuonID == "Medium")   isIsoIDMuon = muon.isMediumMuon();
        else if(IsolatedMuonID == "Tight")    isIsoIDMuon = muon.isTightMuon();
        else if(IsolatedMuonID == "Soft")     isIsoIDMuon = muon.isSoftMuon();

        if(AdditionalMuonID == "Loose")       isAddIDMuon = muon.isLooseMuon();
        else if(AdditionalMuonID == "Medium") isAddIDMuon = muon.isMediumMuon();
        else if(AdditionalMuonID == "Tight")  isAddIDMuon = muon.isTightMuon();
        else if(AdditionalMuonID == "Soft")   isAddIDMuon = muon.isSoftMuon();

        if(VetoMuonID == "Loose")             isVetoIDMuon = muon.isLooseMuon();
        else if(VetoMuonID == "Medium")       isVetoIDMuon = muon.isMediumMuon();
        else if(VetoMuonID == "Tight")        isVetoIDMuon = muon.isTightMuon();
        else if(VetoMuonID == "Soft")         isVetoIDMuon = muon.isSoftMuon();
        // error: 'const class cat::Muon' has no member named 'isHighPtMuon'

        PFIsodbeta04 = muon.relIso(0.4);
        v_Muon_Iso04.push_back(PFIsodbeta04);
        v_Muon_Iso03.push_back(muon.relIso(0.3));
        v_Muon_miniIso.push_back(muon.miniRelIso());
        LV_muon = muon.tlv();
        if(LV_MET.Phi() > -1 * TMath::Pi() && LV_MET.Phi() < TMath::Pi()){
            MT_Muon = sqrt(2.0*LV_muon.Pt()*LV_MET.Pt()*(1-cos(LV_muon.DeltaPhi(LV_MET))));
        } else {
            MT_Muon = -999.9;
        }
        muon_ClosestdR = 999.9;
        muon_Pt_rel = -999.9;
        muon_Pt_ratio = -999.9;
        for (const cat::Jet &jet : *jets){ 
            LV_jet = jet.tlv();
            if(LV_muon.DeltaR(LV_jet) < muon_ClosestdR) {
                muon_ClosestdR = LV_muon.DeltaR(LV_jet);
                muon_Pt_ratio = LV_muon.Pt() / LV_jet.Pt();
                muon_Pt_rel = ((LV_jet.Vect() - LV_muon.Vect()).Cross(LV_muon.Vect())).Mag() / (LV_jet.Vect() - LV_muon.Vect()).Mag();
            }
        }
        v_Muon_Pt_rel.push_back(muon_Pt_rel);
        v_Muon_Pt_ratio.push_back(muon_Pt_ratio);

        SF_Muon = MuonSFEval->get(muon.pt(),muon.eta());
        vSF_Muon.push_back(SF_Muon);

        MuonPtError = muon.pt()*muon.shiftedEn();

/*
         pt = muon.pt();
         lep_iso = PFIsodbeta04;
         for(int id_i=0; id_i<4; ++id_i){
            if(id_i==0){      CutID1 = muon.isMediumMuon(); CutID2 = muon.isMediumMuon(); CutID3 = muon.isMediumMuon(); }
            else if(id_i==1){ CutID1 = muon.isTightMuon();  CutID2 = muon.isMediumMuon(); CutID3 = muon.isMediumMuon(); }
            else if(id_i==2){ CutID1 = muon.isTightMuon();  CutID2 = muon.isTightMuon();  CutID3 = muon.isMediumMuon(); }
            else {            CutID1 = muon.isTightMuon();  CutID2 = muon.isTightMuon();  CutID3 = muon.isTightMuon();  }

            for(int iso_i=0; iso_i<10; ++iso_i){
               for(int pt_i=0; pt_i<10; ++pt_i){

                  if(CutID1 && lep_iso<Muon_Iso[Cut1[iso_i]] && pt>Lep_Pt[Cut1[pt_i]] && std::abs(muon.eta())<2.4){ ++CutTest[id_i][iso_i][pt_i][0]; }
                  if(CutID2 && lep_iso<Muon_Iso[Cut2[iso_i]] && pt>Lep_Pt[Cut2[pt_i]] && std::abs(muon.eta())<2.4){ ++CutTest[id_i][iso_i][pt_i][1]; }
                  if(CutID3 && lep_iso<Muon_Iso[Cut3[iso_i]] && pt>Lep_Pt[Cut3[pt_i]] && std::abs(muon.eta())<2.4){ ++CutTest[id_i][iso_i][pt_i][2]; }

               }
            }
         }
*/

        if(!Try_Cut_Additional && isIsoIDMuon && (muon.pt() > IsolatedMuonPt) && (std::abs(muon.eta()) < IsolatedMuonEta) &&
            ((!IsolatedMuonMultiIso && PFIsodbeta04 < IsolatedMuonIso) ||
                (IsolatedMuonMultiIso &&
                ( (double)muon.miniRelIso() < IsolatedMuonMiniIso && (muon_Pt_rel > IsolatedMuonPtRel || muon_Pt_ratio > IsolatedMuonPtRatio) )
                )
            )
        ){

            isIsolatedMuon = true;
            Index_IsolatedMuon.push_back(Index_Muon);
            if(MuonPtError/LV_muon.Pt()>0.3) Cut_m_Charge = false;
            ssbtreeManager->Fill( "Cut_Muon", muon.pt(), muon.eta(), muon.phi(), muon.energy(), Num_IsolatedMuon );
            ++Num_IsolatedMuon;
            ssbtreeManager->Fill( "Cut_Muon_PFIsodBeta03" , (double)muon.relIso(0.3) );
            ssbtreeManager->Fill( "Cut_Muon_PFIsodBeta04" , PFIsodbeta04      );
            ssbtreeManager->Fill( "Cut_Muon_miniRelIso"   , (double)muon.miniRelIso() );
            ssbtreeManager->Fill( "Cut_Muon_ClosestJetdR" , muon_ClosestdR    );
            ssbtreeManager->Fill( "Cut_Muon_Pt_rel"       , muon_Pt_rel       );
            ssbtreeManager->Fill( "Cut_Muon_Pt_rat"       , muon_Pt_ratio     );
            ssbtreeManager->Fill( "Cut_Muon_dxy"          , (double)muon.dxy() );
            ssbtreeManager->Fill( "Cut_Muon_dz"           , (double)muon.dz() );
            ssbtreeManager->Fill( "Cut_Muon_MT"           , MT_Muon           );
        } else if(Try_Cut_Additional && isAddIDMuon && (muon.pt() > AdditionalMuonPt) && (std::abs(muon.eta()) < AdditionalMuonEta) &&
            ((!AdditionalMuonMultiIso && PFIsodbeta04 < AdditionalMuonIso) ||
                (AdditionalMuonMultiIso &&
                ((double)muon.miniRelIso() < AdditionalMuonMiniIso && (muon_Pt_rel > AdditionalMuonPtRel || muon_Pt_ratio > AdditionalMuonPtRatio) )
                )
            )
        ){

            if(isIsoIDMuon && (muon.pt() > IsolatedMuonPt) && (std::abs(muon.eta()) < IsolatedMuonEta) &&
                ((!IsolatedMuonMultiIso && PFIsodbeta04 < IsolatedMuonIso) ||
                    (IsolatedMuonMultiIso &&
                    ( (double)muon.miniRelIso() < IsolatedMuonMiniIso && (muon_Pt_rel > IsolatedMuonPtRel || muon_Pt_ratio > IsolatedMuonPtRatio) )
                    )
                )
            ){

                isIsolatedMuon = true;
                Index_IsolatedMuon.push_back(Index_Muon);
                if(MuonPtError/LV_muon.Pt()>0.3) Cut_m_Charge = false;
                ssbtreeManager->Fill( "Cut_Muon", muon.pt(), muon.eta(), muon.phi(), muon.energy(), Num_IsolatedMuon );
                ++Num_IsolatedMuon;
                ssbtreeManager->Fill( "Cut_Muon_PFIsodBeta03" , (double)muon.relIso(0.3)  );
                ssbtreeManager->Fill( "Cut_Muon_PFIsodBeta04" , PFIsodbeta04      );
                ssbtreeManager->Fill( "Cut_Muon_miniRelIso"   , (double)muon.miniRelIso() );
                ssbtreeManager->Fill( "Cut_Muon_ClosestJetdR" , muon_ClosestdR    );
                ssbtreeManager->Fill( "Cut_Muon_Pt_rel"       , muon_Pt_rel       );
                ssbtreeManager->Fill( "Cut_Muon_Pt_rat"       , muon_Pt_ratio     );
                ssbtreeManager->Fill( "Cut_Muon_dxy"          , (double)muon.dxy() );
                ssbtreeManager->Fill( "Cut_Muon_dz"           , (double)muon.dz() );
                ssbtreeManager->Fill( "Cut_Muon_MT"           , MT_Muon           );
            } else {
                isAdditionalMuon = true;
                ++Num_AdditionalMuon;
                Index_AdditionalMuon.push_back(Index_Muon);
                //if(MuonPtError/LV_muon.Pt()>0.3) Cut_m_Charge = false;
            }
        } else if(isVetoIDMuon && (muon.pt() > VetoMuonPt) && (std::abs(muon.eta()) < VetoMuonEta) &&
            ((!VetoMuonMultiIso && PFIsodbeta04 < VetoMuonIso) ||
                (VetoMuonMultiIso &&
                ( (double)muon.miniRelIso() < VetoMuonMiniIso && (muon_Pt_rel > VetoMuonPtRel || muon_Pt_ratio > VetoMuonPtRatio) )
                )
            )
        ){
            isVetoMuon = true;
            ++Num_VetoMuon;
            Index_VetoMuon.push_back(Index_Muon);
        }

        ssbtreeManager->Fill( "Muon", muon.pt(), muon.eta(), muon.phi(), muon.energy(), Index_Muon );
        ssbtreeManager->Fill( "Muon_Cut_Isolated"     , isIsolatedMuon       );
        ssbtreeManager->Fill( "Muon_Cut_Additional"   , isAdditionalMuon     );
        ssbtreeManager->Fill( "Muon_Cut_Veto"         , isVetoMuon           );
        ssbtreeManager->Fill( "Muon_isTight"          , muon.isTightMuon()   );
        ssbtreeManager->Fill( "Muon_isMedium"         , muon.isMediumMuon()  );
        ssbtreeManager->Fill( "Muon_isLoose"          , muon.isLooseMuon()   );
        ssbtreeManager->Fill( "Muon_isSoft"           , muon.isSoftMuon()    );
        ssbtreeManager->Fill( "Muon_isIsoID"          , isIsoIDMuon          ); 
        ssbtreeManager->Fill( "Muon_isAddID"          , isAddIDMuon          ); 
        ssbtreeManager->Fill( "Muon_isVetoID"         , isVetoIDMuon         );
        ssbtreeManager->Fill( "Muon_PFIsodBeta03"     , (double)muon.relIso(0.3)  );
        ssbtreeManager->Fill( "Muon_PFIsodBeta04"     , PFIsodbeta04         );
        ssbtreeManager->Fill( "Muon_miniRelIso"       , (double)muon.miniRelIso() );
        ssbtreeManager->Fill( "Muon_ClosestJetdR"     , muon_ClosestdR       );
        ssbtreeManager->Fill( "Muon_Pt_rel"           , muon_Pt_rel          );
        ssbtreeManager->Fill( "Muon_Pt_rat"           , muon_Pt_ratio        );
        ssbtreeManager->Fill( "Muon_dxy"              , (double)muon.dxy()   );
        ssbtreeManager->Fill( "Muon_dz"               , (double)muon.dz()    );
        ssbtreeManager->Fill( "Muon_pdgId"            , muon.pdgId()         );
        ssbtreeManager->Fill( "Muon_Charge"           , muon.charge()        );
        ssbtreeManager->Fill( "Muon_ScaleFactor"      , SF_Muon              );
        //ssbtreeManager->Fill( "Muon_CorrectedPt"      , (double)LV_muon.Pt() );
        ssbtreeManager->Fill( "Muon_CorrectedPtError" , (double)MuonPtError  );
        ssbtreeManager->Fill( "Muon_dPtOverPt"        , (double)(MuonPtError/LV_muon.Pt()) );
        ssbtreeManager->Fill( "Muon_MT"               , MT_Muon              );

        ++Index_Muon;
    } // Muon Loop

    if(TightLooseMethod){
       Index_IsolatedMuon.insert(Index_IsolatedMuon.end(), Index_AdditionalMuon.begin(), Index_AdditionalMuon.end());
       Num_IsolatedMuon = Index_IsolatedMuon.size();
    }

    for(int muon_i = 0; muon_i < Num_IsolatedMuon; ++muon_i){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
        if(IsoMuon.charge() > 0) ++Num_PlusMuon;
        if(IsoMuon.charge() < 0) ++Num_MinusMuon;
        LV_muon = IsoMuon.tlv();
        LV_AllLepton += LV_muon;
        //if(sqrt( pow(LV_muon.Et()-LV_MET.Et(),2) + pow(LV_muon.Px()-LV_MET.Px(),2) + pow(LV_muon.Py()-LV_MET.Py(),2) ) < 120) Cut_MT_min = false;
        //if((IsoMuon.bestTrack()->ptError() / IsoMuon.bestTrack()->pt()) > 0.3) Cut_m_Charge = false;
        /*auto muon_a = std::find(Index_VetoMuon.begin(), Index_VetoMuon.end(), Index_IsolatedMuon.at(muon_i));
        if(muon_a != Index_VetoMuon.end()){
            Index_VetoMuon.erase(muon_a);
        } else {
            std::cout << "Muon? : " << Index_IsolatedMuon.at(muon_i) << "th Muon - Problem with Veto Cut" << endl;
        }*/ 
    }

    Num_VetoMuon = Index_VetoMuon.size();
    if(Num_VetoMuon == 0) {
        Cut_m_MuonVeto = true;
        if(Num_IsolatedMuon == 0 && (!Try_Cut_Additional || (Try_Cut_Additional && Num_AdditionalMuon == 0 ))) Cut_e_MuonVeto = true;
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

    /////////////////////////////
    /////// Electron infor //////
    /////////////////////////////

    if(debugcout) cout << "Electron infor" << endl;
    vSF_Elec.clear();
    v_Elec_Iso03.clear();
    v_Elec_Iso04.clear();
    v_Elec_miniIso.clear();
    v_Elec_Pt_rel.clear();
    v_Elec_Pt_ratio.clear();

    Cut_m_ElectronVeto = false;
    Cut_e_ElectronVeto = false;
    Cut_e_Charge = true;
    //Cut_e_MassVeto = true;

    iEvent.getByToken(electronToken_, electrons);

    Index_Electron = 0;
    Index_IsolatedElectron.clear();
    Num_IsolatedElectron = 0;
    Num_PlusElectron = 0;
    Num_MinusElectron = 0;
    Index_AdditionalElectron.clear();
    Num_AdditionalElectron = 0;
    Index_VetoElectron.clear();
    Num_VetoElectron = 0;

    SF_Electron = 1.0;
    MT_Electron = 0.0;

    for (const cat::Electron &electron : *electrons)
    {

        isIsolatedElectron = false;
        isAdditionalElectron = false;
        isVetoElectron = false;

        isIsoElectronID = false;
        isAddElectronID = false;
        isVetoElectronID = false;


        if(!IsolatedElectronMultiIso){
            //if(IsolatedElectronID == "Veto")     isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
            //if(IsolatedElectronID == "Loose")    isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
            //if(IsolatedElectronID == "Medium")   isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
            //if(IsolatedElectronID == "Tight")    isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");
            if(IsolatedElectronID == "Veto")     isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto-noiso");
            if(IsolatedElectronID == "Loose")    isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose-noiso");
            if(IsolatedElectronID == "Medium")   isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium-noiso");
            if(IsolatedElectronID == "Tight")    isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight-noiso");
        } else {
            if(IsolatedElectronID == "Veto")     isIsoElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(IsolatedElectronID == "Loose")    isIsoElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(IsolatedElectronID == "Medium")   isIsoElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp90");
            if(IsolatedElectronID == "Tight")    isIsoElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp80");
        }

        if(!AdditionalElectronMultiIso){
            //if(AdditionalElectronID == "Veto")   isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
            //if(AdditionalElectronID == "Loose")  isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
            //if(AdditionalElectronID == "Medium") isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
            //if(AdditionalElectronID == "Tight")  isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");
            if(AdditionalElectronID == "Veto")   isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto-noiso");
            if(AdditionalElectronID == "Loose")  isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose-noiso");
            if(AdditionalElectronID == "Medium") isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium-noiso");
            if(AdditionalElectronID == "Tight")  isAddElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight-noiso");
        } else {
            if(AdditionalElectronID == "Veto")   isAddElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(AdditionalElectronID == "Loose")  isAddElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(AdditionalElectronID == "Medium") isAddElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp90");
            if(AdditionalElectronID == "Tight")  isAddElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp80");
        }

        if(!VetoElectronMultiIso){
            //if(VetoElectronID == "Veto")         isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
            //if(VetoElectronID == "Loose")        isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
            //if(VetoElectronID == "Medium")       isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
            //if(VetoElectronID == "Tight")        isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");
            if(VetoElectronID == "Veto")         isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto-noiso");
            if(VetoElectronID == "Loose")        isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose-noiso");
            if(VetoElectronID == "Medium")       isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium-noiso");
            if(VetoElectronID == "Tight")        isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight-noiso");
        } else {
            if(VetoElectronID == "Veto")         isVetoElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(VetoElectronID == "Loose")        isVetoElectronID = electron.electronID("mvaEleID-Spring16-HZZ-V1-wpLoose");
            if(VetoElectronID == "Medium")       isVetoElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp90");
            if(VetoElectronID == "Tight")        isVetoElectronID = electron.electronID("mvaEleID-Spring16-GeneralPurpose-V1-wp80");
        } 

        ///// 0: fails,
        ///// 1: passes electron ID only,
        ///// 2: passes electron Isolation only,
        ///// 3: passes electron ID and Isolation only,
        ///// 4: passes conversion rejection,
        ///// 5: passes conversion rejection and ID,
        ///// 6: passes conversion rejection and Isolation,
        ///// 7: passes the whole selection.
        ///// result : only 0 and 1

        PFIsodbeta03 = electron.relIso(0.3);
        v_Elec_Iso03.push_back(PFIsodbeta03);
        v_Elec_Iso04.push_back(electron.relIso(0.4));
        v_Elec_miniIso.push_back(electron.miniRelIso());
        SF_Electron = ElectronSFEval->get(electron.pt(),electron.eta());
        vSF_Elec.push_back(SF_Electron);
        SuperClusterEta = electron.scEta();
        PassConversionVeto = electron.passConversionVeto();
        ChargeConsistent = electron.isGsfCtfScPixChargeConsistent();
        // Gaussian Sum Fitter (GSF) Track
        // Combinatorial Track Finder (CTF) Track
        // Silicon Pixel Detector (ScPix)
        // error: 'const class cat::Electron' has no member named 'isGsfScPixChargeConsistent'

        LV_electron = electron.tlv();
        if(LV_MET.Phi() > -1 * TMath::Pi() && LV_MET.Phi() < TMath::Pi()){
            MT_Electron = sqrt(2.0*LV_electron.Pt()*LV_MET.Pt()*(1-cos(LV_electron.DeltaPhi(LV_MET))));
        } else {
            MT_Electron = -999.9;
        }
        electron_ClosestdR = 999.9;
        electron_Pt_rel = -999.9;
        electron_Pt_ratio = -999.9;
        for (const cat::Jet &jet : *jets){ 
            LV_jet = jet.tlv();
            if(LV_electron.DeltaR(LV_jet) < electron_ClosestdR) {
                electron_ClosestdR = LV_electron.DeltaR(LV_jet);
                electron_Pt_ratio = LV_electron.Pt() / LV_jet.Pt();
                electron_Pt_rel = ((LV_jet.Vect() - LV_electron.Vect()).Cross(LV_electron.Vect())).Mag() / (LV_jet.Vect() - LV_electron.Vect()).Mag();
            }
        }
        v_Elec_Pt_rel.push_back(electron_Pt_rel);
        v_Elec_Pt_ratio.push_back(electron_Pt_ratio);

/*
         pt      = electron.pt();
         sceta   = SuperClusterEta;
         lep_iso = PFIsodbeta03;
         for(int id_i=0; id_i<4; ++id_i){
            if(id_i==0){      CutID1 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");  CutID2 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");  CutID3 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose"); }
            else if(id_i==1){ CutID1 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); CutID2 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");  CutID3 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose"); }
            else if(id_i==2){ CutID1 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); CutID2 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); CutID3 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose"); }
            else {            CutID1 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); CutID2 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); CutID3 = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium"); }

            for(int iso_i=0; iso_i<10; ++iso_i){
               for(int pt_i=0; pt_i<10; ++pt_i){

                  if(CutID1 && std::abs(electron.eta())<2.4 &&
                     ((sceta > 1.566 && lep_iso < Elec_IsoHigh[Cut1[iso_i]]) || (sceta < 1.4442 && lep_iso < Elec_IsoLow[Cut1[iso_i]])) &&
                     pt > Lep_Pt[Cut1[pt_i]]){ ++CutTest[id_i][iso_i][pt_i][0]; }
                  if(CutID2 && std::abs(electron.eta())<2.4 &&
                     ((sceta > 1.566 && lep_iso < Elec_IsoHigh[Cut2[iso_i]]) || (sceta < 1.4442 && lep_iso < Elec_IsoLow[Cut2[iso_i]])) &&
                     pt > Lep_Pt[Cut2[pt_i]]){ ++CutTest[id_i][iso_i][pt_i][1]; }
                  if(CutID3 && std::abs(electron.eta())<2.4 &&
                     ((sceta > 1.566 && lep_iso < Elec_IsoHigh[Cut3[iso_i]]) || (sceta < 1.4442 && lep_iso < Elec_IsoLow[Cut3[iso_i]])) &&
                     pt > Lep_Pt[Cut3[pt_i]]){ ++CutTest[id_i][iso_i][pt_i][2]; }

               }
            }
         }
*/

        if(!Try_Cut_Additional && isIsoElectronID && (electron.pt() > IsolatedElectronPt) && (std::abs(electron.eta()) < IsolatedElectronEta) && PassConversionVeto &&
            ((!IsolatedElectronMultiIso && ((std::abs(SuperClusterEta) < 1.4442 && PFIsodbeta03 < IsoCutLowEta) || (std::abs(SuperClusterEta) > 1.566 && PFIsodbeta03 < IsoCutHighEta))) ||
                (IsolatedElectronMultiIso &&
                ( (double)electron.miniRelIso() < IsolatedElectronMiniIso && (electron_Pt_rel > IsolatedElectronPtRel || electron_Pt_ratio > IsolatedElectronPtRatio) )
                )
            )
        ){

            isIsolatedElectron = true;
            Index_IsolatedElectron.push_back(Index_Electron);
            if(!ChargeConsistent) Cut_e_Charge = false;
            ssbtreeManager->Fill( "Cut_Elec", electron.pt(), electron.eta(), electron.phi(), electron.energy(), Num_IsolatedElectron );
            ++Num_IsolatedElectron;
            ssbtreeManager->Fill( "Cut_Elec_PFIsodBeta03" , PFIsodbeta03          );
            ssbtreeManager->Fill( "Cut_Elec_PFIsodBeta04" , (double)electron.relIso(0.4) );
            ssbtreeManager->Fill( "Cut_Elec_miniRelIso"   , (double)electron.miniRelIso() );
            ssbtreeManager->Fill( "Cut_Elec_ClosestJetdR" , electron_ClosestdR    );
            ssbtreeManager->Fill( "Cut_Elec_Pt_rel"       , electron_Pt_rel       );
            ssbtreeManager->Fill( "Cut_Elec_Pt_rat"       , electron_Pt_ratio     );
            ssbtreeManager->Fill( "Cut_Elec_dxy"          , (double)electron.dxy() );
            ssbtreeManager->Fill( "Cut_Elec_dz"           , (double)electron.dz() );
            ssbtreeManager->Fill( "Cut_Elec_MT"           , MT_Electron           );
        } else if(Try_Cut_Additional && isAddElectronID && (electron.pt() > AdditionalElectronPt) && (std::abs(electron.eta()) < AdditionalElectronEta) && PassConversionVeto &&
            ((!AdditionalElectronMultiIso && ((std::abs(SuperClusterEta) < 1.4442 && PFIsodbeta03 < AddCutLowEta) || (std::abs(SuperClusterEta) > 1.566 && PFIsodbeta03 < AddCutHighEta))) ||
                (AdditionalElectronMultiIso &&
                ( (double)electron.miniRelIso() < AdditionalElectronMiniIso && (electron_Pt_rel > AdditionalElectronPtRel || electron_Pt_ratio > AdditionalElectronPtRatio) )
                )
            )
        ){
            if(isIsoElectronID && (electron.pt() > IsolatedElectronPt) && (std::abs(electron.eta()) < IsolatedElectronEta) && PassConversionVeto &&
                ((!IsolatedElectronMultiIso && ((std::abs(SuperClusterEta) < 1.4442 && PFIsodbeta03 < IsoCutLowEta) || (std::abs(SuperClusterEta) > 1.566 && PFIsodbeta03 < IsoCutHighEta))) ||
                    (IsolatedElectronMultiIso &&
                    ( (double)electron.miniRelIso() < IsolatedElectronMiniIso && (electron_Pt_rel > IsolatedElectronPtRel || electron_Pt_ratio > IsolatedElectronPtRatio) )
                    )
                )
            ){

                isIsolatedElectron = true;
                Index_IsolatedElectron.push_back(Index_Electron);
                if(!ChargeConsistent) Cut_e_Charge = false;
                ssbtreeManager->Fill( "Cut_Elec", electron.pt(), electron.eta(), electron.phi(), electron.energy(), Num_IsolatedElectron );
                ++Num_IsolatedElectron;
                ssbtreeManager->Fill( "Cut_Elec_PFIsodBeta03" , PFIsodbeta03          );
                ssbtreeManager->Fill( "Cut_Elec_PFIsodBeta04" , (double)electron.relIso(0.4) );
                ssbtreeManager->Fill( "Cut_Elec_miniRelIso"   , (double)electron.miniRelIso() );
                ssbtreeManager->Fill( "Cut_Elec_ClosestJetdR" , electron_ClosestdR    );
                ssbtreeManager->Fill( "Cut_Elec_Pt_rel"       , electron_Pt_rel       );
                ssbtreeManager->Fill( "Cut_Elec_Pt_rat"       , electron_Pt_ratio     );
                ssbtreeManager->Fill( "Cut_Elec_dxy"          , (double)electron.dxy() );
                ssbtreeManager->Fill( "Cut_Elec_dz"           , (double)electron.dz() );
                ssbtreeManager->Fill( "Cut_Elec_MT"           , MT_Electron           );
            } else {
                isAdditionalElectron = true;
                ++Num_AdditionalElectron;
                Index_AdditionalElectron.push_back(Index_Electron);
                //if(!ChargeConsistent) Cut_e_Charge = false;
            }
        } else if(isVetoElectronID && (electron.pt() > VetoElectronPt) && (std::abs(electron.eta()) < VetoElectronEta) && PassConversionVeto &&
            ((!VetoElectronMultiIso && ((std::abs(SuperClusterEta) < 1.4442 && PFIsodbeta03 < VetoCutLowEta) || (std::abs(SuperClusterEta) > 1.566 && PFIsodbeta03 < VetoCutHighEta))) ||
                (VetoElectronMultiIso &&
                ( (double)electron.miniRelIso() < VetoElectronMiniIso && (electron_Pt_rel > VetoElectronPtRel || electron_Pt_ratio > VetoElectronPtRatio) )
                )
            )
        ){
                    isVetoElectron = true;
                    ++Num_VetoElectron;
                    Index_VetoElectron.push_back(Index_Electron);
        }

        ssbtreeManager->Fill( "Elec", electron.pt(), electron.eta(), electron.phi(), electron.energy(), Index_Electron );
        ssbtreeManager->Fill( "Elec_Cut_Isolated"      , isIsolatedElectron );
        ssbtreeManager->Fill( "Elec_Cut_Additional"    , isAdditionalElectron );
        ssbtreeManager->Fill( "Elec_Cut_Veto"          , isVetoElectron     );
        ssbtreeManager->Fill( "Elec_isTight"           , (bool)electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight")  );
        ssbtreeManager->Fill( "Elec_isMedium"          , (bool)electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium") );
        ssbtreeManager->Fill( "Elec_isLoose"           , (bool)electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose")  );
        ssbtreeManager->Fill( "Elec_isVeto"            , (bool)electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto")   );
        ssbtreeManager->Fill( "Elec_isIsoID"           , isIsoElectronID    );
        ssbtreeManager->Fill( "Elec_isAddID"           , isAddElectronID    );
        ssbtreeManager->Fill( "Elec_isVetoID"          , isVetoElectronID   );
        ssbtreeManager->Fill( "Elec_PFIsodBeta03"      , PFIsodbeta03       );
        ssbtreeManager->Fill( "Elec_PFIsodBeta04"      , (double)electron.relIso(0.4) );
        ssbtreeManager->Fill( "Elec_miniRelIso"        , (double)electron.miniRelIso() );
        ssbtreeManager->Fill( "Elec_ClosestJetdR"      , electron_ClosestdR );
        ssbtreeManager->Fill( "Elec_Pt_rel"            , electron_Pt_rel    );
        ssbtreeManager->Fill( "Elec_Pt_rat"            , electron_Pt_ratio  );
        ssbtreeManager->Fill( "Elec_dxy"               , (double)electron.dxy() );
        ssbtreeManager->Fill( "Elec_dz"                , (double)electron.dz() );
        ssbtreeManager->Fill( "Elec_pdgId"             , electron.pdgId()   );
        ssbtreeManager->Fill( "Elec_Charge"            , electron.charge()  );
        ssbtreeManager->Fill( "Elec_ScaleFactor"       , SF_Electron        );
        ssbtreeManager->Fill( "Elec_Conversion"        , PassConversionVeto );
        ssbtreeManager->Fill( "Elec_Supercluster_Eta"  , SuperClusterEta    );
        ssbtreeManager->Fill( "Elec_ChargeId_GsfCtfPx" , ChargeConsistent   );
        ssbtreeManager->Fill( "Elec_MT"                , MT_Electron        );

        ++Index_Electron;
    }

    if(TightLooseMethod){
       Index_IsolatedElectron.insert(Index_IsolatedElectron.end(), Index_AdditionalElectron.begin(), Index_AdditionalElectron.end());
       Num_IsolatedElectron = Index_IsolatedElectron.size();
    }

    for(int elec_i = 0; elec_i < Num_IsolatedElectron; ++elec_i){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
        if(IsoElectron.charge() > 0) ++Num_PlusElectron;
        if(IsoElectron.charge() < 0) ++Num_MinusElectron;
        LV_electron = IsoElectron.tlv();
        LV_AllLepton += LV_electron;
        //if(sqrt( pow(LV_electron.Et()-LV_MET.Et(),2) + pow(LV_electron.Px()-LV_MET.Px(),2) + pow(LV_electron.Py()-LV_MET.Py(),2) ) < 120) Cut_MT_min = false;
        /*auto elec_a = std::find(Index_VetoElectron.begin(), Index_VetoElectron.end(), Index_IsolatedElectron.at(elec_i));
        if(elec_a != Index_VetoElectron.end()){
            Index_VetoElectron.erase(elec_a);
        } else {
            std::cout << "Electron? : " << Index_IsolatedElectron.at(elec_i) << "th Electron - Problem with Veto Cut" << endl;
        }*/
    }

    Num_VetoElectron = Index_VetoElectron.size();
    if(Num_VetoElectron == 0) {
        Cut_e_ElectronVeto = true;
        if(Num_IsolatedElectron == 0 && (!Try_Cut_Additional || (Try_Cut_Additional && Num_AdditionalElectron == 0 ))) Cut_m_ElectronVeto = true;
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

    if(debugcout) cout << "All Lepton Information" << endl;
    AllLeptonMass = 0.0;
    DiLeptonMass1 = 0.0;
    DiLeptonMass2 = 0.0;
    DiLeptonMass3 = 0.0;

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

    Cut_ee_TL = false;
    Cut_mm_TL = false;
    Cut_em_TL = false;
    if(!TightLooseMethod){
        Cut_ee_TL = true;
        Cut_mm_TL = true;
        Cut_em_TL = true;
    } else {
        if(Num_AdditionalElectron > 0) Cut_ee_TL = true;
        if(Num_AdditionalMuon > 0) Cut_mm_TL = true;
        if(Num_AdditionalElectron > 0 || Num_AdditionalMuon > 0) Cut_em_TL = true;
    }

    Cut_LeptonMass = false;
    AllLeptonMass = LV_AllLepton.M();
    if(AllLeptonMass > InvariantMass+InvariantMassE || AllLeptonMass < InvariantMass-InvariantMassE) Cut_LeptonMass = true;

    Cut_dl_Opposite = false;
    Cut_dl_Same = false;
    Num_PlusLepton = Num_PlusMuon + Num_PlusElectron;
    Num_MinusLepton = Num_MinusMuon + Num_MinusElectron;
    if((AllLeptonMass > 20) && (Num_PlusLepton == 1 && Num_MinusLepton == 1)) Cut_dl_Opposite = true;
    if((AllLeptonMass > 12) && ((Num_PlusLepton == 2 && Num_MinusLepton == 0) || (Num_PlusLepton == 0 && Num_MinusLepton == 2))) Cut_dl_Same = true;

    TriLepton_First  = 0;
    TriLepton_Second = 0;
    TriLepton_Third  = 0;
    if(Num_IsolatedElectron + Num_IsolatedMuon > 1){
        map<double,int> pt_order_check;
        pt_order_check.clear();
        for(int elec_i = 0; elec_i < Num_IsolatedElectron; ++elec_i){
            const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
            pt_order_check[IsoElectron.pt()] = (1100+Index_IsolatedElectron.at(elec_i))*IsoElectron.charge();
        }
        for(int muon_i = 0; muon_i < Num_IsolatedMuon; ++muon_i){
            const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
            pt_order_check[IsoMuon.pt()] = (1300+Index_IsolatedMuon.at(muon_i))*IsoMuon.charge();
        }
        std::map<double,int>::reverse_iterator FirstLep  = pt_order_check.rbegin();
        TriLepton_First = FirstLep->second;
        std::map<double,int>::reverse_iterator SecondLep = pt_order_check.rbegin(); ++SecondLep;
        TriLepton_Second = SecondLep->second;
        if(Num_IsolatedElectron + Num_IsolatedMuon > 2){
            std::map<double,int>::reverse_iterator ThirdLep = pt_order_check.rbegin(); ++ThirdLep; ++ThirdLep;
            TriLepton_Third = ThirdLep->second;
        }
    }

    if(abs(TriLepton_First)/100 == 11){       LeptonWeight =  vSF_Elec.at(abs(TriLepton_First)%100); }
    else if(abs(TriLepton_First)/100 == 13){  LeptonWeight =  vSF_Muon.at(abs(TriLepton_First)%100); }
    if(abs(TriLepton_Second)/100 == 11){      LeptonWeight *= vSF_Elec.at(abs(TriLepton_Second)%100); }
    else if(abs(TriLepton_Second)/100 == 13){ LeptonWeight *= vSF_Muon.at(abs(TriLepton_Second)%100); }

    Cut_Tri_First_Opposite = false;
    Cut_Tri_First_Same = false;
    if(TriLepton_First*TriLepton_Second > 0){ Cut_Tri_First_Same = true; }
    else { Cut_Tri_First_Opposite = true; } 

    Cut_Tri_ee = false;
    Cut_Tri_mm = false;
    Cut_Tri_em = false;
    Cut_Tri_First_Zmass = true;
    LV_Tri_First.SetPtEtaPhiE(0,0,0,0);
    LV_Tri_Second.SetPtEtaPhiE(0,0,0,0);
    LV_Tri_Dilepton1.SetPtEtaPhiE(0,0,0,0);
    if(abs(TriLepton_First)/100 == 11 && abs(TriLepton_Second)/100 == 11){
        Cut_Tri_ee = true;
        const cat::Electron &IsoElectron_First  = electrons->at(abs(TriLepton_First)%100);
        LV_Tri_First = IsoElectron_First.tlv();
        LV_Tri_Dilepton1 += LV_Tri_First;
        const cat::Electron &IsoElectron_Second = electrons->at(abs(TriLepton_Second)%100);
        LV_Tri_Second = IsoElectron_Second.tlv();
        LV_Tri_Dilepton1 += LV_Tri_Second;
    } else if(abs(TriLepton_First)/100 == 13 && abs(TriLepton_Second)/100 == 13){
        Cut_Tri_mm = true;
        const cat::Muon &IsoMuon_First  = muons->at(abs(TriLepton_First)%100);
        LV_Tri_First = IsoMuon_First.tlv();
        LV_Tri_Dilepton1 += LV_Tri_First;
        const cat::Muon &IsoMuon_Second = muons->at(abs(TriLepton_Second)%100);
        LV_Tri_Second = IsoMuon_Second.tlv();
        LV_Tri_Dilepton1 += LV_Tri_Second;
    } else if(TriLepton_First != 0 && TriLepton_Second != 0){
        Cut_Tri_em = true;
        if(abs(TriLepton_First)/100 == 13){
            const cat::Muon &IsoMuon_First  = muons->at(abs(TriLepton_First)%100);
            LV_Tri_First = IsoMuon_First.tlv();
            LV_Tri_Dilepton1 += LV_Tri_First;
            const cat::Electron &IsoElectron_Second = electrons->at(abs(TriLepton_Second)%100);
            LV_Tri_Second = IsoElectron_Second.tlv();
            LV_Tri_Dilepton1 += LV_Tri_Second;
        } else {
            const cat::Electron &IsoElectron_First  = electrons->at(abs(TriLepton_First)%100);
            LV_Tri_First = IsoElectron_First.tlv();
            LV_Tri_Dilepton1 += LV_Tri_First;
            const cat::Muon &IsoMuon_Second = muons->at(abs(TriLepton_Second)%100);
            LV_Tri_Second = IsoMuon_Second.tlv();
            LV_Tri_Dilepton1 += LV_Tri_Second;
        }
    }
    DiLeptonMass1 = LV_Tri_Dilepton1.M();
    if((Cut_Tri_ee || Cut_Tri_mm) && Cut_Tri_First_Opposite && (DiLeptonMass1 > InvariantMass-InvariantMassE && DiLeptonMass1 < InvariantMass+InvariantMassE)) Cut_Tri_First_Zmass = false;

    Cut_Tri_ExactlyThree = false;
    if(Num_IsolatedElectron + Num_IsolatedMuon + Num_AdditionalElectron + Num_AdditionalMuon == 3) Cut_Tri_ExactlyThree = true;

    map<double,int> pt_order_check;
    pt_order_check.clear();
    if(TriLepton_Third == 0 && Num_AdditionalElectron + Num_AdditionalMuon > 0){
        for(int elec_i = 0; elec_i < Num_AdditionalElectron; ++elec_i){
            const cat::Electron &IsoElectron = electrons->at(Index_AdditionalElectron.at(elec_i));
            pt_order_check[IsoElectron.pt()] = (1100+Index_AdditionalElectron.at(elec_i))*IsoElectron.charge();
        }
        for(int muon_i = 0; muon_i < Num_AdditionalMuon; ++muon_i){
            const cat::Muon &IsoMuon = muons->at(Index_AdditionalMuon.at(muon_i));
            pt_order_check[IsoMuon.pt()] = (1300+Index_AdditionalMuon.at(muon_i))*IsoMuon.charge();
        }
        std::map<double,int>::reverse_iterator AdditionalLep = pt_order_check.rbegin();
        TriLepton_Third = AdditionalLep->second;
    }

    Cut_Tri_add_e = false;
    Cut_Tri_add_m = false;
    LV_Tri_Third.SetPtEtaPhiE(0,0,0,0);
    if(abs(TriLepton_Third)/100 == 13){
        Cut_Tri_add_m = true;
        const cat::Muon &IsoMuon_Third = muons->at(abs(TriLepton_Third)%100);
        LV_Tri_Third = IsoMuon_Third.tlv();
        AddLeptonWeight = vSF_Muon.at(abs(TriLepton_Third)%100);
    } else if(abs(TriLepton_Third)/100 == 11){
        Cut_Tri_add_e = true;
        const cat::Electron &IsoElectron_Third = electrons->at(abs(TriLepton_Third)%100);
        LV_Tri_Third = IsoElectron_Third.tlv();
        AddLeptonWeight = vSF_Elec.at(abs(TriLepton_Third)%100);
    }

    Cut_Tri_add_Charge = false;
    if(TriLepton_First*TriLepton_Second < 0 && TriLepton_Third != 0) Cut_Tri_add_Charge = true;
    else if(TriLepton_First > 0 && TriLepton_Third < 0) Cut_Tri_add_Charge = true;
    else if(TriLepton_First < 0 && TriLepton_Third > 0) Cut_Tri_add_Charge = true;
    // Posibility of TriLepton_X = 0

    Num_OppositeLepton = 0;
    if(abs(TriLepton_Third)/100 == abs(TriLepton_First)/100  && TriLepton_Third*TriLepton_First  < 0) Num_OppositeLepton = 5;
    if(abs(TriLepton_Third)/100 == abs(TriLepton_Second)/100 && TriLepton_Third*TriLepton_Second < 0) Num_OppositeLepton += 15;

    Cut_Tri_Second_Zmass = true;
    LV_Tri_Dilepton2.SetPtEtaPhiE(0,0,0,0);
    LV_Tri_Dilepton3.SetPtEtaPhiE(0,0,0,0);
    if(Num_OppositeLepton%10 == 5){
        if(Num_OppositeLepton == 5){
            LV_Tri_Dilepton2 += LV_Tri_First;
            LV_Tri_Dilepton2 += LV_Tri_Third;
            LV_Tri_Dilepton3 += LV_Tri_Second;
            LV_Tri_Dilepton3 += LV_Tri_Third;
            if(LV_Tri_Dilepton2.M() > InvariantMass-InvariantMassE && LV_Tri_Dilepton2.M() < InvariantMass+InvariantMassE) Cut_Tri_Second_Zmass = false;
        } else {
            LV_Tri_Dilepton2 += LV_Tri_Second;
            LV_Tri_Dilepton2 += LV_Tri_Third;
            LV_Tri_Dilepton3 += LV_Tri_First;
            LV_Tri_Dilepton3 += LV_Tri_Third;
            if(LV_Tri_Dilepton2.M() > InvariantMass-InvariantMassE && LV_Tri_Dilepton2.M() < InvariantMass+InvariantMassE) Cut_Tri_Second_Zmass = false;
        }
    } else {
            LV_Tri_Dilepton2 += LV_Tri_First;
            LV_Tri_Dilepton2 += LV_Tri_Third;
            LV_Tri_Dilepton3 += LV_Tri_Second;
            LV_Tri_Dilepton3 += LV_Tri_Third;
            if(Num_OppositeLepton == 20){
                if( (LV_Tri_Dilepton2.M() > InvariantMass-InvariantMassE && LV_Tri_Dilepton2.M() < InvariantMass+InvariantMassE) ||
                    (LV_Tri_Dilepton3.M() > InvariantMass-InvariantMassE && LV_Tri_Dilepton3.M() < InvariantMass+InvariantMassE) ) Cut_Tri_Second_Zmass = false;
            }
    }
    DiLeptonMass2 = LV_Tri_Dilepton2.M();
    DiLeptonMass3 = LV_Tri_Dilepton3.M();
    
    if(Num_OppositeLepton == 5 || Num_OppositeLepton == 15) Num_OppositeLepton = 1;
    if(Num_OppositeLepton == 20) Num_OppositeLepton = 2;

    Cut_SUSY_SRZ = false;
    if(TriLepton_Third == 0 && Num_AdditionalElectron + Num_AdditionalMuon > 0){
        for(std::map<double,int>::reverse_iterator AdditionalLep = pt_order_check.rbegin();AdditionalLep != pt_order_check.rend();++AdditionalLep){
            TriLepton_Other = AdditionalLep->second;
            LV_Tri_Other.SetPtEtaPhiE(0,0,0,0);
            if(abs(TriLepton_Other)/100 == 13){
                const cat::Muon &IsoMuon_Other = muons->at(abs(TriLepton_Other)%100);
                LV_Tri_Other = IsoMuon_Other.tlv();
            } else if(abs(TriLepton_Other)/100 == 11){
                const cat::Electron &IsoElectron_Other = electrons->at(abs(TriLepton_Other)%100);
                LV_Tri_Other = IsoElectron_Other.tlv();
            }
            if(abs(TriLepton_Other)/100 == abs(TriLepton_First)/100  && TriLepton_Other*TriLepton_First  < 0){
                LV_Tri_DileptonOther = LV_Tri_Other;
                LV_Tri_DileptonOther += LV_Tri_First;
                if(LV_Tri_DileptonOther.M() > InvariantMass-InvariantMassE && LV_Tri_DileptonOther.M() < InvariantMass+InvariantMassE) Cut_SUSY_SRZ = true;
            }
            if(abs(TriLepton_Other)/100 == abs(TriLepton_Second)/100  && TriLepton_Other*TriLepton_Second  < 0){
                LV_Tri_DileptonOther = LV_Tri_Other;
                LV_Tri_DileptonOther += LV_Tri_Second;
                if(LV_Tri_DileptonOther.M() > InvariantMass-InvariantMassE && LV_Tri_DileptonOther.M() < InvariantMass+InvariantMassE) Cut_SUSY_SRZ = true;
            }
        }
    }

    ssbtreeManager->Fill( "Cut_ej_ElectronIso",     Cut_ej_ElectronIso     );
    ssbtreeManager->Fill( "Cut_mj_MuonIso",         Cut_mj_MuonIso         );
    ssbtreeManager->Fill( "Cut_ee_LeptonPair",      Cut_ee_LeptonPair      );
    ssbtreeManager->Fill( "Cut_mm_LeptonPair",      Cut_mm_LeptonPair      );
    ssbtreeManager->Fill( "Cut_em_LeptonPair",      Cut_em_LeptonPair      );
    ssbtreeManager->Fill( "Cut_LeptonMass",         Cut_LeptonMass         );
    ssbtreeManager->Fill( "Cut_dl_Same",            Cut_dl_Same            );
    ssbtreeManager->Fill( "Cut_dl_Opposite",        Cut_dl_Opposite        );
    ssbtreeManager->Fill( "Num_PlusLepton",         Num_PlusLepton         );
    ssbtreeManager->Fill( "Num_MinusLepton",        Num_MinusLepton        );
//    ssbtreeManager->Fill( "Cut_MT_min",             Cut_MT_min             );
    ssbtreeManager->Fill( "Cut_Tri_ee",             Cut_Tri_ee             );
    ssbtreeManager->Fill( "Cut_Tri_mm",             Cut_Tri_mm             );
    ssbtreeManager->Fill( "Cut_Tri_em",             Cut_Tri_em             );
    ssbtreeManager->Fill( "Cut_Tri_First_Opposite", Cut_Tri_First_Opposite );
    ssbtreeManager->Fill( "Cut_Tri_First_Same",     Cut_Tri_First_Same     );
    ssbtreeManager->Fill( "Cut_Tri_First_Zmass",    Cut_Tri_First_Zmass    );
    ssbtreeManager->Fill( "Cut_Tri_ExactlyThree",   Cut_Tri_ExactlyThree   );
    ssbtreeManager->Fill( "Cut_Tri_add_e",          Cut_Tri_add_e          );
    ssbtreeManager->Fill( "Cut_Tri_add_m",          Cut_Tri_add_m          );
    ssbtreeManager->Fill( "Cut_Tri_add_Charge",     Cut_Tri_add_Charge     );
    ssbtreeManager->Fill( "Cut_Tri_Second_Zmass",   Cut_Tri_Second_Zmass   );
    ssbtreeManager->Fill( "Num_OppositeLepton",     Num_OppositeLepton     );
    ssbtreeManager->Fill( "DiLepton_InvMass1",     DiLeptonMass1          );
    ssbtreeManager->Fill( "DiLepton_InvMass2",     DiLeptonMass2          );
    ssbtreeManager->Fill( "DiLepton_InvMass3",     DiLeptonMass3          );

    ////////////////////////
    /// Jets Information ///
    ////////////////////////

    if(debugcout) cout << "Jets Information" << endl;
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

        LV_jet = jet.tlv();
        for(int muon_i = 0; (muon_i < Num_IsolatedMuon) && isCleanedJet; ++muon_i){
            const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
            LV_muon = IsoMuon.tlv();
            if(LV_muon.DeltaR(LV_jet) < JetCleaningdR) isCleanedJet = false;
        }
        for(int elec_i = 0; (elec_i < Num_IsolatedElectron) && isCleanedJet; ++elec_i){
            const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
            LV_electron = IsoElectron.tlv();
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
    ssbtreeManager->Fill( "Lepton_Weight",     LeptonWeight      );
    ssbtreeManager->Fill( "AddLepton_Weight",  AddLeptonWeight   );

    if(debugcout) cout << "CutStep()" << endl;
    CutStep(); // CutStep.h

    /// Fill Ntuples at each event
    if(debugcout) cout << "FillNtuple()" << endl;
    FillNTuple = false;
    for(int i_Channel=0; i_Channel<(int)CutChannelName.size(); ++i_Channel){
        if(Cut_Step[CutChannelName[i_Channel]][Save_CutStep]) FillNTuple = true;
    }
    if(FillNTuple) ssbtreeManager->FillNtuple();

    if(debugcout) cout << "FillHistogram()" << endl;
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
