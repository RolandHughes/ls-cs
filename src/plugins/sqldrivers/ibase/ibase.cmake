list(APPEND SQL_PUBLIC_INCLUDES
   QIBaseDriver
   QIBaseResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/qsql_ibase.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/qibasedriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/qibaseresult.h
)

# if(WITH_IBASE_PLUGIN AND IBASE_FOUND), unsupported at this time
if (FALSE)

   add_library(Ls-CsSqlIBase MODULE "")
   add_library(Ls-Cs::Ls-CsSqlIBase  ALIAS Ls-CsSqlIBase )

   set_target_properties(Ls-CsSqlIBase  PROPERTIES OUTPUT_NAME Ls-CsSqlIBase ${BUILD_ABI} PREFIX "")

   include_directories(${IBase_INCLUDE_DIRS})

   target_sources(Ls-CsSqlPsql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/qsql_ibase.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/main.cpp
   )

   target_link_libraries(Ls-CsSqlIBase
      Ls-CsCore
      Ls-CsSql
      ${IBase_LIBRARY}
   )

   target_compile_definitions(Ls-CsSqlIBase
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsSqlIBase  DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlIBase  DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()

