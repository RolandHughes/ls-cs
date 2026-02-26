/***********************************************************************
*
* Copyright (c) 2024 Roland Hughes  DBA  Logikal Solutions
*
* This file is part of LsCs.
*
* LsCs is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* LsCs is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/
#include <qstring.h>

// TODO:: add doxygen comment.
#ifdef Q_OS_UNIX
QString lscs_tildeExpansion( const QString &path, bool *expanded = nullptr );
#endif
