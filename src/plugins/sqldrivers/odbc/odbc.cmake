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
   add_library(Ls-CsSqlOdbc MODULE "")
   add_library(Ls-Cs::Ls-CsSqlOdbc ALIAS Ls-CsSqlOdbc)

   set_target_properties(Ls-CsSqlOdbc PROPERTIES OUTPUT_NAME Ls-CsSqlOdbc${BUILD_ABI} PREFIX "")

   include_directories(${ODBC_INCLUDE_DIRS})

   target_sources(Ls-CsSqlOdbc
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/odbc/qsql_odbc.cpp
   )

   target_link_libraries(Ls-CsSqlOdbc
      Ls-CsCore
      Ls-CsSql
      ${ODBC_LIBRARY}
   )

   target_compile_definitions(Ls-CsSqlOdbc
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsSqlOdbc DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlOdbc DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()

   if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD)")
      target_compile_definitions(Ls-CsSqlOdbc
         PRIVATE
         -DUNICODE
      )

   elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
      target_compile_definitions(Ls-CsSqlOdbc
         PRIVATE
         -DUNICODE
      )

   endif()
endif()
