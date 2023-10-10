#include "search_algos.h"


/**
 * interpolation_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0, high = (int) size - 1;
	int pos;

	if (!array)
		return (-1);

	while (low <= high)
	{
		pos = low + (((double)(high - low) / (array[high] - array[low]))
				* (value - array[low]));

		if (pos > (int) size)
		{
			printf("Value checked array[%d] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%d] = [%d]\n", pos, array[pos]);
		if (value == array[pos])
			return (pos);

		if (value > array[pos])
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}
