/**
 * _strcpy - copies a string to anther memory adress
 * @src: pointer to the source string
 * @dest: pointer to the dest address
 *
 * Return: void just prints
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0' && src[i]!= '\n')
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
	int res = *s1 - *s2;

	while (*s1 != '\0' && *s2 != '\0')
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
	}

	return (res);
}

