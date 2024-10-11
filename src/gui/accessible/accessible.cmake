list(APPEND GUI_PUBLIC_INCLUDES
    QAccessible
    QAccessibleActionInterface
    QAccessibleApplication
    QAccessibleBridge
    QAccessibleBridgeFactoryInterface
    QAccessibleBridgePlugin
    QAccessibleEditableTextInterface
    QAccessibleEvent
    QAccessibleFactoryInterface
    QAccessibleImageInterface
    QAccessibleInterface
    QAccessibleObject
    QAccessiblePlugin
    QAccessibleTableInterface
    QAccessibleTextInterface
    QAccessibleValueInterface
    QAccessibleWidget
)

list(APPEND GUI_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessible.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleactioninterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleapplication.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblebridge.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblebridgefactoryinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblebridgeplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleeditabletextinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleevent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblefactoryinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleimageinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleobject.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibletableinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibletextinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblevalueinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget.h
)

list(APPEND GUI_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblecache_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblemenu_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_common_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_complex_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_factory_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_range_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_simple_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_views_p.h
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessible.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblebridge.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblecache.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblemenu.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessibleplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_common.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_complex.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_factory.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_range.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_simple.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblewidget_views.cpp
)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/accessible/qaccessiblecache_mac.mm
   )
endif()
