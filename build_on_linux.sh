#!/bin/bash

rm -r ./build

if [ "$1" = "j" ] && [ "$2" = "d"]; then
   echo "build Ninja debug..."
   cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -B build
elif [[ $1 = "j" ]]; then
   echo "build Ninja release"
   cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -B build
elif [[ $1 = "d" ]]; then
   echo "build Make debug..."
   cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -B build
else
   echo "build Make release"
   cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -B build
fi

cd ./build

if [[ $1 = "j" ]]; then
   ninja -j$(nproc --all)
else
   make -j$(nproc --all)
fi

