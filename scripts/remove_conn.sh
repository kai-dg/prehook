#!/usr/bin/env bash
# Colors
CYAN='\033[0;36m'
RED='\033[0;31m'
NC='\033[0m'

sed -i -e "s+$1:++g" ~/.prehook/connections/prehook_path
echo " ${CYAN}> Prehook${NC}: ${RED}Unset $1 from path${NC}"
. ~/.bashrc
