list(APPEND CONSOLE-HELLO_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/console-hello_build_info.h
)

list(APPEND CONSOLE-HELLO_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

)

add_executable(console-hello ${CONSOLE-HELLO_SOURCES} ${CONSOLE-HELLO_INCLUDES})

target_include_directories(console-hello
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(console-hello
   PRIVATE
   LsCs::LsCsCore
   LsCs::LsCsGui
   LsCs::LsCsNetwork
)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set_target_properties(console-hello PROPERTIES OUTPUT_NAME console-hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set_target_properties(console-hello PROPERTIES OUTPUT_NAME console-hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   install(TARGETS console-hello DESTINATION ../MacOS)
else()
   install(TARGETS console-hello DESTINATION .)
endif()

