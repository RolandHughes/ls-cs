# linux.cmake
#
# For building on any Linux or Unix flavored OS

# Find the PkgConfig module
# find_package(PkgConfig REQUIRED)

# used to control cmake/pc variables when building
# installation packages
#
option(BUILDING_RPM "Are we building RPM" OFF)
option(BUILDING_DEBIAN "Are we building DEBIAN" OFF)
option(BUILDING_LOCAL "Are we doing a non-system LOCAL install" OFF)


# location for install or package
include(GNUInstallDirs)

# this architecture value is only used on the control file for a debian package.
# if the value is bogus or empty on other platforms it simply doesn't matter.
#
# TODO:: See what we get when cross compiling for Arm or other targets.
#
EXECUTE_PROCESS( COMMAND dpkg --print-architecture  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CPACK_PACKAGE_ARCHITECTURE)
EXECUTE_PROCESS( COMMAND arch  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE LIB_ARCHITECTURE)


#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#  Now that we are naming binaries appropriately and putting them in
#  standard locations, all of this RPATH stuff trying to find binaries
#  underneath the lib directory tree is only needed for a BUILDING_LOCAL.
#  Normally a development install into a non-system directory so we 
#  added a test for BUILDING_LOCAL to those plugins and binaries 
#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

set(CMAKE_INSTALL_INCLUDEDIR "include/${CMAKE_PROJECT_NAME}")
set(CMAKE_INSTALL_LIBDIR "lib/${CMAKE_PROJECT_NAME}")


message( "*****************CMAKE_INSTALL_LIBDIR   ${CMAKE_INSTALL_LIBDIR} ")

message( "*****************CMAKE_INSTALL_LIBDIR   ${CMAKE_INSTALL_LIBDIR} ")

# message( "*****************LIBTOOL_INSTALL_PREFIX ${LIBTOOL_INSTALL_PREFIX} ")


    

# CMake is an odd duck. If you provide SOURCE_DIR definition for 
# external project, PREFIX will not create the other directories.
# CMake ASS-U-ME-s all external projects are CMAKE builds. Not 
# the case with libtool and so many other things.
#
# The hacky looking path for the configure command is a result of  
# CMake forcing its own directory structure on external project.
#
#include(ExternalProject)

#set(LS_LIBTOOL_BYPRODUCTS 
#   "${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.a"
#   "${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.la"
#   "${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so"
#   "${LIBTOOL_INSTALL_PREFIX}/include/ltdl.h"
#   "${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_dlloader.h"
#   "${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_error.h"
#   "${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_system.h"
#)
    
# NOTE: If you change the file here you may need to change the libldtl install version.
# Must provide BUILD_BYPRODUCTS when using ninja-build
#ExternalProject_Add(
#    ls_libtool
#    PREFIX "${CMAKE_BINARY_DIR}/ls_libtool"
#    DOWNLOAD_DIR "${CMAKE_BINARY_DIR}"
#    URL https://ftp.gnu.org/gnu/libtool/libtool-2.5.4.tar.gz
#    DOWNLOAD_NO_PROGRESS ON 
#    DOWNLOAD_EXTRACT_TIMESTAMP false
    
#    UPDATE_COMMAND ${CMAKE_COMMAND} -E copy 
#        ${CMAKE_SOURCE_DIR}/libtool-configure.ac
#        ${CMAKE_BINARY_DIR}/ls_libtool/src/ls_libtool/configure.ac
        
#    CONFIGURE_COMMAND ${CMAKE_BINARY_DIR}/ls_libtool/src/ls_libtool/configure --prefix=${LIBTOOL_INSTALL_PREFIX} "CFLAGS=-g -O0" "CXXFLAGS=-g -O0"
#    BUILD_COMMAND make 
#    BUILD_BYPRODUCTS ${LS_LIBTOOL_BYPRODUCTS}
#)



#
# When building for a package we install to /usr under a
# fakeroot or buildroot during build. We don't want
# the build install path but the system target path.
#
if (BUILDING_DEBIAN)
    message(STATUS "** We are building Debian package ***")
    add_compile_definitions(LSCS_PACKAGE_BUILD)
    set(LSCS_INST_PREFIX        "/usr")
    set(LSCS_INST_LIB           "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
    set(LSCS_INST_INCLUDE       "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
    set(CMAKE_INSTALL_FULL_LIBDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}" )
    set(LSCS_INST_BIN           "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_BINDIR}")
    set(LSCS_INST_SHARE         "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}")
    set(LSCS_INST_TRANSLATIONS  "${LSCS_INST_SHARE}/translations")
elseif (BUILDING_RPM)
    message(STATUS "** We are building RPM package ***")
    add_compile_definitions(LSCS_PACKAGE_BUILD)
    set(LSCS_INST_PREFIX        "/usr")
    set(LSCS_INST_LIB           "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
    set(LSCS_INST_INCLUDE       "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
    set(LSCS_INST_BIN           "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_BINDIR}")
    set(LSCS_INST_SHARE         "${LSCS_INST_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}")
    set(LSCS_INST_TRANSLATIONS  "${LSCS_INST_SHARE}/translations")
else()
    set(LSCS_INST_PREFIX        "${CMAKE_INSTALL_PREFIX}")
    set(LSCS_INST_LIB           "${CMAKE_INSTALL_LIBDIR}")
    set(LSCS_INST_INCLUDE       "${CMAKE_INSTALL_INCLUDEDIR}")
    set(LSCS_INST_BIN           "${CMAKE_INSTALL_BINDIR}")
    set(LSCS_INST_SHARE         "${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}")
    set(LSCS_INST_TRANSLATIONS  "${LSCS_INST_SHARE}/translations")
endif()

set(prefix "${LSCS_INST_PREFIX}")



# unused at this time: DBus, Declarative, and ScriptTools
set(LSCS_OPTIONAL_COMPONENTS Gui Multimedia Network OpenGL Sql Svg XmlPatterns)

set(RPM_VERSION       "${BUILD_MAJOR}.${BUILD_MINOR}")
set(RPM_RELEASE       "${BUILD_MICRO}")


# values used in LsCs_build_info.h.in
set(HEX_VERSION "0x0${BUILD_MAJOR}0${BUILD_MINOR}0${BUILD_MICRO}")
set(VERSION     "${PACKAGE_VERSION}")


if (MSVC)
   enable_language(ASM_MASM)
   set(target "MSVC")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang|AppleClang)")
   execute_process(
      COMMAND ${CMAKE_CXX_COMPILER} -dumpmachine
      OUTPUT_VARIABLE DUMPMACHINE_OUTPUT
      RESULT_VARIABLE DUMPMACHINE_EXITCODE
      OUTPUT_STRIP_TRAILING_WHITESPACE
   )

   if (NOT DUMPMACHINE_EXITCODE EQUAL 0)
      message(SEND_ERROR "Failed to obtain machine from ${CMAKE_CXX_COMPILER}")
   endif()

   set(target "${DUMPMACHINE_OUTPUT}")

else()
   message(WARNING
      "Your compiler (${CMAKE_CXX_COMPILER}) may not be supported. "
      "The plugin key which will be used is: ${CMAKE_SYSTEM}"
   )

   set(target "${CMAKE_SYSTEM}")
endif()

set(CPACK_PACKAGE_NAME    ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR  "Logikal Solutions")
set(CPACK_PACKAGE_CONTACT "logikalsolutions.com")

set(CPACK_PACKAGE_VERSION_MAJOR ${BUILD_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${BUILD_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_MICRO})

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cross platform C++ GUI libraries")
set(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_SOURCE_DIR}/README.md")

set(CPACK_PACKAGE_INSTALL_DIRECTORY   ${CMAKE_INSTALL_PREFIX})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY  OFF)

set(CPACK_SOURCE_PACKAGE_FILE_NAME    "${PROJECT_NAME}-${PACKAGE_VERSION}")
set(CPACK_SOURCE_GENERATOR            ZIP TBZ2)

file (READ "description.txt" CPACK_PACKAGE_DESCRIPTION_TEXT)

file(STRINGS cmake/dist_ignore.txt    CPACK_SOURCE_IGNORE_FILES)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

if (CMAKE_SYSTEM_NAME MATCHES "(OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--no-undefined")
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ")
   set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")

else()
   set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--no-undefined")
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
   set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")
endif()

string(TIMESTAMP BUILD_DATE "%Y-%m-%d")
add_definitions(-DLSCS_SHARED)

check_include_file(dlfcn.h       HAVE_DLFCN_H)
check_include_file(dirent.h      HAVE_DIRENT_H)
check_include_file(features.h    HAVE_FEATURES_H)
check_include_file(fcntl.h       HAVE_FCNTL_H)
check_include_file(grp.h         HAVE_GRP_H)
check_include_file(inttypes.h    HAVE_INTTYPES_H)
check_include_file(libpq-fe.h    HAVE_LIBPQ_FE_H)
check_include_file(memory.h      HAVE_MEMORY_H)
check_include_file(pg_config.h   HAVE_PG_CONFIG_H)
check_include_file(pwd.h         HAVE_PWD_H)
check_include_file(signal.h      HAVE_SIGNAL_H)
check_include_file(stdint.h      HAVE_STDINT_H)
check_include_file(stdlib.h      HAVE_STDLIB_H)
check_include_file(strings.h     HAVE_STRINGS_H)
check_include_file(string.h      HAVE_STRING_H)
check_include_file(unistd.h      HAVE_UNISTD_H)

check_include_file(cups/cups.h   HAVE_CUPS_CUPS_H)
check_include_file(net/if.h      HAVE_NET_IF_H)
check_include_file(netinet/in.h  HAVE_NETINET_IN_H)
check_include_file(sys/eventfd.h HAVE_SYS_EVENTFD_H)
check_include_file(sys/types.h   HAVE_SYS_TYPES_H)
check_include_file(sys/ioctl.h   HAVE_SYS_IOCTL_H)
check_include_file(sys/ipc.h     HAVE_SYS_IPC_H)
check_include_file(sys/time.h    HAVE_SYS_TIME_H)
check_include_file(sys/shm.h     HAVE_SYS_SHM_H)
check_include_file(sys/socket.h  HAVE_SYS_SOCKET_H)
check_include_file(sys/stat.h    HAVE_SYS_STAT_H)
check_include_file(sys/wait.h    HAVE_SYS_WAIT_H)
check_include_file(sys/param.h   HAVE_SYS_PARAM_H)

check_include_files("dlfcn.h;stdint.h;stddef.h;inttypes.h;stdlib.h;strings.h;string.h;float.h" STDC_HEADERS)
check_type_size(size_t SIZEOF_SIZE_T)
opj_test_large_files(HAVE_LARGEFILESUPPORT)

# Raspberry Pi does not have built in atomic support
check_working_cxx_atomics(HAVE_CXX_ATOMICS_WITHOUT_LIB)

if (NOT HAVE_CXX_ATOMICS_WITHOUT_LIB)
   check_library_exists(atomic __atomic_fetch_add_4 "" HAVE_LIBATOMIC)

   if (HAVE_LIBATOMIC)
      # handled in LsCsCore cmake file
   else()
      message(SEND_ERROR "Unable to configure, missing libatomic")
   endif()
endif()

option(WITH_PSQL_PLUGIN "Build PostgreSQL database plugin (if possible)" ON)

option(WITH_MYSQL_PLUGIN "Build MySQL database plugin (if possible)" ON)

option(WITH_ODBC_PLUGIN "Build ODBC database plugin (if possible)" ON)

find_package(TIFF QUIET REQUIRED)

find_package(PNG QUIET REQUIRED)

foreach(component ${LSCS_OPTIONAL_COMPONENTS})
   string(TOUPPER ${component} uppercomp)
   option(WITH_${uppercomp} "Build ${component} component" ON)
endforeach()

# start output messages
message("")
message("Configuring CMake for lscs\n\n")
message("-- Searching for required packages\n")

# LibGuarded should go away once we base this on SDL3. 
# SDL3 gives us SDL_Mutex, SDL_RWLock and Thread Local Storage
#
find_package(LsCsLibGuarded QUIET)

# LsCsString will not be a separate library when we are done
#
find_package(LsCsString QUIET)

# SDL3 has a callback api as well as its own event queues. 
# define SDL_MAIN_USE_CALLBACKS 1
# https://www.youtube.com/watch?v=7Qm7yXG_BHs
#
find_package(LsCsSignal QUIET)

find_package(OpenSSL QUIET)
set_package_properties(OpenSSL PROPERTIES
   PURPOSE "Required for network communications"
   DESCRIPTION "a software library used in Linux and other operating systems to provide secure communications over computer networks"
   URL "https://www.openssl-library.org/source/"
   TYPE REQUIRED
)


find_package(ZLIB QUIET)
set_package_properties(ZLIB PROPERTIES
   PURPOSE "Required for compression support"
   DESCRIPTION "A Massively Spiffy Yet Delicately Unobtrusive Compression Library"
   URL "https://www.zlib.net"
   TYPE REQUIRED
)


find_package(JPEG QUIET)
set_package_properties(JPEG PROPERTIES
   PURPOSE "Required for JPEG image compression support"
   DESCRIPTION "a free library with functions for handling the JPEG image data format"
   URL "https://ijg.org"
   TYPE REQUIRED
)


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


find_package(PulseAudio)
set_package_properties(PulseAudio PROPERTIES
   PURPOSE "Required for pulseaudio support"
   DESCRIPTION "Sound processing daemon for Unix"
   URL "https://www.pulseaudio.org"
   TYPE RECOMMENDED
)


find_package(PostgreSQL QUIET)
set_package_properties(PostgreSQL PROPERTIES
   PURPOSE "Required for PostgreSQL database support"
   DESCRIPTION "Popular open source database"
   URL "https://www.postgresql.org"
   TYPE RECOMMENDED
)

if (PosgreSQL_FOUND)
   set(HAVE_PG_CONFIG_H TRUE)
endif()



find_package( Freetype REQUIRED)
set_package_properties(Freetype PROPERTIES
   PURPOSE "Required for font rendering"
   DESCRIPTION "a freely available software library to render fonts"
   URL "https://freetype.org"
   TYPE REQUIRED
)



find_package(MySQL QUIET)
set_package_properties(MySQL PROPERTIES
   PURPOSE "Required for MySQL database support"
   DESCRIPTION "Popular open source database"
   URL "https://www.mysql.com"
   TYPE RECOMMENDED
)

find_package(ODBC QUIET)
set_package_properties(ODBC PROPERTIES
   PURPOSE "Required for ODBC SQL database support"
   DESCRIPTION "ODBC SQL driver implementation"
   TYPE RECOMMENDED
)

find_package(SQLite3 QUIET)
set_package_properties(SQLite3 PROPERTIES
   PURPOSE "Required for SQLite3 database support"
   DESCRIPTION "Popular open source database"
   URL "https://www.sqlite.org"
   TYPE RECOMMENDED
)


find_package(GTK2)
set_package_properties(GTK2 PROPERTIES
   PURPOSE "Required for GTK style and application integration support"
   DESCRIPTION "Multi-platform toolkit for creating graphical user interfaces"
   URL "http://www.gtk.org"
   TYPE RECOMMENDED
)

find_package(Threads)
set_package_properties(Threads PROPERTIES
   PURPOSE "Required for threading support"
   DESCRIPTION "Platform dependant threading library"
   URL ""
   TYPE REQUIRED
)

find_package(GLib2)
set_package_properties(GLib2 PROPERTIES
   PURPOSE "Required for glib mainloop support"
   DESCRIPTION "GNOME core library"
   URL "https://developer.gnome.org/glib"
   TYPE REQUIRED
) 

find_package(GObject2)
set_package_properties(GObject2 PROPERTIES
   PURPOSE "Required for glib mainloop support"
   DESCRIPTION "The object system used for Pango and GTK+"
   URL "https://developer.gnome.org/gobject"
   TYPE REQUIRED
)

find_package(Iconv)
set_package_properties(Iconv PROPERTIES
   PURPOSE "Iconv support"
   DESCRIPTION "For use on systems which do not have Iconv or lack Unicode support"
   URL "http://www.gnu.org/software/libiconv/"
   TYPE REQUIRED
)

if (WITH_GUI)
   find_package(X11 COMPONENTS ICE SM Xcursor Xext Xfixes Xi Xinerama Xrandr Xrender)
   set_package_properties(X11 PROPERTIES
      PURPOSE "Required for X11/X.Org integration support"
      DESCRIPTION "Open source implementation of the X Window System"
      URL "https://www.x.org"
      TYPE REQUIRED
   )

   find_package(XCB COMPONENTS xcb xcb-image xcb-icccm xcb-sync xcb-xfixes xcb-shm xcb-randr
                xcb-shape xcb-keysyms xcb-xinerama xcb-xkb xcb-render xcb-render-util xcb-glx)
   set_package_properties(XCB PROPERTIES
      PURPOSE "Required for XCB/X.Org integration support"
      DESCRIPTION "Open source implementation of the XCB Interface for the X11 Window System"
      URL "https://xcb.freedesktop.org"
      TYPE REQUIRED
   )

   find_package(X11_XCB)
   set_package_properties(X11_XCB PROPERTIES
      PURPOSE "Required for X11 XCB support"
      DESCRIPTION "Integration between X11 and XCB"
      URL "https://xcb.freedesktop.org"
      TYPE REQUIRED
   )

   find_package(XKBCommon)
   set_package_properties(XKBCommon PROPERTIES
      PURPOSE "Required for XKB integration support"
      DESCRIPTION "Keyboard library"
      URL "https://xkbcommon.org"
      TYPE REQUIRED
   )

   find_package(XKBCommon_X11)
   set_package_properties(XKBCommon_X11 PROPERTIES
      PURPOSE "Required for XKB X11 integration support"
      DESCRIPTION "Keyboard library"
      URL "https://xkbcommon.org"
      TYPE REQUIRED
   )

   find_package(Fontconfig)
   set_package_properties(Fontconfig PROPERTIES
      PURPOSE "Required for fonts configuration support"
      DESCRIPTION "Library for configuring and customizing font access"
      URL "http://www.freedesktop.org/wiki/Software/fontconfig/"
      TYPE REQUIRED
   )
endif()

if (WITH_MULTIMEDIA)
   find_package(GStreamer)
   set_package_properties(GStreamer PROPERTIES
      PURPOSE "Required for multimedia audio and video support"
      DESCRIPTION "Open source media playback library"
      URL "http://gstreamer.freedesktop.org"
      TYPE REQUIRED
   )
endif()

if (WITH_OPENGL)
   find_package(OpenGL)
   set_package_properties(OpenGL PROPERTIES
      PURPOSE "Required for OpenGL support"
      DESCRIPTION "The Mesa 3D Graphics Library"
      URL "http://www.mesa3d.org/"
      TYPE REQUIRED
   )
endif()


if (NOT Cups_FOUND)
   add_definitions(-DLSCS_NO_CUPS)
endif()

if (NOT GLIB2_FOUND)
   add_definitions(-DLSCS_NO_GLIB)
endif()

if (HAVE_LARGEFILESUPPORT)
   if (_FILE_OFFSET_BITS)
      add_definitions(-D_FILE_OFFSET_BITS=64)
   endif()

   if (_LARGE_FILES)
      add_definitions(-D_LARGE_FILES)
   endif()

   if (_LARGEFILE_SOURCE)
      add_definitions(-D_LARGEFILE_SOURCE)
   endif()
endif()


add_subdirectory(src/core)
add_subdirectory(src/xml)

foreach(component ${LSCS_OPTIONAL_COMPONENTS})
   string(TOUPPER ${component} uppercomp)

   if (WITH_${uppercomp})
      string(TOLOWER ${component} lowercomp)
      add_subdirectory(src/${lowercomp})
      set(BUILD_COMPONENTS "${BUILD_COMPONENTS} ${component}")
   endif()
endforeach()


# platform plugins
if (WITH_GUI)
   set(BUILD_PLATFORMS_XCB_PLUGIN TRUE)
   include_directories( BEFORE ${CMAKE_SOURCE_DIR}/src/3rdparty/harfbuzz/src )
   add_subdirectory(src/plugins/imageformats)
   add_subdirectory(src/plugins/platforms)
   add_subdirectory(src/plugins/printerdrivers)
endif()


set(PKG_PREFIX "${CMAKE_INSTALL_LIBDIR}/cmake")


if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
    #  Update files needed for Debian
    #  Note: You need to update CPACK_PACKAGE_INSTALLED_SIZE to reflect current installed size
    #
   set(CPACK_PACKAGE_INSTALLED_SIZE "6291456")



   message( STATUS "Architecture: ${CPACK_PACKAGE_ARCHITECTURE}")


    configure_file(
       ${CMAKE_SOURCE_DIR}/deb_build.etc/control.in
       deb_build.etc/control
       @ONLY
    )

    configure_file(
       ${CMAKE_SOURCE_DIR}/LsCs.spec.in
       LsCs.spec
       @ONLY
     )

     configure_file(
       ${CMAKE_SOURCE_DIR}/LsCs-library.conf.in
       LsCs-library.conf
       @ONLY
     )

    #  postrm has some heavy syntax - just copy
    configure_file(
       ${CMAKE_SOURCE_DIR}/deb_build.etc/postrm.in
       deb_build.etc/postrm
       COPYONLY
    )

    #  postinst needs to know package name for logging
    configure_file(
       ${CMAKE_SOURCE_DIR}/deb_build.etc/postinst.in
       deb_build.etc/postinst
    )

    #  hopefully we never need to replace values in rules
    configure_file(
       ${CMAKE_SOURCE_DIR}/deb_build.etc/rules.in
       deb_build.etc/rules
       COPYONLY
    )

    configure_file(
        ${CMAKE_SOURCE_DIR}/README.md
        README.md
        COPYONLY
    )

endif()


# libtool headers and libraries
#

#if (BUILDING_DEBIAN)
#    install(
#      FILES
#      ${LIBTOOL_INSTALL_PREFIX}/include/ltdl.h
#      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#      COMPONENT Development
#    )
#else()
#    install(
#      FILES
#      ${LIBTOOL_INSTALL_PREFIX}/include/ltdl.h
#      DESTINATION ${LSCS_INST_INCLUDE}
#      COMPONENT Development
#    )
#endif()

#if (BUILDING_DEBIAN)
#    install(
#      FILES
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_dlloader.h
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_error.h
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_system.h
#      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#      COMPONENT Development
#    )
#else()
#    install(
#      FILES
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_dlloader.h
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_error.h
#      ${LIBTOOL_INSTALL_PREFIX}/include/libltdl/lt_system.h
#      DESTINATION ${LSCS_INST_INCLUDE}
#      COMPONENT Development
#    )
#endif()

# NOTE:: Need dynamic way of determining major version of library or a for loop finding each 
#        This hard coding bad.
#if (BUILDING_DEBIAN)
#    install(
#       FILES
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.a
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.la
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so.7
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so.7.3.3
#       DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
#       COMPONENT Development
#       COMPONENT Runtime
#    )
#else()
#    install(
#       FILES
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.a
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.la
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so.7
#       ${LIBTOOL_INSTALL_PREFIX}/lib/libltdl.so.7.3.3
#       DESTINATION ${LSCS_INST_LIB}
#       COMPONENT Development
#       COMPONENT Runtime
#    )
#endif()

if (BUILDING_DEBIAN)
    install(
       FILES
          ${CMAKE_BINARY_DIR}/LsCsConfig.cmake
          ${CMAKE_BINARY_DIR}/LsCsConfigVersion.cmake

          ${CMAKE_SOURCE_DIR}/cmake/LsCsMacros.cmake
       DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/cmake
       COMPONENT Development
    )

    install(
      FILES
         ${CMAKE_BINARY_DIR}/LsCs-library.conf
         DESTINATION ${CMAKE_INSTALL_PREFIX}/etc/ld.so.conf.d
         COMPONENT Runtime
         COMPONENT Development
    )
    
else()
    install(
       FILES
          ${CMAKE_BINARY_DIR}/LsCsConfig.cmake
          ${CMAKE_BINARY_DIR}/LsCsConfigVersion.cmake

          ${CMAKE_SOURCE_DIR}/cmake/LsCsMacros.cmake
          DESTINATION ${PKG_PREFIX}
          COMPONENT Development
    )
endif()

install(
    FILES
       ${CMAKE_SOURCE_DIR}/license/LGPL_EXCEPTION.txt
       ${CMAKE_SOURCE_DIR}/license/LICENSE.FDL
       ${CMAKE_SOURCE_DIR}/license/LICENSE.LGPL
       DESTINATION ${CMAKE_INSTALL_DOCDIR}/license
       COMPONENT Runtime
       COMPONENT Development
)

install(
  FILES
     ${CMAKE_BINARY_DIR}/lscs.conf
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}
  COMPONENT Runtime
  COMPONENT Development
)

install(
  FILES
     ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/LsCs_build_info.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  COMPONENT Development
)
  
install(
   # generate cmake files containing rules about linking with LsCs libs

   EXPORT LsCsLibraryTargets
   NAMESPACE LsCs::
   FILE LsCsLibraryTargets.cmake
   DESTINATION ${PKG_PREFIX}
   COMPONENT Development
)

# generate cmake files containing rules about running LsCs binary tools
install(
   EXPORT LsCsBinaryTargets
   NAMESPACE LsCs::
   FILE LsCsBinaryTargets.cmake
   DESTINATION ${PKG_PREFIX}
   COMPONENT Development
)
