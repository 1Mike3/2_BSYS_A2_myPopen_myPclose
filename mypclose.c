//
// Created by michi on 5/18/23.
//

#include "mypclose.h"


#define DEBUG_MYPCLOSE 0

pid_t mypclose(FILE * file){

    static int i = 0;

    //check if the filestream is NULL before performing any operations
    if (file == NULL) {
        fprintf(stderr, "ERROR: stream is NULL!\n");
        return -1;
    }

    //close the filestream
    if (-1 == fclose(file)) {
        fprintf(stderr, "ERROR: fclose failed!\n");
        return -1;
    }


    //get the file descriptor from the filestream
    int fd = fileno(file);

#pragma region debug
#if DEBUG_MYPCLOSE
    printf("CLOSE: waiting child to finish [%i] \n", i);
#endif
#pragma endregion debug
    //only for debugging
    //i++;

    //waiting for the specific process to finish
  pid_t retPid = waitpid(fd,NULL,0); //wait for child to finish
    return retPid;
#pragma region debug
#if DEBUG_MYPCLOSE
    printf("CLOSE: child finished [%i]\n", i);
#endif
#pragma endregion debug

    //return 0 if you got until here
    return -1;
}