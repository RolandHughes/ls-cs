add_library(Ls-CsMultimedia_m3u MODULE "")
add_library(Ls-Cs::Ls-CsMultimedia_m3u ALIAS Ls-CsMultimedia_m3u)

set_target_properties(Ls-CsMultimedia_m3u PROPERTIES OUTPUT_NAME Ls-CsMultimedia_m3u${BUILD_ABI} PREFIX "")


list(APPEND MULTIMEDIA_PRIVATE_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/multimedia/playlistformats/qm3u_plugin.h
)

target_sources(Ls-CsMultimedia_m3u
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src/plugins/multimedia/playlistformats/qm3u_plugin.cpp
)

target_link_libraries(Ls-CsMultimedia_m3u
   PRIVATE
   Ls-CsMultimedia
)

target_compile_definitions(Ls-CsMultimedia_m3u
   PRIVATE
   -DIN_TRUE
   -DQT_PLUGIN
)

if(BUILDING_RPM OR BUILDING_DEBIAN)
  install(TARGETS Ls-CsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/playlistformats)
else()
  install(TARGETS Ls-CsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()
