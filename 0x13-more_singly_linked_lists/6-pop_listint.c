#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to the head of the list
 * Return: head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *temp = *head;
	int data = temp->n;

	if (*head == NULL)
		return (0);

	*head = (*head)->next;
	free(temp);

	return (data);
}
