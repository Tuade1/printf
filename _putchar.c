#include <unistd.h>
/**
 * _putchar - writes character c to stdout
 * @c: The character.
 * Return: 1 if successful.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
