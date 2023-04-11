#include "main.h"
/**
 * _strstr - locates a substring
 * @haystack: string to be searched
 * @needle: substring to be located
 * Return: pointer to the beginning of the located substring
*/
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n == *h && *n)
		{
			n++;
			h++;
		}

		if (*n == '\0')
			return (haystack);
		haystack++;
	}
	
	return (NULL);
}
