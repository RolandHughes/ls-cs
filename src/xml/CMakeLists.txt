add_library(Ls-CsXml SHARED "")
add_library(Ls-Cs::Ls-CsXml ALIAS Ls-CsXml)

set_target_properties(Ls-CsXml PROPERTIES OUTPUT_NAME Ls-CsXml${BUILD_ABI})

add_definitions(
   -DQT_BUILD_XML_LIB
)

set(EXTRA_XML_CXXFLAGS)
set(EXTRA_XML_LDFLAGS)

target_include_directories(Ls-CsXml
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

target_sources(Ls-CsXml
   PRIVATE
   ${XML_INCLUDES}
)

target_link_libraries(Ls-CsXml
   PUBLIC
   Ls-CsCore
)

set_target_properties(Ls-CsXml
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_XML_CXXFLAGS}
   LINK_FLAGS ${EXTRA_XML_LDFLAGS}
)

function_generate_resources(Ls-CsXml)

macro_generate_package(
   Ls-CsXml
   QtXml
   "${EXTRA_XML_CXXFLAGS}"
   "Ls-CsCore"
)

install(
   TARGETS Ls-CsXml
   EXPORT Ls-CsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/QtXml
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Devel
)
