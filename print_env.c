#include "holberton.h"
/**
 * print_env - print environment variables
 * @env: env variables
 */
void print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		_printf("%s\n", env[i]);
}
