// SSBTMMaker v3.00

#include "SSBHistManager.h"

void SSBHistManager::GetCutStep(std::string input_Channel, std::map<std::string,bool> input_CutStep){
    for(unsigned int i_CutStep=0;i_CutStep<CutStepName.size();++i_CutStep){
        AllCut[input_Channel+"_"+CutStepName[i_CutStep]] = input_CutStep[CutStepName[i_CutStep]];
    }
}

void SSBHistManager::SetWeight(std::string input_Channel, std::string input_Cutstep, double Weight){
    AllWeight[input_Channel+"_"+input_Cutstep] = Weight;
}

void SSBHistManager::CheckData(bool isData){
    DataCheck = isData;
}

void SSBHistManager::Fill(std::string VariableName, bool VariableBool, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableBool, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox[HistName] )->Fill(VariableBool, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_Bool Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, int VariableInt, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableInt, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox[HistName] )->Fill(VariableInt, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_Int Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, unsigned int VariableUInt, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableUInt, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox[HistName] )->Fill(VariableUInt, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_UInt Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, float VariableFloat, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableFloat, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox[HistName] )->Fill(VariableFloat, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_Float Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, double VariableDouble, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableDouble, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox[HistName] )->Fill(VariableDouble, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_Double Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, int VariableIntX, int VariableIntY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableIntX, VariableIntY, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox2[HistName] )->Fill(VariableIntX, VariableIntY, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_2D_Int Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, unsigned int VariableUIntX, unsigned int VariableUIntY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableUIntX, VariableUIntY, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox2[HistName] )->Fill(VariableUIntX, VariableUIntY, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_2D_UInt Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, float VariableFloatX, float VariableFloatY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableFloatX, VariableFloatY, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox2[HistName] )->Fill(VariableFloatX, VariableFloatY, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_2D_Float Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, double VariableDoubleX, double VariableDoubleY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableDoubleX, VariableDoubleY, AllWeight[AllCutName[i_hist]]);
                } else {
                    ( HistBox2[HistName] )->Fill(VariableDoubleX, VariableDoubleY, Weight);
                }
            }
        }
        else {
            std::cout << "Hist_2D_Double Error : " << HistName << std::endl;
        }
    }
}

SSBHistManager::SSBHistManager(std::vector<std::string> Channel, std::vector<std::string> CutStep){

    ChannelName = Channel;
    CutStepName = CutStep;
    AllCutName.clear();
    AllCut.clear();
    AllWeight.clear();
    HistName = "";
    for(unsigned int CutChannelInit=0;CutChannelInit<ChannelName.size();++CutChannelInit){
        for(unsigned int CutStepInit=0;CutStepInit<CutStepName.size();++CutStepInit){
            HistName = ChannelName[CutChannelInit]+"_"+CutStepName[CutStepInit];
            AllCutName.push_back(HistName);
            AllCut[HistName] = false;
        }
    }
    

}

SSBHistManager::~SSBHistManager(){

}

void SSBHistManager::Book(TFileDirectory histdir){

    ssbhist = histdir;

}

void SSBHistManager::InitializeHist(){

    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistBox["numPV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("numPV_%s",AllCutName[i_hist].c_str()),Form("numPV_%s",AllCutName[i_hist].c_str()),100,0,100);
        HistBox["numPV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["MET_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("MET_%s",AllCutName[i_hist].c_str()),Form("MET_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["MET_"+AllCutName[i_hist]]->Sumw2();
        HistBox["HT_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("HT_%s",AllCutName[i_hist].c_str()),Form("HT_%s",AllCutName[i_hist].c_str()),3000,0,3000);
        HistBox["HT_"+AllCutName[i_hist]]->Sumw2();
        HistBox["HM_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("HM_%s",AllCutName[i_hist].c_str()),Form("HM_%s",AllCutName[i_hist].c_str()),5000,0,5000);
        HistBox["HM_"+AllCutName[i_hist]]->Sumw2();
        HistBox["numJets_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("numJets_%s",AllCutName[i_hist].c_str()),Form("numJets_%s",AllCutName[i_hist].c_str()),20,0,20);
        HistBox["numJets_"+AllCutName[i_hist]]->Sumw2();
        HistBox["numBJets_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("numBJets_%s",AllCutName[i_hist].c_str()),Form("numBJets_%s",AllCutName[i_hist].c_str()),10,0,10);
        HistBox["numBJets_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AllLepton_InvMass_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AllLepton_InvMass_%s",AllCutName[i_hist].c_str()),Form("AllLepton_InvMass_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["AllLepton_InvMass_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_Pt_%s",AllCutName[i_hist].c_str()),Form("Jet_1_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_Eta_%s",AllCutName[i_hist].c_str()),Form("Jet_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Jet_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_Phi_%s",AllCutName[i_hist].c_str()),Form("Jet_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Jet_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_E_%s",AllCutName[i_hist].c_str()),Form("Jet_1_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_CSV_%s",AllCutName[i_hist].c_str()),Form("Jet_1_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_1_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_1_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_1_qg_%s",AllCutName[i_hist].c_str()),Form("Jet_1_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_1_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_Pt_%s",AllCutName[i_hist].c_str()),Form("Jet_2_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_2_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_Eta_%s",AllCutName[i_hist].c_str()),Form("Jet_2_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Jet_2_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_Phi_%s",AllCutName[i_hist].c_str()),Form("Jet_2_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Jet_2_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_E_%s",AllCutName[i_hist].c_str()),Form("Jet_2_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_2_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_CSV_%s",AllCutName[i_hist].c_str()),Form("Jet_2_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_2_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_2_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_2_qg_%s",AllCutName[i_hist].c_str()),Form("Jet_2_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_2_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_Pt_%s",AllCutName[i_hist].c_str()),Form("Jet_3_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_3_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_Eta_%s",AllCutName[i_hist].c_str()),Form("Jet_3_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Jet_3_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_Phi_%s",AllCutName[i_hist].c_str()),Form("Jet_3_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Jet_3_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_E_%s",AllCutName[i_hist].c_str()),Form("Jet_3_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_3_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_CSV_%s",AllCutName[i_hist].c_str()),Form("Jet_3_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_3_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_3_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_3_qg_%s",AllCutName[i_hist].c_str()),Form("Jet_3_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_3_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_Pt_%s",AllCutName[i_hist].c_str()),Form("Jet_4_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_4_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_Eta_%s",AllCutName[i_hist].c_str()),Form("Jet_4_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Jet_4_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_Phi_%s",AllCutName[i_hist].c_str()),Form("Jet_4_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Jet_4_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_E_%s",AllCutName[i_hist].c_str()),Form("Jet_4_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["Jet_4_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_CSV_%s",AllCutName[i_hist].c_str()),Form("Jet_4_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_4_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Jet_4_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Jet_4_qg_%s",AllCutName[i_hist].c_str()),Form("Jet_4_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["Jet_4_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_Pt_%s",AllCutName[i_hist].c_str()),Form("BJet_1_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_Eta_%s",AllCutName[i_hist].c_str()),Form("BJet_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["BJet_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_Phi_%s",AllCutName[i_hist].c_str()),Form("BJet_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["BJet_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_E_%s",AllCutName[i_hist].c_str()),Form("BJet_1_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_CSV_%s",AllCutName[i_hist].c_str()),Form("BJet_1_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_1_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_1_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_1_qg_%s",AllCutName[i_hist].c_str()),Form("BJet_1_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_1_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_Pt_%s",AllCutName[i_hist].c_str()),Form("BJet_2_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_2_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_Eta_%s",AllCutName[i_hist].c_str()),Form("BJet_2_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["BJet_2_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_Phi_%s",AllCutName[i_hist].c_str()),Form("BJet_2_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["BJet_2_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_E_%s",AllCutName[i_hist].c_str()),Form("BJet_2_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_2_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_CSV_%s",AllCutName[i_hist].c_str()),Form("BJet_2_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_2_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_2_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_2_qg_%s",AllCutName[i_hist].c_str()),Form("BJet_2_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_2_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_Pt_%s",AllCutName[i_hist].c_str()),Form("BJet_3_Pt_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_3_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_Eta_%s",AllCutName[i_hist].c_str()),Form("BJet_3_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["BJet_3_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_Phi_%s",AllCutName[i_hist].c_str()),Form("BJet_3_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["BJet_3_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_E_%s",AllCutName[i_hist].c_str()),Form("BJet_3_E_%s",AllCutName[i_hist].c_str()),2000,0,2000);
        HistBox["BJet_3_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_CSV_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_CSV_%s",AllCutName[i_hist].c_str()),Form("BJet_3_CSV_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_3_CSV_"+AllCutName[i_hist]]->Sumw2();
        HistBox["BJet_3_qg_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("BJet_3_qg_%s",AllCutName[i_hist].c_str()),Form("BJet_3_qg_%s",AllCutName[i_hist].c_str()),200,-1,1);
        HistBox["BJet_3_qg_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Pt_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Eta_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Elec_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Phi_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Elec_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_E_%s",AllCutName[i_hist].c_str()),Form("Elec_1_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Iso03_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_1_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Iso04_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_1_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_miniIso_%s",AllCutName[i_hist].c_str()),Form("Elec_1_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_1_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Elec_1_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_1_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Elec_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Elec_1_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Pt_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_2_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Eta_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Elec_2_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Phi_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Elec_2_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_E_%s",AllCutName[i_hist].c_str()),Form("Elec_2_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_2_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Iso03_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_2_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Iso04_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_2_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_miniIso_%s",AllCutName[i_hist].c_str()),Form("Elec_2_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_2_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Elec_2_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_2_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_2_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Elec_2_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Elec_2_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Pt_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Eta_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Muon_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Phi_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Muon_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_E_%s",AllCutName[i_hist].c_str()),Form("Muon_1_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Iso03_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_1_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Iso04_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_1_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_miniIso_%s",AllCutName[i_hist].c_str()),Form("Muon_1_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_1_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Muon_1_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_1_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Muon_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Muon_1_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Pt_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_2_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Eta_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Muon_2_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Phi_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Muon_2_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_E_%s",AllCutName[i_hist].c_str()),Form("Muon_2_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_2_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Iso03_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_2_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Iso04_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_2_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_miniIso_%s",AllCutName[i_hist].c_str()),Form("Muon_2_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_2_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Muon_2_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_2_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_2_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Muon_2_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Muon_2_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Pt_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_3_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Eta_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Elec_3_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Phi_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Elec_3_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_E_%s",AllCutName[i_hist].c_str()),Form("Elec_3_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Elec_3_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Iso03_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_3_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Iso04_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_3_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_miniIso_%s",AllCutName[i_hist].c_str()),Form("Elec_3_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Elec_3_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Elec_3_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Elec_3_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Elec_3_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Elec_3_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Elec_3_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Pt_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_3_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Eta_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["Muon_3_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Phi_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["Muon_3_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_E_%s",AllCutName[i_hist].c_str()),Form("Muon_3_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["Muon_3_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Iso03_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_3_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Iso04_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_3_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_miniIso_%s",AllCutName[i_hist].c_str()),Form("Muon_3_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["Muon_3_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["Muon_3_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["Muon_3_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("Muon_3_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("Muon_3_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["Muon_3_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Pt_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["AddElec_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Eta_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["AddElec_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Phi_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["AddElec_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_E_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["AddElec_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Iso03_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddElec_1_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Iso04_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddElec_1_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_miniIso_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddElec_1_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["AddElec_1_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddElec_1_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddElec_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("AddElec_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["AddElec_1_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Pt_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Pt_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Pt_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["AddMuon_1_Pt_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Eta_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Eta_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Eta_%s",AllCutName[i_hist].c_str()),1000,-5,5);
        HistBox["AddMuon_1_Eta_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Phi_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Phi_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Phi_%s",AllCutName[i_hist].c_str()),1000,-3.14,3.14);
        HistBox["AddMuon_1_Phi_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_E_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_E_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_E_%s",AllCutName[i_hist].c_str()),1000,0,1000);
        HistBox["AddMuon_1_E_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Iso03_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Iso03_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Iso03_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddMuon_1_Iso03_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Iso04_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Iso04_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Iso04_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddMuon_1_Iso04_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_miniIso_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_miniIso_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_miniIso_%s",AllCutName[i_hist].c_str()),100,0,0.2);
        HistBox["AddMuon_1_miniIso_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Pt_rel_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Pt_rel_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Pt_rel_%s",AllCutName[i_hist].c_str()),200,0,20);
        HistBox["AddMuon_1_Pt_rel_"+AllCutName[i_hist]]->Sumw2();
        HistBox["AddMuon_1_Pt_ratio_"+AllCutName[i_hist]] = ssbhist.make<TH1D>(Form("AddMuon_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),Form("AddMuon_1_Pt_ratio_%s",AllCutName[i_hist].c_str()),150,0,1.5);
        HistBox["AddMuon_1_Pt_ratio_"+AllCutName[i_hist]]->Sumw2();

    }
}

