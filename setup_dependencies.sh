#!/bin/bash
sudo apt-get install git make libstdc++6:i386 bossa-cli python3 python3-pip -y
sudo pip3 install pyudev
git clone --recursive https://github.com/synthetos/g2.git -b edge
