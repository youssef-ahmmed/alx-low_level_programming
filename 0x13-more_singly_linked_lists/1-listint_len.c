#include "lists.h"

/**
 * listint_len - calculate the length of the list
 * @h: head of the list
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	listint_t *curr;

	if (h == NULL)
		return (0);

	curr = (listint_t *) h;
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}

	return (count);
}
