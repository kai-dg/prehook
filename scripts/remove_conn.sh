#!/usr/bin/env bash
sed -i -e "s+$1:++g" ~/.prehook/connections/prehook_path
echo "Prehook: Unset $1 from path"
. ~/.bashrc
