#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer to the first node where value is located,
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr = list, *prev = list;

	if (!list)
		return (NULL);

	while (curr->express && curr->n < value)
	{
		prev = curr;
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	}

	if (!curr->express && curr->next && curr->n < value)
		prev = curr;

	while (!curr->express && curr->next && curr->n < value)
		curr = curr->next;

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, curr->index);

	return (search_skiplist(prev, curr, value));
}

/**
 * search_skiplist - searches for a value in a sorted list of integers
 * @start: pointer to the head of the list to search in
 * @end: pointer to the end of the list to search in
 * @value: value to search for
 * Return: pointer to the first node where value is located,
 */
skiplist_t *search_skiplist(skiplist_t *start, skiplist_t *end, int value)
{
	while (start && start != end->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (value == start->n)
			return (start);
		start = start->next;
	}

	return (NULL);
}
