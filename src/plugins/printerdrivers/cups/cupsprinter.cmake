list(APPEND PRINTERDRIVERS_CUPS_PRIVATE_INCLUDES
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qppdprintdevice.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintersupport_p.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintengine_p.h
)

if(Cups_FOUND)
   add_library(Ls-CsPrinterDriverCups MODULE "")
   add_library(Ls-CS::Ls-CsPrinterDriverCups ALIAS Ls-CsPrinterDriverCups)

   set_target_properties(Ls-CsPrinterDriverCups PROPERTIES OUTPUT_NAME Ls-CsPrinterDriverCups${BUILD_ABI} PREFIX "")

   target_sources(Ls-CsPrinterDriverCups
      PRIVATE
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/main.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qppdprintdevice.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintengine.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintersupport.cpp
   )

   target_include_directories(Ls-CsPrinterDriverCups
      PRIVATE
      ${CUPS_INCLUDE_DIRS}
   )

   target_link_libraries(Ls-CsPrinterDriverCups
      Ls-CsCore
      Ls-CsGui
      ${CUPS_LIBRARIES}
   )

   target_compile_definitions(Ls-CsPrinterDriverCups
      PRIVATE
      -DCS_BUILDING_CUPS
      -DQT_PLUGIN
   )

   function_generate_resources(Ls-CsPrinterDriverCups)

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/printerdrivers)
   else()
      install(TARGETS Ls-CsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

