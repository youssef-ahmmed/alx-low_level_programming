#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: number value
 * @index: given one
 * Return: 1 if done, -1 otherwise
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * CHAR_BIT - 1)
		return (-1);

	*n |= 1 << index;

	return (1);
}
