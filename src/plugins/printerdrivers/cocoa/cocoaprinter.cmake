if(CMAKE_SYSTEM_NAME MATCHES "Darwin")

   add_library(Ls-CsPrinterDriverCocoa MODULE "")
   add_library(Ls-Cs::Ls-CsPrinterDriverCocoa ALIAS Ls-CsPrinterDriverCocoa)

   set_target_properties(Ls-CsPrinterDriverCocoa PROPERTIES OUTPUT_NAME Ls-CsPrinterDriverCocoa${BUILD_ABI})

   target_sources(Ls-CsPrinterDriverCocoa
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/cocoa/main.cpp
   )

   list(APPEND EXTRA_PRINTERDRIVERS_COCOA_LDFLAGS
      -framework Cocoa
   )

   target_link_libraries(Ls-CsPrinterDriverCocoa
      PRIVATE
      Ls-CsCore
      Ls-CsGui
   )

   target_compile_definitions(Ls-CsPrinterDriverCocoa
      PRIVATE
      -DQT_PLUGIN
   )

   install(TARGETS Ls-CsPrinterDriverCocoa DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()
