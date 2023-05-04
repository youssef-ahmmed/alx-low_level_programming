#include "main.h"

/**
 * check_binary - check if the char contain only 1's and 0's
 * @b: the number in string format
 * Return: 1 if it's 0's and 1's, 0 otherwise
 */
int check_binary(const char *b)
{
	int len = 0;

	while (b[len])
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	return (1);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: the number in string format
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int len = strlen(b);
	unsigned int u_int = 0, pow;

	if (b == NULL)
		return (0);

	if (!check_binary(b))
		return (0);

	for (len--, pow = 1; len >= 0; len--, pow *= 2)
	{
		if (b[len] == '1')
			u_int += pow;
	}

	return (u_int);
}
