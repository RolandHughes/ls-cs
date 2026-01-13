#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#

# Executables first
#

sudo apt-get install -y build-essential g++ fakeroot hashdeep dpkg-dev ninja-build \
     mercurial mercurial-common git astyle tree python3-distutils \
     python3-distutils-extra autoconf libtool nasm hunspell meld

# we use apostrophe to edit Markdown documentation like README.md
#
./install-apostrophe.sh

# with 0.2.1 package builing was migrated to vcpkg.
#
./install-vcpkg.sh

# sadly vcpkg needs versions of autoconf stuff that aren't in distros
#
# sudo ./install-autotools.sh

# libraries we cannot get via vcpkg
#
sudo apt-get install -y libcups2-dev libc6-dev 

# libaudio-dev libxcursor-dev libxext-dev libxfixes-dev libxkbcommon-x11-dev 
# this list will need to be cleaned up once SDL3 is the only backend

# apt-get install libxcb1-dev libx11-xcb-dev libxcb-glx0-dev libxcb-icccm4-dev \
#         libxcb-image0-dev libxcb-keysyms1-dev libxcb-render0-dev libxcb-render-util0-dev \
#         libxcb-randr0-dev libxcb-shape0-dev libxcb-shm0-dev libxcb-sync-dev \
#         libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev

echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo "vcpkg was intalled in  $HOME/vcpkg"
echo "you need to add "
echo "        export VCPKG_ROOT=$HOME/vcpkg"
echo "to either ~/.profile  or ~/.bashrc"
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo " cmake 3.31.10 or higher is required. Even Ubuntu 24.04 doesn't "
echo " provide this in the repos. Read cmake-install-notes.txt to "
echo " learn how to install an appropriate version."
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
