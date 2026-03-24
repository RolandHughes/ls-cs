add_library(LsCsSvg SHARED "")
add_library(LsCs::LsCsSvg ALIAS LsCsSvg)

set_target_properties(LsCsSvg PROPERTIES
  VERSION ${BUILD_ABI}
  SOVERSION ${BUILD_MAJOR}
)

add_definitions(
   -DLSCS_BUILD_SVG_LIB
)

set(EXTRA_SVG_CXXFLAGS)
set(EXTRA_SVG_LDFLAGS)

target_include_directories(LsCsSvg
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/QtSvg>
   $<INSTALL_INTERFACE:include/${PACKAGE_NAME}/QtSvg>
)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtGui/private
   ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtSvg/private

   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_SOURCE_DIR}/src/3rdparty/harfbuzz/src
)

set(SVG_PUBLIC_INCLUDES
   QtSvg
   QGraphicsSvgItem
   QSvgGenerator
   QSvgRenderer
   QSvgWidget
)

list(APPEND SVG_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgrenderer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qgraphicssvgitem.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvggenerator.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qtsvg.h
)

list(APPEND SVG_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvggraphics_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvghandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgnode_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgstructure_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgstyle_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgfont_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgtinydocument_p.h
)

target_sources(LsCsSvg
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvggraphics.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvghandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgnode.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgstructure.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgstyle.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgfont.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgtinydocument.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgrenderer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvgwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qgraphicssvgitem.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qsvggenerator.cpp
)

macro_generate_public("${SVG_PUBLIC_INCLUDES}"   QtSvg)
macro_generate_private("${SVG_PRIVATE_INCLUDES}" QtSvg)
macro_generate_misc("${SVG_INCLUDES}" QtSvg)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   target_link_libraries(LsCsSvg
      PRIVATE
      ws2_32
   )
endif()

function_variable_fixup("${EXTRA_SVG_CXXFLAGS}" EXTRA_SVG_CXXFLAGS)
function_variable_fixup("${EXTRA_SVG_LDFLAGS}"  EXTRA_SVG_LDFLAGS)

target_sources(LsCsSvg
   PRIVATE
   ${SVG_INCLUDES}
)

target_link_libraries(LsCsSvg
   PRIVATE
   LsCsCore
   LsCsGui
)

set_target_properties(LsCsSvg
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_SVG_CXXFLAGS}
   LINK_FLAGS ${EXTRA_SVG_LDFLAGS}
)

function_generate_resources(LsCsSvg)

macro_generate_package(
   LsCsSvg
   QtSvg
  "${EXTRA_SVG_CXXFLAGS}"
   "LsCsCore LsCsGui"
)

if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   add_definitions(
      -DHAVE_POSIX_MEMALIGN
   )
endif()

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsSvg
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsSvg
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif() 

install(
   DIRECTORY ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/QtSvg
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
   COMPONENT Devel
)
