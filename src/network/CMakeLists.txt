add_library(LsCsNetwork SHARED "")
add_library(LsCs::LsCsNetwork ALIAS LsCsNetwork)

set_target_properties(LsCsNetwork PROPERTIES OUTPUT_NAME LsCsNetwork${BUILD_ABI})

target_compile_definitions(LsCsNetwork
   PRIVATE
   -DQT_BUILD_NETWORK_LIB
)

set(EXTRA_NETWORK_CXXFLAGS)
set(EXTRA_NETWORK_LDFLAGS)

if (SECURETRANSPORT_FOUND)
   # darwin
   target_compile_definitions(LsCsNetwork
      PUBLIC
      -DQT_SSL
      -DQT_SECURETRANSPORT
   )

elseif (OPENSSL_FOUND)
   target_compile_definitions(LsCsNetwork
      PUBLIC
      -DQT_SSL
      -DQT_OPENSSL
   )
   include_directories(${OPENSSL_INCLUDE_DIR})

   target_link_libraries(LsCsNetwork
      PRIVATE
      ${OPENSSL_LIBRARIES}
   )
endif()

target_include_directories(LsCsNetwork
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/QtNetwork>
   $<INSTALL_INTERFACE:include/QtNetwork>
)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/QtNetwork/private

   ${CMAKE_CURRENT_SOURCE_DIR}/access
   ${CMAKE_CURRENT_SOURCE_DIR}/bearer
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel
   ${CMAKE_CURRENT_SOURCE_DIR}/socket
   ${CMAKE_CURRENT_SOURCE_DIR}/ssl
)

include(access/access.cmake)
include(bearer/bearer.cmake)
include(kernel/kernel.cmake)
include(socket/socket.cmake)
include(ssl/ssl.cmake)

macro_generate_public("${NETWORK_PUBLIC_INCLUDES}"   QtNetwork)
macro_generate_private("${NETWORK_PRIVATE_INCLUDES}" QtNetwork)
macro_generate_misc("${NETWORK_INCLUDES}" QtNetwork)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   list(APPEND EXTRA_NETWORK_CXXFLAGS
      -D__APPLE_USE_RFC_3542
   )

   list(APPEND EXTRA_NETWORK_LDFLAGS
      -framework CoreServices
      -framework Security
      -framework SystemConfiguration
   )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   target_link_libraries(LsCsNetwork
      PRIVATE
      ws2_32
      crypt32
      secur32
      dnsapi
      iphlpapi
    )
endif()

function_variable_fixup("${EXTRA_NETWORK_CXXFLAGS}" EXTRA_NETWORK_CXXFLAGS)
function_variable_fixup("${EXTRA_NETWORK_LDFLAGS}"  EXTRA_NETWORK_LDFLAGS)

target_sources(LsCsNetwork
   PRIVATE
   ${NETWORK_INCLUDES}
)

target_link_libraries(LsCsNetwork
   PUBLIC
   LsCsCore
)

set_target_properties(LsCsNetwork
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_NETWORK_CXXFLAGS}
   LINK_FLAGS ${EXTRA_NETWORK_LDFLAGS}
)

function_generate_resources(LsCsNetwork)

macro_generate_package(
   LsCsNetwork
   QtNetwork
   "${EXTRA_NETWORK_CXXFLAGS}"
   "LsCsCore"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsNetwork
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsNetwork
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif() 

install(
   DIRECTORY ${CMAKE_BINARY_DIR}/include/QtNetwork
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
   COMPONENT Devel
)
