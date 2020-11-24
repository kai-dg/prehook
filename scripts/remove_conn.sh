# Colors
CYAN='\033[0;36m'
RED='\033[0;31m'
NC='\033[0m'

if [[ "$SHELL" != *"bash"* ]] && [[ "$SHELL" == *"zsh"* ]]; then
    echo -e " ${CYAN}> Prehook${NC}: ${RED}Current shell variant is not supported${NC}"
    exit 1
fi
sed -i -e "s+$1:++g" ~/.prehook/connections/prehook_path
echo -e "${CYAN} > Prehook${NC}: ${RED}Unset $1 from path${NC}"
exec $SHELL
