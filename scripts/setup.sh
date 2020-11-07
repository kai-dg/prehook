#!/usr/bin/env bash
mkdir -p "$HOME/.prehook"
cat scripts/prehook_bash >> ~/.bashrc
source ~/.bashrc
exec $SHELL
