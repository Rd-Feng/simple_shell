#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"
/**
 * _setenv -function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @params: parameters
*/
void _setenv(param_t *params)
{
	char *eqs = NULL, *tmp = NULL;
	char *name = params->args[1], *value = params->args[2];
	list_t *h = params->env_head;

	name = str_concat(name, "=");
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			tmp = h->str;
			eqs = _strchr(h->str, '=');
			*(eqs + 1) = '\0';
			free(tmp);
			h->str = str_concat(name, value);
			free(name);
			_printf("Environment variable set: %s\n",
				h->str);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	tmp = name;
	name = str_concat(name, value);
	free(tmp);
	params->env_head = add_node(&(params->env_head), name);
	_printf("New environment variable set: %s\n", params->env_head->str);
	params->status = 0;
}
