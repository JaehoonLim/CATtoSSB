// -*- C++ -*-
//
// Package:    SSBGenInfor
// Class:      SSBGenInfor
// 
/**\class SSBGenInfor SSBGenInfor.cc CMSAnalyses/SSBGenInfor/plugins/SSBGenInfor.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Seungkyu Ha, Sehwook Lee, Suyoung Choi, Jaehoon Lim, 588 R-004, +41227678602
//         Created:  Mon Dec 29 10:42:18 KST 2014
// $Id$
//
//

#include "SSBGenInfor.h"

SSBGenInfor::SSBGenInfor(const edm::ParameterSet& iConfig)
:
CheckBG(iConfig.getUntrackedParameter< std::vector<std::string> >( "CheckBG" ))
{
    //now do what ever initialization is needed
    //if (isMC == true) 
    //{
        genParInfoTag = consumes<reco::GenParticleCollection>(iConfig.getParameter<edm::InputTag>("genParTag"));
        genJetInfoTag = consumes<reco::GenJetCollection>     (iConfig.getParameter<edm::InputTag>("genJetTag"));
    //}

}


SSBGenInfor::~SSBGenInfor()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}
//
// member functions
//
// ------------ method called for each event  ------------
void
SSBGenInfor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    ssbtreeManager->GenInitializeVariables();

    Event = -999;
    Run = -999;
    Lumi = -999;
    isData = false;

    Event = iEvent.id().event();
    Run = iEvent.id().run();
    Lumi = iEvent.id().luminosityBlock();
    isData = iEvent.isRealData();

    ssbtreeManager->Fill( "Info_EventNumber", Event  );
    ssbtreeManager->Fill( "Info_RunNumber"  , Run    ); 
    ssbtreeManager->Fill( "Info_Luminosity" , Lumi   ); 
    ssbtreeManager->Fill( "Info_isData"     , isData ); 

    if (isData == false )
    {
/*
       //////////////////////////////
       /// Generator Event Weight ///
       //////////////////////////////
*/
       ////////////////////////////////
       /// Generator Particle Info. ///
       ////////////////////////////////

        GenPar(iEvent, ssbtreeManager);
//       cout << "Finished GenPar ---" << endl;

        GenJet(iEvent, ssbtreeManager);
//       cout << "Finished GenJet ---" << endl;
        
    }
    ssbtreeManager->FillNtuple();
   
}

// ------------ method called once each job just before starting event loop  ------------
void 
SSBGenInfor::beginJob()
{
   ssbtree = ssbfs->make<TTree>("SSBGenTree", "Tree for Physics Analyses at CMS");
   ssbtreeManager = new SSBTreeManager();
   ssbtreeManager->GenBook(ssbtree);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SSBGenInfor::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
SSBGenInfor::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
SSBGenInfor::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
SSBGenInfor::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
SSBGenInfor::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
SSBGenInfor::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

void
SSBGenInfor::GenPar(const edm::Event& iEvent, SSBTreeManager* ssbtreeManager) {

    debug_cout = false;
    
    ////////////////////////////////////////////
    /// Generator Level Particle Information ///
    ////////////////////////////////////////////

    /// PYTHIA Event Histroy !! 
    edm::Handle<GenParticleCollection> genParticles;
    iEvent.getByToken(genParInfoTag, genParticles); /* get genParticle information */

    InitializeGenPar(); /* initialize vector and map */
    isTop = false;
    NTop = 0;
    //NBoson = 0;
    bool next_t    = false;
    bool next_tbar = false;

    GenParticleCollection::const_iterator itGenParBegin = genParticles->begin();

    vector<const reco::Candidate *> cands; /* reco::Candidate vector (mother and daugher function return reco::Candidate) */
    for ( GenParticleCollection::const_iterator itGenParIndex = genParticles->begin(); itGenParIndex != genParticles->end(); ++itGenParIndex )
    {
	cands.push_back(&*itGenParIndex);
        if(itGenParIndex->status() == 62 && (itGenParIndex->pdgId() == 6 || itGenParIndex->pdgId() == -6)) ++NTop; 
    } /* use for mother and daughter index */
    for(auto CheckBG_i : CheckBG){
        if ( CheckBG_i != "ALL" && NTop > 0) isTop = true;
    }

    for ( GenParticleCollection::const_iterator itGenPar = genParticles->begin(); itGenPar != genParticles->end(); itGenPar++ )
    {
        if(itGenPar->status() == 62 && (itGenPar->pdgId() == 6 || itGenPar->pdgId() == -6)) { 
        if(NTop ==  1){ ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 0 );
        } else if(NTop ==  2){
        if(itGenPar->pdgId() ==  6) ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 0 );
        if(itGenPar->pdgId() == -6) ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 1 );
        } else if(NTop ==  3){
        if(itGenPar->pdgId() ==  6 && !next_t) {
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 0 );
                        next_t = true;}
        else if(itGenPar->pdgId() == -6 && !next_tbar) { 
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 1 );
                        next_tbar = true;}
        else if((itGenPar->pdgId() ==  6 &&  next_t) || (itGenPar->pdgId() == -6 && !next_tbar)) {
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 2 );}
        } else if(NTop ==  4){
        if(itGenPar->pdgId() ==  6 && !next_t) {
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 0 );
                        next_t = true;}
        else if(itGenPar->pdgId() ==  6 &&  next_t) {
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 1 );}
        else if(itGenPar->pdgId() == -6 && !next_tbar) { 
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 2 );
                        next_tbar = true;}
        else if(itGenPar->pdgId() == -6 &&  next_tbar) {
                        ssbtreeManager->Fill( "GenTop", itGenPar->pt(), itGenPar->eta(), itGenPar->phi(), itGenPar->energy(), 3 );}
        } else {
	    cerr << "!!!!! Top Sample : NTop Error : " << NTop << " !!!!!" << endl;
	    cout << "!!!!! Top Sample : NTop Error : " << NTop << " !!!!!" << endl;
        }
        }
	int GenParIndex = itGenPar - itGenParBegin; /* get index */
	OriginalMom.clear();
	for ( unsigned int N_Mother = 0; N_Mother < itGenPar->numberOfMothers(); ++N_Mother ){
	    OriginalMom.push_back(find(cands.begin(), cands.end(), itGenPar->mother(N_Mother)) - cands.begin());
	} /* get all mother's index */
	OriginalDau.clear();
	for ( unsigned int N_Daughter = 0; N_Daughter < itGenPar->numberOfDaughters(); ++N_Daughter ){
	    OriginalDau.push_back(find(cands.begin(), cands.end(), itGenPar->daughter(N_Daughter)) - cands.begin());
	} /* get all daughter's index */

	AllParMom[GenParIndex] = OriginalMom; /* make mother index map */
	AllParDau[GenParIndex] = OriginalDau; /* make daughter index map */

	pdgId_status.clear();
	pdgId_status.push_back(itGenPar->pdgId());
	pdgId_status.push_back(itGenPar->status());
	AllParInfo[GenParIndex] = pdgId_status; /* make pdgid and status map */
	if ( (itGenPar->status() > 21 && itGenPar->status() < 24) ) { /* without proton */
		TreePar.push_back(GenParIndex); /* get tree level particles */
		if ( abs(itGenPar->pdgId()) == 6 ) {
                    if ( SelectedpdgId.find(itGenPar->pdgId()) == SelectedpdgId.end() ) {
			SelectedpdgId[itGenPar->pdgId()] = GenParIndex; /* save index of top */
		    } else {
			SelectedpdgId_FT[itGenPar->pdgId()] = GenParIndex; /* For four top sample */
		    }
		}
	} 

	if ( (itGenPar->status() == 1 || itGenPar->status() == 2) &&
	     (abs(itGenPar->pdgId()) > 10 && abs(itGenPar->pdgId()) < 17) ) {
		FinalPar.push_back(GenParIndex); /* put final state and intermediate lepton and neutrino*/
	}
    }/* genpar loop end */

    if(debug_cout){
    cout << endl << "line 235 TreePar : " << endl;
        for (unsigned int i = 0; i < TreePar.size(); ++i){
            cout << ParName[AllParInfo[TreePar.at(i)].at(0)] << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < TreePar.size(); ++i){
	    cout << TreePar.at(i) << " ";
	}
    cout << endl;
    }

    if (isTop) {
    for (int FinaltoTree = 0; FinaltoTree < (int)FinalPar.size(); ++FinaltoTree){
        int temp_boson = abs( AllParInfo[AllParMom[FinalPar.at(FinaltoTree)].at(0)].at(0) );
	if ( temp_boson == 23 || temp_boson == 24 || temp_boson == 25 ){ /* when First Mother is W,Z,H */
	    TreePar.push_back(FinalPar.at(FinaltoTree));
	    FinalPar.erase(find(FinalPar.begin(), FinalPar.end(), FinalPar.at(FinaltoTree)));
	    --FinaltoTree;
	}
    } /* Move final state particle (from W,Z,H decay) */

    if(debug_cout){
    cout << endl << "line 257 TreePar : " << endl;
        for (unsigned int i = 0; i < TreePar.size(); ++i){
            cout << ParName[AllParInfo[TreePar.at(i)].at(0)] << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < TreePar.size(); ++i){
	    cout << TreePar.at(i) << " ";
	}
    cout << endl;
    }

    int temp_Windex, temp_Bindex, temp_index;
    vector<int> temp_lqindex;

    //SelectedPar.push_back(0);
    //SelectedPar.push_back(1);
    FillGenPar(0, -1, -1, -1, -1, itGenParBegin, ssbtreeManager);
    FillGenPar(1, -1, -1, -1, -1, itGenParBegin, ssbtreeManager);
    FillGenPar(2, -1, -1, -1, -1, itGenParBegin, ssbtreeManager);
    FillGenPar(3, -1, -1, -1, -1, itGenParBegin, ssbtreeManager);

    vector<int> AllTop;
    AllTop.clear();
    int Wid = 24;
    int Bid =  5; 
    if (    SelectedpdgId.find(6) != SelectedpdgId.end())    { AllTop.push_back(SelectedpdgId[6]); }     else { AllTop.push_back(-999); }
    if ( SelectedpdgId_FT.find(6) != SelectedpdgId_FT.end()) { AllTop.push_back(SelectedpdgId_FT[6]); }  else { AllTop.push_back(-999); }
    if (   SelectedpdgId.find(-6) != SelectedpdgId.end())    { AllTop.push_back(SelectedpdgId[-6]); }    else { AllTop.push_back(-999); }
    if (SelectedpdgId_FT.find(-6) != SelectedpdgId_FT.end()) { AllTop.push_back(SelectedpdgId_FT[-6]); } else { AllTop.push_back(-999); }
   
    for (int TopLoop = 0; TopLoop < 4; ++TopLoop){
    if (TopLoop > 1) {Wid = -24; Bid = -5;}
    if (AllTop.at(TopLoop) != -999) {
    temp_Windex = 0;
    temp_Bindex = 0;
    temp_index  = 0;
    temp_lqindex.clear();
    SelectedPar.push_back(AllTop.at(TopLoop));   	
    temp_Windex = IndexLinker(AllParDau, AllTop.at(TopLoop), 0, -999, Wid, 22);
    SelectedPar.push_back( temp_Windex );	
    TreePar.erase(find(TreePar.begin(), TreePar.end(), temp_Windex));
    temp_Bindex = IndexLinker(AllParDau, AllTop.at(TopLoop), 0, -999, Bid, 23);
    if(temp_Bindex == -1) {
        cout << "Can not find  b-quark from top!" << endl;
        cerr << "Can not find  b-quark from top!" << endl;
        temp_Bindex = IndexLinker(AllParDau, AllTop.at(TopLoop), 0, -999, (int)Bid/5*3, 23);
        if(temp_Bindex != -1) cout << "This Event is t to Ws" << endl;
    }
    if(temp_Bindex == -1) {
        temp_Bindex = IndexLinker(AllParDau, AllTop.at(TopLoop), 0, -999, (int)Bid/3,   23);
        if(temp_Bindex != -1) cout << "This Event is t to Wd" << endl;
    }
    SelectedPar.push_back( temp_Bindex );
    TreePar.erase(find(TreePar.begin(), TreePar.end(), temp_Bindex));
    for (int TreeLoop = 0; TreeLoop < (int)TreePar.size(); ++TreeLoop){
        temp_index = IndexLinker(AllParDau, temp_Windex, 0, TreePar.at(TreeLoop));
	if( temp_index != -1 ) {
            temp_lqindex.push_back( temp_index );
	    SelectedPar.push_back( temp_index );
            TreePar.erase(find(TreePar.begin(), TreePar.end(), temp_index));
            --TreeLoop;
        }
    }
    FillGenPar(AllTop.at(TopLoop), AllParMom[AllTop.at(TopLoop)].at(0), AllParMom[AllTop.at(TopLoop)].at(1), temp_Windex, temp_Bindex, itGenParBegin, ssbtreeManager);
    FillGenPar(temp_Windex, AllTop.at(TopLoop), -1, temp_lqindex.at(0), temp_lqindex.at(1), itGenParBegin, ssbtreeManager);
    FillGenPar(temp_Bindex, AllTop.at(TopLoop), -1, -1, -1, itGenParBegin, ssbtreeManager);
    FillGenPar(temp_lqindex.at(0), temp_Windex, -1, -1, -1, itGenParBegin, ssbtreeManager);
    FillGenPar(temp_lqindex.at(1), temp_Windex, -1, -1, -1, itGenParBegin, ssbtreeManager);
    } // if (AllTop.at(TopLoop) != -999)
    } // for (int TopLoop = 0; TopLoop < 4; ++TopLoop)
    bool removeMom = false;
    for (int TreeLoopM = 0; TreeLoopM < (int)TreePar.size(); ++TreeLoopM){
        removeMom = false;
        for (int TreeLoopD = 0; TreeLoopD < (int)TreePar.size(); ++TreeLoopD){
            if(TreeLoopM != TreeLoopD){
                temp_index = IndexLinker(AllParDau, TreePar.at(TreeLoopM), 0, TreePar.at(TreeLoopD));
                if( temp_index != -1 ) {
                    if(!removeMom) {
                        removeMom = true;
                        SelectedPar.push_back( TreePar.at(TreeLoopM) );
                    }
    	            SelectedPar.push_back( temp_index );
                    TreePar.erase(find(TreePar.begin(), TreePar.end(), temp_index));
                    --TreeLoopD;
                    if(TreeLoopD<TreeLoopM) --TreeLoopM;
                }
            }
        } // TreeLoopD
        if(removeMom) {
            TreePar.erase(find(TreePar.begin(), TreePar.end(), TreePar.at(TreeLoopM)));
            --TreeLoopM;
        }
    } // TreeLoopM
    } // if (isTop) 

    else { /* if Background start */
    SelectedPar.push_back(0);
    SelectedPar.push_back(1);
    SelectedPar.push_back(2);
    SelectedPar.push_back(3);
    for (int TreetoSel = 0; TreetoSel < (int)TreePar.size(); ++TreetoSel){
	SelectedPar.push_back(TreePar.at(TreetoSel));
 	TreePar.erase(find(TreePar.begin(), TreePar.end(), TreePar.at(TreetoSel)));
	--TreetoSel;
    }
    for (int FinaltoTree = 0; FinaltoTree < (int)FinalPar.size(); ++FinaltoTree){
	int MompdgId = abs(AllParInfo[AllParMom[FinalPar.at(FinaltoTree)].at(0)].at(0));
	if ( MompdgId == 6 || MompdgId == 23 || MompdgId == 24 || MompdgId == 25 ){
	    TreePar.push_back(FinalPar.at(FinaltoTree));
	    FinalPar.erase(find(FinalPar.begin(), FinalPar.end(), FinalPar.at(FinaltoTree)));
	    --FinaltoTree;
	}
    }

    for (int TreetoSel = 0; TreetoSel < (int)TreePar.size(); ++TreetoSel){
	for (int SelectedSize = 0; SelectedSize < (int)SelectedPar.size(); ++SelectedSize){
	    int SelectedpdgId = abs(AllParInfo[SelectedPar.at(SelectedSize)].at(0));
	    if ( SelectedpdgId == 6 || SelectedpdgId == 23 || SelectedpdgId == 24 || SelectedpdgId == 25 ) { /* Mother : top, Z, W, H */
		if (IndexLinker(AllParMom, TreePar.at(TreetoSel), 0, SelectedPar.at(SelectedSize)) != -1 ) { /* when Mother is in SelectedPar */
		    SelectedPar.push_back(TreePar.at(TreetoSel));
		    TreePar.erase(find(TreePar.begin(), TreePar.end(), TreePar.at(TreetoSel)));
		    --TreetoSel;
		    break;
		}
	    }
	}
    } /* Move final state particle */

    for (int AllSel = 0; AllSel < (int)SelectedPar.size(); ++AllSel) {
	int FM = -1;	
	int SM = -1;	
	int FD = -1;	
	int SD = -1;	
	if ( AllParMom[SelectedPar[AllSel]].size() > 0 ) {
	    FM = AllParMom[SelectedPar[AllSel]].at(0);
	    if ( AllParMom[SelectedPar[AllSel]].size() == 2 ) {
		SM = AllParMom[SelectedPar[AllSel]].at(1);
	    }
	}
	if ( AllParDau[SelectedPar[AllSel]].size() > 0 ) {
	    FD = AllParDau[SelectedPar[AllSel]].at(0);
	    if ( AllParDau[SelectedPar[AllSel]].size() == 2 ) {
		SD = AllParDau[SelectedPar[AllSel]].at(1);
	    }
	}

	FillGenPar(SelectedPar[AllSel], FM, SM, FD, SD, itGenParBegin, ssbtreeManager);
    } /* Fill All Par */

    } /* if Background end */

    for (int RemoveTwo = 0; RemoveTwo < (int)FinalPar.size(); ++RemoveTwo){
	if ( AllParInfo[FinalPar.at(RemoveTwo)].at(1) == 2 ) {
	    //for (unsigned int RemoveTwoSub = 0; RemoveTwoSub < FinalPar.size(); ++RemoveTwoSub){
		//if (RemoveTwo != RemoveTwoSub && IndexLinker(AllParDau, FinalPar.at(RemoveTwo), 0, FinalPar.at(RemoveTwoSub)) != -1) {
		    FinalPar.erase(find(FinalPar.begin(), FinalPar.end(), FinalPar.at(RemoveTwo)));
		    --RemoveTwo;
		    //break;
		//}
	    //}
	}
    } /* my original idea was remove status 2 particle if final state particle form this status 2 particle is in FinalPar */

/*    for (unsigned int RemoveNu = 0; RemoveNu < FinalPar.size(); ++RemoveNu){
        int Nu_pdgId = abs(AllParInfo[FinalPar.at(RemoveNu)].at(0));
	if ( Nu_pdgId == 12 || Nu_pdgId == 14 || Nu_pdgId == 16 ) {
		    FinalPar.erase(find(FinalPar.begin(), FinalPar.end(), FinalPar.at(RemoveNu)));
		    --RemoveNu;
	}
    } * remove neutrinos in FinalPar */ 

    ChannelLepton = 0;
    ChannelLeptonFinal = 0;
    ChannelLeptonP = 0;
    ChannelLeptonM = 0;
    ChannelLeptonPE = 0;
    ChannelLeptonME = 0;
    ChannelLeptonPM = 0;
    ChannelLeptonMM = 0;
    ChannelIndex = 0;
    int ChannelIndexFinal = 0;
    for (int OnlyLepton = 0; OnlyLepton < (int)SelectedPar.size(); ++OnlyLepton) {
	int Lepton_pdgId = abs(AllParInfo[SelectedPar.at(OnlyLepton)].at(0));
	int Check_Charge = AllParInfo[SelectedPar.at(OnlyLepton)].at(0);
	if (Lepton_pdgId == 11 || Lepton_pdgId == 13 || Lepton_pdgId == 15) {
	    ++ChannelLepton; /* check number of lepton */
	    if (Lepton_pdgId == 15) {
		ChannelIndex -= Lepton_pdgId;
	    }
	    else {
		ChannelIndex += Lepton_pdgId;
	    } /* distinguish channel */
	    if (Lepton_pdgId == Check_Charge) {
		++ChannelLeptonP;
                if(Lepton_pdgId == 11) ++ChannelLeptonPE;
                if(Lepton_pdgId == 13) ++ChannelLeptonPM;
	    }
	    else {
		++ChannelLeptonM;
                if(Lepton_pdgId == 11) ++ChannelLeptonME;
                if(Lepton_pdgId == 13) ++ChannelLeptonMM;
	    }
	//} /*check all particle's final state end */
	    SelectedDau.clear();
	    if (Lepton_pdgId == 15) { /* check only tau's final state start */
	    for (int FinalCandidate = 0; FinalCandidate < (int)FinalPar.size(); ++FinalCandidate) {
		if (IndexLinker(AllParDau, SelectedPar.at(OnlyLepton), 0, FinalPar.at(FinalCandidate)) != -1) {
		    SelectedDau.push_back(FinalPar.at(FinalCandidate));
		}
	    }
	    } /* check only tau's final state end */
	    SelParDau[SelectedPar.at(OnlyLepton)] = SelectedDau;
	} /* check all lepton's final state end */
    }
    if(ChannelLepton>2) ChannelIndex += 100;

    ChannelLeptonFinal = ChannelLepton;
    ChannelIndexFinal = ChannelIndex;

    for (map_i_it FinaltoSel = SelParDau.begin(); FinaltoSel != SelParDau.end(); ++FinaltoSel) {
	int Lepton_Mom_pdgId = 0;
	int Lepton_Dau_pdgId = 0;
	int Lepton_Mom_flag = 0;
	for (int DauIndex = 0; DauIndex < (int)(FinaltoSel->second).size(); ++DauIndex) {
	    if(SelectedPar.end() == find(SelectedPar.begin(), SelectedPar.end(), (FinaltoSel->second).at(DauIndex))) { /* count just 1 time */
		SelectedPar.push_back((FinaltoSel->second).at(DauIndex));
		Lepton_Mom_pdgId = abs(AllParInfo[FinaltoSel->first].at(0));
		Lepton_Dau_pdgId = abs(AllParInfo[(FinaltoSel->second).at(DauIndex)].at(0));
		if (Lepton_Mom_pdgId != Lepton_Dau_pdgId) { /* lepton decay to something */
		    if (Lepton_Mom_flag == 0) { /* check mother just 1 time  */
			++Lepton_Mom_flag;
			--ChannelLeptonFinal;
			if (Lepton_Mom_pdgId < 14) ChannelIndexFinal -= Lepton_Mom_pdgId;
			if (Lepton_Mom_pdgId > 14) ChannelIndexFinal += Lepton_Mom_pdgId;
		    }
		    if (Lepton_Dau_pdgId == 11 || Lepton_Dau_pdgId == 13 || Lepton_Dau_pdgId == 15) {
	                FillGenPar((FinaltoSel->second).at(DauIndex), FinaltoSel->first, -1, -1, -1, itGenParBegin, ssbtreeManager);
                        /* fill final state lepton */
			++ChannelLeptonFinal;
			if (Lepton_Dau_pdgId < 14) ChannelIndexFinal += Lepton_Dau_pdgId;
			if (Lepton_Dau_pdgId > 14) ChannelIndexFinal -= Lepton_Dau_pdgId;
		    }
		}
	    }
	}
    }

        if(debug_cout){
	cout << endl << endl << "line 505 SelectedPar : " << endl;
	for (unsigned int i = 0; i < SelectedPar.size(); ++i){
	    cout << ParName[AllParInfo[SelectedPar.at(i)].at(0)] << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < SelectedPar.size(); ++i){
	    cout << SelectedPar.at(i) << " ";
	}
	cout << endl;
        }

    int ChannelJets = 0;
    int ChannelJetsAbs = 0;
    vector<int> temp_Channel;
    temp_Channel.clear();
    if (isTop) {
        for (unsigned int WIndex = 0; WIndex < NTop; ++WIndex) {
            int Channel_pdgId = 0;
            int First_Dau_pdgId = 99;
            int Second_Dau_pdgId = 99;
            First_Dau_pdgId  = AllParInfo[SelectedPar.at(5*WIndex+3)].at(0);
            Second_Dau_pdgId = AllParInfo[SelectedPar.at(5*WIndex+4)].at(0);
            if ( abs(First_Dau_pdgId) < 10) {
                if ( First_Dau_pdgId > Second_Dau_pdgId ) Channel_pdgId = 10*abs(First_Dau_pdgId) + abs(Second_Dau_pdgId);
                else Channel_pdgId = abs(First_Dau_pdgId) + 10*abs(Second_Dau_pdgId);
                if ( abs(First_Dau_pdgId) < abs(Second_Dau_pdgId) ) temp_Channel.push_back(10*abs(First_Dau_pdgId) + abs(Second_Dau_pdgId));
		else temp_Channel.push_back(abs(First_Dau_pdgId) + 10*abs(Second_Dau_pdgId));
                if ( ChannelJets == 0 ) ChannelJets = Channel_pdgId;
                else ChannelJets = 100*ChannelJets + Channel_pdgId;
            }
        }
    }
    if ( ChannelJets > 0 ) {
	for(int sort_i = 0; sort_i < (int)temp_Channel.size(); ++sort_i) {
	for(int sort_j = sort_i+1; sort_j < (int)temp_Channel.size(); ++sort_j) {
	    if(temp_Channel.at(sort_i) > temp_Channel.at(sort_j)) {
		int temp_id = temp_Channel.at(sort_i);
		temp_Channel.at(sort_i) = temp_Channel.at(sort_j);
		temp_Channel.at(sort_j) = temp_id;
	    }
	}	
	}
	for(int i = 0; i < (int)temp_Channel.size(); ++i) {
	    if ( i == 0 ) ChannelJetsAbs = temp_Channel.at(i);
            else ChannelJetsAbs = 100*ChannelJetsAbs + temp_Channel.at(i);
	}
    }

    ssbtreeManager->Fill( "GenPar_Count"          , genPar_index );
    ssbtreeManager->Fill( "Channel_Idx"           , ChannelIndex );
    ssbtreeManager->Fill( "Channel_Idx_Final"     , ChannelIndexFinal );
    ssbtreeManager->Fill( "Channel_Jets"          , ChannelJets );
    ssbtreeManager->Fill( "Channel_Jets_Abs"      , ChannelJetsAbs );
    ssbtreeManager->Fill( "Channel_Lepton_Count"       , ChannelLepton );
    ssbtreeManager->Fill( "Channel_Lepton_Count_Final" , ChannelLeptonFinal );
    ssbtreeManager->Fill( "Channel_Lepton_Plus"        , ChannelLeptonP );
    ssbtreeManager->Fill( "Channel_Lepton_Minus"       , ChannelLeptonM );

        if(debug_cout){
	cout << endl << endl << "line 564 SelectedPar : " << endl;
	for (unsigned int i = 0; i < SelectedPar.size(); ++i){
	    cout << ParName[AllParInfo[SelectedPar.at(i)].at(0)] << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < SelectedPar.size(); ++i){
	    cout << SelectedPar.at(i) << " ";
	}
	cout << endl;
        }
}

int
SSBGenInfor::IndexLinker(map_i IndexMap, int start_index, int target_depth, int target_index, int target_pdgid, int target_status, bool PrintError, int LoopDepth){
    if ( ((start_index == target_index) || (target_index == -999)) && 
         ((AllParInfo[start_index].at(0) == target_pdgid) || (target_pdgid == 0)) &&
         ((AllParInfo[start_index].at(1) == target_status) || (target_status == 0)) ) {
	if (PrintError) {
	    cout << endl << "Here is your target" << endl << "Depth : " << LoopDepth << endl << "Index : " << start_index << endl;
	    cout << "Status : " << AllParInfo[start_index].at(1) << endl;
	    cout << "pdgId : " << AllParInfo[start_index].at(0) << endl << endl;
	    cout << ParName[AllParInfo[start_index].at(0)] << " ";
	}
	return start_index;
    }
    else {
	++LoopDepth;
	int IndexLinkerResult = -1;
	for (int MapLoopIndex = 0; MapLoopIndex < (int)IndexMap[start_index].size(); ++MapLoopIndex){
	    if(IndexMap[start_index].at(MapLoopIndex) != -1) {
		IndexLinkerResult = IndexLinker(IndexMap, IndexMap[start_index].at(MapLoopIndex), target_depth, target_index, target_pdgid, target_status, PrintError, LoopDepth);
		if (IndexLinkerResult != -1){
		    if (LoopDepth != 1) {
			if (PrintError) cout << "(" << IndexMap[start_index].at(MapLoopIndex) << "/" << ParName[IndexMap[start_index].at(MapLoopIndex)] << ") -> ";
		    }
		    else {
			if (PrintError) cout << "(" << IndexMap[start_index].at(MapLoopIndex) << "/" << ParName[IndexMap[start_index].at(MapLoopIndex)] << ") -> (" << start_index << ") " << ParName[AllParInfo[start_index].at(0)] << endl;
		    }
		    if (LoopDepth == target_depth) {
			return IndexMap[start_index].at(MapLoopIndex);
		    }
		    break;
		}
	    }
	}
	if (LoopDepth == 1 && IndexLinkerResult == -1 && PrintError) cout << "Not Found" << endl;
	return IndexLinkerResult;
    }
}

void
SSBGenInfor::InitializeGenPar(){

    genPar_index = 0;
    AllParMom.clear();
    OriginalMom.clear();
    AllParDau.clear();
    OriginalDau.clear();
    AllParInfo.clear();
    pdgId_status.clear();
    SelParDau.clear();
    SelectedDau.clear();

    TreePar.clear();
    FinalPar.clear();
    SelectedPar.clear();

    SelectedpdgId.clear();

    ParName.clear();

    ParName[1] = "d";
    ParName[-1] = "dbar";
    ParName[2] = "u";
    ParName[-2] = "ubar";
    ParName[3] = "s";
    ParName[-3] = "sbar";
    ParName[4] = "c";
    ParName[-4] = "cbar";
    ParName[5] = "b";
    ParName[-5] = "bbar";
    ParName[6] = "t";
    ParName[-6] = "tbar";

    ParName[11] = "e-";
    ParName[-11] = "e+";
    ParName[12] = "nu_e";
    ParName[-12] = "nu_ebar";
    ParName[13] = "mu-";
    ParName[-13] = "mu+";
    ParName[14] = "nu_mu";
    ParName[-14] = "nu_mubar";
    ParName[15] = "tau-";
    ParName[-15] = "tau+";
    ParName[16] = "nu_tau";
    ParName[-16] = "nu_taubar";

    ParName[21] = "g";
    ParName[23] = "Z";
    ParName[24] = "W+";
    ParName[-24] = "W-";
    ParName[25] = "H";

    ParName[2212] = "p+";
}
void
SSBGenInfor::FillGenPar(int GenIndex, int FirstMother, int SecondMother, int FirstDaughter, int SecondDaughter, GenParticleCollection::const_iterator itGenParFill, SSBTreeManager* ssbtreeManager){

    itGenParFill += GenIndex;
    int nMo = 2;
    int nDa = 2;

    if (FirstMother == -1) {
	--nMo;
	if (SecondMother == -1) {
	    --nMo;
	}
	else {
	    //std::swap(FirstMother, SecondMother);
	    FirstMother = SecondMother;
	}
    }
    else if (SecondMother == -1) {
	--nMo;
	SecondMother = FirstMother;
    }
    else if (FirstMother == SecondMother) {
	--nMo;
    }

    if (FirstDaughter == -1) {
	--nDa;
	if (SecondDaughter == -1) {
	    --nDa;
	}
	else {
	    //std::swap(FirstDaughter, SecondDaughter);
	    FirstDaughter = SecondDaughter;
	}
    }
    else if (SecondDaughter == -1) {
	--nDa;
	SecondDaughter = FirstDaughter;
    }
    else if (FirstDaughter == SecondDaughter) {
	--nDa;
    } 

    ssbtreeManager->Fill( "GenPar_Idx"         , GenIndex               );
    ssbtreeManager->Fill( "GenPar_pdgId"       , itGenParFill->pdgId()  );
    ssbtreeManager->Fill( "GenPar_Status"      , itGenParFill->status() );

    ssbtreeManager->Fill( "GenPar_Mom1_Idx"    , FirstMother            );
    ssbtreeManager->Fill( "GenPar_Mom2_Idx"    , SecondMother           );
    ssbtreeManager->Fill( "GenPar_Mom_Counter" , nMo                    );           

    ssbtreeManager->Fill( "GenPar_Dau1_Idx"    , FirstDaughter          );
    ssbtreeManager->Fill( "GenPar_Dau2_Idx"    , SecondDaughter         );
    ssbtreeManager->Fill( "GenPar_Dau_Counter" , nDa                    );           

    ssbtreeManager->Fill( "GenPar", itGenParFill->pt(), itGenParFill->eta(), itGenParFill->phi(), itGenParFill->energy(), genPar_index );

    genPar_index++;

}

void
SSBGenInfor::GenJet(const edm::Event& iEvent, SSBTreeManager* ssbtreeManager) {

    //////////////////////////////////////
    ///Generator Level Jet information ///
    //////////////////////////////////////

    edm::Handle<GenJetCollection> genJets;
    iEvent.getByToken(genJetInfoTag,genJets);

    genJet_index = 0;

    for (GenJetCollection::const_iterator itgJet = genJets->begin() ; itgJet !=genJets->end(); itgJet++) {
	ssbtreeManager->Fill( "GenJet", (*itgJet).pt(), (*itgJet).eta(), (*itgJet).phi(), (*itgJet).energy(), genJet_index );
        //ssbtreeManager->Fill( "GenJet_HadronFlavour", (*itgJet).hadronFlavour() );
        //ssbtreeManager->Fill( "GenJet_PartonFlavour", (*itgJet).partonFlavour() );
        //ssbtreeManager->Fill( "GenJet_HCalEnergy"   , (*itgJet).hadEnergy()     );
        //ssbtreeManager->Fill( "GenJet_ECalEnergy"   , (*itgJet).emEnergy()      );
	genJet_index++;   
    }

    ssbtreeManager->Fill( "GenJet_Count", genJet_index );

}
std::string
SSBGenInfor::ReturnChannel(const edm::Event& iEvent) {
    std::string ChannelName = "Background";
    std::string ChannelCharge = "";
    if(isTop){

        if(ChannelLepton > 1){
            if(ChannelLeptonP == 0 || ChannelLeptonM == 0) ChannelCharge = "SS";
            else if(ChannelLeptonP == ChannelLeptonM) ChannelCharge = "OP";
        }

        if(ChannelIndex ==   0) ChannelName = "Hadronic";

        else if(ChannelIndex ==  11) ChannelName = "Ljets_Electron+Jets";
        else if(ChannelIndex ==  13) ChannelName = "Ljets_Muon+Jets";
        else if(ChannelIndex == -15) ChannelName = "Tau";

        else if(ChannelIndex ==  22) ChannelName = "Dilepton_DoubleElectron";
        else if(ChannelIndex ==  24) ChannelName = "Dilepton_ElectronMuon";
        else if(ChannelIndex ==  26) ChannelName = "Dilepton_DoubleMuon";
        else if(ChannelIndex ==  -4) ChannelName = "SUSY_TauElectron";
        else if(ChannelIndex ==  -2) ChannelName = "SUSY_TauMuon";
        else if(ChannelIndex == -30) ChannelName = "SUSY_DoubleTau";

        else if(ChannelIndex == 133) ChannelName = "Trilepton_TripleElectron";
        else if(ChannelIndex == 135) {ChannelName = "Trilepton_DoubleElectronMuon";
                                      if(ChannelLeptonPE == 1 && ChannelLeptonME == 1) ChannelCharge = "OP";
                                      else ChannelCharge = "SS";
                                     }
        else if(ChannelIndex == 137) {ChannelName = "Trilepton_DoubleMuonElectron";
                                      if(ChannelLeptonPM == 1 && ChannelLeptonMM == 1) ChannelCharge = "OP";
                                      else ChannelCharge = "SS";
                                     }
        else if(ChannelIndex == 139) ChannelName = "Trilepton_TripleMuon";
        else if(ChannelIndex == 107) ChannelName = "SUSY_TauDoubleElectron";
        else if(ChannelIndex == 109) ChannelName = "SUSY_TauElectronMuon";
        else if(ChannelIndex == 111) ChannelName = "SUSY_TauDoubleMuon";
        else if(ChannelIndex ==  81) ChannelName = "SUSY_DoubleTauElectron";
        else if(ChannelIndex ==  83) ChannelName = "SUSY_DoubleTauMuon";
        else if(ChannelIndex ==  55) ChannelName = "SUSY_TripleTau";

        else if(ChannelIndex == 144) ChannelName = "Tetralepton_QuadrupleElectron";
        else if(ChannelIndex == 146) ChannelName = "Tetralepton_TripleElectronMuon";
        else if(ChannelIndex == 148) ChannelName = "Tetralepton_DoubleElectronDoubleMuon";
        else if(ChannelIndex == 150) ChannelName = "Tetralepton_TripleMuonElectron";
        else if(ChannelIndex == 152) ChannelName = "Tetralepton_QuadrupleMuon";
        else if(ChannelIndex == 118) ChannelName = "SUSY_TauTripleElectron";
        else if(ChannelIndex == 120) ChannelName = "SUSY_TauDoubleElectronMuon";
        else if(ChannelIndex == 122) ChannelName = "SUSY_TauDoubleMuonElectron";
        else if(ChannelIndex == 124) ChannelName = "SUSY_TauTripleMuon";
        else if(ChannelIndex ==  92) ChannelName = "SUSY_DoubleTauDoubleElectron";
        else if(ChannelIndex ==  94) ChannelName = "SUSY_DoubleTauElectronMuon";
        else if(ChannelIndex ==  96) ChannelName = "SUSY_DoubleTauDoubleMuon";
        else if(ChannelIndex ==  66) ChannelName = "SUSY_TripleTauElectron";
        else if(ChannelIndex ==  68) ChannelName = "SUSY_TripleTauMuon";
        else if(ChannelIndex ==  40) ChannelName = "SUSY_QuadrupleTau";
        else {
            cout << endl << "Error : Is Signal? " << ChannelIndex << endl << endl; 
            cerr << endl << "Error : Is Signal? " << ChannelIndex << endl << endl; 
        }
    }
    ChannelName = ChannelCharge + ChannelName;
    return ChannelName;
}

//define this as a plug-in
DEFINE_FWK_MODULE(SSBGenInfor);
