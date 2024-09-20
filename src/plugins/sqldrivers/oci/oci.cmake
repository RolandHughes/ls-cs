list(APPEND SQL_PUBLIC_INCLUDES
   QOCIDriver
   QOCIResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qsql_oci.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qocidriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qociresult.h
)

# if(WITH_OCI_PLUGIN AND OCI_FOUND), unsupported at this time
if (FALSE)

   add_library(LsCsSqlOci MODULE "")
   add_library(LsCs::LsCsSqlOci ALIAS LsCsSqlOci)

   set_target_properties(LsCsSqlOci PROPERTIES OUTPUT_NAME LsCsSqlOci${BUILD_ABI} PREFIX "")

   include_directories(${OCI_INCLUDE_DIRS})

   target_sources(LsCsSqlOci
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qsql_oci.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/main.cpp
   )

   target_link_libraries(LsCsSqlOci
      LsCsCore
      LsCsSql
      ${OCI_LIBRARY}
   )

   target_compile_definitions(LsCsSqlOci
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsSqlOci DESTINATION ${CMAKE_INSTALL_LIBDIR}/LsCs/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlOci DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()
