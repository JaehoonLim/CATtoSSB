Suffix=""
if [ ! -z ${2} ]; then
Suffix="_"${2}
fi
if [ ${1} == "SIG" ] || [ ${1} == "ALL" ]; then
# TTTT_Signal
create-batch --jobName TTTT${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_DiLep${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriLep${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriMuon${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_TriElec${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_OSDiElMu${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_SSDiElMu${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_OSDiMuEl${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
#create-batch --jobName TTTT_SSDiMuEl${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTTT.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "SYS" ] || [ ${1} == "ALL" ]; then
create-batch --jobName TTTT_isrup${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_isrup.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_isrdown${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_isrdown.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_fsrup${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_fsrup.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
create-batch --jobName TTTT_fsrdown${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTT_fsrdown.txt --maxFiles 1 --cfg CATtoSSB_cfg.py
else
:
fi
