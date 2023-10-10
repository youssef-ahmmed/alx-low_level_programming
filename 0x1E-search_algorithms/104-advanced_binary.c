#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursive_binary_search(array, 0, (int) size - 1, value));
}

/**
 * recursive_binary_search - prints the range of the array being searched
 * @array: pointer to the first element of the array to search in
 * @low: low index of the array
 * @high: high index of the array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int recursive_binary_search(int *array, int low, int high, int value)
{
	int mid;

	if (low <= high)
	{
		mid = low + (high - low) / 2;

		print_search_range(array, low, high);

		if (array[mid] == value && array[mid - 1] != value)
			return (mid);

		if (array[mid] >= value)
			return (recursive_binary_search(array, low, mid, value));

		return (recursive_binary_search(array, mid + 1, high, value));
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
