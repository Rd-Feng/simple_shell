#include <unistd.h>
#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
/**
 * _cd - cd builtin
 * @params: parameters
 */
void _cd(param_t *params)
{
	char *target = NULL, cwd[1024];
	char **tmpArgs = NULL, **originArgs = NULL;
	int i;

	if (params->tokCount == 1)
		target = _getenv("HOME", params);
	else if (!_strcmp(params->args[1], "-"))
		target = _getenv("OLDPWD", params);
	else
		target = _strdup(params->args[1]);
	i = chdir(target);
	if (i)
	{
		_printf("%s: %d: cd: can't cd to %s",
			params->argv[0], params->inputCount, target);
		free(target);
		return;
	}
	free(target);
	tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
		exit(-1);
	originArgs = params->args;
	params->args = tmpArgs;
	params->tokCount = 3;
	/* set OLDPWD to the current PWD */
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = _getenv("PWD", params);
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);
	/* set PWD to the target wd */
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("PWD");
	tmpArgs[2] = _strdup(getcwd(cwd, 1024));
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);
	free(tmpArgs);
	/* reset params */
	params->args = originArgs;
}
