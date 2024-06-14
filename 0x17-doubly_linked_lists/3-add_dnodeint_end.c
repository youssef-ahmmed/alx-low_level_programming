#include "lists.h"

/**
 * get_last_node - get the address of the last node
 * @head: pointer to the head of the list
 * Return: address of last node
 */
dlistint_t *get_last_node(dlistint_t **head)
{
	dlistint_t *current = *head;

	while (current->next != NULL)
		current = current->next;

	return (current);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: pointer to the head of the list
 * @n: data to be inserted
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *last;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!head || !*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	last = get_last_node(head);
	new_node->prev = last;
	last->next = new_node;

	return (*head);
}
