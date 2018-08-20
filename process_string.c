#include <stdlib.h>
#include "myShell.h"
/**
 * process_string - process a line of command into string tokens
 *
 * @bufPtr: line of command
 *
 * Return: array of string tokens, NULL on error
 */
char **process_string(char *bufPtr)
{
	char **args = NULL, *token = NULL;
	char *tempBuffer = _strdup(bufPtr);
	unsigned int tokCount = 0, i = 0;

	if (!tempBuffer)
		return (NULL);
	token = _strtok(tempBuffer, " \n");
	tokCount++;
	while (token)
	{
		token = _strtok(NULL, " \n");
		tokCount++;
	}
	tokCount++; /* null terminator string */
	args = malloc(sizeof(*args) * tokCount);
	args[i++] = _strtok(bufPtr, " \n");
	while (i < tokCount - 1)
		args[i++] = _strtok(NULL, " \n");
	args[i] = NULL;
	free(tempBuffer);
	return (args);
}
