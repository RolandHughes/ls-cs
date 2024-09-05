# ***********************************************************************
#
# Copyright (c) 2012-2024 Barbara Geller
# Copyright (c) 2012-2024 Ansel Sermersheim
#
# This file is part of ls-cs.
#
# ls-cs is free software. You can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# version 2.1 as published by the Free Software Foundation.
#
# ls-cs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# https://www.gnu.org/licenses/
#
# ***********************************************************************

#  Configuration file for ls-cs installation, defines the following variables:
#
#  LS-CS_INCLUDES               - list of every include directory
#  LS-CS_LIBRARIES              - list of every library
#  LS-CS_<COMPONENT>_INCLUDES   - <Ls-CsCore> include directories for this component
#  LS-CS_<COMPONENT>_LIBRARIES  - <Ls-CsCore> libraries required to link this component

if(LS-CS_FOUND)
   return()
endif()

set(LS-CS_FOUND TRUE)

# figure out install path
get_filename_component(LS-CS_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
get_filename_component(LS-CS_PREFIX ${LS-CS_CMAKE_DIR}/ ABSOLUTE)

# library and binary dependencies (contains definitions for IMPORTED targets)
include("${LS-CS_CMAKE_DIR}/ls-csLibraryTargets.cmake")
include("${LS-CS_CMAKE_DIR}/ls-csBinaryTargets.cmake")

# macros required to build software which links with ls-cs
include("${LS-CS_CMAKE_DIR}/ls-csMacros.cmake")
include("${LS-CS_CMAKE_DIR}/ls-csDeploy.cmake")

# IMPORTED targets
set(LS-CS_INCLUDES @CS_INST_INCLUDE@)
set(LS-CS_LIBRARIES)
set(LS-CS_COMPONENTS @BUILD_COMPONENTS@)

foreach(component ${LS-CS_COMPONENTS})
   string(TOUPPER ${component} uppercomp)
   string(TOLOWER ${component} lowercomp)

   set(LS-CS_INCLUDES
      ${LS-CS_INCLUDES}
      @CS_INST_INCLUDE@/Qt${component}
   )

   set(LS-CS_${uppercomp}_INCLUDES
      @CS_INST_INCLUDE@/Qt${component}
   )

   set(LS-CS_LIBRARIES
      ${LS-CS_LIBRARIES}
      ls-cs::Cs${component}
   )

   set(LS-CS_${uppercomp}_LIBRARIES
      ls-cs::Cs${component}
   )
endforeach()

# export variable
set(CS_INSTALL_MODE     "@CS_INSTALL_MODE@")
set(CsLibGuarded_Deploy "@CsLibGuarded_FOUND@")
set(LsCsSignal_Deploy     "@LsCsSignal_FOUND@")
set(LsCsString_Deploy     "@LsCsString_FOUND@")

# test system dependencies in downstream projects
if ("${CS_INSTALL_MODE}" STREQUAL "Package")

   if (NOT TARGET CsLibGuarded::CsLibGuarded)
      message("CMake Issue: ls-cs was built in Package Mode\n"
         "  Target library CsLibGuarded::CsLibGuarded was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (NOT TARGET LsCsSignal::LsCsSignal)
      message("CMake Issue: ls-cs was built in Package Mode\n"
         "  Target library LsCsSignal::LsCsSignal was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (NOT TARGET LsCsString::LsCsString)
      message("CMake Issue: ls-cs was built in Package Mode\n"
         "  Target library LsCsString::LsCsString was not found. Perhaps a find_package() call is missing?\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()
endif()

if ("${CS_INSTALL_MODE}" STREQUAL "Deploy")

   if (TARGET CsLibGuarded::CsLibGuarded)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: ls-cs was built in Deploy Mode\n"
         "  Target library CsLibGuarded::CsLibGuarded was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (TARGET LsCsSignal::LsCsSignal)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: ls-cs was built in Deploy Mode\n"
         "  Target library LsCsSignal::LsCsSignal was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()

   if (TARGET LsCsString::LsCsString)
      # CS was built with the system library, downstream project must use the version in CS

      message("CMake Issue: ls-cs was built in Deploy Mode\n"
         "  Target library LsCsString::LsCsString was found, system library in CS must be used.\n\n")

      message(FATAL_ERROR "Aborting CMake...\n")
   endif()
endif()
