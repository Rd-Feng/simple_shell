#include "holberton.h"
#include <stdlib.h>

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int head, tail;
	int len;
	char tmp;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (len = 0; s[len] != '\0'; len++)
		;
	head = 0;
	tail = len - 1;
	while (head < tail)
	{
		tmp = *(s + head);
		*(s + head) = *(s + tail);
		*(s + tail) = tmp;
		head++;
		tail--;
	}
}

/**
 * get_rev - reverse a string
 * @s: string
 * Return: string reversed
 */
char *get_rev(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
	{
		return (NULL);
	}
	if (s)
	{
		rev_string(ptr);
	}
	return (ptr);
}

/**
 * rot13 - encodes a string using rot13
 * @s: string to be encoded
 *
 * Return: pointer to encrypted string
 */
char *rot13(char *s)
{
	char *ptr;
	int i;
	char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
			'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char r[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
			'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
	for (ptr = s; *ptr != '\0'; ptr++)
	{
		for (i = 0; i < 52; i++)
		{
			if (*ptr == c[i])
			{
				*ptr = r[i];
				break;
			}
		}
	}
	return (s);
}

/**
 * get_rot13 - get rot13
 * @s: string
 * Return: ptr to string
 */
char *get_rot13(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
		return (NULL);
	if (s)
	{
		rot13(ptr);
	}
	return (ptr);
}
