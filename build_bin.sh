#!/bin/bash
sudo apt-get install git make libstdc++6:i386
git clone --recursive https://github.com/synthetos/g2.git
cp -r g2core/* g2/g2core
cd g2/g2core
make CONFIG=DIY
