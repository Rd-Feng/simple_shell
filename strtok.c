#include <stdlib.h>
#include "myShell.h"
#include "holberton.h"
/**
 * isDelim - check if a character is one of the delimiters
 * @c: character
 * @delim: delimeters
 *
 * Return: 1 if it is a delimiter, 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok - strtok
 * @str: string to be passed
 * @delim: delimiters for tokens
 *
 * Return: next token found in string, NULL if not found
 */
char *_strtok(char *str, char *delim)
{
	static char *ptr, *modifier, *end;

	if (str != NULL)
	{
		ptr = str;
		modifier = str;
		end = str;
		while (*end)
			end++;
	}
	else
	{
		if (modifier == end)
			return (NULL);
		ptr = modifier + 1;
	}
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	while (*modifier && !isDelim(*modifier, delim))
		modifier++;
	*modifier = '\0';
	return (_strdup(ptr));
}
