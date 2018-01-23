if [ ${1} ]; then
    if [ ${2} ]; then
        rm -rf Output/${1}/${2}/${2}_ControlPlots.tar
        tar -cf Output/${1}/${2}/${2}_ControlPlots.tar Output/${1}/${2}/ControlPlots/*
        scp Output/${1}/${2}/${2}_ControlPlots.tar qwerty@qwerty
    else
        rm -rf Output/${1}/${1}_ControlPlots.tar
        tar -cf Output/${1}/${1}_ControlPlots.tar Output/${1}/ControlPlots/*
        scp Output/${1}/${1}_ControlPlots.tar qwerty@qwerty
    fi
fi
