list(APPEND PRINTERDRIVERS_WIN_PRIVATE_INCLUDES
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintersupport.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintdevice.h
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")

   add_library(LsCsPrinterDriverWin MODULE "")
   add_library(LsCs::LsCsPrinterDriverWin ALIAS LsCsPrinterDriverWin)

   set_target_properties(LsCsPrinterDriverWin PROPERTIES OUTPUT_NAME LsCsPrinterDriverWin${BUILD_ABI} PREFIX "")

   target_sources(LsCsPrinterDriverWin
      PRIVATE
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/main.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintersupport.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintdevice.cpp
   )

   target_link_libraries(LsCsPrinterDriverWin
      PRIVATE
      LsCsCore
      LsCsGui
      winspool
      comdlg32
      gdi32
      user32
   )

   target_compile_definitions(LsCsPrinterDriverWin
      PRIVATE
      -DQT_PLUGIN
   )

   install(TARGETS LsCsPrinterDriverWin DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

