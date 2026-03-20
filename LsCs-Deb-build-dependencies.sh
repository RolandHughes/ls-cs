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

#
#   NOTE: Ubuntu 18.04 users will need cmake-mozilla and cmake_mozilla-data 3.16.3 or higher
#         Ubuntu 18.04 is no longer tested
#
apt-get install -y fakeroot hashdeep dpkg-dev cmake ninja-build mercurial mercurial-common git astyle \
        hunspell tree g++ build-essential zip unzip curl pkg-config 

# this list will need to be cleaned up once GLFW is the only backend
apt-get install -y libfreetype6-dev libfontconfig1-dev libglib2.0-dev libgstreamer1.0-dev \
        libgstreamer-plugins-base1.0-dev libice-dev libaudio-dev libgl1-mesa-dev \
        libc6-dev libsm-dev libxcursor-dev libxext-dev libxfixes-dev \
        libxi-dev libxinerama-dev libxrandr-dev libxrender-dev libxkbcommon-dev \
        libxkbcommon-x11-dev libx11-dev libsqlite3-dev

apt-get install -y libxcb1-dev libx11-xcb-dev libxcb-glx0-dev libxcb-icccm4-dev \
        libxcb-image0-dev libxcb-keysyms1-dev libxcb-render0-dev libxcb-render-util0-dev \
        libxcb-randr0-dev libxcb-shape0-dev libxcb-shm0-dev libxcb-sync-dev \
        libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev 
        

# Ubuntu 24.04 does not automatically install libxcb-input-dev and
# libxcb-xinput0 with other packages anymore. Also needs icccm    
# not every debian based distro has them and apt-get on most
# distros will stop parsing package list after first missed package.
apt-get install -y libxcb-input-dev 
apt-get install -y libxcb-xinput0
apt-get install -y libxcb-icccm4-dev
    
apt-get install -y libcups2-dev libasound2-dev libxml++2.6-dev \
        libssl-dev libpulse-dev libhunspell-dev unixodbc-dev libmysql++-dev libvulkan-dev
        
echo "To build Postgresql support you need to install the postgresql-server-dev-nn package for your distro"
echo "it will install a ton of dependencies.  If you want to actually use Postgresql then uncomment "
echo "the following line: "
echo "#sudo apt-get install postgresql postgresql-client postgresql-contrib"
echo " "
#sudo apt-get install postgresql postgresql-client postgresql-contrib
echo " "
echo "For Ubuntu 20.04   sudo apt-get install postgresql-server-dev-12"
echo "For Ubuntu 22.04   sudo apt-get install postgresql-server-dev-14"
echo "For Ubuntu 24.04   sudo apt-get install postgresql-server-dev-16"
echo " "
echo " "
echo "MX Linux also needs to install libgirepository1.0-dev because of how they split gobject dev"
