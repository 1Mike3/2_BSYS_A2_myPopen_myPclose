//
// Created by michi on 5/18/23.
//

#include "mypclose.h"
#include "unistd.h"
#include "sys/wait.h"

#define DEBUG_MYPCLOSE 0

short mypclose(FILE * file){

    static int i = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: stream is NULL\nEID = %d\n", 123);
        return -1;
    }

    fclose(file);

    int fd = fileno(file);

#pragma region debug
#if DEBUG_MYPCLOSE
    printf("CLOSE: waiting child to finish [%i] \n", i);
#endif
#pragma endregion debug

    i++;
    waitpid(fd,NULL,0); //wait for child to finish
#pragma region debug
#if DEBUG_MYPCLOSE
    printf("CLOSE: child finished [%i]\n", i);
#endif
#pragma endregion debug




    return 0;
}