#include "hash_tables.h"

/**
 * hash_table_create - create a hash table
 * @size: size of the table
 * Return: new created table, or NULL if memory allocated failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = malloc(sizeof(hash_table_t));

	if (!table)
		return (NULL);

	table->size = size;
	table->array = malloc(size * sizeof(hash_node_t *));
	if (!table->array)
	{
		free(table);
		return (NULL);
	}

	initialize_table(table);

	return (table);
}

/**
 * initialize_table - initialize the table
 * @table: table to initialize
 */
void initialize_table(hash_table_t *table)
{
	unsigned long int i;

	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
}

/**
 * hash_node_create - create a node in hash table
 * @key: key
 * @value: value
 * Return: new created node, or NULL if memory allocated failed
 */
hash_node_t *hash_node_create(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (!node)
		return (NULL);

	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;

	return (node);
}

/**
 * free_node - free a node
 * @node: node to free
 */
void free_node(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * free_table - free a table
 * @table: table to free
 */
void free_table(hash_table_t *table)
{
	unsigned long int i;
	hash_node_t *current_node, *temp_node;

	for (i = 0; i < table->size; i++)
	{
		current_node = table->array[i];
		while (current_node)
		{
			temp_node = current_node;
			current_node = current_node->next;
			free_node(temp_node);
		}
	}

	free(table->array);
	free(table);
}
