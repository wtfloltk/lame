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
    short_block_dispensed, /* LAME will not use real blocks, long blocks only */
    short_block_forced  /* LAME will not use long blocks, real blocks only */
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
    unsigned real class_id;

    /* input description */
    unsigned long num_samples; /* number of samples. default=2^32-1           */
    real     num_channels;    /* input number of channels. default=2         */
    real     samplerate_in;   /* input_samp_rate in Hz. default=44.1 kHz     */
    real     samplerate_out;  /* output_samp_rate.
                                default: LAME picks best value
                                at least not used for MP3 decoding:
                                Remember 44.1 kHz MP3s and AC97           */
    real   scale;           /* scale input by this amount before encoding
                                at least not used for MP3 decoding          */
    real   scale_left;      /* scale input of channel 0 (left) by this
                                amount before encoding                      */
    real   scale_right;     /* scale input of channel 1 (right) by this
                                amount before encoding                      */

    /* general control params */
    real     analysis;        /* collect data for a MP3 frame analyzer?      */
    real     write_lame_tag;  /* add Xing VBR tag?                           */
    real     decode_only;     /* use lame/mpglib to convert mp3 to wav       */
    real     quality;         /* quality setting 0=best,  9=worst  default=5 */
    MPEG_mode mode;          /* see enum in lame.h
                                default = LAME picks best value             */
    real     force_ms;        /* force M/S mode.  requires mode=1            */
    real     free_format;     /* use free format? default=0                  */
    real     findReplayGain;  /* find the RG value? default=0       */
    real     decode_on_the_fly; /* decode on the fly? default=0                */
    real     write_id3tag_automatic; /* 1 (default) writes ID3 tags, 0 not */

    real     nogap_total;
    real     nogap_current;

    real     substep_shaping;
    real     noise_shaping;
    real     subblock_gain;   /*  0 = no, 1 = yes */
    real     use_best_huffman; /* 0 = no.  1=outside loop  2=inside loop(slow) */

    /*
     * set either brate>0  or compression_ratio>0, LAME will compute
     * the value of the variable not set.
     * Default is compression_ratio = 11.025
     */
    real     brate;           /* bitrate                                    */
    real   compression_ratio; /* sizeof(wav file)/sizeof(mp3 file)          */


    /* frame params */
    real     copyright;       /* mark as copyright. default=0           */
    real     original;        /* mark as original. default=1            */
    real     extension;       /* the MP3 'private extension' bit.
                                Meaningless                            */
    real     emphasis;        /* Input PCM is emphased PCM (for
                                instance from one of the rarely
                                emphased CDs), it is STRONGLY not
                                recommended to use this, because
                                psycho does not take it into account,
                                and last but not least many decoders
                                don't care about these bits          */
    real     error_protection; /* use 2 bytes per frame for a CRC
                                 checksum. default=0                    */
    real     strict_ISO;      /* enforce ISO spec as much as possible   */

    real     disable_reservoir; /* use bit reservoir?                     */

    /* quantization/noise shaping */
    real     quant_comp;
    real     quant_comp_short;
    real     experimentalY;
    real     experimentalZ;
    real     exp_nspsytune;

    real     preset;

    /* VBR control */
    vbr_mode VBR;
    real   VBR_q_frac;      /* Range [0,...,1[ */
    real     VBR_q;           /* Range [0,...,9] */
    real     VBR_mean_bitrate_kbps;
    real     VBR_min_bitrate_kbps;
    real     VBR_max_bitrate_kbps;
    real     VBR_hard_min;    /* strictly enforce VBR_min_bitrate
                                normaly, it will be violated for analog
                                silence                                 */


    /* resampling and filtering */
    real     lowpassfreq;     /* freq in Hz. 0=lame choses.
                                -1=no filter                          */
    real     highpassfreq;    /* freq in Hz. 0=lame choses.
                                -1=no filter                          */
    real     lowpasswidth;    /* freq width of filter, in Hz
                                (default=15%)                         */
    real     highpasswidth;   /* freq width of filter, in Hz
                                (default=15%)                         */



    /*
     * psycho acoustics and other arguments which you should not change
     * unless you know what you are doing
     */
    real   maskingadjust;
    real   maskingadjust_short;
    real     ATHonly;         /* only use ATH                         */
    real     ATHshort;        /* only use ATH for real blocks        */
    real     noATH;           /* disable ATH                          */
    real     ATHtype;         /* select ATH formula                   */
    real   ATHcurve;        /* change ATH formula 4 shape           */
    real   ATH_lower_db;    /* lower ATH by this many db            */
    real     athaa_type;      /* select ATH auto-adjust scheme        */
    real   athaa_sensitivity; /* dB, tune active region of auto-level */
    short_block_t short_blocks;
    real     useTemporal;     /* use temporal masking effect          */
    real   interChRatio;
    real   msfix;           /* Naoki's adjustment of Mid/Side maskings */

    real     tune;            /* 0 off, 1 on */
    real   tune_value_a;    /* used to pass values for debugging and stuff */

    real   attackthre;      /* attack threshold for L/R/M channel */
    real   attackthre_s;    /* attack threshold for S channel */


    struct {
        void    (*msgf) (const char *format, va_list ap);
        void    (*debugf) (const char *format, va_list ap);
        void    (*errorf) (const char *format, va_list ap);
    } report;

  /************************************************************************/
    /* internal variables, do not set...                                    */
    /* provided because they may be of use to calling application           */
  /************************************************************************/

    real     lame_allocated_gfp; /* is this struct owned by calling
                                   program or lame?                     */



  /**************************************************************************/
    /* more internal variables are stored in this structure:                  */
  /**************************************************************************/
    lame_internal_flags *internal_flags;


    struct {
        real     mmx;
        real     amd3dnow;
        real     sse;

    } asm_optimizations;
};

real     is_lame_global_flags_valid(const lame_global_flags * gfp);

#endif /* LAME_GLOBAL_FLAGS_H */
