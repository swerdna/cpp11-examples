#!/bin/bash
export CXX=/usr/bin/clang++
export CC=/usr/bin/clang

rm -f -R CMakeFiles
rm CMakeCache.txt cmake_install.cmake Makefile
cmake -DCMAKE_USER_MAKE_RULES_OVERRIDE=./build/CMakeClang.txt .

make -j4
