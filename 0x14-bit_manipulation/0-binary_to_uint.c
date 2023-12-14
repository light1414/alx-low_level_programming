#include "main.h"

/**
 * bin_to_uint - function changes a binary num to an unsigned int.
 * @b: pointer to a string holding a bin num
 *
 * Return: unsigned int with decimal numb of bin num or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int num;

	num = 0;
	if (!b)
		return (0);
	for (j = 0; b[j] != '\0'; j++)
	{
		if (b[j] != '0' && b[j] != '1')
			return (0);
	}
	for (j = 0; b[j] != '\0'; j++)
	{
		num <<= 1;
		if (b[j] == '1')
			num += 1;
	}
	return (num);
}
