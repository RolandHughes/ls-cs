list(APPEND SQL_PUBLIC_INCLUDES
   QDB2Driver
   QDB2Result
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/qsql_db2.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/qdb2driver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/qdb2result.h
)

# if(WITH_DB2_PLUGIN AND DB2_FOUND), unsupported at this time
if (FALSE)

   add_library(CsSqlDb2 MODULE "")
   add_library(LsCs::LsCsSqlDb2 ALIAS LsCsSqlDb2)

   set_target_properties(LsCsSqlDb2 PROPERTIES
      VERSION ${BUILD_ABI}
      SOVERSION ${BUILD_MAJOR}
   )
     

   include_directories(${DB2_INCLUDE_DIRS})

   target_sources(LsCsSqlDb2
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/qsql_db2.cpp
   )

   target_link_libraries(LsCsSqlDb2
      LsCsCore
      LsCsSql
      ${DB2_LIBRARY}
   )

   target_compile_definitions(LsCsSqlDb2
      PRIVATE
      -DIN_TRUE
      -DLSCS_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBAIN)
      install(TARGETS LsCsSqlDb2 DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlDb2 DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()

