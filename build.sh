#!/bin/sh

mkdir -p build
cmake -S . -B build/
cd build
make 
cp compile_commands.json ..
