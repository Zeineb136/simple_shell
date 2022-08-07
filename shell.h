#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>

char *standard_input(FILE* fp, size_t size);
void _ls();
char *read_standard_input(void);
void shell_loop(void);
#endif
