#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t linked list
 * @head: head pointer of the list
 * Return: summation of all data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *curr = head;

	if (head == NULL)
		return (0);

	while (curr != NULL)
	{
		sum += curr->n;
		curr = curr->next;
	}

	return (sum);
}
