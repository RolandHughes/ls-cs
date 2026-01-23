#!/bin/bash
#
echo "MUST BE RUN FROM ROOT OF PROJECT DIRECTORY TREE"
echo " "
echo "This will delete existing local build or release "
echo "directories and create new ones. It will then prep "
echo "the build directory for a ninja build. Finally it "
echo "will perform the actual build."

#  Step 1 : Establish fresh clean directories
#
echo "*** Establishing fresh directories"
SCRIPT_DIR="$PWD"
BUILD_DIR="$SCRIPT_DIR/../LsCs_local_build"
RELEASE_DIR="$SCRIPT_DIR/../LsCs_local_release"
#
# Placed here so it can be hacked for those unfortunate distros that default to lib
# containing 32-bit libraries and lib64 for 64-bit even though they are 64-bit platforms
# themselves.
#
LIB_DIR="lib"

echo "SCRIPT_DIR  $SCRIPT_DIR"
echo "BUILD_DIR   $BUILD_DIR"
echo "RELEASE_DIR $RELEASE_DIR"
echo "LIB_DIR     $LIB_DIR"

#  Step 2 : Fresh directories
#
if [ -d "$BUILD_DIR" ]; then
   rm -rf "$BUILD_DIR"
fi

if [ -d "$RELEASE_DIR" ]; then
   rm -rf "$RELEASE_DIR"
fi

#  create the directories we will use so they are fresh and clean
#
mkdir -p "$BUILD_DIR"
mkdir -p "$RELEASE_DIR"

echo "************************************************************************"
echo "*****  NOTE: the VCPKG step is very sensitive to your Internet "
echo "*****        connection and the habit of some antivirus packages to "
echo "*****        always eat the first download request. If it fails you "
echo "*****        should see something like "
echo "*****"
echo "*****        openssl does not exist "
echo "*****"
echo "*****        in the lines below. Check your Internet"
echo "*****        and re-run. Think about getting a better antivirus product as well."
echo "*****"
echo "************************************************************************"
echo

#  Step 3 : Prepare Build Directory
#
echo "*** Prepping build directory"
cd "$BUILD_DIR"

# Release
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_INSTALL_PREFIX="$RELEASE_DIR" \
      "$SCRIPT_DIR"

#  Step 4 : Actually build the library
#
echo "*** Building LSCS"
ninja install

exit
