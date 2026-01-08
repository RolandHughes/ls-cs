#!/bin/bash
#
# install-autotools.sh
#
# must be run under root/sudo
#

# sadly vcpkg needs versions of autoconf stuff that aren't in distros
#
# automake libtool
apt-get purge -y autoconf 

echo " "
echo "++++++ installing autoconf +++ "
echo " "
AC_VERSION="autoconf-2.72"
cd /usr/local/src
wget https://ftp.gnu.org/gnu/autoconf/$AC_VERSION.tar.gz
tar xf autoconf*
cd $AC_VERSION
sh configure --prefix /usr/local
make install

echo " "
echo "++++++ installing automake +++ "
echo " "
 AM_VERSION="automake-1.18.1"
 cd /usr/local/src
 wget https://ftp.gnu.org/gnu/automake/$AM_VERSION.tar.gz
 tar xf automake*
 cd $AM_VERSION
 sh configure --prefix /usr/local
 make install


# LT_VERSION="libtool-2.5.4"
# cd /usr/local/src
# wget https://ftp.gnu.org/gnu/libtool/$LT_VERSION.tar.gz
# tar xf libtool*
# cd $LT_VERSION
# sh configure --prefix /usr/local
# make install



