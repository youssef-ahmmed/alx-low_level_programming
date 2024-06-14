#include "lists.h"

/**
 * dlistint_len - calculate the number of nodes
 * @h: head of the list
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t nodes_number = 0;

	if (!h)
		return (0);

	current = h;

	while (current != NULL)
	{
		current = current->next;
		nodes_number++;
	}

	return (nodes_number);
}
