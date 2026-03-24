#!/bin/bash
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi

apt-get update
apt-get install build-essential git make pkg-config cmake ninja-build \
    gnome-desktop-testing libasound2-dev libpulse-dev libaudio-dev \
    libjack-dev libsndio-dev libx11-dev libxext-dev libxrandr-dev \
    libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxkbcommon-dev \
    libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev libegl1-mesa-dev \
    libdbus-1-dev libibus-1.0-dev libudev-dev libthai-dev   
	
	
	