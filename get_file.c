#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"
#include "myShell.h"
#include "lists.h"
/**
 * get_file - get correct path to a command file
 * @params: parameters
 *
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
char *get_file(param_t *params)
{
	char *path = _getenv("PATH", params);
	char *exePath = NULL, *exeArg = NULL, *tmp = NULL;

	if (!path)
		return (NULL);
	if (access(params->args[0], F_OK) == 0)
	{
		free(path);
		return (_strdup(params->args[0]));
	}
	exePath = _strtok(path, ":");
	while (exePath)
	{
		tmp = exeArg;
		exeArg = str_concat(exePath, "/");
		free(tmp);
		tmp = exeArg;
		exeArg = str_concat(exeArg, params->args[0]);
		free(tmp);
		if (access(exeArg, F_OK) == 0)
		{
			free(path);
			return (exeArg);
		}
		exePath = _strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
