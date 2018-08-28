#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"




void _alias(param_t * params)
{
	unsigned int i;
	/**
	Usage: alias [name[='value'] ...]
	alias: Prints a list of all aliases, one per line, in the form name='value'
	count commands
	if 1 print all alias
	alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
	if 2 or more and no = print those names
	alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
	if 2 or more and = set alias
	*/
	if (params->tokCount == 1)
	{
		print_all_alias(params);
		return;
	}
	for (i = 1; i < params->tokCount; i++)
	{
		if (_strchr(params->args[i], '='))
			set_alias(params->args[i], params);
		else
			get_alias(params->args[i], params);
	}
}

/**
 * _setenv - function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @params: parameters
*/
void set_alias(char *name, param_t *params)
{
	char *tmp = NULL;
	unsigned int i = 0;
	list_t *h = params->alias_head;

	while(name[i] != '=')
		i++;

	while (h)
	{
		if (_strcmp_n(name, h->str, i) == 0) /* env var exists */
		{
			tmp = h->str;
			h->str = _strdup(name);
			if (h->str)
			{
				free(tmp);
				params->status = 0;
				return;
			}
			else
			{
				h->str = tmp;
				params->status = -1;
				return;
			}


		}
		h = h->next;
	}
	/* env var DNE */
	params->alias_head = add_node(&(params->alias_head), name);
	params->status = 0;
}

/**
 * _getenv - get environment variable
 * @name: variable name
 * @params: parameters
 *
 * Return: value if found, NULL otherwise
 */
void get_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, len - 1) == 0)
			printf("%s\n", ptr->str);
		ptr = ptr->next;
	}
	params->status = 0;
	return;
}

/**
 * _printenv - print environment variables
 * @params: parameters
 */
void print_all_alias(param_t *params)
{
	print_list_reverse(params->alias_head);
	params->status = 0;
	return;
}
