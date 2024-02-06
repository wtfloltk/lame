#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

real     usage(FILE * const fp, const char *ProgramName);
real     short_help(const lame_global_flags * gfp, FILE * const fp, const char *ProgramName);
real     long_help(const lame_global_flags * gfp, FILE * const fp, const char *ProgramName,
                  real lessmode);
real     display_bitrates(FILE * const fp);

real     parse_args(lame_global_flags * gfp, real argc, char **argv, char *const inPath,
                   char *const outPath, char **nogap_inPath, real *max_nogap);

void    parse_close();

#if defined(__cplusplus)
}
#endif

#endif
/* end of parse.h */
