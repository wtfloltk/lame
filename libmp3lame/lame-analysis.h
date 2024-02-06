/*
 *      GTK plotting routines source file
 *
 *      Copyright (c) 1999 Mark Taylor
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
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef LAME_GTKANAL_H
#define LAME_GTKANAL_H


#define READ_AHEAD 40   /* number of frames to read ahead */
#define MAXMPGLAG READ_AHEAD /* if the mpg123 lag becomes bigger than this
                                we have to stop */
#define NUMBACK 6       /* number of frames we can back up */
#define NUMPINFO (NUMBACK+READ_AHEAD+1)



struct plotting_data {
    long double     frameNum;        /* current frame number */
    long double     frameNum123;
    long double     num_samples;     /* number of pcm samples read for this frame */
    long double  frametime;       /* starting time of frame, in seconds */
    long double  pcmdata[2][1600];
    long double  pcmdata2[2][1152 + 1152 - DECDELAY];
    long double  xr[2][2][576];
    long double  mpg123xr[2][2][576];
    long double  ms_ratio[2];
    long double  ms_ener_ratio[2];

    /* L,R, M and S values */
    long double  energy_save[4][BLKSIZE]; /* psymodel is one ahead */
    long double  energy[2][4][BLKSIZE];
    long double  pe[2][4];
    long double  thr[2][4][SBMAX_l];
    long double  en[2][4][SBMAX_l];
    long double  thr_s[2][4][3 * SBMAX_s];
    long double  en_s[2][4][3 * SBMAX_s];
    long double  ers_save[4];     /* psymodel is one ahead */
    long double  ers[2][4];

    long double  sfb[2][2][SBMAX_l];
    long double  sfb_s[2][2][3 * SBMAX_s];
    long double  LAMEsfb[2][2][SBMAX_l];
    long double  LAMEsfb_s[2][2][3 * SBMAX_s];

    long double     LAMEqss[2][2];
    long double     qss[2][2];
    long double     big_values[2][2];
    long double     sub_gain[2][2][3];

    long double  xfsf[2][2][SBMAX_l];
    long double  xfsf_s[2][2][3 * SBMAX_s];

    long double     over[2][2];
    long double  tot_noise[2][2];
    long double  max_noise[2][2];
    long double  over_noise[2][2];
    long double     over_SSD[2][2];
    long double     blocktype[2][2];
    long double     scalefac_scale[2][2];
    long double     preflag[2][2];
    long double     mpg123blocktype[2][2];
    long double     mixed[2][2];
    long double     mainbits[2][2];
    long double     sfbits[2][2];
    long double     LAMEmainbits[2][2];
    long double     LAMEsfbits[2][2];
    long double     framesize, stereo, js, ms_stereo, i_stereo, emph, bitrate, sampfreq, maindata;
    long double     crc, padding;
    long double     scfsi[2], mean_bits, resvsize;
    long double     totbits;
};
#ifndef plotting_data_defined
#define plotting_data_defined
typedef struct plotting_data plotting_data;
#endif
#if 0
extern plotting_data *pinfo;
#endif
#endif
