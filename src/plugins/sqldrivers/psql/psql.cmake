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

   add_library(Ls-CsSqlPsql MODULE "")
   add_library(Ls-Cs::CsSqlPsql ALIAS Ls-CsSqlPsql)

   set_target_properties(Ls-CsSqlPsql PROPERTIES OUTPUT_NAME Ls-CsSqlPsql${BUILD_ABI} PREFIX "")

   include_directories(${PostgreSQL_INCLUDE_DIRS})

   target_sources(Ls-CsSqlPsql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/qsql_psql.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/psql/main.cpp
   )

   target_link_libraries(Ls-CsSqlPsql
      Ls-CsCore
      Ls-CsSql
      ${PostgreSQL_LIBRARY}
   )

   target_compile_definitions(Ls-CsSqlPsql
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsSqlPsql DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlPsql DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()
