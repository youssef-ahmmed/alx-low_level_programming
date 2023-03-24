#include "main.h"
/**
 * print_triangle - prints a triangle
 * @size: size of triangle
 * Description: prints a triangle
 * Return: void
*/
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = size; i > 0; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			_putchar(' ');
		}
		for (k = 0; k <= size - i; k++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
