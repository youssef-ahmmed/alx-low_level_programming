#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase,
 *              and then in uppercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d", i);
	}

	putchar('\n');

	return (0);
}
