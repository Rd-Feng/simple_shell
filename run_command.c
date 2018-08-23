#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myShell.h"
#include "holberton.h"
/**
 * _getenv - get environment variable
 * @name: variable name
 * @env: environment variables
 * Return: variable value on success, NULL otherwise
 */
char *_getenv(char *name, char **env)
{
	unsigned int len = 0, i, found = 1;

	while (name[len])
		len++;
	while (*env)
	{
		for (i = 0, found = 1; i < len; i++)
		{
			if (name[i] != (*env)[i])
			{
				found = 0;
				break;
			}
		}
		if (found)
			return (_strdup(*env));
		env++;
	}
	return (NULL);
}

/**
 * run_command - searches path dirs for command and execs
 * @args: args to feed to execve
 * @env: environment variables
 * Return: status
 */
int run_command(char ***args, char **env, int tokCount)
{
	char *path = NULL, *exePath = NULL, *exeArg = NULL, *tmp = NULL;
	int status = 0;
	pid_t pid;
	static int inputCount = 0;

	inputCount++;
	if (!_strcmp((*args)[0], "env") && tokCount == 1)
	{
		print_env(env);
		return (0);
	}
	if (!_strcmp((*args)[0], "exit"))
	{
		if ((*args)[1])
			status = _atoi((*args)[1]);
		free(*args);
		exit(status);
	}
	if (!_strcmp((*args)[0], "setenv") && tokCount == 3)
	{
		_setenv(env, (*args)[1], (*args)[2]);
		return (0);
	}
	pid = fork();
	if (pid < 0)
		exit(98);
	else if (pid == 0)
	{
		path = _getenv("PATH", env);
		if (!path)
			exit(-1);
		execve((*args)[0], *args, NULL);
		exePath = _strtok(path, ":");
		while (exePath)
		{
			tmp = exeArg;
			exeArg = str_concat(exePath, "/");
			free(tmp);
			tmp = exeArg;
			exeArg = str_concat(exeArg, (*args)[0]);
			free(tmp);
			execve(exeArg, *args, NULL);
			free(exeArg);
			exeArg = NULL;
			exePath = _strtok(NULL, ":");
		}
		free(*args);
		free(path);
		exit(98);
	}
	else
	{
		wait(&status);
		return (status);
	}
}
