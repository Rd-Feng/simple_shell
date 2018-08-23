#ifndef MY_SHELL_H
#define MY_SHELL_H
#include <stdio.h>
#include "lists.h"
typedef struct param_s
{
	char **argv;
	char *buffer = NULL; /* input buffer */
	char *args = NULL; /* array of arguments */
	int argsCap = 10; /* num of arguments the args array can hold */
	int inputCount = 0; /* total line of linput */
	int tokCount = 0; /* num of tokens in a line input */
	int status = 0; /* run command return status */
	list_t *env_head = NULL; /* head node of environment vars */
} param_t;

/*int process_string(char *, char ***, size_t *);*/
int process_string(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

/*int _getline(char **lineptr, size_t *n);*/
int _getline(param_t *);

int _strcmp(char *, char *);

char *_strtok(char *str, char *delim);

/*int run_command(char ***args, char **env, int tokCount);*/
void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void print_env(param_t *);

void sigint_handler(int);

int _atoi(char *s);

#endif
