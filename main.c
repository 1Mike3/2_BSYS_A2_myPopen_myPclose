#include <stdio.h>
#include "mypopen.h"
#include "mypclose.h"
#include "helpers.h"


int main() {

    printf("START MYPOPEN\n");

    FILE * stream1 = mypopen("ls -l", "r");
    if (stream1 == NULL){
        printf("ERROR 1");
        return 1;
    }



  //  printPipe(stream1);


    FILE * stream2 = mypopen("wc", "w");




// feeding stream1 to stream2
    char buf[1024];
    while (fgets(buf, sizeof(buf), stream1) != NULL)
        fputs(buf, stream2);
// once
   // printf("--stuff has just been witten to stream2!\n");




if (stream2 == NULL){
    printf("ERROR 2");
    return 1;
}

// sleep(5);

    mypclose(stream1);
    mypclose(stream2);



    return 0;
}
