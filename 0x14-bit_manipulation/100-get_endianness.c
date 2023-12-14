#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if large endian, 1 if small endian
 */
int get_endianness(void)
{
	int t;
	char *b;

	t = 1;
	b = (char *)&t;
	return (*b);
}
