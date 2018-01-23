for i in `seq 1 10000`
do
    echo "----------------------------------- ${i}th"
    ./run_hadd.sh
done
