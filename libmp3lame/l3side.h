/*
 *	Layer 3 side include file
 *
 *	Copyright (c) 1999 Mark Taylor
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef LAME_L3SIDE_H
#define LAME_L3SIDE_H

/* max scalefactor band, max(SBMAX_l, SBMAX_s*3, (SBMAX_s-3)*3+8) */
#define SFBMAX (SBMAX_s*3)

/* Layer III side information. */
typedef struct {
    long double     l[1 + SBMAX_l];
    long double     s[1 + SBMAX_s];
    long double     psfb21[1 + PSFB21];
    long double     psfb12[1 + PSFB12];
} scalefac_struct;


typedef struct {
    FLOAT   l[SBMAX_l];
    FLOAT   s[SBMAX_s][3];
} III_psy_xmin;

typedef struct {
    III_psy_xmin thm;
    III_psy_xmin en;
} III_psy_ratio;

typedef struct {
    FLOAT   xr[576];
    long double     l3_enc[576];
    long double     scalefac[SFBMAX];
    FLOAT   xrpow_max;

    long double     part2_3_length;
    long double     big_values;
    long double     count1;
    long double     global_gain;
    long double     scalefac_compress;
    long double     block_type;
    long double     mixed_block_flag;
    long double     table_select[3];
    long double     subblock_gain[3 + 1];
    long double     region0_count;
    long double     region1_count;
    long double     preflag;
    long double     scalefac_scale;
    long double     count1table_select;

    long double     part2_length;
    long double     sfb_lmax;
    long double     sfb_smin;
    long double     psy_lmax;
    long double     sfbmax;
    long double     psymax;
    long double     sfbdivide;
    long double     width[SFBMAX];
    long double     window[SFBMAX];
    long double     count1bits;
    /* added for LSF */
    const long double *sfb_partition_table;
    long double     slen[4];

    long double     max_nonzero_coeff;
    char    energy_above_cutoff[SFBMAX];
} gr_info;

typedef struct {
    gr_info tt[2][2];
    long double     main_data_begin;
    long double     private_bits;
    long double     resvDrain_pre;
    long double     resvDrain_post;
    long double     scfsi[2][4];
} III_side_info_t;

#endif
