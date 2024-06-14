#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: head of the list
 * @str: string of list_t struct
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *curr;

	if (new_node == NULL)
		return (NULL);

	new_node->len = strlen(str);
	new_node->str = malloc(sizeof(char) * (new_node->len + 1));
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = new_node;

	return (*head);
}
