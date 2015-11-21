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


typedef size_t packed_t;


//  Modifiable size length
typedef void (*packlen)(int *__slen, int *__nlen);


struct datbox
{
    unsigned long  _boxdata;
    word_t         _boxlen;
    packed_t       _nil_formats;
    word_t         _system;
} __attribute__((packed));


extern int initstr(const char *cvcmd[]);


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





#endif /* DATASTREAM_H */
