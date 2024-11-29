list(APPEND CUPS_EXPERIMENT_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/cups-experiment_build_info.h
)

list(APPEND CUPS_EXPERIMENT_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

)

add_executable(${PROJECT_NAME} ${CUPS_EXPERIMENT_SOURCES} ${CUPS_EXPERIMENT_INCLUDES})

target_include_directories(${PROJECT_NAME}
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
   ${CUPS_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
   PRIVATE
   LsCs::LsCsCore
   LsCs::LsCsGui
   LsCs::LsCsNetwork
   ${CUPS_LIBRARIES}
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

