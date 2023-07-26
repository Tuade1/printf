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
	int len = 0;
	char g, *e;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(a, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%'), len++;
				format++;
				_putchar(*format), len++;
			}
			else if (*format == 'c')
			{
				_putchar(g = va_arg(a, int)), len++;
			}
			else if (*format == 's')
			{
				e = va_arg(a, char *);
				if (e == NULL)
          e = "(null)";
        for (; *e; e++)
					_putchar(*e), len++;
			}
		}
		else
			_putchar(*format), len++;
	}
	va_end(a);
	return (len);
}
