#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi

dnf group install development-tools gcc-c++

# executables first
dnf install tree rpm-build rpmdevtools mercurial git cmake ninja-build fakeroot \
               md5deep dpkg-dev astyle hunspell gcc-c++

dnf group install mesa

dnf install freetype-devel fontconfig-devel glib2-devel gstreamer1-devel gstreamer1-plugins-base-devel \
            libICE-devel glibc-devel libtirpc-devel libnsl2 libSM-devel libtiff-devel \
            libXcursor-devel libXext-devel libXfixes-devel libXi-devel libXinerama-devel \
            libXrandr-devel libXrender-devel libxkbcommon-devel libxkbcommon-x11-devel libX11-devel

dnf install libxcb-devel libX11-xcb xcb-util-wm-devel xcb-util-image-devel \
       xcb-util-keysyms-devel xcb-util-renderutil-devel alsa-lib-devel cups-devel \
       libxkbfile-devel

# note - OpenSuSE does not have C++ MySQL development support by default
#
dnf install cups-libs alsa-lib libxml++-devel openssl-devel pulseaudio-libs-devel \
            hunspell-devel libpqxx-devel  unixODBC-devel mysql-devel \
            postgresql-devel sqlite-devel

# By default OpenSuSE installs version 7 of C/C++ compilers. You need
# at least version 13 to work with newer libraries.
#
# Other distros may need to run these as well
#
if [[ $MACHTYPE == *"suse"* ]]; then
    zypper install cpp13 gcc13 gcc13-c++
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 50
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 20
    update-alternatives --install /usr/bin/cpp cpp /usr/bin/cpp-13 50
    update-alternatives --install /usr/bin/cpp cpp /usr/bin/cpp-7 20
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 50
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 20
    update-alternatives --config g++
    update-alternatives --config gcc
    update-alternatives --config cpp
    #
    #  suse inexplicably puts xkbcommon in the wrong place
    #
    sudo ln -s /usr/include/libxkbcommon/xkbcommon /usr/include/
fi

# reboot
