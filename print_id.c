#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function to handle format characters %d and %i
 * @format: the specifiers to handle
 * Return: the 
 */
int _printf(const char *format, ...)
{
  va_list a; 
  int i, len = 0, n = 0;

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
        {
          _putchar('%');
          len++;
        }
        else if (format[i] == 'd' || format[i] == 'c')
        {
          n = va_arg(a, int);
          if (n < 0)
          {
            _putchar('-');
            len++;
            n = -n;
          }
          len += print_intdoub(n);
        }
      }
    }
  va_end(a);
  return(len);
}

int print_intdoub(int n)
{
  int len = 0;
  if (n / 10 != 0)
  {
    _putchar('0' + (n % 10));
    len++;
  }
  return (len);
}