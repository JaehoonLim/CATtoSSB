testdir="./"
dirtime=$(TZ=GMT-2 date +%y%m%d)
if [ ! -d ${testdir}/Output ]; then
    mkdir ${testdir}/Output
fi
if [ ! -d ${testdir}/Output/${dirtime} ]; then
    mkdir ${testdir}/Output/${dirtime}
fi
#if [ ! -d ./Output/${dirtime}/ControlPlots ]; then
#    mkdir Output/${dirtime}/ControlPlots
#fi

if [ $1 ]; then
    dirlist=$1
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi

for L in $dirlist; do
    if [ ${L} != "Output" ] && [ ${L} != "dataset" ]; then
        check=$(./checkFinishedJobs.sh ${L})
        if [ "$(echo $check | grep 'All Jobs Finished without Error')" ]; then
            echo "$check" 
            hadd ${testdir}/Output/${dirtime}/${L}.root ${L}/*.root
            rm -rf ${L}
        else
            echo "$check" 
        fi
    fi
done
