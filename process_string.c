#include <stdlib.h>
#include <unistd.h>
#include "myShell.h"
#include <stdio.h>
/**
 * process_string - process the next command into string tokens
 * @params: parameters
 *
 * Return: number of tokens
 */
int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;

	token = _strtok(params->nextCommand, " \n\t", &state);
	(params->args)[(params->tokCount)++] = token;
	while (token)
	{
		token = _strtok(params->nextCommand, " \n\t", &state);
		(params->args)[(params->tokCount)++] = token;
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
						params->argsCap - 10,
						params->argsCap);
			if (!(params->args))
			{
				write(1, "realloc error\n", 14);
				exit(-1);
			}
		}
	}
	return (params->tokCount - 1);
}
