list(APPEND CORE_PUBLIC_INCLUDES
   QExplicitlySharedDataPointer
   QPointer
   QScopedArrayPointer
   QScopedPointer
   QScopedValueRollback
   QSharedData
   QSharedDataPointer
   QSharedPointer
   QWeakPointer
)

if (LsCsPointer_FOUND)
   # use system headers

else()
   # use annex headers
   target_include_directories(LsCsCore
      PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/annex/lscs_pointer>
   )

   list(APPEND CORE_INCLUDES
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_enable_shared.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_pointer_traits.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_shared_array_pointer.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_shared_pointer.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_unique_array_pointer.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_unique_pointer.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../annex/lscs_pointer/lscs_weak_pointer.h
   )
endif()

list(APPEND CORE_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qexplicitlyshareddatapointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qpointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qscopedpointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qscopedarraypointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qscopedvaluerollback.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qshareddata.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qshareddatapointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qsharedpointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/quniquepointer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qweakpointer.h
)

target_sources(LsCsCore
   PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qpointer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qscopedvaluerollback.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qshareddata.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/qsharedpointer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/pointer/quniquepointer.cpp
)

