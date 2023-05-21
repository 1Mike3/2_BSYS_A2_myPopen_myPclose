//
// Created by michi on 5/18/23.
//

#ifndef MYPOPEN_MYPCLOSE_MYPCLOSE_H
#define MYPOPEN_MYPCLOSE_MYPCLOSE_H

#include "unistd.h"
#include "sys/wait.h"

#include "stdio.h"

/**
 *
 * @param file file pointer to the file stream to be closed
 * @return -1 on error, status of the child process on success
 */
pid_t mypclose(FILE * file) ;

#endif //MYPOPEN_MYPCLOSE_MYPCLOSE_H
