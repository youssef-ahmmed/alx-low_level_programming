#include "main.h"
/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the matrix
 * @size: size of the matrix
 * Return: void
*/
void print_diagsums(int *a, int size)
{
	int sum_diag_left = 0, sum_diag_right = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum_diag_left += *(a + i * size + i);
		sum_diag_right += *(a + i * size + size - i - 1);
	}

	printf("%d, %d\n", sum_diag_left, sum_diag_right);
}
