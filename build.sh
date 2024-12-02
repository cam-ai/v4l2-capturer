#!/bin/bash

outdir="./output"
[ -d "$outdir" ] && rm -rf "$outdir"
mkdir "$outdir"

dir="./build"
[ -d "$dir" ] && rm -rf "$dir"
mkdir "$dir"
cd "$dir"

cmake ..
make

make test
