#include <stdio.h>
#include "mypopen.h"
#include "mypclose.h"
#include "helpers.h"
#include "definitions.h"

int main() {
    printf("DEMO MYPOPEN MYPCLOSE\n");
#pragma region mypopen
    FILE * stream1 = mypopen("ls", READ);
    //error handling
    if (stream1 == NULL){
        printf("ERROR MYPOPEN 1!\n");
        return 1;
    }

    FILE * stream2 = mypopen("wc", WRITE);
    //error handling
    if (stream2 == NULL){
        printf("ERROR MYPOPEN 2!\n");
        return 1;
    }
#pragma endregion mypopen

//feeding the output of stream1 to stream2
#pragma region feeding stream1 to stream2
// feeding stream1 to stream2
    char buf[1024];
    while (fgets(buf, sizeof(buf), stream1) != NULL)
        fputs(buf, stream2);
   // printf("--stuff has just been witten to stream2!\n");
#pragma endregion feeding stream1 to stream2

//closing the filestreams and error handling
#pragma region mypclose

    if(0 > mypclose(stream1)){
        printf("ERROR MYPCLOSE 1!\n");
        return 1;
    }

    if(0 > mypclose(stream2)){
        printf("ERROR MYPCLOSE 2!\n");
        return 1;
    }
#pragma endregion mypclose

    return 0;
}
