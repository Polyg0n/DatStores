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




//  Bad call key string
#define DATASTREAM_BADCALL 0x0BADCA11


//  Modifiable package length
typedef void (*packlen)(int *__slen, int *__nlen);

typedef enum
{
    //  USE AS PLACER FOR NO OPERATION IN STREAM
    OP_NO_OP     = 0xCCFF,  // OP has no instruction
    OP_NO_READ   = 0x00,    // OP has no reading at the moment
    
    OP_READ_FULL = 0x01,    // OP read full instruction
    OP_READ_PART = 0x02,    // OP read part of the instruction
    OP_READ_SEED = 0x03,    // OP read the seed of the instruction
    OP_READ_POP  = 0x04,    // OP read the pop address
    OP_PUSH_SDD  = 0x05,    // OP read the Static Destruction Designator
    
    OP_CALL_SEED = 0xA1,    // OP called instruction seed
    OP_CALL_FULL = 0xA2,    // OP called full instruction
    OP_CALL_DEAD = 0xA3,    // OP called a dead instruction (also could be missing/un-referenced address?)
    OP_CALL_PART = 0xA4,    // OP called part of the instruction
    
    // USE WITH NO LINK
    OP_FULL_PART = 0xB1,    // OP read full part (i.e fragmented but complete fragment)
                            //                      ^ can piece together? ^
} _opaque_op_flags_t;


typedef struct
{
    uword_t     othread_start;          // Opaque thread starting address
    uword_t     othread_end;            // Opaque thread ending address
    uword_t     othread_jmp;            // Opaque jump addres
    uword_t     othread_cmp;            // Opaque compare address
    uword_t     othread_non_cond_jmp;   // Opaque non condition jump address
    
    packed_t    othread_no_start_cond;  // Opqaue no starting conditional
    
    BOOL        has_forward  : 1;       // Has forward address to compare before main processes handler
    BOOL        will_forward : 1;       // Will forward self address to compare with main process handler
    
    //  Store same addr
    union {
        ubyte_t     _hold_pack;         // Holding package
        ubyte_t     _dump_pack;         // Dump package
        byte_t      _hold_pack_upper;   // Hold the upper bit package
        byte_t      _dump_pack_upper;   // Dump the upper bit package
    };
} _opaque_ops_t;


struct datbox
{
    unsigned long  _boxdata;        // Data size per box
    word_t         _boxlen;         // Data length per box
    packed_t       _nil_formats;    // Nil-able formats
    word_t         _system;         // System data
} __attribute__((packed));          // Pack this S.O.B


//  Field sectors
struct _fieldsec
{
    word_t          _fieldlen;  // Field data length
    word_t          _typelen;   // Type data length
    
    
    //  If we're running hot and mean
    #if defined(__DAT_LEAN_AND_MEAN__)
        dword_t     _fieldlen;
        dword_t     _typelen;
    #endif
};

#pragma mark - String Controllers
extern int  initstr(cbyte_t *cvcmd[]);                //  Init a string space
extern int  desstr(cbyte_t *cvcmd[]);                 //  Destroy a string space
extern void movname(char *_virtual, char *_vrmove);   //  Move typename to another space via its name



#pragma mark - System/Process Handlers
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
//             Primary Low Level Controller Defs       //     Version: 1.0.1
//                                                     //
/////////////////////////////////////////////////////////////////////////////////

#pragma mark - Low Level Controllers


/*
 *  If defined to "1" kernel will force wait of new commands 
 *  instead of multithreading them.
 */
#define _KERN_WAITS 0


//  Can operate on inline operations
//  TODO: Monitor low level binary from I/O streams?
volatile ubyte_t ASM
(cbyte_t __inst, cbyte_t *__op, cbyte_t *__reg_dest, cbyte_t *__reg_src);

extern int movword
(word_t *_s1, word_t *_s2);                     // Move word to reg

extern int delword
(word_t *_s1, word_t *_s2);                     // Delete word to reg

extern packed_t _minimum_lendef
(_opaque_ops_t *_ops, struct _fieldsec *fsec, dword_t *_un); // Minimum length definition

extern uword_t _move_lendef
(_opaque_ops_t *_ops, byte_t *bytesec);         // Move length definition

extern byte_t cmpbyte
(char* __byte, char* __byte_cmp);               // Compare byte sequence

#pragma mark -



//////////////////////////////////////////////////////////////////////////////////////
//                                                     //
// END         Primary Low Level Controller Defs       //     Version: 1.0.1    END //
//                                                     //
//////////////////////////////////////////////////////////////////////////////////////



//  If we don't have any explicitly defined addressing space
#ifdef __NO_DEFINED_ADDR_SPACE__
    //  We use this bad boy
    extern void __create_system_byte
    (word_t *_byte_inner, word_t *_byte_outer) _BMASK;
#else
    //  If not... Well... We go here...
    //  Shouldn't you know control flow?  \( ._.)/
    extern void __create_system_byte
    (dword_t *_byte_inner, dword_t *_byte_outer) _BMASK;
#endif


//  Seek out free address
uword_t skaddr
(ubyte_t *aptr);




#endif /* DATASTREAM_H */
