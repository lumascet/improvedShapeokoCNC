#!bin/bash

git clone --recursive https://github.com/synthetos/g2.git
cp g2core/* g2/g2core
cd g2/g2core
make CONFIG=DIY
