add_library(LsCsXml SHARED "")
add_library(LsCs::LsCsXml ALIAS LsCsXml)

set_target_properties(LsCsXml PROPERTIES 
  VERSION ${BUILD_ABI}
  SOVERSION ${BUILD_MAJOR}
)

add_definitions(
   -DLSCS_BUILD_XML_LIB
)

set(EXTRA_XML_CXXFLAGS)
set(EXTRA_XML_LDFLAGS)

target_include_directories(LsCsXml
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/QtXml>
   $<INSTALL_INTERFACE:include/QtXml>
)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/QtXml/private

   ${CMAKE_CURRENT_SOURCE_DIR}/dom
   ${CMAKE_CURRENT_SOURCE_DIR}/sax
   ${CMAKE_CURRENT_SOURCE_DIR}/stream
   ${GLIB2_INCLUDES}
)

include(dom/dom.cmake)
include(sax/sax.cmake)
include(stream/stream.cmake)

macro_generate_public("${XML_PUBLIC_INCLUDES}"   QtXml)
macro_generate_private("${XML_PRIVATE_INCLUDES}" QtXml)
macro_generate_misc("${XML_INCLUDES}" QtXml)

function_variable_fixup("${EXTRA_XML_CXXFLAGS}" EXTRA_XML_CXXFLAGS)
function_variable_fixup("${EXTRA_XML_LDFLAGS}"  EXTRA_XML_LDFLAGS)

target_sources(LsCsXml
   PRIVATE
   ${XML_INCLUDES}
)

target_link_libraries(LsCsXml
   PUBLIC
   LsCsCore
)

set_target_properties(LsCsXml
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_XML_CXXFLAGS}
   LINK_FLAGS ${EXTRA_XML_LDFLAGS}
)

function_generate_resources(LsCsXml)

macro_generate_package(
   LsCsXml
   QtXml
   "${EXTRA_XML_CXXFLAGS}"
   "LsCsCore"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsXml
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsXml
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/QtXml
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Devel
)
