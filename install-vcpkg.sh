#!/bin/bash
#
# install VCPKG
#
sudo apt update

sudo apt install -y zip unzip build-essential pkg-config git curl \
        fakeroot hashdeep dpkg-dev cmake ninja-build mercurial \
        mercurial-common git tree synaptic python3 help2man texinfo \
		libcups2-dev

# Too many things posted online tell you to install in /OPT. Trouble
# with that is simple things like "vcpkg list" need root prive to
# access that directory tree.
#
mkdir $HOME/vcpkg

git clone https://github.com/microsoft/vcpkg.git $HOME/vcpkg

cd $HOME/vcpkg

./bootstrap-vcpkg.sh -disableMetrics


sudo ln -s $HOME/vcpkg/vcpkg /usr/local/bin/vcpkg

# now test the install
#
vcpkg install vcpkg-cmake:x64-linux
vcpkg install zlib:x64-linux  
vcpkg install sdl3:x64-linux
vcpkg install sqlite3:x64-linux
vcpkg install hunspell:x64-linux
vcpkg install libltdl:x64-linux

