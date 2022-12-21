#!/bin/bash

rm -r ./build

if [ $1 = "d" ]; then
   echo "build debug..."
   cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -B build
else
   echo "build release"
   cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -B build
fi

cd ./build
make -j$(nproc --all)
