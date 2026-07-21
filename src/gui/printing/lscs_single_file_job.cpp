/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2026 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs, also known as LsCs
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

#include <lscs_single_file_job.h>

lscs_single_file_job::lscs_single_file_job() :
    validJob( false )
    , useCollateValue( false )
    , usePrintQualityValue( false )
    , usePaperSourceValue( false )
    , useColorValue( false )
    , useOrientationValue( false )
    , useScalingValue( false )
    , useCopiesValue( false )
    , useNumberUpValue( false )
    , useDuplexValue( false )
    , destinationIsFile( false )
    , spoolerType( LsCsSpoolerType::None )
    , copies( 1 )
{
}

QString lscs_single_file_job::to_string()
{
    QString retVal;

    QTextStream out( &retVal );

    out << "validJob:           " << validJob << "\n";
    out << "destinationName:    " << destinationName << "\n";
    out << "destinationIsFile:  " << destinationIsFile << "\n";

    out << "spoolerType:        ";

    switch ( spoolerType )
    {
        case LsCsSpoolerType::None:
            out << "none";
            break;

        case LsCsSpoolerType::Text:
            out << "Text";
            break;

        case LsCsSpoolerType::Raw:
            out << "Raw";
            break;

        case LsCsSpoolerType::Pdf:
            out << "Pdf";
            break;

        case LsCsSpoolerType::Postscript:
            out << "Postscript";
            break;
    }

    out << "\n";

    out << "copies:               " << copies << "\n";
    out << "paperSource:          " << paperSource << "\n";
    out << "paper:                " << paper << "\n";
    out << "duplex:               " << duplex << "\n";
    out << "numberUp:             " << numberUp << "\n";
    out << "scaling:              " << scaling << "\n";
    out << "orientation:          " << orientation << "\n";
    out << "printQuality:         " << printQuality << "\n";

    out << "useCollateValue:      " << useCollateValue << "\n";
    out << "usePrintQualityValue: " << usePrintQualityValue << "\n";
    out << "usePaperSourceValue:  " << usePaperSourceValue << "\n";
    out << "useColorValue:        " << useColorValue << "\n";
    out << "useOrientationValue:  " << useOrientationValue << "\n";
    out << "useScalingValue:      " << useScalingValue << "\n";
    out << "useCopiesValue:       " << useCopiesValue << "\n";
    out << "useNumberUpValue:     " << useNumberUpValue << "\n";
    out << "useDuplexValue:       " << useDuplexValue << "\n";


    out.flush();

    return retVal;
}

#endif   // LSCS_NO_PRINTER
