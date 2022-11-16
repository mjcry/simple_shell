#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>

extern char **environ;

/* Functions needed */
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);

/* Functions for shell */
void loop(void);
char *readline(void);
char **split(char *line, char *limit);
int exec(char **args);
char *_getenv(char *name);
int num_built(void);
int exit_bn(__attribute__((__unused__)));
int cd_bn(char **args);
int env_bn(__attribute__((__unused__)));
int exec_built(char **args);
char **get_path(char **args);
void signalHandler(int control);

#endif
