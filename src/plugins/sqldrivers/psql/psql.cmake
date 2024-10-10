list(APPEND SQL_PUBLIC_INCLUDES
   QPSQLDriver
   QPSQLResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/qsql_psql.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/qpsqldriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/qpsqlresult.h
)

if(WITH_PSQL_PLUGIN AND PostgreSQL_FOUND)

   add_library(LsCsSqlPsql MODULE "")
   add_library(LsCs::CsSqlPsql ALIAS LsCsSqlPsql)

   set_target_properties(LsCsSqlPsql PROPERTIES OUTPUT_NAME LsCsSqlPsql${BUILD_ABI} PREFIX "")

   include_directories(${PostgreSQL_INCLUDE_DIRS})

   target_sources(LsCsSqlPsql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/qsql_psql.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/main.cpp
   )

   target_link_libraries(LsCsSqlPsql
      LsCsCore
      LsCsSql
      ${PostgreSQL_LIBRARY}
   )

   target_compile_definitions(LsCsSqlPsql
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsSqlPsql DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlPsql DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()
