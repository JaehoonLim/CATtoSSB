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

 // tri-lepton - 1st di-lepton pair
 Cut_Tri_ee, Cut_Tri_mm, Cut_Tri_em
 Cut_Tri_First_Opposite, Cut_Tri_First_Same
 Cut_Tri_First_Zmass

 Cut_MET

 Num_CleanedJet
 Num_BJet

 Num_AdditionalElectron, Num_AdditionalMuon

 // tri-lepton - additional lepton
 Cut_Tri_ExactlyThree
 Cut_Tri_add_e, Cut_Tri_add_m, Cut_Tri_add_Charge
 Cut_Tri_Second_Zmass

 Num_VetoElectron, Cut_e_ElectronVeto, Cut_m_ElectronVeto 
 Num_VetoMuon, Cut_m_MuonVeto, Cut_e_MuonVeto

 Cut_SUSY_SRZ

*/

    if(Channel == "FourTop Tri-Lepton"){

                                                                                                                        Cut_Step["ss_ee_e"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ss_ee_e"]["0a"] && Cut_e_Trigger){                                                                     Cut_Step["ss_ee_e"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ss_ee_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_ee_e"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ss_ee_e"]["0c"] && Cut_Tri_ee && Cut_Tri_First_Same && DiLeptonMass1 > 10){                            Cut_Step["ss_ee_e"]["1"]  = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ss_ee_e"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_ee_e"]["2"]  = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ss_ee_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_ee_e"]["3"]  = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ss_ee_e"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_ee_e"]["4"]  = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ss_ee_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_ee_e"]["5"]  = true; EventInfo[0]->Fill(7.5,1.0);}
    if(Cut_Step["ss_ee_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_ee_e"]["6a"] = true; EventInfo[0]->Fill(8.5,1.0);}
    if(Cut_Step["ss_ee_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 2){                                     Cut_Step["ss_ee_e"]["6b"] = true; EventInfo[0]->Fill(9.5,1.0);}
    if(Cut_Step["ss_ee_e"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["ss_ee_e"]["7"]  = true; EventInfo[0]->Fill(10.5,1.0);}
    if(Cut_Step["ss_ee_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_ee_e"]["8"]  = true; EventInfo[0]->Fill(11.5,1.0);}
    if(Cut_Step["ss_ee_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_ee_e"]["9"]  = true; EventInfo[0]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_ee_e"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["os_ee_e"]["0a"] && Cut_e_Trigger){                                                                     Cut_Step["os_ee_e"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["os_ee_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_ee_e"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["os_ee_e"]["0c"] && Cut_Tri_ee && Cut_Tri_First_Opposite && DiLeptonMass1 > 10){                        Cut_Step["os_ee_e"]["1"]  = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["os_ee_e"]["1"]  && Cut_Tri_First_Zmass){                                                               Cut_Step["os_ee_e"]["2"]  = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["os_ee_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_ee_e"]["3"]  = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["os_ee_e"]["3"]  && Cut_MET){                                                                           Cut_Step["os_ee_e"]["4"]  = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["os_ee_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_ee_e"]["5"]  = true; EventInfo[1]->Fill(7.5,1.0);}
    if(Cut_Step["os_ee_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_ee_e"]["6a"] = true; EventInfo[1]->Fill(8.5,1.0);}
    if(Cut_Step["os_ee_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 1){                                     Cut_Step["os_ee_e"]["6b"] = true; EventInfo[1]->Fill(9.5,1.0);}
    if(Cut_Step["os_ee_e"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["os_ee_e"]["7"]  = true; EventInfo[1]->Fill(10.5,1.0);}
    if(Cut_Step["os_ee_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_ee_e"]["8"]  = true; EventInfo[1]->Fill(11.5,1.0);}
    if(Cut_Step["os_ee_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_ee_e"]["9"]  = true; EventInfo[1]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["ss_ee_m"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["ss_ee_m"]["0a"] && Cut_e_Trigger){                                                                     Cut_Step["ss_ee_m"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["ss_ee_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_ee_m"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["ss_ee_m"]["0c"] && Cut_Tri_ee && Cut_Tri_First_Same && DiLeptonMass1 > 10){                            Cut_Step["ss_ee_m"]["1"]  = true; EventInfo[2]->Fill(3.5,1.0);}
    if(Cut_Step["ss_ee_m"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_ee_m"]["2"]  = true; EventInfo[2]->Fill(4.5,1.0);}
    if(Cut_Step["ss_ee_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_ee_m"]["3"]  = true; EventInfo[2]->Fill(5.5,1.0);}
    if(Cut_Step["ss_ee_m"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_ee_m"]["4"]  = true; EventInfo[2]->Fill(6.5,1.0);}
    if(Cut_Step["ss_ee_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_ee_m"]["5"]  = true; EventInfo[2]->Fill(7.5,1.0);}
    if(Cut_Step["ss_ee_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_ee_m"]["6a"] = true; EventInfo[2]->Fill(8.5,1.0);}
    if(Cut_Step["ss_ee_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["ss_ee_m"]["6b"] = true; EventInfo[2]->Fill(9.5,1.0);}
    if(Cut_Step["ss_ee_m"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["ss_ee_m"]["7"]  = true; EventInfo[2]->Fill(10.5,1.0);}
    if(Cut_Step["ss_ee_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_ee_m"]["8"]  = true; EventInfo[2]->Fill(11.5,1.0);}
    if(Cut_Step["ss_ee_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_ee_m"]["9"]  = true; EventInfo[2]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_ee_m"]["0a"] = true; EventInfo[3]->Fill(0.5,1.0);
    if(Cut_Step["os_ee_m"]["0a"] && Cut_e_Trigger){                                                                     Cut_Step["os_ee_m"]["0b"] = true; EventInfo[3]->Fill(1.5,1.0);}
    if(Cut_Step["os_ee_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_ee_m"]["0c"] = true; EventInfo[3]->Fill(2.5,1.0);}
    if(Cut_Step["os_ee_m"]["0c"] && Cut_Tri_ee && Cut_Tri_First_Opposite && DiLeptonMass1 > 10){                        Cut_Step["os_ee_m"]["1"]  = true; EventInfo[3]->Fill(3.5,1.0);}
    if(Cut_Step["os_ee_m"]["1"]  && Cut_Tri_First_Zmass){                                                               Cut_Step["os_ee_m"]["2"]  = true; EventInfo[3]->Fill(4.5,1.0);}
    if(Cut_Step["os_ee_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_ee_m"]["3"]  = true; EventInfo[3]->Fill(5.5,1.0);}
    if(Cut_Step["os_ee_m"]["3"]  && Cut_MET){                                                                           Cut_Step["os_ee_m"]["4"]  = true; EventInfo[3]->Fill(6.5,1.0);}
    if(Cut_Step["os_ee_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_ee_m"]["5"]  = true; EventInfo[3]->Fill(7.5,1.0);}
    if(Cut_Step["os_ee_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_ee_m"]["6a"] = true; EventInfo[3]->Fill(8.5,1.0);}
    if(Cut_Step["os_ee_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["os_ee_m"]["6b"] = true; EventInfo[3]->Fill(9.5,1.0);}
    if(Cut_Step["os_ee_m"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["os_ee_m"]["7"]  = true; EventInfo[3]->Fill(10.5,1.0);}
    if(Cut_Step["os_ee_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_ee_m"]["8"]  = true; EventInfo[3]->Fill(11.5,1.0);}
    if(Cut_Step["os_ee_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_ee_m"]["9"]  = true; EventInfo[3]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["ss_em_e"]["0a"] = true; EventInfo[4]->Fill(0.5,1.0);
    if(Cut_Step["ss_em_e"]["0a"] && Cut_em_Trigger){                                                                    Cut_Step["ss_em_e"]["0b"] = true; EventInfo[4]->Fill(1.5,1.0);}
    if(Cut_Step["ss_em_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_em_e"]["0c"] = true; EventInfo[4]->Fill(2.5,1.0);}
    if(Cut_Step["ss_em_e"]["0c"] && Cut_Tri_em /*&& Cut_Tri_First_Opposite*/ && DiLeptonMass1 > 10){                    Cut_Step["ss_em_e"]["1"]  = true; EventInfo[4]->Fill(3.5,1.0);}
    if(Cut_Step["ss_em_e"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_em_e"]["2"]  = true; EventInfo[4]->Fill(4.5,1.0);}
    if(Cut_Step["ss_em_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_em_e"]["3"]  = true; EventInfo[4]->Fill(5.5,1.0);}
    if(Cut_Step["ss_em_e"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_em_e"]["4"]  = true; EventInfo[4]->Fill(6.5,1.0);}
    if(Cut_Step["ss_em_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_em_e"]["5"]  = true; EventInfo[4]->Fill(7.5,1.0);}
    if(Cut_Step["ss_em_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_em_e"]["6a"] = true; EventInfo[4]->Fill(8.5,1.0);}
    if(Cut_Step["ss_em_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["ss_em_e"]["6b"] = true; EventInfo[4]->Fill(9.5,1.0);}
    if(Cut_Step["ss_em_e"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["ss_em_e"]["7"]  = true; EventInfo[4]->Fill(10.5,1.0);}
    if(Cut_Step["ss_em_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_em_e"]["8"]  = true; EventInfo[4]->Fill(11.5,1.0);}
    if(Cut_Step["ss_em_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_em_e"]["9"]  = true; EventInfo[4]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_em_e"]["0a"] = true; EventInfo[5]->Fill(0.5,1.0);
    if(Cut_Step["os_em_e"]["0a"] && Cut_em_Trigger){                                                                    Cut_Step["os_em_e"]["0b"] = true; EventInfo[5]->Fill(1.5,1.0);}
    if(Cut_Step["os_em_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_em_e"]["0c"] = true; EventInfo[5]->Fill(2.5,1.0);}
    if(Cut_Step["os_em_e"]["0c"] && Cut_Tri_em /*&& Cut_Tri_First_Opposite*/ && DiLeptonMass1 > 10){                    Cut_Step["os_em_e"]["1"]  = true; EventInfo[5]->Fill(3.5,1.0);}
    if(Cut_Step["os_em_e"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["os_em_e"]["2"]  = true; EventInfo[5]->Fill(4.5,1.0);}
    if(Cut_Step["os_em_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_em_e"]["3"]  = true; EventInfo[5]->Fill(5.5,1.0);}
    if(Cut_Step["os_em_e"]["3"]  && Cut_MET){                                                                           Cut_Step["os_em_e"]["4"]  = true; EventInfo[5]->Fill(6.5,1.0);}
    if(Cut_Step["os_em_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_em_e"]["5"]  = true; EventInfo[5]->Fill(7.5,1.0);}
    if(Cut_Step["os_em_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_em_e"]["6a"] = true; EventInfo[5]->Fill(8.5,1.0);}
    if(Cut_Step["os_em_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 1){                                     Cut_Step["os_em_e"]["6b"] = true; EventInfo[5]->Fill(9.5,1.0);}
    if(Cut_Step["os_em_e"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["os_em_e"]["7"]  = true; EventInfo[5]->Fill(10.5,1.0);}
    if(Cut_Step["os_em_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_em_e"]["8"]  = true; EventInfo[5]->Fill(11.5,1.0);}
    if(Cut_Step["os_em_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_em_e"]["9"]  = true; EventInfo[5]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["ss_em_m"]["0a"] = true; EventInfo[6]->Fill(0.5,1.0);
    if(Cut_Step["ss_em_m"]["0a"] && Cut_em_Trigger){                                                                    Cut_Step["ss_em_m"]["0b"] = true; EventInfo[6]->Fill(1.5,1.0);}
    if(Cut_Step["ss_em_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_em_m"]["0c"] = true; EventInfo[6]->Fill(2.5,1.0);}
    if(Cut_Step["ss_em_m"]["0c"] && Cut_Tri_em /*&& Cut_Tri_First_Same*/ && DiLeptonMass1 > 10){                        Cut_Step["ss_em_m"]["1"]  = true; EventInfo[6]->Fill(3.5,1.0);}
    if(Cut_Step["ss_em_m"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_em_m"]["2"]  = true; EventInfo[6]->Fill(4.5,1.0);}
    if(Cut_Step["ss_em_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_em_m"]["3"]  = true; EventInfo[6]->Fill(5.5,1.0);}
    if(Cut_Step["ss_em_m"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_em_m"]["4"]  = true; EventInfo[6]->Fill(6.5,1.0);}
    if(Cut_Step["ss_em_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_em_m"]["5"]  = true; EventInfo[6]->Fill(7.5,1.0);}
    if(Cut_Step["ss_em_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_em_m"]["6a"] = true; EventInfo[6]->Fill(8.5,1.0);}
    if(Cut_Step["ss_em_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["ss_em_m"]["6b"] = true; EventInfo[6]->Fill(9.5,1.0);}
    if(Cut_Step["ss_em_m"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["ss_em_m"]["7"]  = true; EventInfo[6]->Fill(10.5,1.0);}
    if(Cut_Step["ss_em_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_em_m"]["8"]  = true; EventInfo[6]->Fill(11.5,1.0);}
    if(Cut_Step["ss_em_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_em_m"]["9"]  = true; EventInfo[6]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_em_m"]["0a"] = true; EventInfo[7]->Fill(0.5,1.0);
    if(Cut_Step["os_em_m"]["0a"] && Cut_em_Trigger){                                                                    Cut_Step["os_em_m"]["0b"] = true; EventInfo[7]->Fill(1.5,1.0);}
    if(Cut_Step["os_em_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_em_m"]["0c"] = true; EventInfo[7]->Fill(2.5,1.0);}
    if(Cut_Step["os_em_m"]["0c"] && Cut_Tri_em /*&& Cut_Tri_First_Opposite*/ && DiLeptonMass1 > 10){                    Cut_Step["os_em_m"]["1"]  = true; EventInfo[7]->Fill(3.5,1.0);}
    if(Cut_Step["os_em_m"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["os_em_m"]["2"]  = true; EventInfo[7]->Fill(4.5,1.0);}
    if(Cut_Step["os_em_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_em_m"]["3"]  = true; EventInfo[7]->Fill(5.5,1.0);}
    if(Cut_Step["os_em_m"]["3"]  && Cut_MET){                                                                           Cut_Step["os_em_m"]["4"]  = true; EventInfo[7]->Fill(6.5,1.0);}
    if(Cut_Step["os_em_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_em_m"]["5"]  = true; EventInfo[7]->Fill(7.5,1.0);}
    if(Cut_Step["os_em_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_em_m"]["6a"] = true; EventInfo[7]->Fill(8.5,1.0);}
    if(Cut_Step["os_em_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 1){                                     Cut_Step["os_em_m"]["6b"] = true; EventInfo[7]->Fill(9.5,1.0);}
    if(Cut_Step["os_em_m"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["os_em_m"]["7"]  = true; EventInfo[7]->Fill(10.5,1.0);}
    if(Cut_Step["os_em_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_em_m"]["8"]  = true; EventInfo[7]->Fill(11.5,1.0);}
    if(Cut_Step["os_em_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_em_m"]["9"]  = true; EventInfo[7]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["ss_mm_e"]["0a"] = true; EventInfo[8]->Fill(0.5,1.0);
    if(Cut_Step["ss_mm_e"]["0a"] && Cut_m_Trigger){                                                                     Cut_Step["ss_mm_e"]["0b"] = true; EventInfo[8]->Fill(1.5,1.0);}
    if(Cut_Step["ss_mm_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_mm_e"]["0c"] = true; EventInfo[8]->Fill(2.5,1.0);}
    if(Cut_Step["ss_mm_e"]["0c"] && Cut_Tri_mm && Cut_Tri_First_Same && DiLeptonMass1 > 10){                            Cut_Step["ss_mm_e"]["1"]  = true; EventInfo[8]->Fill(3.5,1.0);}
    if(Cut_Step["ss_mm_e"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_mm_e"]["2"]  = true; EventInfo[8]->Fill(4.5,1.0);}
    if(Cut_Step["ss_mm_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_mm_e"]["3"]  = true; EventInfo[8]->Fill(5.5,1.0);}
    if(Cut_Step["ss_mm_e"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_mm_e"]["4"]  = true; EventInfo[8]->Fill(6.5,1.0);}
    if(Cut_Step["ss_mm_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_mm_e"]["5"]  = true; EventInfo[8]->Fill(7.5,1.0);}
    if(Cut_Step["ss_mm_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_mm_e"]["6a"] = true; EventInfo[8]->Fill(8.5,1.0);}
    if(Cut_Step["ss_mm_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["ss_mm_e"]["6b"] = true; EventInfo[8]->Fill(9.5,1.0);}
    if(Cut_Step["ss_mm_e"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["ss_mm_e"]["7"]  = true; EventInfo[8]->Fill(10.5,1.0);}
    if(Cut_Step["ss_mm_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_mm_e"]["8"]  = true; EventInfo[8]->Fill(11.5,1.0);}
    if(Cut_Step["ss_mm_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_mm_e"]["9"]  = true; EventInfo[8]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_mm_e"]["0a"] = true; EventInfo[9]->Fill(0.5,1.0);
    if(Cut_Step["os_mm_e"]["0a"] && Cut_m_Trigger){                                                                     Cut_Step["os_mm_e"]["0b"] = true; EventInfo[9]->Fill(1.5,1.0);}
    if(Cut_Step["os_mm_e"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_mm_e"]["0c"] = true; EventInfo[9]->Fill(2.5,1.0);}
    if(Cut_Step["os_mm_e"]["0c"] && Cut_Tri_mm && Cut_Tri_First_Opposite && DiLeptonMass1 > 10){                        Cut_Step["os_mm_e"]["1"]  = true; EventInfo[9]->Fill(3.5,1.0);}
    if(Cut_Step["os_mm_e"]["1"]  && Cut_Tri_First_Zmass){                                                               Cut_Step["os_mm_e"]["2"]  = true; EventInfo[9]->Fill(4.5,1.0);}
    if(Cut_Step["os_mm_e"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_mm_e"]["3"]  = true; EventInfo[9]->Fill(5.5,1.0);}
    if(Cut_Step["os_mm_e"]["3"]  && Cut_MET){                                                                           Cut_Step["os_mm_e"]["4"]  = true; EventInfo[9]->Fill(6.5,1.0);}
    if(Cut_Step["os_mm_e"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_mm_e"]["5"]  = true; EventInfo[9]->Fill(7.5,1.0);}
    if(Cut_Step["os_mm_e"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_e && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_mm_e"]["6a"] = true; EventInfo[9]->Fill(8.5,1.0);}
    if(Cut_Step["os_mm_e"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 0){                                     Cut_Step["os_mm_e"]["6b"] = true; EventInfo[9]->Fill(9.5,1.0);}
    if(Cut_Step["os_mm_e"]["6b"] /*&& Cut_Tri_Second_Zmass*/){                                                          Cut_Step["os_mm_e"]["7"]  = true; EventInfo[9]->Fill(10.5,1.0);}
    if(Cut_Step["os_mm_e"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_mm_e"]["8"]  = true; EventInfo[9]->Fill(11.5,1.0);}
    if(Cut_Step["os_mm_e"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_mm_e"]["9"]  = true; EventInfo[9]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["ss_mm_m"]["0a"] = true; EventInfo[10]->Fill(0.5,1.0);
    if(Cut_Step["ss_mm_m"]["0a"] && Cut_m_Trigger){                                                                     Cut_Step["ss_mm_m"]["0b"] = true; EventInfo[10]->Fill(1.5,1.0);}
    if(Cut_Step["ss_mm_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["ss_mm_m"]["0c"] = true; EventInfo[10]->Fill(2.5,1.0);}
    if(Cut_Step["ss_mm_m"]["0c"] && Cut_Tri_mm && Cut_Tri_First_Same && DiLeptonMass1 > 10){                            Cut_Step["ss_mm_m"]["1"]  = true; EventInfo[10]->Fill(3.5,1.0);}
    if(Cut_Step["ss_mm_m"]["1"]  /*&& Cut_Tri_First_Zmass*/){                                                           Cut_Step["ss_mm_m"]["2"]  = true; EventInfo[10]->Fill(4.5,1.0);}
    if(Cut_Step["ss_mm_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["ss_mm_m"]["3"]  = true; EventInfo[10]->Fill(5.5,1.0);}
    if(Cut_Step["ss_mm_m"]["3"]  && Cut_MET){                                                                           Cut_Step["ss_mm_m"]["4"]  = true; EventInfo[10]->Fill(6.5,1.0);}
    if(Cut_Step["ss_mm_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["ss_mm_m"]["5"]  = true; EventInfo[10]->Fill(7.5,1.0);}
    if(Cut_Step["ss_mm_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["ss_mm_m"]["6a"] = true; EventInfo[10]->Fill(8.5,1.0);}
    if(Cut_Step["ss_mm_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 2){                                     Cut_Step["ss_mm_m"]["6b"] = true; EventInfo[10]->Fill(9.5,1.0);}
    if(Cut_Step["ss_mm_m"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["ss_mm_m"]["7"]  = true; EventInfo[10]->Fill(10.5,1.0);}
    if(Cut_Step["ss_mm_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["ss_mm_m"]["8"]  = true; EventInfo[10]->Fill(11.5,1.0);}
    if(Cut_Step["ss_mm_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["ss_mm_m"]["9"]  = true; EventInfo[10]->Fill(12.5,1.0);}

                                                                                                                        Cut_Step["os_mm_m"]["0a"] = true; EventInfo[11]->Fill(0.5,1.0);
    if(Cut_Step["os_mm_m"]["0a"] && Cut_m_Trigger){                                                                     Cut_Step["os_mm_m"]["0b"] = true; EventInfo[11]->Fill(1.5,1.0);}
    if(Cut_Step["os_mm_m"]["0b"] && Cut_Event_Filter){                                                                  Cut_Step["os_mm_m"]["0c"] = true; EventInfo[11]->Fill(2.5,1.0);}
    if(Cut_Step["os_mm_m"]["0c"] && Cut_Tri_mm && Cut_Tri_First_Opposite && DiLeptonMass1 > 10){                        Cut_Step["os_mm_m"]["1"]  = true; EventInfo[11]->Fill(3.5,1.0);}
    if(Cut_Step["os_mm_m"]["1"]  && Cut_Tri_First_Zmass){                                                               Cut_Step["os_mm_m"]["2"]  = true; EventInfo[11]->Fill(4.5,1.0);}
    if(Cut_Step["os_mm_m"]["2"]  && Num_CleanedJet >= 2){                                                               Cut_Step["os_mm_m"]["3"]  = true; EventInfo[11]->Fill(5.5,1.0);}
    if(Cut_Step["os_mm_m"]["3"]  && Cut_MET){                                                                           Cut_Step["os_mm_m"]["4"]  = true; EventInfo[11]->Fill(6.5,1.0);}
    if(Cut_Step["os_mm_m"]["4"]  && Num_BJet >= 2){                                                                     Cut_Step["os_mm_m"]["5"]  = true; EventInfo[11]->Fill(7.5,1.0);}
    if(Cut_Step["os_mm_m"]["5"]  && Cut_Tri_ExactlyThree && Cut_Tri_add_m && DiLeptonMass2 > 10 && DiLeptonMass3 > 10){ Cut_Step["os_mm_m"]["6a"] = true; EventInfo[11]->Fill(8.5,1.0);}
    if(Cut_Step["os_mm_m"]["6a"] && Cut_Tri_add_Charge && Num_OppositeLepton == 1){                                     Cut_Step["os_mm_m"]["6b"] = true; EventInfo[11]->Fill(9.5,1.0);}
    if(Cut_Step["os_mm_m"]["6b"] && Cut_Tri_Second_Zmass){                                                              Cut_Step["os_mm_m"]["7"]  = true; EventInfo[11]->Fill(10.5,1.0);}
    if(Cut_Step["os_mm_m"]["7"]  && Num_CleanedJet >= 4){                                                               Cut_Step["os_mm_m"]["8"]  = true; EventInfo[11]->Fill(11.5,1.0);}
    if(Cut_Step["os_mm_m"]["8"]  && Num_BJet >= 3){                                                                     Cut_Step["os_mm_m"]["9"]  = true; EventInfo[11]->Fill(12.5,1.0);}

    if(Cut_Step["ss_ee_e"]["0a"] || Cut_Step["os_ee_e"]["0a"]){                                                        Cut_Step["eee"]["0a"] = true; EventInfo[12]->Fill(0.5,1.0);}
    if(Cut_Step["ss_ee_e"]["0b"] || Cut_Step["os_ee_e"]["0b"]){                                                        Cut_Step["eee"]["0b"] = true; EventInfo[12]->Fill(1.5,1.0);}
    if(Cut_Step["ss_ee_e"]["0c"] || Cut_Step["os_ee_e"]["0c"]){                                                        Cut_Step["eee"]["0c"] = true; EventInfo[12]->Fill(2.5,1.0);}
    if(Cut_Step["ss_ee_e"]["1"]  || Cut_Step["os_ee_e"]["1"] ){                                                        Cut_Step["eee"]["1"]  = true; EventInfo[12]->Fill(3.5,1.0);}
    if(Cut_Step["ss_ee_e"]["2"]  || Cut_Step["os_ee_e"]["2"] ){                                                        Cut_Step["eee"]["2"]  = true; EventInfo[12]->Fill(4.5,1.0);}
    if(Cut_Step["ss_ee_e"]["3"]  || Cut_Step["os_ee_e"]["3"] ){                                                        Cut_Step["eee"]["3"]  = true; EventInfo[12]->Fill(5.5,1.0);}
    if(Cut_Step["ss_ee_e"]["4"]  || Cut_Step["os_ee_e"]["4"] ){                                                        Cut_Step["eee"]["4"]  = true; EventInfo[12]->Fill(6.5,1.0);}
    if(Cut_Step["ss_ee_e"]["5"]  || Cut_Step["os_ee_e"]["5"] ){                                                        Cut_Step["eee"]["5"]  = true; EventInfo[12]->Fill(7.5,1.0);}
    if(Cut_Step["ss_ee_e"]["6a"] || Cut_Step["os_ee_e"]["6a"]){                                                        Cut_Step["eee"]["6a"] = true; EventInfo[12]->Fill(8.5,1.0);}
    if(Cut_Step["ss_ee_e"]["6b"] || Cut_Step["os_ee_e"]["6b"]){                                                        Cut_Step["eee"]["6b"] = true; EventInfo[12]->Fill(9.5,1.0);}
    if(Cut_Step["ss_ee_e"]["7"]  || Cut_Step["os_ee_e"]["7"] ){                                                        Cut_Step["eee"]["7"]  = true; EventInfo[12]->Fill(10.5,1.0);}
    if(Cut_Step["ss_ee_e"]["8"]  || Cut_Step["os_ee_e"]["8"] ){                                                        Cut_Step["eee"]["8"]  = true; EventInfo[12]->Fill(11.5,1.0);}
    if(Cut_Step["ss_ee_e"]["9"]  || Cut_Step["os_ee_e"]["9"] ){                                                        Cut_Step["eee"]["9"]  = true; EventInfo[12]->Fill(12.5,1.0);}

    if(Cut_Step["ss_mm_m"]["0a"] || Cut_Step["os_mm_m"]["0a"]){                                                        Cut_Step["mmm"]["0a"] = true; EventInfo[13]->Fill(0.5,1.0);}
    if(Cut_Step["ss_mm_m"]["0b"] || Cut_Step["os_mm_m"]["0b"]){                                                        Cut_Step["mmm"]["0b"] = true; EventInfo[13]->Fill(1.5,1.0);}
    if(Cut_Step["ss_mm_m"]["0c"] || Cut_Step["os_mm_m"]["0c"]){                                                        Cut_Step["mmm"]["0c"] = true; EventInfo[13]->Fill(2.5,1.0);}
    if(Cut_Step["ss_mm_m"]["1"]  || Cut_Step["os_mm_m"]["1"] ){                                                        Cut_Step["mmm"]["1"]  = true; EventInfo[13]->Fill(3.5,1.0);}
    if(Cut_Step["ss_mm_m"]["2"]  || Cut_Step["os_mm_m"]["2"] ){                                                        Cut_Step["mmm"]["2"]  = true; EventInfo[13]->Fill(4.5,1.0);}
    if(Cut_Step["ss_mm_m"]["3"]  || Cut_Step["os_mm_m"]["3"] ){                                                        Cut_Step["mmm"]["3"]  = true; EventInfo[13]->Fill(5.5,1.0);}
    if(Cut_Step["ss_mm_m"]["4"]  || Cut_Step["os_mm_m"]["4"] ){                                                        Cut_Step["mmm"]["4"]  = true; EventInfo[13]->Fill(6.5,1.0);}
    if(Cut_Step["ss_mm_m"]["5"]  || Cut_Step["os_mm_m"]["5"] ){                                                        Cut_Step["mmm"]["5"]  = true; EventInfo[13]->Fill(7.5,1.0);}
    if(Cut_Step["ss_mm_m"]["6a"] || Cut_Step["os_mm_m"]["6a"]){                                                        Cut_Step["mmm"]["6a"] = true; EventInfo[13]->Fill(8.5,1.0);}
    if(Cut_Step["ss_mm_m"]["6b"] || Cut_Step["os_mm_m"]["6b"]){                                                        Cut_Step["mmm"]["6b"] = true; EventInfo[13]->Fill(9.5,1.0);}
    if(Cut_Step["ss_mm_m"]["7"]  || Cut_Step["os_mm_m"]["7"] ){                                                        Cut_Step["mmm"]["7"]  = true; EventInfo[13]->Fill(10.5,1.0);}
    if(Cut_Step["ss_mm_m"]["8"]  || Cut_Step["os_mm_m"]["8"] ){                                                        Cut_Step["mmm"]["8"]  = true; EventInfo[13]->Fill(11.5,1.0);}
    if(Cut_Step["ss_mm_m"]["9"]  || Cut_Step["os_mm_m"]["9"] ){                                                        Cut_Step["mmm"]["9"]  = true; EventInfo[13]->Fill(12.5,1.0);}
                                                              
    if(Cut_Step["ss_ee_m"]["0a"] || Cut_Step["ss_em_e"]["0a"]){                                                         Cut_Step["ss_eem"]["0a"] = true; EventInfo[14]->Fill(0.5,1.0);}
    if(Cut_Step["ss_ee_m"]["0b"] || Cut_Step["ss_em_e"]["0b"]){                                                         Cut_Step["ss_eem"]["0b"] = true; EventInfo[14]->Fill(1.5,1.0);}
    if(Cut_Step["ss_ee_m"]["0c"] || Cut_Step["ss_em_e"]["0c"]){                                                         Cut_Step["ss_eem"]["0c"] = true; EventInfo[14]->Fill(2.5,1.0);}
    if(Cut_Step["ss_ee_m"]["1"]  || Cut_Step["ss_em_e"]["1"] ){                                                         Cut_Step["ss_eem"]["1"]  = true; EventInfo[14]->Fill(3.5,1.0);}
    if(Cut_Step["ss_ee_m"]["2"]  || Cut_Step["ss_em_e"]["2"] ){                                                         Cut_Step["ss_eem"]["2"]  = true; EventInfo[14]->Fill(4.5,1.0);}
    if(Cut_Step["ss_ee_m"]["3"]  || Cut_Step["ss_em_e"]["3"] ){                                                         Cut_Step["ss_eem"]["3"]  = true; EventInfo[14]->Fill(5.5,1.0);}
    if(Cut_Step["ss_ee_m"]["4"]  || Cut_Step["ss_em_e"]["4"] ){                                                         Cut_Step["ss_eem"]["4"]  = true; EventInfo[14]->Fill(6.5,1.0);}
    if(Cut_Step["ss_ee_m"]["5"]  || Cut_Step["ss_em_e"]["5"] ){                                                         Cut_Step["ss_eem"]["5"]  = true; EventInfo[14]->Fill(7.5,1.0);}
    if(Cut_Step["ss_ee_m"]["6a"] || Cut_Step["ss_em_e"]["6a"]){                                                         Cut_Step["ss_eem"]["6a"] = true; EventInfo[14]->Fill(8.5,1.0);}
    if(Cut_Step["ss_ee_m"]["6b"] || Cut_Step["ss_em_e"]["6b"]){                                                         Cut_Step["ss_eem"]["6b"] = true; EventInfo[14]->Fill(9.5,1.0);}
    if(Cut_Step["ss_ee_m"]["7"]  || Cut_Step["ss_em_e"]["7"] ){                                                         Cut_Step["ss_eem"]["7"]  = true; EventInfo[14]->Fill(10.5,1.0);}
    if(Cut_Step["ss_ee_m"]["8"]  || Cut_Step["ss_em_e"]["8"] ){                                                         Cut_Step["ss_eem"]["8"]  = true; EventInfo[14]->Fill(11.5,1.0);}
    if(Cut_Step["ss_ee_m"]["9"]  || Cut_Step["ss_em_e"]["9"] ){                                                         Cut_Step["ss_eem"]["9"]  = true; EventInfo[14]->Fill(12.5,1.0);}
                                                               
    if(Cut_Step["os_ee_m"]["0a"] || Cut_Step["os_em_e"]["0a"]){                                                         Cut_Step["os_eem"]["0a"] = true; EventInfo[15]->Fill(0.5,1.0);}
    if(Cut_Step["os_ee_m"]["0b"] || Cut_Step["os_em_e"]["0b"]){                                                         Cut_Step["os_eem"]["0b"] = true; EventInfo[15]->Fill(1.5,1.0);}
    if(Cut_Step["os_ee_m"]["0c"] || Cut_Step["os_em_e"]["0c"]){                                                         Cut_Step["os_eem"]["0c"] = true; EventInfo[15]->Fill(2.5,1.0);}
    if(Cut_Step["os_ee_m"]["1"]  || Cut_Step["os_em_e"]["1"] ){                                                         Cut_Step["os_eem"]["1"]  = true; EventInfo[15]->Fill(3.5,1.0);}
    if(Cut_Step["os_ee_m"]["2"]  || Cut_Step["os_em_e"]["2"] ){                                                         Cut_Step["os_eem"]["2"]  = true; EventInfo[15]->Fill(4.5,1.0);}
    if(Cut_Step["os_ee_m"]["3"]  || Cut_Step["os_em_e"]["3"] ){                                                         Cut_Step["os_eem"]["3"]  = true; EventInfo[15]->Fill(5.5,1.0);}
    if(Cut_Step["os_ee_m"]["4"]  || Cut_Step["os_em_e"]["4"] ){                                                         Cut_Step["os_eem"]["4"]  = true; EventInfo[15]->Fill(6.5,1.0);}
    if(Cut_Step["os_ee_m"]["5"]  || Cut_Step["os_em_e"]["5"] ){                                                         Cut_Step["os_eem"]["5"]  = true; EventInfo[15]->Fill(7.5,1.0);}
    if(Cut_Step["os_ee_m"]["6a"] || Cut_Step["os_em_e"]["6a"]){                                                         Cut_Step["os_eem"]["6a"] = true; EventInfo[15]->Fill(8.5,1.0);}
    if(Cut_Step["os_ee_m"]["6b"] || Cut_Step["os_em_e"]["6b"]){                                                         Cut_Step["os_eem"]["6b"] = true; EventInfo[15]->Fill(9.5,1.0);}
    if(Cut_Step["os_ee_m"]["7"]  || Cut_Step["os_em_e"]["7"] ){                                                         Cut_Step["os_eem"]["7"]  = true; EventInfo[15]->Fill(10.5,1.0);}
    if(Cut_Step["os_ee_m"]["8"]  || Cut_Step["os_em_e"]["8"] ){                                                         Cut_Step["os_eem"]["8"]  = true; EventInfo[15]->Fill(11.5,1.0);}
    if(Cut_Step["os_ee_m"]["9"]  || Cut_Step["os_em_e"]["9"] ){                                                         Cut_Step["os_eem"]["9"]  = true; EventInfo[15]->Fill(12.5,1.0);}
                                                             
    if(Cut_Step["ss_eem"]["0a"] || Cut_Step["os_eem"]["0a"]){                                                           Cut_Step["eem"]["0a"] = true; EventInfo[16]->Fill(0.5,1.0);}
    if(Cut_Step["ss_eem"]["0b"] || Cut_Step["os_eem"]["0b"]){                                                           Cut_Step["eem"]["0b"] = true; EventInfo[16]->Fill(1.5,1.0);}
    if(Cut_Step["ss_eem"]["0c"] || Cut_Step["os_eem"]["0c"]){                                                           Cut_Step["eem"]["0c"] = true; EventInfo[16]->Fill(2.5,1.0);}
    if(Cut_Step["ss_eem"]["1"]  || Cut_Step["os_eem"]["1"] ){                                                           Cut_Step["eem"]["1"]  = true; EventInfo[16]->Fill(3.5,1.0);}
    if(Cut_Step["ss_eem"]["2"]  || Cut_Step["os_eem"]["2"] ){                                                           Cut_Step["eem"]["2"]  = true; EventInfo[16]->Fill(4.5,1.0);}
    if(Cut_Step["ss_eem"]["3"]  || Cut_Step["os_eem"]["3"] ){                                                           Cut_Step["eem"]["3"]  = true; EventInfo[16]->Fill(5.5,1.0);}
    if(Cut_Step["ss_eem"]["4"]  || Cut_Step["os_eem"]["4"] ){                                                           Cut_Step["eem"]["4"]  = true; EventInfo[16]->Fill(6.5,1.0);}
    if(Cut_Step["ss_eem"]["5"]  || Cut_Step["os_eem"]["5"] ){                                                           Cut_Step["eem"]["5"]  = true; EventInfo[16]->Fill(7.5,1.0);}
    if(Cut_Step["ss_eem"]["6a"] || Cut_Step["os_eem"]["6a"]){                                                           Cut_Step["eem"]["6a"] = true; EventInfo[16]->Fill(8.5,1.0);}
    if(Cut_Step["ss_eem"]["6b"] || Cut_Step["os_eem"]["6b"]){                                                           Cut_Step["eem"]["6b"] = true; EventInfo[16]->Fill(9.5,1.0);}
    if(Cut_Step["ss_eem"]["7"]  || Cut_Step["os_eem"]["7"] ){                                                           Cut_Step["eem"]["7"]  = true; EventInfo[16]->Fill(10.5,1.0);}
    if(Cut_Step["ss_eem"]["8"]  || Cut_Step["os_eem"]["8"] ){                                                           Cut_Step["eem"]["8"]  = true; EventInfo[16]->Fill(11.5,1.0);}
    if(Cut_Step["ss_eem"]["9"]  || Cut_Step["os_eem"]["9"] ){                                                           Cut_Step["eem"]["9"]  = true; EventInfo[16]->Fill(12.5,1.0);}
                                                               
    if(Cut_Step["ss_mm_e"]["0a"] || Cut_Step["ss_em_m"]["0a"]){                                                         Cut_Step["ss_emm"]["0a"] = true; EventInfo[17]->Fill(0.5,1.0);}
    if(Cut_Step["ss_mm_e"]["0b"] || Cut_Step["ss_em_m"]["0b"]){                                                         Cut_Step["ss_emm"]["0b"] = true; EventInfo[17]->Fill(1.5,1.0);}
    if(Cut_Step["ss_mm_e"]["0c"] || Cut_Step["ss_em_m"]["0c"]){                                                         Cut_Step["ss_emm"]["0c"] = true; EventInfo[17]->Fill(2.5,1.0);}
    if(Cut_Step["ss_mm_e"]["1"]  || Cut_Step["ss_em_m"]["1"] ){                                                         Cut_Step["ss_emm"]["1"]  = true; EventInfo[17]->Fill(3.5,1.0);}
    if(Cut_Step["ss_mm_e"]["2"]  || Cut_Step["ss_em_m"]["2"] ){                                                         Cut_Step["ss_emm"]["2"]  = true; EventInfo[17]->Fill(4.5,1.0);}
    if(Cut_Step["ss_mm_e"]["3"]  || Cut_Step["ss_em_m"]["3"] ){                                                         Cut_Step["ss_emm"]["3"]  = true; EventInfo[17]->Fill(5.5,1.0);}
    if(Cut_Step["ss_mm_e"]["4"]  || Cut_Step["ss_em_m"]["4"] ){                                                         Cut_Step["ss_emm"]["4"]  = true; EventInfo[17]->Fill(6.5,1.0);}
    if(Cut_Step["ss_mm_e"]["5"]  || Cut_Step["ss_em_m"]["5"] ){                                                         Cut_Step["ss_emm"]["5"]  = true; EventInfo[17]->Fill(7.5,1.0);}
    if(Cut_Step["ss_mm_e"]["6a"] || Cut_Step["ss_em_m"]["6a"]){                                                         Cut_Step["ss_emm"]["6a"] = true; EventInfo[17]->Fill(8.5,1.0);}
    if(Cut_Step["ss_mm_e"]["6b"] || Cut_Step["ss_em_m"]["6b"]){                                                         Cut_Step["ss_emm"]["6b"] = true; EventInfo[17]->Fill(9.5,1.0);}
    if(Cut_Step["ss_mm_e"]["7"]  || Cut_Step["ss_em_m"]["7"] ){                                                         Cut_Step["ss_emm"]["7"]  = true; EventInfo[17]->Fill(10.5,1.0);}
    if(Cut_Step["ss_mm_e"]["8"]  || Cut_Step["ss_em_m"]["8"] ){                                                         Cut_Step["ss_emm"]["8"]  = true; EventInfo[17]->Fill(11.5,1.0);}
    if(Cut_Step["ss_mm_e"]["9"]  || Cut_Step["ss_em_m"]["9"] ){                                                         Cut_Step["ss_emm"]["9"]  = true; EventInfo[17]->Fill(12.5,1.0);}
                                                               
    if(Cut_Step["os_mm_e"]["0a"] || Cut_Step["os_em_m"]["0a"]){                                                         Cut_Step["os_emm"]["0a"] = true; EventInfo[18]->Fill(0.5,1.0);}
    if(Cut_Step["os_mm_e"]["0b"] || Cut_Step["os_em_m"]["0b"]){                                                         Cut_Step["os_emm"]["0b"] = true; EventInfo[18]->Fill(1.5,1.0);}
    if(Cut_Step["os_mm_e"]["0c"] || Cut_Step["os_em_m"]["0c"]){                                                         Cut_Step["os_emm"]["0c"] = true; EventInfo[18]->Fill(2.5,1.0);}
    if(Cut_Step["os_mm_e"]["1"]  || Cut_Step["os_em_m"]["1"] ){                                                         Cut_Step["os_emm"]["1"]  = true; EventInfo[18]->Fill(3.5,1.0);}
    if(Cut_Step["os_mm_e"]["2"]  || Cut_Step["os_em_m"]["2"] ){                                                         Cut_Step["os_emm"]["2"]  = true; EventInfo[18]->Fill(4.5,1.0);}
    if(Cut_Step["os_mm_e"]["3"]  || Cut_Step["os_em_m"]["3"] ){                                                         Cut_Step["os_emm"]["3"]  = true; EventInfo[18]->Fill(5.5,1.0);}
    if(Cut_Step["os_mm_e"]["4"]  || Cut_Step["os_em_m"]["4"] ){                                                         Cut_Step["os_emm"]["4"]  = true; EventInfo[18]->Fill(6.5,1.0);}
    if(Cut_Step["os_mm_e"]["5"]  || Cut_Step["os_em_m"]["5"] ){                                                         Cut_Step["os_emm"]["5"]  = true; EventInfo[18]->Fill(7.5,1.0);}
    if(Cut_Step["os_mm_e"]["6a"] || Cut_Step["os_em_m"]["6a"]){                                                         Cut_Step["os_emm"]["6a"] = true; EventInfo[18]->Fill(8.5,1.0);}
    if(Cut_Step["os_mm_e"]["6b"] || Cut_Step["os_em_m"]["6b"]){                                                         Cut_Step["os_emm"]["6b"] = true; EventInfo[18]->Fill(9.5,1.0);}
    if(Cut_Step["os_mm_e"]["7"]  || Cut_Step["os_em_m"]["7"] ){                                                         Cut_Step["os_emm"]["7"]  = true; EventInfo[18]->Fill(10.5,1.0);}
    if(Cut_Step["os_mm_e"]["8"]  || Cut_Step["os_em_m"]["8"] ){                                                         Cut_Step["os_emm"]["8"]  = true; EventInfo[18]->Fill(11.5,1.0);}
    if(Cut_Step["os_mm_e"]["9"]  || Cut_Step["os_em_m"]["9"] ){                                                         Cut_Step["os_emm"]["9"]  = true; EventInfo[18]->Fill(12.5,1.0);}
                                                             
    if(Cut_Step["ss_emm"]["0a"] || Cut_Step["os_emm"]["0a"]){                                                           Cut_Step["emm"]["0a"] = true; EventInfo[19]->Fill(0.5,1.0);}
    if(Cut_Step["ss_emm"]["0b"] || Cut_Step["os_emm"]["0b"]){                                                           Cut_Step["emm"]["0b"] = true; EventInfo[19]->Fill(1.5,1.0);}
    if(Cut_Step["ss_emm"]["0c"] || Cut_Step["os_emm"]["0c"]){                                                           Cut_Step["emm"]["0c"] = true; EventInfo[19]->Fill(2.5,1.0);}
    if(Cut_Step["ss_emm"]["1"]  || Cut_Step["os_emm"]["1"] ){                                                           Cut_Step["emm"]["1"]  = true; EventInfo[19]->Fill(3.5,1.0);}
    if(Cut_Step["ss_emm"]["2"]  || Cut_Step["os_emm"]["2"] ){                                                           Cut_Step["emm"]["2"]  = true; EventInfo[19]->Fill(4.5,1.0);}
    if(Cut_Step["ss_emm"]["3"]  || Cut_Step["os_emm"]["3"] ){                                                           Cut_Step["emm"]["3"]  = true; EventInfo[19]->Fill(5.5,1.0);}
    if(Cut_Step["ss_emm"]["4"]  || Cut_Step["os_emm"]["4"] ){                                                           Cut_Step["emm"]["4"]  = true; EventInfo[19]->Fill(6.5,1.0);}
    if(Cut_Step["ss_emm"]["5"]  || Cut_Step["os_emm"]["5"] ){                                                           Cut_Step["emm"]["5"]  = true; EventInfo[19]->Fill(7.5,1.0);}
    if(Cut_Step["ss_emm"]["6a"] || Cut_Step["os_emm"]["6a"]){                                                           Cut_Step["emm"]["6a"] = true; EventInfo[19]->Fill(8.5,1.0);}
    if(Cut_Step["ss_emm"]["6b"] || Cut_Step["os_emm"]["6b"]){                                                           Cut_Step["emm"]["6b"] = true; EventInfo[19]->Fill(9.5,1.0);}
    if(Cut_Step["ss_emm"]["7"]  || Cut_Step["os_emm"]["7"] ){                                                           Cut_Step["emm"]["7"]  = true; EventInfo[19]->Fill(10.5,1.0);}
    if(Cut_Step["ss_emm"]["8"]  || Cut_Step["os_emm"]["8"] ){                                                           Cut_Step["emm"]["8"]  = true; EventInfo[19]->Fill(11.5,1.0);}
    if(Cut_Step["ss_emm"]["9"]  || Cut_Step["os_emm"]["9"] ){                                                           Cut_Step["emm"]["9"]  = true; EventInfo[19]->Fill(12.5,1.0);}

    } // if(Channel == "FourTop Tri-Lepton"){
    else if(Channel == "TTbar Di-Lepton"){

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

    else if(Channel == "FourTop SS Di-Lepton"){

                                                                      Cut_Step["ee"]["0a"] = true; EventInfo[0]->Fill(0.5,1.0);
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                        Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                     Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && Cut_ee_LeptonPair && Cut_dl_Same && Cut_ee_TL){     Cut_Step["ee"]["1a"] = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["1a"] && Cut_e_Charge){                         Cut_Step["ee"]["1b"] = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Cut_e_ElectronVeto && Cut_e_MuonVeto){ Cut_Step["ee"]["2"]  = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["ee"]["3"]  = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["3"]  && Index_Cut_BJet >= 2){                  Cut_Step["ee"]["4"]  = true; EventInfo[0]->Fill(7.5,1.0);}
    if(Cut_Step["ee"]["4"]  && HT>500){                               Cut_Step["ee"]["5"]  = true; EventInfo[0]->Fill(8.5,1.0);}

                                                                      Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                        Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                     Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && Cut_mm_LeptonPair && Cut_dl_Same && Cut_mm_TL){     Cut_Step["mm"]["1a"] = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["1a"] && Cut_m_Charge){                         Cut_Step["mm"]["1b"] = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Cut_m_ElectronVeto && Cut_m_MuonVeto){ Cut_Step["mm"]["2"]  = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["2"]  && Index_Cut_Jet >= 4){                   Cut_Step["mm"]["3"]  = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["mm"]["3"]  && Index_Cut_BJet >= 2){                  Cut_Step["mm"]["4"]  = true; EventInfo[1]->Fill(7.5,1.0);}
    if(Cut_Step["mm"]["4"]  && HT>500){                               Cut_Step["mm"]["5"]  = true; EventInfo[1]->Fill(8.5,1.0);}

                                                                      Cut_Step["em"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["em"]["0a"] && Cut_em_Trigger){                       Cut_Step["em"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["em"]["0b"] && Cut_Event_Filter){                     Cut_Step["em"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["em"]["0c"] && Cut_em_LeptonPair && Cut_dl_Same && Cut_em_TL){     Cut_Step["em"]["1a"] = true; EventInfo[2]->Fill(3.5,1.0);}
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

    } // if(Channel == "FourTop SS Di-Lepton"){

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
    if(Cut_Step["ee"]["0a"] && Cut_e_Trigger){                        Cut_Step["ee"]["0b"] = true; EventInfo[0]->Fill(1.5,1.0);}
    if(Cut_Step["ee"]["0b"] && Cut_Event_Filter){                     Cut_Step["ee"]["0c"] = true; EventInfo[0]->Fill(2.5,1.0);}
    if(Cut_Step["ee"]["0c"] && Cut_Tri_ee){                           Cut_Step["ee"]["0d"] = true; EventInfo[0]->Fill(3.5,1.0);}
    if(Cut_Step["ee"]["0d"] && Cut_ee_LeptonPair && Cut_dl_Same && Cut_e_Charge){                                   Cut_Step["ee"]["1a"] = true; EventInfo[0]->Fill(4.5,1.0);}
    if(Cut_Step["ee"]["1a"] && Cut_MET && HT > 300){                                                                Cut_Step["ee"]["BL"] = true; EventInfo[0]->Fill(5.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SRW"] = true; EventInfo[0]->Fill(6.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SR1"] = true; EventInfo[0]->Fill(7.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SR2"] = true; EventInfo[0]->Fill(8.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SR3"] = true; EventInfo[0]->Fill(9.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){ Cut_Step["ee"]["SR4"] = true; EventInfo[0]->Fill(10.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SR5"] = true; EventInfo[0]->Fill(11.5,1.0);}
    if(Cut_Step["ee"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                         Cut_Step["ee"]["SR6"] = true; EventInfo[0]->Fill(12.5,1.0);}
    if(Cut_Step["ee"]["0d"] && Cut_Tri_ee && Num_IsolatedElectron + Num_IsolatedMuon == 3 && Cut_Tri_add_Charge){                            Cut_Step["ee"]["1b"] = true; EventInfo[0]->Fill(13.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["ee"]["SR7"] = true; EventInfo[0]->Fill(14.5,1.0);}
    if(Cut_Step["ee"]["1b"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["ee"]["SR8"] = true; EventInfo[0]->Fill(15.5,1.0);}
    if((Cut_Step["ee"]["1a"] && Cut_SUSY_SRZ) || (Cut_Step["ee"]["1b"] && (!Cut_Tri_First_Zmass || !Cut_Tri_Second_Zmass || Cut_SUSY_SRZ))){ Cut_Step["ee"]["SRZ"] = true; EventInfo[0]->Fill(16.5,1.0);}

                                                                      Cut_Step["mm"]["0a"] = true; EventInfo[1]->Fill(0.5,1.0);
    if(Cut_Step["mm"]["0a"] && Cut_m_Trigger){                        Cut_Step["mm"]["0b"] = true; EventInfo[1]->Fill(1.5,1.0);}
    if(Cut_Step["mm"]["0b"] && Cut_Event_Filter){                     Cut_Step["mm"]["0c"] = true; EventInfo[1]->Fill(2.5,1.0);}
    if(Cut_Step["mm"]["0c"] && Cut_Tri_mm){                           Cut_Step["mm"]["0d"] = true; EventInfo[1]->Fill(3.5,1.0);}
    if(Cut_Step["mm"]["0d"] && Cut_mm_LeptonPair && Cut_dl_Same && Cut_m_Charge){                                   Cut_Step["mm"]["1a"] = true; EventInfo[1]->Fill(4.5,1.0);}
    if(Cut_Step["mm"]["1a"] && Cut_MET && HT > 300){                                                                Cut_Step["mm"]["BL"] = true; EventInfo[1]->Fill(5.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SRW"] = true; EventInfo[1]->Fill(6.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SR1"] = true; EventInfo[1]->Fill(7.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SR2"] = true; EventInfo[1]->Fill(8.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SR3"] = true; EventInfo[1]->Fill(9.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){ Cut_Step["mm"]["SR4"] = true; EventInfo[1]->Fill(10.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SR5"] = true; EventInfo[1]->Fill(11.5,1.0);}
    if(Cut_Step["mm"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                         Cut_Step["mm"]["SR6"] = true; EventInfo[1]->Fill(12.5,1.0);}
    if(Cut_Step["mm"]["0d"] && Cut_Tri_mm && Num_IsolatedElectron + Num_IsolatedMuon == 3 && Cut_Tri_add_Charge){                            Cut_Step["mm"]["1b"] = true; EventInfo[1]->Fill(13.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["mm"]["SR7"] = true; EventInfo[1]->Fill(14.5,1.0);}
    if(Cut_Step["mm"]["1b"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["mm"]["SR8"] = true; EventInfo[1]->Fill(15.5,1.0);}
    if((Cut_Step["mm"]["1a"] && Cut_SUSY_SRZ) || (Cut_Step["mm"]["1b"] && (!Cut_Tri_First_Zmass || !Cut_Tri_Second_Zmass || Cut_SUSY_SRZ))){ Cut_Step["mm"]["SRZ"] = true; EventInfo[1]->Fill(16.5,1.0);}

                                                                      Cut_Step["em"]["0a"] = true; EventInfo[2]->Fill(0.5,1.0);
    if(Cut_Step["em"]["0a"] && Cut_em_Trigger){                       Cut_Step["em"]["0b"] = true; EventInfo[2]->Fill(1.5,1.0);}
    if(Cut_Step["em"]["0b"] && Cut_Event_Filter){                     Cut_Step["em"]["0c"] = true; EventInfo[2]->Fill(2.5,1.0);}
    if(Cut_Step["em"]["0c"] && Cut_Tri_em){                           Cut_Step["em"]["0d"] = true; EventInfo[2]->Fill(3.5,1.0);}
    if(Cut_Step["em"]["0d"] && Cut_em_LeptonPair && Cut_dl_Same && Cut_e_Charge && Cut_m_Charge){                   Cut_Step["em"]["1a"] = true; EventInfo[2]->Fill(4.5,1.0);}
    if(Cut_Step["em"]["1a"] && Cut_MET && HT > 300){                                                                Cut_Step["em"]["BL"] = true; EventInfo[2]->Fill(5.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet <= 5 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SRW"] = true; EventInfo[2]->Fill(6.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 6 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SR1"] = true; EventInfo[2]->Fill(7.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet == 7 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SR2"] = true; EventInfo[2]->Fill(8.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 8 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SR3"] = true; EventInfo[2]->Fill(9.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 3 && (Index_Cut_Jet == 5 || Index_Cut_Jet == 6) && !Cut_SUSY_SRZ){ Cut_Step["em"]["SR4"] = true; EventInfo[2]->Fill(10.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet == 3 && Index_Cut_Jet >= 7 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SR5"] = true; EventInfo[2]->Fill(11.5,1.0);}
    if(Cut_Step["em"]["BL"] && Index_Cut_BJet >= 4 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ){                         Cut_Step["em"]["SR6"] = true; EventInfo[2]->Fill(12.5,1.0);}
    if(Cut_Step["em"]["0d"] && Cut_Tri_em && Num_IsolatedElectron + Num_IsolatedMuon == 3 && Cut_Tri_add_Charge){                            Cut_Step["em"]["1b"] = true; EventInfo[2]->Fill(13.5,1.0);}
    if(Cut_Step["em"]["1b"] && Index_Cut_BJet == 2 && Index_Cut_Jet >= 5 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["em"]["SR7"] = true; EventInfo[2]->Fill(14.5,1.0);}
    if(Cut_Step["em"]["1b"] && Index_Cut_BJet >= 3 && Index_Cut_Jet >= 4 && !Cut_SUSY_SRZ && Cut_Tri_First_Zmass && Cut_Tri_Second_Zmass){   Cut_Step["em"]["SR8"] = true; EventInfo[2]->Fill(15.5,1.0);}
    if((Cut_Step["em"]["1a"] && Cut_SUSY_SRZ) || (Cut_Step["em"]["1b"] && (!Cut_Tri_First_Zmass || !Cut_Tri_Second_Zmass || Cut_SUSY_SRZ))){ Cut_Step["em"]["SRZ"] = true; EventInfo[2]->Fill(16.5,1.0);}

    ssbtreeManager->Fill( "Cut_ee_Step0a", Cut_Step["ee"]["0a"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0b", Cut_Step["ee"]["0b"]  );
    ssbtreeManager->Fill( "Cut_ee_Step0c", Cut_Step["ee"]["0c"]  );
    ssbtreeManager->Fill( "Cut_ee_Step1a", Cut_Step["ee"]["1a"]  );
    ssbtreeManager->Fill( "Cut_ee_BaseLine",     Cut_Step["ee"]["BL"]  );
    ssbtreeManager->Fill( "Cut_ee_SRW",    Cut_Step["ee"]["SRW"] );
    ssbtreeManager->Fill( "Cut_ee_SR1",    Cut_Step["ee"]["SR1"] );
    ssbtreeManager->Fill( "Cut_ee_SR2",    Cut_Step["ee"]["SR2"] );
    ssbtreeManager->Fill( "Cut_ee_SR3",    Cut_Step["ee"]["SR3"] );
    ssbtreeManager->Fill( "Cut_ee_SR4",    Cut_Step["ee"]["SR4"] );
    ssbtreeManager->Fill( "Cut_ee_SR5",    Cut_Step["ee"]["SR5"] );
    ssbtreeManager->Fill( "Cut_ee_SR6",    Cut_Step["ee"]["SR6"] );
    ssbtreeManager->Fill( "Cut_ee_Step1b", Cut_Step["ee"]["1b"]  );
    ssbtreeManager->Fill( "Cut_ee_SR7",    Cut_Step["ee"]["SR7"] );
    ssbtreeManager->Fill( "Cut_ee_SR8",    Cut_Step["ee"]["SR8"] );
    ssbtreeManager->Fill( "Cut_ee_SRZ",    Cut_Step["ee"]["SRZ"] );

    ssbtreeManager->Fill( "Cut_mm_Step0a", Cut_Step["mm"]["0a"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0b", Cut_Step["mm"]["0b"]  );
    ssbtreeManager->Fill( "Cut_mm_Step0c", Cut_Step["mm"]["0c"]  );
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
    ssbtreeManager->Fill( "Cut_mm_SR7",    Cut_Step["mm"]["SR7"] );
    ssbtreeManager->Fill( "Cut_mm_SR8",    Cut_Step["mm"]["SR8"] );
    ssbtreeManager->Fill( "Cut_mm_SRZ",    Cut_Step["mm"]["SRZ"] );

    ssbtreeManager->Fill( "Cut_em_Step0a", Cut_Step["em"]["0a"]  );
    ssbtreeManager->Fill( "Cut_em_Step0b", Cut_Step["em"]["0b"]  );
    ssbtreeManager->Fill( "Cut_em_Step0c", Cut_Step["em"]["0c"]  );
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
    ssbtreeManager->Fill( "Cut_em_SR7",    Cut_Step["em"]["SR7"] );
    ssbtreeManager->Fill( "Cut_em_SR8",    Cut_Step["em"]["SR8"] );
    ssbtreeManager->Fill( "Cut_em_SRZ",    Cut_Step["em"]["SRZ"] );

    } // if(Channel == "FourTop SUSY"){
}

