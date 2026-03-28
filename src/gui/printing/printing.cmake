list(APPEND GUI_PUBLIC_INCLUDES
  QPageLayout
  QPageSize
  lscs_spooler
  lscs_spooler_device
)

list(APPEND GUI_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagelayout.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagesize.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_pdf.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_postscript.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_raw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_text.h
)

list(APPEND GUI_PRIVATE_INCLUDES
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagelayout.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagesize.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler.cpp
 )

 if (Cups_FOUND)

   message( STATUS, "******* CUPS being added to print")
   
   list(APPEND GUI_INCLUDES
     ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device_cups.h
   )
   
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device_cups.cpp
    )

    target_link_libraries(LsCsGui
      PRIVATE
      ${CUPS_LIBRARIES}
    )

    include_directories(
      ${CUPS_INCLUDE_DIRS}
    )

 elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
   list(APPEND GUI_INCLUDES
     ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device_windows.h
   )
   
   target_compile_definitions(LsCsGui
      PRIVATE
      -DLSCS_BUILDING_WIN
    )
   
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/printing/lscs_spooler_device_windows.cpp
    )
 endif()
 

