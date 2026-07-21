add_executable(lconvert${TOOLS_SUFFIX} "")
add_executable(LsCs::lconvert ALIAS lconvert${TOOLS_SUFFIX})

add_definitions(
   -DPROEVALUATOR_CUMULATIVE
   -DPROEVALUATOR_INIT_PROPS
)

set(EXTRA_LCONVERT_LIBS
   LsCsCore
   LsCsXml
)

set(EXTRA_LCONVERT_CXXFLAGS)
set(EXTRA_LCONVERT_LDFLAGS)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/${PACKAGE_NAME}/QtXml/private

   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_SOURCE_DIR}/src/tools/shared
)

target_sources(lconvert${TOOLS_SUFFIX}
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

if(CMAKE_SYSTEM_NAME MATCHES "DARWIN")
   list(APPEND EXTRA_LCONVERT_LDFLAGS  '-Wl,-rpath,$ORIGIN/../lib')
endif()

if(CMAKE_SYSTEM_NAME MATCHES "(OpenBSD|FreeBSD|NetBSD)")
   list(APPEND EXTRA_LCONVERT_LDFLAGS  '-Wl,-rpath,$ORIGIN/../lib')
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  if(BUILDING_DEBIAN OR BUILDING_RPM)
    # only use RPATH for local build
  else()
      list(APPEND EXTRA_LCONVERT_LDFLAGS  '-Wl,-rpath,$ORIGIN/../lib')
  endif()
endif()

# don't include sharedtools until you have the full list of sources
#
target_sources(lconvert${TOOLS_SUFFIX}
   PRIVATE
   $<TARGET_OBJECTS:sharedtools>
 )
 
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   list(APPEND EXTRA_LCONVERT_LIBS
      uuid
   )
endif()
 

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   list(APPEND EXTRA_LCONVERT_LIBS
      uuid
   )
endif()

function_variable_fixup("${EXTRA_LCONVERT_CXXFLAGS}" EXTRA_LCONVERT_CXXFLAGS)
function_variable_fixup("${EXTRA_LCONVERT_LDFLAGS}"  EXTRA_LCONVERT_LDFLAGS)

target_link_libraries(lconvert${TOOLS_SUFFIX}
   PRIVATE
   ${EXTRA_LCONVERT_LIBS}
)

set_target_properties(lconvert${TOOLS_SUFFIX}
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_LCONVERT_CXXFLAGS}
   LINK_FLAGS ${EXTRA_LCONVERT_LDFLAGS}
   EXPORT_NAME lconvert
)

install(
    TARGETS lconvert${TOOLS_SUFFIX}
    EXPORT LsCsBinaryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
