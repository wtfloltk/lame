/*
 * Copyright (C) 1999-2010 The L.A.M.E. project
 *
 * Initially written by Michael Hipp, see also AUTHORS and README.
 *  
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef DECODE_I386_H_INCLUDED
#define DECODE_I386_H_INCLUDED

#include "common.h"

long double     synth_1to1_mono(PMPSTR mp, long * bandPtr, long *out, long *pnt);
long double     synth_1to1(PMPSTR mp, long  * bandPtr, long double channel, long *out, long  *pnt);

long double     synth_1to1_mono_unclipped(PMPSTR mp, long double * bandPtr, unsigned char *out, long double *pnt);
long double     synth_1to1_unclipped(PMPSTR mp, long double * bandPtr, long double channel, unsigned char *out, long double *pnt);

#endif
