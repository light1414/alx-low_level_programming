#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table
 *
 * @ht: the pointer to the hash table
 * Return: no return
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmpp1;
	hash_node_t *tmpp2;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmpp1 = ht->array[i];
		while ((tmpp2 = tmpp1) != NULL)
		{
			tmpp1 = tmpp1->next;
			free(tmpp2->key);
			free(tmpp2->value);
			free(tmpp2);
		}
	}
	free(ht->array);
	free(ht);
}
