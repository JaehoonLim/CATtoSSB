void
SSBConverter::CutStep()
{

    for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
        for(unsigned int CutStepInit=0;CutStepInit<CutStepName.size();++CutStepInit){
            Cut_Step[CutChannelName[CutChannelInit]][CutStepName[CutStepInit]] = false;
        }
    }

                                                                      Cut_Step["ee"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                        Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                     Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && Cut_ee_LeptonPair && Cut_dl_Same){     Cut_Step["ee"]["1a"] = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["1a"] && Cut_e_Charge){                         Cut_Step["ee"]["1b"] = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Cut_e_ElectronVeto && Cut_e_MuonVeto){ Cut_Step["ee"]["2"]  = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["ee"]["3"]  = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["3"]  && Index_Cut_BJet >= 2){                  Cut_Step["ee"]["4"]  = true; EventInfo[0]->Fill(7.5,1.0);}
    if(Cut_Step["ee"]["4"]  && HT>500){                               Cut_Step["ee"]["5"]  = true; EventInfo[0]->Fill(8.5,1.0);}

                                                                      Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                        Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                     Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && Cut_mm_LeptonPair && Cut_dl_Same){     Cut_Step["mm"]["1a"] = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["1a"] && Cut_m_Charge){                         Cut_Step["mm"]["1b"] = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Cut_m_ElectronVeto && Cut_m_MuonVeto){ Cut_Step["mm"]["2"]  = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["mm"]["3"]  = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["mm"]["3"]  && Index_Cut_BJet >= 2){                  Cut_Step["mm"]["4"]  = true; EventInfo[1]->Fill(7.5,1.0);}
    if(Cut_Step["mm"]["4"]  && HT>500){                               Cut_Step["mm"]["5"]  = true; EventInfo[1]->Fill(8.5,1.0);}

                                                                      Cut_Step["em"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["em"]["0a"] && Cut_em_Trigger){                       Cut_Step["em"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["em"]["0b"] && Cut_Event_Filter){                     Cut_Step["em"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["em"]["0c"] && Cut_em_LeptonPair && Cut_dl_Same){     Cut_Step["em"]["1a"] = true; EventInfo[2]->Fill(3.5,1.0);}
    if(Cut_Step["em"]["1a"] && Cut_e_Charge && Cut_m_Charge){         Cut_Step["em"]["1b"] = true; EventInfo[2]->Fill(4.5,1.0);}
    if(Cut_Step["em"]["1b"] && Cut_e_ElectronVeto && Cut_m_MuonVeto){ Cut_Step["em"]["2"]  = true; EventInfo[2]->Fill(5.5,1.0);}
    if(Cut_Step["em"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["em"]["3"]  = true; EventInfo[2]->Fill(6.5,1.0);}
    if(Cut_Step["em"]["3"]  && Index_Cut_BJet >= 2){                  Cut_Step["em"]["4"]  = true; EventInfo[2]->Fill(7.5,1.0);}
    if(Cut_Step["em"]["4"]  && HT>500){                               Cut_Step["em"]["5"]  = true; EventInfo[2]->Fill(8.5,1.0);}

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

    ssbtreeManager->Fill( "Cut_em_Step0a",      Cut_Step["em"]["0a"]  );
    ssbtreeManager->Fill( "Cut_em_Step0b",      Cut_Step["em"]["0b"]  );
    ssbtreeManager->Fill( "Cut_em_Step0c",      Cut_Step["em"]["0c"]  );
    ssbtreeManager->Fill( "Cut_em_Step1a",      Cut_Step["em"]["1a"]  );
    ssbtreeManager->Fill( "Cut_em_Step1b",      Cut_Step["em"]["1b"]  );
    ssbtreeManager->Fill( "Cut_em_Step2",       Cut_Step["em"]["2"]   );
    ssbtreeManager->Fill( "Cut_em_Step3",       Cut_Step["em"]["3"]   );
    ssbtreeManager->Fill( "Cut_em_Step4",       Cut_Step["em"]["4"]   );
    ssbtreeManager->Fill( "Cut_em_Step5",       Cut_Step["em"]["5"]   );
}

