#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	listint_t *curr;

	for (curr = (listint_t *) h; curr != NULL; curr = curr->next)
	{
		printf("%d\n", curr->n);
		count++;
	}

	return (count);
}
