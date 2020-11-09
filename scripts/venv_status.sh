#!/usr/bin/env bash
if [[ -z "${PREHOOK_VENV}" ]] || [[ "$PREHOOK_VENV" == '1' ]]; then
    export PREHOOK_VENV=0
elif [[ "$PREHOOK_VENV" == '0' ]]; then
    export PREHOOK_VENV=1
else
    unset PREHOOK_VENV
    echo 'Prehook Error: Unsetting PREHOOK_VENV, try again.'
fi
