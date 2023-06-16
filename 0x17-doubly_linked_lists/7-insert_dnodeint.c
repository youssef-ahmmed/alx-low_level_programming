#include "lists.h"

/**
 * dlistint_len - calculate the number of nodes
 * @h: head of the list
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t nodes_number = 0;

	if (!h)
		return (0);

	current = h;

	while (current != NULL)
	{
		current = current->next;
		nodes_number++;
	}

	return (nodes_number);
}

/**
 * get_node_current_index - get index
 * @h: pointer to the head of the list
 * @idx: index of the node
 * Return: address of that node
 */
dlistint_t *get_node_current_index(dlistint_t **h, unsigned int idx)
{
	dlistint_t *current = *h;

	while (current != NULL && idx > 1)
	{
		current = current->next;
		idx--;
	}
	return (current);
}
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index of the node
 * @n: data
 * Return: the address of the new node, or NULL if it failed
 */
	dlistint_t
*insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;

	if (!h)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = get_node_current_index(h, idx);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	current = get_node_current_index(h, idx);
	if (!current)
		return (NULL);
	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = add_dnodeint(&(current->next), n);
	if (new_node == NULL)
		return (NULL);

	new_node->prev = current;
	return (new_node);
}
