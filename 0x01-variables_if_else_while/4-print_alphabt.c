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

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i == 'e' || i == 'q')
			continue;
	}

	return (0);
}
