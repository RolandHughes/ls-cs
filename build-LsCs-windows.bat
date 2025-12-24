@echo off
REM  build-LsCs-windows.bat
REM
set srcDir=%CD%
ECHO Must be run from root of project directory
ECHO ********  Cannot be run from regular Command window
ECHO must be run in a Visual Studio Developer Command prompt to get
ECHO all of the needed environment variables.
ECHO
ECHO
ECHO Build will create new ..\ls-cs-build directory to execute build in
ECHO and ..\ls-cs-release directory to install library and header files
ECHO
ECHO ****
ECHO  use -skip command line parameter to skip styling source code
ECHO ****
ECHO
ECHO ******
ECHO ******    NOTE: You need to change value of VCPKG_TARGET_TRIPLET to
ECHO ******          build anything other than x64-windows
ECHO ******

if exist "..\ls-cs-build" rmdir /S /Q "..\ls-cs-build"
if exist "..\ls-cs-release" rmdir /S /Q "..\ls-cs-release"

if exist "..\ls-cs-build" ECHO "You must rmdir /s /q ..\ls-cs-build prior to running ; cd %srcDir% ; exit

if /I "%1" == "-skip" goto CREATEDIRS
ECHO "Enforcing style"
ECHO " "
call astyle-project.bat
ECHO " "

:CREATEDIRS
ECHO "Creating empty build directories"
ECHO " "

mkdir ..\ls-cs-build
mkdir ..\ls-cs-release
ECHO " "
ECHO "Building libraries and packages"
ECHO " "
cd ..\ls-cs-build
cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%"\scripts\buildsystems\vcpkg.cmake^
      -DVCPKG_TARGET_TRIPLET=x64-windows^
      -DCMAKE_BUILD_TYPE=Release^
      -DCMAKE_INSTALL_PREFIX=..\ls-cs-release "%srcDir%"
ECHO " "
ninja

ninja install

cd %srcDir%
