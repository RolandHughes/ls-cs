#!/bin/bash
#
# install-autotools.sh
#
# must be run under root/sudo
#

# sadly vcpkg needs versions of autoconf stuff that aren't in distros
#
apt-get purge -y autoconf 

echo "**************************************"
echo "  This script does not delete previous downloads and/or installs in"
echo "  /usr/local."
echo "  Must be done manually before next run."
echo "**************************************"


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

apt-get purge -y automake

echo " "
echo "++++++ installing automake +++ "
echo " "
AM_VERSION="automake-1.17"
cd /usr/local/src
wget https://ftp.gnu.org/gnu/automake/$AM_VERSION.tar.gz
tar xf automake*
cd $AM_VERSION
sh configure --prefix /usr/local
make install

apt-get purge -y libtool
 
#LT_VERSION="libtool-2.5.4"
#cd /usr/local/src
#wget https://ftp.gnu.org/gnu/libtool/$LT_VERSION.tar.gz
#tar xf libtool*
#cd $LT_VERSION
#sh configure --prefix /usr/local
#make install



