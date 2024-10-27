if(CMAKE_SYSTEM_NAME MATCHES "Darwin")

   add_library(LsCsPrinterDriverCocoa MODULE "")
   add_library(LsCs::LsCsPrinterDriverCocoa ALIAS LsCsPrinterDriverCocoa)

   set_target_properties(LsCsPrinterDriverCocoa PROPERTIES OUTPUT_NAME LsCsPrinterDriverCocoa${BUILD_ABI})

   target_sources(LsCsPrinterDriverCocoa
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/cocoa/main.cpp
   )

   list(APPEND EXTRA_PRINTERDRIVERS_COCOA_LDFLAGS
      -framework Cocoa
   )

   target_link_libraries(LsCsPrinterDriverCocoa
      PRIVATE
      LsCsCore
      LsCsGui
   )

   target_compile_definitions(LsCsPrinterDriverCocoa
      PRIVATE
      -DLSCS_PLUGIN
   )

   install(TARGETS LsCsPrinterDriverCocoa DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()
