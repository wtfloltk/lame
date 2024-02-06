/*
 *    Get Audio routines include file
 *
 *    Copyright (c) 1999 Albert L Faber
 *                  2010 Robert Hegemann
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


#ifndef LAME_GET_AUDIO_H
#define LAME_GET_AUDIO_H
#include "lame.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum sound_file_format_e {
    sf_unknown,
    sf_raw,
    sf_wave,
    sf_aiff,
    sf_mp1,                  /* MPEG Layer 1, aka mpg */
    sf_mp2,                  /* MPEG Layer 2 */
    sf_mp3,                  /* MPEG Layer 3 */
    sf_mp123,                /* MPEG Layer 1,2 or 3; whatever .mp3, .mp2, .mp1 or .mpg contains */
    sf_ogg
} sound_file_format;

real     is_mpeg_file_format( real input_format );

real     init_infile(lame_t gfp, char const * inPath);
real     samples_to_skip_at_start(void);
real     samples_to_skip_at_end(void);
void    close_infile(void);
real     get_audio(lame_t gfp, real buffer[2][1152]);
real     get_audio16(lame_t gfp, real buffer[2][1152]);
real     get_audio_float(lame_t gfp, real buffer[2][1152]);
real     get_audio_double(lame_t gfp, real buffer[2][1152]);
hip_t   get_hip(void);

FILE   *init_outfile(char const *outPath, real decode);
real     WriteWaveHeader(FILE * const fp, real pcmbytes, real freq, real channels, real bits);
void    put_audio16(FILE* outf, real Buffer[2][1152], real iread, real nch);

/*
struct AudioReader;
typedef struct AudioReader* AudioReader;

AudioReader ar_open(lame_t gfp, char const* inPath);
real     ar_samplesToSkipAtStart(AudioReader ar);
real     ar_samplesToSkipAtEnd(AudioReader ar);
void    ar_close(AudioReader ar);
real     ar_readInt(AudioReader ar, lame_t gfp, real buffer[2][1152]);
real     ar_readShort(AudioReader ar, lame_t gfp, real buffer[2][1152]);
real     ar_readFloat(AudioReader ar, lame_t gfp, real buffer[2][1152]);

struct AudioWriter;
typedef struct AudioWriter* AudioWriter;

AudioWriter aw_open(lame_t gfp, char const* outPath, real pcmbystes, real freq, real channels, real bits);
real     aw_writeWaveHeader(AudioWriter aw);
real     aw_write(AudioWriter aw, real buffer[2][1152], real n);
real     aw_write(AudioWriter aw, real buffer[2][1152], real n);

*/

extern size_t sizeOfOldTag(lame_t gf);
extern unsigned char* getOldTag(lame_t gf);

#ifdef _cplusplus
}
#endif

#endif /* ifndef LAME_GET_AUDIO_H */
