#ifndef TYPES_H
#define TYPES_H

typedef size_t packed_t;
//typedef unsigned int size_t;
typedef int BOOL;

typedef unsigned long  uqword_t;
typedef          long  qword_t;
typedef unsigned int   udword_t;
typedef          int   dword_t;
typedef unsigned short uword_t;
typedef          short word_t;
typedef unsigned char  ubyte_t;
typedef          char  byte_t;


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


#endif /* TYPES_H */
