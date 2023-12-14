#include "main.h"

/**
 * flip_bits - counts the num of bits to modify
 * to get from one num
 * @t: 1st num
 * @u: 2nd num
 *
 * Return: numb of bits to modify
 */
unsigned int flip_bits(unsigned long int t, unsigned long int u)
{
	int v, countbit = 0;
	unsigned long int currt;
	unsigned long int exclusive = t ^ u;

	for (v = 63; v >= 0; v--)
	{
		currt = exclusive >> v;
		if (currt & 1)
			countbit++;
	}

	return (countbit);
}
