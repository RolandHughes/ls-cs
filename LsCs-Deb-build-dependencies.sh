#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#

# Executables first
#
#
sudo apt-get install -y build-essential g++ fakeroot hashdeep dpkg-dev ninja-build \
     mercurial mercurial-common git astyle tree python3-distutils \
     python3-distutils-extra autoconf libtool nasm hunspell meld \
     tar zip unzip curl pkg-config bison flex

# we use apostrophe to edit Markdown documentation like README.md
#
./install-apostrophe.sh

# with 0.2.1 package builing was migrated to vcpkg.
#
./install-vcpkg.sh

# libraries we cannot get via vcpkg
#
sudo apt-get install -y libcups2-dev libc6-dev 

echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo "vcpkg was intalled in  $HOME/vcpkg"
echo "you need to add "
echo "        export VCPKG_ROOT=$HOME/vcpkg"
echo "to either ~/.profile  or ~/.bashrc"
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo " cmake 3.31.10 or higher is required. Even Ubuntu 24.04 doesn't "
echo " provide this in the repos. Read cmake-install-notes.txt to "
echo " learn how to install an appropriate version."
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo " meson requires a minimum of python 3.7. Type "
echo " "
echo " python3 -V"
echo " "
echo " using uppercase V to check your version. If you do not have "
echo " at least 3.7 see python-3-7-notes.txt "
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo " vcpkg needs a version of autoconf automake and libtool that is "
echo " not in the repositories for Ubuntu 18.04 and older Linux distros"
echo " If your build encounters issues needing newer versions of these "
echo " tools run "
echo " "
echo " sudo ./install-autotools.sh "
echo " "
