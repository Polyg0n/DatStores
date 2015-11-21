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
ERROR:         Exiting BOOL systempoint(...) at %x\n\n", (int)&__inst);
        
        goto error_return;
    } else if (strstr(__inst, "sys_")){
        
        printf("\
Instruction being passed:   %s\n\
At address:                 %x\n\n", __inst, (int)&__inst);
        goto passive_return;
        
    }
    
    
    
error_return:
    if(PASSED_WITH_ERROR) return 2;
    
warning_return:
    
    printf("\
WARNING:       Instruction has been passed but with warnings!\n\
WARNING:       See logfile for more info...\n\n");
    
    if(PASSED_WITH_WARNING) return 1;
    
passive_return:
    
    printf("\
System instruction has been passed successfully!\n\
Continuing...\n\n");
    
    return 0;
}