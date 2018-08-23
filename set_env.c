#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"

/*
 * getenv -function searches the environment list to find the
 * environment variable name, and returns a pointer to the corresponding
 * value string.
 * @name: string to search env for
 * Return: a pointer to the corresponding value string.
*/
char *_get_env(char *name)
{
	extern char **environ;
	size_t i = 0;
	char *eqs;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		if (_strcmp(name, environ[i]) == 0)
		{
			eqs = _strchr(environ[i], '=');
			if (eqs)
				eqs += 1;
		}
		i++;
	}
	
	return (eqs);
}

/*
 * setenv -function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @name: string to search env for
 * @value: val to set our env
 * @overwrite: bool to tell us to overwrite exisitng value;
 * Return: a pointer to the corresponding value string.
*/
int _setenv(char **env, char *name, char *value)
{
	size_t i = 0;
	char *eqs = NULL;
	// char **newEnv = NULL;

	name = str_concat(name, "=");
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		if (_strcmp(name, env[i]) == 0)
		{
			eqs = _strchr(env[i], '=');
			if (eqs)
				*(eqs + 1) = '\0';
			env[i] = str_concat(env[i], value);			
		}
		i++;
	}
	if (!eqs)
	{
		// newEnv = malloc(8 * (i + 1));
		// if (!(newEnv))
		// {
		// 	_printf("malloc error\n");
		// 	exit(-1);
		// }
		// if (newEnv)
		// {
		// 	for (j = 0; j <= i; j++)
		// 		newEnv[j] = NULL;
		// 	for (j = 0; j < i; j++)
		// 	{
		// 		newEnv[j] = env[j];
		// 	}
		// 	// free(env);
		// 	&env = newEnv;
		// }
		*env = _realloc(env, i, i + 1);
		env[i] = str_concat(name, value);
	}
	
	return (0);
}
