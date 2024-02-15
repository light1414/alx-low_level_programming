#include "hash_tables.h"

/**
 * add_p_hash - it adds a node at the start of an hash table
 * @Hd: the head of the hash linked list
 * @key: the key of the hash
 * @value: value to store
 * Return: the head of the hash
 */
hash_node_t *add_p_hash(hash_node_t **Hd, const char *key, const char *value)
{
	hash_node_t *tmpp;

	tmpp = *Hd;

	while (tmpp != NULL)
	{
		if (strcmp(key, tmpp->key) == 0)
		{
			free(tmpp->value);
			tmpp->value = strdup(value);
			return (*Hd);
		}
		tmpp = tmpp->next;
	}

	tmpp = malloc(sizeof(hash_node_t));

	if (tmpp == NULL)
		return (NULL);

	tmpp->key = strdup(key);
	tmpp->value = strdup(value);
	tmpp->next = *Hd;
	*Hd = tmpp;

	return (*Hd);
}
