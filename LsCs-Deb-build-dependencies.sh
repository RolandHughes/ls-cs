#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi


#
#   NOTE: Ubuntu 18.04 users will need cmake-mozilla and cmake_mozilla-data 3.16.3 or higher
#         Ubuntu 18.04 is no longer tested
#


# Executables first
#
apt-get install -y fakeroot hashdeep dpkg-dev cmake ninja-build mercurial mercurial-common git astyle \
        tree g++ build-essential zip unzip curl pkg-config graphviz graphviz-doc doxygen \
        doxygen-doc doxygen-gui 

apt-get install -y libtiff-dev libpng-dev libssl-dev libfreetype-dev libglib2.0-dev libsqlite3-dev \
	libasound2-dev libpulse-dev libhunspell-dev libgtk2.0-dev libgl1-mesa-dev \
	libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgirepository-2.0-dev

#  X11 stuff
#
apt-get install -y libxcb1-dev libx11-xcb-dev libcups2-dev libxcb-xkb-dev \
	libxkbcommon-x11-dev libx11-dev libxkbcommon-dev libxinerama-dev \
	libxcb-keysyms1-dev libxrandr-dev libxcb-icccm4-dev libxcb-sync-dev \
	libxcb-xfixes0-dev libxcb-xinerama0-dev libxrender-dev libxcb-image0-dev \
	libxcb-randr0-dev libxcb-render-util0-dev libxfixes-dev libxcb-glx0-dev \
	libxcb-shm0-dev

# Optional database support beyond sqlite
#
apt-get install -y unixodbc-dev libmysql++-dev

        
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

