#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t nodes_number = 0;

	if (!h)
		return (0);

	current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		nodes_number++;
	}

	return (nodes_number);
}
