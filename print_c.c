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
	char g;
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
				g = va_arg(a, int);
				_putchar(g);
				len++;
			}
			else if (format[i] == 's')
			{
				e = va_arg(a, char *);
				if (e == NULL)
				{
					return (NULL);
				}
				else
				{
					for (; *e; e++)
					{
						_putchar(*e)
						len++;
					}
				}
			}
			else
			{
				j = va_args(a, char);
				_putchar(j);
				len++;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	va_end(a);
	return (len);
}
