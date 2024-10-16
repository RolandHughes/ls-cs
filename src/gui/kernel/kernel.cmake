list(APPEND GUI_PUBLIC_INCLUDES
   QAction
   QActionEvent
   QActionGroup
   QApplication
   QGuiApplication
   QClipboard
   QClipboardEvent
   QCloseEvent
   QColorGroup
   QContextMenuEvent
   QCursor
   QCursorShape
   QDesktopWidget
   QDrag
   QDragEnterEvent
   QDragLeaveEvent
   QDragMoveEvent
   QDragResponseEvent
   QDropEvent
   QEvent
   QFileOpenEvent
   QFocusEvent
   QGenericPlugin
   QGenericPluginFactory
   QGesture
   QGestureEvent
   QGestureRecognizer
   QHelpEvent
   QHideEvent
   QHoverEvent
   QIconDragEvent
   QInputEvent
   QInputMethod
   QInputMethodEvent
   QKeyEvent
   QKeySequence
   QMenubarUpdatedEvent
   QMouseEvent
   QMoveEvent
   QOffscreenSurface
   QOpenGLContext
   QOpenGLWidget
   QOpenGLWindow
   QPaintDeviceWindow
   QPaintEvent
   QPalette
   QPanGesture
   QPinchGesture
   QPixelFormat
   QRasterWindow
   QResizeEvent
   QScreen
   QSessionManager
   QShortcut
   QShortcutEvent
   QShowEvent
   QSizePolicy
   QSpacerItem
   QStatusTipEvent
   QStyleHints
   QSurface
   QSurfaceFormat
   QSwipeGesture
   QTabletEvent
   QTapAndHoldGesture
   QTapGesture
   QToolBarChangeEvent
   QToolTip
   QTouchDevice
   QTouchEvent
   QUpdateLaterEvent
   QWhatsThis
   QWhatsThisClickedEvent
   QWheelEvent
   QWindow
   QWindowStateChangeEvent
   QWindowSystemInterface
   QtGui
)

list(APPEND GUI_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qaction.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qactionevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qactiongroup.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qapplication.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qguiapplication.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qclipboard.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qclipboardevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcloseevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcolorgroup.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcontextmenuevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcursor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcursorshape.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdesktopwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdrag.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdragenterevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdragleaveevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdragmoveevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdragresponseevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdropevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qfileopenevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qfocusevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgenericplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgenericpluginfactory.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgestureevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesturerecognizer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhelpevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhideevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhoverevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qicondragevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputmethod.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputmethodevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeyevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeysequence.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qmenubarupdatedevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qmouseevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qmoveevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qoffscreensurface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglcontext.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpaintdevicewindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpaintevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpalette.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpangesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpinchgesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpixelformat.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qrasterwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qresizeevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qscreen.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsessionmanager.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshortcut.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshortcutevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshowevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsizepolicy.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qspaceritem.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qstatustipevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qstylehints.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsurface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsurfaceformat.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qswipegesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtabletevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtapandholdgesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtapgesture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtevents.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtoolbarchangeevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtooltip.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtouchdevice.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtouchevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qupdatelaterevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwhatsthis.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwhatsthisclickedevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwheelevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindow.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowdefs.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowdefs_win.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowstatechangeevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowsysteminterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/lscs_carbon_wrapper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtgui.h
)

list(APPEND GUI_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qaction_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qapplication_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qguiapplication_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcursor_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdesktopwidget_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdnd_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qevent_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesture_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesturemanager_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhexstring_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhighdpiscaling_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputdevicemanager_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputmethod_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeymapper_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeysequence_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglcontext_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpaintdevicewindow_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qscreen_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshapedpixmapdndwindow_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsessionmanager_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshortcutmap_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsimpledrag_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qstandardgestures_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtouchdevice_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qvariantgui_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindow_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowcontainer_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowsysteminterface_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/lscs_carbon_wrapper_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/lscs_mac_p.h
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qaction.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qactiongroup.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qapplication.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qapplication_lscs.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qclipboard.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qcursor.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdrag.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdnd.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qdesktopwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qevent.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgenericplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgenericpluginfactory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesture.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesturerecognizer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qgesturemanager.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qhighdpiscaling.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputdevicemanager.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qinputmethod.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeymapper.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qkeysequence.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qoffscreensurface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglcontext.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qopenglwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpaintdevicewindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpalette.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qrasterwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsessionmanager.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsimpledrag.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsizepolicy.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qscreen.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshapedpixmapdndwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshortcut.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qshortcutmap.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qstandardgestures.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qstylehints.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsurface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsurfaceformat.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtooltip.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtouchdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qvariantgui.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwhatsthis.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowcontainer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qwindowsysteminterface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qpixelformat.cpp
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   add_definitions(-DQT_NO_DIRECTDRAW)

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qmacgesturerecognizer.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/kernel/lscs_carbon_wrapper.mm
   )

   list(APPEND EXTRA_GUI_LDFLAGS
      -framework AppKit
   )
endif()
