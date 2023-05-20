//
// Created by michi on 5/18/23.
//

#include "mypopen.h"
#include <unistd.h>
#include "definitions.h"

// set to 1 for debug information
#define DEBUG_MYPOPEN 0

FILE *mypopen(const char *command, const char *type) {

    int fd[2];
    int pid;



#pragma region debug
#if DEBUG_MYPOPEN
    static int callcounter = 0;
#endif
#pragma endregion debug




    if( pipe(fd) == -1){
#pragma region debug
#if DEBUG_MYPOPEN
        callcounter++;
#endif
#pragma endregion debug

        printf("ERROR pipe \n");
        return NULL;
    }
#pragma region debug
#if DEBUG_MYPOPEN
    printf("PP pipe created process: %i\n", callcounter);
    printf("PP pipe created read end: %i\n", fd[0] );
    printf("PP pipe created write end: %i\n", fd[1]);
#endif
#pragma endregion debug


    pid = fork();



    if (pid == -1) {
        printf("ERROR fork \n");

#pragma region debug
#if DEBUG_MYPOPEN
        callcounter++;
#endif
#pragma endregion debug

        return NULL;
    }

//PARENT
    if (pid PARENT) {
#pragma region debug
#if DEBUG_MYPOPEN
        pid_t newPid = getpid();
        printf("+I am the PARENT Process on call %i\n", callcounter);
        printf("+My PID is %i \n", newPid);

#endif
#pragma endregion debug

        if (type[0] == 'w') {
            close(fd[FD_READ]);

#pragma region debug
#if DEBUG_MYPOPEN
            callcounter++;
#endif
#pragma endregion debug

            FILE *opened = fdopen(fd[FD_WRITE], WRITE);

#pragma region debug
#if DEBUG_MYPOPEN
            printf("´´´w returned the pointer\n");
            perror("fdopen w:");
#endif
#pragma endregion debug

            return opened;
        }


    if (type[0] == 'r') {
       close(fd[FD_WRITE]);

#pragma region debug
#if DEBUG_MYPOPEN
        callcounter++;
#endif
#pragma endregion debug

        FILE *opened = fdopen(fd[FD_READ], READ);
#pragma region debug
#if DEBUG_MYPOPEN
        perror("fdopen r:");
#endif
#pragma endregion debug
        return opened;
    }
} // if pid > 0




    //CHILD
    if (pid CHILD) {
#pragma region debug
#if DEBUG_MYPOPEN

        pid_t newPid = getpid();
        printf("#I am the CHILD Process on call %i\n", callcounter);
        printf("#My PID is %i \n",newPid);

#endif
#pragma endregion debug
        if(type[FD_READ] == 'w'){

            char buffer2[1024];

            close(fd[FD_WRITE]);
#pragma region debug
#if DEBUG_MYPOPEN
            printf("EE1 fd0 is %i\n\n",fd[0]);
            printf("EE1 stdin is %i\n\n",STDIN_FILENO);
#endif
#pragma endregion debug

            dup2(fd[FD_READ],STDIN_FILENO);

#pragma region debug
#if DEBUG_MYPOPEN
            perror("dup2 w:");
            printf("EE2 fd0 is %i\n\n",fd[0]);
            printf("EE2 stdin is %i\n\n",STDIN_FILENO);
#endif
#pragma endregion debug

            close(fd[FD_READ]);
#pragma region debug
#if DEBUG_MYPOPEN
            printf("EE3 fd0 is %i\n\n",fd[0]);
            printf("EE3 stdin is %i\n\n",STDIN_FILENO);
#endif
#pragma endregion debug



            execl("/bin/sh", "sh", "-c", command, NULL);

            //old for loop to read out debug information
            /*
            for (int i = 0; i < 5; ++i) {
                scanf("%s",buffer2);
                printf("!!!!! buffer: %s\n\n",buffer2);
            }
*/


#pragma region debug
#if DEBUG_MYPOPEN
            printf("\nEE i am now echo\n");
            printf("EE my stdin is %i\n\n",STDIN_FILENO);
#endif
#pragma endregion debug




            exit(EXIT_FAILURE);
    } // end w part child process


        if(type[0] == 'r'){
            close(fd[FD_READ]);
            dup2(fd[FD_WRITE],STDOUT_FILENO);
            close(fd[FD_WRITE]);

            //write 10 chars into the pipe
          //  write(STDOUT_FILENO, "1234567890", 10);
        //  execlp("bin/sh", "-c",command, NULL);
            execl("/bin/sh", "sh", "-c", command, NULL);
exit(EXIT_FAILURE);
        }


}

#pragma region debug
#if DEBUG_MYPOPEN
    callcounter++;
#endif
#pragma endregion debug

    return NULL;
}