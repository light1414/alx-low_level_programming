#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - This sets the val of a bit to 0 at a given index
 * @p: parameter
 * @index: index
 * Return: 1 on success, -1 on error
 */
int clear_bit(unsigned long int *p, unsigned int index)
{
	if (index > sizeof(p) * 8)
		return (-1);
	*p &= ~(1 << index);
	return (1);
}

