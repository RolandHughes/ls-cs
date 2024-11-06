list(APPEND PLATFORMS_XCB_GLX_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_context.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_integration.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_nativeinterfacehandler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_window.h

   ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_convenience_p.h
)

if(BUILD_PLATFORMS_XCB_PLUGIN AND XCB_GLX_LIB)
   add_library(LsCsGuiXcb_Glx MODULE "")
   add_library(LsCs::LsCsGuiXcb_Glx ALIAS LsCsGuiXcb_Glx)

   set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

   if (BUILDING_DEBIAN)
      set_target_properties(LsCsGuiXcb_Glx PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
      )
   elseif (BUILDING_RPM)
      set_target_properties(LsCsGuiXcb_Glx PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
      )
    else()
      # ass-u-me local build for testing
     set_target_properties(LsCsGuiXcb_Glx PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
          INSTALL_RPATH "$ORIGIN/.."
    )
  endif()
  

   target_sources(LsCsGuiXcb_Glx
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_convenience.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qglx_context.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_integration.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_nativeinterfacehandler.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_window.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/glx/qxcb_glx_main.cpp
   )

   target_link_libraries(LsCsGuiXcb_Glx
      PRIVATE
      LsCsCore
      LsCsGui
      LsCsXcbSupport
      ${XCB_LIB}
      ${XCB_GLX_LIB}
      ${X11_X11_LIB}
   )

   target_include_directories(LsCsGuiXcb_Glx
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/platforms/xcb/glx
   )

   target_compile_definitions(LsCsGuiXcb_Glx
      PRIVATE
      -DLSCS_PLUGIN
      -DLSCS_NO_XRENDER
      -DXCB_HAS_XCB_GLX
      -DXCB_USE_GLX
      -DXCB_USE_XLIB
      -DXCB_USE_XINPUT2
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/xcbglintegrations)
#   else()
#      install(TARGETS LsCsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()
