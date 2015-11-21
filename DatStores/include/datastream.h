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



#endif /* DATASTREAM_H */
