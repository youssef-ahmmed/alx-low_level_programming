#include "lists.h"

/**
 * sum_dlistint - sum of all the data (n) of a linked list
 * @head: pointer to the head of the list
 * Return: summation
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	if (!head)
		return (0);

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
