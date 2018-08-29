#include <unistd.h>
#include "myShell.h"
#include "holberton.h"
#define BUFFER_SIZE 4096

/**
 * _getline - fetches a line of chars from stdin
 * @params: parameters
 *
 * Return: number of char read
 */

int _getline(param_t *params)
{
	static char line[BUFFER_SIZE];
	char *writeHead = line, *linePtr = line;
	unsigned int len, i;

	do {
		len = read(0, writeHead, BUFFER_SIZE);
		if (len == 0)
			break;
		writeHead += len;
	} while (*(writeHead - 1) != '\n');

	for (i = 0; linePtr != writeHead; i++, linePtr++)
		params->buffer[i] = *linePtr;
	if (len == 0)
		return (-1);
	return (i);
}
