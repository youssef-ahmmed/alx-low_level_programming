#include "main.h"

/**
 * flip_bits - count the number of fliped bits
 * @n: first number
 * @m: second number
 * Return: he number of bits you would need to flip
 * to get from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
	unsigned int count = 0;

	for (i = sizeof(unsigned long int) * CHAR_BIT - 1; i >= 0; i--)
	{
		if ((n & (1L << i)) ^ (m & (1L << i)))
			count++;
	}

	return (count);
}
