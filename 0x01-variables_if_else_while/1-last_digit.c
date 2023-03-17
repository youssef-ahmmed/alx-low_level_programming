#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
  * main - Entry point
  * Check if positive or negative or zero
  * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		int mod = n % 10;

		if (mod > 5)
			printf("Last digit of %d is %d and is grater than 5\n", n, mod);
		else if (mod < 6 && mod != 0)
			printf("Last digit of %d is %d and is less than 6 and not 0\n", n, mod);
	}
	else if (n < 0)
	{
		int mod = (-n) % 10;

		if (mod > 5)
			printf("Last digit of %d is %d and is grater than 5\n", n, mod);
		else if (mod < 6 && mod != 0)
			printf("Last digit of %d is %d and is less than 6 and not 0\n", n, mod);
	}
	else if (n % 10 == 0)
		printf("Last digit of %d and is 0 and is 0\n", n);
	return (0);
}
