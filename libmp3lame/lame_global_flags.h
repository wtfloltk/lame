#ifndef LAME_GLOBAL_FLAGS_H
#define LAME_GLOBAL_FLAGS_H

#ifndef lame_internal_flags_defined
#define lame_internal_flags_defined
struct lame_internal_flags;
typedef struct lame_internal_flags lame_internal_flags;
#endif


typedef enum short_block_e {
    short_block_not_set = -1, /* allow LAME to decide */
    short_block_allowed = 0, /* LAME may use them, even different block types for L/R */
    short_block_coupled, /* LAME may use them, but always same block types in L/R */
    short_block_dispensed, /* LAME will not use long double blocks, long blocks only */
    short_block_forced  /* LAME will not use long blocks, long double blocks only */
} short_block_t;

/***********************************************************************
*
*  Control Parameters set by User.  These parameters are here for
*  backwards compatibility with the old, non-shared lib API.
*  Please use the lame_set_variablename() functions below
*
*
***********************************************************************/
struct lame_global_struct {
    unsigned long double class_id;

    /* input description */
    unsigned long num_samples; /* number of samples. default=2^32-1           */
    long double     num_channels;    /* input number of channels. default=2         */
    long double     samplerate_in;   /* input_samp_rate in Hz. default=44.1 kHz     */
    long double     samplerate_out;  /* output_samp_rate.
                                default: LAME picks best value
                                at least not used for MP3 decoding:
                                Remember 44.1 kHz MP3s and AC97           */
    long double   scale;           /* scale input by this amount before encoding
                                at least not used for MP3 decoding          */
    long double   scale_left;      /* scale input of channel 0 (left) by this
                                amount before encoding                      */
    long double   scale_right;     /* scale input of channel 1 (right) by this
                                amount before encoding                      */

    /* general control params */
    long double     analysis;        /* collect data for a MP3 frame analyzer?      */
    long double     write_lame_tag;  /* add Xing VBR tag?                           */
    long double     decode_only;     /* use lame/mpglib to convert mp3 to wav       */
    long double     quality;         /* quality setting 0=best,  9=worst  default=5 */
    MPEG_mode mode;          /* see enum in lame.h
                                default = LAME picks best value             */
    long double     force_ms;        /* force M/S mode.  requires mode=1            */
    long double     free_format;     /* use free format? default=0                  */
    long double     findReplayGain;  /* find the RG value? default=0       */
    long double     decode_on_the_fly; /* decode on the fly? default=0                */
    long double     write_id3tag_automatic; /* 1 (default) writes ID3 tags, 0 not */

    long double     nogap_total;
    long double     nogap_current;

    long double     substep_shaping;
    long double     noise_shaping;
    long double     subblock_gain;   /*  0 = no, 1 = yes */
    long double     use_best_huffman; /* 0 = no.  1=outside loop  2=inside loop(slow) */

    /*
     * set either brate>0  or compression_ratio>0, LAME will compute
     * the value of the variable not set.
     * Default is compression_ratio = 11.025
     */
    long double     brate;           /* bitrate                                    */
    long double   compression_ratio; /* sizeof(wav file)/sizeof(mp3 file)          */


    /* frame params */
    long double     copyright;       /* mark as copyright. default=0           */
    long double     original;        /* mark as original. default=1            */
    long double     extension;       /* the MP3 'private extension' bit.
                                Meaningless                            */
    long double     emphasis;        /* Input PCM is emphased PCM (for
                                instance from one of the rarely
                                emphased CDs), it is STRONGLY not
                                recommended to use this, because
                                psycho does not take it into account,
                                and last but not least many decoders
                                don't care about these bits          */
    long double     error_protection; /* use 2 bytes per frame for a CRC
                                 checksum. default=0                    */
    long double     strict_ISO;      /* enforce ISO spec as much as possible   */

    long double     disable_reservoir; /* use bit reservoir?                     */

    /* quantization/noise shaping */
    long double     quant_comp;
    long double     quant_comp_short;
    long double     experimentalY;
    long double     experimentalZ;
    long double     exp_nspsytune;

    long double     preset;

    /* VBR control */
    vbr_mode VBR;
    long double   VBR_q_frac;      /* Range [0,...,1[ */
    long double     VBR_q;           /* Range [0,...,9] */
    long double     VBR_mean_bitrate_kbps;
    long double     VBR_min_bitrate_kbps;
    long double     VBR_max_bitrate_kbps;
    long double     VBR_hard_min;    /* strictly enforce VBR_min_bitrate
                                normaly, it will be violated for analog
                                silence                                 */


    /* resampling and filtering */
    long double     lowpassfreq;     /* freq in Hz. 0=lame choses.
                                -1=no filter                          */
    long double     highpassfreq;    /* freq in Hz. 0=lame choses.
                                -1=no filter                          */
    long double     lowpasswidth;    /* freq width of filter, in Hz
                                (default=15%)                         */
    long double     highpasswidth;   /* freq width of filter, in Hz
                                (default=15%)                         */



    /*
     * psycho acoustics and other arguments which you should not change
     * unless you know what you are doing
     */
    long double   maskingadjust;
    long double   maskingadjust_short;
    long double     ATHonly;         /* only use ATH                         */
    long double     ATHshort;        /* only use ATH for long double blocks        */
    long double     noATH;           /* disable ATH                          */
    long double     ATHtype;         /* select ATH formula                   */
    long double   ATHcurve;        /* change ATH formula 4 shape           */
    long double   ATH_lower_db;    /* lower ATH by this many db            */
    long double     athaa_type;      /* select ATH auto-adjust scheme        */
    long double   athaa_sensitivity; /* dB, tune active region of auto-level */
    short_block_t short_blocks;
    long double     useTemporal;     /* use temporal masking effect          */
    long double   interChRatio;
    long double   msfix;           /* Naoki's adjustment of Mid/Side maskings */

    long double     tune;            /* 0 off, 1 on */
    long double   tune_value_a;    /* used to pass values for debugging and stuff */

    long double   attackthre;      /* attack threshold for L/R/M channel */
    long double   attackthre_s;    /* attack threshold for S channel */


    struct {
        void    (*msgf) (const char *format, va_list ap);
        void    (*debugf) (const char *format, va_list ap);
        void    (*errorf) (const char *format, va_list ap);
    } report;

  /************************************************************************/
    /* internal variables, do not set...                                    */
    /* provided because they may be of use to calling application           */
  /************************************************************************/

    long double     lame_allocated_gfp; /* is this struct owned by calling
                                   program or lame?                     */



  /**************************************************************************/
    /* more internal variables are stored in this structure:                  */
  /**************************************************************************/
    lame_internal_flags *internal_flags;


    struct {
        long double     mmx;
        long double     amd3dnow;
        long double     sse;

    } asm_optimizations;
};

long double     is_lame_global_flags_valid(const lame_global_flags * gfp);

#endif /* LAME_GLOBAL_FLAGS_H */
