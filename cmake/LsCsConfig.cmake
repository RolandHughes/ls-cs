# ***********************************************************************
#
# Copyright (c) 2012-2024 Barbara Geller
# Copyright (c) 2012-2024 Ansel Sermersheim
#
# This file is part of LsCs.
#
# LsCs is free software. You can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# version 2.1 as published by the Free Software Foundation.
#
# LsCs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# https://www.gnu.org/licenses/
#
# ***********************************************************************

#  Configuration file for LsCs installation, defines the following variables:
#
#  LSCS_INCLUDES               - list of every include directory
#  LSCS_LIBRARIES              - list of every library
#  LSCS_<COMPONENT>_INCLUDES   - <LsCsCore> include directories for this component
#  LSCS_<COMPONENT>_LIBRARIES  - <LsCsCore> libraries required to link this component

if(LSCS_FOUND)
   return()
endif()

set(LSCS_FOUND TRUE)

# figure out install path
get_filename_component(LSCS_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
get_filename_component(LSCS_PREFIX ${LSCS_CMAKE_DIR}/ ABSOLUTE)

# library and binary dependencies (contains definitions for IMPORTED targets)
include("${LSCS_CMAKE_DIR}/LsCsLibraryTargets.cmake")
include("${LSCS_CMAKE_DIR}/LsCsBinaryTargets.cmake")

# macros required to build software which links with Cs-Cs
include("${LSCS_CMAKE_DIR}/LsCsMacros.cmake")
include("${LSCS_CMAKE_DIR}/LsCsDeploy.cmake")

# IMPORTED targets
set(LSCS_INCLUDES @LSCS_INST_INCLUDE@)
set(LSCS_LIBRARIES)
set(LSCS_COMPONENTS @BUILD_COMPONENTS@)

foreach(component ${LSCS_COMPONENTS})
   string(TOUPPER ${component} uppercomp)
   string(TOLOWER ${component} lowercomp)

   set(LSCS_INCLUDES
      ${LSCS_INCLUDES}
      @LSCS_INST_INCLUDE@/Qt${component}
   )

   set(LSCS_${uppercomp}_INCLUDES
      @LSCS_INST_INCLUDE@/Qt${component}
   )

   set(LSCS_LIBRARIES
      ${LSCS_LIBRARIES}
      LsCs::Cs${component}
   )

   set(LSCS_${uppercomp}_LIBRARIES
      LsCs::Cs${component}
   )
endforeach()

# export variable
set(LSCS_INSTALL_MODE     "@LSCS_INSTALL_MODE@")
set(LsCsLibGuarded_Deploy "@LsCsLibGuarded_FOUND@")
set(LsCsSignal_Deploy     "@LsCsSignal_FOUND@")
set(LsCsString_Deploy     "@LsCsString_FOUND@")

# test system dependencies in downstream projects
if ("${LSCS_INSTALL_MODE}" STREQUAL "Package")

   if (NOT TARGET LsCsLibGuarded::LsCsLibGuarded)
      message("CMake Issue: LsCs was built in Package Mode\n"
         "  Target library LsCsLibGuarded::LsCsLibGuarded was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (NOT TARGET LsCsSignal::LsCsSignal)
      message("CMake Issue: LsCs was built in Package Mode\n"
         "  Target library LsCsSignal::LsCsSignal was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (NOT TARGET LsCsString::LsCsString)
      message("CMake Issue: LsCs was built in Package Mode\n"
         "  Target library LsCsString::LsCsString was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()
endif()

if ("${LSCS_INSTALL_MODE}" STREQUAL "Deploy")

   if (TARGET LsCsLibGuarded::LsCsLibGuarded)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: LsCs was built in Deploy Mode\n"
         "  Target library LsCsLibGuarded::LsCsLibGuarded was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (TARGET LsCsSignal::LsCsSignal)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: LsCs was built in Deploy Mode\n"
         "  Target library LsCsSignal::LsCsSignal was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (TARGET LsCsString::LsCsString)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: LsCs was built in Deploy Mode\n"
         "  Target library LsCsString::LsCsString was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()
endif()
