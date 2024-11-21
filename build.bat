@echo off
cls
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .

OmniBrew
cd ..