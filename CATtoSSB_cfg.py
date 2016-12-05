UseList = True
#UseList = False
InputList = './../data/dataset/dataset_TT_powheg.txt'
InputFile = 'file:/xrootd/store/group/CAT/TTbarXSecSynchronization/v8-0-1/TT_TuneCUETP8M1_13TeV-powheg-pythia8__PUSpring16_80X_mcRun2_asymptotic_2016_v3_ext3-v1__1671FA99-240F-E611-BF05-00266CFAE464.root'
#ChannelName = "Electron+Jets"
ChannelName = "Muon+Jets"
#ChannelName = "Jets" # ejets + mujets
MakeOthersSample = False
Number_of_Events = 1 
FileNameSuffix = "_test"
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
                                         # Reco Level Cut Variables
                                         Save_Channel      = cms.untracked.string(ChannelName),
                                         Save_Inversion    = cms.untracked.bool(MakeOthersSample),
                                         # Trigger0
                                         Do_Trigger_Cut    = cms.untracked.bool(False), 
                                         e_Trigger         = cms.untracked.vstring('HLT_Ele23_WPLoose_Gsf'),
                                         m_Trigger         = cms.untracked.vstring('HLT_IsoMu18'),
                                         em_Trigger        = cms.untracked.vstring('HLT_IsoMu18'),
                                         # Lepton
                                         ElectronID   = cms.untracked.string("Medium"),
                                         ElectronPt   = cms.untracked.double(30.0),
                                         ElectronEta  = cms.untracked.double(2.4),
                                         MuonID       = cms.untracked.string("Tight"),
                                         MuonPt       = cms.untracked.double(26.0),
                                         MuonEta      = cms.untracked.double(2.1),
                                         MuonIso      = cms.untracked.double(0.15),
                                         # Veto Lepton
                                         veto_ElectronID   = cms.untracked.string("Veto"),
                                         veto_ElectronPt   = cms.untracked.double(10.0),
                                         veto_ElectronEta  = cms.untracked.double(2.4),
                                         veto_MuonID       = cms.untracked.string("Loose"),
                                         veto_MuonPt       = cms.untracked.double(10.0),
                                         veto_MuonEta      = cms.untracked.double(2.4),
                                         veto_MuonIso      = cms.untracked.double(0.25),
                                         # Jet
                                         JetID        = cms.untracked.string("Loose"),
                                         JetPt        = cms.untracked.double(30.0),
                                         JetEta       = cms.untracked.double(2.4),
                                         CleaningdR   = cms.untracked.double(0.4),
                                         # B-Jet
                                         BTag         = cms.untracked.string("Medium"),
                                         # Lepton Inclusive Mass (Z Mass)
                                         InclusiveMass = cms.untracked.double(80.4),
                                         PlusMinus     = cms.untracked.double(15.0),
                                         # MET
                                         METPt        = cms.untracked.double(0.0)
                                        )

process.TFileService=cms.Service("TFileService",
        fileName=cms.string("SSBTree"+FileNameSuffix+".root"),
        closeFileFast = cms.untracked.bool(True)
)

process.p = cms.Path(process.SSBAnalyzer)
#process.MessageLogger.cerr.FwkReport.reportEvery = 50000
