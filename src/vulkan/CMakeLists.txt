add_library(LsCsVulkan SHARED "")
add_library(LsCs::LsCsVulkan ALIAS LsCsVulkan)

set_target_properties(LsCsVulkan PROPERTIES OUTPUT_NAME LsCsVulkan${BUILD_ABI})

target_compile_definitions(LsCsVulkan
   PRIVATE
   -DLSCS_BUILD_VULKAN_LIB
)

set(EXTRA_VULKAN_CXXFLAGS)
set(EXTRA_VULKAN_LDFLAGS)

target_include_directories(LsCsVulkan
   PUBLIC
   $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include/QtVulkan>
   $<INSTALL_INTERFACE:include/QtVulkan>
)

include_directories(
   ${CMAKE_BINARY_DIR}/privateinclude/QtCore/private
   ${CMAKE_BINARY_DIR}/privateinclude/QtGui/private
   ${CMAKE_BINARY_DIR}/privateinclude/QtVulkan/private

   ${CMAKE_CURRENT_SOURCE_DIR}
)

list(APPEND VULKAN_PUBLIC_INCLUDES
   QVulkanDeviceFunctions
   QVulkanFunctions
   QVulkanInstance
   QVulkanWindow
   QVulkanWindowRenderer
)

list(APPEND VULKAN_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkandevicefunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkanfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkaninstance.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkanwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkanwindowrenderer.h

   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_device_functions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_functions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_instance.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_window.h
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_window_renderer.h
)

target_sources(LsCsVulkan
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_device_functions.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_functions.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_instance.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_window.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/qvulkan_window_renderer.cpp
)

macro_generate_public("${VULKAN_PUBLIC_INCLUDES}" QtVulkan)
macro_generate_private("${VULKAN_PRIVATE_INCLUDES}" QtVulkan)
macro_generate_misc("${VULKAN_INCLUDES}" QtVulkan)

function_variable_fixup("${EXTRA_VULKAN_CXXFLAGS}" EXTRA_VULKAN_CXXFLAGS)
function_variable_fixup("${EXTRA_VULKAN_LDFLAGS}"  EXTRA_VULKAN_LDFLAGS)

target_link_libraries(LsCsVulkan
   PUBLIC
   LsCsCore
   LsCsGui
   Vulkan::Vulkan
)

set_target_properties(LsCsVulkan
   PROPERTIES
   COMPILE_FLAGS ${EXTRA_VULKAN_CXXFLAGS}
   LINK_FLAGS ${EXTRA_VULKAN_LDFLAGS}
)

if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
  target_compile_definitions(LsCsVulkan
    PUBLIC
    -DVK_USE_PLATFORM_XCB_KHR
  )

  target_link_libraries(LsCsVulkan
      PRIVATE
      ${XCB_LIB}
  )

else()
  target_compile_definitions(LsCsVulkan
     PUBLIC
     -DVK_USE_PLATFORM_WIN32_KHR
  )

endif()

function_generate_resources(LsCsVulkan)

macro_generate_package(
   LsCsVulkan
   QtVulkan
   ""
   "LsCsCore LsCsGui"
)

if (DEBIAN_FOUND)
    install(
        TARGETS LsCsVulkan
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
else()  
    install(
        TARGETS LsCsVulkan
        EXPORT LsCsLibraryTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()

install(
   DIRECTORY ${CMAKE_BINARY_DIR}/include/QtVulkan
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
   COMPONENT Devel
)
