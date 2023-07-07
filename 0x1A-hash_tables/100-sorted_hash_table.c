#include "hash_tables.h"

/**
 * shash_node_create - sorted hash node
 * @key: key
 * @value: value
 * Return: new created node, or NULL if memory allocated failed
 */
shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

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
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}

/**
 * shash_table_create - sorted hash table
 * @size: size of the table
 * Return: new created table, or NULL if memory allocated failed
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;

	table = malloc(sizeof(shash_table_t));
	if (!table)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(shash_node_t *) * size);
	if (!table->array)
	{
		free(table);
		return (NULL);
	}

	initialize_sorted_table(table);

	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * initialize_sorted_table - initialize the table
 * @table: table to initialize
 */
void initialize_sorted_table(shash_table_t *table)
{
	unsigned long int i;

	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
}

/**
 * shash_table_set - sort the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 * Return: 1 if success, 0 if failed
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node;
	unsigned long int index;

	if (!ht || !key)
		return (FAIL);

	index = key_index((unsigned char *) key, ht->size);
	current_node = ht->array[index];
	new_node = shash_node_create(key, value);
	if (!new_node)
		return (FAIL);

	if (!current_node)
	{
		ht->array[index] = new_node;
		if (!ht->shead && !ht->stail)
		{
			ht->shead = ht->stail = new_node;
			return (SUCCESS);
		}
		sort_hash_table(ht, new_node);
		return (SUCCESS);
	}

	while (current_node)
	{
		if (!strcmp(current_node->key, key))
		{
			free(current_node->value);
			current_node->value = strdup(value);
			free_sorted_node(new_node);
			return (SUCCESS);
		}
		current_node = current_node->next;
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	sort_hash_table(ht, new_node);

	return (SUCCESS);
}

/**
 * free_sorted_node - free a sorted node
 * @node: node to free
 */
void free_sorted_node(shash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * sort_hash_table - sort the hash table
 * @table: hash table
 * @new_node: new node to insert
 */
void sort_hash_table(shash_table_t *table, shash_node_t *new_node)
{
	shash_node_t *current;

	if (strcmp(new_node->key, table->shead->key) < 0)
	{
		new_node->snext = table->shead;
		table->shead->sprev = new_node;
		table->shead = new_node;
		return;
	}

	current = table->shead;

	while (current && strcmp(new_node->key, current->key) > 0)
		current = current->snext;

	if (!current)
	{
		new_node->snext = NULL;
		new_node->sprev = table->stail;
		table->stail->snext = new_node;
		table->stail = new_node;
		return;
	}

	new_node->snext = current;
	new_node->sprev = current->sprev;
	if (current->sprev != NULL)
		current->sprev->snext = new_node;
	current->sprev = new_node;
}

/**
 * shash_table_get - get the value of a key
 * @ht: hash table
 * @key: key to get
 * Return: value of the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current_node;

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

/**
 * shash_table_print - print the hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int printed = 0;

	if (!ht)
		return;

	current_node = ht->shead;

	printf("{");

	while (current_node)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		printed = 1;
		current_node = current_node->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - print the hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int printed = 0;

	if (!ht)
		return;

	current_node = ht->stail;

	printf("{");

	while (current_node)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		printed = 1;
		current_node = current_node->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - delete the hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current_node, *temp_node;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node)
		{
			temp_node = current_node;
			current_node = current_node->next;
			free_sorted_node(temp_node);
		}
	}

	free(ht->array);
	free(ht);
}
