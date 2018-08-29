#include <stdlib.h>
#include <limits.h>
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
 * _myExit - buildin exit function
 * @params: parameters
 */
void _myExit(param_t *params)
{
	int status = 0;
	unsigned int i;

	if (!params->args[1])
	{
		status = params->status;
		free(params->buffer);
		for (i = 0; i < params->argsCap; i++)
			free(params->args[i]);
		free(params->args);
		free(params->nextCommand);
		free_list(params->env_head);
		free_list(params->alias_head);
		free(params);
		exit(status);
	}
	if (validNum(params->args[1]))
	{
		status = _atoi((params->args)[1]);
		if (status == -1)
		{
			_printf("%s: %d: exit: Illegal number: %s\n",
				params->argv[0], params->lineCount, params->args[1]);
			return;
		}
		free(params->buffer);
		for (i = 0; i < params->argsCap; i++)
			free(params->args[i]);
		free(params->args);
		free_list(params->env_head);
		free_list(params->alias_head);
		free(params);
		exit(status);
	}
	else
	{
		_printf("%s: %d: exit: Illegal number: %s\n",
			params->argv[0], params->lineCount, params->args[1]);
	}
}
