#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - put the variadic parameter into a buffer as string
 * @type: type of parameter
 *
 * Return: pointer to to the resulting buffer string
 */
char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		return (get_number(va_arg(params, int)));
	case 'b':
		return (get_binary(va_arg(params, int)));
	case 'r':
		return (get_rev(va_arg(params, char *)));
	case 'R':
		return (get_rot13(va_arg(params, char *)));
	default:
		return (NULL);/* Error */
	}
}
