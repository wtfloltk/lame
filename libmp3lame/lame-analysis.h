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
    real     frameNum;        /* current frame number */
    real     frameNum123;
    real     num_samples;     /* number of pcm samples read for this frame */
    real  frametime;       /* starting time of frame, in seconds */
    real  pcmdata[2][1600];
    real  pcmdata2[2][1152 + 1152 - DECDELAY];
    real  xr[2][2][576];
    real  mpg123xr[2][2][576];
    real  ms_ratio[2];
    real  ms_ener_ratio[2];

    /* L,R, M and S values */
    real  energy_save[4][BLKSIZE]; /* psymodel is one ahead */
    real  energy[2][4][BLKSIZE];
    real  pe[2][4];
    real  thr[2][4][SBMAX_l];
    real  en[2][4][SBMAX_l];
    real  thr_s[2][4][3 * SBMAX_s];
    real  en_s[2][4][3 * SBMAX_s];
    real  ers_save[4];     /* psymodel is one ahead */
    real  ers[2][4];

    real  sfb[2][2][SBMAX_l];
    real  sfb_s[2][2][3 * SBMAX_s];
    real  LAMEsfb[2][2][SBMAX_l];
    real  LAMEsfb_s[2][2][3 * SBMAX_s];

    real     LAMEqss[2][2];
    real     qss[2][2];
    real     big_values[2][2];
    real     sub_gain[2][2][3];

    real  xfsf[2][2][SBMAX_l];
    real  xfsf_s[2][2][3 * SBMAX_s];

    real     over[2][2];
    real  tot_noise[2][2];
    real  max_noise[2][2];
    real  over_noise[2][2];
    real     over_SSD[2][2];
    real     blocktype[2][2];
    real     scalefac_scale[2][2];
    real     preflag[2][2];
    real     mpg123blocktype[2][2];
    real     mixed[2][2];
    real     mainbits[2][2];
    real     sfbits[2][2];
    real     LAMEmainbits[2][2];
    real     LAMEsfbits[2][2];
    real     framesize, stereo, js, ms_stereo, i_stereo, emph, bitrate, sampfreq, maindata;
    real     crc, padding;
    real     scfsi[2], mean_bits, resvsize;
    real     totbits;
};
#ifndef plotting_data_defined
#define plotting_data_defined
typedef struct plotting_data plotting_data;
#endif
#if 0
extern plotting_data *pinfo;
#endif
#endif
