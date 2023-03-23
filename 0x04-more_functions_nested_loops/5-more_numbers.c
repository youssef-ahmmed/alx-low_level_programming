#include "main.h"
/**
 * more_numbers - prints 10 times the numbers 0 to 14
 * Return: void
*/
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			_putchar(j + '0');
		}
		_putchar('\n');
	}
}
