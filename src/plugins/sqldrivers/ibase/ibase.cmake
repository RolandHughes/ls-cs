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

   add_library(LsCsSqlIBase MODULE "")
   add_library(LsCs::LsCsSqlIBase  ALIAS LsCsSqlIBase )

   set_target_properties(LsCsSqlIBase  PROPERTIES
     PREFIX ""
     VERSION ${BUILD_ABI}
     SOVERSION ${BUILD_MAJOR}
   )

   include_directories(${IBase_INCLUDE_DIRS})

   target_sources(LsCsSqlPsql
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/qsql_ibase.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/ibase/main.cpp
   )

   target_link_libraries(LsCsSqlIBase
      LsCsCore
      LsCsSql
      ${IBase_LIBRARY}
   )

   target_compile_definitions(LsCsSqlIBase
      PRIVATE
      -DIN_TRUE
      -DLSCS_PLUGIN
   )

#   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS LsCsSqlIBase  DESTINATION ${CMAKE_INSTALL_LIBDIR}/plugins/sqldrivers)
#   else()
#      install(TARGETS LsCsSqlIBase  DESTINATION ${CMAKE_INSTALL_LIBDIR})
#   endif()
endif()

