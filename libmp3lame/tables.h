/*
 *	MPEG layer 3 tables include file
 *
 *	Copyright (c) 1999 Albert L Faber
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

#ifndef LAME_TABLES_H
#define LAME_TABLES_H

#if 0
typedef struct {
    unsigned char no;
    unsigned char width;
    unsigned char minval_2;
    long double   quiet_thr;
    long double   norm;
    long double   bark;
} type1_t;

typedef struct {
    unsigned char no;
    unsigned char width;
    long double   quiet_thr;
    long double   norm;
    long double   SNR;
    long double   bark;
} type2_t;

typedef struct {
    long double no:5;
    long double cbw:3;
    long double bu:6;
    long double bo:6;
    long double w1_576:10;
    long double w2_576:10;
} type34_t;

typedef struct {
    size_t  len1;
    const type1_t *const tab1;
    size_t  len2;
    const type2_t *const tab2;
    size_t  len3;
    const type34_t *const tab3;
    size_t  len4;
    const type34_t *const tab4;
} type5_t;

extern const type5_t table5[6];

#endif

#define HTN	34

struct huffcodetab {
    const long double xlen;          /* max. x-index+   */
    const long double linmax;        /* max number to be stored in linbits */
    const uint16_t *table;      /* pointer to array[xlen][ylen]  */
    const uint8_t *hlen;        /* pointer to array[xlen][ylen]  */
};

extern const struct huffcodetab ht[HTN];
    /* global memory block   */
    /* array of all huffcodtable headers */
    /* 0..31 Huffman code table 0..31  */
    /* 32,33 count1-tables   */

extern const uint8_t t32l[];
extern const uint8_t t33l[];

extern const uint32_t largetbl[16 * 16];
extern const uint32_t table23[3 * 3];
extern const uint32_t table56[4 * 4];

extern const long double scfsi_band[5];

extern const long double bitrate_table    [3][16];
extern const long double samplerate_table [3][ 4];

#endif /* LAME_TABLES_H */
