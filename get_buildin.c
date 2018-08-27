#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myShell.h"
#include "lists.h"
#include "holberton.h"
/**
 * struct op - a buildin function
 * @name: buildin name
 * @func: pointer to buildin function
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;
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
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
