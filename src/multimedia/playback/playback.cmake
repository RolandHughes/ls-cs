list(APPEND MULTIMEDIA_PUBLIC_INCLUDES
   QMediaContent
   QMediaPlayer
   QMediaPlayList
   QMediaResource
)

list(APPEND MULTIMEDIA_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediacontent.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplayer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylist.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaresource.h
)

list(APPEND MULTIMEDIA_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylist_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistprovider_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistioplugin_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistnavigator_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmedianetworkplaylistprovider_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/playlistfileparser_p.h
)

target_sources(LsCsMultimedia
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmedianetworkplaylistprovider.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediacontent.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplayer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylist.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistioplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistnavigator.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaplaylistprovider.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/qmediaresource.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/playback/playlistfileparser.cpp
)


