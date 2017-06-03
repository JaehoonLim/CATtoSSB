if [ $1 ]; then
    dirlist=$1
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi
for L in $dirlist; do
    if [ ${L} != "Output" ]; then
        allfile=$(ls $L/job_*.err 2>/dev/null | wc -l)
        >&2 echo ""
        >&2 echo "${L} : Checking ${allfile} files"
        #grep -H 'xception' ./${L}/job_*.err
        errorfile=$(grep -H 'xception' ./${L}/job_*.err 2>/dev/null | wc -l)
        #grep -H 'real' ./${L}/job_*.err
        endfile=$(grep -H 'real' ./${L}/job_*.err 2>/dev/null | wc -l)
        if [ ${allfile} == 0 ]; then
            echo "${L} : Log Files Removed? - All Jobs Finished without Error"
        elif [ ${allfile} == ${endfile} ] && [ ${errorfile} == 0 ]; then
            echo "${L} : All Jobs Finished without Error"
        else
            echo "${L} : ${errorfile} Error Files - ${endfile}/${allfile} Jobs Finished"
        fi
    fi
done 
