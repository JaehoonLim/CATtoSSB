void
SSBConverter::CutStep()
{

    for(unsigned int CutStepInit=0;CutStepInit<CutStepName.size();++CutStepInit){
        Cut_ee_Step[CutStepName[CutStepInit]] = false;
        Cut_mm_Step[CutStepName[CutStepInit]] = false;
        Cut_em_Step[CutStepName[CutStepInit]] = false;
    }

                                                                   Cut_ee_Step["0a"] = true; ee_EventInfo->Fill(0.5,1.0);
    if(Cut_ee_Step["0a"] && Cut_e_Trigger){                        Cut_ee_Step["0b"] = true; ee_EventInfo->Fill(1.5,1.0);}
    if(Cut_ee_Step["0b"] && Cut_Event_Filter){                     Cut_ee_Step["0c"] = true; ee_EventInfo->Fill(2.5,1.0);}
    if(Cut_ee_Step["0c"] && Cut_ee_LeptonPair && Cut_dl_Same){     Cut_ee_Step["1a"] = true; ee_EventInfo->Fill(3.5,1.0);}
    if(Cut_ee_Step["1a"] && Cut_e_Charge){                         Cut_ee_Step["1b"] = true; ee_EventInfo->Fill(4.5,1.0);}
    if(Cut_ee_Step["1b"] && Cut_e_ElectronVeto && Cut_e_MuonVeto){ Cut_ee_Step["2"]  = true; ee_EventInfo->Fill(5.5,1.0);}
    if(Cut_ee_Step["2"]  && Index_Cut_Jet >= 4){                   Cut_ee_Step["3"]  = true; ee_EventInfo->Fill(6.5,1.0);}
    if(Cut_ee_Step["3"]  && Index_Cut_BJet >= 2){                  Cut_ee_Step["4"]  = true; ee_EventInfo->Fill(7.5,1.0);}
    if(Cut_ee_Step["4"]  && HT>500){                               Cut_ee_Step["5"]  = true; ee_EventInfo->Fill(8.5,1.0);}

                                                                   Cut_mm_Step["0a"] = true; mm_EventInfo->Fill(0.5,1.0);
    if(Cut_mm_Step["0a"] && Cut_m_Trigger){                        Cut_mm_Step["0b"] = true; mm_EventInfo->Fill(1.5,1.0);}
    if(Cut_mm_Step["0b"] && Cut_Event_Filter){                     Cut_mm_Step["0c"] = true; mm_EventInfo->Fill(2.5,1.0);}
    if(Cut_mm_Step["0c"] && Cut_mm_LeptonPair && Cut_dl_Same){     Cut_mm_Step["1a"] = true; mm_EventInfo->Fill(3.5,1.0);}
    if(Cut_mm_Step["1a"] && Cut_m_Charge){                         Cut_mm_Step["1b"] = true; mm_EventInfo->Fill(4.5,1.0);}
    if(Cut_mm_Step["1b"] && Cut_m_ElectronVeto && Cut_m_MuonVeto){ Cut_mm_Step["2"]  = true; mm_EventInfo->Fill(5.5,1.0);}
    if(Cut_mm_Step["2"]  && Index_Cut_Jet >= 4){                   Cut_mm_Step["3"]  = true; mm_EventInfo->Fill(6.5,1.0);}
    if(Cut_mm_Step["3"]  && Index_Cut_BJet >= 2){                  Cut_mm_Step["4"]  = true; mm_EventInfo->Fill(7.5,1.0);}
    if(Cut_mm_Step["4"]  && HT>500){                               Cut_mm_Step["5"]  = true; mm_EventInfo->Fill(8.5,1.0);}

                                                                   Cut_em_Step["0a"] = true; em_EventInfo->Fill(0.5,1.0);
    if(Cut_em_Step["0a"] && Cut_em_Trigger){                       Cut_em_Step["0b"] = true; em_EventInfo->Fill(1.5,1.0);}
    if(Cut_em_Step["0b"] && Cut_Event_Filter){                     Cut_em_Step["0c"] = true; em_EventInfo->Fill(2.5,1.0);}
    if(Cut_em_Step["0c"] && Cut_em_LeptonPair && Cut_dl_Same){     Cut_em_Step["1a"] = true; em_EventInfo->Fill(3.5,1.0);}
    if(Cut_em_Step["1a"] && Cut_e_Charge && Cut_m_Charge){         Cut_em_Step["1b"] = true; em_EventInfo->Fill(4.5,1.0);}
    if(Cut_em_Step["1b"] && Cut_e_ElectronVeto && Cut_m_MuonVeto){ Cut_em_Step["2"]  = true; em_EventInfo->Fill(5.5,1.0);}
    if(Cut_em_Step["2"]  && Index_Cut_Jet >= 4){                   Cut_em_Step["3"]  = true; em_EventInfo->Fill(6.5,1.0);}
    if(Cut_em_Step["3"]  && Index_Cut_BJet >= 2){                  Cut_em_Step["4"]  = true; em_EventInfo->Fill(7.5,1.0);}
    if(Cut_em_Step["4"]  && HT>500){                               Cut_em_Step["5"]  = true; em_EventInfo->Fill(8.5,1.0);}

    ssbtreeManager->Fill( "Cut_ee_Step0a",      Cut_ee_Step["0a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0b",      Cut_ee_Step["0b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0c",      Cut_ee_Step["0c"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1a",      Cut_ee_Step["1a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1b",      Cut_ee_Step["1b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step2",       Cut_ee_Step["2"]   );
    ssbtreeManager->Fill( "Cut_ee_Step3",       Cut_ee_Step["3"]   );
    ssbtreeManager->Fill( "Cut_ee_Step4",       Cut_ee_Step["4"]   );
    ssbtreeManager->Fill( "Cut_ee_Step5",       Cut_ee_Step["5"]   );

    ssbtreeManager->Fill( "Cut_mm_Step0a",      Cut_mm_Step["0a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0b",      Cut_mm_Step["0b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0c",      Cut_mm_Step["0c"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1a",      Cut_mm_Step["1a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step1b",      Cut_mm_Step["1b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step2",       Cut_mm_Step["2"]   );
    ssbtreeManager->Fill( "Cut_mm_Step3",       Cut_mm_Step["3"]   );
    ssbtreeManager->Fill( "Cut_mm_Step4",       Cut_mm_Step["4"]   );
    ssbtreeManager->Fill( "Cut_mm_Step5",       Cut_mm_Step["5"]   );

    ssbtreeManager->Fill( "Cut_em_Step0a",      Cut_em_Step["0a"]  );
    ssbtreeManager->Fill( "Cut_em_Step0b",      Cut_em_Step["0b"]  );
    ssbtreeManager->Fill( "Cut_em_Step0c",      Cut_em_Step["0c"]  );
    ssbtreeManager->Fill( "Cut_em_Step1a",      Cut_em_Step["1a"]  );
    ssbtreeManager->Fill( "Cut_em_Step1b",      Cut_em_Step["1b"]  );
    ssbtreeManager->Fill( "Cut_em_Step2",       Cut_em_Step["2"]   );
    ssbtreeManager->Fill( "Cut_em_Step3",       Cut_em_Step["3"]   );
    ssbtreeManager->Fill( "Cut_em_Step4",       Cut_em_Step["4"]   );
    ssbtreeManager->Fill( "Cut_em_Step5",       Cut_em_Step["5"]   );
}

