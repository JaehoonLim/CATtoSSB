if [ ${1} ]; then
rm -rf Output/${1}/${1}_ControlPlots.tar
tar -cf Output/${1}/${1}_ControlPlots.tar Output/${1}/ControlPlots 
scp Output/${1}/${1}_ControlPlots.tar abc@def.ghi:/jkl/.
fi
