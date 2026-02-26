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



opj_test_large_files(HAVE_LARGEFILESUPPORT)

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
endif()

if (MSVC)
   string (REGEX REPLACE "/W3" "" CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}"  )
   string (REGEX REPLACE "/W3" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

   add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:/utf-8>")

else()

   set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--no-undefined")
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
   set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")

   if (CMAKE_SYSTEM_NAME MATCHES "Windows")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
      set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wa,-mbig-obj")
   endif()

endif()

 


find_package(PostgreSQL QUIET)
set_package_properties(PostgreSQL PROPERTIES
   PURPOSE "Required for PostgreSQL database support"
   DESCRIPTION "Popular open source database"
   URL "https://www.postgresql.org"
   TYPE RECOMMENDED
)


if (PostgreSQL_FOUND AND CMAKE_SYSTEM_NAME MATCHES "Windows" AND NOT MSVC)

   foreach (fname IN LISTS PostgreSQL_INCLUDE_DIRS)
      # testing for 'EXISTS', a query for if the file can be read or written

      if (EXISTS "${fname}/pthread.h")
         # Postgres bug

         message(WARNING "")
         message(WARNING "------------------------------------------------------------")
         message(WARNING "WARNING WARNING")
         message(WARNING "The '${fname}' directory contains a file called pthread.h")
         message(WARNING "")
         message(WARNING "A conflict exists between pthread.h and the standard library ")
         message(WARNING "Rename or remove pthread.h in order to build the CsSqlPsql plugin")
         message(WARNING "------------------------------------------------------------")
         message(WARNING "")

         # force to not found
         set(PostgreSQL_FOUND false)

         message(STATUS "PostgreSQL client library was found, lscs plugin will not be built")
         message(STATUS "")
      endif()

   endforeach()
 endif()
 
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

find_package(GTK2)
set_package_properties(GTK2 PROPERTIES
   PURPOSE "Required for GTK style and application integration support"
   DESCRIPTION "Multi-platform toolkit for creating graphical user interfaces"
   URL "http://www.gtk.org"
   TYPE RECOMMENDED
 )

if (WIN32)
   add_definitions(-DUNICODE)
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

if (WITH_GUI)
  set(BUILD_PLATFORMS_WINDOWS_PLUGIN TRUE)
endif()

set(PKG_PREFIX "cmake/LsCs")


