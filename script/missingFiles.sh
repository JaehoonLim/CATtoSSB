if [ ${1} ]; then
    if [ -z ${1//[0-9]/} ]; then
        if [ -e "job_${1}.log" ]; then
            dirlist="./"
            MissingFiles=$1
            if [ -s "SSBTree_${1}.root" ]; then
                echo "No Error File"
                exit
            fi
        else
            echo "Check File Name"
            exit
        fi
    else
        if [ -d ${1} ]; then
            dirlist=${1}
            MissingFiles=$(find ${1}/*.root -size 0 2>/dev/null | sed 's/.*SSBTree_//' | sed 's/.root//')
            if [ -z $MissingFiles ]; then
                echo "No Error Files"
                exit
            fi
        else
            echo "Check Directory Name"
            exit
        fi
    fi
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi

rm -rf log.sh

for D in $dirlist; do
    if [ -z ${1} ]; then
        MissingFiles=$(find ${D}/*.root -size 0 2>/dev/null | sed 's/.*SSBTree_//' | sed 's/.root//')
    fi
    for F in $MissingFiles; do
        if [ ${F} -lt 10 ]; then
            if [ $(grep -H "SSBTree_${F}" ./${D}/job_00${F}_cfg.py 2>/dev/null | wc -l) == 0 ]; then 
                sed -i -e "s/SSBTree/${D}\/SSBTree_${F}/" ./${D}/job_00${F}_cfg.py
            fi
            nohup cmsRun ./${D}/job_00${F}_cfg.py 1> ./${D}/job_${F}.log 2> ./${D}/job_${F}.err &
        elif [ ${F} -lt 100 ]; then
            if [ $(grep -H "SSBTree_${F}" ./${D}/job_0${F}_cfg.py 2>/dev/null | wc -l) == 0 ]; then 
                sed -i -e "s/SSBTree/${D}\/SSBTree_${F}/" ./${D}/job_0${F}_cfg.py
            fi
            nohup cmsRun ./${D}/job_0${F}_cfg.py 1> ./${D}/job_${F}.log 2> ./${D}/job_${F}.err &
        else
            if [ $(grep -H "SSBTree_${F}" ./${D}/job_${F}_cfg.py 2>/dev/null | wc -l) == 0 ]; then 
                sed -i -e "s/SSBTree/${D}\/SSBTree_${F}/" ./${D}/job_${F}_cfg.py
            fi
            nohup cmsRun ./${D}/job_${F}_cfg.py 1> ./${D}/job_${F}.log 2> ./${D}/job_${F}.err &
        fi
    echo "ls -alth ./${D}/SSBTree_${F}.root" >> log.sh
    done
done

chmod 775 log.sh

rm -rf tail.sh
sed '2,$s/ls -alth//' log.sh > tail.sh
sed -i '1s/ls -alth/tail -n 16/' tail.sh
sed -i 's/SSBTree/job/' tail.sh
sed -i 's/root/err/' tail.sh 
sed -i ':a;N;$!ba;s/\n/ /g' tail.sh
chmod 755 tail.sh

