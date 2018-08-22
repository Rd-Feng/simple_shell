#include "holberton.h"
/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: n the value of the first number in the st0ring
 */
int _atoi(char *s)
{
	int i, n, posi;

	i = 0;
	n = 0;
	posi = 1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			posi *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (posi == 1)
				n = n * 10 + (s[i] - '0');
			else
				n = n * 10 - (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;
	}
	return (n);
}
