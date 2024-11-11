list(APPEND PRINTERDRIVERS_CUPS_PRIVATE_INCLUDES
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qppdprintdevice.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintersupport_p.h
	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintengine_p.h
)

if(Cups_FOUND)
   add_library(LsCsPrinterDriverCups MODULE "")
   add_library(LsCs::LsCsPrinterDriverCups ALIAS LsCsPrinterDriverCups)

   set_target_properties(LsCsPrinterDriverCups PROPERTIES
     PREFIX ""
     VERSION ${BUILD_ABI}
     SOVERSION ${BUILD_MAJOR}
   )

   target_sources(LsCsPrinterDriverCups
      PRIVATE
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/main.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qppdprintdevice.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintengine.cpp
   	${CMAKE_SOURCE_DIR}/src/plugins/printerdrivers/cups/qcupsprintersupport.cpp
   )

   target_include_directories(LsCsPrinterDriverCups
      PRIVATE
      ${CUPS_INCLUDE_DIRS}
   )

   target_link_libraries(LsCsPrinterDriverCups
      LsCsCore
      LsCsGui
      ${CUPS_LIBRARIES}
   )

   target_compile_definitions(LsCsPrinterDriverCups
      PRIVATE
      -DLSCS_BUILDING_CUPS
      -DLSCS_PLUGIN
   )

   function_generate_resources(LsCsPrinterDriverCups)

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/printerdrivers)
   else()
      install(TARGETS LsCsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

