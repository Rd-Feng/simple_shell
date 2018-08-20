#include <stdlib.h>
#include <string.h>
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
	token = strtok(tempBuffer, " \n");
	tokCount++;
	while (token)
	{
		token = strtok(NULL, " \n");
		tokCount++;
	}
	tokCount++; /* null terminator string */
	args = malloc(sizeof(*args) * tokCount);
	args[i++] = strtok(bufPtr, " \n");
	while (i < tokCount - 1)
		args[i++] = strtok(NULL, " \n");
	args[i] = NULL;
	free(tempBuffer);
	return (args);
}
