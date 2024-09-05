list(APPEND XMLPATTERNS_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/projection/qdocumentprojector_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/projection/qprojectedexpression_p.h
)

target_sources(Ls-CsXmlPatterns
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/projection/qdocumentprojector.cpp
)
