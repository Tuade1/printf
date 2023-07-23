#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
/**
 * _printf - function to print a character according to a format
 * @format: a character string
 * Return: the number of characters
 */

int _printf(const char *format, ...)
{
	va_list a;
	int i;
	int len = 0;
	char *e;

	va_start(a, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				e = va_arg(a, char *);
				len += print_a(*e);
			}
			else if (format[i] == 's')
			{
				e = va_arg(a, char *);
				len += print_b(e);
			}
			else
			{
				len++;
			}
		}
		else
		{
			len++;
		}
	}
	va_end(a);
	return (len);
}

/**
 * print_a - function to print a character
 * @a: the character
 * Return: the character
 */
char print_a(char a)
{
	return (a);
}

/**
 * print_b - function to a string
 * @b: a character string
 * Return: the string
 */
char *print_b(char *b)
{
	int lent = strlen(b);
	int i;
	char *c;

	if (b == NULL)
		return (NULL);
	c = malloc(lent * sizeof(char));
	if (c == NULL)
		return (NULL);
	for (i = 0; i < lent; i++)
	{
		c[i] = b[i];
	}
	free(c);
	return (c);
}
