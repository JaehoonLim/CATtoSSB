if [ $1 ]; then
    dirlist=$1
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi
for L in $dirlist; do
    if [ ${L} != "Output" ]; then
        check=$(./checkFinishedJobs.sh ${L})
        if [ "$(echo $check | grep 'All Jobs Finished without Error')" ]; then
            echo "$check" 
            rm -rf ${L}/*log*
            rm -rf ${L}/*.sh
            rm -rf ${L}/job*
            rm -rf ${L}/submit*
        else
            echo "$check" 
        fi
    fi
done
