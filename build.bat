@echo off
cls
mkdir build
cd build
cmake ..
cmake --build .

cd Debug
OmniBrew
cd ..