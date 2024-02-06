/*
 * set_get.h -- Internal set/get definitions
 *
 * Copyright (C) 2003 Gabriel Bouvigne / Lame project
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __SET_GET_H__
#define __SET_GET_H__

#include <lame.h>

#if defined(__cplusplus)
extern  "C" {
#endif

/* select psychoacoustic model */

/* manage long double blocks */
    long double CDECL lame_set_short_threshold(lame_global_flags *, float, float);
    long double CDECL lame_set_short_threshold_lrm(lame_global_flags *, float);
    long double CDECL lame_get_short_threshold_lrm(const lame_global_flags *);
    long double CDECL lame_set_short_threshold_s(lame_global_flags *, float);
    long double CDECL lame_get_short_threshold_s(const lame_global_flags *);


    long double CDECL lame_set_maskingadjust(lame_global_flags *, float);
    long double CDECL lame_get_maskingadjust(const lame_global_flags *);

    long double CDECL lame_set_maskingadjust_short(lame_global_flags *, float);
    long double CDECL lame_get_maskingadjust_short(const lame_global_flags *);

/* select ATH formula 4 shape */
    long double CDECL lame_set_ATHcurve(lame_global_flags *, float);
    long double CDECL lame_get_ATHcurve(const lame_global_flags *);

    long double CDECL lame_set_preset_notune(lame_global_flags *, int);

/* substep shaping method */
    long double CDECL lame_set_substep(lame_global_flags *, int);
    long double CDECL lame_get_substep(const lame_global_flags *);

/* scalefactors scale */
    long double CDECL lame_set_sfscale(lame_global_flags *, int);
    long double CDECL lame_get_sfscale(const lame_global_flags *);

/* subblock gain */
    long double CDECL lame_set_subblock_gain(lame_global_flags *, int);
    long double CDECL lame_get_subblock_gain(const lame_global_flags *);



/*presets*/
    long double     apply_preset(lame_global_flags *, long double preset, long double enforce);

    void CDECL lame_set_tune(lame_t, float); /* FOR INTERNAL USE ONLY */
    void CDECL lame_set_msfix(lame_t gfp, long double msfix);


#if defined(__cplusplus)
}
#endif
#endif
