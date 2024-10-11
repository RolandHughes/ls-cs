cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

cmake_policy(VERSION 3.8..3.13)

# support using rpath on Mac OS X
cmake_policy(SET CMP0042 NEW)

project(gui-hello)

set(BUILD_MAJOR "1")
set(BUILD_MINOR "3")
set(BUILD_MICRO "4")

set(BUILD_COMPONENTS "gui-hello")

include(CheckCXXCompilerFlag)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)

find_package(LsCs REQUIRED)


# When building your own stand alone executables
# you really shouldn't use RPATH. That's only for
# locally built libraries you are testing/debugging.
# If you choose to use RPATH you need to comment this
# line out and uncomment one or more of the lines
# assigning a value to CMAKE_INSTALL_RPATH.
#
#set(CMAKE_SKIP_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# file locations for installing
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   include(GNUInstallDirs)

   # indicates where libraries are located relative to the executable
   set(CMAKE_INSTALL_RPATH "@executable_path/../Resources")

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   include(GNUInstallDirs)

   # indicates where libraries are located relative to the executable
   #set(CMAKE_INSTALL_RPATH "\$ORIGIN")

   # lots of warnings and all warnings as errors
   add_compile_options(-Wall -Wextra -Wpedantic -Werror)

elseif(MSVC)
   # use defaults

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
   #MinGW should no longer be needed

endif()

set(PACKAGE           "gui-hello")
set(PACKAGE_NAME      "gui-hello")
set(PACKAGE_VERSION   "${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_STRING    "gui-hello ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_TARNAME   "gui-hello")
#set(PACKAGE_BUGREPORT "info@copperspice.com")
#set(PACKAGE_URL       "https://www.copperspice.com/")

set(CPACK_PACKAGE_NAME    ${PROJECT_NAME} )
set(CPACK_PACKAGE_VENDOR  "LogikalSolutions")

set(CPACK_PACKAGE_VERSION_MAJOR ${BUILD_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${BUILD_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_MICRO})

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cross platform Hello World GUI sample")
#set(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_SOURCE_DIR}/README.md")

set(CPACK_PACKAGE_INSTALL_DIRECTORY   ${CMAKE_INSTALL_PREFIX})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY  OFF)

# mac osx only
set(CPACK_BUNDLE_NAME    gui-hello)
#set(CPACK_BUNDLE_PLIST   "${CMAKE_SOURCE_DIR}/resources/Info.plist")

include(CPack)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

if(APPLE)
    set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,-undefined,error")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-undefined,error")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,-undefined,error")
else()
    set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--no-undefined")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")
endif()

string(TIMESTAMP BUILD_DATE "%m/%d/%Y")
add_definitions(-DBUILD_DATE="${BUILD_DATE}")

configure_file(
   ${CMAKE_SOURCE_DIR}/src/gui-hello_build_info.h.in
   src/gui-hello_build_info.h
)

add_subdirectory(src)

if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
   set(TARGETBITS 32)
else()
   set(TARGETBITS 64)
endif()

message("")
message("gui-hello configured to run on:  ${CMAKE_SYSTEM_NAME} ${TARGETBITS} bit, ${CMAKE_BUILD_TYPE} Mode")
message("gui-hello will be built in:      ${CMAKE_BINARY_DIR}")
message("gui-helo will be installed in:  ${CMAKE_INSTALL_PREFIX}")
message("\n")
