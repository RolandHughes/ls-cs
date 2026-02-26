cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

cmake_policy(VERSION 3.16..3.23)

if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.19.0")
   # allows spaces in ctest names
   cmake_policy(SET CMP0110 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

set(BUILD_MAJOR "0")
set(BUILD_MINOR "3")
set(BUILD_MICRO "1")

# unused at this time: DBus, Declarative, and ScriptTools
set(LSCS_OPTIONAL_COMPONENTS Gui Multimedia Network OpenGL Sql Svg XmlPatterns)

set(PACKAGE           "lscs")
set(PACKAGE_NAME      "LsCs")
set(PACKAGE_VERSION   "${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_STRING    "lscs ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_TARNAME   "lscs")
set(PACKAGE_BUGREPORT "originalseasonedgeek@gmail.com")
set(PACKAGE_URL       "https://github.com/RolandHughes/ls-cs")


project(LsCs VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO} DESCRIPTION "A C++ Cross Platform Application Framework" )

function(dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif()
        endif()
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()

set(BUILD_ABI ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO})

# We don't want to collide with Qt binary names
set(TOOLS_SUFFIX "_ls")

include(CheckCXXCompilerFlag)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(FeatureSummary)
include(CheckAtomics)
include(CheckLibraryExists)

include(ResourceMacros)
include(TestLargeFiles)

# required libraries
set(BUILD_COMPONENTS "Core Xml")

set(LIBTOOL_INSTALL_PREFIX  "${CMAKE_BINARY_DIR}/ls_libtool/install")

if (CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
  include(linux.cmake)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  include(mac.cmake)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
  include(windows.cmake)
endif()

# hack to use local harfbuzz instead of system.
#
include_directories( BEFORE ${CMAKE_SOURCE_DIR}/src/3rdparty/harfbuzz/src )

configure_file(
   ${CMAKE_SOURCE_DIR}/cmake/lscs_config.h.cmake
   ${CMAKE_BINARY_DIR}/include/lscs_config.h
)

# file locations for building
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_PROJECT})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


configure_file(
   ${CMAKE_SOURCE_DIR}/src/core/global/LsCs_build_info.h.in
   ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/LsCs_build_info.h
)

# Ninja generator does not yet know how to build archives in pieces, so response
# files must be used to deal with very long linker command lines.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE 1)

# check components dependencies
if (WITH_MULTIMEDIA AND NOT (WITH_GUI AND WITH_NETWORK AND WITH_OPENGL))
   message(SEND_ERROR "LsCsMultimedia component requires LsCsGui, LsCsNetwork, and LsCsOpenGL components")

elseif (WITH_OPENGL AND NOT WITH_GUI)
   message(SEND_ERROR "LsCsOpenGL component requires LsCsGui component")

elseif (WITH_SVG AND NOT WITH_GUI)
   message(SEND_ERROR "LsCsSvg component requires LsCsGui component")

elseif (WITH_XMLPATTERNS AND NOT WITH_NETWORK)
   message(SEND_ERROR "LsCsXmlPatterns component requires LsCsNetwork component")

endif()

add_subdirectory(src/tools/shared)
add_subdirectory(src/tools/lconvert)
add_subdirectory(src/tools/lrelease)
add_subdirectory(src/tools/lupdate)

add_subdirectory(src/tools/rcc)
add_subdirectory(src/tools/uic)

if (WITH_GUI)
   add_subdirectory(src/tools/linguist)
endif()

configure_file(
   ${CMAKE_SOURCE_DIR}/cmake/LsCsConfig.cmake
   ${CMAKE_BINARY_DIR}/LsCsConfig.cmake
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/cmake/LsCsConfigVersion.cmake
   ${CMAKE_BINARY_DIR}/LsCsConfigVersion.cmake
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/lscs.conf.in
   ${CMAKE_BINARY_DIR}/lscs.conf
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/tools.qrc.in
   ${CMAKE_BINARY_DIR}/tools.qrc
   @ONLY
)


include(CPack)

include (InstallRequiredSystemLibraries)

message("\n")
message("-- The following lscs libraries will be built:")
message("\n * ${BUILD_COMPONENTS}\n")

feature_summary(WHAT PACKAGES_FOUND PACKAGES_NOT_FOUND FATAL_ON_MISSING_REQUIRED_PACKAGES)

if (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
   set(TARGETBITS 32)
else()
   set(TARGETBITS 64)
endif()

message("   ***   ")
message("   ***   ")
message("   ***   ")
message("   LSCS_INST_PREFIX     ${LSCS_INST_PREFIX}")
message("   LSCS_INST_LIB        ${LSCS_INST_LIB}")
message("   LSCS_INST_INCLUDE    ${LSCS_INST_INCLUDE}")
message("   LSCS_INST_BIN        ${LSCS_INST_BIN}")
message("   LSCS_INST_SHARE      ${LSCS_INST_SHARE}")
message( " ")
message("PACKAGE_NAME                   ${PACKAGE_NAME}")
message("CMAKE_PACKAGE_NAME             ${CMAKE_PACKAGE_NAME}")
message("CMAKE_BINARY_DIR               ${CMAKE_BINARY_DIR}")
message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message( " " )
message("CMAKE_INSTALL_DATAROOTDIR      ${CMAKE_INSTALL_DATAROOTDIR}")
message("CMAKE_INSTALL_DOCDIR           ${CMAKE_INSTALL_DOCDIR}")
message("CMAKE_INSTALL_BINDIR           ${CMAKE_INSTALL_BINDIR}" )
message("CMAKE_INSTALL_LIBDIR           ${CMAKE_INSTALL_LIBDIR}" )
message("CMAKE_INSTALL_INCLUDEDIR       ${CMAKE_INSTALL_INCLUDEDIR}" )
message("CMAKE_INSTALL_FULL_LIBDIR      ${CMAKE_INSTALL_FULL_LIBDIR}" )
message("CMAKE_INSTALL_FULL_INCLUDEDIR  ${CMAKE_INSTALL_FULL_INCLUDEDIR}" )
message("CMAKE_INSTALL_FULL_BINDIR      ${CMAKE_INSTALL_FULL_BINDIR}")
message(" ")
message("LIB_ARCHITECTURE               ${LIB_ARCHITECTURE}" )
message("CPACK_PACKAGE_ARCHITECTURE     ${CPACK_PACKAGE_ARCHITECTURE}" )
message("   ***      ***      ***      ***      ***      ***      ***   ")
message("   ***      ***      ***      ***      ***      ***      ***   ")
message("   ***      ***      ***      ***      ***      ***      ***   ")

message("")
message("LsCs configured to run on:  ${CMAKE_SYSTEM_NAME} ${TARGETBITS} bit, ${CMAKE_BUILD_TYPE} Mode")
message("LsCs will be built in:      ${CMAKE_BINARY_DIR}")
message("LsCs will be installed in:  ${CMAKE_INSTALL_PREFIX}")
message("LsCs package prefix:        ${PKG_PREFIX}")
message("prefix:                     ${prefix}")
message("\n")
