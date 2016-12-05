void
SSBConverter::cutstep()
{

    Cut_ej_ElectronIso = false;
    Cut_ej_Step1  = false;
    Cut_ej_Step2a = false;
    Cut_ej_Step2b = false;

    Cut_mj_MuonIso = false;
    Cut_mj_Step1  = false;
    Cut_mj_Step2a = false;
    Cut_mj_Step2b = false;


    if(Num_IsolatedElectron == 1) Cut_ej_ElectronIso = true;
    if(Num_IsolatedMuon == 1) Cut_mj_MuonIso = true;



    ejets_EventInfo->Fill(0.5,1.0); // e+jets All Signal
    if(Cut_e_Trigger){
        ejets_EventInfo->Fill(1.5,1.0); // Trigger
        if(Cut_ej_ElectronIso){
            Cut_ej_Step1 = true;
            ejets_EventInfo->Fill(2.5,1.0); // 1 Electron
            if(Cut_e_MuonVeto){
                Cut_ej_Step2a = true;
                ejets_EventInfo->Fill(3.5,1.0); // Muon Veto
                if(Cut_e_ElectronVeto){
                    Cut_ej_Step2b = true;
                    ejets_EventInfo->Fill(4.5,1.0); // Electron Veto

                    if(Index_Cut_Jet > 3){ // Number of jets
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                        ejets_EventInfo->Fill(7.5,1.0);
                        ejets_EventInfo->Fill(8.5,1.0);
                        if(Index_Cut_BJet > 1){ // Number of b-jets
                            ejets_EventInfo->Fill( 9.5,1.0);
                            ejets_EventInfo->Fill(10.5,1.0);
                            if(Index_Cut_BJet == 2) ejets_EventInfo->Fill(11.5,1.0); // NJets>=4 && NBJets==2
                        } // NJets>=4 && NBJets>=2
                        if(Index_Cut_BJet == 1) ejets_EventInfo->Fill(9.5,1.0); // NJets>=4 && NBJets==1
                    } // NJets>=4
                    else if(Index_Cut_Jet == 3){
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                        ejets_EventInfo->Fill(7.5,1.0);
                    } // NJets==3
                    else if(Index_Cut_Jet == 2){
                        ejets_EventInfo->Fill(5.5,1.0);
                        ejets_EventInfo->Fill(6.5,1.0);
                    } // Njets==2
                    else if(Index_Cut_Jet == 1) ejets_EventInfo->Fill(5.5,1.0); // Njets==1

                } // ElectronVeto
            } // MuonVeto
        } // Single Electron
    } // Trigger

    mjets_EventInfo->Fill(0.5,1.0); // mu+jets All Signal
    if(Cut_m_Trigger){
        mjets_EventInfo->Fill(1.5,1.0); // Trigger
        if(Cut_mj_MuonIso){
            Cut_mj_Step1 = true;
            mjets_EventInfo->Fill(2.5,1.0); // 1 Muon
            if(Cut_m_MuonVeto){
                Cut_mj_Step2a = true;
                mjets_EventInfo->Fill(3.5,1.0); // Muon Veto
                if(Cut_m_ElectronVeto){
                    Cut_mj_Step2b = true;
                    mjets_EventInfo->Fill(4.5,1.0); // Electron Veto

                    if(Index_Cut_Jet > 3){ // Number of jets
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                        mjets_EventInfo->Fill(7.5,1.0);
                        mjets_EventInfo->Fill(8.5,1.0);
                        if(Index_Cut_BJet > 1){ // Number of b-jets
                            mjets_EventInfo->Fill( 9.5,1.0);
                            mjets_EventInfo->Fill(10.5,1.0);
                            if(Index_Cut_BJet == 2) mjets_EventInfo->Fill(11.5,1.0); // NJets>=4 && NBJets==2
                        } // NJets>=4 && NBJets>=2
                        if(Index_Cut_BJet == 1) mjets_EventInfo->Fill(9.5,1.0); // NJets>=4 && NBJets==1
                    } // NJets>=4
                    else if(Index_Cut_Jet == 3){
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                        mjets_EventInfo->Fill(7.5,1.0);
                    } // NJets==3
                    else if(Index_Cut_Jet == 2){
                        mjets_EventInfo->Fill(5.5,1.0);
                        mjets_EventInfo->Fill(6.5,1.0);
                    } // Njets==2
                    else if(Index_Cut_Jet == 1) mjets_EventInfo->Fill(5.5,1.0); // Njets==1

                } // ElectronVeto
            } // MuonVeto
        } // Single Electron
    } // Trigger

    ssbtreeManager->Fill( "Cut_ejet_Trigger",      Cut_e_Trigger      );
    ssbtreeManager->Fill( "Cut_ejet_Lepton",       Cut_ej_ElectronIso  );
    ssbtreeManager->Fill( "Cut_ejet_MuonVeto",     Cut_e_MuonVeto     );
    ssbtreeManager->Fill( "Cut_ejet_ElectronVeto", Cut_e_ElectronVeto );
    ssbtreeManager->Fill( "Cut_ejet_Step1",        Cut_ej_Step1        );
    ssbtreeManager->Fill( "Cut_ejet_Step2a",       Cut_ej_Step2a       );
    ssbtreeManager->Fill( "Cut_ejet_Step2b",       Cut_ej_Step2b       );

    ssbtreeManager->Fill( "Cut_mjet_Trigger",      Cut_m_Trigger      );
    ssbtreeManager->Fill( "Cut_mjet_Lepton",       Cut_mj_MuonIso      );
    ssbtreeManager->Fill( "Cut_mjet_MuonVeto",     Cut_m_MuonVeto     );
    ssbtreeManager->Fill( "Cut_mjet_ElectronVeto", Cut_m_ElectronVeto );
    ssbtreeManager->Fill( "Cut_mjet_Step1",        Cut_mj_Step1        );
    ssbtreeManager->Fill( "Cut_mjet_Step2a",       Cut_mj_Step2a       );
    ssbtreeManager->Fill( "Cut_mjet_Step2b",       Cut_mj_Step2b       );
                        


}

