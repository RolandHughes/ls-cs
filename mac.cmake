# mac.cmake
#
# For building on Apple/Mac

include(GNUInstallDirs)
# MAC is not tested as of 20240904
# rpath used for rcc and uic when compiling a user application
#file(RELATIVE_PATH LSCS_BIN_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}"
#                                "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}")

#set(CMAKE_INSTALL_RPATH "@executable_path")


