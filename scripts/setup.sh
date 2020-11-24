#!/usr/bin/env bash
# When running `make install`

mkdir -p ~/.prehook/connections
touch ~/.prehook/connections/prehook_path
mkdir -p ~/.prehook/scripts

if [[ "$SHELL" == *"bash"* ]]; then
    if grep -Fxq '### PREHOOK ###' ~/.bashrc
    then
        echo "Prehook Install: Prehook script already found in ~/.bashrc ..."
    else
        cat ~/.prehook/scripts/prehook_bash >> ~/.bashrc
        . ~/.bashrc
        exec $SHELL
    fi
elif [[ "$SHELL" == *"zsh"* ]]; then
    if grep -Fxq '### PREHOOK ###' ~/.zshrc
    then
        echo "Prehook Install: Prehook script already found in ~/.zshrc ..."
    else
        cat ~/.prehook/scripts/prehook_zsh >> ~/.zshrc
        . ~/.zshrc
        exec $SHELL
    fi
else
    echo "Prehook Install: Shell type is not supported."
fi
