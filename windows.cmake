# windows.cmake
#
# For building on Windows

set(CMAKE_INSTALL_BINDIR bin)
set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_INCLUDEDIR include)
set(CMAKE_INSTALL_DATAROOTDIR share)

message( "CMAKE_INSTALL_PREFIX   ${CMAKE_INSTALL_PREFIX}")

# TODO:: We don't have translations right now, but need to define LSCS_INST_SHARE for Windows
#
set(LSCS_INST_PREFIX        "${CMAKE_INSTALL_PREFIX}")
set(LSCS_INST_LIB           "${CMAKE_INSTALL_LIBDIR}")
set(LSCS_INST_INCLUDE       "${CMAKE_INSTALL_INCLUDEDIR}")
set(LSCS_INST_BIN           "${CMAKE_INSTALL_BINDIR}")
set(LSCS_INST_SHARE         "${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}")
set(LSCS_INST_TRANSLATIONS  "${LSCS_INST_SHARE}/translations")

