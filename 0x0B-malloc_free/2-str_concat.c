#include "main.h"
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to concatenated string
*/
char *str_concat(char *s1, char *s2)
{
	char *str;
	int len1, len2, i, j;

	len1 = 0;
	len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	str = malloc(sizeof(char) * (len1 + len2 + 1));

	if (str == NULL)
		return (NULL);
	
	i = 0;
	j = 0;

	if (s1)
	{
		
		while ((str[i] = s1[i]) != '\0')
			i++;
	}

	if (s2)
	{
		while ((str[i] = s2[j]) != '\0')
		{
			i++;
			j++;
		}
	}
	str[i] = '\0';

	return (str);
}
