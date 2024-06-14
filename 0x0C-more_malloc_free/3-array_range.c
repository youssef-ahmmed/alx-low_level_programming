#include "main.h"
/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 * Return: pointer to the newly created array
*/
int *array_range(int min, int max)
{
	int i;
	int *num;

	if (min > max)
		return (NULL);

	num = malloc(sizeof(int) * (max - min + 1));

	if (num == NULL)
		return (NULL);

	i = 0;
	while (min <= max)
	{
		num[i] = min++;
		i++;
	}

	return (num);
}
