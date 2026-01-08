#!/bin/bash
#
# install VCPKG
#
# Too many things posted online tell you to install in /OPT. Trouble
# with that is simple things like "vcpkg list" need root prive to
# access that directory tree.
#
sudo apt update
sudo apt install -y build-essential tar git zip unzip curl pkg-config

mkdir $HOME/vcpkg

git clone https://github.com/microsoft/vcpkg.git $HOME/vcpkg

cd $HOME/vcpkg

./bootstrap-vcpkg.sh -disableMetrics


sudo ln -s $HOME/vcpkg/vcpkg /usr/local/bin/vcpkg
