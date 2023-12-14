#include "main.h"

/**
 * set_bit - Function to set a specific bit in a number to 1.
 * @number: Pointer to the number to be modified
 * @bit_index: Index of the bit to set
 *
 * Return: 1 if successful, otherwise -1 for errors
 */
int set_bit(unsigned long int *number, unsigned int bit_index)
{
	unsigned long int bit_mask;

	if (bit_index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	bit_mask = 1UL << bit_index;
	*number |= bit_mask;

	return (1);
}
