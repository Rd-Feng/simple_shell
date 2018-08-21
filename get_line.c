#include <unistd.h>
#include "myShell.h"
#include "holberton.h"
#define BUFFER_SIZE 1024

/**
 * _get_line - fetches a line of chars from stdin
 * @lineptr: ptr to a buffer to store the line
 * @n: size of the buffer
 *
 * Return: pointer to begining of mem area
 */

int _getline(char **lineptr, size_t *n)
{
	static char line[BUFFER_SIZE];
	char *ptr;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	read(0, line, BUFFER_SIZE);
	/* iterate through line looking for \n */
	ptr = _strchr(line, '\n');
	if (ptr)
		*ptr = '\0';

	_strcpy(*lineptr, line);
	return (len);
}
