// SSBHMMaker v1.00

#include "SSBHistManager.h"

void SSBHistManager::FillHist(){
   ssbhist->Fill();
}

void SSBHistManager::GetCutStep(std::map<std::string,bool> Cut_ee, std::map<std::string,bool> Cut_mm, std::map<std::string,bool> Cut_em){
    AllCut.clear();
    for(unsigned int i_Channel=0;i_Channel<ChannelName.size();++i_Channel){
        for(unsigned int i_CutStep=0;i_CutStep<CutStepName.size();++i_CutStep){
            if(i_Channel==0) AllCut.push_back(Cut_ee[CutStepName[i_CutStep]]);
            if(i_Channel==1) AllCut.push_back(Cut_mm[CutStepName[i_CutStep]]);
            if(i_Channel==2) AllCut.push_back(Cut_em[CutStepName[i_CutStep]]);
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, bool VariableBool ){
    if ((it_HistBox = HistBox.find(VariableName.c_str())) != HistBox.end()){
        for(unsigned int i_hist=0;i_hist<AllCut.size();++i_hist){
            if(AllCut.at(i_hist)){ ( (TH1D*)HistBox[VariableName.c_str()]->At(i_hist) )->Fill(VariableBool); }
        }
    }
    else {
        std::cout << "Fill_Bool Error : " << VariableName << std::endl;
    }
}

void SSBHistManager::Fill(std::string VariableName, int VariableInt ){
    if ((it_HistBox = HistBox.find(VariableName.c_str())) != HistBox.end()){
        for(unsigned int i_hist=0;i_hist<AllCut.size();++i_hist){
            if(AllCut.at(i_hist)){ ( (TH1D*)HistBox[VariableName.c_str()]->At(i_hist) )->Fill(VariableInt); }
        }
    }
    else {
        std::cout << "Fill_Int Error : " << VariableName << std::endl;
    }
}

void SSBHistManager::Fill(std::string VariableName, unsigned int VariableUInt ){
    if ((it_HistBox = HistBox.find(VariableName.c_str())) != HistBox.end()){
        for(unsigned int i_hist=0;i_hist<AllCut.size();++i_hist){
            if(AllCut.at(i_hist)){ ( (TH1D*)HistBox[VariableName.c_str()]->At(i_hist) )->Fill(VariableUInt); }
        }
    }
    else {
        std::cout << "Fill_UInt Error : " << VariableName << std::endl;
    }
}

void SSBHistManager::Fill(std::string VariableName, float VariableFloat ){
    if ((it_HistBox = HistBox.find(VariableName.c_str())) != HistBox.end()){
        for(unsigned int i_hist=0;i_hist<AllCut.size();++i_hist){
            if(AllCut.at(i_hist)){ ( (TH1D*)HistBox[VariableName.c_str()]->At(i_hist) )->Fill(VariableFloat); }
        }
    }
    else {
        std::cout << "Fill_Float Error : " << VariableName << std::endl;
    }
}

void SSBHistManager::Fill(std::string VariableName, double VariableDouble ){
    if ((it_HistBox = HistBox.find(VariableName.c_str())) != HistBox.end()){
        for(unsigned int i_hist=0;i_hist<AllCut.size();++i_hist){
            if(AllCut.at(i_hist)){ ( (TH1D*)HistBox[VariableName.c_str()]->At(i_hist) )->Fill(VariableDouble); }
        }
    }
    else {
        std::cout << "Fill_Double Error : " << VariableName << std::endl;
    }
}

SSBHistManager::SSBHistManager(std::vector<std::string> CutStep){

    CutStepName = CutStep;
    HistBox["numPV"] = new TClonesArray("TH1D");
    HistBox["MET"] = new TClonesArray("TH1D");
    HistBox["HT"] = new TClonesArray("TH1D");
    HistBox["HM"] = new TClonesArray("TH1D");
    HistBox["numJets"] = new TClonesArray("TH1D");
    HistBox["numBJets"] = new TClonesArray("TH1D");
    HistBox["InvMass"] = new TClonesArray("TH1D");
    HistBox["Jet_1_Pt"] = new TClonesArray("TH1D");
    HistBox["Jet_1_Eta"] = new TClonesArray("TH1D");
    HistBox["Jet_1_Phi"] = new TClonesArray("TH1D");
    HistBox["Jet_1_E"] = new TClonesArray("TH1D");
    HistBox["Jet_1_CSV"] = new TClonesArray("TH1D");
    HistBox["Jet_2_Pt"] = new TClonesArray("TH1D");
    HistBox["Jet_2_Eta"] = new TClonesArray("TH1D");
    HistBox["Jet_2_Phi"] = new TClonesArray("TH1D");
    HistBox["Jet_2_E"] = new TClonesArray("TH1D");
    HistBox["Jet_2_CSV"] = new TClonesArray("TH1D");
    HistBox["Jet_3_Pt"] = new TClonesArray("TH1D");
    HistBox["Jet_3_Eta"] = new TClonesArray("TH1D");
    HistBox["Jet_3_Phi"] = new TClonesArray("TH1D");
    HistBox["Jet_3_E"] = new TClonesArray("TH1D");
    HistBox["Jet_3_CSV"] = new TClonesArray("TH1D");
    HistBox["Jet_4_Pt"] = new TClonesArray("TH1D");
    HistBox["Jet_4_Eta"] = new TClonesArray("TH1D");
    HistBox["Jet_4_Phi"] = new TClonesArray("TH1D");
    HistBox["Jet_4_E"] = new TClonesArray("TH1D");
    HistBox["Jet_4_CSV"] = new TClonesArray("TH1D");
    HistBox["BJet_1_Pt"] = new TClonesArray("TH1D");
    HistBox["BJet_1_Eta"] = new TClonesArray("TH1D");
    HistBox["BJet_1_Phi"] = new TClonesArray("TH1D");
    HistBox["BJet_1_E"] = new TClonesArray("TH1D");
    HistBox["BJet_1_CSV"] = new TClonesArray("TH1D");
    HistBox["BJet_2_Pt"] = new TClonesArray("TH1D");
    HistBox["BJet_2_Eta"] = new TClonesArray("TH1D");
    HistBox["BJet_2_Phi"] = new TClonesArray("TH1D");
    HistBox["BJet_2_E"] = new TClonesArray("TH1D");
    HistBox["BJet_2_CSV"] = new TClonesArray("TH1D");
    HistBox["Elec_1_Pt"] = new TClonesArray("TH1D");
    HistBox["Elec_1_Eta"] = new TClonesArray("TH1D");
    HistBox["Elec_1_Phi"] = new TClonesArray("TH1D");
    HistBox["Elec_1_E"] = new TClonesArray("TH1D");
    HistBox["Elec_2_Pt"] = new TClonesArray("TH1D");
    HistBox["Elec_2_Eta"] = new TClonesArray("TH1D");
    HistBox["Elec_2_Phi"] = new TClonesArray("TH1D");
    HistBox["Elec_2_E"] = new TClonesArray("TH1D");
    HistBox["Muon_1_Pt"] = new TClonesArray("TH1D");
    HistBox["Muon_1_Eta"] = new TClonesArray("TH1D");
    HistBox["Muon_1_Phi"] = new TClonesArray("TH1D");
    HistBox["Muon_1_E"] = new TClonesArray("TH1D");
    HistBox["Muon_2_Pt"] = new TClonesArray("TH1D");
    HistBox["Muon_2_Eta"] = new TClonesArray("TH1D");
    HistBox["Muon_2_Phi"] = new TClonesArray("TH1D");
    HistBox["Muon_2_E"] = new TClonesArray("TH1D");

}

SSBHistManager::~SSBHistManager(){


}

void SSBHistManager::Book(TTree* tree){

    ssbhist = tree;
    ssbhist->Branch("numPV", "TClonesArray", &HistBox["numPV"], 32000, 0);
    HistBox["numPV"]->BypassStreamer();
    ssbhist->Branch("MET", "TClonesArray", &HistBox["MET"], 32000, 0);
    HistBox["MET"]->BypassStreamer();
    ssbhist->Branch("HT", "TClonesArray", &HistBox["HT"], 32000, 0);
    HistBox["HT"]->BypassStreamer();
    ssbhist->Branch("HM", "TClonesArray", &HistBox["HM"], 32000, 0);
    HistBox["HM"]->BypassStreamer();
    ssbhist->Branch("numJets", "TClonesArray", &HistBox["numJets"], 32000, 0);
    HistBox["numJets"]->BypassStreamer();
    ssbhist->Branch("numBJets", "TClonesArray", &HistBox["numBJets"], 32000, 0);
    HistBox["numBJets"]->BypassStreamer();
    ssbhist->Branch("InvMass", "TClonesArray", &HistBox["InvMass"], 32000, 0);
    HistBox["InvMass"]->BypassStreamer();
    ssbhist->Branch("Jet_1_Pt", "TClonesArray", &HistBox["Jet_1_Pt"], 32000, 0);
    HistBox["Jet_1_Pt"]->BypassStreamer();
    ssbhist->Branch("Jet_1_Eta", "TClonesArray", &HistBox["Jet_1_Eta"], 32000, 0);
    HistBox["Jet_1_Eta"]->BypassStreamer();
    ssbhist->Branch("Jet_1_Phi", "TClonesArray", &HistBox["Jet_1_Phi"], 32000, 0);
    HistBox["Jet_1_Phi"]->BypassStreamer();
    ssbhist->Branch("Jet_1_E", "TClonesArray", &HistBox["Jet_1_E"], 32000, 0);
    HistBox["Jet_1_E"]->BypassStreamer();
    ssbhist->Branch("Jet_1_CSV", "TClonesArray", &HistBox["Jet_1_CSV"], 32000, 0);
    HistBox["Jet_1_CSV"]->BypassStreamer();
    ssbhist->Branch("Jet_2_Pt", "TClonesArray", &HistBox["Jet_2_Pt"], 32000, 0);
    HistBox["Jet_2_Pt"]->BypassStreamer();
    ssbhist->Branch("Jet_2_Eta", "TClonesArray", &HistBox["Jet_2_Eta"], 32000, 0);
    HistBox["Jet_2_Eta"]->BypassStreamer();
    ssbhist->Branch("Jet_2_Phi", "TClonesArray", &HistBox["Jet_2_Phi"], 32000, 0);
    HistBox["Jet_2_Phi"]->BypassStreamer();
    ssbhist->Branch("Jet_2_E", "TClonesArray", &HistBox["Jet_2_E"], 32000, 0);
    HistBox["Jet_2_E"]->BypassStreamer();
    ssbhist->Branch("Jet_2_CSV", "TClonesArray", &HistBox["Jet_2_CSV"], 32000, 0);
    HistBox["Jet_2_CSV"]->BypassStreamer();
    ssbhist->Branch("Jet_3_Pt", "TClonesArray", &HistBox["Jet_3_Pt"], 32000, 0);
    HistBox["Jet_3_Pt"]->BypassStreamer();
    ssbhist->Branch("Jet_3_Eta", "TClonesArray", &HistBox["Jet_3_Eta"], 32000, 0);
    HistBox["Jet_3_Eta"]->BypassStreamer();
    ssbhist->Branch("Jet_3_Phi", "TClonesArray", &HistBox["Jet_3_Phi"], 32000, 0);
    HistBox["Jet_3_Phi"]->BypassStreamer();
    ssbhist->Branch("Jet_3_E", "TClonesArray", &HistBox["Jet_3_E"], 32000, 0);
    HistBox["Jet_3_E"]->BypassStreamer();
    ssbhist->Branch("Jet_3_CSV", "TClonesArray", &HistBox["Jet_3_CSV"], 32000, 0);
    HistBox["Jet_3_CSV"]->BypassStreamer();
    ssbhist->Branch("Jet_4_Pt", "TClonesArray", &HistBox["Jet_4_Pt"], 32000, 0);
    HistBox["Jet_4_Pt"]->BypassStreamer();
    ssbhist->Branch("Jet_4_Eta", "TClonesArray", &HistBox["Jet_4_Eta"], 32000, 0);
    HistBox["Jet_4_Eta"]->BypassStreamer();
    ssbhist->Branch("Jet_4_Phi", "TClonesArray", &HistBox["Jet_4_Phi"], 32000, 0);
    HistBox["Jet_4_Phi"]->BypassStreamer();
    ssbhist->Branch("Jet_4_E", "TClonesArray", &HistBox["Jet_4_E"], 32000, 0);
    HistBox["Jet_4_E"]->BypassStreamer();
    ssbhist->Branch("Jet_4_CSV", "TClonesArray", &HistBox["Jet_4_CSV"], 32000, 0);
    HistBox["Jet_4_CSV"]->BypassStreamer();
    ssbhist->Branch("BJet_1_Pt", "TClonesArray", &HistBox["BJet_1_Pt"], 32000, 0);
    HistBox["BJet_1_Pt"]->BypassStreamer();
    ssbhist->Branch("BJet_1_Eta", "TClonesArray", &HistBox["BJet_1_Eta"], 32000, 0);
    HistBox["BJet_1_Eta"]->BypassStreamer();
    ssbhist->Branch("BJet_1_Phi", "TClonesArray", &HistBox["BJet_1_Phi"], 32000, 0);
    HistBox["BJet_1_Phi"]->BypassStreamer();
    ssbhist->Branch("BJet_1_E", "TClonesArray", &HistBox["BJet_1_E"], 32000, 0);
    HistBox["BJet_1_E"]->BypassStreamer();
    ssbhist->Branch("BJet_1_CSV", "TClonesArray", &HistBox["BJet_1_CSV"], 32000, 0);
    HistBox["BJet_1_CSV"]->BypassStreamer();
    ssbhist->Branch("BJet_2_Pt", "TClonesArray", &HistBox["BJet_2_Pt"], 32000, 0);
    HistBox["BJet_2_Pt"]->BypassStreamer();
    ssbhist->Branch("BJet_2_Eta", "TClonesArray", &HistBox["BJet_2_Eta"], 32000, 0);
    HistBox["BJet_2_Eta"]->BypassStreamer();
    ssbhist->Branch("BJet_2_Phi", "TClonesArray", &HistBox["BJet_2_Phi"], 32000, 0);
    HistBox["BJet_2_Phi"]->BypassStreamer();
    ssbhist->Branch("BJet_2_E", "TClonesArray", &HistBox["BJet_2_E"], 32000, 0);
    HistBox["BJet_2_E"]->BypassStreamer();
    ssbhist->Branch("BJet_2_CSV", "TClonesArray", &HistBox["BJet_2_CSV"], 32000, 0);
    HistBox["BJet_2_CSV"]->BypassStreamer();
    ssbhist->Branch("Elec_1_Pt", "TClonesArray", &HistBox["Elec_1_Pt"], 32000, 0);
    HistBox["Elec_1_Pt"]->BypassStreamer();
    ssbhist->Branch("Elec_1_Eta", "TClonesArray", &HistBox["Elec_1_Eta"], 32000, 0);
    HistBox["Elec_1_Eta"]->BypassStreamer();
    ssbhist->Branch("Elec_1_Phi", "TClonesArray", &HistBox["Elec_1_Phi"], 32000, 0);
    HistBox["Elec_1_Phi"]->BypassStreamer();
    ssbhist->Branch("Elec_1_E", "TClonesArray", &HistBox["Elec_1_E"], 32000, 0);
    HistBox["Elec_1_E"]->BypassStreamer();
    ssbhist->Branch("Elec_2_Pt", "TClonesArray", &HistBox["Elec_2_Pt"], 32000, 0);
    HistBox["Elec_2_Pt"]->BypassStreamer();
    ssbhist->Branch("Elec_2_Eta", "TClonesArray", &HistBox["Elec_2_Eta"], 32000, 0);
    HistBox["Elec_2_Eta"]->BypassStreamer();
    ssbhist->Branch("Elec_2_Phi", "TClonesArray", &HistBox["Elec_2_Phi"], 32000, 0);
    HistBox["Elec_2_Phi"]->BypassStreamer();
    ssbhist->Branch("Elec_2_E", "TClonesArray", &HistBox["Elec_2_E"], 32000, 0);
    HistBox["Elec_2_E"]->BypassStreamer();
    ssbhist->Branch("Muon_1_Pt", "TClonesArray", &HistBox["Muon_1_Pt"], 32000, 0);
    HistBox["Muon_1_Pt"]->BypassStreamer();
    ssbhist->Branch("Muon_1_Eta", "TClonesArray", &HistBox["Muon_1_Eta"], 32000, 0);
    HistBox["Muon_1_Eta"]->BypassStreamer();
    ssbhist->Branch("Muon_1_Phi", "TClonesArray", &HistBox["Muon_1_Phi"], 32000, 0);
    HistBox["Muon_1_Phi"]->BypassStreamer();
    ssbhist->Branch("Muon_1_E", "TClonesArray", &HistBox["Muon_1_E"], 32000, 0);
    HistBox["Muon_1_E"]->BypassStreamer();
    ssbhist->Branch("Muon_2_Pt", "TClonesArray", &HistBox["Muon_2_Pt"], 32000, 0);
    HistBox["Muon_2_Pt"]->BypassStreamer();
    ssbhist->Branch("Muon_2_Eta", "TClonesArray", &HistBox["Muon_2_Eta"], 32000, 0);
    HistBox["Muon_2_Eta"]->BypassStreamer();
    ssbhist->Branch("Muon_2_Phi", "TClonesArray", &HistBox["Muon_2_Phi"], 32000, 0);
    HistBox["Muon_2_Phi"]->BypassStreamer();
    ssbhist->Branch("Muon_2_E", "TClonesArray", &HistBox["Muon_2_E"], 32000, 0);
    HistBox["Muon_2_E"]->BypassStreamer();

}

void SSBHistManager::InitializeHist(){

    for(unsigned int i_Channel=0;i_Channel<ChannelName.size();++i_Channel){
        for(unsigned int i_CutStep=0;i_CutStep<CutStepName.size();++i_CutStep){
            new ((*HistBox["numPV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"numPV",100,0,100);
            new ((*HistBox["MET"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"MET",1000,0,1000);
            new ((*HistBox["HT"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"HT",3000,0,3000);
            new ((*HistBox["HM"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"HM",5000,0,5000);
            new ((*HistBox["numJets"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"numJets",30,0,30);
            new ((*HistBox["numBJets"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"numBJets",30,0,30);
            new ((*HistBox["InvMass"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"InvMass",1000,0,1000);
            new ((*HistBox["Jet_1_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_1_Pt",2000,0,2000);
            new ((*HistBox["Jet_1_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_1_Eta",1000,-5,5);
            new ((*HistBox["Jet_1_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_1_Phi",628,-3.14,3.14);
            new ((*HistBox["Jet_1_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_1_E",2000,0,2000);
            new ((*HistBox["Jet_1_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_1_CSV",200,-1,1);
            new ((*HistBox["Jet_2_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_2_Pt",2000,0,2000);
            new ((*HistBox["Jet_2_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_2_Eta",1000,-5,5);
            new ((*HistBox["Jet_2_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_2_Phi",628,-3.14,3.14);
            new ((*HistBox["Jet_2_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_2_E",2000,0,2000);
            new ((*HistBox["Jet_2_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_2_CSV",200,-1,1);
            new ((*HistBox["Jet_3_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_3_Pt",2000,0,2000);
            new ((*HistBox["Jet_3_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_3_Eta",1000,-5,5);
            new ((*HistBox["Jet_3_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_3_Phi",628,-3.14,3.14);
            new ((*HistBox["Jet_3_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_3_E",2000,0,2000);
            new ((*HistBox["Jet_3_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_3_CSV",200,-1,1);
            new ((*HistBox["Jet_4_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_4_Pt",2000,0,2000);
            new ((*HistBox["Jet_4_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_4_Eta",1000,-5,5);
            new ((*HistBox["Jet_4_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_4_Phi",628,-3.14,3.14);
            new ((*HistBox["Jet_4_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_4_E",2000,0,2000);
            new ((*HistBox["Jet_4_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Jet_4_CSV",200,-1,1);
            new ((*HistBox["BJet_1_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_1_Pt",2000,0,2000);
            new ((*HistBox["BJet_1_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_1_Eta",1000,-5,5);
            new ((*HistBox["BJet_1_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_1_Phi",628,-3.14,3.14);
            new ((*HistBox["BJet_1_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_1_E",2000,0,2000);
            new ((*HistBox["BJet_1_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_1_CSV",200,-1,1);
            new ((*HistBox["BJet_2_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_2_Pt",2000,0,2000);
            new ((*HistBox["BJet_2_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_2_Eta",1000,-5,5);
            new ((*HistBox["BJet_2_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_2_Phi",628,-3.14,3.14);
            new ((*HistBox["BJet_2_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_2_E",2000,0,2000);
            new ((*HistBox["BJet_2_CSV"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"BJet_2_CSV",200,-1,1);
            new ((*HistBox["Elec_1_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_1_Pt",1000,0,1000);
            new ((*HistBox["Elec_1_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_1_Eta",1000,-5,5);
            new ((*HistBox["Elec_1_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_1_Phi",628,-3.14,3.14);
            new ((*HistBox["Elec_1_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_1_E",1000,0,1000);
            new ((*HistBox["Elec_2_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_2_Pt",1000,0,1000);
            new ((*HistBox["Elec_2_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_2_Eta",1000,-5,5);
            new ((*HistBox["Elec_2_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_2_Phi",628,-3.14,3.14);
            new ((*HistBox["Elec_2_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Elec_2_E",1000,0,1000);
            new ((*HistBox["Muon_1_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_1_Pt",1000,0,1000);
            new ((*HistBox["Muon_1_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_1_Eta",1000,-5,5);
            new ((*HistBox["Muon_1_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_1_Phi",628,-3.14,3.14);
            new ((*HistBox["Muon_1_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_1_E",1000,0,1000);
            new ((*HistBox["Muon_2_Pt"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_2_Pt",1000,0,1000);
            new ((*HistBox["Muon_2_Eta"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_2_Eta",1000,-5,5);
            new ((*HistBox["Muon_2_Phi"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_2_Phi",628,-3.14,3.14);
            new ((*HistBox["Muon_2_E"])[i_Channel*CutStepName.size()+i_CutStep]) TH1D(Form("%s_%s",ChannelName.at(i_Channel).c_str(),CutStepName.at(i_CutStep).c_str()),"Muon_2_E",1000,0,1000);

        }
    }
}

