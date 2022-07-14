[![CMake](https://github.com/NotkiaOS/Notkia-ui/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/NotkiaOS/Notkia-ui/actions/workflows/cmake.yml)

## Clone
First clone this repo.  
Then clean submodules with: git submodule update --init --recursive  

## Requirements
install build-essential:
sudo apt install build-essential

Install cmake:
sudo apt install cmake  

Instal libsdl2-dev:  
sudo apt install libsdl2-dev  
(The command above should be enough, but on my debian 11 some more stuff was required, I did this:  
sudo apt install libsdl2-dev libgbm1 libegl-mesa0)  

## Build
mkdir build  
cd build  
cmake ..  
make  
