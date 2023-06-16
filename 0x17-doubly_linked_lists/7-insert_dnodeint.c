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
 * get_node_before_index - get index
 * @h: pointer to the head of the list
 * @idx: index of the node
 * Return: address of that node
 */
dlistint_t *get_node_before_index(dlistint_t **h, unsigned int idx)
{
	dlistint_t *current = *h;
	unsigned int i;

	for (i = 0; i < idx - 1 && current != NULL; i++)
		current = current->next;

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
	dlistint_t *new_node, *before;
	size_t count = dlistint_len(*h);

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (idx >= count - 1)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	before = get_node_before_index(h, idx);

	new_node->n = n;
	new_node->next = before->next;
	new_node->prev = before;
	before->next->prev = new_node;
	before->next = new_node;

	return (new_node);
}
