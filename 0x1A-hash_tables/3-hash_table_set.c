#include "hash_tables.h"

/**
 * hash_table_set - add an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 * Return: 1 if success, 0 if failed
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current_node;
	unsigned long int index;

	if (!ht || !key)
		return (FAIL);

	index = key_index((unsigned char *) key, ht->size);

	/* search if exist or not */
	current_node = ht->array[index];

	new_node = hash_node_create(key, value);
	if (!new_node)
		return (FAIL);

	/* 1. if not in the table, put directly */
	if (!current_node)
	{
		ht->array[index] = new_node;
		return (SUCCESS);
	}

	/* 2. if key exist => update the value */
	while (current_node)
	{
		if (!strcmp(current_node->key, key))
		{
			free(current_node->value);
			current_node->value = strdup(value);
			free_node(new_node);
			return (SUCCESS);
		}
		current_node = current_node->next;
	}

	/* 3. Add at first of array */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (SUCCESS);
}
