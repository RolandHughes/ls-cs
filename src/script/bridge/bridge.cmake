list(APPEND SCRIPT_PRIVATE_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptfunction_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptclassobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptvariant_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptqobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptglobalobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptactivationobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptstaticscopeobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptdeclarativeobject_p.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptdeclarativeclass_p.h
)

target_sources(LsCsScript
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptfunction.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptclassobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptvariant.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptqobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptglobalobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptactivationobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptstaticscopeobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptdeclarativeobject.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bridge/qscriptdeclarativeclass.cpp
)
