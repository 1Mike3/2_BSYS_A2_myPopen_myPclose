#include <stdio.h>
#include "mypopen.h"
#include "mypclose.h"
#include "helpers.h"


int main() {
    FILE * ls = mypopen("ls -l","r");
    if (ls == NULL){
        printf("ERROR 1");
        return 1;
    }



  //  printPipe(ls);
 //   printf("TEST\n");

    FILE * wc = mypopen("wc","w");

    sleep(1);

    char buffer[11];
    fgets(buffer,11,ls);
    buffer[10] = '\0';
    buffer[9] = '\n';
    fputs(buffer,wc);
    printf("--stuff has just been witten to wc!\n");




if (wc == NULL){
    printf("ERROR 2");
    return 1;
}



   // sleep(5);


    return 0;
}
