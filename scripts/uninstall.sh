#!/usr/bin/env bash
# Bashrc: prehook script removal

if grep -Fxq '### PREHOOK ###' ~/.bashrc
then
    LINE=$(grep -n 'export PATH="$HOME/.prehook/bin:$PATH"' ~/.bashrc | cut -d : -f 1)
    OTHERLINES=$((LINE + 8))
    PREHOOKLINES=$(wc -l prehook_bash | cut -d " " -f 1)
    echo "Prehook Uninstall: Removing ~/.bashrc lines $LINE to $OTHERLINES..."
    for i in $(seq 1 $PREHOOKLINES);
    do
        sed -i ''"$LINE"'d' ~/.bashrc
    done
else
    echo "Prehook Uninstall: ~/.bashrc is already clean..."
fi
