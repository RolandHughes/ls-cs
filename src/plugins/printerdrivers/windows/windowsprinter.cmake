list(APPEND PRINTERDRIVERS_WIN_PRIVATE_INCLUDES
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintersupport.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintdevice.h
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")

   add_library(Ls-CsPrinterDriverWin MODULE "")
   add_library(Ls-Cs::Ls-CsPrinterDriverWin ALIAS Ls-CsPrinterDriverWin)

   set_target_properties(Ls-CsPrinterDriverWin PROPERTIES OUTPUT_NAME Ls-CsPrinterDriverWin${BUILD_ABI} PREFIX "")

   target_sources(Ls-CsPrinterDriverWin
      PRIVATE
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/main.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintersupport.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/windows/qwindowsprintdevice.cpp
   )

   target_link_libraries(Ls-CsPrinterDriverWin
      PRIVATE
      Ls-CsCore
      Ls-CsGui
      winspool
      comdlg32
      gdi32
      user32
   )

   target_compile_definitions(Ls-CsPrinterDriverWin
      PRIVATE
      -DQT_PLUGIN
   )

   install(TARGETS Ls-CsPrinterDriverWin DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

