//
// Created by michi on 5/18/23.
//

#include "mypopen.h"
#include <unistd.h>


#define DEBUG_MYPOPEN 1

FILE *mypopen(const char *command, const char *type) {

    int fd[2];
    int pid;
    static int callcounter = 0;


    if( pipe(fd) == -1){
        callcounter++;
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
        callcounter++;
        return NULL;
    }

//PARENT
    if (pid > 0) {
#pragma region debug
#if DEBUG_MYPOPEN
        pid_t newPid = getpid();
        printf("+I am the PARENT Process on call %i\n", callcounter);
        printf("+My PID is %i \n", newPid);

#endif
#pragma endregion debug

        if (type[0] == 'w') {
            close(fd[0]);
            callcounter++;
            FILE *opened = fdopen(fd[1], "w");
            printf("´´´w returned the pointer\n");
            perror("fdopen w:");
            return opened;
        }


    if (type[0] == 'r') {
       close(fd[1]);
        callcounter++;
        FILE *opened = fdopen(fd[0], "r");
        perror("fdopen r:");
        return opened;
    }
} // if pid > 0




    //CHILD
    if (pid == 0){
#pragma region debug
#if DEBUG_MYPOPEN
        pid_t newPid = getpid();
        printf("#I am the CHILD Process on call %i\n", callcounter);
        printf("#My PID is %i \n",newPid);

#endif
#pragma endregion debug
        if(type[0] == 'w'){

            char buffer2[1024];

            close(fd[1]);

            printf("EE1 fd0 is %i\n\n",fd[0]);
            printf("EE1 stdin is %i\n\n",STDIN_FILENO);
            dup2(fd[0],STDIN_FILENO);
            perror("dup2 w:");
            printf("EE2 fd0 is %i\n\n",fd[0]);
            printf("EE2 stdin is %i\n\n",STDIN_FILENO);
            close(fd[0]);
            printf("EE3 fd0 is %i\n\n",fd[0]);
            printf("EE3 stdin is %i\n\n",STDIN_FILENO);


            execl("/bin/sh", "sh", "-c", command, NULL);

            for (int i = 0; i < 5; ++i) {
                scanf("%s",buffer2);
                printf("!!!!! buffer: %s\n\n",buffer2);
            }




            printf("\nEE i am now echo\n");
            printf("EE my stdin is %i\n\n",STDIN_FILENO);



            execl("/bin/sh", "echo", NULL, NULL);




               // printf("i should be writing something\n\n");
               // fscanf(stdin,"%s",buffer2);
               //FILE * opened = fdopen(STDIN_FILENO,"r");
               // buffer2[0] = fgetc(opened);

             //  printf("buffer: %s\n\n",buffer2);





//execlp("bin/sh", "-c",command, NULL);
            exit(EXIT_FAILURE);
    } // end w part child process

        if(type[0] == 'r'){
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]);

            //write 10 chars into the pipe
          //  write(STDOUT_FILENO, "1234567890", 10);
        //  execlp("bin/sh", "-c",command, NULL);
            execl("/bin/sh", "sh", "-c", command, NULL);
exit(EXIT_FAILURE);
        }


}

    callcounter++;
    return NULL;
}