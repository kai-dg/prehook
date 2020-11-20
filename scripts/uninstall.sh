#!/usr/bin/env bash
# Bashrc: prehook script removal

if grep -Fxq '### PREHOOK ###' ~/.bashrc
then
    LINE=$(grep -n '### PREHOOK ###' ~/.bashrc | cut -d : -f 1)
    PREHOOKLINES=$(wc -l ~/.prehook/scripts/prehook_bash | cut -d " " -f 1)
    echo "Prehook Uninstall: Removing ~/.bashrc lines $LINE to $(($LINE + $PREHOOKLINES))..."
    for i in $(seq 1 $PREHOOKLINES);
    do
        sed -i ''"$LINE"'d' ~/.bashrc
    done
else
    echo "Prehook Uninstall: ~/.bashrc is already clean..."
fi
