SSB=$(readlink -f $0 | sed 's/move//')
CAT=$CMSSW_BASE/src/CATTools/CatAnalyzer
mv $SSB/SSB* $CAT/plugins/.
mv $SSB/CAT* $CAT/test/.
rm -rf $0
rm -rf $SSB
