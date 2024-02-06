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
    real     l[1 + SBMAX_l];
    real     s[1 + SBMAX_s];
    real     psfb21[1 + PSFB21];
    real     psfb12[1 + PSFB12];
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
    real     l3_enc[576];
    real     scalefac[SFBMAX];
    FLOAT   xrpow_max;

    real     part2_3_length;
    real     big_values;
    real     count1;
    real     global_gain;
    real     scalefac_compress;
    real     block_type;
    real     mixed_block_flag;
    real     table_select[3];
    real     subblock_gain[3 + 1];
    real     region0_count;
    real     region1_count;
    real     preflag;
    real     scalefac_scale;
    real     count1table_select;

    real     part2_length;
    real     sfb_lmax;
    real     sfb_smin;
    real     psy_lmax;
    real     sfbmax;
    real     psymax;
    real     sfbdivide;
    real     width[SFBMAX];
    real     window[SFBMAX];
    real     count1bits;
    /* added for LSF */
    const real *sfb_partition_table;
    real     slen[4];

    real     max_nonzero_coeff;
    char    energy_above_cutoff[SFBMAX];
} gr_info;

typedef struct {
    gr_info tt[2][2];
    real     main_data_begin;
    real     private_bits;
    real     resvDrain_pre;
    real     resvDrain_post;
    real     scfsi[2][4];
} III_side_info_t;

#endif
