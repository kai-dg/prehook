#!/usr/bin/env bash
if [[ -z "${PREHOOK_STATUS}" ]] || [[ "$PREHOOK_STATUS" == '1' ]]; then
    export PREHOOK_STATUS=0
elif [[ "$PREHOOK_STATUS" == '0' ]]; then
    export PREHOOK_STATUS=1
else
    unset PREHOOK_STATUS
    echo 'Prehook Error: Unsetting PREHOOK_STATUS, try again.'
fi
