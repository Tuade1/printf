#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function to print a character according to a format
 * @format: a character string
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list a;
	int i, len = 0;
	char g, *e;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	va_start(a, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				_putchar('%');
				len++;
			else if (format[i] == 'c')
			{
				g = va_arg(a, int);
				_putchar(g);
				len++;
			}
			else if (format[i] == 's')
			{
				e = va_arg(a, char *);
				if (e != NULL)
				{
					for (; *e; e++)
						_putchar(*e);
						len++;
				}
			}
		}
		else
			_putchar(format[i]);
			len++;
	}
	va_end(a);
	return (len);
}
