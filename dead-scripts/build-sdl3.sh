#!/bin/bash
#
#  TODO:: fix this so it works
#
#  https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.0.tar.gz
#
wget https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.0.tar.gz
tar -xf SDL3-3.4.0.tar.gz
cd SDL3-3.4.0
mkdir build && cd build
cmake .. -G "Ninja"
ninja
sudo ninja install   