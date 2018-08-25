#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "myShell.h"
#include "holberton.h" /* for _printf */
#define BUFFER_SIZE 1024
void init_param(param_t *, char **argv, char **env);
/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: Null terminated argument list
 * @env: Null terminated environment variables list
 *
 * Return: 0 on success
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	param_t *params = malloc(sizeof(param_t));
	int cond;
	unsigned int i;

	if (!params)
		exit(-1);
	signal(SIGINT, sigint_handler);
	init_param(params, argv, env);
	while (1)
	{
		for (i = 0; i < BUFFER_SIZE; i++)
			(params->buffer)[i] = 0;
		for (i = 0; i < params->argsCap; i++)
			(params->args)[i] = NULL;
		params->tokCount = 0;
		_printf("($) ");
		cond = _getline(params);
		params->inputCount++;
		if (cond == -1 || cond == 0)
			return (0);
		params->tokCount = process_string(params);
		if (params->tokCount == 0)
			continue;
		run_command(params);
	}
}
/**
 * init_param - initialize params
 * @params: params
 * @argv: command line argument
 * @env: environment variables
 */
void init_param(param_t *params, char **argv, char **env)
{
	int i;

	params->argv = argv;
	params->buffer = malloc(BUFFER_SIZE);
	if (!(params->buffer))
	{
		free(params);
		exit(-1);
	}
	params->args = malloc(sizeof(char *) * params->argsCap);
	if (!(params->args))
	{
		free(params->buffer);
		free(params);
		exit(-1);
	}
	params->argsCap = 10;
	params->inputCount = 0;
	params->tokCount = 0;
	params->status = 0;
	for (i = 0; env[i]; i++)
	{
		params->env_head = add_node(&(params->env_head), env[i]);
		if (!(params->env_head))
		{
			free(params->buffer);
			free(params->args);
			free_list(params->env_head);
			free(params);
			exit(-1);
		}
	}
}
