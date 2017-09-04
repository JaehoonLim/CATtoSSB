import FWCore.ParameterSet.Config as cms

SetAnalyzer = "FourTop SUSY"
#SetAnalyzer = "Lepton+Jets"
#SetAnalyzer = "FourTop SS Di-Lepton"
#SetAnalyzer = "FourTop Tri-Lepton"
#SetAnalyzer = "Di-Lepton"

#Channel = "SIG"
#Channel = "OTH"
Channel = "BG"
ISO = "WP1"
#ISO = "SUSY"

if ISO == "WP1":
    M_MiniIso  = cms.untracked.double(0.09)
    M_PtRatio  = cms.untracked.double(0.74)
    M_PtRel    = cms.untracked.double(7.2)
    E_MiniIso  = cms.untracked.double(0.05)
    E_PtRatio  = cms.untracked.double(0.78)
    E_PtRel    = cms.untracked.double(7.8)
elif ISO == "SUSY":
    M_MiniIso  = cms.untracked.double(0.16)
    M_PtRatio  = cms.untracked.double(0.76)
    M_PtRel    = cms.untracked.double(7.2)
    E_MiniIso  = cms.untracked.double(0.12)
    E_PtRatio  = cms.untracked.double(0.80)
    E_PtRel    = cms.untracked.double(7.2)
else:
    M_MiniIso  = cms.untracked.double(0.16)
    M_PtRatio  = cms.untracked.double(0.76)
    M_PtRel    = cms.untracked.double(7.2)
    E_MiniIso  = cms.untracked.double(0.12)
    E_PtRatio  = cms.untracked.double(0.80)
    E_PtRel    = cms.untracked.double(7.2)

if Channel == "SIG":
    ChannelName = ('SSDilepton','Trilepton','Tetralepton')
    MakeOthersSample = False
elif Channel == "OTH":
    ChannelName = ('SSDilepton','Trilepton','Tetralepton')
    MakeOthersSample = True
elif Channel == "BG":
    ChannelName = ("ALL")
    MakeOthersSample = False
else:
    ChannelName = ("ALL")
    MakeOthersSample = False

Number_of_Events = -1
#Number_of_Events = 10000

SaveCutStep = "0d"

FileNameSuffix = ""
#FileNameSuffix = "_Others"

OnlyGeneratedLevel = False
#OnlyGeneratedLevel = True

#ChannelName = ("Electron+Jets")
#ChannelName = ("Muon+Jets")
#ChannelName = ("Jets") # ejets + mujets
#ChannelName = ("Trilepton")
#ChannelName = ("Trilepton_TripleMuon")
#ChannelName = ("Trilepton_TripleElectron")
#ChannelName = ("OPTrilepton_DoubleElectronMuon")
#ChannelName = ("SSTrilepton_DoubleElectronMuon")
#ChannelName = ("OPTrilepton_DoubleMuonElectron")
#ChannelName = ("SSTrilepton_DoubleMuonElectron")

#UseList = True # InputList
UseList = False # InputFile

#InputList = './../data/dataset/dataset_TT_powheg.txt'
InputList = './../data/dataset/dataset_TTTT.txt'

InputFile = 'file:/xrootd/store/group/CAT/TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8/v8-0-6_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170316_033329/0000/catTuple_1.root'
#InputFile = 'file:/xrootd/store/group/CAT/DoubleMuon/v8-0-6_Run2016F-03Feb2017-v1/170424_185324/0000/catTuple_402.root'
#InputFile = 'file:/xrootd/store/user/jhlim/crab_v8-0-6_TTGamma_Dilept_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8/results/catTuple_1.root'
#InputFile = 'file:/xrootd/store/user/jhlim/crab_v8-0-6_TTTJ_TuneCUETP8M2T4_13TeV-madgraph-pythia8/results/catTuple_10.root'

process = cms.Process("CATtoSSB")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(Number_of_Events))
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )

process.options.allowUnscheduled = cms.untracked.bool(True)
if UseList:
    import FWCore.Utilities.FileUtils as FileUtils
    mylist = FileUtils.loadListFromFile (InputList)
    process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(*mylist))
else :
    process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(InputFile))

from CATTools.CatAnalyzer.leptonSF_cff import *

if OnlyGeneratedLevel:
    process.SSBAnalyzer = cms.EDAnalyzer('SSBGenInfor',
                                         genParTag         = cms.InputTag("prunedGenParticles"),
                                         genJetTag         = cms.InputTag("slimmedGenJets",""),
                                         CheckBG           = cms.untracked.vstring(ChannelName),
                                        )
else :
    process.SSBAnalyzer = cms.EDAnalyzer('SSBConverter',
                                         # Channel
                                         Channel = cms.untracked.string(SetAnalyzer),
                                         # Trigger
                                         Do_Trigger_Cut    = cms.untracked.bool(True), 
                                         e_Trigger         = cms.untracked.vstring('HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ',
                                                                                   'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
                                                                                   'HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v'),
                                         m_Trigger         = cms.untracked.vstring('HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ'
                                                                                   'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v',
                                                                                   'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v'),
                                         em_Trigger        = cms.untracked.vstring('HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL',
                                                                                   'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v',
                                                                                   'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v',
                                                                                   'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v',
                                                                                   'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
                                                                                   'HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL',
                                                                                   'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v',
                                                                                   'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v'),
                                         # Reco Level Cut Variables
                                         # Lepton
                                         ElectronID   = cms.untracked.string("Tight"),
                                         #ElectronID   = cms.untracked.string("Medium"),
                                         #ElectronID   = cms.untracked.string("Loose"),
                                         ElectronSF   = electronSFCutBasedIDMediumWP, # NEED FIX
                                         ElectronPt   = cms.untracked.double(20.0),
                                         ElectronEta  = cms.untracked.double(2.4),
                                         ElectronIso  = cms.untracked.string("TEMP"), # TEMP 10.0
                                         Do_Elec_MultiIso = cms.untracked.bool(True), # Switch to MVA ID
                                         #Do_Elec_MultiIso  = cms.untracked.bool(False),
                                         #ElectronMiniIso  = cms.untracked.double(0.05),
                                         #ElectronPtRatio  = cms.untracked.double(0.78),
                                         #ElectronPtRel    = cms.untracked.double(7.8),
                                         ElectronMiniIso  = E_MiniIso,
                                         ElectronPtRatio  = E_PtRatio,
                                         ElectronPtRel    = E_PtRel,
                                         #MuonID       = cms.untracked.string("Tight"),
                                         MuonID       = cms.untracked.string("Medium"),
                                         #MuonID       = cms.untracked.string("Loose"),
                                         MuonSF       = muonSFTight, # NEED FIX
                                         MuonPt       = cms.untracked.double(20.0),
                                         MuonEta      = cms.untracked.double(2.4),
                                         #MuonIso      = cms.untracked.double(0.15),
                                         MuonIso      = cms.untracked.double(10.0), # TEMP
                                         Do_Muon_MultiIso = cms.untracked.bool(True),
                                         #Do_Muon_MultiIso  = cms.untracked.bool(False),
                                         #MuonMiniIso  = cms.untracked.double(0.09),
                                         #MuonPtRatio  = cms.untracked.double(0.74),
                                         #MuonPtRel    = cms.untracked.double(7.2),
                                         MuonMiniIso  = M_MiniIso,
                                         MuonPtRatio  = M_PtRatio,
                                         MuonPtRel    = M_PtRel,

                                         # Additional Lepton Cut
                                         Do_Additional_Cut = cms.untracked.bool(True), 
                                         #Do_TightLoose     = cms.untracked.bool(True), 
                                         #Do_Additional_Cut = cms.untracked.bool(False), 
                                         Do_TightLoose     = cms.untracked.bool(False), 
                                         Add_ElectronID    = cms.untracked.string("Tight"),
                                         #Add_ElectronID    = cms.untracked.string("Medium"),
                                         #Add_ElectronID    = cms.untracked.string("Loose"),
                                         Add_ElectronSF    = electronSFCutBasedIDMediumWP, # NEED FIX
                                         Add_ElectronPt    = cms.untracked.double(5.0),
                                         Add_ElectronEta   = cms.untracked.double(2.4),
                                         Add_ElectronIso   = cms.untracked.string("TEMP"), # TEMP 10.0
                                         Do_Add_Elec_MultiIso = cms.untracked.bool(True), # Switch to MVA ID
                                         #Do_Add_Elec_MultiIso  = cms.untracked.bool(False),
                                         #Add_ElectronMiniIso  = cms.untracked.double(0.05),
                                         #Add_ElectronPtRatio  = cms.untracked.double(0.78),
                                         #Add_ElectronPtRel    = cms.untracked.double(7.8),
                                         Add_ElectronMiniIso  = E_MiniIso,
                                         Add_ElectronPtRatio  = E_PtRatio,
                                         Add_ElectronPtRel    = E_PtRel,
                                         Add_MuonID        = cms.untracked.string("Medium"),
                                         #Add_MuonID        = cms.untracked.string("Loose"),
                                         Add_MuonSF        = muonSFTight, # NEED FIX
                                         Add_MuonPt        = cms.untracked.double(5.0),
                                         Add_MuonEta       = cms.untracked.double(2.4),
                                         Add_MuonIso       = cms.untracked.double(10.0), # TEMP
                                         Do_Add_Muon_MultiIso = cms.untracked.bool(True),
                                         #Do_Add_Muon_MultiIso  = cms.untracked.bool(False),
                                         #Add_MuonMiniIso  = cms.untracked.double(0.09),
                                         #Add_MuonPtRatio  = cms.untracked.double(0.74),
                                         #Add_MuonPtRel    = cms.untracked.double(7.2),
                                         Add_MuonMiniIso  = M_MiniIso,
                                         Add_MuonPtRatio  = M_PtRatio,
                                         Add_MuonPtRel    = M_PtRel,

                                         # Veto Lepton
                                         veto_ElectronID  = cms.untracked.string("Veto"),
                                         veto_ElectronPt  = cms.untracked.double(5.0),
                                         veto_ElectronEta = cms.untracked.double(2.4),
                                         #veto_ElectronIso = cms.untracked.string("Veto"),
                                         veto_ElectronIso = cms.untracked.string("TEMP"), # TEMP 10.0
                                         Do_veto_Elec_MultiIso = cms.untracked.bool(True), # Switch to MVA ID
                                         #Do_veto_Elec_MultiIso  = cms.untracked.bool(False),
                                         #veto_ElectronMiniIso  = cms.untracked.double(10.0),
                                         #veto_ElectronPtRatio  = cms.untracked.double(0.0),
                                         #veto_ElectronPtRel    = cms.untracked.double(0.0),
                                         veto_ElectronMiniIso  = E_MiniIso,
                                         veto_ElectronPtRatio  = E_PtRatio,
                                         veto_ElectronPtRel    = E_PtRel,
                                         veto_MuonID      = cms.untracked.string("Loose"),
                                         veto_MuonPt      = cms.untracked.double(5.0),
                                         veto_MuonEta     = cms.untracked.double(2.4),
                                         #veto_MuonIso      = cms.untracked.double(0.25),
                                         veto_MuonIso      = cms.untracked.double(10.0), # TEMP
                                         Do_veto_Muon_MultiIso = cms.untracked.bool(True),
                                         #Do_veto_Muon_MultiIso  = cms.untracked.bool(False),
                                         #veto_MuonMiniIso  = cms.untracked.double(10.0),
                                         #veto_MuonPtRatio  = cms.untracked.double(0.0),
                                         #veto_MuonPtRel    = cms.untracked.double(0.0),
                                         veto_MuonMiniIso  = M_MiniIso,
                                         veto_MuonPtRatio  = M_PtRatio,
                                         veto_MuonPtRel    = M_PtRel,

                                         # Jet
                                         JetID        = cms.untracked.string("Loose"),
                                         JetPt        = cms.untracked.double(30.0),
                                         JetEta       = cms.untracked.double(2.5),
                                         CleaningdR   = cms.untracked.double(0.4),
                                         # B-Jet
                                         BTag         = cms.untracked.string("Medium"),
                                         # All Lepton Invariant Mass (ex : Dilepton - Z Mass Veto)
                                         InvariantMass = cms.untracked.double(91.2),
                                         PlusMinus     = cms.untracked.double(15.0),
                                         # MET
                                         METPt        = cms.untracked.double(50.0),
                                         # SSBGenInfor
                                         genParTag         = cms.InputTag("prunedGenParticles"),
                                         genJetTag         = cms.InputTag("slimmedGenJets",""),
                                         CheckBG           = cms.untracked.vstring(ChannelName),
                                         # SSBAnalyzer
                                         lumiMaskTag       = cms.InputTag("lumiMask"),
                                         muonTag           = cms.InputTag("catMuons"),
                                         electronTag       = cms.InputTag("catElectrons"),
                                         jetTag            = cms.InputTag("catJets"),
                                         metTag            = cms.InputTag("catMETs"),
                                         npvTag            = cms.InputTag("catVertex:nGoodPV"),
                                         triggerBitsTag      = cms.VInputTag(cms.InputTag("TriggerResults::HLT"),
                                                                             cms.InputTag("TriggerResults::HLT2")),
                                         EventFilterBitsTag = cms.VInputTag(cms.InputTag("TriggerResults::PAT"),
                                                                            cms.InputTag("TriggerResults::RECO")),
                                         genWeightTag    = cms.InputTag("genWeight"),
                                         PileUpWeightTag = cms.InputTag("pileupWeight"),
                                         # Save Channel
                                         Save_Channel      = cms.untracked.vstring(ChannelName),
                                         Save_CutStep      = cms.untracked.string(SaveCutStep),
                                         Save_Inversion    = cms.untracked.bool(MakeOthersSample),
                                         # Debug
                                         Debug_cout = cms.untracked.bool(False)
                                        )

process.TFileService=cms.Service("TFileService",
        fileName=cms.string("SSBTree"+FileNameSuffix+".root"),
        closeFileFast = cms.untracked.bool(True)
)
process.p = cms.Path(process.SSBAnalyzer)

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleTreeDrawer",
                                   src = cms.InputTag("prunedGenParticles"),                                                                 
                                   printP4 = cms.untracked.bool(False),
                                   printPtEtaPhi = cms.untracked.bool(False),
                                   printVertex = cms.untracked.bool(False),
                                   printStatus = cms.untracked.bool(True),
                                   printIndex = cms.untracked.bool(True),
                                   status = cms.untracked.vint32( 1,2,4,21,22,23,24,31,32,33,34,41,42,43,44,51,52,53,54,61,62,63,64,71,72,73,74 )
                                   )
#process.p = cms.Path(process.printTree)

#process.MessageLogger.cerr.FwkReport.reportEvery = 50000
