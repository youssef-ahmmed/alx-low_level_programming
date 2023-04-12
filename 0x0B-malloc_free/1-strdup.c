#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 * Return: pointer to the duplicated string
*/
char *_strdup(char *str)
{
	char *new_str;
	int len = 0, i;

	if (str == NULL)
		return (NULL);


	while (str[len++])
		;

	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}

	return (new_str);
}
