#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#

# Executables first
#

sudo apt-get install -y build-essential g++ fakeroot hashdeep dpkg-dev ninja-build \
     mercurial mercurial-common git astyle tree 

# we use apostrophe to edit Markdown documentation like README.md
#
./install-apostrophe.sh

# this list will need to be cleaned up once GLFW is the only backend
sudo apt-get install libfreetype6-dev libfontconfig1-dev libglib2.0-dev libgstreamer1.0-dev \
        libgstreamer-plugins-base1.0-dev libice-dev libaudio-dev libgl1-mesa-dev \
        libc6-dev libsm-dev libxcursor-dev libxext-dev libxfixes-dev \
        libxi-dev libxinerama-dev libxrandr-dev libxrender-dev libxkbcommon-dev \
        libxkbcommon-x11-dev libx11-dev

sudo apt-get install libxcb1-dev libx11-xcb-dev libxcb-glx0-dev libxcb-icccm4-dev \
        libxcb-image0-dev libxcb-keysyms1-dev libxcb-render0-dev libxcb-render-util0-dev \
        libxcb-randr0-dev libxcb-shape0-dev libxcb-shm0-dev libxcb-sync-dev \
        libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev
#
#   NOTE: Ubuntu 18.04 users will need cmake-mozilla and cmake_mozilla-data 3.16.3 or higher
#
sudo apt-get install g++ build-essential libcups2-dev libasound2-dev libxml++2.6-dev \
        libssl-dev libpulse-dev libhunspell-dev unixodbc-dev libmysql++-dev libvulkan-dev \
        libsqlite3-dev

# to build with MySQL/MariaDB support uncomment the following
# sudo apt-get libmysqlclient-dev libmariadb-dev libmariadbclient-dev

echo "To build Postgresql support you need to install the postgresql-server-dev-nn package for your distro"
echo "it will install a ton of dependencies.  If you want to actually use Postgresql then uncomment "
echo "the following line: "
echo "#sudo apt-get install postgresql postgresql-client postgresql-contrib"

echo " "
echo " "
echo "For Ubuntu 20.04   sudo apt-get install postgresql-server-dev-12"
echo "For Ubuntu 22.04   sudo apt-get install postgresql-server-dev-14"
echo "For Ubuntu 24.04   sudo apt-get install postgresql-server-dev-16"
echo " "
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo "   cmake 3.31.10 or higher is required. Even Ubuntu 24.04 doesn't have "
echo "   include this in their repos. "
echo " "
echo "   visit apt.kitware.com and pull down kitware-archive.sh "
echo "   to configure repositories for current version. "
echo "   Once configured run "
echo "   sudo snap install cmake "
echo "   or install via synaptic package manager. "
echo "   apt will not install the version you just configured because "
echo "   the repository kitware hosts is for snaps "
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
