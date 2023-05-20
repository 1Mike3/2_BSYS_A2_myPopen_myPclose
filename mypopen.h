//
// Created by michi on 5/18/23.
//

#ifndef MYPOPEN_MYPCLOSE_MYPOPEN_H
#define MYPOPEN_MYPCLOSE_MYPOPEN_H

#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

FILE *mypopen(const char *command, const char *type);

#endif //MYPOPEN_MYPCLOSE_MYPOPEN_H
