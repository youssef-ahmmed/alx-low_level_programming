#include "main.h"
/**
 * more_numbers - prints 10 times the numbers 0 to 14
 * Return: void
*/
void more_numbers(void)
{
	int num, i, j;

	for (i = 1; i <= 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			num = j;
			if (j > 9)
			{
				_putchar(1 + 48);
				num = j % 10;
			}
			_putchar(num + '0');
		}
		_putchar('\n');
	}
}
