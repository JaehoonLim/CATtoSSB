if [ ${1} == "TT" ]; then
# TT
create-batch --jobName TT --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TT_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttWToLNu --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttWToLNu.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZToLL_M-1to10 --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttZToLL_M-1to10.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttH_bb --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttH_bb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttH_nonbb --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttH_nonbb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttbb --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttbb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

elif [ ${1} == "ST" ]; then
# SingleTop
#create-batch --jobName SingleTop_s --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_s.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName SingleTop_t --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_t.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName SingleTbar_t --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTbar_t.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName SingleTop_tW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_tW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName SingleTbar_tW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTbar_tW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

elif [ ${1} == "DY" ]; then
# DY
#create-batch --jobName DYJets --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DYJets_MG --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets_MG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DYJets_MG_10to50 --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets_MG_10to50.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

elif [ ${1} == "SB" ]; then
# Boson + jets
#create-batch --jobName WJets --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WJets.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WJets_MG --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WJets_MG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

# Boson + gamma
create-batch --jobName WGtoLNuG --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WGtoLNuG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZGto2LG --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZGto2LG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

elif [ ${1} == "DB" ]; then
# di-Bosons
#create-batch --jobName WW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WWTo2L2Nu --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWTo2L2Nu.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName WZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WZTo3LNu --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZTo3LNu_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ZZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZZTo4L --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZTo4L_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WpWpEWK --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WpWpEWK.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WpWpQCD --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WpWpQCD.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

elif [ ${1} == "TB" ]; then
# tri-Bosons
create-batch --jobName WWW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WWZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WZZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZZZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

else
:
#create-batch --jobName  --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
