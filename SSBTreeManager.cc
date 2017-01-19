// SSBTMMaker v2.11

#include "SSBTreeManager.h"

void SSBTreeManager::FillNtuple(){
   ssbtree->Fill();
}

void SSBTreeManager::Fill(st VariableName, double pt, double eta, double phi, double e, int index){
    if ((it_VariableBox_LorentzVector = VariableBox_LorentzVector.find(VariableName.c_str())) != VariableBox_LorentzVector.end()){
	new ((*VariableBox_LorentzVector[VariableName.c_str()])[index]) TLorentzVector();
	( (TLorentzVector*)VariableBox_LorentzVector[VariableName.c_str()]->At(index) )->SetPtEtaPhiE(pt, eta, phi, e);
    }
    else {
	std::cout << "Fill_LV_Int Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, double pt, double eta, double phi, double e, unsigned int index){
    if ((it_VariableBox_LorentzVector = VariableBox_LorentzVector.find(VariableName.c_str())) != VariableBox_LorentzVector.end()){
	new ((*VariableBox_LorentzVector[VariableName.c_str()])[index]) TLorentzVector();
	( (TLorentzVector*)VariableBox_LorentzVector[VariableName.c_str()]->At(index) )->SetPtEtaPhiE(pt, eta, phi, e);
    }
    else {
	std::cout << "Fill_LV_UInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, bool VariableBool){
    if ((it_VariableBox_Bool = VariableBox_Bool.find(VariableName.c_str())) != VariableBox_Bool.end()){
	VariableBox_Bool[VariableName.c_str()] = VariableBool;
	//std::cout << "Val : " << VariableBool << " == " << it_VariableBox_Bool->second << std::endl;
    }
    else if ((it_VectorBox_Bool = VectorBox_Bool.find(VariableName.c_str())) != VectorBox_Bool.end()){
        (it_VectorBox_Bool->second).push_back(VariableBool);
	//std::cout << "Vec : " << VariableBool << " == " << (it_VectorBox_Bool->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Bool Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, int VariableInt){
    if ((it_VariableBox_Int = VariableBox_Int.find(VariableName.c_str())) != VariableBox_Int.end()){
	VariableBox_Int[VariableName.c_str()] = VariableInt;
	//std::cout << "Val : " << VariableInt << " == " << it_VariableBox_Int->second << std::endl;
    }
    else if ((it_VectorBox_Int = VectorBox_Int.find(VariableName.c_str())) != VectorBox_Int.end()){
        (it_VectorBox_Int->second).push_back(VariableInt);
	//std::cout << "Vec : " << VariableInt << " == " << (it_VectorBox_Int->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Int Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, unsigned int VariableUInt){
    if ((it_VariableBox_UInt = VariableBox_UInt.find(VariableName.c_str())) != VariableBox_UInt.end()){
	VariableBox_UInt[VariableName.c_str()] = VariableUInt;
	//std::cout << "Val : " << VariableUInt << " == " << it_VariableBox_UInt->second << std::endl;
    }
    else if ((it_VectorBox_UInt = VectorBox_UInt.find(VariableName.c_str())) != VectorBox_UInt.end()){
        (it_VectorBox_UInt->second).push_back(VariableUInt);
	//std::cout << "Vec : " << VariableUInt << " == " << (it_VectorBox_UInt->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_UInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, float VariableFloat){
    if ((it_VariableBox_Float = VariableBox_Float.find(VariableName.c_str())) != VariableBox_Float.end()){
	VariableBox_Float[VariableName.c_str()] = VariableFloat;
	//std::cout << "Val : " << VariableFloat << " == " << it_VariableBox_Float->second << std::endl;
    }
    else if ((it_VectorBox_Float = VectorBox_Float.find(VariableName.c_str())) != VectorBox_Float.end()){
        (it_VectorBox_Float->second).push_back(VariableFloat);
	//std::cout << "Vec : " << VariableFloat << " == " << (it_VectorBox_Float->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Float Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, double VariableDouble){
    if ((it_VariableBox_Double = VariableBox_Double.find(VariableName.c_str())) != VariableBox_Double.end()){
	VariableBox_Double[VariableName.c_str()] = VariableDouble;
	//std::cout << "Val : " << VariableDouble << " == " << it_VariableBox_Double->second << std::endl;
    }
    else if ((it_VectorBox_Double = VectorBox_Double.find(VariableName.c_str())) != VectorBox_Double.end()){
        (it_VectorBox_Double->second).push_back(VariableDouble);
	//std::cout << "Vec : " << VariableDouble << " == " << (it_VectorBox_Double->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Double Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, st VariableString){
    if ((it_VariableBox_String = VariableBox_String.find(VariableName.c_str())) != VariableBox_String.end()){
	VariableBox_String[VariableName.c_str()] = VariableString;
	//std::cout << "Val : " << VariableString << " == " << it_VariableBox_String->second << std::endl;
    }
    else if ((it_VectorBox_String = VectorBox_String.find(VariableName.c_str())) != VectorBox_String.end()){
        (it_VectorBox_String->second).push_back(VariableString);
	//std::cout << "Vec : " << VariableString << " == " << (it_VectorBox_String->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_String Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_b VectorBool){
    if ((it_VectorBox_Bool = VectorBox_Bool.find(VariableName.c_str())) != VectorBox_Bool.end()){
        (it_VectorBox_Bool->second) = VectorBool;
    }
    else {
	std::cout << "Fill_VectorBool Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_i VectorInt){
    if ((it_VectorBox_Int = VectorBox_Int.find(VariableName.c_str())) != VectorBox_Int.end()){
        (it_VectorBox_Int->second) = VectorInt;
    }
    else {
	std::cout << "Fill_VectorInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_ui VectorUInt){
    if ((it_VectorBox_UInt = VectorBox_UInt.find(VariableName.c_str())) != VectorBox_UInt.end()){
        (it_VectorBox_UInt->second) = VectorUInt;
    }
    else {
	std::cout << "Fill_VectorUInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_f VectorFloat){
    if ((it_VectorBox_Float = VectorBox_Float.find(VariableName.c_str())) != VectorBox_Float.end()){
        (it_VectorBox_Float->second) = VectorFloat;
    }
    else {
	std::cout << "Fill_VectorFloat Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_d VectorDouble){
    if ((it_VectorBox_Double = VectorBox_Double.find(VariableName.c_str())) != VectorBox_Double.end()){
        (it_VectorBox_Double->second) = VectorDouble;
    }
    else {
	std::cout << "Fill_VectorDouble Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_s VectorString){
    if ((it_VectorBox_String = VectorBox_String.find(VariableName.c_str())) != VectorBox_String.end()){
        (it_VectorBox_String->second) = VectorString;
    }
    else {
	std::cout << "Fill_VectorString Error : " << VariableName << std::endl;
    }
}

SSBTreeManager::SSBTreeManager(){

    VariableBox_LorentzVector["GenPar"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["GenJet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["GenTop"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Muon"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Muon"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Elec"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Elec"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Jet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Jet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["MET"] = new TClonesArray("TLorentzVector");

}

SSBTreeManager::~SSBTreeManager(){


}

void SSBTreeManager::Book(TTree* tree){

    ssbtree = tree;
    ssbtree->Branch("Info_EventNumber", &VariableBox_Int["Info_EventNumber"], "Info_EventNumber/I");
    ssbtree->Branch("Info_Luminosity", &VariableBox_Int["Info_Luminosity"], "Info_Luminosity/I");
    ssbtree->Branch("Info_RunNumber", &VariableBox_Int["Info_RunNumber"], "Info_RunNumber/I");
    ssbtree->Branch("Info_isData", &VariableBox_Bool["Info_isData"], "Info_isData/B");
    ssbtree->Branch("Channel_Idx", &VariableBox_Int["Channel_Idx"], "Channel_Idx/I");
    ssbtree->Branch("Channel_Idx_Final", &VariableBox_Int["Channel_Idx_Final"], "Channel_Idx_Final/I");
    ssbtree->Branch("Channel_Jets", &VariableBox_Int["Channel_Jets"], "Channel_Jets/I");
    ssbtree->Branch("Channel_Jets_Abs", &VariableBox_Int["Channel_Jets_Abs"], "Channel_Jets_Abs/I");
    ssbtree->Branch("Channel_Lepton_Count", &VariableBox_Int["Channel_Lepton_Count"], "Channel_Lepton_Count/I");
    ssbtree->Branch("Channel_Lepton_Count_Final", &VariableBox_Int["Channel_Lepton_Count_Final"], "Channel_Lepton_Count_Final/I");
    ssbtree->Branch("Channel_Lepton_Minus", &VariableBox_Int["Channel_Lepton_Minus"], "Channel_Lepton_Minus/I");
    ssbtree->Branch("Channel_Lepton_Plus", &VariableBox_Int["Channel_Lepton_Plus"], "Channel_Lepton_Plus/I");
    ssbtree->Branch("Cut_BJet_Count", &VariableBox_Int["Cut_BJet_Count"], "Cut_BJet_Count/I");
    ssbtree->Branch("Cut_Elec", "TClonesArray", &VariableBox_LorentzVector["Cut_Elec"], 32000, 0);
    VariableBox_LorentzVector["Cut_Elec"]->BypassStreamer();
    ssbtree->Branch("Cut_Event_Filter", &VariableBox_Bool["Cut_Event_Filter"], "Cut_Event_Filter/B");
    ssbtree->Branch("Cut_Jet", "TClonesArray", &VariableBox_LorentzVector["Cut_Jet"], 32000, 0);
    VariableBox_LorentzVector["Cut_Jet"]->BypassStreamer();
    ssbtree->Branch("Cut_Jet_Count", &VariableBox_Int["Cut_Jet_Count"], "Cut_Jet_Count/I");
    ssbtree->Branch("Cut_Jet_Index", &VectorBox_Int["Cut_Jet_Index"]);
    ssbtree->Branch("Cut_Jet_bTag", &VectorBox_Bool["Cut_Jet_bTag"]);
    ssbtree->Branch("Cut_LeptonMass", &VariableBox_Bool["Cut_LeptonMass"], "Cut_LeptonMass/B");
    ssbtree->Branch("Cut_MET", &VariableBox_Bool["Cut_MET"], "Cut_MET/B");
    ssbtree->Branch("Cut_MT_min", &VariableBox_Bool["Cut_MT_min"], "Cut_MT_min/B");
    ssbtree->Branch("Cut_Muon", "TClonesArray", &VariableBox_LorentzVector["Cut_Muon"], 32000, 0);
    VariableBox_LorentzVector["Cut_Muon"]->BypassStreamer();
    ssbtree->Branch("Cut_dl_Opposite", &VariableBox_Bool["Cut_dl_Opposite"], "Cut_dl_Opposite/B");
    ssbtree->Branch("Cut_dl_Same", &VariableBox_Bool["Cut_dl_Same"], "Cut_dl_Same/B");
    ssbtree->Branch("Cut_e_Charge", &VariableBox_Bool["Cut_e_Charge"], "Cut_e_Charge/B");
    ssbtree->Branch("Cut_e_ElectronVeto", &VariableBox_Bool["Cut_e_ElectronVeto"], "Cut_e_ElectronVeto/B");
    ssbtree->Branch("Cut_e_MassVeto", &VariableBox_Bool["Cut_e_MassVeto"], "Cut_e_MassVeto/B");
    ssbtree->Branch("Cut_e_MuonVeto", &VariableBox_Bool["Cut_e_MuonVeto"], "Cut_e_MuonVeto/B");
    ssbtree->Branch("Cut_e_Trigger", &VariableBox_Bool["Cut_e_Trigger"], "Cut_e_Trigger/B");
    ssbtree->Branch("Cut_ee_LeptonPair", &VariableBox_Bool["Cut_ee_LeptonPair"], "Cut_ee_LeptonPair/B");
    ssbtree->Branch("Cut_ee_Step0a", &VariableBox_Bool["Cut_ee_Step0a"], "Cut_ee_Step0a/B");
    ssbtree->Branch("Cut_ee_Step0b", &VariableBox_Bool["Cut_ee_Step0b"], "Cut_ee_Step0b/B");
    ssbtree->Branch("Cut_ee_Step0c", &VariableBox_Bool["Cut_ee_Step0c"], "Cut_ee_Step0c/B");
    ssbtree->Branch("Cut_ee_Step1a", &VariableBox_Bool["Cut_ee_Step1a"], "Cut_ee_Step1a/B");
    ssbtree->Branch("Cut_ee_Step1b", &VariableBox_Bool["Cut_ee_Step1b"], "Cut_ee_Step1b/B");
    ssbtree->Branch("Cut_ee_Step2", &VariableBox_Bool["Cut_ee_Step2"], "Cut_ee_Step2/B");
    ssbtree->Branch("Cut_ee_Step3", &VariableBox_Bool["Cut_ee_Step3"], "Cut_ee_Step3/B");
    ssbtree->Branch("Cut_ee_Step4", &VariableBox_Bool["Cut_ee_Step4"], "Cut_ee_Step4/B");
    ssbtree->Branch("Cut_ee_Step5", &VariableBox_Bool["Cut_ee_Step5"], "Cut_ee_Step5/B");
    ssbtree->Branch("Cut_em_LeptonPair", &VariableBox_Bool["Cut_em_LeptonPair"], "Cut_em_LeptonPair/B");
    ssbtree->Branch("Cut_em_Step0a", &VariableBox_Bool["Cut_em_Step0a"], "Cut_em_Step0a/B");
    ssbtree->Branch("Cut_em_Step0b", &VariableBox_Bool["Cut_em_Step0b"], "Cut_em_Step0b/B");
    ssbtree->Branch("Cut_em_Step0c", &VariableBox_Bool["Cut_em_Step0c"], "Cut_em_Step0c/B");
    ssbtree->Branch("Cut_em_Step1a", &VariableBox_Bool["Cut_em_Step1a"], "Cut_em_Step1a/B");
    ssbtree->Branch("Cut_em_Step1b", &VariableBox_Bool["Cut_em_Step1b"], "Cut_em_Step1b/B");
    ssbtree->Branch("Cut_em_Step2", &VariableBox_Bool["Cut_em_Step2"], "Cut_em_Step2/B");
    ssbtree->Branch("Cut_em_Step3", &VariableBox_Bool["Cut_em_Step3"], "Cut_em_Step3/B");
    ssbtree->Branch("Cut_em_Step4", &VariableBox_Bool["Cut_em_Step4"], "Cut_em_Step4/B");
    ssbtree->Branch("Cut_em_Step5", &VariableBox_Bool["Cut_em_Step5"], "Cut_em_Step5/B");
    ssbtree->Branch("Cut_em_Trigger", &VariableBox_Bool["Cut_em_Trigger"], "Cut_em_Trigger/B");
    ssbtree->Branch("Cut_m_Charge", &VariableBox_Bool["Cut_m_Charge"], "Cut_m_Charge/B");
    ssbtree->Branch("Cut_m_ElectronVeto", &VariableBox_Bool["Cut_m_ElectronVeto"], "Cut_m_ElectronVeto/B");
    ssbtree->Branch("Cut_m_MassVeto", &VariableBox_Bool["Cut_m_MassVeto"], "Cut_m_MassVeto/B");
    ssbtree->Branch("Cut_m_MuonVeto", &VariableBox_Bool["Cut_m_MuonVeto"], "Cut_m_MuonVeto/B");
    ssbtree->Branch("Cut_m_Trigger", &VariableBox_Bool["Cut_m_Trigger"], "Cut_m_Trigger/B");
    ssbtree->Branch("Cut_mm_LeptonPair", &VariableBox_Bool["Cut_mm_LeptonPair"], "Cut_mm_LeptonPair/B");
    ssbtree->Branch("Cut_mm_Step0a", &VariableBox_Bool["Cut_mm_Step0a"], "Cut_mm_Step0a/B");
    ssbtree->Branch("Cut_mm_Step0b", &VariableBox_Bool["Cut_mm_Step0b"], "Cut_mm_Step0b/B");
    ssbtree->Branch("Cut_mm_Step0c", &VariableBox_Bool["Cut_mm_Step0c"], "Cut_mm_Step0c/B");
    ssbtree->Branch("Cut_mm_Step1a", &VariableBox_Bool["Cut_mm_Step1a"], "Cut_mm_Step1a/B");
    ssbtree->Branch("Cut_mm_Step1b", &VariableBox_Bool["Cut_mm_Step1b"], "Cut_mm_Step1b/B");
    ssbtree->Branch("Cut_mm_Step2", &VariableBox_Bool["Cut_mm_Step2"], "Cut_mm_Step2/B");
    ssbtree->Branch("Cut_mm_Step3", &VariableBox_Bool["Cut_mm_Step3"], "Cut_mm_Step3/B");
    ssbtree->Branch("Cut_mm_Step4", &VariableBox_Bool["Cut_mm_Step4"], "Cut_mm_Step4/B");
    ssbtree->Branch("Cut_mm_Step5", &VariableBox_Bool["Cut_mm_Step5"], "Cut_mm_Step5/B");
    ssbtree->Branch("Elec", "TClonesArray", &VariableBox_LorentzVector["Elec"], 32000, 0);
    VariableBox_LorentzVector["Elec"]->BypassStreamer();
    ssbtree->Branch("Elec_Charge", &VectorBox_Int["Elec_Charge"]);
    ssbtree->Branch("Elec_ChargeId_GsfCtfPx", &VectorBox_Bool["Elec_ChargeId_GsfCtfPx"]);
    ssbtree->Branch("Elec_Conversion", &VectorBox_Bool["Elec_Conversion"]);
    ssbtree->Branch("Elec_Count", &VariableBox_Int["Elec_Count"], "Elec_Count/I");
    ssbtree->Branch("Elec_Cut_Isolated", &VectorBox_Bool["Elec_Cut_Isolated"]);
    ssbtree->Branch("Elec_Cut_Veto", &VectorBox_Bool["Elec_Cut_Veto"]);
    ssbtree->Branch("Elec_PFIsodBeta03", &VectorBox_Double["Elec_PFIsodBeta03"]);
    ssbtree->Branch("Elec_Supercluster_Eta", &VectorBox_Double["Elec_Supercluster_Eta"]);
    ssbtree->Branch("Elec_isIsoID", &VectorBox_Bool["Elec_isIsoID"]);
    ssbtree->Branch("Elec_isVetoID", &VectorBox_Bool["Elec_isVetoID"]);
    ssbtree->Branch("Elec_pdgId", &VectorBox_Int["Elec_pdgId"]);
    ssbtree->Branch("GenJet", "TClonesArray", &VariableBox_LorentzVector["GenJet"], 32000, 0);
    VariableBox_LorentzVector["GenJet"]->BypassStreamer();
    ssbtree->Branch("GenJet_Count", &VariableBox_Int["GenJet_Count"], "GenJet_Count/I");
    ssbtree->Branch("GenPar", "TClonesArray", &VariableBox_LorentzVector["GenPar"], 32000, 0);
    VariableBox_LorentzVector["GenPar"]->BypassStreamer();
    ssbtree->Branch("GenPar_Count", &VariableBox_Int["GenPar_Count"], "GenPar_Count/I");
    ssbtree->Branch("GenPar_Dau1_Idx", &VectorBox_Int["GenPar_Dau1_Idx"]);
    ssbtree->Branch("GenPar_Dau2_Idx", &VectorBox_Int["GenPar_Dau2_Idx"]);
    ssbtree->Branch("GenPar_Dau_Counter", &VectorBox_Int["GenPar_Dau_Counter"]);
    ssbtree->Branch("GenPar_Idx", &VectorBox_Int["GenPar_Idx"]);
    ssbtree->Branch("GenPar_Mom1_Idx", &VectorBox_Int["GenPar_Mom1_Idx"]);
    ssbtree->Branch("GenPar_Mom2_Idx", &VectorBox_Int["GenPar_Mom2_Idx"]);
    ssbtree->Branch("GenPar_Mom_Counter", &VectorBox_Int["GenPar_Mom_Counter"]);
    ssbtree->Branch("GenPar_Status", &VectorBox_Int["GenPar_Status"]);
    ssbtree->Branch("GenPar_pdgId", &VectorBox_Int["GenPar_pdgId"]);
    ssbtree->Branch("GenTop", "TClonesArray", &VariableBox_LorentzVector["GenTop"], 32000, 0);
    VariableBox_LorentzVector["GenTop"]->BypassStreamer();
    ssbtree->Branch("HT", &VariableBox_Double["HT"], "HT/D");
    ssbtree->Branch("Jet", "TClonesArray", &VariableBox_LorentzVector["Jet"], 32000, 0);
    VariableBox_LorentzVector["Jet"]->BypassStreamer();
    ssbtree->Branch("Jet_Count", &VariableBox_Int["Jet_Count"], "Jet_Count/I");
    ssbtree->Branch("Jet_bDisc", &VectorBox_Double["Jet_bDisc"]);
    ssbtree->Branch("Jet_cDiscCvsB", &VectorBox_Double["Jet_cDiscCvsB"]);
    ssbtree->Branch("Jet_cDiscCvsL", &VectorBox_Double["Jet_cDiscCvsL"]);
    ssbtree->Branch("Jet_isCleanedJet", &VectorBox_Bool["Jet_isCleanedJet"]);
    ssbtree->Branch("Jet_isJetID", &VectorBox_Bool["Jet_isJetID"]);
    ssbtree->Branch("MET", "TClonesArray", &VariableBox_LorentzVector["MET"], 32000, 0);
    VariableBox_LorentzVector["MET"]->BypassStreamer();
    ssbtree->Branch("Muon", "TClonesArray", &VariableBox_LorentzVector["Muon"], 32000, 0);
    VariableBox_LorentzVector["Muon"]->BypassStreamer();
    ssbtree->Branch("Muon_Charge", &VectorBox_Int["Muon_Charge"]);
    ssbtree->Branch("Muon_Count", &VariableBox_Int["Muon_Count"], "Muon_Count/I");
    ssbtree->Branch("Muon_Cut_Isolated", &VectorBox_Bool["Muon_Cut_Isolated"]);
    ssbtree->Branch("Muon_Cut_Veto", &VectorBox_Bool["Muon_Cut_Veto"]);
    ssbtree->Branch("Muon_PFIsodBeta04", &VectorBox_Double["Muon_PFIsodBeta04"]);
    ssbtree->Branch("Muon_isIsoID", &VectorBox_Bool["Muon_isIsoID"]);
    ssbtree->Branch("Muon_isVetoID", &VectorBox_Bool["Muon_isVetoID"]);
    ssbtree->Branch("Muon_pdgId", &VectorBox_Int["Muon_pdgId"]);
    ssbtree->Branch("Num_MinusElectron", &VariableBox_Int["Num_MinusElectron"], "Num_MinusElectron/I");
    ssbtree->Branch("Num_MinusLepton", &VariableBox_Int["Num_MinusLepton"], "Num_MinusLepton/I");
    ssbtree->Branch("Num_MinusMuon", &VariableBox_Int["Num_MinusMuon"], "Num_MinusMuon/I");
    ssbtree->Branch("Num_PlusElectron", &VariableBox_Int["Num_PlusElectron"], "Num_PlusElectron/I");
    ssbtree->Branch("Num_PlusLepton", &VariableBox_Int["Num_PlusLepton"], "Num_PlusLepton/I");
    ssbtree->Branch("Num_PlusMuon", &VariableBox_Int["Num_PlusMuon"], "Num_PlusMuon/I");
    ssbtree->Branch("PV_Count", &VariableBox_Int["PV_Count"], "PV_Count/I");

}

void SSBTreeManager::InitializeVariables(){

    VariableBox_Int["Info_EventNumber"] = 0;
    VariableBox_Int["Info_Luminosity"] = 0;
    VariableBox_Int["Info_RunNumber"] = 0;
    VariableBox_Bool["Info_isData"] = false;
    VariableBox_Int["Channel_Idx"] = 0;
    VariableBox_Int["Channel_Idx_Final"] = 0;
    VariableBox_Int["Channel_Jets"] = 0;
    VariableBox_Int["Channel_Jets_Abs"] = 0;
    VariableBox_Int["Channel_Lepton_Count"] = 0;
    VariableBox_Int["Channel_Lepton_Count_Final"] = 0;
    VariableBox_Int["Channel_Lepton_Minus"] = 0;
    VariableBox_Int["Channel_Lepton_Plus"] = 0;
    VariableBox_Int["Cut_BJet_Count"] = 0;
    VariableBox_LorentzVector["Cut_Elec"]->Clear();
    VariableBox_Bool["Cut_Event_Filter"] = false;
    VariableBox_LorentzVector["Cut_Jet"]->Clear();
    VariableBox_Int["Cut_Jet_Count"] = 0;
    VectorBox_Int["Cut_Jet_Index"].clear();
    VectorBox_Bool["Cut_Jet_bTag"].clear();
    VariableBox_Bool["Cut_LeptonMass"] = false;
    VariableBox_Bool["Cut_MET"] = false;
    VariableBox_Bool["Cut_MT_min"] = false;
    VariableBox_LorentzVector["Cut_Muon"]->Clear();
    VariableBox_Bool["Cut_dl_Opposite"] = false;
    VariableBox_Bool["Cut_dl_Same"] = false;
    VariableBox_Bool["Cut_e_Charge"] = false;
    VariableBox_Bool["Cut_e_ElectronVeto"] = false;
    VariableBox_Bool["Cut_e_MassVeto"] = false;
    VariableBox_Bool["Cut_e_MuonVeto"] = false;
    VariableBox_Bool["Cut_e_Trigger"] = false;
    VariableBox_Bool["Cut_ee_LeptonPair"] = false;
    VariableBox_Bool["Cut_ee_Step0a"] = false;
    VariableBox_Bool["Cut_ee_Step0b"] = false;
    VariableBox_Bool["Cut_ee_Step0c"] = false;
    VariableBox_Bool["Cut_ee_Step1a"] = false;
    VariableBox_Bool["Cut_ee_Step1b"] = false;
    VariableBox_Bool["Cut_ee_Step2"] = false;
    VariableBox_Bool["Cut_ee_Step3"] = false;
    VariableBox_Bool["Cut_ee_Step4"] = false;
    VariableBox_Bool["Cut_ee_Step5"] = false;
    VariableBox_Bool["Cut_em_LeptonPair"] = false;
    VariableBox_Bool["Cut_em_Step0a"] = false;
    VariableBox_Bool["Cut_em_Step0b"] = false;
    VariableBox_Bool["Cut_em_Step0c"] = false;
    VariableBox_Bool["Cut_em_Step1a"] = false;
    VariableBox_Bool["Cut_em_Step1b"] = false;
    VariableBox_Bool["Cut_em_Step2"] = false;
    VariableBox_Bool["Cut_em_Step3"] = false;
    VariableBox_Bool["Cut_em_Step4"] = false;
    VariableBox_Bool["Cut_em_Step5"] = false;
    VariableBox_Bool["Cut_em_Trigger"] = false;
    VariableBox_Bool["Cut_m_Charge"] = false;
    VariableBox_Bool["Cut_m_ElectronVeto"] = false;
    VariableBox_Bool["Cut_m_MassVeto"] = false;
    VariableBox_Bool["Cut_m_MuonVeto"] = false;
    VariableBox_Bool["Cut_m_Trigger"] = false;
    VariableBox_Bool["Cut_mm_LeptonPair"] = false;
    VariableBox_Bool["Cut_mm_Step0a"] = false;
    VariableBox_Bool["Cut_mm_Step0b"] = false;
    VariableBox_Bool["Cut_mm_Step0c"] = false;
    VariableBox_Bool["Cut_mm_Step1a"] = false;
    VariableBox_Bool["Cut_mm_Step1b"] = false;
    VariableBox_Bool["Cut_mm_Step2"] = false;
    VariableBox_Bool["Cut_mm_Step3"] = false;
    VariableBox_Bool["Cut_mm_Step4"] = false;
    VariableBox_Bool["Cut_mm_Step5"] = false;
    VariableBox_LorentzVector["Elec"]->Clear();
    VectorBox_Int["Elec_Charge"].clear();
    VectorBox_Bool["Elec_ChargeId_GsfCtfPx"].clear();
    VectorBox_Bool["Elec_Conversion"].clear();
    VariableBox_Int["Elec_Count"] = 0;
    VectorBox_Bool["Elec_Cut_Isolated"].clear();
    VectorBox_Bool["Elec_Cut_Veto"].clear();
    VectorBox_Double["Elec_PFIsodBeta03"].clear();
    VectorBox_Double["Elec_Supercluster_Eta"].clear();
    VectorBox_Bool["Elec_isIsoID"].clear();
    VectorBox_Bool["Elec_isVetoID"].clear();
    VectorBox_Int["Elec_pdgId"].clear();
    VariableBox_LorentzVector["GenJet"]->Clear();
    VariableBox_Int["GenJet_Count"] = 0;
    VariableBox_LorentzVector["GenPar"]->Clear();
    VariableBox_Int["GenPar_Count"] = 0;
    VectorBox_Int["GenPar_Dau1_Idx"].clear();
    VectorBox_Int["GenPar_Dau2_Idx"].clear();
    VectorBox_Int["GenPar_Dau_Counter"].clear();
    VectorBox_Int["GenPar_Idx"].clear();
    VectorBox_Int["GenPar_Mom1_Idx"].clear();
    VectorBox_Int["GenPar_Mom2_Idx"].clear();
    VectorBox_Int["GenPar_Mom_Counter"].clear();
    VectorBox_Int["GenPar_Status"].clear();
    VectorBox_Int["GenPar_pdgId"].clear();
    VariableBox_LorentzVector["GenTop"]->Clear();
    VariableBox_Double["HT"] = 0;
    VariableBox_LorentzVector["Jet"]->Clear();
    VariableBox_Int["Jet_Count"] = 0;
    VectorBox_Double["Jet_bDisc"].clear();
    VectorBox_Double["Jet_cDiscCvsB"].clear();
    VectorBox_Double["Jet_cDiscCvsL"].clear();
    VectorBox_Bool["Jet_isCleanedJet"].clear();
    VectorBox_Bool["Jet_isJetID"].clear();
    VariableBox_LorentzVector["MET"]->Clear();
    VariableBox_LorentzVector["Muon"]->Clear();
    VectorBox_Int["Muon_Charge"].clear();
    VariableBox_Int["Muon_Count"] = 0;
    VectorBox_Bool["Muon_Cut_Isolated"].clear();
    VectorBox_Bool["Muon_Cut_Veto"].clear();
    VectorBox_Double["Muon_PFIsodBeta04"].clear();
    VectorBox_Bool["Muon_isIsoID"].clear();
    VectorBox_Bool["Muon_isVetoID"].clear();
    VectorBox_Int["Muon_pdgId"].clear();
    VariableBox_Int["Num_MinusElectron"] = 0;
    VariableBox_Int["Num_MinusLepton"] = 0;
    VariableBox_Int["Num_MinusMuon"] = 0;
    VariableBox_Int["Num_PlusElectron"] = 0;
    VariableBox_Int["Num_PlusLepton"] = 0;
    VariableBox_Int["Num_PlusMuon"] = 0;
    VariableBox_Int["PV_Count"] = 0;

}

void SSBTreeManager::GenBook(TTree* tree){

    ssbtree = tree;
    ssbtree->Branch("Info_EventNumber", &VariableBox_Int["Info_EventNumber"], "Info_EventNumber/I");
    ssbtree->Branch("Info_Luminosity", &VariableBox_Int["Info_Luminosity"], "Info_Luminosity/I");
    ssbtree->Branch("Info_RunNumber", &VariableBox_Int["Info_RunNumber"], "Info_RunNumber/I");
    ssbtree->Branch("Info_isData", &VariableBox_Bool["Info_isData"], "Info_isData/B");
    ssbtree->Branch("Channel_Idx", &VariableBox_Int["Channel_Idx"], "Channel_Idx/I");
    ssbtree->Branch("Channel_Idx_Final", &VariableBox_Int["Channel_Idx_Final"], "Channel_Idx_Final/I");
    ssbtree->Branch("Channel_Jets", &VariableBox_Int["Channel_Jets"], "Channel_Jets/I");
    ssbtree->Branch("Channel_Jets_Abs", &VariableBox_Int["Channel_Jets_Abs"], "Channel_Jets_Abs/I");
    ssbtree->Branch("Channel_Lepton_Count", &VariableBox_Int["Channel_Lepton_Count"], "Channel_Lepton_Count/I");
    ssbtree->Branch("Channel_Lepton_Count_Final", &VariableBox_Int["Channel_Lepton_Count_Final"], "Channel_Lepton_Count_Final/I");
    ssbtree->Branch("Channel_Lepton_Minus", &VariableBox_Int["Channel_Lepton_Minus"], "Channel_Lepton_Minus/I");
    ssbtree->Branch("Channel_Lepton_Plus", &VariableBox_Int["Channel_Lepton_Plus"], "Channel_Lepton_Plus/I");
    ssbtree->Branch("GenJet", "TClonesArray", &VariableBox_LorentzVector["GenJet"], 32000, 0);
    VariableBox_LorentzVector["GenJet"]->BypassStreamer();
    ssbtree->Branch("GenJet_Count", &VariableBox_Int["GenJet_Count"], "GenJet_Count/I");
    ssbtree->Branch("GenPar", "TClonesArray", &VariableBox_LorentzVector["GenPar"], 32000, 0);
    VariableBox_LorentzVector["GenPar"]->BypassStreamer();
    ssbtree->Branch("GenPar_Count", &VariableBox_Int["GenPar_Count"], "GenPar_Count/I");
    ssbtree->Branch("GenPar_Dau1_Idx", &VectorBox_Int["GenPar_Dau1_Idx"]);
    ssbtree->Branch("GenPar_Dau2_Idx", &VectorBox_Int["GenPar_Dau2_Idx"]);
    ssbtree->Branch("GenPar_Dau_Counter", &VectorBox_Int["GenPar_Dau_Counter"]);
    ssbtree->Branch("GenPar_Idx", &VectorBox_Int["GenPar_Idx"]);
    ssbtree->Branch("GenPar_Mom1_Idx", &VectorBox_Int["GenPar_Mom1_Idx"]);
    ssbtree->Branch("GenPar_Mom2_Idx", &VectorBox_Int["GenPar_Mom2_Idx"]);
    ssbtree->Branch("GenPar_Mom_Counter", &VectorBox_Int["GenPar_Mom_Counter"]);
    ssbtree->Branch("GenPar_Status", &VectorBox_Int["GenPar_Status"]);
    ssbtree->Branch("GenPar_pdgId", &VectorBox_Int["GenPar_pdgId"]);
    ssbtree->Branch("GenTop", "TClonesArray", &VariableBox_LorentzVector["GenTop"], 32000, 0);
    VariableBox_LorentzVector["GenTop"]->BypassStreamer();

}

void SSBTreeManager::GenInitializeVariables(){

    VariableBox_Int["Info_EventNumber"] = 0;
    VariableBox_Int["Info_Luminosity"] = 0;
    VariableBox_Int["Info_RunNumber"] = 0;
    VariableBox_Bool["Info_isData"] = false;
    VariableBox_Int["Channel_Idx"] = 0;
    VariableBox_Int["Channel_Idx_Final"] = 0;
    VariableBox_Int["Channel_Jets"] = 0;
    VariableBox_Int["Channel_Jets_Abs"] = 0;
    VariableBox_Int["Channel_Lepton_Count"] = 0;
    VariableBox_Int["Channel_Lepton_Count_Final"] = 0;
    VariableBox_Int["Channel_Lepton_Minus"] = 0;
    VariableBox_Int["Channel_Lepton_Plus"] = 0;
    VariableBox_LorentzVector["GenJet"]->Clear();
    VariableBox_Int["GenJet_Count"] = 0;
    VariableBox_LorentzVector["GenPar"]->Clear();
    VariableBox_Int["GenPar_Count"] = 0;
    VectorBox_Int["GenPar_Dau1_Idx"].clear();
    VectorBox_Int["GenPar_Dau2_Idx"].clear();
    VectorBox_Int["GenPar_Dau_Counter"].clear();
    VectorBox_Int["GenPar_Idx"].clear();
    VectorBox_Int["GenPar_Mom1_Idx"].clear();
    VectorBox_Int["GenPar_Mom2_Idx"].clear();
    VectorBox_Int["GenPar_Mom_Counter"].clear();
    VectorBox_Int["GenPar_Status"].clear();
    VectorBox_Int["GenPar_pdgId"].clear();
    VariableBox_LorentzVector["GenTop"]->Clear();

}

