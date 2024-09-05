# ***********************************************************************
#
# Copyright (c) 2012-2024 Barbara Geller
# Copyright (c) 2012-2024 Ansel Sermersheim
#
# This file is part of ls-cs.
#
# ls-cs is free software. You can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# version 2.1 as published by the Free Software Foundation.
#
# ls-cs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# https://www.gnu.org/licenses/
#
# ***********************************************************************

# location of Ls-CsCore
get_target_property(CS_CORE_LIB ls-cs::Ls-CsCore LOCATION)

get_filename_component(CS_INSTALLED_LIB_DIR "${CS_CORE_LIB}" DIRECTORY)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   get_filename_component(CS_PLUGIN_DIR  "${CS_INSTALLED_LIB_DIR}/../lib" ABSOLUTE)
else()
   get_filename_component(CS_PLUGIN_DIR  "${CS_CORE_LIB}" DIRECTORY)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set(CS_LIB_SUFFIX ".so")

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set(CS_LIB_SUFFIX ".so")

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(CS_LIB_SUFFIX ".dll")

endif()


function(cs_copy_library LIB_NAME)
   # location of the cs library
   get_target_property(CS_${LIB_NAME}_LIB ls-cs::${LIB_NAME} LOCATION)

   if(ARGC EQUAL 2)
      set(APP_INSTALL_DIR ${ARGV1})
   else()
      set(APP_INSTALL_DIR .)
   endif()

   install(FILES ${CS_${LIB_NAME}_LIB} DESTINATION ${APP_INSTALL_DIR})

   if(LIB_NAME STREQUAL "Ls-CsCore")

      if ("${LsCsSignal_Deploy}")
         # install system library since CS was built with the system library

         if (CS_INSTALL_MODE STREQUAL "Deploy")
            install(FILES ${CS_INSTALLED_LIB_DIR}/libLsCsSignal${CS_LIB_SUFFIX} DESTINATION ${APP_INSTALL_DIR})
         endif()
      endif()

      if ("${LsCsString_Deploy}")
         # install system library since CS was built with the system library

         if (CS_INSTALL_MODE STREQUAL "Deploy")
            install(FILES ${CS_INSTALLED_LIB_DIR}/libLsCsString${CS_LIB_SUFFIX} DESTINATION ${APP_INSTALL_DIR})
         endif()
      endif()

   endif()

endfunction()


function(cs_copy_plugins LIB_NAME)

   if(ARGC EQUAL 2)
      set(APP_INSTALL_DIR ${ARGV1})
   else()
      set(APP_INSTALL_DIR .)
   endif()

   if(LIB_NAME STREQUAL "Ls-CsGui")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsGuiCocoa${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/platforms)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsGuiXcb${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/platforms)
         install(FILES ${CS_INSTALLED_LIB_DIR}/libLs-CsXcbSupport${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR})

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsGuiWin${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/platforms)

      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsMultimedia")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_avf_camera${LS_CS_VERSION_API}.so      DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_avf_mediaplayer${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_m3u${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_gst_audiodecoder${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/audio)
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_gst_camerabin${LS_CS_VERSION_API}.so    DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_gst_mediaplayer${LS_CS_VERSION_API}.so  DESTINATION ${APP_INSTALL_DIR}/mediaservices)

         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_m3u${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_DirectShow${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/mediaservices)
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsMultimedia_m3u${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/playlistformats)

      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsOpenGL")

      if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsGuiXcb_Glx${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/xcbglintegrations)
      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsSqlMySql")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlMySql${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlMySql${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlMySql${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsSqlOdbc")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlOdbc${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlOdbc${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlOdbc${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsSqlPsql")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlPsql${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlPsql${LS_CS_VERSION_API}.so DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         install(FILES ${CS_PLUGIN_DIR}/Ls-CsSqlPsql${LS_CS_VERSION_API}.dll DESTINATION ${APP_INSTALL_DIR}/sqldrivers)

      endif()
   endif()

   if(LIB_NAME STREQUAL "Ls-CsPrinterDriver")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         set(file ${CS_PLUGIN_DIR}/Ls-CsPrinterDriverCups${LS_CS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         set(file ${CS_PLUGIN_DIR}/Ls-CsPrinterDriverCups${LS_CS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         set(file ${CS_PLUGIN_DIR}/Ls-CsPrinterDriverWin${LS_CS_VERSION_API}.dll)

      endif()

      if(NOT EXISTS ${file})
         message(FATAL_ERROR " \n ** ls-cs plugin: ${file} \n ** appears to be missing, please verify your installation\n")
      endif()

      install(FILES ${file} DESTINATION ${APP_INSTALL_DIR}/printerdrivers)

   endif()

   if(LIB_NAME STREQUAL "Ls-CsImageFormatsSvg")

      if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
         set(file ${CS_PLUGIN_DIR}/Ls-CsImageFormatsSvg${LS_CS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
         set(file ${CS_PLUGIN_DIR}/Ls-CsImageFormatsSvg${LS_CS_VERSION_API}.so)

      elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
         set(file ${CS_PLUGIN_DIR}/Ls-CsImageFormatsSvg${LS_CS_VERSION_API}.dll)

      endif()

      if(NOT EXISTS ${file})
         message(FATAL_ERROR " \n ** ls-cs plugin: ${file} \n ** appears to be missing, please verify your installation\n")
      endif()

      install(FILES ${file} DESTINATION ${APP_INSTALL_DIR}/imageformats)

   endif()

endfunction()


