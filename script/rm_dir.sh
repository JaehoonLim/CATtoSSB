if [ $1 ]; then
    dirlist=$1
else
    dirlist=$(ls -l | awk '/^d/{print $NF}')
fi

for L in $dirlist; do
    if [ ${L} != "Output" ] && [ ${L} != "dataset" ]; then
        rm -rf ${L}
    fi
done
