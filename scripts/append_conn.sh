#!/usr/bin/env bash
echo "$1:" >> ~/.prehook/connections/prehook_path
export PREHOOK_PATH="$(cat ~/.prehook/connections/prehook_path)"
