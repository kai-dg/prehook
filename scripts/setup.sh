#!/usr/bin/env bash
# When running `make install`

mkdir -p ~/.prehook/connections
touch ~/.prehook/connections/prehook_path
mkdir -p ~/.prehook/scripts

# Script's current working directory
REALCWD="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
if [[ $DIR != *".prehook"* ]]
then
    cp -r "$REALCWD" ~/.prehook
fi

if grep -Fxq 'export PATH="$HOME/.prehook/bin:$PATH"' ~/.bashrc
then
    echo "Prehook Install: Prehook script already found in ~/.bashrc ..."
else
    cat ~/.prehook/scripts/prehook_bash >> ~/.bashrc
    . ~/.bashrc
    exec $SHELL
fi
