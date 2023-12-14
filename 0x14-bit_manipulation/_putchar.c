#include <unistd.h>

/**
 * _putchar - gives the char c to stdout
 * @c: char to return
 *
 * Return: 1 on success.
 * On error, return -1 on error and errno is set correctly
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
