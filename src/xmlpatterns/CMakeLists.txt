add_library(LsCsXmlPatterns SHARED "")
add_library(LsCs::LsCsXmlPatterns ALIAS LsCsXmlPatterns)

set_target_properties(LsCsXmlPatterns PROPERTIES
  VERSION ${BUILD_ABI}
  SOVERSION ${BUILD_MAJOR}
)


add_definitions(
   -DLSCS_BUILD_XMLPATTERNS_LIB
)

set(EXTRA_XMLPATTERNS_CXXFLAGS)
set(EXTRA_XMLPATTERNS_LDFLAGS)

target_include_directories(LsCsXmlPatterns
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/QtXmlPatterns>
   $<INSTALL_INTERFACE:include/${PACKAGE_NAME}/QtXmlPatterns>
)

include_directories(
    ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtCore/private
    ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtXmlPatterns/private

    ${CMAKE_CURRENT_SOURCE_DIR}/acceltree
    ${CMAKE_CURRENT_SOURCE_DIR}/api
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    ${CMAKE_CURRENT_SOURCE_DIR}/environment
    ${CMAKE_CURRENT_SOURCE_DIR}/expr
    ${CMAKE_CURRENT_SOURCE_DIR}/functions
    ${CMAKE_CURRENT_SOURCE_DIR}/iterators
    ${CMAKE_CURRENT_SOURCE_DIR}/janitors
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
    ${CMAKE_CURRENT_SOURCE_DIR}/projection
    ${CMAKE_CURRENT_SOURCE_DIR}/qtokenautomaton
    ${CMAKE_CURRENT_SOURCE_DIR}/schema
    ${CMAKE_CURRENT_SOURCE_DIR}/type
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

include(acceltree/acceltree.cmake)
include(api/api.cmake)
include(data/data.cmake)
include(environment/environment.cmake)
include(expr/expr.cmake)
include(functions/functions.cmake)
include(iterators/iterators.cmake)
include(janitors/janitors.cmake)
include(parser/parser.cmake)
include(projection/projection.cmake)
include(schema/schema.cmake)
include(type/type.cmake)
include(utils/utils.cmake)

macro_generate_public("${XMLPATTERNS_PUBLIC_INCLUDES}" QtXmlPatterns)
macro_generate_private("${XMLPATTERNS_PRIVATE_INCLUDES}" QtXmlPatterns)
macro_generate_misc("${XMLPATTERNS_INCLUDES}" QtXmlPatterns)

function_variable_fixup("${EXTRA_XMLPATTERNS_CXXFLAGS}" EXTRA_XMLPATTERNS_CXXFLAGS)
function_variable_fixup("${EXTRA_XMLPATTERNS_LDFLAGS}" EXTRA_XMLPATTERNS_LDFLAGS)

target_sources(LsCsXmlPatterns
   PRIVATE
   ${XMLPATTERNS_INCLUDES}
)

target_link_libraries(LsCsXmlPatterns
   PRIVATE
   LsCsCore
   LsCsNetwork
)

set_target_properties(LsCsXmlPatterns
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_XMLPATTERNS_CXXFLAGS}
   LINK_FLAGS ${EXTRA_XMLPATTERNS_LDFLAGS}
)

function_generate_resources(LsCsXmlPatterns)

macro_generate_package(
   LsCsXmlPatterns
   QtXmlPatterns
   "${EXTRA_XMLPATTERNS_CXXFLAGS}"
   "LsCsCore LsCsNetwork"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsXmlPatterns
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsXmlPatterns
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()  

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}/QtXmlPatterns
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Devel
)
