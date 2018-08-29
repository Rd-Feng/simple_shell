#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
#include "lists.h"

/**
 * _alias - alias utility builtin, call apropos func
 * @params: shell state
 * Return: void
*/
void _alias(param_t *params)
{
	unsigned int i;

	if (params->tokCount == 1)
	{
		print_all_aliases(params);
		return;
	}
	for (i = 1; i < params->tokCount; i++)
	{
		if (_strchr(params->args[i], '='))
			set_alias(params->args[i], params);
		else
			print_alias(params->args[i], params);
	}
}

/**
 * set_alias - function searches the alias list and sets to the corresponding
 * @name: key/value string.
 * @params: shell state
*/
void set_alias(char *name, param_t *params)
{
	char *val;
	unsigned int i = 0, len;
	list_t *h = params->alias_head;

	while (name[i] != '=')
		i++;
	len = _strlen(name);
	if (name[i + 1] == '\'' && name[len - 1] == '\'')
	{
		name[len - 1] = '\0';
		val = _strdup(&name[i + 2]);
	}
	else
	{
		val = _strdup(&name[i + 1]);
	}
	name[i] = '\0';

	while (h)
	{
		if (_strcmp_n(name, h->str, i) == 0)
		{
			free(h->val);
			h->val = _strdup(val);
			h->val_len = i;
			free(val);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* env var DNE */

	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}

/**
 * print_alias - searches the alias list and prints to the corresponding value
 * @name: variable name
 * @params: shell state
 *
 * Return: only print
 */
void print_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, len - 1) == 0)
			_printf("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_all_aliases - print all aliases
 * @params: shell state
 * Return: void print
 */
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}

/**
 * print_list_alias - print an alias formatted
 * @head: head node of list
 * Return: void print
 */
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}