#include "main.h"
/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of characters to concatenate
 * Return: pointer to the resulting string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, i, j;
	char *str;

	len1 = 0;
	len2 = 0;

	while (s1 && s1[len1])
		len1++;

	while (s2 && s2[len2])
		len2++;

	if (n >= len2)
		str = malloc(sizeof(char) * (len1 + len2 + 1));
	else
		str = malloc(sizeof(char) * (len1 + n + 1));

	if (str == NULL)
		return (NULL);

	i = 0;
	j = 0;

	while (s1 && (str[i] = s1[i]) != '\0')
		i++;

	while (n < len2 && i < (len1 + n))
		str[i++] = s2[j++];

	while (n >= len2 && i < (len1 + len2))
		str[i++] = s2[j++];

	str[i] = '\0';

	return (str);
}
