#include "holberton.h"
#include "lists.h"
#include "myShell.h"

/**
 * _printenv - print environment variables
 * @params: parameters
 */
void _printenv(param_t *params)
{
	print_list_env(params->env_head);
	params->status = 0;
}

/**
 * print_list_env - print a list in reverse order
 * @head: head of list
 */
void print_list_env(list_t *head)
{
	if (head)
	{
		print_list_env(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}
