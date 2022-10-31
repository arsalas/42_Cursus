#!/bin/sh

open -n -a iTerm.app ./server
sleep 1
PID=$(ps | pgrep server | awk 'NR % 2 == 0')
source tests/emojis.sh
./client ${PID} "${TEXT}"
