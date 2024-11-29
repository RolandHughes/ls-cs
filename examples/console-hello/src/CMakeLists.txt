list(APPEND CONSOLE-HELLO_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}_build_info.h
)

list(APPEND CONSOLE-HELLO_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

)

add_executable(${PROJECT_NAME} ${CONSOLE-HELLO_SOURCES} ${CONSOLE-HELLO_INCLUDES})

target_include_directories(${PROJECT_NAME}
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
   PRIVATE
   LsCs::LsCsCore
   LsCs::LsCsGui
   LsCs::LsCsNetwork
)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   install(TARGETS ${PROJECT_NAME} DESTINATION ../MacOS)
else()
   install(TARGETS ${PROJECT_NAME} DESTINATION .)
endif()

#  If you are using RPATH in the main CMakeLists.txt
#  then you need to copy the libraries and plugins
#  where the executable looks for them.
#
#  This flies in the face of shared libraries but
#  could be handy if you are testing library changes.
#
# lscs_copy_library(LsCsCore)
# lscs_copy_library(LsCsGui)
# lscs_copy_library(LsCsNetwork)
#
# if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   # copy required plugins to the bundle
   # lscs_copy_plugins(LsCsGui ../plugins)
# else()
   # installs required plugins
   #lscs_copy_plugins(LsCsGui)
# endif()
