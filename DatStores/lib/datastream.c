//
//  datastream.c
//  DatStores
//
//  Created by Corbin Matschull on 11/19/15.
//  Copyright © 2015 Corbin Matschull. All rights reserved.
//

#include <stdio.h>
#include <string.h>


#include "../include/datastream.h"
#include "../include/econn.h"

BOOL systempoint(const char *__inst){
    
    
    if (__inst == NULL || strcmp(__inst, " ")) {
        printf("ERROR:         Cannot pass null instruction to *__inst!\n\
ERROR:         Exiting BOOL systempoint(...) at %x\n\n", (int)&__inst);
        goto error_return;
    }
    
    
    
error_return:
    if(PASSED_WITH_ERROR) return 2;
    
warning_return:
    if(PASSED_WITH_WARNING) return 1;
    
passive_return:
    return 0;
}