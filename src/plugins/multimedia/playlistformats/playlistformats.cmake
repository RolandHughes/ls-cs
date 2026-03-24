add_library(LsCsMultimedia_m3u MODULE "")
add_library(LsCs::LsCsMultimedia_m3u ALIAS LsCsMultimedia_m3u)

if ( BUILDING_LOCAL )
    set_target_properties(LsCsMultimedia_m3u PROPERTIES
      PREFIX ""
      VERSION ${BUILD_ABI}
      SOVERSION ${BUILD_MAJOR}
      INSTALL_RPATH "${LSCS_INST_PREFIX}/${LSCS_INST_LIB};${LSCS_INST_PREFIX}/${LSCS_INST_LIB}/plugins/playlistformats"
    )
else()
    set_target_properties(LsCsMultimedia_m3u PROPERTIES
      PREFIX ""
      VERSION ${BUILD_ABI}
      SOVERSION ${BUILD_MAJOR}
    )
endif()


list(APPEND MULTIMEDIA_PRIVATE_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/multimedia/playlistformats/qm3u_plugin.h
)

target_sources(LsCsMultimedia_m3u
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src/plugins/multimedia/playlistformats/qm3u_plugin.cpp
)

target_link_libraries(LsCsMultimedia_m3u
   PRIVATE
   LsCsMultimedia
)

target_compile_definitions(LsCsMultimedia_m3u
   PRIVATE
   -DIN_TRUE
   -DLSCS_PLUGIN
)

#if(BUILDING_RPM OR BUILDING_DEBIAN)
  install(TARGETS LsCsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/playlistformats)
#else()
#  install(TARGETS LsCsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR})
#endif()
