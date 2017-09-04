Suffix=""
if [ ! -z ${2} ]; then
Suffix="_"${2}
fi
if [ ${1} == "SIG" ] || [ ${1} == "ALL" ]; then
# TTTT_others
create-batch --jobName TTTT_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_DiLep_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriLep_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriMuon_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriElec_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_OSDiElMu_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_SSDiElMu_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_OSDiMuEl_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_SSDiMuEl_Others${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "SYS" ] || [ ${1} == "ALL" ]; then
create-batch --jobName TTTT_Others_isrup${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_isrup.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_Others_isrdown${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_isrdown.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_Others_fsrup${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_fsrup.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_Others_fsrdown${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_fsrdown.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
else
:
fi
