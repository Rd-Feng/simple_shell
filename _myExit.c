#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
/**
 * validNum - check if string is a valid number
 * @s: string
 *
 * Return: 0 if false, 1 otherwise
 */
int validNum(char *s)
{
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}
/**
 * _exit - buildin exit function
 * @params: parameters
 */
void _myExit(param_t *params)
{
	int status = 0;

	if (!params->args[1])
	{
		free(params->buffer);
		free(params->args);
		free_list(params->env_head);
		free(params);
		exit(0);
	}
	if (validNum(params->args[1]))
	{
		status = _atoi((params->args)[1]);
		free(params->buffer);
		free(params->args);
		free_list(params->env_head);
		free(params);
		exit (status);
	}
	else
	{
		_printf("%s: %d: exit: Illegal number: %s\n",
			params->argv[0], params->inputCount, params->args[1]);
	}
}
