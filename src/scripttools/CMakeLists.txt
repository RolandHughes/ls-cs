add_library(LsCsScriptTools SHARED "")
add_library(LsCs::LsCsScriptTools ALIAS LsCsScriptTools)

set_target_properties(LsCsScriptTools PROPERTIES OUTPUT_NAME LsCsScriptTools${BUILD_ABI})

target_add_definitions(LsCsScriptTools
   PRIVATE
   -DQT_BUILD_SCRIPTTOOLS_LIB
)

set(EXTRA_SCRIPTTOOLS_CXXFLAGS)
set(EXTRA_SCRIPTTOOLS_LDFLAGS)

include_directories(
    ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
    ${CMAKE_BINARY_DIR}/privateinclude/QtGui/private

    ${CMAKE_BINARY_DIR}/include/QtScriptTools
    ${CMAKE_BINARY_DIR}/privateinclude/QtScriptTools/private

    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/debugging
)

include(debugging/debugging.cmake)

macro_generate_public("${SCRIPTTOOLS_PUBLIC_INCLUDES}"   QtScriptTools)
macro_generate_private("${SCRIPTTOOLS_PRIVATE_INCLUDES}" QtScriptTools)
macro_generate_misc("${SCRIPTTOOLS_INCLUDES}" QtScriptTools)

function_variable_fixup("${EXTRA_SCRIPTTOOLS_CXXFLAGS}" EXTRA_SCRIPTTOOLS_CXXFLAGS)
function_variable_fixup("${EXTRA_SCRIPTTOOLS_LDFLAGS}"  EXTRA_SCRIPTTOOLS_LDFLAGS)

target_link_libraries(LsCsScriptTools
   PRIVATE
   LsCsCore
   LsCsScript
)

set_target_properties(LsCsScriptTools
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_SCRIPTTOOLS_CXXFLAGS}
   LINK_FLAGS ${EXTRA_SCRIPTTOOLS_LDFLAGS}
)

function_generate_resources("${SCRIPTTOOLS_SOURCES}")

macro_generate_package(
   LsCsScriptTools
   QtScriptTools
   "${EXTRA_SCRIPTTOOLS_CXXFLAGS}"
   "LsCsCore LsCsGui"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsScriptTools
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsScriptTools
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()  

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/QtScriptTools
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Devel
)
