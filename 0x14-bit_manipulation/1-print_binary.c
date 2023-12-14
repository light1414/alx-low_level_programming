#include "main.h"

/**
 * _pow - func cal (base ^ power)
 * @base: base of the expn
 * @power: power of the expn
 *
 * Return: numb of (base ^ power)
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int numb;
	unsigned int d;

	numb = 1;
	for (d = 1; d <= power; d++)
		numb *= base;
	return (numb);
}

/**
 * print_binary - prints a num in binary notation
 * @n: num to print
 *
 * Return: empty
 */
void print_binary(unsigned long int n)
{
	unsigned long int diviso, chk;
	char flg;

	flg = 0;
	diviso = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (diviso != 0)
	{
		chk = n & diviso;
		if (chk == diviso)
		{
			flg = 1;
			_putchar('1');
		}
		else if (flg == 1 || diviso == 1)
		{
			_putchar('0');
		}
		diviso >>= 1;
	}
}
