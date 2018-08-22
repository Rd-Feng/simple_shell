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
	unsigned int len, i;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	len = read(0, line, BUFFER_SIZE);
	_strcpy(*lineptr, line);
	for (i = 0; i < BUFFER_SIZE; i++)
		line[i] = 0;
	return (len);
}
