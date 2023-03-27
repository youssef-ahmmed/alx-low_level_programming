#include "main.h"
/**
 * puts_half - prints the second half of a string
 * @str: string to be printed
 * Return: void
*/
void puts_half(char *str)
{
	int len, i;

	len = 0;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		i = len / 2;
	else
		i = (len - 1) / 2;

	for (; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
