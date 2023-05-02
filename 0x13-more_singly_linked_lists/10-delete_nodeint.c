#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index in list
 * @head: pointer to the head of the list
 * @index: given one to be removed
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *curr = *head;
	listint_t *removed = NULL;

	if (!(*head))
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(curr);
		return (1);
	}

	for (; i < index - 1; i++, curr = curr->next)
	{
		if (!curr || !(curr->next))
			return (-1);
	}

	removed = curr->next;
	curr->next = removed->next;
	free(removed);

	return (1);
}
