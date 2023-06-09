#include <stdio.h>
/**
 * main - computes and prints the sum of all the multiples
 * Description: print the first 50 Fibonacci
 * Return: Always 0 (Success)
 */
int main(void)
{
	long prev = 1, curr = 2;

	long next;
	long i;

	printf("%ld, %ld, ", prev, curr);

	for (i = 2; i < 50; i++)
	{
		next = prev + curr;
		printf("%ld", next);

		if (i < 49)
		{
			printf(", ");
		}

		prev = curr;
		curr = next;
	}
	printf("\n");
	return (0);
}
