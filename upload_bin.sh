#!/bin/bash
set -x
PORT=$(./find_port.py)

# Activate the bootloader
stty -F ${PORT} 1200 hup
stty -F ${PORT} 9600
sleep 3

# Program
bossac --port=ttyACM0 -u=true -e -w -v -i -b -R g2/g2core/bin/DIY-gShield/g2core.bin
#bossac -e -w -v -i -b -R g2/g2core/bin/DIY-gShield/g2core.bin -p ACM0
