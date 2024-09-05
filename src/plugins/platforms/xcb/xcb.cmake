list(APPEND PLATFORMS_XCB_PRIVATE_INCLUDES
)

if(BUILD_PLATFORMS_XCB_PLUGIN)
   add_library(Ls-CsGuiXcb MODULE "")
   add_library(Ls-Cs::Ls-CsGuiXcb ALIAS Ls-CsGuiXcb)

   set_target_properties(Ls-CsGuiXcb PROPERTIES
      OUTPUT_NAME   Ls-CsGuiXcb${BUILD_ABI} PREFIX ""
      INSTALL_RPATH "$ORIGIN/.."
   )

   target_sources(Ls-CsGuiXcb
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/qxcb_main.cpp
   )

   target_link_libraries(Ls-CsGuiXcb
      PRIVATE
      Ls-CsCore
      Ls-CsGui
      Ls-CsXcbSupport
   )

   target_compile_definitions(Ls-CsGuiXcb
      PRIVATE
      -DQT_PLUGIN
      -DXCB_USE_XINPUT2
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/platforms)
   else()
      install(TARGETS Ls-CsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

