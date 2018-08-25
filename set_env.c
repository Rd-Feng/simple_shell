#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"
/**
 * _setenv -function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @params: parameters
 * @name: string to search env for
 * @value: val to set our env
 * Return: a pointer to the corresponding value string.
*/
char *_setenv(param_t *params, char *name, char *value)
{
	char *eqs = NULL, *tmp = NULL;
	list_t *h = params->env_head;

	name = str_concat(name, "=");
	while (h->str)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			tmp = h->str;
			eqs = _strchr(h->str, '=');
			*(eqs + 1) = '\0';
			free(tmp);
			h->str = str_concat(name, value);
			free(name);
			return (h->str);
		}
		h = h->next;
	}
	tmp = name;
	name = str_concat(name, value);
	free(tmp);
	params->env_head = add_node(&(params->env_head), name);
	_printf("new env: %s\n", params->env_head->str);
	return (params->env_head->str);
}
