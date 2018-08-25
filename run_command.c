#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myShell.h"
#include "lists.h"
#include "holberton.h"
/**
 * run_command - searches path dirs for command and execs
 * @params: parameters
 */
void run_command(param_t *params)
{
	char *exeFile = NULL, *tmp = NULL;
	pid_t pid;
	int sts = 0;

	params->status = 0;
	if (!_strcmp((params->args)[0], "env") && params->tokCount == 1)
	{
		print_env(params);
		params->status = 0;
		return;
	}
	if (!_strcmp((params->args)[0], "exit"))
	{
		/* TODO: break out to separate function  */
		if ((params->args)[1])
		{
			/* TODO: check if the argument is a valid number */
			sts = 0;
			tmp = (params->args)[1];
			while (tmp[sts] != '\0')
			{
				if ((sts == 0 && tmp[sts] == '-') || (tmp[sts] >= '0' && tmp[sts] <= '9'))
					sts++;
				else
				{
					_printf("exit: Illegal number: %s\n", tmp);
					return;
				}
			}
			sts = _atoi((params->args)[1]);
			free(params->buffer);
			free(params->args);
			free_list(params->env_head);
			free(params);
		}
		exit(sts);
	}
	if (!_strcmp((params->args)[0], "setenv") && params->tokCount == 3)
	{
		tmp = _setenv(params, (params->args)[1], (params->args)[2]);
		_printf("New environment set: %s\n", tmp);
		params->status = 0;
		return;
	}
	exeFile = get_file(params);
	if (!exeFile)
	{
		params->status = NOT_FOUND;
		_printf("%s: %d: %s: not found\n",
			params->argv[0], params->inputCount,
			params->args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
		exit(98);
	else if (pid == 0)
	{
		execve(exeFile, params->args, NULL);
	}
	else
	{
		wait(NULL);
	}
}
