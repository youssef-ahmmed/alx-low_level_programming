#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: head of the list
 * @str: string of the list_t struct
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

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
	new_node->next = *head;

	*head = new_node;

	return (*head);
}
