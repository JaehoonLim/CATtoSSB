#UseList = True # InputList
UseList = False # InputFile

#InputList = './../data/dataset/dataset_TT_powheg.txt'
InputList = './../data/dataset/dataset_TTTT.txt'

#InputFile = 'file:/xrootd/store/group/CAT/DoubleEG/v8-0-3_Run2016B-23Sep2016-v3/161204_004831/0000/catTuple_2.root'
#InputFile = 'file:/xrootd/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-pythia8/v8-0-3_RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14_ext3-v1/161207_135636/0000/catTuple_1.root'
#InputFile = 'file:/xrootd/store/group/CAT/ttWJets_13TeV_madgraphMLM/v8-0-3_RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/161219_094322/0000/catTuple_1.root'
#InputFile = 'file:/xrootd/store/group/CAT/ttZJets_13TeV_madgraphMLM/v8-0-3_RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/161219_094507/0000/catTuple_1.root'
#InputFile = 'file:/cms/scratch/jhlim/CMSSW_8_0_25/src/CATTools/CatProducer/prod/catTuple.root'
#InputFile = 'file:/xrootd/store/group/CAT/TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8/v8-0-6_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170316_033329/0000/catTuple_1.root'
InputFile = 'file:/xrootd/store/group/CAT/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/v8-0-4_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170113_122604/0000/catTuple_2.root'

SetAnalyzer = "FourTop SS Di-Lepton"
#SetAnalyzer = "FourTop Tri-Lepton"

ChannelName = "ALL"
MakeOthersSample = False
FileNameSuffix = ""
Number_of_Events = -1
OnlyGeneratedLevel = False

#SetAnalyzer = "Di-Lepton"
#ChannelName = "Electron+Jets"
#ChannelName = "Muon+Jets"
#ChannelName = "Jets" # ejets + mujets
#ChannelName = "SSDilepton"
#ChannelName = "Trilepton"
#ChannelName = "Trilepton_TripleMuon"
#ChannelName = "Trilepton_TripleElectron"
#ChannelName = "OPTrilepton_DoubleElectronMuon"
#ChannelName = "SSTrilepton_DoubleElectronMuon"
#ChannelName = "OPTrilepton_DoubleMuonElectron"
#ChannelName = "SSTrilepton_DoubleMuonElectron"
#MakeOthersSample = True
#FileNameSuffix = "_Other"
#Number_of_Events = 200
#OnlyGeneratedLevel = True

SaveCutStep = "1a" # 0b, 0c, 1a, 1b, 2, 3, 4, 5
#SaveCutStep = "5" # 0b, 0c, 1, 2, 3, 4, 5,

import FWCore.ParameterSet.Config as cms
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
                                         ElectronID   = cms.untracked.string("Medium"),
                                         ElectronSF   = electronSFCutBasedIDMediumWP,
                                         ElectronPt   = cms.untracked.double(25.0),
                                         ElectronEta  = cms.untracked.double(2.4),
                                         MuonID       = cms.untracked.string("Tight"),
                                         MuonSF       = muonSFTight,
                                         MuonPt       = cms.untracked.double(20.0),
                                         MuonEta      = cms.untracked.double(2.4),
                                         MuonIso      = cms.untracked.double(0.15),
                                         # Additional Lepton Cut
                                         Do_Additional_Cut = cms.untracked.bool(True), 
                                         Add_ElectronID    = cms.untracked.string("Loose"),
                                         Add_ElectronSF    = electronSFCutBasedIDMediumWP, # FIX
                                         Add_ElectronPt    = cms.untracked.double(10.0),
                                         Add_ElectronEta   = cms.untracked.double(2.4),
                                         Add_MuonID        = cms.untracked.string("Medium"),
                                         Add_MuonSF        = muonSFTight, # FIX
                                         Add_MuonPt        = cms.untracked.double(10.0),
                                         Add_MuonEta       = cms.untracked.double(2.4),
                                         Add_MuonIso       = cms.untracked.double(0.20),
                                         # Veto Lepton
                                         veto_ElectronID  = cms.untracked.string("Veto"),
                                         veto_ElectronPt  = cms.untracked.double(5.0),
                                         veto_ElectronEta = cms.untracked.double(2.4),
                                         veto_MuonID      = cms.untracked.string("Loose"),
                                         veto_MuonPt      = cms.untracked.double(5.0),
                                         veto_MuonEta     = cms.untracked.double(2.4),
                                         veto_MuonIso      = cms.untracked.double(0.25),
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
                                         METPt        = cms.untracked.double(40.0),
                                         # SSBGenInfor
                                         genParTag         = cms.InputTag("prunedGenParticles"),
                                         genJetTag         = cms.InputTag("slimmedGenJets",""),
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
                                         Save_Channel      = cms.untracked.string(ChannelName),
                                         Save_CutStep      = cms.untracked.string(SaveCutStep),
                                         Save_Inversion    = cms.untracked.bool(MakeOthersSample),
                                         # Debug
                                         Debug_cout = cms.untracked.bool(False)
                                        )

process.TFileService=cms.Service("TFileService",
        fileName=cms.string("SSBTree_"+ChannelName+FileNameSuffix+".root"),
        closeFileFast = cms.untracked.bool(True)
)
process.p = cms.Path(process.SSBAnalyzer)

#process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
#process.printTree = cms.EDAnalyzer("ParticleTreeDrawer",
#                                   src = cms.InputTag("prunedGenParticles"),                                                                 
#                                   printP4 = cms.untracked.bool(False),
#                                   printPtEtaPhi = cms.untracked.bool(False),
#                                   printVertex = cms.untracked.bool(False),
#                                   printStatus = cms.untracked.bool(True),
#                                   printIndex = cms.untracked.bool(True),
#                                   status = cms.untracked.vint32( 1,2,4,21,22,23,24,31,32,33,34,41,42,43,44,51,52,53,54,61,62,63,64,71,72,73,74 )
#                                   )
#process.p = cms.Path(process.printTree)

#process.MessageLogger.cerr.FwkReport.reportEvery = 50000
