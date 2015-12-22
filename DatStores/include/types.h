#ifndef TYPES_H
#define TYPES_H

#define VECSTK_DEFAULT 255

#if !defined(bool)
#   include <stdbool.h>
#endif

typedef size_t packed_t;
typedef size_t masksize_t;
typedef int BOOL;
typedef unsigned long  uqword_t;
typedef          long  qword_t;
typedef unsigned int   udword_t;
typedef          int   dword_t;
typedef unsigned short uword_t;
typedef          short word_t;
typedef unsigned char  ubyte_t;
typedef          char  byte_t;
typedef const char     cbyte_t;
typedef          bool  uboolean;


typedef struct
{
    int l[VECSTK_DEFAULT];
    int r[VECSTK_DEFAULT];
} vec2d;


typedef struct
{
    unsigned int   R[256];
    unsigned int   G[256];
    unsigned int   B[256];
             float A[1];    // 0->1
} crt_color_t;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define NRX  0x01
#define NRC  0x02
#define NCA  0x03
#define NCB  0x04

#define __STOP // Hammer time
#define _BMASK //  Defines a "can modify" flag to all bit mask functions

#define FOREACH_CHAR(ptrvar, strvar) char* ptrvar; for( ptrvar=strvar ; (*ptrvar) != '\0' ; *ptrvar++ )
#define FOREACH_INT(intpvar, intary) int* intpvar; for( intpvar=intary ; (intpvar < (sizeof(intary)/sizeof(intary[0]))) ; intpvar++)

#endif /* TYPES_H */
