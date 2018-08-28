#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myShell.h"
#include "lists.h"
#include "holberton.h"
/**
 * get_buildin - get buildin function
 * @params: parameters
 *
 * Return: pointer to buildin function. NULL if not found
 */
void (*get_buildin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp_n(params->args[0], op->name, _strlen(op->name)))
			return (op->func);
		op++;
	}
	return (NULL);
}
