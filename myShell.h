#ifndef MY_SHELL_H
#define MY_SHELL_H
#include <stdio.h>

int process_string(char *, char ***, size_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(char **lineptr, size_t *n);

int _strcmp(char *, char *);

char *_strtok(char *, char *);

void run_command(char **args, char **env);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void print_env(char **);

void sigint_handler(int);
#endif
