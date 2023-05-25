#ifndef GUARD
#define GUARD

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

extern char **environ;
char *_strtok(char *, char *);
int _isspace(int);
void print_error(char *fi, char *token, int i);
int echeck(char *token, char *input, char *trick, int);
int env(char*, char*);
void print_number_in(int);
int _strcmp(char *, char *, int);
int _strlen(char *);
void handler(int);
char *_strcpy(char *, char *);
void _puts(char *str);
int _putchar(char c);
char *get_input(void);
int count_words(char *data);
int count_char(char *str, char target);
char *path_check(char *ip);
char **parse_input(char *input, char *fi, int line_count, int status);
char  *str_concat(char *s1, char *s2);
#endif

