list(APPEND CS_GUI_HELLO_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/cs_gui_hello_build_info.h
)

list(APPEND CS_GUI_HELLO_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h

)
#   qrc_cs_gui_hello.cpp

# run rcc to generate qrc output
# COPPERSPICE_RESOURCES(
#   ${CMAKE_CURRENT_SOURCE_DIR}/../cs_gui_hello.qrc
#)

# run uic to generate source
# .ui files go here
#COPPERSPICE_RESOURCES(
#)

add_executable(Cs_GUI_Hello ${CS_GUI_HELLO_SOURCES})

target_include_directories(Cs_GUI_Hello
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(Cs_GUI_Hello
   PRIVATE
   CopperSpice::CsCore
   CopperSpice::CsGui
   CopperSpice::CsNetwork
)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set_target_properties(Cs_GUI_Hello PROPERTIES OUTPUT_NAME cs_gui_hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
   set_target_properties(Cs_GUI_Hello PROPERTIES OUTPUT_NAME cs_gui_hello)

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   install(TARGETS Cs_GUI_Hello DESTINATION ../MacOS)
else()
   install(TARGETS Cs_GUI_Hello DESTINATION .)
endif()

cs_copy_library(CsCore)
cs_copy_library(CsGui)
cs_copy_library(CsNetwork)
cs_copy_library(CsMultimedia)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   # copy required plugins to the bundle
   cs_copy_plugins(CsGui ../plugins)
   cs_copy_plugins(CsPrinterDriver ../plugins)
else()
   # installs required plugins
   cs_copy_plugins(CsGui)
   cs_copy_plugins(CsPrinterDriver)
endif()