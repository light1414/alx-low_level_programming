#include "hash_tables.h"

/**
 * hash_table_print - It prts the keys and numbs of the hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmpp;
	char *sept;

	if (ht == NULL)
		return;

	printf("{");
	sept = "";

	for (i = 0; i < ht->size; i++)
	{
		tmpp = ht->array[i];
		while (tmpp != NULL)
		{
			printf("%s'%s': '%s'", sept, tmpp->key, tmpp->value);
			sept = ", ";
			tmpp = tmpp->next;
		}
	}
	printf("}\n");
}
