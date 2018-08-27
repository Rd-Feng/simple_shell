#include "holberton.h"
#include "lists.h"
#include "myShell.h"
void print_list_reverse(list_t *);

/**
 * _printenv - print environment variables
 * @params: parameters
 */
void _printenv(param_t *params)
{
	print_list_reverse(params->env_head);
	params->status = 0;
}

/**
 * print_list_reverse - print a list in reverse order
 * @head: head of list
 */
void print_list_reverse(list_t *head)
{
	if (head)
	{
		print_list_reverse(head->next);
		if (head->str)
			_printf("%s\n", head->str);
	}
}
