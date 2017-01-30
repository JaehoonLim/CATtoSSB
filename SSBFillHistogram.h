void
SSBConverter::FillHistogram()
{

    ssbhistManager->GetCutStep(Cut_ee_Step,Cut_mm_Step,Cut_em_Step);

    ssbhistManager->Fill( "numPV", numPV    );
    const cat::MET &met = mets->at(0);
    ssbhistManager->Fill( "MET",   met.pt() );

    if(Num_IsolatedElectron>0){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(0));
        ssbhistManager->Fill( "Elec_1_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "Elec_1_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "Elec_1_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "Elec_1_E",   IsoElectron.energy() );
    }
    if(Num_IsolatedElectron>1){
        const cat::Electron &IsoElectron = electrons->at(Index_IsolatedElectron.at(1));
        ssbhistManager->Fill( "Elec_2_Pt",  IsoElectron.pt()     );
        ssbhistManager->Fill( "Elec_2_Eta", IsoElectron.eta()    );
        ssbhistManager->Fill( "Elec_2_Phi", IsoElectron.phi()    );
        ssbhistManager->Fill( "Elec_2_E",   IsoElectron.energy() );
    }
    if(Num_IsolatedMuon>0){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(0));
        ssbhistManager->Fill( "Muon_1_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "Muon_1_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "Muon_1_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "Muon_1_E",   IsoMuon.energy() );
    }
    if(Num_IsolatedMuon>1){
        const cat::Muon &IsoMuon = muons->at(Index_IsolatedMuon.at(1));
        ssbhistManager->Fill( "Muon_2_Pt",  IsoMuon.pt()     );
        ssbhistManager->Fill( "Muon_2_Eta", IsoMuon.eta()    );
        ssbhistManager->Fill( "Muon_2_Phi", IsoMuon.phi()    );
        ssbhistManager->Fill( "Muon_2_E",   IsoMuon.energy() );
    }
    if(Num_PlusLepton+Num_MinusLepton == 2){
        ssbhistManager->Fill( "InvMass", LV_AllLepton.M() );
    }

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
    }
    if(Num_CleanedJet>1){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(1));
        ssbhistManager->Fill( "Jet_2_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_2_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_2_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_2_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_2_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
    }
    if(Num_CleanedJet>2){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(2));
        ssbhistManager->Fill( "Jet_3_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_3_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_3_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_3_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_3_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
    }
    if(Num_CleanedJet>3){
        const cat::Jet &CleanedJet = jets->at(Index_CleanedJet.at(3));
        ssbhistManager->Fill( "Jet_4_Pt",  CleanedJet.pt()     );
        ssbhistManager->Fill( "Jet_4_Eta", CleanedJet.eta()    );
        ssbhistManager->Fill( "Jet_4_Phi", CleanedJet.phi()    );
        ssbhistManager->Fill( "Jet_4_E",   CleanedJet.energy() );
        ssbhistManager->Fill( "Jet_4_CSV", CleanedJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
    }

    if(Num_BJet>0){
        const cat::Jet &BJet = jets->at(Index_BJet.at(0));
        ssbhistManager->Fill( "BJet_1_Pt",  BJet.pt()     );
        ssbhistManager->Fill( "BJet_1_Eta", BJet.eta()    );
        ssbhistManager->Fill( "BJet_1_Phi", BJet.phi()    );
        ssbhistManager->Fill( "BJet_1_E",   BJet.energy() );
        ssbhistManager->Fill( "BJet_1_CSV", BJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
    }
    if(Num_BJet>1){
        const cat::Jet &BJet = jets->at(Index_BJet.at(1));
        ssbhistManager->Fill( "BJet_2_Pt",  BJet.pt()     );
        ssbhistManager->Fill( "BJet_2_Eta", BJet.eta()    );
        ssbhistManager->Fill( "BJet_2_Phi", BJet.phi()    );
        ssbhistManager->Fill( "BJet_2_E",   BJet.energy() );
        ssbhistManager->Fill( "BJet_2_CSV", BJet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags") );
    }

}
