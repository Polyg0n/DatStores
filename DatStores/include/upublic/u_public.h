//
//  upublic/u_public.h
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
//  ================================================================================================
//
//
//  u_public.h -- Public structures, enums, prototypes, defines for unity operations
//
#ifndef UPUBLIC_H
#define UPUBLIC_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../types.h"


#define MAX_STRING_BUFFER 512


typedef unsigned long utime_s; // Seconds
typedef unsigned char utime_d; // Declarator


struct utime
{
    utime_s ssdv; // Scaling seconds declarated variable
    utime_d dcls; // Declarated long second (Defined as char for string interpolation)
};


struct unitypath
{
    uword_t *psize;      // Path size
    uword_t *achpath;    // Asynchronous path
    uboolean pHighlight; // Path highlighting
    dword_t uvec2d[MAX_STRING_BUFFER][MAX_STRING_BUFFER]; // 2 Dimensional vector path (Both arrays have a max size of 512-Bytes)
};


typedef struct
{
    vec2d *svec_t;
} uvec_t;



void PublicCreationCC(unsigned int pointalize, bool willCreate) {
    unsigned int CCUnit;
    for (int i=0;i<16;i++) {
        printf("Creating public CC unit...\n");
        sleep(1);
        
        switch (pointalize) {
            case 1:
                printf("\tCreating STATIC CCUnit\n");
                CCUnit = 0x01;
                willCreate = false;
            break;
            case 2:
                printf("\tCreating EXPLICIT CCUnit\n");
                CCUnit = 0x021 ^ 14;
                willCreate = true;
                for(int i=0;i<8;i++){
                    CCUnit = CCUnit ^ 6;
                }
            break;
            case 3:
                printf("\tCreating INLINE CCUnit\n");
                CCUnit = 0x032 ^ 16;
                willCreate = true;
            break;
            default:
                printf("\tDefaulting to variable CCUnit\n");
                CCUnit = 0x064 ^ 32;
                willCreate = false;
            break;
        }

        printf("\n\t\tPass Number: %d\n\t\tCCUnit_ID: %x\n\t\tState Of <willCreate>: %d\n\n", i, CCUnit, willCreate);
    }
}


//
//  <VOID>u_time(-><STRUCT>utime)
/**
 * \brief Unity time function
 * \param *utbuf - Structure call for time constructs
 * \return Nothing
 *
 * \note This is a stupid function to have but I'm including it for sanities sake
 */
void u_time(struct utime *utbuf){
    for(utime_s i=0;i<utbuf->ssdv;i++){
        if (i==utbuf->ssdv) {
            break;
        }
    }
}



//
// <BOOLEAN>UnityDepthPath()
/**
 * \brief Creates a deep I/O path to provide a low level systems interface for superfast I/O
 */
uboolean UnityDepthPath(struct unitypath *up, uboolean sortHighFirst, uboolean viewConstructsAsParams);


//
// 
/**
 *
 */
uboolean UnityTime(struct utime *timesvc, uword_t *uTime);


















#endif /* UPUBLIC_H */
