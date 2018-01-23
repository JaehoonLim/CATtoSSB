Suffix=""
if [ ! -z ${2} ]; then
Suffix="_"${2}
fi
if [ ${1} == "EE" ] || [ ${1} == "ALL" ]; then
create-batch --jobName DoubleEG_Run2016B${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016B.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016C${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016C.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016D${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016D.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016E${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016E.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016F${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016F.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016G${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016G.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016H_v2${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016H_v2.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleEG_Run2016H_v3${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleEG_Run2016H_v3.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "MM" ] || [ ${1} == "ALL" ]; then
create-batch --jobName DoubleMuon_Run2016B${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016B.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016C${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016C.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016D${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016D.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016E${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016E.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016F${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016F.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016G${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016G.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016H_v2${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016H_v2.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DoubleMuon_Run2016H_v3${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DoubleMuon_Run2016H_v3.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "EM" ] || [ ${1} == "ALL" ]; then
create-batch --jobName MuonEG_Run2016B${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016B.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016C${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016C.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016D${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016D.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016E${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016E.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016F${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016F.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016G${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016G.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016H_v2${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016H_v2.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName MuonEG_Run2016H_v3${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_MuonEG_Run2016H_v3.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
else
:
fi
echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Done."
