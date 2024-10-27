list(APPEND IMAGEFORMATS_SVG_PRIVATE_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/qsvgiohandler.h
)

if(WITH_SVG)
   add_library(LsCsImageFormatsSvg MODULE "")
   add_library(LsCs::LsCsImageFormatsSvg ALIAS LsCsImageFormatsSvg)

   set_target_properties(LsCsImageFormatsSvg PROPERTIES OUTPUT_NAME LsCsImageFormatsSvg${BUILD_ABI} PREFIX "")

   target_sources(LsCsImageFormatsSvg
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/qsvgiohandler.cpp
   )

   target_link_libraries(LsCsImageFormatsSvg
      LsCsCore
      LsCsGui
      LsCsSvg
   )

   target_compile_definitions(LsCsImageFormatsSvg
      PRIVATE
      -DLSCS_PLUGIN
   )

   function_generate_resources(LsCsImageFormatsSvg)


#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsImageFormatsSvg DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/imageformats)
#   else()
#      install(TARGETS LsCsImageFormatsSvg DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()

