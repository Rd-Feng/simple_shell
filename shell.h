#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#define NULL_PTR -1
#define WRONG_SPECIFIER -2


/**
 * struct list_s - singly linked list
 * @str: key string - (malloc'ed string)
 * @len: length of the key string
 * @val: value string
 * @valLen: length value string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

/**
 * struct param_s - structure used to hold all shell variables needed
 * @argv: command line argument from main function
 * @buffer: input buffer
 * @args: array of arguments
 * @nextCommand: the next command to process
 * @argsCap: num of arguments the args array can hold
 * @lineCount: total line of input
 * @tokCount: num of tokens in a line input
 * @status: run command return status
 * @env_head: singly linked list of environment vars
 * @alias_head: singly linked list of aliases
 * Description: This structures hold all variables that passed into
 * other functions.
 */
typedef struct param_s
{
	char **argv;
	char *buffer;
	char **args;
	char *nextCommand;
	unsigned int argsCap;
	unsigned int lineCount;
	unsigned int tokCount;
	int status;
	list_t *env_head;
	list_t *alias_head;
} param_t;

/**
 * struct op - a buildin function
 * @name: buildin name
 * @func: pointer to buildin function
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

int process_string(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

char *_strtok(char *str, char *delim, char **savePtr);

void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void _printenv(param_t *);

void sigint_handler(int);

int _atoi(char *s);

char *_getenv(char *name, param_t *params);

void _setenv(param_t *params);

void _unsetenv(param_t *params);

char *get_file(param_t *params);

void (*get_buildin(param_t *params))(param_t *);

void _myExit(param_t *params);

void _cd(param_t *params);

void _alias(param_t *params);

void set_alias(char *name, param_t *params);

void print_alias(char *name, param_t *params);

void print_all_aliases(param_t *params);

void print_list_env(list_t *);

void print_list_alias(list_t *);

void free_params(param_t *params);

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);

/**
 * get_char - put a character into a memory block allocated using malloc
 * The allocated memory should has two bytes: the character, and the
 * terminating null byte.
 *
 * @c: character
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_char(char c);

/**
 * get_string - put a string into a memory block allocated using malloc
 * @s: string
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_string(char *s);

/**
 * put_number - put an integer into a block of memory
 * @n: integer
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_number(int n);

/**
 * print_arg - put one passed in parameter into a block of memory
 * @type: type of the parameter
 *
 * Return: pointer to the memory block, NULL if error
 */
char *get_arg(char type, ...);

/**
 * get_binary - converts an unsigned int to binary
 * @n: integer
 *
 * Return: pointer to binary
 */
char *get_binary(unsigned int n);

/**
 * get_rev - reverse a string
 * @s: string
 * Return: string reversed
 */
char *get_rev(char *s);

/**
 * get_rot13 - rot13 as a string
 * @s: string
 * Return: rot13
 */
char *get_rot13(char *s);

char *str_concat(char *, char *);

char *string_nconcat(char *, char *, unsigned int);

int _strlen(char *);

int _printf(const char *, ...);

char *_strchr(char *s, char c);

#endif
