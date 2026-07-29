/*! \file lscs_single_file_job.h
 *
 *  \brief Header file for class to hold all job information
 *
 *  \details Every print or file spooling job will have a set of
 *        parameters for spooler type, destination device or file, etc.
 *        When destination is a printer there will be paper, quality, duplex
 *        parameters required as well.
 *
 *  \author Roland Hughes
 *  \copyright Copyright © 2025-2026 Roland Hughes d.b.a. Logikal Solutions All rights reserved.
 *  \license This project is released under LGPL 2.1
 *
 *;;;;
 *
 * This file is part of Ls-Cs, also known as LsCs
 *
 * Ls-Cs is free software. You can redistribute it and/or
 * modify it under the terms the Basis Doctrina License found in
 * Basis_Doctrina_License.txt
 *
 * Ls-Cs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef LSCSSINGLEFILEJOB_H
#define LSCSSINGLEFILEJOB_H

#ifndef LSCS_NO_PRINTER
#include <qstring.h>

#include <lscs_spooler.h>


class lscs_single_file_job
{
public:
    lscs_single_file_job();

    bool            validJob;

    //  capability flags
    //  destination either doesn't support the capability
    //  or user entered values negated them.
    //
    bool            useCollateValue;
    bool            usePrintQualityValue;
    bool            usePaperSourceValue;
    bool            useColorValue;
    bool            useOrientationValue;
    bool            useScalingValue;
    bool            useCopiesValue;
    bool            useNumberUpValue;
    bool            useDuplexValue;

    QString         destinationName;
    bool            destinationIsFile;
    LsCsSpoolerType   spoolerType;
    int             copies;
    QString         paperSource;
    QString         paper;
    QString         duplex;
    QString         numberUp;
    QString         scaling;
    QString         orientation;
    QString         printQuality;

    QString         to_string();
};

#endif   // LSCS_NO_PRINTER
#endif   // LSCSSINGLEFILEJOB_H
