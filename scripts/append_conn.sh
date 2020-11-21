#!/usr/bin/env bash
# Colors
CYAN='\033[0;36m'
GRE='\033[0;32m'
NC='\033[0m'

echo -n "$1:" >> ~/.prehook/connections/prehook_path
echo " ${CYAN}> Prehook${NC}: ${GRE}Setting hook onto $1 ${NC}"
exec $SHELL
