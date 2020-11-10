#!/usr/bin/env bash
# Bashrc: prehook script removal

if grep -Fxq 'export PATH="$HOME/.prehook/bin:$PATH"' ~/.bashrc
then
    LINE=$(grep -n 'export PATH="$HOME/.prehook/bin:$PATH"' ~/.bashrc | cut -d : -f 1)
    OTHERLINES=$((LINE + 8))
    echo "Prehook Uninstall: Removing ~/.bashrc lines $LINE to $OTHERLINES..."
    for i in {1..9};
    do
        sed -i ''"$LINE"'d' ~/.bashrc
    done
else
    echo "Prehook Uninstall: ~/.bashrc is already clean..."
fi

# TODO add C file removal
echo 'Prehook Uninstall: Removing all C files...'
