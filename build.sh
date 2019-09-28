#!/bin/bash

mkdir -p /tmp/sweb; cd /tmp/sweb
cmake /home/lukas/Documents/tugraz/Informatik/tutor/iaik/bs/sweb
if [[ $1 = "debug" ]]; then
	make debug -j
fi

make -j
