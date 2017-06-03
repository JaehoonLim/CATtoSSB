dirtime=$(TZ=GMT-2 date +%y%m%d)
if [ ! -d ./Output ]; then
    mkdir Output
fi
if [ ! -d ./Output/${dirtime} ]; then
    mkdir Output/${dirtime}
fi
if [ ! -d ./Output/${dirtime}/ControlPlots ]; then
    mkdir Output/${dirtime}/ControlPlots
fi

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
            hadd Output/${dirtime}/${L}.root ${L}/*.root
            rm -rf ${L}
        else
            echo "$check" 
        fi
    fi
done
