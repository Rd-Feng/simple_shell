#include <unistd.h>
#include "myShell.h"
#include "holberton.h"
#define BUFFER_SIZE 1024

/**
 * _getline - fetches a line of chars from stdin
 * @lineptr: ptr to a buffer to store the line
 * @n: size of the buffer
 *
 * Return: pointer to begining of mem area
 */

int _getline(char **lineptr, size_t *n)
{
	static char line[BUFFER_SIZE];
	unsigned int len;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	read(0, line, BUFFER_SIZE);
	/* iterate through line looking for \n */

	len = _strlen(line);
	_strcpy(*lineptr, line);
	return (len);
}
