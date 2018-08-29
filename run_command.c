#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "myShell.h"
#include "lists.h"
#include "holberton.h"
/**
 * run_command - searches path dirs for command and execs
 * @params: parameters
 */
void run_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	buildin = get_buildin(params);
	if (buildin)
	{
		buildin(params);
		return;
	}
	exeFile = get_file(params);
	if (!exeFile)
	{
		params->status = NOT_FOUND;
		_printf("%s: %d: %s: not found\n",
			params->argv[0], params->lineCount,
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
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(exeFile);
	}
}
