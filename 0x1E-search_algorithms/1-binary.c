#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int low = 0, high = (int) size - 1, mid;

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
