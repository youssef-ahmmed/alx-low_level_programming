#include "main.h"

/**
 * print_binary - the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	int i, flag = 0;

	for (i = sizeof(unsigned long int) * CHAR_BIT - 1; i >= 0; i--)
	{
		if (n & (1L << i))
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag)
		{
			_putchar('0');
		}
	}

	if (!flag)
		_putchar('0');
}
