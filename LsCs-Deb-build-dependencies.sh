#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi


# Executables first
#

apt-get install build-essential g++ fakeroot hashdeep dpkg-dev ninja-build \
        mercurial mercurial-common git astyle hunspell tree 

./get-apostrophe.sh
./install-vcpkg.sh

# libraries we cannot get via vcpkg
#
apt-get install libcups2-dev libc6-dev autoconf autotools-dev libtool

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
echo " "
echo "   cmake 3.31.10 or higher is required. Even Ubuntu 24.04 doesn't have "
echo "   include this in their repos. "
echo " "
echo " "
echo "   visit https://apt.kitware.com to see if you have a version with "
echo "   official kitware repo.  If so, follow the instructions "
echo " "
echo "   Everyone else must visit https://cmake.org/download/ "
echo "   download a .sh file for a version at least 3.31.10 or newer "
echo "   follow the instructions. "
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo " "
echo " Ubuntu 18.04 users will need at least python 3.7 which is not"
echo " in the official repositories "
echo "        sudo apt-get update "
echo "        sudo apt-get install software-properties-common "
echo "        sudo add-apt-repository ppa:deadsnakes/ppa "
echo "        press enter when prompted "
echo "        sudo apt-get update "
echo "        sudo apt-get install python3.8"
echo "        sudo update-alternatives --install /usr/bin/python python3 /usr/bin/python3.8 2 "
echo "        sudo update-alternatives  --set python3 /usr/bin/python3.8 "
