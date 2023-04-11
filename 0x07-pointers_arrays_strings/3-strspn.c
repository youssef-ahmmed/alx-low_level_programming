#include "main.h"
/**
 * _strspn - a function that gets the length of a prefix substring
 * @s: string to be searched
 * @accept: string to be searched
 * Return: length of the prefix substring
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	char *p;

	while (*s)
	{
		for (p = accept; *p; p++)
		{
			if (*s == *p)
			{
				i++;
				break;
			}
		}
		if (*p == '\0')
			break;
		s++;
	}

	return (i);
}
