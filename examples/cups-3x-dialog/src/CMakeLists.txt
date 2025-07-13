list(APPEND CUPS_3X_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdcupsspoolerdevice.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdpdfspooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdpostscriptspooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdrawspooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdsinglefilejobdialog.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdsinglefilejob.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdspoolerdevice.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdspooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/bdtextspooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagelayout.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagesize.h
)

list(APPEND CUPS_3X_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bdcupsspoolerdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bdsinglefilejobdialog.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bdsinglefilejob.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bdspooler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bdspoolerdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagelayout.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagesize.cpp

)


add_executable(${PROJECT_NAME} ${CUPS_3X_INCLUDES} ${CUPS_3X_SOURCES})

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

