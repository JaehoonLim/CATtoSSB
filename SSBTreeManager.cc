// SSBTMMaker v3.00

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
    ssbtree->Branch("Cut_All_BaseLine", &VariableBox_Bool["Cut_All_BaseLine"], "Cut_All_BaseLine/B");
    ssbtree->Branch("Cut_All_BaseLine2", &VariableBox_Bool["Cut_All_BaseLine2"], "Cut_All_BaseLine2/B");
    ssbtree->Branch("Cut_All_SR1", &VariableBox_Bool["Cut_All_SR1"], "Cut_All_SR1/B");
    ssbtree->Branch("Cut_All_SR2", &VariableBox_Bool["Cut_All_SR2"], "Cut_All_SR2/B");
    ssbtree->Branch("Cut_All_SR3", &VariableBox_Bool["Cut_All_SR3"], "Cut_All_SR3/B");
    ssbtree->Branch("Cut_All_SR4", &VariableBox_Bool["Cut_All_SR4"], "Cut_All_SR4/B");
    ssbtree->Branch("Cut_All_SR5", &VariableBox_Bool["Cut_All_SR5"], "Cut_All_SR5/B");
    ssbtree->Branch("Cut_All_SR6", &VariableBox_Bool["Cut_All_SR6"], "Cut_All_SR6/B");
    ssbtree->Branch("Cut_All_SR7", &VariableBox_Bool["Cut_All_SR7"], "Cut_All_SR7/B");
    ssbtree->Branch("Cut_All_SR8", &VariableBox_Bool["Cut_All_SR8"], "Cut_All_SR8/B");
    ssbtree->Branch("Cut_All_SRW", &VariableBox_Bool["Cut_All_SRW"], "Cut_All_SRW/B");
    ssbtree->Branch("Cut_All_SRZ", &VariableBox_Bool["Cut_All_SRZ"], "Cut_All_SRZ/B");
    ssbtree->Branch("Cut_All_Step0a", &VariableBox_Bool["Cut_All_Step0a"], "Cut_All_Step0a/B");
    ssbtree->Branch("Cut_All_Step0b", &VariableBox_Bool["Cut_All_Step0b"], "Cut_All_Step0b/B");
    ssbtree->Branch("Cut_All_Step0c", &VariableBox_Bool["Cut_All_Step0c"], "Cut_All_Step0c/B");
    ssbtree->Branch("Cut_All_Step0d", &VariableBox_Bool["Cut_All_Step0d"], "Cut_All_Step0d/B");
    ssbtree->Branch("Cut_All_Step1a", &VariableBox_Bool["Cut_All_Step1a"], "Cut_All_Step1a/B");
    ssbtree->Branch("Cut_All_Step1b", &VariableBox_Bool["Cut_All_Step1b"], "Cut_All_Step1b/B");
    ssbtree->Branch("Cut_BJet_Count", &VariableBox_Int["Cut_BJet_Count"], "Cut_BJet_Count/I");
    ssbtree->Branch("Cut_Elec", "TClonesArray", &VariableBox_LorentzVector["Cut_Elec"], 32000, 0);
    VariableBox_LorentzVector["Cut_Elec"]->BypassStreamer();
    ssbtree->Branch("Cut_Elec_ClosestJetdR", &VectorBox_Double["Cut_Elec_ClosestJetdR"]);
    ssbtree->Branch("Cut_Elec_MT", &VectorBox_Double["Cut_Elec_MT"]);
    ssbtree->Branch("Cut_Elec_PFIsodBeta03", &VectorBox_Double["Cut_Elec_PFIsodBeta03"]);
    ssbtree->Branch("Cut_Elec_PFIsodBeta04", &VectorBox_Double["Cut_Elec_PFIsodBeta04"]);
    ssbtree->Branch("Cut_Elec_Pt_rat", &VectorBox_Double["Cut_Elec_Pt_rat"]);
    ssbtree->Branch("Cut_Elec_Pt_rel", &VectorBox_Double["Cut_Elec_Pt_rel"]);
    ssbtree->Branch("Cut_Elec_Weight", &VectorBox_Double["Cut_Elec_Weight"]);
    ssbtree->Branch("Cut_Elec_dxy", &VectorBox_Double["Cut_Elec_dxy"]);
    ssbtree->Branch("Cut_Elec_dz", &VectorBox_Double["Cut_Elec_dz"]);
    ssbtree->Branch("Cut_Elec_miniRelIso", &VectorBox_Double["Cut_Elec_miniRelIso"]);
    ssbtree->Branch("Cut_Event_Filter", &VariableBox_Bool["Cut_Event_Filter"], "Cut_Event_Filter/B");
    ssbtree->Branch("Cut_Jet", "TClonesArray", &VariableBox_LorentzVector["Cut_Jet"], 32000, 0);
    VariableBox_LorentzVector["Cut_Jet"]->BypassStreamer();
    ssbtree->Branch("Cut_Jet_BJetWeight", &VectorBox_Double["Cut_Jet_BJetWeight"]);
    ssbtree->Branch("Cut_Jet_Count", &VariableBox_Int["Cut_Jet_Count"], "Cut_Jet_Count/I");
    ssbtree->Branch("Cut_Jet_Index", &VectorBox_Int["Cut_Jet_Index"]);
    ssbtree->Branch("Cut_Jet_JERWeight", &VectorBox_Double["Cut_Jet_JERWeight"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_CFerr1_down", &VectorBox_Double["Cut_Jet_SYS_BJet_CFerr1_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_CFerr1_up", &VectorBox_Double["Cut_Jet_SYS_BJet_CFerr1_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_CFerr2_down", &VectorBox_Double["Cut_Jet_SYS_BJet_CFerr2_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_CFerr2_up", &VectorBox_Double["Cut_Jet_SYS_BJet_CFerr2_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HF_down", &VectorBox_Double["Cut_Jet_SYS_BJet_HF_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HF_up", &VectorBox_Double["Cut_Jet_SYS_BJet_HF_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HFstat1_down", &VectorBox_Double["Cut_Jet_SYS_BJet_HFstat1_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HFstat1_up", &VectorBox_Double["Cut_Jet_SYS_BJet_HFstat1_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HFstat2_down", &VectorBox_Double["Cut_Jet_SYS_BJet_HFstat2_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_HFstat2_up", &VectorBox_Double["Cut_Jet_SYS_BJet_HFstat2_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_JES_down", &VectorBox_Double["Cut_Jet_SYS_BJet_JES_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_JES_up", &VectorBox_Double["Cut_Jet_SYS_BJet_JES_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LF_down", &VectorBox_Double["Cut_Jet_SYS_BJet_LF_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LF_up", &VectorBox_Double["Cut_Jet_SYS_BJet_LF_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LFstat1_down", &VectorBox_Double["Cut_Jet_SYS_BJet_LFstat1_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LFstat1_up", &VectorBox_Double["Cut_Jet_SYS_BJet_LFstat1_up"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LFstat2_down", &VectorBox_Double["Cut_Jet_SYS_BJet_LFstat2_down"]);
    ssbtree->Branch("Cut_Jet_SYS_BJet_LFstat2_up", &VectorBox_Double["Cut_Jet_SYS_BJet_LFstat2_up"]);
    ssbtree->Branch("Cut_Jet_SYS_JER_down", &VectorBox_Double["Cut_Jet_SYS_JER_down"]);
    ssbtree->Branch("Cut_Jet_SYS_JER_up", &VectorBox_Double["Cut_Jet_SYS_JER_up"]);
    ssbtree->Branch("Cut_Jet_SYS_JES_down", &VectorBox_Double["Cut_Jet_SYS_JES_down"]);
    ssbtree->Branch("Cut_Jet_SYS_JES_up", &VectorBox_Double["Cut_Jet_SYS_JES_up"]);
    ssbtree->Branch("Cut_Jet_bTag", &VectorBox_Bool["Cut_Jet_bTag"]);
    ssbtree->Branch("Cut_LeptonMass", &VariableBox_Bool["Cut_LeptonMass"], "Cut_LeptonMass/B");
    ssbtree->Branch("Cut_MET", &VariableBox_Bool["Cut_MET"], "Cut_MET/B");
    ssbtree->Branch("Cut_Muon", "TClonesArray", &VariableBox_LorentzVector["Cut_Muon"], 32000, 0);
    VariableBox_LorentzVector["Cut_Muon"]->BypassStreamer();
    ssbtree->Branch("Cut_Muon_ClosestJetdR", &VectorBox_Double["Cut_Muon_ClosestJetdR"]);
    ssbtree->Branch("Cut_Muon_MT", &VectorBox_Double["Cut_Muon_MT"]);
    ssbtree->Branch("Cut_Muon_PFIsodBeta03", &VectorBox_Double["Cut_Muon_PFIsodBeta03"]);
    ssbtree->Branch("Cut_Muon_PFIsodBeta04", &VectorBox_Double["Cut_Muon_PFIsodBeta04"]);
    ssbtree->Branch("Cut_Muon_Pt_rat", &VectorBox_Double["Cut_Muon_Pt_rat"]);
    ssbtree->Branch("Cut_Muon_Pt_rel", &VectorBox_Double["Cut_Muon_Pt_rel"]);
    ssbtree->Branch("Cut_Muon_Weight", &VectorBox_Double["Cut_Muon_Weight"]);
    ssbtree->Branch("Cut_Muon_dxy", &VectorBox_Double["Cut_Muon_dxy"]);
    ssbtree->Branch("Cut_Muon_dz", &VectorBox_Double["Cut_Muon_dz"]);
    ssbtree->Branch("Cut_Muon_miniRelIso", &VectorBox_Double["Cut_Muon_miniRelIso"]);
    ssbtree->Branch("Cut_Tri_Charge", &VariableBox_Bool["Cut_Tri_Charge"], "Cut_Tri_Charge/B");
    ssbtree->Branch("Cut_Tri_First_Zmass", &VariableBox_Bool["Cut_Tri_First_Zmass"], "Cut_Tri_First_Zmass/B");
    ssbtree->Branch("Cut_Tri_Second_Zmass", &VariableBox_Bool["Cut_Tri_Second_Zmass"], "Cut_Tri_Second_Zmass/B");
    ssbtree->Branch("Cut_Tri_TriOrMore", &VariableBox_Bool["Cut_Tri_TriOrMore"], "Cut_Tri_TriOrMore/B");
    ssbtree->Branch("Cut_Tri_ee", &VariableBox_Bool["Cut_Tri_ee"], "Cut_Tri_ee/B");
    ssbtree->Branch("Cut_Tri_em", &VariableBox_Bool["Cut_Tri_em"], "Cut_Tri_em/B");
    ssbtree->Branch("Cut_Tri_mm", &VariableBox_Bool["Cut_Tri_mm"], "Cut_Tri_mm/B");
    ssbtree->Branch("Cut_dl_Opposite", &VariableBox_Bool["Cut_dl_Opposite"], "Cut_dl_Opposite/B");
    ssbtree->Branch("Cut_dl_Same", &VariableBox_Bool["Cut_dl_Same"], "Cut_dl_Same/B");
    ssbtree->Branch("Cut_e_Charge", &VariableBox_Bool["Cut_e_Charge"], "Cut_e_Charge/B");
    ssbtree->Branch("Cut_e_ElectronVeto", &VariableBox_Bool["Cut_e_ElectronVeto"], "Cut_e_ElectronVeto/B");
    ssbtree->Branch("Cut_e_MuonVeto", &VariableBox_Bool["Cut_e_MuonVeto"], "Cut_e_MuonVeto/B");
    ssbtree->Branch("Cut_e_Trigger", &VariableBox_Bool["Cut_e_Trigger"], "Cut_e_Trigger/B");
    ssbtree->Branch("Cut_ee_BaseLine", &VariableBox_Bool["Cut_ee_BaseLine"], "Cut_ee_BaseLine/B");
    ssbtree->Branch("Cut_ee_BaseLine2", &VariableBox_Bool["Cut_ee_BaseLine2"], "Cut_ee_BaseLine2/B");
    ssbtree->Branch("Cut_ee_LeptonPair", &VariableBox_Bool["Cut_ee_LeptonPair"], "Cut_ee_LeptonPair/B");
    ssbtree->Branch("Cut_ee_LeptonPair_TightMass", &VariableBox_Bool["Cut_ee_LeptonPair_TightMass"], "Cut_ee_LeptonPair_TightMass/B");
    ssbtree->Branch("Cut_ee_SR1", &VariableBox_Bool["Cut_ee_SR1"], "Cut_ee_SR1/B");
    ssbtree->Branch("Cut_ee_SR2", &VariableBox_Bool["Cut_ee_SR2"], "Cut_ee_SR2/B");
    ssbtree->Branch("Cut_ee_SR3", &VariableBox_Bool["Cut_ee_SR3"], "Cut_ee_SR3/B");
    ssbtree->Branch("Cut_ee_SR4", &VariableBox_Bool["Cut_ee_SR4"], "Cut_ee_SR4/B");
    ssbtree->Branch("Cut_ee_SR5", &VariableBox_Bool["Cut_ee_SR5"], "Cut_ee_SR5/B");
    ssbtree->Branch("Cut_ee_SR6", &VariableBox_Bool["Cut_ee_SR6"], "Cut_ee_SR6/B");
    ssbtree->Branch("Cut_ee_SR7", &VariableBox_Bool["Cut_ee_SR7"], "Cut_ee_SR7/B");
    ssbtree->Branch("Cut_ee_SR8", &VariableBox_Bool["Cut_ee_SR8"], "Cut_ee_SR8/B");
    ssbtree->Branch("Cut_ee_SRW", &VariableBox_Bool["Cut_ee_SRW"], "Cut_ee_SRW/B");
    ssbtree->Branch("Cut_ee_SRZ", &VariableBox_Bool["Cut_ee_SRZ"], "Cut_ee_SRZ/B");
    ssbtree->Branch("Cut_ee_Step0a", &VariableBox_Bool["Cut_ee_Step0a"], "Cut_ee_Step0a/B");
    ssbtree->Branch("Cut_ee_Step0b", &VariableBox_Bool["Cut_ee_Step0b"], "Cut_ee_Step0b/B");
    ssbtree->Branch("Cut_ee_Step0c", &VariableBox_Bool["Cut_ee_Step0c"], "Cut_ee_Step0c/B");
    ssbtree->Branch("Cut_ee_Step0d", &VariableBox_Bool["Cut_ee_Step0d"], "Cut_ee_Step0d/B");
    ssbtree->Branch("Cut_ee_Step1a", &VariableBox_Bool["Cut_ee_Step1a"], "Cut_ee_Step1a/B");
    ssbtree->Branch("Cut_ee_Step1b", &VariableBox_Bool["Cut_ee_Step1b"], "Cut_ee_Step1b/B");
    ssbtree->Branch("Cut_ej_ElectronIso", &VariableBox_Bool["Cut_ej_ElectronIso"], "Cut_ej_ElectronIso/B");
    ssbtree->Branch("Cut_em_BaseLine", &VariableBox_Bool["Cut_em_BaseLine"], "Cut_em_BaseLine/B");
    ssbtree->Branch("Cut_em_BaseLine2", &VariableBox_Bool["Cut_em_BaseLine2"], "Cut_em_BaseLine2/B");
    ssbtree->Branch("Cut_em_LeptonPair", &VariableBox_Bool["Cut_em_LeptonPair"], "Cut_em_LeptonPair/B");
    ssbtree->Branch("Cut_em_LeptonPair_TightMass", &VariableBox_Bool["Cut_em_LeptonPair_TightMass"], "Cut_em_LeptonPair_TightMass/B");
    ssbtree->Branch("Cut_em_SR1", &VariableBox_Bool["Cut_em_SR1"], "Cut_em_SR1/B");
    ssbtree->Branch("Cut_em_SR2", &VariableBox_Bool["Cut_em_SR2"], "Cut_em_SR2/B");
    ssbtree->Branch("Cut_em_SR3", &VariableBox_Bool["Cut_em_SR3"], "Cut_em_SR3/B");
    ssbtree->Branch("Cut_em_SR4", &VariableBox_Bool["Cut_em_SR4"], "Cut_em_SR4/B");
    ssbtree->Branch("Cut_em_SR5", &VariableBox_Bool["Cut_em_SR5"], "Cut_em_SR5/B");
    ssbtree->Branch("Cut_em_SR6", &VariableBox_Bool["Cut_em_SR6"], "Cut_em_SR6/B");
    ssbtree->Branch("Cut_em_SR7", &VariableBox_Bool["Cut_em_SR7"], "Cut_em_SR7/B");
    ssbtree->Branch("Cut_em_SR8", &VariableBox_Bool["Cut_em_SR8"], "Cut_em_SR8/B");
    ssbtree->Branch("Cut_em_SRW", &VariableBox_Bool["Cut_em_SRW"], "Cut_em_SRW/B");
    ssbtree->Branch("Cut_em_SRZ", &VariableBox_Bool["Cut_em_SRZ"], "Cut_em_SRZ/B");
    ssbtree->Branch("Cut_em_Step0a", &VariableBox_Bool["Cut_em_Step0a"], "Cut_em_Step0a/B");
    ssbtree->Branch("Cut_em_Step0b", &VariableBox_Bool["Cut_em_Step0b"], "Cut_em_Step0b/B");
    ssbtree->Branch("Cut_em_Step0c", &VariableBox_Bool["Cut_em_Step0c"], "Cut_em_Step0c/B");
    ssbtree->Branch("Cut_em_Step0d", &VariableBox_Bool["Cut_em_Step0d"], "Cut_em_Step0d/B");
    ssbtree->Branch("Cut_em_Step1a", &VariableBox_Bool["Cut_em_Step1a"], "Cut_em_Step1a/B");
    ssbtree->Branch("Cut_em_Step1b", &VariableBox_Bool["Cut_em_Step1b"], "Cut_em_Step1b/B");
    ssbtree->Branch("Cut_em_Trigger", &VariableBox_Bool["Cut_em_Trigger"], "Cut_em_Trigger/B");
    ssbtree->Branch("Cut_m_Charge", &VariableBox_Bool["Cut_m_Charge"], "Cut_m_Charge/B");
    ssbtree->Branch("Cut_m_ElectronVeto", &VariableBox_Bool["Cut_m_ElectronVeto"], "Cut_m_ElectronVeto/B");
    ssbtree->Branch("Cut_m_MuonVeto", &VariableBox_Bool["Cut_m_MuonVeto"], "Cut_m_MuonVeto/B");
    ssbtree->Branch("Cut_m_Trigger", &VariableBox_Bool["Cut_m_Trigger"], "Cut_m_Trigger/B");
    ssbtree->Branch("Cut_mj_MuonIso", &VariableBox_Bool["Cut_mj_MuonIso"], "Cut_mj_MuonIso/B");
    ssbtree->Branch("Cut_mm_BaseLine", &VariableBox_Bool["Cut_mm_BaseLine"], "Cut_mm_BaseLine/B");
    ssbtree->Branch("Cut_mm_BaseLine2", &VariableBox_Bool["Cut_mm_BaseLine2"], "Cut_mm_BaseLine2/B");
    ssbtree->Branch("Cut_mm_LeptonPair", &VariableBox_Bool["Cut_mm_LeptonPair"], "Cut_mm_LeptonPair/B");
    ssbtree->Branch("Cut_mm_LeptonPair_TightMass", &VariableBox_Bool["Cut_mm_LeptonPair_TightMass"], "Cut_mm_LeptonPair_TightMass/B");
    ssbtree->Branch("Cut_mm_SR1", &VariableBox_Bool["Cut_mm_SR1"], "Cut_mm_SR1/B");
    ssbtree->Branch("Cut_mm_SR2", &VariableBox_Bool["Cut_mm_SR2"], "Cut_mm_SR2/B");
    ssbtree->Branch("Cut_mm_SR3", &VariableBox_Bool["Cut_mm_SR3"], "Cut_mm_SR3/B");
    ssbtree->Branch("Cut_mm_SR4", &VariableBox_Bool["Cut_mm_SR4"], "Cut_mm_SR4/B");
    ssbtree->Branch("Cut_mm_SR5", &VariableBox_Bool["Cut_mm_SR5"], "Cut_mm_SR5/B");
    ssbtree->Branch("Cut_mm_SR6", &VariableBox_Bool["Cut_mm_SR6"], "Cut_mm_SR6/B");
    ssbtree->Branch("Cut_mm_SR7", &VariableBox_Bool["Cut_mm_SR7"], "Cut_mm_SR7/B");
    ssbtree->Branch("Cut_mm_SR8", &VariableBox_Bool["Cut_mm_SR8"], "Cut_mm_SR8/B");
    ssbtree->Branch("Cut_mm_SRW", &VariableBox_Bool["Cut_mm_SRW"], "Cut_mm_SRW/B");
    ssbtree->Branch("Cut_mm_SRZ", &VariableBox_Bool["Cut_mm_SRZ"], "Cut_mm_SRZ/B");
    ssbtree->Branch("Cut_mm_Step0a", &VariableBox_Bool["Cut_mm_Step0a"], "Cut_mm_Step0a/B");
    ssbtree->Branch("Cut_mm_Step0b", &VariableBox_Bool["Cut_mm_Step0b"], "Cut_mm_Step0b/B");
    ssbtree->Branch("Cut_mm_Step0c", &VariableBox_Bool["Cut_mm_Step0c"], "Cut_mm_Step0c/B");
    ssbtree->Branch("Cut_mm_Step0d", &VariableBox_Bool["Cut_mm_Step0d"], "Cut_mm_Step0d/B");
    ssbtree->Branch("Cut_mm_Step1a", &VariableBox_Bool["Cut_mm_Step1a"], "Cut_mm_Step1a/B");
    ssbtree->Branch("Cut_mm_Step1b", &VariableBox_Bool["Cut_mm_Step1b"], "Cut_mm_Step1b/B");
    ssbtree->Branch("Elec", "TClonesArray", &VariableBox_LorentzVector["Elec"], 32000, 0);
    VariableBox_LorentzVector["Elec"]->BypassStreamer();
    ssbtree->Branch("Elec_Charge", &VectorBox_Int["Elec_Charge"]);
    ssbtree->Branch("Elec_ChargeId_GsfCtfPx", &VectorBox_Bool["Elec_ChargeId_GsfCtfPx"]);
    ssbtree->Branch("Elec_ClosestJetdR", &VectorBox_Double["Elec_ClosestJetdR"]);
    ssbtree->Branch("Elec_Conversion", &VectorBox_Bool["Elec_Conversion"]);
    ssbtree->Branch("Elec_Count", &VariableBox_Int["Elec_Count"], "Elec_Count/I");
    ssbtree->Branch("Elec_Cut_Additional", &VectorBox_Bool["Elec_Cut_Additional"]);
    ssbtree->Branch("Elec_Cut_Isolated", &VectorBox_Bool["Elec_Cut_Isolated"]);
    ssbtree->Branch("Elec_Cut_Veto", &VectorBox_Bool["Elec_Cut_Veto"]);
    ssbtree->Branch("Elec_MT", &VectorBox_Double["Elec_MT"]);
    ssbtree->Branch("Elec_PFIsodBeta03", &VectorBox_Double["Elec_PFIsodBeta03"]);
    ssbtree->Branch("Elec_PFIsodBeta04", &VectorBox_Double["Elec_PFIsodBeta04"]);
    ssbtree->Branch("Elec_Pt_rat", &VectorBox_Double["Elec_Pt_rat"]);
    ssbtree->Branch("Elec_Pt_rel", &VectorBox_Double["Elec_Pt_rel"]);
    ssbtree->Branch("Elec_Supercluster_Eta", &VectorBox_Double["Elec_Supercluster_Eta"]);
    ssbtree->Branch("Elec_Weight", &VectorBox_Double["Elec_Weight"]);
    ssbtree->Branch("Elec_dxy", &VectorBox_Double["Elec_dxy"]);
    ssbtree->Branch("Elec_dz", &VectorBox_Double["Elec_dz"]);
    ssbtree->Branch("Elec_isAddID", &VectorBox_Bool["Elec_isAddID"]);
    ssbtree->Branch("Elec_isIsoID", &VectorBox_Bool["Elec_isIsoID"]);
    ssbtree->Branch("Elec_isLoose", &VectorBox_Bool["Elec_isLoose"]);
    ssbtree->Branch("Elec_isMedium", &VectorBox_Bool["Elec_isMedium"]);
    ssbtree->Branch("Elec_isTight", &VectorBox_Bool["Elec_isTight"]);
    ssbtree->Branch("Elec_isVeto", &VectorBox_Bool["Elec_isVeto"]);
    ssbtree->Branch("Elec_isVetoID", &VectorBox_Bool["Elec_isVetoID"]);
    ssbtree->Branch("Elec_miniRelIso", &VectorBox_Double["Elec_miniRelIso"]);
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
    ssbtree->Branch("GenWeight", &VariableBox_Double["GenWeight"], "GenWeight/D");
    ssbtree->Branch("HM", &VariableBox_Double["HM"], "HM/D");
    ssbtree->Branch("HT", &VariableBox_Double["HT"], "HT/D");
    ssbtree->Branch("Jet", "TClonesArray", &VariableBox_LorentzVector["Jet"], 32000, 0);
    VariableBox_LorentzVector["Jet"]->BypassStreamer();
    ssbtree->Branch("Jet_BJetWeight", &VectorBox_Double["Jet_BJetWeight"]);
    ssbtree->Branch("Jet_Count", &VariableBox_Int["Jet_Count"], "Jet_Count/I");
    ssbtree->Branch("Jet_JERWeight", &VectorBox_Double["Jet_JERWeight"]);
    ssbtree->Branch("Jet_SYS_BJet_CFerr1_down", &VectorBox_Double["Jet_SYS_BJet_CFerr1_down"]);
    ssbtree->Branch("Jet_SYS_BJet_CFerr1_up", &VectorBox_Double["Jet_SYS_BJet_CFerr1_up"]);
    ssbtree->Branch("Jet_SYS_BJet_CFerr2_down", &VectorBox_Double["Jet_SYS_BJet_CFerr2_down"]);
    ssbtree->Branch("Jet_SYS_BJet_CFerr2_up", &VectorBox_Double["Jet_SYS_BJet_CFerr2_up"]);
    ssbtree->Branch("Jet_SYS_BJet_HF_down", &VectorBox_Double["Jet_SYS_BJet_HF_down"]);
    ssbtree->Branch("Jet_SYS_BJet_HF_up", &VectorBox_Double["Jet_SYS_BJet_HF_up"]);
    ssbtree->Branch("Jet_SYS_BJet_HFstat1_down", &VectorBox_Double["Jet_SYS_BJet_HFstat1_down"]);
    ssbtree->Branch("Jet_SYS_BJet_HFstat1_up", &VectorBox_Double["Jet_SYS_BJet_HFstat1_up"]);
    ssbtree->Branch("Jet_SYS_BJet_HFstat2_down", &VectorBox_Double["Jet_SYS_BJet_HFstat2_down"]);
    ssbtree->Branch("Jet_SYS_BJet_HFstat2_up", &VectorBox_Double["Jet_SYS_BJet_HFstat2_up"]);
    ssbtree->Branch("Jet_SYS_BJet_JES_down", &VectorBox_Double["Jet_SYS_BJet_JES_down"]);
    ssbtree->Branch("Jet_SYS_BJet_JES_up", &VectorBox_Double["Jet_SYS_BJet_JES_up"]);
    ssbtree->Branch("Jet_SYS_BJet_LF_down", &VectorBox_Double["Jet_SYS_BJet_LF_down"]);
    ssbtree->Branch("Jet_SYS_BJet_LF_up", &VectorBox_Double["Jet_SYS_BJet_LF_up"]);
    ssbtree->Branch("Jet_SYS_BJet_LFstat1_down", &VectorBox_Double["Jet_SYS_BJet_LFstat1_down"]);
    ssbtree->Branch("Jet_SYS_BJet_LFstat1_up", &VectorBox_Double["Jet_SYS_BJet_LFstat1_up"]);
    ssbtree->Branch("Jet_SYS_BJet_LFstat2_down", &VectorBox_Double["Jet_SYS_BJet_LFstat2_down"]);
    ssbtree->Branch("Jet_SYS_BJet_LFstat2_up", &VectorBox_Double["Jet_SYS_BJet_LFstat2_up"]);
    ssbtree->Branch("Jet_SYS_JER_down", &VectorBox_Double["Jet_SYS_JER_down"]);
    ssbtree->Branch("Jet_SYS_JER_up", &VectorBox_Double["Jet_SYS_JER_up"]);
    ssbtree->Branch("Jet_SYS_JES_down", &VectorBox_Double["Jet_SYS_JES_down"]);
    ssbtree->Branch("Jet_SYS_JES_up", &VectorBox_Double["Jet_SYS_JES_up"]);
    ssbtree->Branch("Jet_bDisc", &VectorBox_Double["Jet_bDisc"]);
    ssbtree->Branch("Jet_cDiscCvsB", &VectorBox_Double["Jet_cDiscCvsB"]);
    ssbtree->Branch("Jet_cDiscCvsL", &VectorBox_Double["Jet_cDiscCvsL"]);
    ssbtree->Branch("Jet_isCleanedJet", &VectorBox_Bool["Jet_isCleanedJet"]);
    ssbtree->Branch("Jet_isJetID", &VectorBox_Bool["Jet_isJetID"]);
    ssbtree->Branch("Jet_qgLikelihood", &VectorBox_Double["Jet_qgLikelihood"]);
    ssbtree->Branch("Lepton_Weight", &VariableBox_Double["Lepton_Weight"], "Lepton_Weight/D");
    ssbtree->Branch("MET", "TClonesArray", &VariableBox_LorentzVector["MET"], 32000, 0);
    VariableBox_LorentzVector["MET"]->BypassStreamer();
    ssbtree->Branch("Muon", "TClonesArray", &VariableBox_LorentzVector["Muon"], 32000, 0);
    VariableBox_LorentzVector["Muon"]->BypassStreamer();
    ssbtree->Branch("Muon_Charge", &VectorBox_Int["Muon_Charge"]);
    ssbtree->Branch("Muon_ClosestJetdR", &VectorBox_Double["Muon_ClosestJetdR"]);
    ssbtree->Branch("Muon_CorrectedPt", &VectorBox_Double["Muon_CorrectedPt"]);
    ssbtree->Branch("Muon_CorrectedPtError", &VectorBox_Double["Muon_CorrectedPtError"]);
    ssbtree->Branch("Muon_Count", &VariableBox_Int["Muon_Count"], "Muon_Count/I");
    ssbtree->Branch("Muon_Cut_Additional", &VectorBox_Bool["Muon_Cut_Additional"]);
    ssbtree->Branch("Muon_Cut_Isolated", &VectorBox_Bool["Muon_Cut_Isolated"]);
    ssbtree->Branch("Muon_Cut_Veto", &VectorBox_Bool["Muon_Cut_Veto"]);
    ssbtree->Branch("Muon_MT", &VectorBox_Double["Muon_MT"]);
    ssbtree->Branch("Muon_PFIsodBeta03", &VectorBox_Double["Muon_PFIsodBeta03"]);
    ssbtree->Branch("Muon_PFIsodBeta04", &VectorBox_Double["Muon_PFIsodBeta04"]);
    ssbtree->Branch("Muon_Pt_rat", &VectorBox_Double["Muon_Pt_rat"]);
    ssbtree->Branch("Muon_Pt_rel", &VectorBox_Double["Muon_Pt_rel"]);
    ssbtree->Branch("Muon_Weight", &VectorBox_Double["Muon_Weight"]);
    ssbtree->Branch("Muon_dPtOverPt", &VectorBox_Double["Muon_dPtOverPt"]);
    ssbtree->Branch("Muon_dxy", &VectorBox_Double["Muon_dxy"]);
    ssbtree->Branch("Muon_dz", &VectorBox_Double["Muon_dz"]);
    ssbtree->Branch("Muon_isAddID", &VectorBox_Bool["Muon_isAddID"]);
    ssbtree->Branch("Muon_isIsoID", &VectorBox_Bool["Muon_isIsoID"]);
    ssbtree->Branch("Muon_isLoose", &VectorBox_Bool["Muon_isLoose"]);
    ssbtree->Branch("Muon_isMedium", &VectorBox_Bool["Muon_isMedium"]);
    ssbtree->Branch("Muon_isSoft", &VectorBox_Bool["Muon_isSoft"]);
    ssbtree->Branch("Muon_isTight", &VectorBox_Bool["Muon_isTight"]);
    ssbtree->Branch("Muon_isVetoID", &VectorBox_Bool["Muon_isVetoID"]);
    ssbtree->Branch("Muon_miniRelIso", &VectorBox_Double["Muon_miniRelIso"]);
    ssbtree->Branch("Muon_pdgId", &VectorBox_Int["Muon_pdgId"]);
    ssbtree->Branch("Num_MinusElectron", &VariableBox_Int["Num_MinusElectron"], "Num_MinusElectron/I");
    ssbtree->Branch("Num_MinusLepton", &VariableBox_Int["Num_MinusLepton"], "Num_MinusLepton/I");
    ssbtree->Branch("Num_MinusMuon", &VariableBox_Int["Num_MinusMuon"], "Num_MinusMuon/I");
    ssbtree->Branch("Num_PlusElectron", &VariableBox_Int["Num_PlusElectron"], "Num_PlusElectron/I");
    ssbtree->Branch("Num_PlusLepton", &VariableBox_Int["Num_PlusLepton"], "Num_PlusLepton/I");
    ssbtree->Branch("Num_PlusMuon", &VariableBox_Int["Num_PlusMuon"], "Num_PlusMuon/I");
    ssbtree->Branch("PV_Count", &VariableBox_Int["PV_Count"], "PV_Count/I");
    ssbtree->Branch("PileUpWeight", &VariableBox_Double["PileUpWeight"], "PileUpWeight/D");
    ssbtree->Branch("SYS_PileUp_down", &VariableBox_Double["SYS_PileUp_down"], "SYS_PileUp_down/D");
    ssbtree->Branch("SYS_PileUp_up", &VariableBox_Double["SYS_PileUp_up"], "SYS_PileUp_up/D");

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
    VariableBox_Bool["Cut_All_BaseLine"] = false;
    VariableBox_Bool["Cut_All_BaseLine2"] = false;
    VariableBox_Bool["Cut_All_SR1"] = false;
    VariableBox_Bool["Cut_All_SR2"] = false;
    VariableBox_Bool["Cut_All_SR3"] = false;
    VariableBox_Bool["Cut_All_SR4"] = false;
    VariableBox_Bool["Cut_All_SR5"] = false;
    VariableBox_Bool["Cut_All_SR6"] = false;
    VariableBox_Bool["Cut_All_SR7"] = false;
    VariableBox_Bool["Cut_All_SR8"] = false;
    VariableBox_Bool["Cut_All_SRW"] = false;
    VariableBox_Bool["Cut_All_SRZ"] = false;
    VariableBox_Bool["Cut_All_Step0a"] = false;
    VariableBox_Bool["Cut_All_Step0b"] = false;
    VariableBox_Bool["Cut_All_Step0c"] = false;
    VariableBox_Bool["Cut_All_Step0d"] = false;
    VariableBox_Bool["Cut_All_Step1a"] = false;
    VariableBox_Bool["Cut_All_Step1b"] = false;
    VariableBox_Int["Cut_BJet_Count"] = 0;
    VariableBox_LorentzVector["Cut_Elec"]->Clear();
    VectorBox_Double["Cut_Elec_ClosestJetdR"].clear();
    VectorBox_Double["Cut_Elec_MT"].clear();
    VectorBox_Double["Cut_Elec_PFIsodBeta03"].clear();
    VectorBox_Double["Cut_Elec_PFIsodBeta04"].clear();
    VectorBox_Double["Cut_Elec_Pt_rat"].clear();
    VectorBox_Double["Cut_Elec_Pt_rel"].clear();
    VectorBox_Double["Cut_Elec_Weight"].clear();
    VectorBox_Double["Cut_Elec_dxy"].clear();
    VectorBox_Double["Cut_Elec_dz"].clear();
    VectorBox_Double["Cut_Elec_miniRelIso"].clear();
    VariableBox_Bool["Cut_Event_Filter"] = false;
    VariableBox_LorentzVector["Cut_Jet"]->Clear();
    VectorBox_Double["Cut_Jet_BJetWeight"].clear();
    VariableBox_Int["Cut_Jet_Count"] = 0;
    VectorBox_Int["Cut_Jet_Index"].clear();
    VectorBox_Double["Cut_Jet_JERWeight"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_CFerr1_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_CFerr1_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_CFerr2_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_CFerr2_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HF_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HF_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HFstat1_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HFstat1_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HFstat2_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_HFstat2_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_JES_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_JES_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LF_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LF_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LFstat1_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LFstat1_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LFstat2_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_BJet_LFstat2_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_JER_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_JER_up"].clear();
    VectorBox_Double["Cut_Jet_SYS_JES_down"].clear();
    VectorBox_Double["Cut_Jet_SYS_JES_up"].clear();
    VectorBox_Bool["Cut_Jet_bTag"].clear();
    VariableBox_Bool["Cut_LeptonMass"] = false;
    VariableBox_Bool["Cut_MET"] = false;
    VariableBox_LorentzVector["Cut_Muon"]->Clear();
    VectorBox_Double["Cut_Muon_ClosestJetdR"].clear();
    VectorBox_Double["Cut_Muon_MT"].clear();
    VectorBox_Double["Cut_Muon_PFIsodBeta03"].clear();
    VectorBox_Double["Cut_Muon_PFIsodBeta04"].clear();
    VectorBox_Double["Cut_Muon_Pt_rat"].clear();
    VectorBox_Double["Cut_Muon_Pt_rel"].clear();
    VectorBox_Double["Cut_Muon_Weight"].clear();
    VectorBox_Double["Cut_Muon_dxy"].clear();
    VectorBox_Double["Cut_Muon_dz"].clear();
    VectorBox_Double["Cut_Muon_miniRelIso"].clear();
    VariableBox_Bool["Cut_Tri_Charge"] = false;
    VariableBox_Bool["Cut_Tri_First_Zmass"] = false;
    VariableBox_Bool["Cut_Tri_Second_Zmass"] = false;
    VariableBox_Bool["Cut_Tri_TriOrMore"] = false;
    VariableBox_Bool["Cut_Tri_ee"] = false;
    VariableBox_Bool["Cut_Tri_em"] = false;
    VariableBox_Bool["Cut_Tri_mm"] = false;
    VariableBox_Bool["Cut_dl_Opposite"] = false;
    VariableBox_Bool["Cut_dl_Same"] = false;
    VariableBox_Bool["Cut_e_Charge"] = false;
    VariableBox_Bool["Cut_e_ElectronVeto"] = false;
    VariableBox_Bool["Cut_e_MuonVeto"] = false;
    VariableBox_Bool["Cut_e_Trigger"] = false;
    VariableBox_Bool["Cut_ee_BaseLine"] = false;
    VariableBox_Bool["Cut_ee_BaseLine2"] = false;
    VariableBox_Bool["Cut_ee_LeptonPair"] = false;
    VariableBox_Bool["Cut_ee_LeptonPair_TightMass"] = false;
    VariableBox_Bool["Cut_ee_SR1"] = false;
    VariableBox_Bool["Cut_ee_SR2"] = false;
    VariableBox_Bool["Cut_ee_SR3"] = false;
    VariableBox_Bool["Cut_ee_SR4"] = false;
    VariableBox_Bool["Cut_ee_SR5"] = false;
    VariableBox_Bool["Cut_ee_SR6"] = false;
    VariableBox_Bool["Cut_ee_SR7"] = false;
    VariableBox_Bool["Cut_ee_SR8"] = false;
    VariableBox_Bool["Cut_ee_SRW"] = false;
    VariableBox_Bool["Cut_ee_SRZ"] = false;
    VariableBox_Bool["Cut_ee_Step0a"] = false;
    VariableBox_Bool["Cut_ee_Step0b"] = false;
    VariableBox_Bool["Cut_ee_Step0c"] = false;
    VariableBox_Bool["Cut_ee_Step0d"] = false;
    VariableBox_Bool["Cut_ee_Step1a"] = false;
    VariableBox_Bool["Cut_ee_Step1b"] = false;
    VariableBox_Bool["Cut_ej_ElectronIso"] = false;
    VariableBox_Bool["Cut_em_BaseLine"] = false;
    VariableBox_Bool["Cut_em_BaseLine2"] = false;
    VariableBox_Bool["Cut_em_LeptonPair"] = false;
    VariableBox_Bool["Cut_em_LeptonPair_TightMass"] = false;
    VariableBox_Bool["Cut_em_SR1"] = false;
    VariableBox_Bool["Cut_em_SR2"] = false;
    VariableBox_Bool["Cut_em_SR3"] = false;
    VariableBox_Bool["Cut_em_SR4"] = false;
    VariableBox_Bool["Cut_em_SR5"] = false;
    VariableBox_Bool["Cut_em_SR6"] = false;
    VariableBox_Bool["Cut_em_SR7"] = false;
    VariableBox_Bool["Cut_em_SR8"] = false;
    VariableBox_Bool["Cut_em_SRW"] = false;
    VariableBox_Bool["Cut_em_SRZ"] = false;
    VariableBox_Bool["Cut_em_Step0a"] = false;
    VariableBox_Bool["Cut_em_Step0b"] = false;
    VariableBox_Bool["Cut_em_Step0c"] = false;
    VariableBox_Bool["Cut_em_Step0d"] = false;
    VariableBox_Bool["Cut_em_Step1a"] = false;
    VariableBox_Bool["Cut_em_Step1b"] = false;
    VariableBox_Bool["Cut_em_Trigger"] = false;
    VariableBox_Bool["Cut_m_Charge"] = false;
    VariableBox_Bool["Cut_m_ElectronVeto"] = false;
    VariableBox_Bool["Cut_m_MuonVeto"] = false;
    VariableBox_Bool["Cut_m_Trigger"] = false;
    VariableBox_Bool["Cut_mj_MuonIso"] = false;
    VariableBox_Bool["Cut_mm_BaseLine"] = false;
    VariableBox_Bool["Cut_mm_BaseLine2"] = false;
    VariableBox_Bool["Cut_mm_LeptonPair"] = false;
    VariableBox_Bool["Cut_mm_LeptonPair_TightMass"] = false;
    VariableBox_Bool["Cut_mm_SR1"] = false;
    VariableBox_Bool["Cut_mm_SR2"] = false;
    VariableBox_Bool["Cut_mm_SR3"] = false;
    VariableBox_Bool["Cut_mm_SR4"] = false;
    VariableBox_Bool["Cut_mm_SR5"] = false;
    VariableBox_Bool["Cut_mm_SR6"] = false;
    VariableBox_Bool["Cut_mm_SR7"] = false;
    VariableBox_Bool["Cut_mm_SR8"] = false;
    VariableBox_Bool["Cut_mm_SRW"] = false;
    VariableBox_Bool["Cut_mm_SRZ"] = false;
    VariableBox_Bool["Cut_mm_Step0a"] = false;
    VariableBox_Bool["Cut_mm_Step0b"] = false;
    VariableBox_Bool["Cut_mm_Step0c"] = false;
    VariableBox_Bool["Cut_mm_Step0d"] = false;
    VariableBox_Bool["Cut_mm_Step1a"] = false;
    VariableBox_Bool["Cut_mm_Step1b"] = false;
    VariableBox_LorentzVector["Elec"]->Clear();
    VectorBox_Int["Elec_Charge"].clear();
    VectorBox_Bool["Elec_ChargeId_GsfCtfPx"].clear();
    VectorBox_Double["Elec_ClosestJetdR"].clear();
    VectorBox_Bool["Elec_Conversion"].clear();
    VariableBox_Int["Elec_Count"] = 0;
    VectorBox_Bool["Elec_Cut_Additional"].clear();
    VectorBox_Bool["Elec_Cut_Isolated"].clear();
    VectorBox_Bool["Elec_Cut_Veto"].clear();
    VectorBox_Double["Elec_MT"].clear();
    VectorBox_Double["Elec_PFIsodBeta03"].clear();
    VectorBox_Double["Elec_PFIsodBeta04"].clear();
    VectorBox_Double["Elec_Pt_rat"].clear();
    VectorBox_Double["Elec_Pt_rel"].clear();
    VectorBox_Double["Elec_Supercluster_Eta"].clear();
    VectorBox_Double["Elec_Weight"].clear();
    VectorBox_Double["Elec_dxy"].clear();
    VectorBox_Double["Elec_dz"].clear();
    VectorBox_Bool["Elec_isAddID"].clear();
    VectorBox_Bool["Elec_isIsoID"].clear();
    VectorBox_Bool["Elec_isLoose"].clear();
    VectorBox_Bool["Elec_isMedium"].clear();
    VectorBox_Bool["Elec_isTight"].clear();
    VectorBox_Bool["Elec_isVeto"].clear();
    VectorBox_Bool["Elec_isVetoID"].clear();
    VectorBox_Double["Elec_miniRelIso"].clear();
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
    VariableBox_Double["GenWeight"] = 0;
    VariableBox_Double["HM"] = 0;
    VariableBox_Double["HT"] = 0;
    VariableBox_LorentzVector["Jet"]->Clear();
    VectorBox_Double["Jet_BJetWeight"].clear();
    VariableBox_Int["Jet_Count"] = 0;
    VectorBox_Double["Jet_JERWeight"].clear();
    VectorBox_Double["Jet_SYS_BJet_CFerr1_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_CFerr1_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_CFerr2_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_CFerr2_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_HF_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_HF_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_HFstat1_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_HFstat1_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_HFstat2_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_HFstat2_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_JES_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_JES_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_LF_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_LF_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_LFstat1_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_LFstat1_up"].clear();
    VectorBox_Double["Jet_SYS_BJet_LFstat2_down"].clear();
    VectorBox_Double["Jet_SYS_BJet_LFstat2_up"].clear();
    VectorBox_Double["Jet_SYS_JER_down"].clear();
    VectorBox_Double["Jet_SYS_JER_up"].clear();
    VectorBox_Double["Jet_SYS_JES_down"].clear();
    VectorBox_Double["Jet_SYS_JES_up"].clear();
    VectorBox_Double["Jet_bDisc"].clear();
    VectorBox_Double["Jet_cDiscCvsB"].clear();
    VectorBox_Double["Jet_cDiscCvsL"].clear();
    VectorBox_Bool["Jet_isCleanedJet"].clear();
    VectorBox_Bool["Jet_isJetID"].clear();
    VectorBox_Double["Jet_qgLikelihood"].clear();
    VariableBox_Double["Lepton_Weight"] = 0;
    VariableBox_LorentzVector["MET"]->Clear();
    VariableBox_LorentzVector["Muon"]->Clear();
    VectorBox_Int["Muon_Charge"].clear();
    VectorBox_Double["Muon_ClosestJetdR"].clear();
    VectorBox_Double["Muon_CorrectedPt"].clear();
    VectorBox_Double["Muon_CorrectedPtError"].clear();
    VariableBox_Int["Muon_Count"] = 0;
    VectorBox_Bool["Muon_Cut_Additional"].clear();
    VectorBox_Bool["Muon_Cut_Isolated"].clear();
    VectorBox_Bool["Muon_Cut_Veto"].clear();
    VectorBox_Double["Muon_MT"].clear();
    VectorBox_Double["Muon_PFIsodBeta03"].clear();
    VectorBox_Double["Muon_PFIsodBeta04"].clear();
    VectorBox_Double["Muon_Pt_rat"].clear();
    VectorBox_Double["Muon_Pt_rel"].clear();
    VectorBox_Double["Muon_Weight"].clear();
    VectorBox_Double["Muon_dPtOverPt"].clear();
    VectorBox_Double["Muon_dxy"].clear();
    VectorBox_Double["Muon_dz"].clear();
    VectorBox_Bool["Muon_isAddID"].clear();
    VectorBox_Bool["Muon_isIsoID"].clear();
    VectorBox_Bool["Muon_isLoose"].clear();
    VectorBox_Bool["Muon_isMedium"].clear();
    VectorBox_Bool["Muon_isSoft"].clear();
    VectorBox_Bool["Muon_isTight"].clear();
    VectorBox_Bool["Muon_isVetoID"].clear();
    VectorBox_Double["Muon_miniRelIso"].clear();
    VectorBox_Int["Muon_pdgId"].clear();
    VariableBox_Int["Num_MinusElectron"] = 0;
    VariableBox_Int["Num_MinusLepton"] = 0;
    VariableBox_Int["Num_MinusMuon"] = 0;
    VariableBox_Int["Num_PlusElectron"] = 0;
    VariableBox_Int["Num_PlusLepton"] = 0;
    VariableBox_Int["Num_PlusMuon"] = 0;
    VariableBox_Int["PV_Count"] = 0;
    VariableBox_Double["PileUpWeight"] = 0;
    VariableBox_Double["SYS_PileUp_down"] = 0;
    VariableBox_Double["SYS_PileUp_up"] = 0;

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

