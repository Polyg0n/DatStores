//
//  datastream.h
//  DatStores
//
//  Created by Corbin Matschull on 11/19/15.
//  Copyright © 2015 Corbin Matschull. All rights reserved.
//
//  LICENSE:
//
//      Basically the license appended to this software is as follows,
//          I don't care what you do with this license, just know that I don't care...
//          If you break something or use this to try and defile some government thingy or another,
//          I don't care it's not my problem, I'm simply the red-eyed breaker of things-
//          that developed this software...
//

#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <stdio.h>
#include "types.h"


#define DATASTREAM_BADCALL 0x0BADCA11


//  Modifiable size length
typedef void (*packlen)(int *__slen, int *__nlen);


typedef enum
{
    //  USE AS PLACER FOR NO OPERATION IN STREAM
    OP_NO_OP     = 0xCCFF,
    OP_NO_READ   = 0x00,
    
    OP_READ_FULL = 0x01,
    OP_READ_PART = 0x02,
    OP_READ_SEED = 0x03,
    OP_READ_POP  = 0x04,
    OP_PUSH_SDD  = 0x05,
    
    OP_CALL_SEED = 0xA1,
    OP_CALL_FULL = 0xA2,
    OP_CALL_DEAD = 0xA3,
    OP_CALL_PART = 0xA4,
    
    // USE WITH NO LINK
    OP_FULL_PART = 0xB1,
} _opaque_op_flags_t;

typedef struct
{
    uword_t     othread_start;
    uword_t     othread_end;
    uword_t     othread_jmp;
    uword_t     othread_cmp;
    uword_t     othread_non_cond_jmp;
    
    packed_t    othread_no_start_cond;
    
    BOOL        has_forward  : 1;
    BOOL        will_forward : 1;
    
    union {
        ubyte_t     _hold_pack;
        ubyte_t     _dump_pack;
        byte_t      _hold_pack_upper;
        byte_t      _dump_pack_upper;
    };
} _opaque_ops_t;


struct datbox
{
    unsigned long  _boxdata;
    word_t         _boxlen;
    packed_t       _nil_formats;
    word_t         _system;
} __attribute__((packed));


struct _fieldsec
{
    word_t          _fieldlen;
    word_t          _typelen;
    
    
    //  If we're running hot and mean
    #if defined(__DAT_LEAN_AND_MEAN__)
        dword_t     _fieldlen;
        dword_t     _typelen;
    #endif
};


//  Init a string space
extern int  initstr(const char *cvcmd[]);

//  Destroy a string space
extern int  desstr(const char *cvcmd[]);

//  Move typename to another space via its name
extern void movname(char *__virtual, char *__vrmove);

// INTERNAL:
long procstore(struct datbox *box, packed_t packlen_addr);



/**
 * \brief Point an instruction to a data stream
 *
 * \param *__inst - Instruction to pass
 * \param *__databoxes - Packages that contain current data in a stream
 *
 * \return 2 IF instruction did not pass due to errors
 * \return 1 IF instruction was passed but with warnings
 * \return 0 IF instruction was successfully passed
 */
BOOL systempoint(const char *__inst);



/////////////////////////////////////////////////////////////////////////////////
//                                                     //
//             Primary low level controller defs       //     Version: 1.0.1
//                                                     //
/////////////////////////////////////////////////////////////////////////////////

//  Can operate on inline operations
//  TODO:   Monitor low level binary from I/O streams?
volatile ubyte_t ASM(const char __inst, const char *__op,
                     const char *__reg_dest, const char *__reg_src);


extern int movword(word_t *_s1, word_t *_s2);   // Move word to reg
extern int delword(word_t *_s1, word_t *_s2);   // Delete word to reg
extern packed_t _minimum_lendef(_opaque_ops_t *_ops, struct _fieldsec *fsec, dword_t *_un);
extern uword_t _move_lendef(_opaque_ops_t *_ops, byte_t *bytesec);


























#endif /* DATASTREAM_H */
