#include "main.h"
/**
 * rev_string - reverses a string
 * @s: string to be reversed
 * Return: void
*/
void rev_string(char *s)
{
	int i, len;
	char temp;

	len = 0;

	while (s[len] != '\0')
		len++;

	len--;

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len];
		s[len--] = temp;
	}
}
