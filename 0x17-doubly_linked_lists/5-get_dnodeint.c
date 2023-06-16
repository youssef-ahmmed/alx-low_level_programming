#include "lists.h"

/**
 * get_dnodeint_at_index - get the index of nth node
 * @head: pointer to the head of the list
 * @index: of the node
 * Return: address of that node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	if (!head)
		return (NULL);

	for (i = 0; i < index; i++)
	{
		current = current->next;
	}

	return (current);
}
