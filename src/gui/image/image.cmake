list(APPEND GUI_PUBLIC_INCLUDES
   QBitmap
   QIcon
   QIconEngine
   QIconEnginePlugin
   QIconSet
   QImage
   QImageIOHandler
   QImageIOHandlerFactoryInterface
   QImageIOPlugin
   QImageReader
   QImageWriter
   QMovie
   QPicture
   QPictureFormatInterface
   QPictureFormatPlugin
   QPictureIO
   QPixmap
   QPixmapCache
)

list(APPEND GUI_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qbitmap.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qicon.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconengine.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconengineplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconset.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimageiohandler.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimageiohandlerfactoryinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimageioplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagereader.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagewriter.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qmovie.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpicture.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpictureformatinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpictureformatplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpictureio.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmapcache.h
)

list(APPEND GUI_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qbmphandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qicohandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qicon_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconloader_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagepixmapcleanuphooks_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qjpeghandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qnativeimage_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qgifhandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpaintengine_pic_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpicture_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap_blitter_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap_raster_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmapcache_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmapfilter_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpnghandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qppmhandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qtiffhandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qxbmhandler_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qxpmhandler_p.h
)

target_sources(LsCsGui
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qbmphandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qbitmap.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qicon.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconloader.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage_sse2.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage_ssse3.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimageiohandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagereader.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagewriter.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpaintengine_pic.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpicture.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpictureformatplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmapcache.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmapfilter.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconengine.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qiconengineplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qmovie.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap_raster.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap_blitter.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qnativeimage.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimagepixmapcleanuphooks.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qgifhandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qicohandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qpnghandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qjpeghandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qxpmhandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qxbmhandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qppmhandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qtiffhandler.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage_conversions.cpp

   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_callback_xs.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_chunk_descr.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_chunk_io.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_chunk_prc.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_chunk_xs.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_cms.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_display.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_dither.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_error.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_filter.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_hlapi.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_jpeg.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_object_prc.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_pixels.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_prop_xs.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_read.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_trace.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_write.c
   ${CMAKE_SOURCE_DIR}/src/3rdparty/libmng/libmng_zlib.c
)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/image/qimage_neon.cpp
   )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   target_sources(LsCsGui
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/image/qpixmap_win.cpp
   )

endif()


