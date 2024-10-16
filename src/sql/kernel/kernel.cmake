list(APPEND SQL_PUBLIC_INCLUDES
   QSqlDatabase
   QSqlDriver
   QSqlDriverPlugin
   QSqlError
   QSqlField
   QSqlIndex
   QSqlQuery
   QSqlRecord
   QSqlResult
   QSqlDriverCreator
   QSqlDriverCreatorBase
   QSqlDriverFactoryInterface
   QtSql
)

list(APPEND SQL_PRIVATE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlnulldriver_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlcachedresult_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriver_p.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlresult_p.h
)

list(APPEND SQL_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsql.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldatabase.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriver.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriverplugin.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlerror.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlfield.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlindex.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlquery.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlrecord.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlresult.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldrivercreator.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldrivercreatorbase.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriverfactoryinterface.h
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qtsql.h
)

target_sources(LsCsSql
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlquery.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldatabase.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlfield.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlrecord.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriver.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqldriverplugin.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlerror.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlresult.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlindex.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsqlcachedresult.cpp
)
