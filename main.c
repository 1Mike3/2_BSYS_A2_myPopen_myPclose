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



    char buffer[11];
  //  fgets(buffer,11,ls);
  buffer[0] = 'H';
    buffer[1] = 'e';
    buffer[2] = 'l';
    buffer[3] = 'l';
    buffer[4] = 'o';
    buffer[5] = ' ';
    buffer[6] = 'W';
    buffer[7] = 'o';
    buffer[8] = 'r';
    buffer[9] = 'l';
    buffer[10] = '\0';
    buffer[9] = '\n';
    fputs(buffer,wc);
    printf("--stuff has just been witten to wc!\n");




if (wc == NULL){
    printf("ERROR 2");
    return 1;
}


    mypclose(ls);
    mypclose(wc);
   // sleep(5);


    return 0;
}
