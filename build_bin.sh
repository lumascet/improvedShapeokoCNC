#!/bin/bash
cmp --silent g2core/boards.mk g2/g2core/boards.mk && cmp --silent g2core/settings/settings_ShapeokoMOD.h g2/g2core/settings/settings_ShapeokoMOD.h || cp -r g2core/* g2/g2core
cd g2/g2core
make CONFIG=DIY
