UseList = True # InputList
#UseList = False # InputFile

#InputList = './../data/dataset/dataset_TT_powheg.txt'
InputList = './../test/TTTT.txt'

InputFile = 'file:/xrootd/store/group/CAT/TTbarXSecSynchronization/v8-0-1/TT_TuneCUETP8M1_13TeV-powheg-pythia8__PUSpring16_80X_mcRun2_asymptotic_2016_v3_ext3-v1__1671FA99-240F-E611-BF05-00266CFAE464.root'

#ChannelName = "Electron+Jets"
#ChannelName = "Muon+Jets"
#ChannelName = "Jets" # ejets + mujets
#ChannelName = "SSDilepton"
ChannelName = "ALL"

SaveCutStep = "1a" # 0b, 0c, 1a, 1b, 2, 3, 4, 5

#MakeOthersSample = True
MakeOthersSample = False

#Number_of_Events = 20000
Number_of_Events = -1

FileNameSuffix = ""
#FileNameSuffix = "_Other"

#OnlyGeneratedLevel = True
OnlyGeneratedLevel = False

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

if OnlyGeneratedLevel:
    process.SSBAnalyzer = cms.EDAnalyzer('SSBGenInfor',
                                         genParTag         = cms.InputTag("prunedGenParticles"),
                                         genJetTag         = cms.InputTag("slimmedGenJets",""),
                                        )
else :
    process.SSBAnalyzer = cms.EDAnalyzer('SSBConverter',
                                         # Trigger
                                         Do_Trigger_Cut    = cms.untracked.bool(False), 
                                         e_Trigger         = cms.untracked.vstring('HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ',
                                                                                   'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
                                                                                   'HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v'),
                                         m_Trigger         = cms.untracked.vstring('HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ'
                                                                                   'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v',
                                                                                   'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v'),
                                         em_Trigger        = cms.untracked.vstring('HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL',
                                                                                   'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v',
                                                                                   'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v',
                                                                                   'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
                                                                                   'HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL',
                                                                                   'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v'),
                                         # Reco Level Cut Variables
                                         # Lepton
                                         ElectronID   = cms.untracked.string("Medium"),
                                         ElectronPt   = cms.untracked.double(20.0),
                                         ElectronEta  = cms.untracked.double(2.4),
                                         MuonID       = cms.untracked.string("Tight"),
                                         MuonPt       = cms.untracked.double(20.0),
                                         MuonEta      = cms.untracked.double(2.4),
                                         MuonIso      = cms.untracked.double(0.15),
                                         # Veto Lepton
                                         veto_ElectronID   = cms.untracked.string("Veto"),
                                         veto_ElectronPt   = cms.untracked.double(5.0),
                                         veto_ElectronEta  = cms.untracked.double(2.4),
                                         veto_MuonID       = cms.untracked.string("Loose"),
                                         veto_MuonPt       = cms.untracked.double(5.0),
                                         veto_MuonEta      = cms.untracked.double(2.4),
                                         veto_MuonIso      = cms.untracked.double(0.25),
                                         # Jet
                                         JetID        = cms.untracked.string("Loose"),
                                         JetPt        = cms.untracked.double(30.0),
                                         JetEta       = cms.untracked.double(2.5),
                                         CleaningdR   = cms.untracked.double(0.4),
                                         # B-Jet
                                         BTag         = cms.untracked.string("Medium"),
                                         # All Lepton Invariant Mass (Dilepton : Z Mass Veto)
                                         InvariantMass = cms.untracked.double(91.2),
                                         PlusMinus     = cms.untracked.double(15.0),
                                         # MET
                                         METPt        = cms.untracked.double(40.0),
                                         # SSBGenInfor
                                         genParTag         = cms.InputTag("prunedGenParticles"),
                                         genJetTag         = cms.InputTag("slimmedGenJets",""),
                                         # SSBAnalyzer
                                         muonTag           = cms.InputTag("catMuons"),
                                         electronTag       = cms.InputTag("catElectrons"),
                                         jetTag            = cms.InputTag("catJets"),
                                         metTag            = cms.InputTag("catMETs"),
                                         npvTag            = cms.InputTag("catVertex:nGoodPV"),
                                         triggerBitsTag    = cms.InputTag("TriggerResults::HLT"),
                                         EventFilterBitsTag= cms.InputTag("TriggerResults::PAT"),
                                         genWeightLabel    = cms.InputTag("genWeight"),
                                         # Save Channel
                                         Save_Channel      = cms.untracked.string(ChannelName),
                                         Save_CutStep      = cms.untracked.string(SaveCutStep),
                                         Save_Inversion    = cms.untracked.bool(MakeOthersSample)
                                        )

process.TFileService=cms.Service("TFileService",
        fileName=cms.string("SSBTree_"+ChannelName+FileNameSuffix+".root"),
        closeFileFast = cms.untracked.bool(True)
)

process.p = cms.Path(process.SSBAnalyzer)
#process.MessageLogger.cerr.FwkReport.reportEvery = 50000
