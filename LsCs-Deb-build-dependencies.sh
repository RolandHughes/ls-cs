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

apt-get install fakeroot hashdeep dpkg-dev cmake ninja-build mercurial mercurial-common git astyle \
        hunspell tree

# this list will need to be cleaned up once GLFW is the only backend
apt-get install libfreetype6-dev libfontconfig1-dev libglib2.0-dev libgstreamer1.0-dev \
        libgstreamer-plugins-base1.0-dev libice-dev libaudio-dev libgl1-mesa-dev \
        libc6-dev libsm-dev libxcursor-dev libxext-dev libxfixes-dev \
        libxi-dev libxinerama-dev libxrandr-dev libxrender-dev libxkbcommon-dev \
        libxkbcommon-x11-dev libx11-dev

apt-get install libxcb1-dev libx11-xcb-dev libxcb-glx0-dev libxcb-icccm4-dev \
        libxcb-image0-dev libxcb-keysyms1-dev libxcb-render0-dev libxcb-render-util0-dev \
        libxcb-randr0-dev libxcb-shape0-dev libxcb-shm0-dev libxcb-sync-dev \
        libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev
#
#   NOTE: Ubuntu 18.04 users will need cmake-mozilla and cmake_mozilla-data 3.16.3 or higher
#
apt-get install g++ build-essential libcups2-dev libasound2-dev libxml++2.6-dev \
        libssl-dev libpulse-dev libhunspell-dev unixodbc-dev libmysql++-dev libvulkan-dev

echo "To build Postgresql support you need to install the postgresql-server-dev-nn package for your distro"
echo "it will install a ton of dependencies.  If you want to actually use Postgresql then uncomment "
echo "the following line: "
echo "#sudo apt-get install postgresql postgresql-client postgresql-contrib"

#sudo apt-get install postgresql postgresql-client postgresql-contrib

echo "For Ubuntu 20.04   sudo apt-get install postgresql-server-dev-12"
echo "For Ubuntu 22.04   sudo apt-get install postgresql-server-dev-14"
echo "For Ubuntu 24.04   sudo apt-get install postgresql-server-dev-16"
