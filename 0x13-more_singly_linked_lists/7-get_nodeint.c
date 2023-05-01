#include "lists.h"

/**
 * get_nodeint_at_index - get nth node of list
 * @head: the head pointer of the list
 * @index: the index of the node
 * Return: address of the nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int idx;
	listint_t *curr;

	if (head == NULL)
		return (NULL);

	curr = head;
	idx = 0;
	while (curr && idx < index)
	{
		idx++;
		curr = curr->next;
	}

	return (curr);
}
