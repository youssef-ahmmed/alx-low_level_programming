#include "main.h"

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: number in string format
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int u_int, pow;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (pow = 1, u_int = 0, len--; len >= 0; len--, pow *= 2)
	{
		if (b[len] == '1')
			u_int += pow;
	}

	return (u_int);
}
