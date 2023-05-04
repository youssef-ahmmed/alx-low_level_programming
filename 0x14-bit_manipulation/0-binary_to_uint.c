#include "main.h"

/**
 * check_binary - check if the char contain only 1's and 0's
 * @b: the number in string format
 * @length: length of the string
 * Return: 1 if it's 0's and 1's, 0 otherwise
 */
int check_binary(const char *b, int length)
{
	int len = 0;

	while (*b == '1' || *b == '0')
	{
		len++;
		b++;
	}

	return (len == length);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: the number in string format
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int len = strlen(b), i;
	unsigned int u_int = 0;

	if (b == NULL)
		return (0);

	if (!check_binary(b, len))
		return (0);

	for (i = 0; i < len; i++)
	{
		u_int <<= 1;
		if (b[i] == '1')
			u_int |= 1;
	}

	return (u_int);
}
