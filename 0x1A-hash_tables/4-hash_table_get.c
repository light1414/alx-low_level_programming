#include "hash_tables.h"

/**
 * hash_table_get - it gets a value associated with a key
 *
 * @ht: the pointer to the hash table
 * @key: key of the hash
 * Return: the hash value.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	hash_node_t *tmpp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, ht->size);

	tmpp = ht->array[k_index];

	while (tmpp != NULL)
	{
		if (strcmp(tmpp->key, key) == 0)
			return (tmpp->value);
		tmpp = tmpp->next;
	}

	return (NULL);
}
