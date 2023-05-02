#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head of the function
 * @idx: given index
 * @n: element of the struct
 * Return: address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *curr;
	unsigned int i;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	i = 0;
	curr = *head;
	while (curr && i < idx)
	{
		i++;
		curr = curr->next;
	}

	new_node->next = curr->next->next;
	curr->next = new_node;

	return (*head);
}
