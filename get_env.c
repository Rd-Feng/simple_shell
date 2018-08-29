#include "holberton.h"
#include "lists.h"
#include "myShell.h"
#include <stdlib.h>
/**
 * _getenv - get environment variable
 * @name: variable name
 * @params: parameters
 *
 * Return: value if found, NULL otherwise
 */
char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->val));
		ptr = ptr->next;
	}
	return (NULL);
}
