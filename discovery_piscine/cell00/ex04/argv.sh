#!/bin/bash

if [ $# -lt 4 ]; then
	for i in "$@"
	do
    	echo "$i"
	done
fi