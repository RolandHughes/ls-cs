add_library(LsCsMultimedia SHARED "")
add_library(LsCs::LsCsMultimedia ALIAS LsCsMultimedia)

set_target_properties(LsCsMultimedia PROPERTIES
    VERSION ${BUILD_ABI}
  SOVERSION ${BUILD_MAJOR}
)

target_compile_definitions(LsCsMultimedia
   PRIVATE
   -DLSCS_BUILD_MULTIMEDIA_LIB
)

set(EXTRA_MULTIMEDIA_CXXFLAGS)
set(EXTRA_MULTIMEDIA_LDFLAGS)

target_include_directories(LsCsMultimedia
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/QtMultimedia>
   $<INSTALL_INTERFACE:include/QtMultimedia>
)

include_directories(
    ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
    ${CMAKE_BINARY_DIR}/privateinclude/QtMultimedia/private

    ${CMAKE_CURRENT_SOURCE_DIR}/audio
    ${CMAKE_CURRENT_SOURCE_DIR}/camera
    ${CMAKE_CURRENT_SOURCE_DIR}/controls
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel
    ${CMAKE_CURRENT_SOURCE_DIR}/playback
    ${CMAKE_CURRENT_SOURCE_DIR}/radio
    ${CMAKE_CURRENT_SOURCE_DIR}/recording
    ${CMAKE_CURRENT_SOURCE_DIR}/video
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets
)

include(audio/audio.cmake)
include(camera/camera.cmake)
include(controls/controls.cmake)
include(kernel/kernel.cmake)
include(playback/playback.cmake)
include(radio/radio.cmake)
include(recording/recording.cmake)
include(video/video.cmake)
include(widgets/widgets.cmake)

include(../plugins/multimedia/mediaservices/avfoundation/avfoundation.cmake)
include(../plugins/multimedia/mediaservices/directshow/directshow.cmake)
include(../plugins/multimedia/mediaservices/gstreamer/gstreamer.cmake)
include(../plugins/multimedia/playlistformats/playlistformats.cmake)

macro_generate_public("${MULTIMEDIA_PUBLIC_INCLUDES}" QtMultimedia)
macro_generate_private("${MULTIMEDIA_PRIVATE_INCLUDES}" QtMultimedia)
macro_generate_misc("${MULTIMEDIA_INCLUDES}" QtMultimedia)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   list(APPEND EXTRA_MULTIMEDIA_LDFLAGS
      -framework OpenGL
   )
endif()

function_variable_fixup("${EXTRA_MULTIMEDIA_CXXFLAGS}" EXTRA_MULTIMEDIA_CXXFLAGS)
function_variable_fixup("${EXTRA_MULTIMEDIA_LDFLAGS}"  EXTRA_MULTIMEDIA_LDFLAGS)

target_sources(LsCsMultimedia
   PRIVATE
   ${MULTIMEDIA_INCLUDES}
)

target_link_libraries(LsCsMultimedia
   PUBLIC
   LsCsCore
   LsCsGui
   LsCsNetwork
   LsCsOpenGL
)

target_include_directories(LsCsMultimedia
   PUBLIC
   ${GSTREAMER_INCLUDE_DIRS}
)

set_target_properties(LsCsMultimedia
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_MULTIMEDIA_CXXFLAGS}
   LINK_FLAGS ${EXTRA_MULTIMEDIA_LDFLAGS}
)

function_generate_resources(LsCsMultimedia)

macro_generate_package(
   LsCsMultimedia
   QtMultimedia
   "${EXTRA_MULTIMEDIA_CXXFLAGS}"
   "LsCsCore LsCsGui"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsMultimedia
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsMultimedia
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()  

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/QtMultimedia
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Devel
)
