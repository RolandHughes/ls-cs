list(APPEND IMAGEFORMATS_SVG_PRIVATE_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/qsvgiohandler.h
)

if(WITH_SVG)
   add_library(Ls-CsImageFormatsSvg MODULE "")
   add_library(Ls-Cs::Ls-CsImageFormatsSvg ALIAS Ls-CsImageFormatsSvg)

   set_target_properties(Ls-CsImageFormatsSvg PROPERTIES OUTPUT_NAME Ls-CsImageFormatsSvg${BUILD_ABI} PREFIX "")

   target_sources(Ls-CsImageFormatsSvg
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/imageformats/svg/qsvgiohandler.cpp
   )

   target_link_libraries(Ls-CsImageFormatsSvg
      Ls-CsCore
      Ls-CsGui
      Ls-CsSvg
   )

   target_compile_definitions(Ls-CsImageFormatsSvg
      PRIVATE
      -DQT_PLUGIN
   )

   function_generate_resources(Ls-CsImageFormatsSvg)


   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsImageFormatsSvg DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/imageformats)
   else()
      install(TARGETS Ls-CsImageFormatsSvg DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

