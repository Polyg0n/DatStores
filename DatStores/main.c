//
//  main.c
//  DatStores
//
//  Created by Corbin Matschull on 11/19/15.
//  Copyright © 2015 Corbin Matschull. All rights reserved.
//

#include <stdio.h>

#include "include/datastream.h"

int main(int argc, const char * argv[]) {
    char exitc;
    while (exitc != 'Y' || exitc != 'y') {
        printf("Enter command to pass > ");
        char comd;
        scanf("%s", &comd);
        systempoint(&comd);
        printf("Run command structure again? > ");
        scanf("%s", &exitc);
        
        if(exitc == 'N' || exitc == 'n') {
            break;
        }
    }
    return 0;
}
