#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int address_diff;
	listint_t *curr;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		address_diff = *h - (*h)->next;
		if (address_diff > 0)
		{
			curr = (*h)->next;
			free(*h);
			*h = curr;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
