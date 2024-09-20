list(APPEND SQL_PUBLIC_INCLUDES
   QODBCDriver
   QODBCResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/qsql_odbc.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/qodbcdriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/qodbcresult.h
)

if (WITH_ODBC_PLUGIN AND ODBC_FOUND)
   add_library(LsCsSqlOdbc MODULE "")
   add_library(LsCs::LsCsSqlOdbc ALIAS LsCsSqlOdbc)

   set_target_properties(LsCsSqlOdbc PROPERTIES OUTPUT_NAME LsCsSqlOdbc${BUILD_ABI} PREFIX "")

   include_directories(${ODBC_INCLUDE_DIRS})

   target_sources(LsCsSqlOdbc
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/qsql_odbc.cpp
   )

   target_link_libraries(LsCsSqlOdbc
      LsCsCore
      LsCsSql
      ${ODBC_LIBRARY}
   )

   target_compile_definitions(LsCsSqlOdbc
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsSqlOdbc DESTINATION ${CMAKE_INSTALL_LIBDIR}/LsCs/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlOdbc DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()

   if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD)")
      target_compile_definitions(LsCsSqlOdbc
         PRIVATE
         -DUNICODE
      )

   elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
      target_compile_definitions(LsCsSqlOdbc
         PRIVATE
         -DUNICODE
      )

   endif()
endif()
