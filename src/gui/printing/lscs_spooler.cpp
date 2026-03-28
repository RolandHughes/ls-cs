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

/*! \file lscs_spooler.h
 *  \brief Implementation for base class of spooler interface
 */

#include <lscs_spooler.h>

/*! \brief Explicit Constructor
 *
 * \param Enum value indicating type of spooler
 * \param Optional full path to file name. If this is provided will not spool to device.
 */
lscs_spooler::lscs_spooler( const LsCsSpoolerType spoolerType, const QString outputFile ) :
    m_spoolerType( spoolerType )
    , m_outputFile( outputFile )
{
}

/*! \brief Default Constructor
 */
lscs_spooler::lscs_spooler() :
    m_spoolerType( LsCsSpoolerType::None )
{
}

/*! \brief Obtains type of spooler
 *
 * \return Enum value indicating type of spooler
 */
LsCsSpoolerType lscs_spooler::spooler_type()
{
    return m_spoolerType;
}
