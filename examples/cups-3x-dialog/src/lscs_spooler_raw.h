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
#ifndef LSCSSPOOLERRAW_H
#define LSCSSPOOLERRAW_H

#ifndef LSCS_NO_PRINTER

#include <lscs_spooler.h>

// TODO:: actually create this
class Q_GUI_EXPORT lscs_spooler_raw : public lscs_spooler
{
    LSCS_OBJECT( lscs_spooler )
};

#endif // LSCS_NO_PRINTER

#endif // LSCSSPOOLERRAW_H
