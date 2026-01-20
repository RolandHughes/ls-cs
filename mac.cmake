# mac.cmake
#
# For building on Apple/Mac

include(GNUInstallDirs)
# MAC is not tested as of 20240904
# rpath used for rcc and uic when compiling a user application
#file(RELATIVE_PATH LSCS_BIN_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}"
#                                "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}")

#set(CMAKE_INSTALL_RPATH "@executable_path")

set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,-undefined,error")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-undefined,error")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,-undefined,error")


find_package(Cups)
set_package_properties(Cups PROPERTIES
   PURPOSE "Required for printing support"
   DESCRIPTION "CUPS is the standards-based open source printing system"
   URL "https://www.cups.org"
   TYPE RECOMMENDED
)

find_package(ALSA)
set_package_properties(ALSA PROPERTIES
   PURPOSE "Required for ALSA audio support"
   DESCRIPTION "Advanced Linux Sound Architecture"
   URL "https://www.alsa-project.org"
   TYPE RECOMMENDED
)



if (WITH_GUI)
  set(BUILD_PLATFORMS_COCOA_PLUGIN TRUE)
endif()

set(PKG_PREFIX "lscs.framework/Resources")



