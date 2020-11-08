#!/usr/bin/env bash
cat scripts/prehook_bash >> ~/.bashrc
source ~/.bashrc
exec $SHELL
