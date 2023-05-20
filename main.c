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




// we consume the output of `ls` and feed it to `wc`
    char buf[1024];
    while (fgets(buf, sizeof(buf), ls) != NULL)
        fputs(buf, wc);
// once
   // printf("--stuff has just been witten to wc!\n");




if (wc == NULL){
    printf("ERROR 2");
    return 1;
}

// sleep(5);

    mypclose(ls);
    mypclose(wc);



    return 0;
}
