#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr_node = NULL;
	const listint_t *loop_node = NULL;
	size_t node_count = 0;
	size_t loop_index;

	curr_node = head;
	while (curr_node)
	{
		printf("[%p] %d\n", (void *) curr_node, curr_node->n);
		node_count++;
		curr_node = curr_node->next;

		/* Check for a loop */
		loop_node = head;
		loop_index = 0;
		while (loop_index < node_count)
		{
			if (loop_node == curr_node)
			{
				printf("-> [%p] %d\n", (void *) curr_node, curr_node->n);
				return (node_count);
			}
			loop_index++;
			loop_node = loop_node->next;
		}

		if (!head)
			exit(98);
	}

	return (node_count);
}
