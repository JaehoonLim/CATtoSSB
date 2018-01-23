void
SSBConverter::CutStep()
{

    for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
        for(unsigned int CutStepInit=0;CutStepInit<CutStepName.size();++CutStepInit){
            Cut_Step[CutChannelName[CutChannelInit]][CutStepName[CutStepInit]] = false;
        }
    }

/*

 Cut_e_Trigger, Cut_m_Trigger, Cut_em_Trigger
 Cut_Event_Filter

 Num_IsolatedElectron, Num_PlusElectron, Num_MinusElectron
 Num_IsolatedMuon, Num_PlusMuon, Num_MinusMuon
 Num_PlusLepton, Num_MinusLepton

 // l+jets
 Cut_ej_ElectronIso, Cut_mj_MuonIso

 // di-lepton
 Cut_ee_LeptonPair, Cut_mm_LeptonPair, Cut_em_LeptonPair
 Cut_dl_Opposite, Cut_dl_Same
 Cut_LeptonMass

 // tri-lepton
 Cut_Tri_TriOrMore
 Cut_Tri_ee, Cut_Tri_mm, Cut_Tri_em
 Cut_Tri_First_Opposite, Cut_Tri_First_Same

 Cut_Tri_First_Zmass
 Cut_Tri_Second_Zmass
 Cut_SUSY_SRZ

 Cut_MET

 Num_CleanedJet
 Num_BJet

 Num_AdditionalElectron, Num_AdditionalMuon

 Num_VetoElectron, Cut_e_ElectronVeto, Cut_m_ElectronVeto 
 Num_VetoMuon, Cut_m_MuonVeto, Cut_e_MuonVeto

*/

    if(Channel == "TTbar Di-Lepton"){

                                                                          Cut_Step["ee"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                            Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                         Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && Cut_ee_LeptonPair && Cut_dl_Opposite){     Cut_Step["ee"]["1"]  = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["1"]  && Cut_LeptonMass){                           Cut_Step["ee"]["2"]  = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["2"]  && Cut_MET){                                  Cut_Step["ee"]["3"]  = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["3"]  && Num_CleanedJet >= 2){                      Cut_Step["ee"]["4"]  = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["4"]  && Num_BJet >= 1){                            Cut_Step["ee"]["5"]  = true; EventInfo[0]->Fill(7.5,1.0);}

                                                                          Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                            Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                         Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && Cut_mm_LeptonPair && Cut_dl_Opposite){     Cut_Step["mm"]["1"]  = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["1"]  && Cut_LeptonMass){                           Cut_Step["mm"]["2"]  = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["2"]  && Cut_MET){                                  Cut_Step["mm"]["3"]  = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["3"]  && Num_CleanedJet >= 2){                      Cut_Step["mm"]["4"]  = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["mm"]["4"]  && Num_BJet >= 1){                            Cut_Step["mm"]["5"]  = true; EventInfo[1]->Fill(7.5,1.0);}

                                                                          Cut_Step["em"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["em"]["0a"] && Cut_em_Trigger){                           Cut_Step["em"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["em"]["0b"] && Cut_Event_Filter){                         Cut_Step["em"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["em"]["0c"] && Cut_em_LeptonPair && Cut_dl_Opposite){     Cut_Step["em"]["1"]  = true; EventInfo[2]->Fill(3.5,1.0);}
    if(Cut_Step["em"]["1"]  ){                                            Cut_Step["em"]["2"]  = true; EventInfo[2]->Fill(4.5,1.0);}
    if(Cut_Step["em"]["2"]  ){                                            Cut_Step["em"]["3"]  = true; EventInfo[2]->Fill(5.5,1.0);}
    if(Cut_Step["em"]["3"]  && Num_CleanedJet >= 2){                      Cut_Step["em"]["4"]  = true; EventInfo[2]->Fill(6.5,1.0);}
    if(Cut_Step["em"]["4"]  && Num_BJet >= 1){                            Cut_Step["em"]["5"]  = true; EventInfo[2]->Fill(7.5,1.0);}

    ssbtreeManager->Fill( "Cut_ee_Step0a",      Cut_Step["ee"]["0a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0b",      Cut_Step["ee"]["0b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0c",      Cut_Step["ee"]["0c"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1a",      Cut_Step["ee"]["1"]   );
    ssbtreeManager->Fill( "Cut_ee_Step1b",      Cut_Step["ee"]["1"]   );
    ssbtreeManager->Fill( "Cut_ee_Step2",       Cut_Step["ee"]["2"]   );
    ssbtreeManager->Fill( "Cut_ee_Step3",       Cut_Step["ee"]["3"]   );
    ssbtreeManager->Fill( "Cut_ee_Step4",       Cut_Step["ee"]["4"]   );
    ssbtreeManager->Fill( "Cut_ee_Step5",       Cut_Step["ee"]["5"]   );

    ssbtreeManager->Fill( "Cut_mm_Step0a",      Cut_Step["mm"]["0a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0b",      Cut_Step["mm"]["0b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0c",      Cut_Step["mm"]["0c"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1a",      Cut_Step["mm"]["1"]   );
    ssbtreeManager->Fill( "Cut_mm_Step1b",      Cut_Step["mm"]["1"]   );
    ssbtreeManager->Fill( "Cut_mm_Step2",       Cut_Step["mm"]["2"]   );
    ssbtreeManager->Fill( "Cut_mm_Step3",       Cut_Step["mm"]["3"]   );
    ssbtreeManager->Fill( "Cut_mm_Step4",       Cut_Step["mm"]["4"]   );
    ssbtreeManager->Fill( "Cut_mm_Step5",       Cut_Step["mm"]["5"]   );

    ssbtreeManager->Fill( "Cut_em_Step0a",      Cut_Step["em"]["0a"]  );
    ssbtreeManager->Fill( "Cut_em_Step0b",      Cut_Step["em"]["0b"]  );
    ssbtreeManager->Fill( "Cut_em_Step0c",      Cut_Step["em"]["0c"]  );
    ssbtreeManager->Fill( "Cut_em_Step1a",      Cut_Step["em"]["1"]   );
    ssbtreeManager->Fill( "Cut_em_Step1b",      Cut_Step["em"]["1"]   );
    ssbtreeManager->Fill( "Cut_em_Step2",       Cut_Step["em"]["2"]   );
    ssbtreeManager->Fill( "Cut_em_Step3",       Cut_Step["em"]["3"]   );
    ssbtreeManager->Fill( "Cut_em_Step4",       Cut_Step["em"]["4"]   );
    ssbtreeManager->Fill( "Cut_em_Step5",       Cut_Step["em"]["5"]   );

    } // if(Channel == "Di-Lepton")

    else if(Channel == "Lepton+Jets"){

                                                                      Cut_Step["ee"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                        Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                     Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && Cut_ej_ElectronIso){                   Cut_Step["ee"]["1a"] = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["1a"] && Cut_e_Charge){                         Cut_Step["ee"]["1b"] = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Cut_e_ElectronVeto && Cut_e_MuonVeto){ Cut_Step["ee"]["2"]  = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["ee"]["3"]  = true; EventInfo[0]->Fill(6.5,1.0);}

                                                                      Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                        Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                     Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && Cut_mj_MuonIso){                       Cut_Step["mm"]["1a"] = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["1a"] && Cut_m_Charge){                         Cut_Step["mm"]["1b"] = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Cut_m_ElectronVeto && Cut_m_MuonVeto){ Cut_Step["mm"]["2"]  = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["mm"]["3"]  = true; EventInfo[1]->Fill(6.5,1.0);}

    ssbtreeManager->Fill( "Cut_ee_Step0a",      Cut_Step["ee"]["0a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0b",      Cut_Step["ee"]["0b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0c",      Cut_Step["ee"]["0c"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1a",      Cut_Step["ee"]["1a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1b",      Cut_Step["ee"]["1b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step2",       Cut_Step["ee"]["2"]   );
    ssbtreeManager->Fill( "Cut_ee_Step3",       Cut_Step["ee"]["3"]   );
    ssbtreeManager->Fill( "Cut_ee_Step4",       Cut_Step["ee"]["4"]   );
    ssbtreeManager->Fill( "Cut_ee_Step5",       Cut_Step["ee"]["5"]   );

    ssbtreeManager->Fill( "Cut_mm_Step0a",      Cut_Step["mm"]["0a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0b",      Cut_Step["mm"]["0b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0c",      Cut_Step["mm"]["0c"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1a",      Cut_Step["mm"]["1a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1b",      Cut_Step["mm"]["1b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step2",       Cut_Step["mm"]["2"]   );
    ssbtreeManager->Fill( "Cut_mm_Step3",       Cut_Step["mm"]["3"]   );
    ssbtreeManager->Fill( "Cut_mm_Step4",       Cut_Step["mm"]["4"]   );
    ssbtreeManager->Fill( "Cut_mm_Step5",       Cut_Step["mm"]["5"]   );

    } // if(Channel == "Lepton+Jets"){ 

    else if(Channel == "FourTop SUSY"){

                                                                                                                                             Cut_Step["ee"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                                                                                               Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                                                                                            Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && ((Cut_ee_LeptonPair && Cut_dl_Same) || (Cut_Tri_ee || Cut_Tri_Charge))){                                      Cut_Step["ee"]["0d"] = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["0d"] && Cut_ee_LeptonPair && Cut_dl_Same && Cut_e_Charge){                                                            Cut_Step["ee"]["1a"] = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["1a"] && Cut_ee_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["ee"]["BL"] = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SRW"] = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SR1"] = true; EventInfo[0]->Fill(7.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SR2"] = true; EventInfo[0]->Fill(8.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SR3"] = true; EventInfo[0]->Fill(9.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){                          Cut_Step["ee"]["SR4"] = true; EventInfo[0]->Fill(10.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SR5"] = true; EventInfo[0]->Fill(11.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["ee"]["SR6"] = true; EventInfo[0]->Fill(12.5,1.0);}
    if(Cut_Step["ee"]["0d"] && Cut_Tri_ee && Cut_Tri_Charge && Cut_e_Charge){                                                                Cut_Step["ee"]["1b"]  = true; EventInfo[0]->Fill(13.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Cut_ee_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["ee"]["BL2"] = true; EventInfo[0]->Fill(14.5,1.0);}
    if(Cut_Step["ee"]["BL2"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["ee"]["SR7"] = true; EventInfo[0]->Fill(15.5,1.0);}
    if(Cut_Step["ee"]["BL2"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["ee"]["SR8"] = true; EventInfo[0]->Fill(16.5,1.0);}
    if(Cut_SUSY_SRZ && (Cut_Step["ee"]["BL"] || Cut_Step["ee"]["BL2"])){                                                                     Cut_Step["ee"]["SRZ"] = true; EventInfo[0]->Fill(17.5,1.0);}

                                                                                                                                             Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                                                                                               Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                                                                                            Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && ((Cut_mm_LeptonPair && Cut_dl_Same) || (Cut_Tri_mm && Cut_Tri_Charge))){                                      Cut_Step["mm"]["0d"] = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["0d"] && Cut_mm_LeptonPair && Cut_dl_Same && Cut_m_Charge){                                                            Cut_Step["mm"]["1a"] = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["1a"] && Cut_mm_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["mm"]["BL"] = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SRW"] = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SR1"] = true; EventInfo[1]->Fill(7.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SR2"] = true; EventInfo[1]->Fill(8.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SR3"] = true; EventInfo[1]->Fill(9.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){                          Cut_Step["mm"]["SR4"] = true; EventInfo[1]->Fill(10.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SR5"] = true; EventInfo[1]->Fill(11.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["mm"]["SR6"] = true; EventInfo[1]->Fill(12.5,1.0);}
    if(Cut_Step["mm"]["0d"] && Cut_Tri_mm && Cut_Tri_Charge && Cut_m_Charge){                                                                Cut_Step["mm"]["1b"]  = true; EventInfo[1]->Fill(13.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Cut_mm_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["mm"]["BL2"] = true; EventInfo[1]->Fill(14.5,1.0);}
    if(Cut_Step["mm"]["BL2"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["mm"]["SR7"] = true; EventInfo[1]->Fill(15.5,1.0);}
    if(Cut_Step["mm"]["BL2"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["mm"]["SR8"] = true; EventInfo[1]->Fill(16.5,1.0);}
    if(Cut_SUSY_SRZ && (Cut_Step["mm"]["BL"] || Cut_Step["mm"]["BL2"])){                                                                     Cut_Step["mm"]["SRZ"] = true; EventInfo[1]->Fill(17.5,1.0);}

                                                                                                                                             Cut_Step["em"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["em"]["0a"] && Cut_em_Trigger){                                                                                              Cut_Step["em"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["em"]["0b"] && Cut_Event_Filter){                                                                                            Cut_Step["em"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["em"]["0c"] && ((Cut_em_LeptonPair && Cut_dl_Same) || (Cut_Tri_em && Cut_Tri_Charge))){                                      Cut_Step["em"]["0d"] = true; EventInfo[2]->Fill(3.5,1.0);}
    if(Cut_Step["em"]["0d"] && Cut_em_LeptonPair && Cut_dl_Same && Cut_e_Charge && Cut_m_Charge){                                            Cut_Step["em"]["1a"] = true; EventInfo[2]->Fill(4.5,1.0);}
    if(Cut_Step["em"]["1a"] && Cut_em_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["em"]["BL"] = true; EventInfo[2]->Fill(5.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SRW"] = true; EventInfo[2]->Fill(6.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SR1"] = true; EventInfo[2]->Fill(7.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SR2"] = true; EventInfo[2]->Fill(8.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SR3"] = true; EventInfo[2]->Fill(9.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){                          Cut_Step["em"]["SR4"] = true; EventInfo[2]->Fill(10.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SR5"] = true; EventInfo[2]->Fill(11.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                                                  Cut_Step["em"]["SR6"] = true; EventInfo[2]->Fill(12.5,1.0);}
    if(Cut_Step["em"]["0d"] && Cut_Tri_em && Cut_Tri_Charge && Cut_e_Charge && Cut_m_Charge){                                                Cut_Step["em"]["1b"]  = true; EventInfo[2]->Fill(13.5,1.0);}
    if(Cut_Step["em"]["1b"] && Cut_em_LeptonPair_TightMass && Cut_MET && HT > 300 && Index_Cut_BJet >= 2 && Index_Cut_Jet >= 2){             Cut_Step["em"]["BL2"] = true; EventInfo[2]->Fill(14.5,1.0);}
    if(Cut_Step["em"]["BL2"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["em"]["SR7"] = true; EventInfo[2]->Fill(15.5,1.0);}
    if(Cut_Step["em"]["BL2"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){  Cut_Step["em"]["SR8"] = true; EventInfo[2]->Fill(16.5,1.0);}
    if(Cut_SUSY_SRZ && (Cut_Step["em"]["BL"] || Cut_Step["em"]["BL2"])){                                                                     Cut_Step["em"]["SRZ"] = true; EventInfo[2]->Fill(17.5,1.0);}

                                                                                                                                             Cut_Step["All"]["0a"] = true; EventInfo[3]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0b"]  || Cut_Step["mm"]["0b"]  || Cut_Step["em"]["0b"] ){                                                             Cut_Step["All"]["0b"] = true; EventInfo[3]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0c"]  || Cut_Step["mm"]["0c"]  || Cut_Step["em"]["0c"] ){                                                             Cut_Step["All"]["0c"] = true; EventInfo[3]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0d"]  || Cut_Step["mm"]["0d"]  || Cut_Step["em"]["0d"] ){                                                             Cut_Step["All"]["0d"] = true; EventInfo[3]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["1a"]  || Cut_Step["mm"]["1a"]  || Cut_Step["em"]["1a"] ){                                                             Cut_Step["All"]["1a"] = true; EventInfo[3]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["BL"]  || Cut_Step["mm"]["BL"]  || Cut_Step["em"]["BL"] ){                                                             Cut_Step["All"]["BL"] = true; EventInfo[3]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["SRW"] || Cut_Step["mm"]["SRW"] || Cut_Step["em"]["SRW"]){                                                             Cut_Step["All"]["SRW"] = true; EventInfo[3]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["SR1"] || Cut_Step["mm"]["SR1"] || Cut_Step["em"]["SR1"]){                                                             Cut_Step["All"]["SR1"] = true; EventInfo[3]->Fill(7.5,1.0);}
    if(Cut_Step["ee"]["SR2"] || Cut_Step["mm"]["SR2"] || Cut_Step["em"]["SR2"]){                                                             Cut_Step["All"]["SR2"] = true; EventInfo[3]->Fill(8.5,1.0);}
    if(Cut_Step["ee"]["SR3"] || Cut_Step["mm"]["SR3"] || Cut_Step["em"]["SR3"]){                                                             Cut_Step["All"]["SR3"] = true; EventInfo[3]->Fill(9.5,1.0);}
    if(Cut_Step["ee"]["SR4"] || Cut_Step["mm"]["SR4"] || Cut_Step["em"]["SR4"]){                                                             Cut_Step["All"]["SR4"] = true; EventInfo[3]->Fill(10.5,1.0);}
    if(Cut_Step["ee"]["SR5"] || Cut_Step["mm"]["SR5"] || Cut_Step["em"]["SR5"]){                                                             Cut_Step["All"]["SR5"] = true; EventInfo[3]->Fill(11.5,1.0);}
    if(Cut_Step["ee"]["SR6"] || Cut_Step["mm"]["SR6"] || Cut_Step["em"]["SR6"]){                                                             Cut_Step["All"]["SR6"] = true; EventInfo[3]->Fill(12.5,1.0);}
    if(Cut_Step["ee"]["1b"]  || Cut_Step["mm"]["1b"]  || Cut_Step["em"]["1b"] ){                                                             Cut_Step["All"]["1b"]  = true; EventInfo[3]->Fill(13.5,1.0);}
    if(Cut_Step["ee"]["BL2"] || Cut_Step["mm"]["BL2"] || Cut_Step["em"]["BL2"]){                                                             Cut_Step["All"]["BL2"] = true; EventInfo[3]->Fill(14.5,1.0);}
    if(Cut_Step["ee"]["SR7"] || Cut_Step["mm"]["SR7"] || Cut_Step["em"]["SR7"]){                                                             Cut_Step["All"]["SR7"] = true; EventInfo[3]->Fill(15.5,1.0);}
    if(Cut_Step["ee"]["SR8"] || Cut_Step["mm"]["SR8"] || Cut_Step["em"]["SR8"]){                                                             Cut_Step["All"]["SR8"] = true; EventInfo[3]->Fill(16.5,1.0);}
    if(Cut_Step["ee"]["SRZ"] || Cut_Step["mm"]["SRZ"] || Cut_Step["em"]["SRZ"]){                                                             Cut_Step["All"]["SRZ"] = true; EventInfo[3]->Fill(17.5,1.0);}
 
    ssbtreeManager->Fill( "Cut_ee_Step0a", Cut_Step["ee"]["0a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0b", Cut_Step["ee"]["0b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0c", Cut_Step["ee"]["0c"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0d", Cut_Step["ee"]["0d"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1a", Cut_Step["ee"]["1a"]  );
    ssbtreeManager->Fill( "Cut_ee_BaseLine", Cut_Step["ee"]["BL"]  );
    ssbtreeManager->Fill( "Cut_ee_SRW",    Cut_Step["ee"]["SRW"] );
    ssbtreeManager->Fill( "Cut_ee_SR1",    Cut_Step["ee"]["SR1"] );
    ssbtreeManager->Fill( "Cut_ee_SR2",    Cut_Step["ee"]["SR2"] );
    ssbtreeManager->Fill( "Cut_ee_SR3",    Cut_Step["ee"]["SR3"] );
    ssbtreeManager->Fill( "Cut_ee_SR4",    Cut_Step["ee"]["SR4"] );
    ssbtreeManager->Fill( "Cut_ee_SR5",    Cut_Step["ee"]["SR5"] );
    ssbtreeManager->Fill( "Cut_ee_SR6",    Cut_Step["ee"]["SR6"] );
    ssbtreeManager->Fill( "Cut_ee_Step1b", Cut_Step["ee"]["1b"]  );
    ssbtreeManager->Fill( "Cut_ee_BaseLine2", Cut_Step["ee"]["BL2"]  );
    ssbtreeManager->Fill( "Cut_ee_SR7",    Cut_Step["ee"]["SR7"] );
    ssbtreeManager->Fill( "Cut_ee_SR8",    Cut_Step["ee"]["SR8"] );
    ssbtreeManager->Fill( "Cut_ee_SRZ",    Cut_Step["ee"]["SRZ"] );

    ssbtreeManager->Fill( "Cut_mm_Step0a", Cut_Step["mm"]["0a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0b", Cut_Step["mm"]["0b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0c", Cut_Step["mm"]["0c"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0d", Cut_Step["mm"]["0d"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1a", Cut_Step["mm"]["1a"]  );
    ssbtreeManager->Fill( "Cut_mm_BaseLine", Cut_Step["mm"]["BL"]  );
    ssbtreeManager->Fill( "Cut_mm_SRW",    Cut_Step["mm"]["SRW"] );
    ssbtreeManager->Fill( "Cut_mm_SR1",    Cut_Step["mm"]["SR1"] );
    ssbtreeManager->Fill( "Cut_mm_SR2",    Cut_Step["mm"]["SR2"] );
    ssbtreeManager->Fill( "Cut_mm_SR3",    Cut_Step["mm"]["SR3"] );
    ssbtreeManager->Fill( "Cut_mm_SR4",    Cut_Step["mm"]["SR4"] );
    ssbtreeManager->Fill( "Cut_mm_SR5",    Cut_Step["mm"]["SR5"] );
    ssbtreeManager->Fill( "Cut_mm_SR6",    Cut_Step["mm"]["SR6"] );
    ssbtreeManager->Fill( "Cut_mm_Step1b", Cut_Step["mm"]["1b"]  );
    ssbtreeManager->Fill( "Cut_mm_BaseLine2", Cut_Step["mm"]["BL2"]  );
    ssbtreeManager->Fill( "Cut_mm_SR7",    Cut_Step["mm"]["SR7"] );
    ssbtreeManager->Fill( "Cut_mm_SR8",    Cut_Step["mm"]["SR8"] );
    ssbtreeManager->Fill( "Cut_mm_SRZ",    Cut_Step["mm"]["SRZ"] );

    ssbtreeManager->Fill( "Cut_em_Step0a", Cut_Step["em"]["0a"]  );
    ssbtreeManager->Fill( "Cut_em_Step0b", Cut_Step["em"]["0b"]  );
    ssbtreeManager->Fill( "Cut_em_Step0c", Cut_Step["em"]["0c"]  );
    ssbtreeManager->Fill( "Cut_em_Step0d", Cut_Step["em"]["0d"]  );
    ssbtreeManager->Fill( "Cut_em_Step1a", Cut_Step["em"]["1a"]  );
    ssbtreeManager->Fill( "Cut_em_BaseLine", Cut_Step["em"]["BL"]  );
    ssbtreeManager->Fill( "Cut_em_SRW",    Cut_Step["em"]["SRW"] );
    ssbtreeManager->Fill( "Cut_em_SR1",    Cut_Step["em"]["SR1"] );
    ssbtreeManager->Fill( "Cut_em_SR2",    Cut_Step["em"]["SR2"] );
    ssbtreeManager->Fill( "Cut_em_SR3",    Cut_Step["em"]["SR3"] );
    ssbtreeManager->Fill( "Cut_em_SR4",    Cut_Step["em"]["SR4"] );
    ssbtreeManager->Fill( "Cut_em_SR5",    Cut_Step["em"]["SR5"] );
    ssbtreeManager->Fill( "Cut_em_SR6",    Cut_Step["em"]["SR6"] );
    ssbtreeManager->Fill( "Cut_em_Step1b", Cut_Step["em"]["1b"]  );
    ssbtreeManager->Fill( "Cut_em_BaseLine2", Cut_Step["em"]["BL2"]  );
    ssbtreeManager->Fill( "Cut_em_SR7",    Cut_Step["em"]["SR7"] );
    ssbtreeManager->Fill( "Cut_em_SR8",    Cut_Step["em"]["SR8"] );
    ssbtreeManager->Fill( "Cut_em_SRZ",    Cut_Step["em"]["SRZ"] );

    ssbtreeManager->Fill( "Cut_All_Step0a", Cut_Step["All"]["0a"]  );
    ssbtreeManager->Fill( "Cut_All_Step0b", Cut_Step["All"]["0b"]  );
    ssbtreeManager->Fill( "Cut_All_Step0c", Cut_Step["All"]["0c"]  );
    ssbtreeManager->Fill( "Cut_All_Step0d", Cut_Step["All"]["0d"]  );
    ssbtreeManager->Fill( "Cut_All_Step1a", Cut_Step["All"]["1a"]  );
    ssbtreeManager->Fill( "Cut_All_BaseLine", Cut_Step["All"]["BL"]  );
    ssbtreeManager->Fill( "Cut_All_SRW",    Cut_Step["All"]["SRW"] );
    ssbtreeManager->Fill( "Cut_All_SR1",    Cut_Step["All"]["SR1"] );
    ssbtreeManager->Fill( "Cut_All_SR2",    Cut_Step["All"]["SR2"] );
    ssbtreeManager->Fill( "Cut_All_SR3",    Cut_Step["All"]["SR3"] );
    ssbtreeManager->Fill( "Cut_All_SR4",    Cut_Step["All"]["SR4"] );
    ssbtreeManager->Fill( "Cut_All_SR5",    Cut_Step["All"]["SR5"] );
    ssbtreeManager->Fill( "Cut_All_SR6",    Cut_Step["All"]["SR6"] );
    ssbtreeManager->Fill( "Cut_All_Step1b", Cut_Step["All"]["1b"]  );
    ssbtreeManager->Fill( "Cut_All_BaseLine2", Cut_Step["All"]["BL2"]  );
    ssbtreeManager->Fill( "Cut_All_SR7",    Cut_Step["All"]["SR7"] );
    ssbtreeManager->Fill( "Cut_All_SR8",    Cut_Step["All"]["SR8"] );
    ssbtreeManager->Fill( "Cut_All_SRZ",    Cut_Step["All"]["SRZ"] );

    } // if(Channel == "FourTop SUSY"){
}

