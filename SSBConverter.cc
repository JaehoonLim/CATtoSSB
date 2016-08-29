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
ej_Trigger(          iConfig.getUntrackedParameter< std::vector<std::string> >( "ejet_Trigger"                              )),
mj_Trigger(          iConfig.getUntrackedParameter< std::vector<std::string> >( "mjet_Trigger"                              )),

IsolatedMuonID(      iConfig.getUntrackedParameter< std::string >(              "mjet_MuonID",        std::string("Tight")  )), 
IsolatedMuonPt(      iConfig.getUntrackedParameter< double >(                   "mjet_MuonPt",        26.0                  )),
IsolatedMuonEta(     iConfig.getUntrackedParameter< double >(                   "mjet_MuonEta",       2.1                   )),
IsolatedMuonIso(     iConfig.getUntrackedParameter< double >(                   "mjet_MuonIso",       0.15                  )),

IsolatedElectronID(  iConfig.getUntrackedParameter< std::string >(              "ejet_ElectronID",    std::string("Medium") )), 
IsolatedElectronPt(  iConfig.getUntrackedParameter< double >(                   "ejet_ElectronPt",    30.0                  )),
IsolatedElectronEta( iConfig.getUntrackedParameter< double >(                   "ejet_ElectronEta",   2.4                   )),

VetoMuonID(          iConfig.getUntrackedParameter< std::string >(              "veto_MuonID",        std::string("Loose")  )), 
VetoMuonPt(          iConfig.getUntrackedParameter< double >(                   "veto_MuonPt",        10.0                  )),
VetoMuonEta(         iConfig.getUntrackedParameter< double >(                   "veto_MuonEta",       2.4                   )),
VetoMuonIso(         iConfig.getUntrackedParameter< double >(                   "veto_MuonIso",       0.25                  )),

VetoElectronID(      iConfig.getUntrackedParameter< std::string >(              "veto_ElectronID",    std::string("Veto")   )), 
VetoElectronPt(      iConfig.getUntrackedParameter< double >(                   "veto_ElectronPt",    10.0                  )),
VetoElectronEta(     iConfig.getUntrackedParameter< double >(                   "veto_ElectronEta",   2.4                   )),

JetID(               iConfig.getUntrackedParameter< std::string >(              "ljet_JetID",         std::string("Loose")  )),   
JetPt(               iConfig.getUntrackedParameter< double >(                   "ljet_JetPt",         30.0                  )),
JetEta(              iConfig.getUntrackedParameter< double >(                   "ljet_JetEta",        2.4                   )),
JetBTag(             iConfig.getUntrackedParameter< std::string >(              "ljet_BTag",          std::string("Medium") )),
JetCleaningdR(       iConfig.getUntrackedParameter< double >(                   "ljet_CleaningdR",    0.4                   )),

METPt(               iConfig.getUntrackedParameter< double >(                   "ljet_METPt",         0.0                   ))
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

    Num_ej_Trigger = ej_Trigger.size();
    Num_mj_Trigger = mj_Trigger.size();

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

    ejets_EventInfo = ssbfs->make<TH1F>("ejets_EventInfo","e+jets Event Information",17,-1,16);
    ejets_EventInfo->GetXaxis()->SetBinLabel(1 ,"Number of Inclusive Samples");
    ejets_EventInfo->GetXaxis()->SetBinLabel(2 ,"0a : Number of Signal Events");
    ejets_EventInfo->GetXaxis()->SetBinLabel(3 ,"0b : Trigger filter");
    ejets_EventInfo->GetXaxis()->SetBinLabel(4 ,"1  : Single lepton");
    ejets_EventInfo->GetXaxis()->SetBinLabel(5 ,"2a : Veto muon");
    ejets_EventInfo->GetXaxis()->SetBinLabel(6 ,"2b : Veto electron");
    ejets_EventInfo->GetXaxis()->SetBinLabel(7 ,"3a : Njets>=1");
    ejets_EventInfo->GetXaxis()->SetBinLabel(8 ,"3b : Njets>=2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(9 ,"3c : Njets>=3");
    ejets_EventInfo->GetXaxis()->SetBinLabel(10 ,"3d : Njets>=4");
    ejets_EventInfo->GetXaxis()->SetBinLabel(11,"3x : Njets==4");
    ejets_EventInfo->GetXaxis()->SetBinLabel(12,"4a : Njets>=4 && Nbjets>=1");
    ejets_EventInfo->GetXaxis()->SetBinLabel(13,"4b : Njets>=4 && Nbjets>=2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(14,"4c : Njets>=4 && Nbjets==2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(15,"4x : Njets==4 && Nbjets>=1");
    ejets_EventInfo->GetXaxis()->SetBinLabel(16,"4y : Njets==4 && Nbjets>=2");
    ejets_EventInfo->GetXaxis()->SetBinLabel(17,"4z : Njets==4 && Nbjets==2");

    mjets_EventInfo = ssbfs->make<TH1F>("mjets_EventInfo","#mu+jets Event Information",17,-1,16);
    mjets_EventInfo->GetXaxis()->SetBinLabel(1 ,"Number of Inclusive Samples");
    mjets_EventInfo->GetXaxis()->SetBinLabel(2 ,"0a : Number of Signal Events");
    mjets_EventInfo->GetXaxis()->SetBinLabel(3 ,"0b : Trigger filter");
    mjets_EventInfo->GetXaxis()->SetBinLabel(4 ,"1  : Single lepton");
    mjets_EventInfo->GetXaxis()->SetBinLabel(5 ,"2a : Veto muon");
    mjets_EventInfo->GetXaxis()->SetBinLabel(6 ,"2b : Veto electron");
    mjets_EventInfo->GetXaxis()->SetBinLabel(7 ,"3a : Njets>=1");
    mjets_EventInfo->GetXaxis()->SetBinLabel(8 ,"3b : Njets>=2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(9 ,"3c : Njets>=3");
    mjets_EventInfo->GetXaxis()->SetBinLabel(10 ,"3d : Njets>=4");
    mjets_EventInfo->GetXaxis()->SetBinLabel(11,"3x : Njets==4");
    mjets_EventInfo->GetXaxis()->SetBinLabel(12,"4a : Njets>=4 && Nbjets>=1");
    mjets_EventInfo->GetXaxis()->SetBinLabel(13,"4b : Njets>=4 && Nbjets>=2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(14,"4c : Njets>=4 && Nbjets==2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(15,"4x : Njets==4 && Nbjets>=1");
    mjets_EventInfo->GetXaxis()->SetBinLabel(16,"4y : Njets==4 && Nbjets>=2");
    mjets_EventInfo->GetXaxis()->SetBinLabel(17,"4z : Njets==4 && Nbjets==2");

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

    Cut_ej_Trigger = false;
    Cut_mj_Trigger = false;
    edm::Handle<edm::TriggerResults> triggerBits;                                                                                        
    iEvent.getByToken(triggerBits_, triggerBits);                                                                                        
    const edm::TriggerNames &trigNames = iEvent.triggerNames(*triggerBits);
    unsigned int Num_Trigger = triggerBits->size();

    for(unsigned int Index_Trigger = 0; Index_Trigger < Num_Trigger; ++Index_Trigger){
        const string& trigName = trigNames.triggerName(Index_Trigger); 
        for(unsigned int Index_ej = 0; Index_ej < Num_ej_Trigger; ++Index_ej){
            if(trigName.find(ej_Trigger.at(Index_ej)) != std::string::npos
               && triggerBits->accept(Index_Trigger)){
                Cut_ej_Trigger = true;
            }
        }    
        for(unsigned int Index_mj = 0; Index_mj < Num_mj_Trigger; ++Index_mj){
            if(trigName.find(mj_Trigger.at(Index_mj)) != std::string::npos
               && triggerBits->accept(Index_Trigger)){
                Cut_mj_Trigger = true;
            }
        }
    }
    if(!Try_Cut_Trigger){
        Cut_ej_Trigger = true;
        Cut_mj_Trigger = true;
    }

    /////////////////////////
    /// Muon Information ////
    /////////////////////////

    Cut_ej_MuonVeto = false;
    Cut_mj_MuonIso  = false;
    Cut_mj_MuonVeto = false;

    Handle<cat::MuonCollection> muons;
    iEvent.getByToken(muonToken_, muons);

    Index_Muon = 0; 
    Num_IsolatedMuon = 0;
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
            Index_IsolatedMuon = Index_Muon;
        }
        if(isVetoIDMuon && (muon.pt() > VetoMuonPt) && (std::abs(muon.eta()) < VetoMuonEta) && PFIsodbeta04 < VetoMuonIso){
            isVetoMuon = true;
            ++Num_VetoMuon;
            Index_VetoMuon = Index_Muon;
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

    if(Num_IsolatedMuon == 0 && Num_VetoMuon == 0) Cut_ej_MuonVeto = true;
    if(Num_IsolatedMuon == 1){
        Cut_mj_MuonIso = true;
        if(Num_VetoMuon == 1 && Index_IsolatedMuon == Index_VetoMuon) Cut_mj_MuonVeto = true;
        if(Num_VetoMuon == 0) std::cout << "Muon? : Num_IsolatedMuon = " << Num_IsolatedMuon << " / Num_VetoMuon = " << Num_VetoMuon << endl;
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon);
        ssbtreeManager->Fill( "Cut_Muon", IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy(), 0 );
        LV_muon.SetPtEtaPhiE(IsoMuon.pt(), IsoMuon.eta(), IsoMuon.phi(), IsoMuon.energy());
    }

    ssbtreeManager->Fill( "Muon_Count", Index_Muon );

    ////////////////////////////
    /////// Electron infor//////
    ////////////////////////////

    Cut_mj_ElectronVeto = false;
    Cut_ej_ElectronIso  = false;
    Cut_ej_ElectronVeto = false;

    Handle<cat::ElectronCollection> electrons;
    iEvent.getByToken(electronToken_, electrons);

    Index_Electron = 0;
    Num_IsolatedElectron = 0;
    Num_VetoElectron = 0;

    for (const cat::Electron &electron : *electrons)
    {

        isIsolatedElectron = false;
        isVetoElectron = false;

        isIsoElectronID = false;
        isVetoElectronID = false;

        if(IsolatedElectronID == "Veto")   isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-veto");
        if(IsolatedElectronID == "Loose")  isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-loose");
        if(IsolatedElectronID == "Medium") isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-medium");
        if(IsolatedElectronID == "Tight")  isIsoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-tight");

        if(VetoElectronID == "Veto")   isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-veto");
        if(VetoElectronID == "Loose")  isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-loose");
        if(VetoElectronID == "Medium") isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-medium");
        if(VetoElectronID == "Tight")  isVetoElectronID = electron.electronID("cutBasedElectronID-Spring15-25ns-V1-standalone-tight");

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
                Index_IsolatedElectron = Index_Electron;
            }
        }
        if((SuperClusterEta < 1.4442 && PFIsodbeta03 < VetoCutLowEta) || (SuperClusterEta > 1.566 && PFIsodbeta03 < VetoCutHighEta)){
            if(isVetoElectronID && (electron.pt() > VetoElectronPt) && (std::abs(electron.eta()) < VetoElectronEta)){
                isVetoElectron = true;
                ++Num_VetoElectron;
                Index_VetoElectron = Index_Electron;
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

    if(Num_IsolatedElectron == 0 && Num_VetoElectron == 0) Cut_mj_ElectronVeto = true;
    if(Num_IsolatedElectron == 1){
        Cut_ej_ElectronIso = true;
        if(Num_VetoElectron == 1 && Index_IsolatedElectron == Index_VetoElectron) Cut_ej_ElectronVeto = true;
        if(Num_VetoElectron == 0) std::cout << "Electron? : Num_IsolatedElectron = " << Num_IsolatedElectron << " / Num_VetoElectron = " << Num_VetoElectron << endl;
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron);
        ssbtreeManager->Fill( "Cut_Elec", IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy(), 0 );
        LV_electron.SetPtEtaPhiE(IsoElectron.pt(), IsoElectron.eta(), IsoElectron.phi(), IsoElectron.energy());
    }

    ssbtreeManager->Fill( "Elec_Count" , Index_Electron );

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
        if(Cut_mj_MuonIso     && (LV_muon.DeltaR(LV_jet)     < JetCleaningdR)) isCleanedJet = false;
        if(Cut_ej_ElectronIso && (LV_electron.DeltaR(LV_jet) < JetCleaningdR)) isCleanedJet = false;

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

    Index_MET = 0;

    Handle<cat::METCollection> mets;
    iEvent.getByToken(metToken_, mets);

    for (const cat::MET &met : *mets)
    {
        if(met.pt() > METPt){
            ssbtreeManager->Fill( "MET" , met.pt(), 0, met.phi(), 0, Index_MET );
            ++Index_MET;
        }
    }

    Cut_ej_Step1  = false;
    Cut_ej_Step2a = false;
    Cut_ej_Step2b = false;
    Cut_mj_Step1  = false;
    Cut_mj_Step2a = false;
    Cut_mj_Step2b = false;

    ejets_EventInfo->Fill(-0.5,1.0);
    mjets_EventInfo->Fill(-0.5,1.0);

    if(FillNTuple){
    ejets_EventInfo->Fill(0.5,1.0);
    if(Cut_ej_Trigger){
        ejets_EventInfo->Fill(1.5,1.0);
        if(Cut_ej_ElectronIso){
            Cut_ej_Step1 = true;
            ejets_EventInfo->Fill(2.5,1.0);
            if(Cut_ej_MuonVeto){
                Cut_ej_Step2a = true;
                ejets_EventInfo->Fill(3.5,1.0);
                if(Cut_ej_ElectronVeto){
                    Cut_ej_Step2b = true;
                    ejets_EventInfo->Fill(4.5,1.0);
                    if(Index_Cut_Jet > 3){
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                        ejets_EventInfo->Fill(7.5,1.0);
                        ejets_EventInfo->Fill(8.5,1.0);
                        if(Index_Cut_BJet > 1){
                            ejets_EventInfo->Fill(10.5,1.0);
                            ejets_EventInfo->Fill(11.5,1.0);
                            if(Index_Cut_BJet == 2) ejets_EventInfo->Fill(12.5,1.0); // NJets>=4 && NBJets==2
                        } // NJets>=4 && NBJets>=2
                        if(Index_Cut_BJet == 1) ejets_EventInfo->Fill(10.5,1.0); // NJets>=4 && NBJets==1
                        if(Index_Cut_Jet == 4){
                            ejets_EventInfo->Fill(9.5,1.0);
                            if(Index_Cut_BJet > 1){
                                ejets_EventInfo->Fill(13.5,1.0);
                                ejets_EventInfo->Fill(14.5,1.0);
                                if(Index_Cut_BJet == 2) ejets_EventInfo->Fill(15.5,1.0); // NJets==4 && NBJets==2
                            } // NJets==4 && NBJets>=2
                            if(Index_Cut_BJet == 1) ejets_EventInfo->Fill(13.5,1.0); // NJets==4 && NBJets==1
                        } // NJets==4
                    } // NJets>=4
                    if(Index_Cut_Jet == 3){
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                        ejets_EventInfo->Fill(7.5,1.0);
                    } // NJets==3
                    if(Index_Cut_Jet == 2){
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                    } // Njets==2
                    if(Index_Cut_Jet == 1) ejets_EventInfo->Fill(5.5,1.0); // Njets==1
                } // ElectronVeto
            } // MuonVeto
        } // Single Electron
    } // Trigger
                
    mjets_EventInfo->Fill(0.5,1.0);
    if(Cut_mj_Trigger){
        mjets_EventInfo->Fill(1.5,1.0);
        if(Cut_mj_MuonIso){
            Cut_mj_Step1 = true;
            mjets_EventInfo->Fill(2.5,1.0);
            if(Cut_mj_MuonVeto){
                Cut_mj_Step2a = true;
                mjets_EventInfo->Fill(3.5,1.0);
                if(Cut_mj_ElectronVeto){
                    Cut_mj_Step2b = true;
                    mjets_EventInfo->Fill(4.5,1.0);
                    if(Index_Cut_Jet > 3){
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                        mjets_EventInfo->Fill(7.5,1.0);
                        mjets_EventInfo->Fill(8.5,1.0);
                        if(Index_Cut_BJet > 1){
                            mjets_EventInfo->Fill(10.5,1.0);
                            mjets_EventInfo->Fill(11.5,1.0);
                            if(Index_Cut_BJet == 2) mjets_EventInfo->Fill(12.5,1.0); // NJets>=4 && NBJets==2
                        } // NJets>=4 && NBJets>=2
                        if(Index_Cut_BJet == 1) mjets_EventInfo->Fill(10.5,1.0); // NJets>=4 && NBJets==1
                        if(Index_Cut_Jet == 4){
                            mjets_EventInfo->Fill(9.5,1.0);
                            if(Index_Cut_BJet > 1){
                                mjets_EventInfo->Fill(13.5,1.0);
                                mjets_EventInfo->Fill(14.5,1.0);
                                if(Index_Cut_BJet == 2) mjets_EventInfo->Fill(15.5,1.0); // NJets==4 && NBJets==2
                            } // NJets==4 && NBJets>=2
                            if(Index_Cut_BJet == 1) mjets_EventInfo->Fill(13.5,1.0); // NJets==4 && NBJets==1
                        } // NJets==4
                    } // NJets>=4
                    if(Index_Cut_Jet == 3){
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                        mjets_EventInfo->Fill(7.5,1.0);
                    } // NJets==3
                    if(Index_Cut_Jet == 2){
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                    } // Njets==2
                    if(Index_Cut_Jet == 1) mjets_EventInfo->Fill(5.5,1.0); // Njets==1
                } // ElectronVeto
            } // MuonVeto
        } // Single Electron
    } // Trigger
    } // FillNTuple

    ssbtreeManager->Fill( "Cut_ejet_Trigger",      Cut_ej_Trigger      );
    ssbtreeManager->Fill( "Cut_ejet_Lepton",       Cut_ej_ElectronIso  );
    ssbtreeManager->Fill( "Cut_ejet_MuonVeto",     Cut_ej_MuonVeto     );
    ssbtreeManager->Fill( "Cut_ejet_ElectronVeto", Cut_ej_ElectronVeto );
    ssbtreeManager->Fill( "Cut_ejet_Step1",        Cut_ej_Step1        );
    ssbtreeManager->Fill( "Cut_ejet_Step2a",       Cut_ej_Step2a       );
    ssbtreeManager->Fill( "Cut_ejet_Step2b",       Cut_ej_Step2b       );

    ssbtreeManager->Fill( "Cut_mjet_Trigger",      Cut_mj_Trigger      );
    ssbtreeManager->Fill( "Cut_mjet_Lepton",       Cut_mj_MuonIso      );
    ssbtreeManager->Fill( "Cut_mjet_MuonVeto",     Cut_mj_MuonVeto     );
    ssbtreeManager->Fill( "Cut_mjet_ElectronVeto", Cut_mj_ElectronVeto );
    ssbtreeManager->Fill( "Cut_mjet_Step1",        Cut_mj_Step1        );
    ssbtreeManager->Fill( "Cut_mjet_Step2a",       Cut_mj_Step2a       );
    ssbtreeManager->Fill( "Cut_mjet_Step2b",       Cut_mj_Step2b       );
                        
    /// Fill Ntuples at each event
    if(FillNTuple) ssbtreeManager->FillNtuple();
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
