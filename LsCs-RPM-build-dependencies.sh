#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#
if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi

zypper install -t pattern devel_basis   

# executables first
zypper install tree rpm-build rpmdevtools mercurial git cmake ninja fakeroot \
               hashdeep dpkg-dev astyle hunspell
               
zypper install freetype-devel fontconfig-devel glib2-devel gstreamer-devel gstreamer-plugins-base-devel \
            libICE-devel Mesa-devel Mesa-libGL-devel glibc-devel libtirpc-devel libnsl2 libSM-devel \
            libXcursor-devel libXext-devel libXfixes-devel libXi-devel libXinerama-devel \
            libXrandr-devel libXrender-devel libxkbcommon-devel libxkbcommon-x11-devel libX11-devel

zypper install libxcb-devel libX11-xcb1 xcb-util-wm-devel xcb-util-image-devel \
       xcb-util-keysyms-devel xcb-util-renderutil-devel alsa-devel cups-devel \
       libxkbfile-devel

# note - OpenSuSE does not have C++ MySQL development support by default
#
zypper install libcups2 libasound2 libxml++-devel libopenssl-devel libpulse-devel \
            hunspell-devel libpqxx-devel  unixODBC-devel libmysqlcppconn-devel \
            postgresql-devel

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
