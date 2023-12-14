#include"main.h"

/**
 * get_bit - returns the numb of a bit at a given index.
 * @n: numb to chk bits in
 * @index: index at which to chk bit
 *
 * Return: numb of the bit, or -1 if there is error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int diviso, chk;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	diviso = 1 << index;
	chk = n & diviso;
	if (chk == diviso)
		return (1);
	return (0);
}
