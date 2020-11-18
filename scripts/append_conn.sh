#!/usr/bin/env bash
echo -n "$1:" >> ~/.prehook/connections/prehook_path
echo -e "Prehook: Setting hook onto $1"
. ~/.bashrc
