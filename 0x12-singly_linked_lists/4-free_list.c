#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: head of the list
 */
void free_list(list_t *head)
{
	list_t *curr;

	while (curr)
	{
		curr = head->next;
		free(head->str);
		free(head);
		head = curr;
	}
}
