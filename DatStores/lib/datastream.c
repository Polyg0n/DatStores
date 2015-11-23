//
//  datastream.c
//  DatStores
//
//  Created by Corbin Matschull on 11/19/15.
//  Copyright © 2015 Corbin Matschull. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "../include/datastream.h"
#include "../include/econn.h"


BOOL systempoint(const char *__inst) {
    
    //  Check for null space where *__inst should be
    if (strtok((char *)__inst, "\t") == NULL) {
        
        printf("\
ERROR:         Cannot pass null instruction to <const char>*__inst!\n\
ERROR:         Exiting BOOL systempoint(...) at 0x%x\n\n", (int)&__inst);
        
        return 2;
        
    //  If we start with a command starting with sys_ we know it's a system command
    } else if (strstr(__inst, "sys_")) {
        
        printf("\
Instruction being passed:   %s\n\
At address:                 0x%x\n\n", __inst, (int)&__inst);

        printf("\
System instruction has been passed successfully!\n\
Continuing...\n\n");
        
        
        FILE *f= fopen("../syspack.txt", "w");
        if (f == NULL) {
            printf("ERROR: File could not be created or read...\n");
            printf("Error: %s\n", strerror(errno));
        }
        
        
            fprintf(f, "%s\n", __inst);
            printf("Successfully wrote data to file. Exiting...\n\n");
            fclose(f);
        
        
        return 0;
        
    } else {

        printf("\
               WARNING:       Instruction has been passed but with warnings!\n\
               WARNING:       See logfile for more info...\n\n");
        return 1;
        
    }
}




packed_t _minimum_lendef(_opaque_ops_t *_ops, struct _fieldsec *fsec, dword_t *_un) {
    
    for(int i=0;i<16;i++) {
        _ops->_dump_pack_upper++;
    }
    
    return (unsigned long)_un;
}




