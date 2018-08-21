#include <stdlib.h>
#include <unistd.h>
#include "myShell.h"
#include <stdio.h>
/**
 * process_string - process a line of command into string tokens
 *
 * @bufPtr: line of command
 * @args: address of arg array
 * @count: number of tokens args can hold
 */
void process_string(char *bufPtr, char ***args, size_t *count)
{
	char *token = NULL;
	unsigned int tokCount = 0;

	token = _strtok(bufPtr, " \n\t");
	(*args)[tokCount++] = token;
	while (token)
	{
		token = _strtok(NULL, " \n\t");
		(*args)[tokCount++] = token;
		if (tokCount == *count)
		{
			(*count) += 10;
			*args = _realloc(*args, (*count) - 10, *count);
			if (!(*args))
			{
				write(1, "realloc error\n", 14);
				exit(-1);
			}
		}
	}
}
