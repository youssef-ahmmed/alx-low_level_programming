#include "main.h"

/**
 * get_bit - value of a bit at a given index
 * @n: number value
 * @index: given index
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * CHAR_BIT - 1)
		return (-1);

	if (n & (1L << index))
		return (1);
	else
		return (0);
}
