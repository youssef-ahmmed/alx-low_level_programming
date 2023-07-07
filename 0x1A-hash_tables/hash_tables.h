#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0

/** MANDATORY TASKS */

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/** create table and node */
hash_node_t *hash_node_create(const char *key, const char *value);
hash_table_t *hash_table_create(unsigned long int size);
void initialize_table(hash_table_t *table);

/** hash function */
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/** insert */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/** search */
char *hash_table_get(const hash_table_t *ht, const char *key);

/** print */
void hash_table_print(const hash_table_t *ht);

/** delete */
void hash_table_delete(hash_table_t *ht);

/** free operations */
void free_node(hash_node_t *node);

/********************************************************************/

/** ADVANCED TASK */

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;


/** create table */
shash_table_t *shash_table_create(unsigned long int size);
shash_node_t *shash_node_create(const char *key, const char *value);
void initialize_sorted_table(shash_table_t *table);

/** insert */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void sort_hash_table(shash_table_t *table, shash_node_t *new_node);

/** search */
char *shash_table_get(const shash_table_t *ht, const char *key);

/** print */
void shash_table_print(const shash_table_t *ht);

/** print reverse */
void shash_table_print_rev(const shash_table_t *ht);

/** delete */
void shash_table_delete(shash_table_t *ht);

/** free operations */
void free_sorted_node(shash_node_t *node);

#endif /* HASH_TABLES_H */
