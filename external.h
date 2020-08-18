#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _putchar(char c);
void _puts(char *str);
int fid_div(char *s);
int _strlen(const char *s);
char *_strdup(char const *str);
void stoarr(char *str, char **tab);

#endif
