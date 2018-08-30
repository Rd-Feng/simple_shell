#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "holberton.h"
/**
 * get_builtin - get buildin function
 * @params: parameters
 *
 * Return: pointer to buildin function. NULL if not found
 */
void (*get_builtin(param_t *params))(param_t *)
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
