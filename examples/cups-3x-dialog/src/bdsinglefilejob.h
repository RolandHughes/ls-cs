/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2025 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs.
;;
;; Ls-Cs is free software. You can redistribute it and/or
;; modify it under the terms the Basis Doctrina License found in
;; Basis_Doctrina_License.txt
;;
;; Ls-Cs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
#ifndef BDSINGLEFILEJOB_H
#define BDSINGLEFILEJOB_H

#ifndef LSCS_NO_PRINTER
#include <qstring.h>

#include <bdspooler.h>


class BdSingleFileJob
{
public:
    BdSingleFileJob();

    bool            validJob;
    QString         destinationName;
    bool            destinationIsFile;
    BdSpoolerType   spoolerType;
    int             copies;
    QString         paperSource;
    QString         paper;
    QString         orientation;

    QString         duplex;
    QString         numberUp;
    QString         scaling;

};

#endif   // LSCS_NO_PRINTER
#endif   // BDSINGLEFILEJOB_H
