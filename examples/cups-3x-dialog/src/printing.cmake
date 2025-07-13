list(APPEND GUI_PUBLIC_INCLUDES
  QPageLayout
  QPageSize
  QPdfWriter
  BdSpooler
  BdCupsSpoolerDevice
)

list(APPEND GUI_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagelayout.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagesize.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdspooler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdspoolerdevice.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdtextspooler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdpdfspooler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdrawspooler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdpostscriptspooler.h
)

list(APPEND GUI_PRIVATE_INCLUDES
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagelayout.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/qpagesize.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdspoolerdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdspooler.cpp
 )

 if (Cups_FOUND)

   message( STATUS, "******* CUPS being added to print")
   
   list(APPEND GUI_INCLUDES
     ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdcupsspoolerdevice.h
   )
   
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdcupsspoolerdevice.cpp
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
     ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdwinspoolerdevice.h
   )
   
   target_compile_definitions(LsCsGui
      PRIVATE
      -DLSCS_BUILDING_WIN
    )
   
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/printing/bdwinspoolerdevice.cpp
    )
 endif()
 

