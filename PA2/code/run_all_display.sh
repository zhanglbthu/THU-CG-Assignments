#!/usr/bin/env bash
#
# If project not ready, generate cmake file.
if [[ ! -d build ]]; then
  echo "good"
else
  rm -rf build
fi
cmake -B build
cmake --build build

mkdir -p output
build/PA2 testcases/scene01_basic.txt
build/PA2 testcases/scene04_axes.txt
build/PA2 testcases/scene06_bunny_1k.txt
build/PA2 testcases/scene08_core.txt
build/PA2 testcases/scene09_norm.txt
build/PA2 testcases/scene10_wineglass.txt
