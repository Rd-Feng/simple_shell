#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"
/*
 * setenv -function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @name: string to search env for
 * @value: val to set our env
 * @overwrite: bool to tell us to overwrite exisitng value;
 * Return: a pointer to the corresponding value string.
*/
int _setenv(list_t **env, char *name, char *value)
{
	char *eqs = NULL;
	list_t *h;

	h = *env;
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
		add_node_end(env, name);
	}

	return (0);
}
