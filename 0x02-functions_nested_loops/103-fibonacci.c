#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	long prev = 1;
	long curr = 2;

	long next;
	long sum = 2;

	while (curr <= 4000000)
	{
		next = prev + curr;

		if (next % 2 == 0)
		{
			sum += next;
		}
		prev = curr;
		curr = next;
	}
	printf("%ld\n", sum);

	return (0);
}
