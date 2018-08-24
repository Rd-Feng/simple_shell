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
	unsigned int len = 0, i, found;
	list_t *ptr = params->env_head;

	len = _strlen(name);
	while (ptr)
	{
		for (i = 0, found = 1; i < len; i++)
		{
			if (name[i] != (ptr->str)[i])
			{
				found = 0;
				break;
			}
		}
		if ((ptr->str)[i] != '=')
			found = 0;
		if (found)
			return (_strdup(ptr->str + len + 1));
		ptr = ptr->next;
	}
	return (NULL);
}
