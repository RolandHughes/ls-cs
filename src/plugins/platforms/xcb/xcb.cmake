list(APPEND PLATFORMS_XCB_PRIVATE_INCLUDES
)

if(BUILD_PLATFORMS_XCB_PLUGIN)
   add_library(LsCsGuiXcb MODULE "")
   add_library(LsCs::LsCsGuiXcb ALIAS LsCsGuiXcb)

   # TODO:: Need to handle Windows and MAC
   #
   if (BUILDING_DEBIAN)
     set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
     set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
        )
   elseif (BUILDING_RPM)
     set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
     set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
        )
   elseif (BUILDING_LOCAL)
     message("*****************************")
     message("     XCB BUILDING_LOCAL ")
     message("*****************************")
     set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
          INSTALL_RPATH "${LSCS_INST_PREFIX}/${LSCS_INST_LIB};${LSCS_INST_PREFIX}/${LSCS_INST_LIB}/plugins/platforms"
        )
   else()
        #  ass-u-me local install tree and hope for the best
        #
      message("*****************************")
      message("     XCB BUILDING unknown ")
      message("*****************************")
     set_target_properties(LsCsGuiXcb PROPERTIES
          VERSION ${BUILD_ABI}
          SOVERSION ${BUILD_MAJOR}
          PREFIX ""
          INSTALL_RPATH "$ORIGIN/../.."
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
      ls_libtool_ep
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

