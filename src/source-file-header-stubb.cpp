/*! \file lscs_single_file_job_dialog.cpp
 *
 *  \brief Allows user to submit a single file job to print queue or file
 *
 *  \details Handles all job values including CUPS security (when needed)
 *        With CUPS 3.x and even later 2.x it is no longer acceptable to
 *        open a "device" and lock it while you spew to it a page at a time.
 *        Now we generate a temporary file via a spooler and send the entire
 *        single file job to the output device.
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
