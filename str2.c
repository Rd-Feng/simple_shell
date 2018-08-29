#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "myShell.h"
#include "holberton.h"
/**
 * _strcpy - copies a string to anther memory adress
 * @src: pointer to the source string
 * @dest: pointer to the dest address
 *
 * Return: pointer to the dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}

/**
 * _strcmp_n - compares n bytes of two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to comp
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}


/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: n the value of the first number in the st0ring
 */
int _atoi(char *s)
{
	int i, n;

	i = 0;
	n = 0;

	while (s[i] != '\0')
	{
		if (n > INT_MAX)
			return (-1);
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = n * 10 + (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;

	}
	return (n);
}
