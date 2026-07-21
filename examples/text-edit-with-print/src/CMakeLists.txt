list(APPEND EXAMPLE2_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/printerselectiondialog.h
)

list(APPEND EXAMPLE2_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printerselectiondialog.cpp
)


add_executable(${PROJECT_NAME} ${EXAMPLE2_SOURCES})

if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
    target_link_libraries(${PROJECT_NAME}
       PRIVATE
       LsCs::LsCsCore
       LsCs::LsCsGui
       ${CUPS_LIBRARIES}
    )
else()
    target_link_libraries(${PROJECT_NAME}
       PRIVATE
       LsCs::LsCsCore
       LsCs::LsCsGui
    )
endif()

target_include_directories(${PROJECT_NAME}
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
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

