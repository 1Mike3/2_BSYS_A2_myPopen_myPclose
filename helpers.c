//
// Created by michi on 5/18/23.
//

#include "helpers.h"

//ignore, just used this one for debugging

void printPipe(FILE * file){

    char lineBuffer[300];
    while (fgets(lineBuffer,300,file) != 0){
        fputs(lineBuffer,stdout);
    }
}