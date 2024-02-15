#include "hash_tables.h"

/**
 * hash_table_create - it creates a hash table
 * @size: the size of the hash table
 *
 * Return: The hash table, or NULL if function fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	hash_node_t **array;
	unsigned long int i;

	table = valloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	array =valloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	table->array = array;
	table->size = size;

	return (table);
}
