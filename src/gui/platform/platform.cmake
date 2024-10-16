add_definitions(
   -DQT_USE_FREETYPE
)

list(APPEND GUI_PUBLIC_INCLUDES
   QPlatform_Accessibility
   QPlatform_BackingStore
   QPlatform_Clipboard
   QPlatform_Cursor
   QPlatform_DialogHelper
   QPlatform_Drag
   QPlatform_FontDatabase
   QPlatform_GraphicsBuffer
   QPlatform_GraphicsBufferHelper
   QPlatform_HeaderHelper
   QPlatform_Integration
   QPlatform_IntegrationPlugin
   QPlatform_InputContext
   QPlatform_Menu
   QPlatform_NativeInterface
   QPlatform_OffScreenSurface
   QPlatform_OpenGLContext
   QPlatform_Pixmap
   QPlatform_PrintDevice
   QPlatform_PrinterSupport
   QPlatform_PrintPlugin
   QPlatform_Screen
   QPlatform_Services
   QPlatform_SessionManager
   QPlatform_SharedGraphicsCache
   QPlatform_Surface
   QPlatform_SystemTrayIcon
   QPlatform_Theme
   QPlatform_ThemePlugin
   QPlatform_Window
)

list(APPEND GUI_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_accessibility.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_backingstore.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_clipboard.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_cursor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_dialoghelper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_drag.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_fontdatabase.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_graphicsbuffer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_graphicsbufferhelper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_headerhelper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integration.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integrationplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_menu.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_nativeinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_offscreensurface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_openglcontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_pixmap.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printdevice.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printersupport.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_screen.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_services.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_sessionmanager.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_sharedgraphicscache.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_surface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_systemtrayicon.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_theme.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_themeplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_window.h
)

list(APPEND GUI_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontext_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontextfactory_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontextplugin_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integrationfactory_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_screen_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_theme_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_themefactory_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_window_p.h
)

list(APPEND GUI_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/qbasicfontdatabase_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/qfontengine_ft_p.h
)

list(APPEND GUI_PLATFORMHEADERS_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/cocoa/qcocoanativecontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/cocoa/qcocoawindowfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/xcb/qglxnativecontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/xcb/qxcbintegrationfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/xcb/qxcbscreenfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/xcb/qxcbwindowfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/windows/qwindowswindowfunctions.h
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/windows/qwglnativecontext.h
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_accessibility.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_backingstore.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_clipboard.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_cursor.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_dialoghelper.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_drag.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_fontdatabase.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_graphicsbuffer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_graphicsbufferhelper.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontext.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontextfactory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_inputcontextplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integration.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integrationfactory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_integrationplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_menu.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_nativeinterface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_offscreensurface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_openglcontext.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_pixmap.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printersupport.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_printplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_screen.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_services.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_sessionmanager.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_sharedgraphicscache.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_surface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_systemtrayicon.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_theme.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_themefactory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_themeplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/qplatform_window.cpp

   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/qbasicfontdatabase.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/platform/platformheaders/qfontengine_ft.cpp
)
