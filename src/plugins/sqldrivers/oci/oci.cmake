list(APPEND SQL_PUBLIC_INCLUDES
   QOCIDriver
   QOCIResult
)

list(APPEND SQL_INCLUDES
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qsql_oci.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qocidriver.h
   ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qociresult.h
)

# if(WITH_OCI_PLUGIN AND OCI_FOUND), unsupported at this time
if (FALSE)

   add_library(Ls-CsSqlOci MODULE "")
   add_library(Ls-Cs::Ls-CsSqlOci ALIAS Ls-CsSqlOci)

   set_target_properties(Ls-CsSqlOci PROPERTIES OUTPUT_NAME Ls-CsSqlOci${BUILD_ABI} PREFIX "")

   include_directories(${OCI_INCLUDE_DIRS})

   target_sources(Ls-CsSqlOci
      PRIVATE
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/qsql_oci.cpp
      ${CMAKE_SOURCE_DIR}/src/plugins/sqldrivers/oci/main.cpp
   )

   target_link_libraries(Ls-CsSqlOci
      Ls-CsCore
      Ls-CsSql
      ${OCI_LIBRARY}
   )

   target_compile_definitions(Ls-CsSqlOci
      PRIVATE
      -DIN_TRUE
      -DQT_PLUGIN
   )

   if(BUILDING_RPM OR BUILDING_DEBIAN)
      install(TARGETS Ls-CsSqlOci DESTINATION ${CMAKE_INSTALL_LIBDIR}/ls-cs/plugins/sqldrivers)
   else()
      install(TARGETS Ls-CsSqlOci DESTINATION ${CMAKE_INSTALL_LIBDIR})
   endif()
endif()
