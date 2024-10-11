if(BUILD_PLATFORMS_XCB_PLUGIN)
   add_library(LsCsXcbSupport SHARED "")
   add_library(LsCs::LsCsXcbSupport ALIAS LsCsXcbSupport)

   set_target_properties(LsCsXcbSupport PROPERTIES OUTPUT_NAME LsCsXcbSupport${BUILD_ABI})

   target_compile_definitions(LsCsXcbSupport
      PRIVATE
      -DQT_NO_ACCESSIBILITY_ATSPI_BRIDGE
      -DQT_NO_DBUS
      -DQT_FONTCONFIGDATABASE
      -DQT_USE_FREETYPE
      -DXCB_USE_RENDER
      -DXCB_USE_SM
      -DXCB_USE_XLIB
      -DXCB_USE_XINPUT2
   )

   list(APPEND XCB_SUPPORT_PRIVATE_INCLUDES
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_backingstore.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_clipboard.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_connection.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_cursor.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_drag.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_export.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_gl_integration.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_gl_integrationfactory.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_gl_integrationplugin.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_image.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_integration.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_keyboard.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_mime.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_nativeinterface.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_nativeinterfacehandler.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_object.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_screen.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_sessionmanager.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_systemtraytracker.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_window.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_wm_support.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_xsettings.h

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qgenericunix_eventdispatcher_p.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qunix_eventdispatcher_p.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qxcb_eventdispatcher_glib_p.h

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/fonts/qfontconfig_database_p.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/fonts/qfontengine_multifontconfig_p.h
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/fonts/qgenericunix_fontdatabase_p.h

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/services/qgenericunix_services_p.h

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/themes/qgenericunix_theme_p.h
   )

   target_sources(LsCsXcbSupport
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_backingstore.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_clipboard.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_connection.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_connection_xi2.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_cursor.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_drag.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_gl_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_gl_integrationfactory.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_image.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_keyboard.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_mime.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_nativeinterface.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_nativeinterfacehandler.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_screen.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_sessionmanager.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_systemtraytracker.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_window.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_wm_support.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/xcb_support/qxcb_xsettings.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qgenericunix_eventdispatcher.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qunix_eventdispatcher.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/fonts/qfontconfig_database.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/fonts/qfontengine_multifontconfig.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/services/qgenericunix_services.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/themes/qgenericunix_theme.cpp
   )

   macro_generate_misc_private("${XCB_SUPPORT_PRIVATE_INCLUDES}" QtGui/private/platforms)

   target_sources(LsCsXcbSupport
      PRIVATE
      ${XCB_SUPPORT_PRIVATE_INCLUDES}
   )

   target_link_libraries(LsCsXcbSupport
      PRIVATE
      LsCsCore
      LsCsGui
      ${FONTCONFIG_LIBRARIES}
      ${XCB_LIB}
      ${XCB_IMAGE_LIB}
      ${XCB_ICCCM_LIB}
      ${XCB_SYNC_LIB}
      ${XCB_XFIXES_LIB}
      ${XCB_SHM_LIB}
      ${XCB_RANDR_LIB}
      ${XCB_SHAPE_LIB}
      ${XCB_KEYSYMS_LIB}
      ${XCB_XINERAMA_LIB}
      ${XCB_XKB_LIB}
      ${XCB_RENDER_LIB}
      ${XCB_RENDER_UTIL_LIB}
      ${X11_SM_LIB}
      ${X11_ICE_LIB}
      ${X11_X11_LIB}
      ${X11_Xi_LIB}
      ${X11_XCB_LIB}
      ${XKBCOMMON_LIB}
      ${XKBCOMMON_X11_LIB}
   )

   target_include_directories(LsCsXcbSupport
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/3rdparty/freetype/include
      ${CMAKE_SOURCE_DIR}/src/3rdparty/freetype/include/freetype
      ${CMAKE_SOURCE_DIR}/src/3rdparty/harbuzz/src
   )

   if(GTK2_FOUND)
      target_link_libraries(LsCsXcbSupport
         PRIVATE
         ${GLIB2_LIBRARIES}
         ${GOBJECT2_LIBRARIES}
      )

      target_sources(LsCsGuiXcb
         PRIVATE
         ${CMAKE_CURRENT_SOURCE_DIR}/xcb/events/qxcb_eventdispatcher_glib.cpp
      )

   else()
      target_compile_definitions(LsCsXcbSupport
         PRIVATE
         -DQT_NO_GLIB
      )
   endif()

   install(
      TARGETS LsCsXcbSupport
      EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
      RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
      LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
      ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
   )
endif()
