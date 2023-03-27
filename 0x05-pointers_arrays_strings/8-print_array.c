#include "main.h"
#include <stdio.h>
/**
 * print_array - prints n elements of an array of integers separated by commas
 * @a: array of integers
 * @n: number of elements to print
 * Return: void
*/
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d, ", a[i]);
		if (i == n - 1)
		{
			printf("%d", a[i]);
		}
	}
	printf("\n");
}
