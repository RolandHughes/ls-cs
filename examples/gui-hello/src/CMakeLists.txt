list(APPEND GUI-HELLO_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/gui-hello_build_info.h
)

list(APPEND GUI-HELLO_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h

)

add_executable(gui-hello ${GUI-HELLO_SOURCES} ${GUI-HELLO_INCLUDES})

target_include_directories(gui-hello
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(gui-hello
   PRIVATE
   LsCs::LsCsCore
   LsCs::LsCsGui
   LsCs::LsCsNetwork
)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set_target_properties(gui-hello PROPERTIES OUTPUT_NAME gui-hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set_target_properties(gui-hello PROPERTIES OUTPUT_NAME gui-hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   install(TARGETS gui-hello DESTINATION ../MacOS)
else()
   install(TARGETS gui-hello DESTINATION .)
endif()

