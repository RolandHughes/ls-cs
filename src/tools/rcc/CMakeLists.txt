add_executable(rcc${TOOLS_SUFFIX} "")
add_executable(Ls-Cs::rcc ALIAS rcc${TOOLS_SUFFIX})

set(EXTRA_RCC_LIBS
   Ls-CsCore
   Ls-CsXml
)

set(EXTRA_RCC_CXXFLAGS)
set(EXTRA_RCC_LDFLAGS)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/QtXml/private

   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(rcc${TOOLS_SUFFIX}
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/rcc.h

   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/rcc.cpp
)

if(CMAKE_SYSTEM_NAME MATCHES "DARWIN")
   list(APPEND EXTRA_RCC_LDFLAGS '-Wl,-rpath,$ORIGIN/../lib')
endif()

if(CMAKE_SYSTEM_NAME MATCHES "(OpenBSD|FreeBSD|NetBSD)")
   list(APPEND EXTRA_RCC_LDFLAGS '-Wl,-rpath,$ORIGIN/../lib')
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
   list(APPEND EXTRA_RCC_LDFLAGS '-Wl,-rpath,$ORIGIN/../lib')
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   list(APPEND EXTRA_RCC_LIBS uuid)
endif()

function_variable_fixup("${EXTRA_RCC_CXXFLAGS}" EXTRA_RCC_CXXFLAGS)
function_variable_fixup("${EXTRA_RCC_LDFLAGS}"  EXTRA_RCC_LDFLAGS)

target_link_libraries(rcc${TOOLS_SUFFIX}
   PRIVATE
   ${EXTRA_RCC_LIBS}
)

set_target_properties(rcc${TOOLS_SUFFIX}
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_RCC_CXXFLAGS}
   LINK_FLAGS ${EXTRA_RCC_LDFLAGS}
   EXPORT_NAME rcc
)

#
#   Now that binary file names don't collide with
#   Qt or any version of CopperSpice, we can just
#   put them in the default binary dir
#
install(
    TARGETS rcc${TOOLS_SUFFIX}
    EXPORT Ls-CsBinaryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
