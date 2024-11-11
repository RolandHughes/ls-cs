list(APPEND PLATFORMS_XCB_PRIVATE_INCLUDES
)

if(BUILD_PLATFORMS_XCB_PLUGIN)
   add_library(LsCsGuiXcb MODULE "")
   add_library(LsCs::LsCsGuiXcb ALIAS LsCsGuiXcb)

   # TODO:: Need to handle Windows and MAC
   #
   if (BUILDING_DEBIAN)
     set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
        )
   elseif (BUILDING_RPM)
        set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
        )
      else()
        #  ass-u-me local development build
        #
        set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
          INSTALL_RPATH "$ORIGIN/.."
        )
 endif()
 
   target_sources(LsCsGuiXcb
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/xcb/qxcb_main.cpp
   )

   target_link_libraries(LsCsGuiXcb
      PRIVATE
      LsCsCore
      LsCsGui
      LsCsXcbSupport
   )

   target_compile_definitions(LsCsGuiXcb
      PRIVATE
      -DLSCS_PLUGIN
      -DXCB_USE_XINPUT2
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/platforms)
#   else()
#      install(TARGETS LsCsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()

