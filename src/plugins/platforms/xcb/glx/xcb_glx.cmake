list(APPEND PLATFORMS_XCB_GLX_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_context.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_integration.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_nativeinterfacehandler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_window.h

   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_convenience_p.h
)

if(BUILD_PLATFORMS_XCB_PLUGIN AND XCB_GLX_LIB)
   add_library(Ls-CsGuiXcb_Glx MODULE "")
   add_library(Ls-Cs::Ls-CsGuiXcb_Glx ALIAS Ls-CsGuiXcb_Glx)

   set_target_properties(Ls-CsGuiXcb_Glx PROPERTIES
      OUTPUT_NAME Ls-CsGuiXcb_Glx${BUILD_ABI} PREFIX ""
      INSTALL_RPATH "$ORIGIN/.."
   )

   target_sources(Ls-CsGuiXcb_Glx
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_convenience.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_context.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_nativeinterfacehandler.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_window.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_main.cpp
   )

   target_link_libraries(Ls-CsGuiXcb_Glx
      PRIVATE
      Ls-CsCore
      Ls-CsGui
      Ls-CsXcbSupport
      ${XCB_LIB}
      ${XCB_GLX_LIB}
      ${X11_X11_LIB}
   )

   target_include_directories(Ls-CsGuiXcb_Glx
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/platforms/xcb/glx
   )

   target_compile_definitions(Ls-CsGuiXcb_Glx
      PRIVATE
      -DQT_PLUGIN
      -DQT_NO_XRENDER
      -DXCB_HAS_XCB_GLX
      -DXCB_USE_GLX
      -DXCB_USE_XLIB
      -DXCB_USE_XINPUT2
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/xcbglintegrations)
   else()
      install(TARGETS Ls-CsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()
