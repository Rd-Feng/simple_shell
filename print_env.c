#include "holberton.h"
#include "lists.h"
#include "myShell.h"
/**
 * print_env - print environment variables
 * @params: parameters
 */
void print_env(param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr && ptr->str)
	{
		_printf("%s\n", ptr->str);
		ptr = ptr->next;
	}
}
