#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"
/**
 * _setenv -function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @env: environment variables
 * @name: string to search env for
 * @value: val to set our env
 * Return: a pointer to the corresponding value string.
*/
int _setenv(param_t *params, char *name, char *value)
{
	char *eqs = NULL;
	list_t *h = params->env_head;

	name = str_concat(name, "=");
	while (h->next != NULL)
	{
		if (_strcmp(name, h->str) == 0)
		{
			eqs = _strchr(h->str, '=');
			if (eqs)
				*(eqs + 1) = '\0';
			h->str = str_concat(h->str, value);
		}
		h = h->next;
	}
	if (!eqs)
	{
		name = str_concat(name, value);
		// not working, there's something wrong with the tail node, causes free errors
		// add_node_end(&(params->env_head), name); 
		add_node(&(params->env_head), name);
	}

	return (0);
}
