#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"

/**
 * _setenv - function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @params: parameters
*/
void _setenv(param_t *params)
{
	char *tmp = NULL;
	char *name = params->args[1], *value = params->args[2];
	list_t *h = params->env_head;

	if (params->tokCount != 3)
	{
		write(STDERR_FILENO,
		      "Usage: setenv VARIABLE VALUE\n", 29);
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			tmp = h->val;
			free(tmp);
			h->val = _strdup(value);
			h->val_len = _strlen(value);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* env var DNE */
	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}


/**
 * _unsetenv - function searches the environment list to find the
 * environment variable name and removes it.
 * @params: parameters
*/
void _unsetenv(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL, *h = params->env_head;

	if (params->tokCount != 2)
	{
		write(STDERR_FILENO,
		      "Usage: unsetenv VARIABLE\n", 25);
		return;
	}
	name = str_concat(name, "=");
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			if (h == params->env_head)
				params->env_head = h->next;
			else if (prev)
				prev->next = h->next;
			free(h->str);
			free(h->val);
			free(h);
			free(name);
			_printf("Environment variable unset: %s\n",	params->args[1]);
			params->status = 0;
			return;
		}
		prev = h;
		h = h->next;
	}
	_printf("Environment not found: %s\n", params->args[1]);
	params->status = 0;
}
