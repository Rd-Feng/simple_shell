#include <stdlib.h>
#include "shell.h"
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
	char *val, *tmp = NULL;
	unsigned int i = 0, j = 1;
	list_t *h = params->alias_head;

	while (name[i] && name[i] != '=')
		i++;
	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			tmp = _strchr(&name[i + 2], '\'');
			*tmp = '\0';
			val = _strdup(&name[i + 2]);
			if (!val)
			{
				write(STDERR_FILENO, "set alias malloc error\n", 18);
				exit(-1);
			}
			if (tmp[1] != '\0')
			{
				while (tmp[j] &&
					(tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n'))
					j++;
				if (tmp[j] != '\0')
					set_alias(&tmp[j], params);
			}
		}
		else
		{
			_printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
	{
		val = _strdup(&name[i + 1]);
		if (!val)
		{
			write(STDERR_FILENO, "set alias malloc error\n", 18);
			exit(-1);
		}
	}
	name[i] = '\0'; /* set = to terminater */
	while (h)
	{
		if (!_strcmp(name, h->str))
		{
			free(h->val);
			h->val = val;
			h->valLen = _strlen(val);
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
