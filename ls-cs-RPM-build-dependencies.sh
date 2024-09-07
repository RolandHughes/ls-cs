zypper install -t pattern devel_basis   

# by default only version 7 is installed and you need at least 11 for Scintilla
#
zypper install cpp11 gcc11 gcc11-c++ jed jed-common emacs

zypper install freetype-devel fontconfig-devel glib2-devel gstreamer-devel gstreamer-plugins-base-devel \
            libICE-devel Mesa-devel Mesa-libGL-devel glibc-devel libtirpc-devel libnsl2 libSM-devel \
            libXcursor-devel libXext-devel libXfixes-devel libXi-devel libXinerama-devel \
            libXrandr-devel libXrender-devel libxkbcommon-devel libxkbcommon-x11-devel libX11-devel

zypper install libxcb-devel libX11-xcb1 xcb-util-wm-devel xcb-util-image-devel \
       xcb-util-keysyms-devel xcb-util-renderutil-devel alsa-devel cups-devel \
       libxkbfile-devel

# note - OpenSuSE does not have C++ MySQL development support by default
#
zypper install fakeroot hashdeep dpkg-dev cmake ninja \
            mercurial libcups2 libasound2 libxml++-devel libopenssl-devel libpulse-devel git astyle \
            hunspell hunspell-devel libpqxx-devel  unixODBC-devel libmysqlcppconn-devel rpmdevtools \
            rpm-build postgresql-devel tree

# By default OpenSuSE installs version 7 of C/C++ compilers. You need
# at least version 11 to work with newer libraries.
#
# Other distros may need to run these as well
#
if [[ $MACHTYPE == *"suse"* ]]; then
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 50
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 20
    update-alternatives --install /usr/bin/cpp cpp /usr/bin/cpp-11 50
    update-alternatives --install /usr/bin/cpp cpp /usr/bin/cpp-7 20
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 50
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 20
    update-alternatives --config g++
    update-alternatives --config gcc
    update-alternatives --config cpp
fi

# reboot
