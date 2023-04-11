#include "main.h"
/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: character to be searched
 * Return: pointer to the first occurrence of the character c
*/
char *_strchr(char *s, char c)
{
	while (*s != '0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == '\0')
		return (s);
	return (NULL);
}
