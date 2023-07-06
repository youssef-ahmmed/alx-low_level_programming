#include "hash_tables.h"

/**
 * hash_table_get - get the value of a key
 * @ht: hash table
 * @key: key
 * Return: value of the key, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (!ht || !key)
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);

	current_node = ht->array[index];

	while (current_node)
	{
		if (!strcmp(current_node->key, key))
			return (current_node->value);

		current_node = current_node->next;
	}

	return (NULL);
}
