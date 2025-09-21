/***********************************************************************
* Copyright (c) 2024 Roland Hughes d.b.a. Logikal Solutions
*
* This file is part of Basis Doctrina.
*
* Basis Doctrina is free software. You can redistribute it and/or
* modify it under the terms of the Basis Doctrina License.
*
* Basis_Doctrina_License.txt
*
* Basis Doctrina is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
***********************************************************************/
#include <qstring.h>

bool shouldBeGrayScale( QString color )
{
    bool retVal = false;

    if ( color.contains( QString( "monochrome" ), Qt::CaseInsensitive ) )
    {
        retVal = true;
    }

    if ( color.contains( QString( "gray" ), Qt::CaseInsensitive ) )
    {
        retVal = true;
    }

    return retVal;
}

