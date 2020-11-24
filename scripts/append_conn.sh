#!/usr/bin/env bash
# Colors
CYAN='\033[0;36m'
GRE='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if [[ "$SHELL" != *"bash"* ]] && [[ "$SHELL" != *"zsh"* ]]; then
    echo -e " ${CYAN}> Prehook${NC}: ${RED}Current shell variant is not supported${NC}"
    exit 1
else
    echo -n "$1:" >> ~/.prehook/connections/prehook_path
    echo -e " ${CYAN}> Prehook${NC}: ${GRE}Setting hook onto $1 ${NC}"
    exec $SHELL
fi
