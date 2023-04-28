#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: head of the list
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t count;
	list_t *curr;

	if (h == NULL)
		return (0);

	count = 0;
	curr = (list_t *) h;
	while (curr != NULL)
	{
		if (curr->str == NULL)
			curr->str = "[0] (nil)";

		printf("[%d] %s\n", curr->len, curr->str);
		curr = curr->next;
		count++;
	}

	return (count);
}
