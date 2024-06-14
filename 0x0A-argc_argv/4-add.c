#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - adds positive numbers passed from the command line
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if successful, 1 if an error occurred
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];

		for (j = 0; arg[j] != '\0'; j++)
		{
			if (!isdigit(arg[j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(arg);
	}

	printf("%d\n", sum);
	return (0);
}
