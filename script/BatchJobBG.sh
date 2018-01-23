Suffix=""
if [ ! -z ${2} ]; then
Suffix="_"${2}
fi
if [ ${1} == "TT" ] || [ ${1} == "ALL" ]; then
# TT
create-batch --jobName TT${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TT_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName TT${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_TTLJ_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttWToLNu${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttWToLNu.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZToLL_M-1to10${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttZToLL_M-1to10.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZToLLNuNu_M-10${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTZToLLNuNu_M-10.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttH_bb${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttH_bb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttH_nonbb${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttH_nonbb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ttbb${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ttbb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "ST" ] || [ ${1} == "ALL" ]; then
# SingleTop
#create-batch --jobName SingleTop_s${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_s.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName SingleTop_t${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_t.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName SingleTbar_t${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTbar_t.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName SingleTop_tW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTop_tW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName SingleTbar_tW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_SingleTbar_tW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "DY" ] || [ ${1} == "ALL" ]; then
# DY
#create-batch --jobName DYJets --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName DYJets_MG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets_MG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DYJets_MG_10to50${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_DYJets_MG_10to50.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName DYJets_MG_ext1${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_DYJets_MG_ext1.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "SB" ] || [ ${1} == "ALL" ]; then
# Boson + jets
#create-batch --jobName WJets --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WJets.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WJets_MG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WJets_MG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py

# Boson + gamma
create-batch --jobName WGtoLNuG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WGtoLNuG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZGto2LG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZGto2LG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "DB" ] || [ ${1} == "ALL" ]; then
# di-Bosons
#create-batch --jobName WW --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WWTo2L2Nu${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWTo2L2Nu.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName WZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WZTo3LNu${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZTo3LNu_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
#create-batch --jobName ZZ --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZZTo4L${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZTo4L_powheg.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WpWpEWK${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WpWpEWK.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WpWpQCD${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WpWpQCD.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if [ ${1} == "TB" ] || [ ${1} == "ALL" ]; then
# tri-Bosons
create-batch --jobName WWW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WWZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WWZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WZZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_WZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ZZZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_ZZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
if  [ ${1} == "ADD" ] || [ ${1} == "ALL" ]; then
# Additional BG
create-batch --jobName GluGluHToZZTo4L${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_GluGluHToZZTo4L.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName TGJets${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TGJets.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttGamma_Dilept${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTGamma_Dilept.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttGamma_SingleLeptFromT${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTGamma_SingleLeptFromT.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttGamma_SingleLeptFromTbar${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTGamma_SingleLeptFromTbar.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttHH${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTHH.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttWH${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTWH.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttWW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTWW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttWZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTWZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZH${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTZH.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName ttZZ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTZZ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName VHToNonbb${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_VHToNonbb.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WWG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_WWG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName WZG${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_WZG.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName tZq_ll_4f${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_tZq_ll_4f.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName tttJ${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTJ.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
create-batch --jobName tttW${Suffix} --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/CATtoSSB/script/dataset/dataset_TTTW.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
else
:
#create-batch --jobName  --fileList $CMSSW_BASE/src/CATTools/CatAnalyzer/data/dataset/dataset_.txt --maxFiles 10 --cfg CATtoSSB_cfg.py
fi
echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Done."
