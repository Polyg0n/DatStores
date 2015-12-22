//
//  binread.h
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

#ifndef BINREAD_H
#define BINREAD_H

#include <stdbool.h>
#include "types.h"





typedef struct
{
    unsigned int mask_upper_len;
    unsigned int mask_lower_len;
    unsigned int stack_addr_lower;
    unsigned int stack_addr_upper;
    
    //  TODO: Insert these somewhere within a formatting engine?
    union
    {
        unsigned short drt_len;
        unsigned short drt_format;
    };

} drt_unsigned_masks;


//  Only adding two modes for now :P
typedef struct
{
    unsigned int *BIN_MODE_SIMPLE; // Simple In/Out operating
    unsigned int *BIN_MODE_SAFE;  // In/Out operating with system protection enabled
} bin_modes;


typedef struct
{
#ifdef _CV_INT16
    uint16_t      unsignedU099[4];
    uint16_t      unsignedU100[4];
    uint16_t      unsignedU101[4];
#endif
    
    unsigned int *masklen;
} cv_bitmode;


struct grt_fields {
    
} __attribute__((packed));


/**
 * \brief Reads mask through standard param input (duh)
 * \param *binaryModes - Reads which binary mode to read from
 * \return sizeof(mask)
 */
masksize_t readmask(bin_modes *binaryModes);


//  Boolean returns
extern bool canCallMode(bin_modes *bin); //  Checks for call masking mode
extern bool setCallMode(bin_modes *bin); //  Sets call masking mode
extern bool movCallMode(bin_modes *bin); //  Moves call masking mode


//  CRTD Standard I/O
extern int crtdin(drt_unsigned_masks *dms);
extern int crtdout(drt_unsigned_masks *dms);


#endif /* BINREAD_H */
