# ***********************************************************************
#
# Copyright (c) 2012-2024 Barbara Geller
# Copyright (c) 2012-2024 Ansel Sermersheim
#
# This file is part of LsCs.
#
# LsCs is free software. You can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# version 2.1 as published by the Free Software Foundation.
#
# LsCs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# https://www.gnu.org/licenses/
#
# ***********************************************************************

# location of LsCsCore
get_target_property(LSCS_CORE_LIB LsCs::LsCsCore LOCATION)

get_filename_component(LSCS_INSTALLED_LIB_DIR "${LSCS_CORE_LIB}" DIRECTORY)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   get_filename_component(LSCS_PLUGIN_DIR  "${LSCS_INSTALLED_LIB_DIR}/../lib" ABSOLUTE)
elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set(LSCS_PLUGIN_DIR "${LSCS_INSTALLED_LIB_DIR}/plugins")
else()
   get_filename_component(LSCS_PLUGIN_DIR  "${LSCS_CORE_LIB}" DIRECTORY)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set(LSCS_LIB_SUFFIX ".so")

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set(LSCS_LIB_SUFFIX ".so")

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(LSCS_LIB_SUFFIX ".dll")

endif()


function(lscs_copy_library LIB_NAME)
   # location of the cs library
   get_target_property(LSCS_${LIB_NAME}_LIB LsCs::${LIB_NAME} LOCATION)

   if(ARGC EQUAL 2)
      set(APP_INSTALL_DIR ${ARGV1})
   else()
      set(APP_INSTALL_DIR .)
   endif()

   install(FILES ${LSCS_${LIB_NAME}_LIB} DESTINATION ${APP_INSTALL_DIR})
   message(STATUS "   ***   ")
   message(STATUS " lscs_copy_library  ${LIB_NAME}  APP_INSTALL_DIR  ${APP_INSTALL_DIR}")
   message(STATUS "   ***   ")
   if(LIB_NAME STREQUAL "LsCsCore")

      if ("${LsCsSignal_Deploy}")
         # install system library since CS was built with the system library

         if (LSCS_INSTALL_MODE STREQUAL "Deploy")
            install(FILES ${LSCS_INSTALLED_LIB_DIR}/libLsCsSignal${LSCS_LIB_SUFFIX} DESTINATION ${APP_INSTALL_DIR})
         endif()
      endif()

      if ("${LsCsString_Deploy}")
         # install system library since CS was built with the system library

         if (LSCS_INSTALL_MODE STREQUAL "Deploy")
            install(FILES ${LSCS_INSTALLED_LIB_DIR}/libLsCsString${LSCS_LIB_SUFFIX} DESTINATION ${APP_INSTALL_DIR})
         endif()
      endif()

   endif()

endfunction()


function(lscs_copy_plugins LIB_NAME)

   if(ARGC EQUAL 2)
      set(APP_INSTALL_DIR ${ARGV1})
   else()
      set(APP_INSTALL_DIR .)
   endif()

   if(LIB_NAME STREQUAL "LsCsGui")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsGuiCocoa${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/platforms)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsGuiXcb${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/platforms)
         install(FILES ${LSCS_INSTALLED_LIB_DIR}/libLsCsXcbSupport${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR})

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsGuiWin${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/platforms)

      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsMultimedia")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_avf_camera${LSCS_VERSION_API}.so      DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_avf_mediaplayer${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_m3u${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_gst_audiodecoder${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/audio)
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_gst_camerabin${LSCS_VERSION_API}.so    DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_gst_mediaplayer${LSCS_VERSION_API}.so  DESTINATION ${APP_INSTALL_DIR}/mediaservices)

         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_m3u${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_DirectShow${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsMultimedia_m3u${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsOpenGL")

      if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsGuiXcb_Glx${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/xcbglintegrations)
      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsSqlMySql")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlMySql${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlMySql${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlMySql${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsSqlOdbc")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlOdbc${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlOdbc${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlOdbc${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsSqlPsql")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlPsql${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlPsql${LSCS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${LSCS_PLUGIN_DIR}/LsCsSqlPsql${LSCS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "LsCsPrinterDriver")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         set(file ${LSCS_PLUGIN_DIR}/LsCsPrinterDriverCups${LSCS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         set(file ${LSCS_PLUGIN_DIR}/LsCsPrinterDriverCups${LSCS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         set(file ${LSCS_PLUGIN_DIR}/LsCsPrinterDriverWin${LSCS_VERSION_API}.dll)

      endif()

      if(NOT EXISTS ${file})
         message(FATAL_ERROR " \n ** LsCs plugin: ${file} \n ** appears to be missing, please verify your installation\n")
      endif()

      install(FILES ${file} DESTINATION ${APP_INSTALL_DIR}/printerdrivers)

   endif()

   if(LIB_NAME STREQUAL "LsCsImageFormatsSvg")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         set(file ${LSCS_PLUGIN_DIR}/LsCsImageFormatsSvg${LSCS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         set(file ${LSCS_PLUGIN_DIR}/LsCsImageFormatsSvg${LSCS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         set(file ${LSCS_PLUGIN_DIR}/LsCsImageFormatsSvg${LSCS_VERSION_API}.dll)

      endif()

      if(NOT EXISTS ${file})
         message(FATAL_ERROR " \n ** LsCs plugin: ${file} \n ** appears to be missing, please verify your installation\n")
      endif()

      install(FILES ${file} DESTINATION ${APP_INSTALL_DIR}/imageformats)

   endif()

endfunction()


