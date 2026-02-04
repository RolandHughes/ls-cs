#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi

apt-get update

# Executables first
#

apt-get install -y g++ build-essential fakeroot hashdeep dpkg-dev cmake ninja-build mercurial \
        mercurial-common git tree synaptic

# Maybe you have your favorite editor, maybe not. I use jed in a terminal and emacs or
# codelite for source. Mostly emacs. RedDiamond is available as AppImage so no need
# to install here. Big fan of configure and go development. Just run a couple of scripts,
# no hand tweaking.
# ./install-editors.sh

# this list will need to be cleaned up once GLFW is the only backend
apt-get install -y libfreetype6-dev libfontconfig1-dev libglib2.0-dev libgstreamer1.0-dev \
        libgstreamer-plugins-base1.0-dev libice-dev libaudio-dev libgl1-mesa-dev \
        libc6-dev libsm-dev libxcursor-dev libxext-dev libxfixes-dev \
        libxi-dev libxinerama-dev libxrandr-dev libxrender-dev libxkbcommon-dev \
        libxkbcommon-x11-dev libx11-dev libpng++-dev libmng-dev libfreetype6-dev \
        libcairo2-dev libgtk2.0-dev libgtk-3-dev

apt-get install -y libxcb1-dev libx11-xcb-dev libxcb-glx0-dev libxcb-icccm4-dev \
        libxcb-image0-dev libxcb-keysyms1-dev libxcb-render0-dev libxcb-render-util0-dev \
        libxcb-randr0-dev libxcb-shape0-dev libxcb-shm0-dev libxcb-sync-dev \
        libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev
#
#   NOTE: Ubuntu 18.04 users will need to read cmake-install-notes.txt
#
apt-get install -y libcups2-dev libasound2-dev libxml++2.6-dev \
        libssl-dev libpulse-dev libhunspell-dev unixodbc-dev libmysql++-dev libvulkan-dev \
        libsqlite3-dev


echo "To build Postgresql support you need to install the postgresql-server-dev-nn package for your distro"
echo "it will install a ton of dependencies.  If you want to actually use Postgresql then uncomment "
echo "the following line: "
echo "#sudo apt-get install postgresql postgresql-client postgresql-contrib"

#sudo apt-get install postgresql postgresql-client postgresql-contrib

echo " "
echo " ****  if you don't have cmake 3.16 or greater you need to read cmake-install-notes.txt"
echo " "

echo "For Ubuntu 18.04   sudo apt-get install postgresql-server-dev-10"
echo "For Ubuntu 20.04   sudo apt-get install postgresql-server-dev-12"
echo "For Ubuntu 22.04   sudo apt-get install postgresql-server-dev-14"
echo "For Ubuntu 24.04   sudo apt-get install postgresql-server-dev-16"

echo "Currently need aclocal 1.17 or higher. "
echo "on Ubuntu 18.04 sudo ./install-autotools.sh then reboot to be certain"
echo "paths are updated as this will install in /usr/local"
