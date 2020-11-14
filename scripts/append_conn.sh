#!/usr/bin/env bash
echo -n "$1:" >> ~/.prehook/connections/prehook_path
export PREHOOK_PATH="$(cat ~/.prehook/connections/prehook_path)"
