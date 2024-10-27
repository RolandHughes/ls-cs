list(APPEND SQL_PUBLIC_INCLUDES
   QMYSQLDriver
   QMYSQLResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/qsql_mysql.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/qmysqldriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/qmysqlresult.h
)

if(WITH_MYSQL_PLUGIN AND MySQL_FOUND)

   add_library(LsCsSqlMySql MODULE "")
   add_library(LsCs::LsCsSqlMySql ALIAS LsCsSqlMySql)

   set_target_properties(LsCsSqlMySql PROPERTIES OUTPUT_NAME LsCsSqlMySql${BUILD_ABI} PREFIX "")

   include_directories(${MySQL_INCLUDE_DIRS})

   target_sources(LsCsSqlMySql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/qsql_mysql.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/main.cpp
    )

   target_link_libraries(LsCsSqlMySql
      LsCsCore
      LsCsSql
      ${MySQL_LIBRARIES}
   )

   if(ZLIB_FOUND)
      target_link_libraries(LsCsSqlMySql
         ${ZLIB_LIBRARIES}
      )
   endif()

   target_compile_definitions(LsCsSqlMySql
      PRIVATE
      -DIN_TRUE
      -DLSCS_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsSqlMySql DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlMySql DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()
