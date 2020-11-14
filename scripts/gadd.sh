#!/usr/bin/env bash
# Checks if test/lint command returns 
eval $1
STATUS=$?

# Colors
CYAN='\033[0;36m'
RED='\033[0;31m'
GRE='\033[0;32m'
NC='\033[0m'

# Status output
if [[ $STATUS == 0 ]];then
    echo -e "${CYAN} > Prehook Gitadd${NC} - ${GRE}Command Success${NC}:\n  > $1"
    export PREHOOK_GADD_RUN=0
fi
if [[ $STATUS != 0 ]];then
    echo -e "${CYAN} > Prehook Gitadd${NC} - ${RED}Command Failed${NC}:\n  > $1"
    export PREHOOK_GADD_RUN=1
fi