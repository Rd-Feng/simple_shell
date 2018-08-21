#include <stdlib.h>
#include <unistd.h>
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

void run_command(char **args, char **env)
{
	char *path = _getenv("PATH", env);
	char *exePath = NULL;
	char *exeArg = NULL;
	char *tmp = NULL;

	if (!path)
		return;
	execve(args[0], args, NULL);/* see if a valid path is given */
	exePath = _strtok(path, ":");
	while (exePath)
	{
		tmp = exeArg;
		exeArg = str_concat(exePath, "/");
		free(tmp);
		tmp = exeArg;
		exeArg = str_concat(exeArg, args[0]);
		free(tmp);
		execve(exeArg, args, NULL);
		free(exeArg);
		exeArg = NULL;
		exePath = _strtok(NULL, ":");
	}
	free(path);
}
