#ifndef GUARD
#define GUARD

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

extern char **environ;
char **input(void);
int count_string(char *);
char **path(char **);
#endif
