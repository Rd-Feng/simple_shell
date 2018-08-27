#include <unistd.h>
#include "myShell.h"
#include "holberton.h"
#define BUFFER_SIZE 1024

/**
 * _getline - fetches a line of chars from stdin
 * @params: parameters
 *
 * Return: number of char read
 */

int _getline(param_t *params)
{
	static char line[BUFFER_SIZE];
	unsigned int len, i;

	len = read(0, line, BUFFER_SIZE);
	_strcpy(params->buffer, line);
	for (i = 0; i < BUFFER_SIZE; i++)
		line[i] = 0;
	return (len);
}
