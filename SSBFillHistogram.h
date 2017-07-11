void SSBConverter::FillHistogram()
{

    ssbhistManager->CheckData(isData);
    if(Channel == "FourTop Tri-Lepton"){
        for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
            ssbhistManager->GetCutStep(CutChannelName[CutChannelInit],Cut_Step[CutChannelName[CutChannelInit]]);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0a", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0b", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0c", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "2",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "3",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "4",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "5",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "6a", GenWeight*PileUpWeight*LeptonWeight);//*AddLeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "6b", GenWeight*PileUpWeight*LeptonWeight);//*AddLeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "7",  GenWeight*PileUpWeight*LeptonWeight);//*AddLeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "8",  GenWeight*PileUpWeight*LeptonWeight);//*AddLeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "9",  GenWeight*PileUpWeight*LeptonWeight);//*AddLeptonWeight);
        }
    } // if(Channel == "FourTop Tri-Lepton")
    else if(Channel == "FourTop SS Di-Lepton"){
        for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
            ssbhistManager->GetCutStep(CutChannelName[CutChannelInit],Cut_Step[CutChannelName[CutChannelInit]]);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0a", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0b", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0c", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1a", GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1b", GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "2",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "3",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "4",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "5",  GenWeight*PileUpWeight*LeptonWeight);
        }
    }
    else if(Channel == "Lepton+Jets"){
        for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
            ssbhistManager->GetCutStep(CutChannelName[CutChannelInit],Cut_Step[CutChannelName[CutChannelInit]]);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0a", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0b", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0c", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1a", GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1b", GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "2",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "3",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "4",  GenWeight*PileUpWeight*LeptonWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "5",  GenWeight*PileUpWeight*LeptonWeight);
        }
    }
    else if(Channel == "FourTop SUSY"){
        for(unsigned int CutChannelInit=0;CutChannelInit<CutChannelName.size();++CutChannelInit){
            ssbhistManager->GetCutStep(CutChannelName[CutChannelInit],Cut_Step[CutChannelName[CutChannelInit]]);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0a", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0b", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0c", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "0d", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1a", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SRW", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR1", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR2", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR3", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR4", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR5", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR6", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "1b", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR7", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SR8", GenWeight*PileUpWeight);
            ssbhistManager->SetWeight(CutChannelName[CutChannelInit], "SRZ", GenWeight*PileUpWeight);
        }
    }

    ssbhistManager->Fill( "numPV", numPV);
    const cat::MET &met = mets->at(0);
    ssbhistManager->Fill( "MET",   met.pt());

    if(Num_IsolatedElectron>0){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(0));
        ssbhistManager->Fill( "Elec_1_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "Elec_1_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "Elec_1_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "Elec_1_E",   IsoElectron.energy() );
        ssbhistManager->Fill( "Elec_1_Iso03",    v_Elec_Iso03.at(Index_IsolatedElectron.at(0))    );
        ssbhistManager->Fill( "Elec_1_Iso04",    v_Elec_Iso04.at(Index_IsolatedElectron.at(0))    );
        ssbhistManager->Fill( "Elec_1_miniIso",  v_Elec_miniIso.at(Index_IsolatedElectron.at(0))  );
        ssbhistManager->Fill( "Elec_1_Pt_rel",   v_Elec_Pt_rel.at(Index_IsolatedElectron.at(0))   );
        ssbhistManager->Fill( "Elec_1_Pt_ratio", v_Elec_Pt_ratio.at(Index_IsolatedElectron.at(0)) );
    }
    if(Num_IsolatedElectron>1){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(1));
        ssbhistManager->Fill( "Elec_2_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "Elec_2_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "Elec_2_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "Elec_2_E",   IsoElectron.energy() );
        ssbhistManager->Fill( "Elec_2_Iso03",    v_Elec_Iso03.at(Index_IsolatedElectron.at(1))    );
        ssbhistManager->Fill( "Elec_2_Iso04",    v_Elec_Iso04.at(Index_IsolatedElectron.at(1))    );
        ssbhistManager->Fill( "Elec_2_miniIso",  v_Elec_miniIso.at(Index_IsolatedElectron.at(1))  );
        ssbhistManager->Fill( "Elec_2_Pt_rel",   v_Elec_Pt_rel.at(Index_IsolatedElectron.at(1))   );
        ssbhistManager->Fill( "Elec_2_Pt_ratio", v_Elec_Pt_ratio.at(Index_IsolatedElectron.at(1)) );
    }
    if(Num_IsolatedElectron>2){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(2));
        ssbhistManager->Fill( "Elec_3_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "Elec_3_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "Elec_3_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "Elec_3_E",   IsoElectron.energy() );
        ssbhistManager->Fill( "Elec_3_Iso03",    v_Elec_Iso03.at(Index_IsolatedElectron.at(2))    );
        ssbhistManager->Fill( "Elec_3_Iso04",    v_Elec_Iso04.at(Index_IsolatedElectron.at(2))    );
        ssbhistManager->Fill( "Elec_3_miniIso",  v_Elec_miniIso.at(Index_IsolatedElectron.at(2))  );
        ssbhistManager->Fill( "Elec_3_Pt_rel",   v_Elec_Pt_rel.at(Index_IsolatedElectron.at(2))   );
        ssbhistManager->Fill( "Elec_3_Pt_ratio", v_Elec_Pt_ratio.at(Index_IsolatedElectron.at(2)) );
    }
    if(Num_AdditionalElectron>0){
        const cat::Electron &IsoElectron = electrons->at(Index_AdditionalElectron.at(0));
        ssbhistManager->Fill( "AddElec_1_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "AddElec_1_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "AddElec_1_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "AddElec_1_E",   IsoElectron.energy() );
        ssbhistManager->Fill( "AddElec_1_Iso03",    v_Elec_Iso03.at(Index_AdditionalElectron.at(0))    );
        ssbhistManager->Fill( "AddElec_1_Iso04",    v_Elec_Iso04.at(Index_AdditionalElectron.at(0))    );
        ssbhistManager->Fill( "AddElec_1_miniIso",  v_Elec_miniIso.at(Index_AdditionalElectron.at(0))  );
        ssbhistManager->Fill( "AddElec_1_Pt_rel",   v_Elec_Pt_rel.at(Index_AdditionalElectron.at(0))   );
        ssbhistManager->Fill( "AddElec_1_Pt_ratio", v_Elec_Pt_ratio.at(Index_AdditionalElectron.at(0)) );
    }

    if(Num_IsolatedMuon>0){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(0));
        ssbhistManager->Fill( "Muon_1_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "Muon_1_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "Muon_1_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "Muon_1_E",   IsoMuon.energy() );
        ssbhistManager->Fill( "Muon_1_Iso03",    v_Muon_Iso03.at(Index_IsolatedMuon.at(0))    );
        ssbhistManager->Fill( "Muon_1_Iso04",    v_Muon_Iso04.at(Index_IsolatedMuon.at(0))    );
        ssbhistManager->Fill( "Muon_1_miniIso",  v_Muon_miniIso.at(Index_IsolatedMuon.at(0))  );
        ssbhistManager->Fill( "Muon_1_Pt_rel",   v_Muon_Pt_rel.at(Index_IsolatedMuon.at(0))   );
        ssbhistManager->Fill( "Muon_1_Pt_ratio", v_Muon_Pt_ratio.at(Index_IsolatedMuon.at(0)) );
    }
    if(Num_IsolatedMuon>1){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(1));
        ssbhistManager->Fill( "Muon_2_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "Muon_2_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "Muon_2_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "Muon_2_E",   IsoMuon.energy() );
        ssbhistManager->Fill( "Muon_2_Iso03",    v_Muon_Iso03.at(Index_IsolatedMuon.at(1))    );
        ssbhistManager->Fill( "Muon_2_Iso04",    v_Muon_Iso04.at(Index_IsolatedMuon.at(1))    );
        ssbhistManager->Fill( "Muon_2_miniIso",  v_Muon_miniIso.at(Index_IsolatedMuon.at(1))  );
        ssbhistManager->Fill( "Muon_2_Pt_rel",   v_Muon_Pt_rel.at(Index_IsolatedMuon.at(1))   );
        ssbhistManager->Fill( "Muon_2_Pt_ratio", v_Muon_Pt_ratio.at(Index_IsolatedMuon.at(1)) );
    }
    if(Num_IsolatedMuon>2){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(2));
        ssbhistManager->Fill( "Muon_3_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "Muon_3_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "Muon_3_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "Muon_3_E",   IsoMuon.energy() );
        ssbhistManager->Fill( "Muon_3_Iso03",    v_Muon_Iso03.at(Index_IsolatedMuon.at(2))    );
        ssbhistManager->Fill( "Muon_3_Iso04",    v_Muon_Iso04.at(Index_IsolatedMuon.at(2))    );
        ssbhistManager->Fill( "Muon_3_miniIso",  v_Muon_miniIso.at(Index_IsolatedMuon.at(2))  );
        ssbhistManager->Fill( "Muon_3_Pt_rel",   v_Muon_Pt_rel.at(Index_IsolatedMuon.at(2))   );
        ssbhistManager->Fill( "Muon_3_Pt_ratio", v_Muon_Pt_ratio.at(Index_IsolatedMuon.at(2)) );
    }
    if(Num_AdditionalMuon>0){
        const cat::Muon &IsoMuon = muons->at(Index_AdditionalMuon.at(0));
        ssbhistManager->Fill( "AddMuon_1_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "AddMuon_1_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "AddMuon_1_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "AddMuon_1_E",   IsoMuon.energy() );
        ssbhistManager->Fill( "AddMuon_1_Iso03",    v_Muon_Iso03.at(Index_AdditionalMuon.at(0))    );
        ssbhistManager->Fill( "AddMuon_1_Iso04",    v_Muon_Iso04.at(Index_AdditionalMuon.at(0))    );
        ssbhistManager->Fill( "AddMuon_1_miniIso",  v_Muon_miniIso.at(Index_AdditionalMuon.at(0))  );
        ssbhistManager->Fill( "AddMuon_1_Pt_rel",   v_Muon_Pt_rel.at(Index_AdditionalMuon.at(0))   );
        ssbhistManager->Fill( "AddMuon_1_Pt_ratio", v_Muon_Pt_ratio.at(Index_AdditionalMuon.at(0)) );
    }

    ssbhistManager->Fill( "AllLepton_InvMass",  LV_AllLepton.M() );
    ssbhistManager->Fill( "DiLepton_InvMass1", DiLeptonMass1    );
    ssbhistManager->Fill( "DiLepton_InvMass2", DiLeptonMass2    );
    ssbhistManager->Fill( "DiLepton_InvMass3", DiLeptonMass3    );
     
    ssbhistManager->Fill( "numJets",  Num_CleanedJet );
    ssbhistManager->Fill( "numBJets", Num_BJet       );
    ssbhistManager->Fill( "HT",       HT             );
    ssbhistManager->Fill( "HM",       HM             );

    if(Num_CleanedJet>0){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(0));
        ssbhistManager->Fill( "Jet_1_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_1_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_1_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_1_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_1_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "Jet_1_qg",  CleanedJet.qgLikelihood() );
    }
    if(Num_CleanedJet>1){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(1));
        ssbhistManager->Fill( "Jet_2_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_2_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_2_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_2_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_2_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "Jet_2_qg",  CleanedJet.qgLikelihood() );
    }
    if(Num_CleanedJet>2){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(2));
        ssbhistManager->Fill( "Jet_3_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_3_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_3_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_3_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_3_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "Jet_3_qg",  CleanedJet.qgLikelihood() );
    }
    if(Num_CleanedJet>3){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(3));
        ssbhistManager->Fill( "Jet_4_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_4_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_4_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_4_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_4_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "Jet_4_qg",  CleanedJet.qgLikelihood() );
    }

    if(Num_BJet>0){
        const cat::Jet &BJet = jets->at(Index_BJet.at(0));
        ssbhistManager->Fill( "BJet_1_Pt",  BJet.pt()     );
        ssbhistManager->Fill( "BJet_1_Eta", BJet.eta()    );
        ssbhistManager->Fill( "BJet_1_Phi", BJet.phi()    );
        ssbhistManager->Fill( "BJet_1_E",   BJet.energy() );
        ssbhistManager->Fill( "BJet_1_CSV", BJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "BJet_1_qg",  BJet.qgLikelihood() );
    }
    if(Num_BJet>1){
        const cat::Jet &BJet = jets->at(Index_BJet.at(1));
        ssbhistManager->Fill( "BJet_2_Pt",  BJet.pt()     );
        ssbhistManager->Fill( "BJet_2_Eta", BJet.eta()    );
        ssbhistManager->Fill( "BJet_2_Phi", BJet.phi()    );
        ssbhistManager->Fill( "BJet_2_E",   BJet.energy() );
        ssbhistManager->Fill( "BJet_2_CSV", BJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "BJet_2_qg",  BJet.qgLikelihood() );
    }
    if(Num_BJet>2){
        const cat::Jet &BJet = jets->at(Index_BJet.at(2));
        ssbhistManager->Fill( "BJet_3_Pt",  BJet.pt()     );
        ssbhistManager->Fill( "BJet_3_Eta", BJet.eta()    );
        ssbhistManager->Fill( "BJet_3_Phi", BJet.phi()    );
        ssbhistManager->Fill( "BJet_3_E",   BJet.energy() );
        ssbhistManager->Fill( "BJet_3_CSV", BJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
        ssbhistManager->Fill( "BJet_3_qg",  BJet.qgLikelihood() );
    }


}
