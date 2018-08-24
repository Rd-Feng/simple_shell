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
	char *path = NULL, *exePath = NULL, *exeArg = NULL, *tmp = NULL;
	pid_t pid;
	int status = 0;

	if (!_strcmp((params->args)[0], "env") && params->tokCount == 1)
	{
		print_env(params);
		params->status = 0;
		return;
	}
	if (!_strcmp((params->args)[0], "exit"))
	{
		if ((params->args)[1])
			/* TODO: check if the argument is a valid number */
			status = _atoi((params->args)[1]);
		/* TODO: free parameters */
		exit(status);
	}
	if (!_strcmp((params->args)[0], "setenv") && params->tokCount == 3)
	{
		/*_setenv(env, (*args)[1], (*args)[2]);*/
		params->status = 0;
		return;
	}
	pid = fork();
	if (pid < 0)
		exit(98);
	else if (pid == 0)
	{
		path = _getenv("PATH", params);
		if (!path)
			exit(-1);
		execve((params->args)[0], params->args, NULL);
		exePath = _strtok(path, ":");
		while (exePath)
		{
			tmp = exeArg;
			exeArg = str_concat(exePath, "/");
			free(tmp);
			tmp = exeArg;
			exeArg = str_concat(exeArg, (params->args)[0]);
			free(tmp);
			execve(exeArg, params->args, NULL);
			free(exeArg);
			exeArg = NULL;
			exePath = _strtok(NULL, ":");
		}
		/* TODO: free params */
		free(path);
		exit(98);
	}
	else
	{
		wait(&status);
		if (status)
			params->status = CMD_NOT_RUN;
	}
}
