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
Save_Channel(        iConfig.getUntrackedParameter< std::string >(              "Save_Channel",       std::string("Jets")   )), 
Save_Inversion(      iConfig.getUntrackedParameter< bool >(                     "Save_Inversion",     false                 )), 

Try_Cut_Trigger(     iConfig.getUntrackedParameter< bool >(                     "Do_Trigger_Cut",     true                  )), 
e_Trigger(           iConfig.getUntrackedParameter< std::vector<std::string> >( "e_Trigger"                                 )),
m_Trigger(           iConfig.getUntrackedParameter< std::vector<std::string> >( "m_Trigger"                                 )),
em_Trigger(          iConfig.getUntrackedParameter< std::vector<std::string> >( "em_Trigger"                                )),

IsolatedMuonID(      iConfig.getUntrackedParameter< std::string >(              "MuonID",           std::string("Tight")  )), 
IsolatedMuonPt(      iConfig.getUntrackedParameter< double >(                   "MuonPt",           26.0                  )),
IsolatedMuonEta(     iConfig.getUntrackedParameter< double >(                   "MuonEta",          2.1                   )),
IsolatedMuonIso(     iConfig.getUntrackedParameter< double >(                   "MuonIso",          0.15                  )),

IsolatedElectronID(  iConfig.getUntrackedParameter< std::string >(              "ElectronID",       std::string("Medium") )), 
IsolatedElectronPt(  iConfig.getUntrackedParameter< double >(                   "ElectronPt",       30.0                  )),
IsolatedElectronEta( iConfig.getUntrackedParameter< double >(                   "ElectronEta",      2.4                   )),

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

InclusiveMass(       iConfig.getUntrackedParameter< double >(                   "InclusiveMass",      80.4                  )),
InclusiveMassE(      iConfig.getUntrackedParameter< double >(                   "PlusMinus",          15.0                  )),
METPt(               iConfig.getUntrackedParameter< double >(                   "METPt",              0.0                   ))
{
    //now do what ever initialization is needed

    genParInfoTag    = consumes<reco::GenParticleCollection> (iConfig.getParameter<edm::InputTag>("genParTag"));
    genJetInfoTag    = consumes<reco::GenJetCollection>      (iConfig.getParameter<edm::InputTag>("genJetTag"));

    muonToken_       = consumes<cat::MuonCollection>         (iConfig.getParameter<edm::InputTag>("muonTag"));
    electronToken_   = consumes<cat::ElectronCollection>     (iConfig.getParameter<edm::InputTag>("electronTag"));
    jetToken_        = consumes<cat::JetCollection>          (iConfig.getParameter<edm::InputTag>("jetTag"));
    metToken_        = consumes<cat::METCollection>          (iConfig.getParameter<edm::InputTag>("metTag"));

    npvToken_        = consumes<int>                         (iConfig.getParameter<edm::InputTag>("npvTag"));

    triggerBits_     = consumes<edm::TriggerResults>         (iConfig.getParameter<edm::InputTag>("triggerBitsTag"));

    ssbgeninfor = new SSBGenInfor(iConfig);

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

    ejets_EventInfo = ssbfs->make<TH1F>("ejets_EventInfo","e+jets Event Information",13,-1,12);
    ejets_EventInfo->GetXaxis()->SetBinLabel(1 ,"Number of Inclusive Samples");
    ejets_EventInfo->GetXaxis()->SetBinLabel(2 ,"0a : Number of Signal Events");
    ejets_EventInfo->GetXaxis()->SetBinLabel(3 ,"0b : Trigger filter");
    ejets_EventInfo->GetXaxis()->SetBinLabel(4 ,"1  : Single lepton");
    ejets_EventInfo->GetXaxis()->SetBinLabel(5 ,"2a : Veto muon");
    ejets_EventInfo->GetXaxis()->SetBinLabel(6 ,"2b : Veto electron");
    ejets_EventInfo->GetXaxis()->SetBinLabel(7 ,"3a : Njets>=1");
    ejets_EventInfo->GetXaxis()->SetBinLabel(8 ,"3b : Njets>=2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(9 ,"3c : Njets>=3");
    ejets_EventInfo->GetXaxis()->SetBinLabel(10,"3d : Njets>=4");
    ejets_EventInfo->GetXaxis()->SetBinLabel(11,"4a : Njets>=4 && Nbjets>=1");
    ejets_EventInfo->GetXaxis()->SetBinLabel(12,"4b : Njets>=4 && Nbjets>=2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(13,"4c : Njets>=4 && Nbjets==2");

    mjets_EventInfo = ssbfs->make<TH1F>("mjets_EventInfo","#mu+jets Event Information",13,-1,12);
    mjets_EventInfo->GetXaxis()->SetBinLabel(1 ,"Number of Inclusive Samples");
    mjets_EventInfo->GetXaxis()->SetBinLabel(2 ,"0a : Number of Signal Events");
    mjets_EventInfo->GetXaxis()->SetBinLabel(3 ,"0b : Trigger filter");
    mjets_EventInfo->GetXaxis()->SetBinLabel(4 ,"1  : Single lepton");
    mjets_EventInfo->GetXaxis()->SetBinLabel(5 ,"2a : Veto muon");
    mjets_EventInfo->GetXaxis()->SetBinLabel(6 ,"2b : Veto electron");
    mjets_EventInfo->GetXaxis()->SetBinLabel(7 ,"3a : Njets>=1");
    mjets_EventInfo->GetXaxis()->SetBinLabel(8 ,"3b : Njets>=2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(9 ,"3c : Njets>=3");
    mjets_EventInfo->GetXaxis()->SetBinLabel(10,"3d : Njets>=4");
    mjets_EventInfo->GetXaxis()->SetBinLabel(11,"4a : Njets>=4 && Nbjets>=1");
    mjets_EventInfo->GetXaxis()->SetBinLabel(12,"4b : Njets>=4 && Nbjets>=2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(13,"4c : Njets>=4 && Nbjets==2");

    ee_EventInfo = ssbfs->make<TH1F>("ee_EventInfo","ee Dilepton Event Information",13,-1,12);
    mm_EventInfo = ssbfs->make<TH1F>("mm_EventInfo","#mu#mu Dilepton Event Information",13,-1,12);
    em_EventInfo = ssbfs->make<TH1F>("em_EventInfo","e#mu Dilepton Event Information",13,-1,12);
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

    Event = iEvent.id().event();
    Run = iEvent.id().run();
    Lumi = iEvent.id().luminosityBlock();
    isData = iEvent.isRealData();

    ssbtreeManager->Fill( "Info_EventNumber", Event  );
    ssbtreeManager->Fill( "Info_RunNumber"  , Run    ); 
    ssbtreeManager->Fill( "Info_Luminosity" , Lumi   ); 
    ssbtreeManager->Fill( "Info_isData"     , isData ); 
    ejets_EventInfo->Fill(-0.5,1.0);
    mjets_EventInfo->Fill(-0.5,1.0);
    ee_EventInfo->Fill(-0.5,1.0);
    mm_EventInfo->Fill(-0.5,1.0);
    em_EventInfo->Fill(-0.5,1.0);

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
        ChannelName = ssbgeninfor->ReturnChannel(iEvent);
        if(ChannelName.find(Save_Channel) == std::string::npos) FillNTuple = false;
        if(Save_Inversion) FillNTuple = !FillNTuple;

    } else {
        ChannelName = "Data";
    }

    if(FillNTuple) {

    /////////////////////////////////////////
    /// inconsistentMuonPFCandidateFilter ///
    /////////////////////////////////////////

    //////////////////////////
    /// Greedy Muon Filter ///
    //////////////////////////
                                            
    ///////////////////////////////////
    // Primary Vertices Information ///
    ///////////////////////////////////

    edm::Handle<int> Num_PV;
    iEvent.getByToken( npvToken_, Num_PV );
    ssbtreeManager->Fill( "PV_Count", (int)*Num_PV );

    /////////////////////////
    ///  Rho Information  ///
    /////////////////////////

    //////////////////////////
    /// Pileup Information ///
    //////////////////////////

    /////////////////////////
    ///Trigger Information///
    /////////////////////////

    Cut_e_Trigger  = false;
    Cut_m_Trigger  = false;
    Cut_em_Trigger = false;
    edm::Handle<edm::TriggerResults> triggerBits;                                                                                        
    iEvent.getByToken(triggerBits_, triggerBits);                                                                                        
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
    if(!Try_Cut_Trigger){
        Cut_e_Trigger  = true;
        Cut_m_Trigger  = true;
        Cut_em_Trigger = true;
    }

    Num_PlusLepton = 0;
    Num_MinusLepton = 0;
    LV_AllLepton.SetPtEtaPhiE(0,0,0,0);

    /////////////////////////
    /// Muon Information ////
    /////////////////////////

    Cut_e_MuonVeto = false;
    Cut_m_MuonVeto = false;

    Handle<cat::MuonCollection> muons;
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

    for(unsigned int muon_i = 0; muon_i < Num_IsolatedMuon; ++muon_i){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
        if(IsoMuon.charge() > 0) ++Num_PlusMuon;
        if(IsoMuon.charge() < 0) ++Num_MinusMuon;
        ssbtreeManager->Fill( "Cut_Muon", IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy(), muon_i );
        LV_muon.SetPtEtaPhiE(IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy());
        LV_AllLepton += LV_muon;
        auto muon_j = std::find(Index_VetoMuon.begin(), Index_VetoMuon.end(), Index_IsolatedMuon.at(muon_i));
        if(muon_j != Index_VetoMuon.end()){
            Index_VetoMuon.erase(muon_j);
        } else {
            std::cout << "Muon? : " << Index_IsolatedMuon.at(muon_i) << "th Muon - Problem with Veto Cut" << endl;
        } 
    }
    Num_VetoMuon = Index_VetoMuon.size();
    if(Num_VetoMuon == 0) {
        Cut_m_MuonVeto = true;
        if(Num_IsolatedMuon == 0) Cut_e_MuonVeto = true;
    }

    ssbtreeManager->Fill( "Muon_Count", Index_Muon );

    ////////////////////////////
    /////// Electron infor//////
    ////////////////////////////

    Cut_m_ElectronVeto = false;
    Cut_e_ElectronVeto = false;

    Handle<cat::ElectronCollection> electrons;
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

        if(IsolatedElectronID == "Veto")   isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
        if(IsolatedElectronID == "Loose")  isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
        if(IsolatedElectronID == "Medium") isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
        if(IsolatedElectronID == "Tight")  isIsoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");

        if(VetoElectronID == "Veto")   isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-veto");
        if(VetoElectronID == "Loose")  isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-loose");
        if(VetoElectronID == "Medium") isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-medium");
        if(VetoElectronID == "Tight")  isVetoElectronID = electron.electronID("cutBasedElectronID-Summer16-80X-V1-tight");

        PFIsodbeta03 = electron.relIso(0.3);
        SuperClusterEta = electron.scEta();
        PassConversionVeto = electron.passConversionVeto();
        //ChargeConsistent = electron.isGsfScPixChargeConsistent();
        // Gaussian Sum Fitter (GSF) Track
        // Combinatorial Track Finder (CTF) Track
        // Silicon Pixel Detector (ScPix)
        // error: 'const class cat::Electron' has no member named 'isGsfScPixChargeConsistent'

        if((SuperClusterEta < 1.4442 && PFIsodbeta03 < IsoCutLowEta) || (SuperClusterEta > 1.566 && PFIsodbeta03 < IsoCutHighEta)){
            if(isIsoElectronID && (electron.pt() > IsolatedElectronPt) && (std::abs(electron.eta()) < IsolatedElectronEta)){
                isIsolatedElectron = true;
                ++Num_IsolatedElectron;
                Index_IsolatedElectron.push_back(Index_Electron);
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
        //ssbtreeManager->Fill( "Elec_ChargeId_GsfPx"     , ChargeConsistent       );

        ++Index_Electron;
    }

    for(unsigned int elec_i = 0; elec_i < Num_IsolatedElectron; ++elec_i){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
        if(IsoElectron.charge() > 0) ++Num_PlusElectron;
        if(IsoElectron.charge() < 0) ++Num_MinusElectron;
        ssbtreeManager->Fill( "Cut_Elec", IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy(), elec_i );
        LV_electron.SetPtEtaPhiE(IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy());
        LV_AllLepton += LV_electron;
        auto elec_j = std::find(Index_VetoElectron.begin(), Index_VetoElectron.end(), Index_IsolatedElectron.at(elec_i));
        if(elec_j != Index_VetoElectron.end()){
            Index_VetoElectron.erase(elec_j);
        } else {
            std::cout << "Electron? : " << Index_IsolatedElectron.at(elec_i) << "th Electron - Problem with Veto Cut" << endl;
        } 
    }
    Num_VetoElectron = Index_VetoElectron.size();
    if(Num_VetoElectron == 0) {
        Cut_e_ElectronVeto = true;
        if(Num_IsolatedElectron == 0) Cut_m_ElectronVeto = true;
    }

    ssbtreeManager->Fill( "Elec_Count" , Index_Electron );

    Cut_LeptonMass = false;
    Num_PlusLepton = Num_PlusMuon + Num_PlusElectron;
    Num_MinusLepton = Num_MinusMuon + Num_MinusElectron;
    if(LV_AllLepton.Mass() > InclusiveMass+InclusiveMassE || LV_AllLepton.Mass() < InclusiveMass-InclusiveMassE) Cut_LeptonMass = true;

    /////////////////////////
    /// Jets Information  ///
    /////////////////////////

    Index_Jet = 0;
    Index_Cut_Jet = 0;
    Index_Cut_BJet = 0;
 
    Handle<cat::JetCollection> jets;
    iEvent.getByToken(jetToken_, jets);

    for (const cat::Jet &jet : *jets) 
    {

        isJet  = false;
        isCleanedJet = true;
        isBJet = false;

        bDiscriminator     = jet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
        cDiscriminatorCvsL = jet.bDiscriminator("pfCombinedCvsLJetTags");
        cDiscriminatorCvsB = jet.bDiscriminator("pfCombinedCvsBJetTags");

        if(JetID == "Loose") isJet = jet.LooseId();
        if(JetID == "Tight") isJet = jet.TightId();

        LV_jet.SetPtEtaPhiE(jet.pt(), jet.eta(), jet.phi(), jet.energy());
        for(unsigned int muon_i = 0; (muon_i < Num_IsolatedMuon) && isCleanedJet; ++muon_i){
            const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(muon_i));
            LV_muon.SetPtEtaPhiE(IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy());
            if(LV_muon.DeltaR(LV_jet) < JetCleaningdR) isCleanedJet = false;
        }
        for(unsigned int elec_i = 0; (elec_i < Num_IsolatedElectron) && isCleanedJet; ++elec_i){
            const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(elec_i));
            LV_electron.SetPtEtaPhiE(IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy());
            if(LV_electron.DeltaR(LV_jet) < JetCleaningdR) isCleanedJet = false;
        }

        if(isJet && isCleanedJet && (jet.pt() > JetPt) && (std::abs(jet.eta()) < JetEta)){
            ssbtreeManager->Fill( "Cut_Jet", jet.pt(), jet.eta(), jet.phi(), jet.energy(), Index_Cut_Jet );
            ssbtreeManager->Fill( "Cut_Jet_Index", Index_Jet );
            ++Index_Cut_Jet;
            if(bDiscriminator > bDiscCut) {
                isBJet = true;
                ++Index_Cut_BJet;
            }
            ssbtreeManager->Fill( "Cut_Jet_bTag" , isBJet );
        }

        ssbtreeManager->Fill( "Jet", jet.pt(), jet.eta(), jet.phi(), jet.energy(), Index_Jet );
        ssbtreeManager->Fill( "Jet_isJetID"  , isJet     );
        ssbtreeManager->Fill( "Jet_isCleanedJet" , isCleanedJet  );
        ssbtreeManager->Fill( "Jet_bDisc"    , bDiscriminator      );
        ssbtreeManager->Fill( "Jet_cDiscCvsL"    , cDiscriminatorCvsL      );
        ssbtreeManager->Fill( "Jet_cDiscCvsB"    , cDiscriminatorCvsB      );
  
        ++Index_Jet;
    }

    ssbtreeManager->Fill( "Jet_Count", Index_Jet );
    ssbtreeManager->Fill( "Cut_Jet_Count",  Index_Cut_Jet );
    ssbtreeManager->Fill( "Cut_BJet_Count", Index_Cut_BJet );

    ///////////////////////////////
    /////// MET Information ///////
    ///////////////////////////////

    Cut_MET = false;

    Handle<cat::METCollection> mets;
    iEvent.getByToken(metToken_, mets);

    const cat::MET &met = mets->at(0);
    ssbtreeManager->Fill( "MET" , met.pt(), 0, met.phi(), 0, 0 );
    if(met.pt() > METPt){
        Cut_MET = true;
    }

    cutstep();

    /// Fill Ntuples at each event
    ssbtreeManager->FillNtuple();
} // FillNTuple
}


// ------------ method called once each job just before starting event loop  ------------
void 
SSBConverter::beginJob()
{
   ssbtree = ssbfs->make<TTree>("SSBTree", "Tree for Physics Analyses at CMS");
   ssbtreeManager = new SSBTreeManager();
   ssbtreeManager->Book(ssbtree);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SSBConverter::endJob() 
{
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
