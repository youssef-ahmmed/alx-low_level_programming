#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_search_range(int *array, int low, int high);
int jump_search(int *array, size_t size, int value);
size_t linear_search_for_jump(int *array, size_t start, size_t end, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_search_for_exponential(int *array, size_t start,
								  size_t end, int value);
int min(int a, int b);
int advanced_binary(int *array, size_t size, int value);
int recursive_binary_search(int *array, int low, int high, int value);

listint_t *jump_list(listint_t *list, size_t size, int value);
listint_t *search_list(listint_t *start, listint_t *end, int value);

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *search_skiplist(skiplist_t *start, skiplist_t *end, int value);

/** linked list helper functions */
listint_t *create_list(int *array, size_t size);
void free_list(listint_t *list);
void print_list(const listint_t *list);

#endif
