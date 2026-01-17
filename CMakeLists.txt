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
set(BUILD_MINOR "2")
set(BUILD_MICRO "1")

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


if (CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
  include(linux.cmake)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  include(mac.cmake)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
  include(windows.cmake)
endif()


include(CPack)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    include (InstallRequiredSystemLibraries)
endif()

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
