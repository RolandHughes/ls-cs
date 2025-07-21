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
#ifndef LSCS_NO_PRINTER

#include <qtextstream.h>

#include <bdsinglefilejob.h>

BdSingleFileJob::BdSingleFileJob() :
    validJob( false )
    , destinationIsFile( false )
    , spoolerType( BdSpoolerType::None )
{
}

QString BdSingleFileJob::toString()
{
    QString retVal;

    QTextStream out( &retVal );

    out << "validJob:           " << validJob << "\n";
    out << "destinationName:    " << destinationName << "\n";
    out << "destinationIsFile:  " << destinationIsFile << "\n";

    out << "spoolerType:        ";

    switch ( spoolerType )
    {
        case BdSpoolerType::None:
            out << "none";
            break;

        case BdSpoolerType::Text:
            out << "Text";
            break;

        case BdSpoolerType::Raw:
            out << "Raw";
            break;

        case BdSpoolerType::Pdf:
            out << "Pdf";
            break;

        case BdSpoolerType::Postscript:
            out << "Postscript";
            break;
    }

    out << "\n";

    out << "copies:             " << copies << "\n";
    out << "paperSource:        " << paperSource << "\n";
    out << "paper:              " << paper << "\n";
    out << "duplex:             " << duplex << "\n";
    out << "numberUp:           " << numberUp << "\n";
    out << "scaling:            " << scaling << "\n";
    out << "orientation:        " << orientation << "\n";
    out << "printQuality:       " << printQuality << "\n";

    out.flush();

    return retVal;
}

#endif   // LSCS_NO_PRINTER
