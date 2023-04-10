#include "main.h"

/**
 * rot13 - encodes a string in rot13
 * @s: string to be encoded
 * 
 * Return: encoded string
*/
char *rot13(char *s)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13_map[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; alphabet[j] != '\0'; j++)
		{
			if (s[i] == alphabet[j])
			{
				s[i] = rot13_map[i];
				break;
			}
		}
	}
	return (s);
}
