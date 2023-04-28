#include "lists.h"

/**
 * list_len - calculate the number of elements in a linked
 * @h: head of the list
 * Return: number of elements
*/
size_t list_len(const list_t *h)
{
    size_t count;
    list_t *curr;

    if (h == NULL)
        return (0);

    count = 0;
    curr = (list_t *) h;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    return (count);
}