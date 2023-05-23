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
void handler(int);
char *_strcpy(char *, char *);
void _puts(char *str);
int _putchar(char c);
char *get_input(void);
int count_words(char *data);
int count_char(char *str, char target);
char *path_check(char *ip);
char **parse_input(char *, char *, int);
char  *str_concat(char *s1, char *s2);
#endif
