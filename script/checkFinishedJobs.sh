if [ $1 ]; then
    dirlist=$1
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi
for L in $dirlist; do
    if [ ${L} != "Output" ] && [ ${L} != "dataset" ]; then
        allfile=$(ls $L/job_*.err 2>/dev/null | wc -l)
        >&2 echo ""
        >&2 echo "${L} : Checking ${allfile} files"
        # >&2 means 'stdout' to 'stderr' / & means 'not file' (ex : Name of file is '2')
        #grep -H 'Begin Fatal Exception' ./${L}/job_*.err
        errorfile=$(grep -H -e 'Begin Fatal Exception' -e 'Segmentation fault      cmsRun' ./${L}/job_*.err 2>/dev/null | wc -l)
        #grep -H 'real' ./${L}/job_*.err
        #endfile=$(grep -H 'real' ./${L}/job_*.err 2>/dev/null | wc -l)
        endfile=$(grep -H 'MessageLogger' ./${L}/job_*.err 2>/dev/null | wc -l)
        if [ ${allfile} == 0 ]; then
            echo "${L} : Log Files Removed? - All Jobs Finished without Error"
        elif [ ${allfile} == ${endfile} ] && [ ${errorfile} == 0 ]; then
            echo "${L} : All Jobs Finished without Error"
        else
            echo "${L} : ${errorfile} Error Files - ${endfile}/${allfile} Jobs Finished"
        fi
    fi
done 
