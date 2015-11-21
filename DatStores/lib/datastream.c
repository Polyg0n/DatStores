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
    
    if (strtok((char *)__inst, "\t") == NULL) {
        
        printf("\
ERROR:         Cannot pass null instruction to <const char>*__inst!\n\
ERROR:         Exiting BOOL systempoint(...) at 0x%x\n\n", (int)&__inst);
        
        return 2;
        
    } else if (strstr(__inst, "sys_")) {
        
        printf("\
Instruction being passed:   %s\n\
At address:                 0x%x\n\n", __inst, (int)&__inst);

        printf("\
System instruction has been passed successfully!\n\
Continuing...\n\n");
        return 0;
        
    } else {
        
        printf("\
               WARNING:       Instruction has been passed but with warnings!\n\
               WARNING:       See logfile for more info...\n\n");
        return 1;
        
    }
}