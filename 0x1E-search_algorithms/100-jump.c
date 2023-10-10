#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int step = sqrt((int) size);
	int prev = 0;

	if (!array)
		return (-1);

	while (array[prev] < value)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev += step;
		if (prev >= (int) size)
		{
			printf("Value found between indexes [%d] and [%d]\n", prev - step, prev);
			return ((int) linear_search_for_jump(array, prev - step, size - 1, value));
		}
	}

	printf("Value found between indexes [%d] and [%d]\n", prev - step, prev);

	return ((int) linear_search_for_jump(array, prev - step, prev, value));
}

/**
 * linear_search_for_jump - searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @start: start index
 * @end: end index
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
size_t linear_search_for_jump(int *array, size_t start, size_t end, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = start; i <= end; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
