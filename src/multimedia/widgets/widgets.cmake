list(APPEND MULTIMEDIA_PUBLIC_INCLUDES
   QCameraViewfinder
   QVideoWidget
)

list(APPEND MULTIMEDIA_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qcameraviewfinder.h
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qgraphicsvideoitem.h
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qvideowidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qvideowidgetcontrol.h
)

list(APPEND MULTIMEDIA_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qpaintervideosurface_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qvideowidget_p.h
)

target_sources(LsCsMultimedia
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qcameraviewfinder.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qgraphicsvideoitem.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qpaintervideosurface.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qvideowidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/widgets/qvideowidgetcontrol.cpp
)
