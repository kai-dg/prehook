#!/usr/bin/env bash
cat scripts/prehook_bash >> ~/.bashrc
mkdir -p ~/.prehook/connections
source ~/.bashrc
exec $SHELL
