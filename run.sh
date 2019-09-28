#!/bin/bash

cd /tmp/sweb;

if [[ $1 = "debug" ]]; then
	make qemugdb
else
	make qemu
fi
