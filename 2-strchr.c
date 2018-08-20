#include "holberton.h"

/**
 * _strchr - locates a character in a string
 * @s: where to start looking
 * @c: values to find
 *
 * Return: pointer to begining of mem area
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}
