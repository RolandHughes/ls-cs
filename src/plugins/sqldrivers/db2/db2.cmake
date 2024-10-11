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
   add_library(Ls-Cs::Ls-CsSqlDb2 ALIAS Ls-CsSqlDb2)

   set_target_properties(Ls-CsSqlDb2 PROPERTIES OUTPUT_NAME Ls-CsSqlDb2${BUILD_ABI} PREFIX "")

   include_directories(${DB2_INCLUDE_DIRS})

   target_sources(Ls-CsSqlDb2
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/main.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/db2/qsql_db2.cpp
   )

   target_link_libraries(Ls-CsSqlDb2
      Ls-CsCore
      Ls-CsSql
      ${DB2_LIBRARY}
   )

   target_compile_definitions(Ls-CsSqlDb2
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBAIN)
      install(TARGETS Ls-CsSqlDb2 DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlDb2 DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

