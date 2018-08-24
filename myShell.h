#ifndef MY_SHELL_H
#define MY_SHELL_H
#include <stdio.h>
#include "lists.h"
#define CMD_NOT_RUN 1
/**
 * struct param_s - structure used to hold all shell variables needed
 * @argv: command line argument from main function
 * @buffer: input buffer
 * @args: array of arguments
 * @argsCap: num of arguments the args array can hold
 * @inputCount: total line of input
 * @tokCount: num of tokens in a line input
 * @status: run command return status
 * @env_head: singly linked list of environment vars
 *
 * Description: This structures hold all variables that passed into
 * other functions.
 */
typedef struct param_s
{
	char **argv;
	char *buffer;
	char **args;
	unsigned int argsCap;
	unsigned int inputCount;
	unsigned int tokCount;
	int status;
	list_t *env_head;
} param_t;

int process_string(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

int _strcmp(char *, char *);

char *_strtok(char *str, char *delim);

void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void print_env(param_t *);

void sigint_handler(int);

int _atoi(char *s);

char *_getenv(char *name, param_t *params);
#endif
