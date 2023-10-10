#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int i;

	if (!array)
		return (0);

	if (array[0] == value)
		return (0);

	i = 1;
	while (i < (int) size && value >= array[i])
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		i *= 2;
	}

	printf("Value found between indexes [%d] and [%d]\n",
		   i / 2, min(i, (int) size - 1));

	return (binary_search_for_exponential(array, i / 2,
										  min(i, (int) size - 1), value));
}

/**
 * binary_search_for_exponential - searches for a value in a
 * sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @start: start index
 * @end: end index
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int binary_search_for_exponential(int *array, size_t start,
								  size_t end, int value)
{
	size_t low = start, high = end, mid;

	if (!array)
		return (-1);

	while (low <= high)
	{
		print_search_range(array, low, high);

		mid = low + (high - low) / 2;
		if (value == array[mid])
			return (mid);

		if (value > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

/**
 * print_search_range - prints the range of the array being searched
 * @array: pointer to the first element of the array to search in
 * @low: low index of the array
 * @high: high index of the array
 */
void print_search_range(int *array, int low, int high)
{
	int i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i == high)
			printf("%d", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("\n");
}

/**
 * min - returns the minimum of two integers
 * @a: first integer
 * @b: second integer
 * Return: the minimum of the two integers
 */
int min(int a, int b)
{
	return (a > b ? b : a);
}
