list(APPEND PLATFORMS_WIN_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/array.h

   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_additional.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_backingstore.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_clipboard.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_context.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_cursor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_dialoghelpers.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_drag.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontdatabase.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontdatabase_ft.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontengine.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gdi_integration.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gdi_nativeinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gl_context.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_global.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_inputcontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_integration.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_internal_mimedata.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_keymapper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_mime.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_mousehandler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_nativeimage.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_nativeinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_ole.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_opengl_context.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_opengl_tester.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_screen.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_services.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_session_manager.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_theme.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_threadpoolrunner.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_window.h
)

list(APPEND PLATFORMS_WIN_OTHER_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/comutils.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/qwin_accessibility.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/qwin_msaa_accessible.h
   ${CMAKE_CURRENT_SOURCE_DIR}/windows/events/qwin_gui_eventdispatcher_p.h
)

if(BUILD_PLATFORMS_WINDOWS_PLUGIN)

   add_library(LsCsGuiWin MODULE "")
   add_library(LsCs::LsCsGuiWin ALIAS LsCsGuiWin)

   set_target_properties(LsCsGuiWin PROPERTIES OUTPUT_NAME LsCsGuiWin${BUILD_ABI} PREFIX "")

   target_sources(LsCsGuiWin
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/main.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_backingstore.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gdi_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gdi_nativeinterface.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_window.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_context.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_screen.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_keymapper.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontengine.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontdatabase.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_mousehandler.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_ole.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_mime.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_internal_mimedata.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_cursor.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_inputcontext.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_theme.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_dialoghelpers.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_services.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_nativeimage.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_nativeinterface.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_gl_context.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_opengl_tester.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_clipboard.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_drag.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_fontdatabase_ft.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/qwin_session_manager.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/comutils.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/qwin_accessibility.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/accessible/qwin_msaa_accessible.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/windows/events/qwin_gui_eventdispatcher.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/windows/cursors.qrc
      ${CMAKE_CURRENT_BINARY_DIR}/qrc_cursors.cpp
   )

   target_include_directories(LsCsGuiWin
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/3rdparty/freetype/include
      ${CMAKE_SOURCE_DIR}/src/3rdparty/freetype/include/freetype
   )

   target_link_libraries(LsCsGuiWin
      PRIVATE
      LsCsCore
      LsCsGui
      opengl32
      gdi32
      winmm
      ole32
      winspool
      oleaut32
      comdlg32
      imm32
      uuid
      user32
   )

   target_compile_definitions(LsCsGuiWin
      PRIVATE
      -DLSCS_PLUGIN
      -DLSCS_USE_FREETYPE
   )

   function_generate_resources(LsCsGuiWin)

   install(TARGETS LsCsGuiWin DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

