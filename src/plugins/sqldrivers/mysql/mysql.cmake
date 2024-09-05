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

   add_library(Ls-CsSqlMySql MODULE "")
   add_library(Ls-Cs::Ls-CsSqlMySql ALIAS Ls-CsSqlMySql)

   set_target_properties(Ls-CsSqlMySql PROPERTIES OUTPUT_NAME Ls-CsSqlMySql${BUILD_ABI} PREFIX "")

   include_directories(${MySQL_INCLUDE_DIRS})

   target_sources(Ls-CsSqlMySql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/qsql_mysql.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/mysql/main.cpp
    )

   target_link_libraries(Ls-CsSqlMySql
      Ls-CsCore
      Ls-CsSql
      ${MySQL_LIBRARIES}
   )

   if(ZLIB_FOUND)
      target_link_libraries(Ls-CsSqlMySql
         ${ZLIB_LIBRARIES}
      )
   endif()

   target_compile_definitions(Ls-CsSqlMySql
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsSqlMySql DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlMySql DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()
