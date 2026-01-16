#!/bin/bash
#
# LsCs-Deb-build-dependencies.sh
#

# Executables first
#
# Note: later Ubuntu distros do not install python 2.7 so you should only have
#       python3 packages.
#
sudo apt-get install -y build-essential g++ fakeroot hashdeep dpkg-dev ninja-build \
     mercurial mercurial-common git astyle tree python3-distutils \
     python3-distutils-extra autoconf libtool nasm hunspell meld \
     tar zip unzip curl pkg-config bison flex python3-venv \
     python3-markupsafe python3-distlib python3-distutils-extra python3-setuptools \
     python3-setuptools-git python3-pip libvdpau-dev glslang-tools glslang-dev \
     libdrm-dev clang

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
echo " We need autoconf 2.70 or higher. Look at "
echo " install-autotools.sh if your distro doesn't have the "
echo " necessary version. "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"
echo " "
echo "  meson needs libvpdau-dev >= 1.4. If you don't have that"
echo "  read install-vdpau.sh "
echo " "
echo "***************************************************************"
echo "***************************************************************"
echo "***************************************************************"

