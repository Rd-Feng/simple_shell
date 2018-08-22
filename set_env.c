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

int _setenv(char *name, char *value, int overwrite)
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
				*(eqs + 1) = '\0';
			environ[i] = str_concat(environ[i], value);			
		}
		i++;
	}
	
	return (0);
}