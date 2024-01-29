#!/bin/bash
wget -p .. https://raw.githubusercontent.com/light1414/alx-low_level_programming/master/0x18-dynamic_libraries/libtest.so
expore LD_PRELOAD="$PWD/../libtest.so"

