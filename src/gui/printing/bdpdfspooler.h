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
#ifndef BDPDFSPOOLER_H
#define BDPDFSPOOLER_H

#ifndef LSCS_NO_PRINTER

#include <bdspooler.h>

// TODO:: actually create this
class Q_GUI_EXPORT BdPdfSpooler : public BdSpooler
{
    LSCS_OBJECT( BdPdfSpooler )
};

#endif // LSCS_NO_PRINTER

#endif // BDPDFSPOOLER_H
