list(APPEND CUPS_3X_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_device_cups.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_pdf.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_postscript.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_raw.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_single_file_job_dialog.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_single_file_job.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_device.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_text.h
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagelayout.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qpagesize.h
)

list(APPEND CUPS_3X_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/myeditwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_device_cups.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_single_file_job_dialog.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_single_file_job.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/lscs_spooler_device.cpp
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

