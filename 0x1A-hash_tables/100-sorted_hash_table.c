#include "hash_tables.h"

/**
 * shash_table_create - It creates a shash table with a given size
 *
 * @size: The size of the shash table
 * Return: The Created shash table, or NULL if function fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_node_t **array;
	unsigned long int i;

	table = valloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	array = valloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	table->array = array;
	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * add_n_shash - it Adds a node at the start of a shash table
 * @h: The head of the shash linked list
 * @key: key of the shash
 * @value: value to store
 * Return: created node
 */
shash_node_t *add_n_shash(shash_node_t **h, const char *key, const char *value)
{
	shash_node_t *tmpp;

	tmpp = *h;

	while (tmpp != NULL)
	{
		if (strcmp(key, tmpp->key) == 0)
		{
			free(tmpp->value);
			tmpp->value = strdup(value);
			return (tmpp);
		}
		tmpp = tmpp->next;
	}

	tmpp = malloc(sizeof(shash_node_t));

	if (tmpp == NULL)
		return (NULL);

	tmpp->key = strdup(key);
	tmpp->value = strdup(value);
	tmpp->next = *h;

	*h = tmpp;

	return (tmpp);
}

/**
 * add_i_shash - it adds a node on the DLL of the shash table
 *
 * @Hd: the pointer to the table
 * @new: new node to add
 * Return: no return
 */
void add_i_shash(shash_table_t *Hd, shash_node_t *new)
{
	shash_node_t *tmpp1, *tmpp2;
	int ret;

	tmpp1 = tmpp2 = Hd->shead;

	while (tmpp1 != NULL)
	{
		ret = strcmp(new->key, tmpp1->key);
		if (ret == 0)
		{
			return;
		}
		else if (ret < 0)
		{
			new->sprev = tmpp1->sprev;

			if (tmpp1->sprev)
				tmpp1->sprev->snext = new;
			else
				Hd->shead = new;

			tmpp1->sprev = new;
			new->snext = tmpp1;

			return;
		}
		tmpp2 = tmpp1;
		tmpp1 = tmpp1->snext;
	}

	new->sprev = tmpp2;
	new->snext = NULL;

	if (Hd->shead)
		tmpp2->snext = new;
	else
		Hd->shead = new;

	Hd->stail = new;
}

/**
 * shash_table_set - it adds a hash (key, value) to a given shash table
 *
 * @Hd: The pointer to the shash table
 * @key: key of the shash
 * @value: value to store
 * Return: 1 if successes, 0 if fails
 */
int shash_table_set(shash_table_t *Hd, const char *key, const char *value)
{
	unsigned long int k_index;
	shash_node_t *new;

	if (Hd == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	k_index = key_index((unsigned char *)key, Hd->size);

	new = add_n_shash(&(Hd->array[k_index]), key, value);

	if (new == NULL)
		return (0);

	add_i_shash(Hd, new);

	return (1);
}

/**
 * shash_table_get - it gets the value associated with a key
 *
 * @Hd: pointer to the shash table
 * @key: key of the shash
 * Return: value of the shash.
 */
char *shash_table_get(const shash_table_t *Hd, const char *key)
{
	unsigned long int k_index;
	shash_node_t *tmpp;

	if (Hd == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, Hd->size);

	tmpp = Hd->array[k_index];

	while (tmpp != NULL)
	{
		if (strcmp(tmpp->key, key) == 0)
			return (tmpp->value);
		tmpp = tmpp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the keys and values of the shash table
 *
 * @Hd: pointer to the shash table
 * Return: no return
 */
void shash_table_print(const shash_table_t *Hd)
{
	shash_node_t *tmpp;
	char *sept;

	if (Hd == NULL)
		return;

	printf("{");
	sept = "";

	tmpp = Hd->shead;

	while (tmpp != NULL)
	{
		printf("%s'%s': '%s'", sept, tmpp->key, tmpp->value);
		sept = ", ";
		tmpp = tmpp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints the keys and values of the shash table
 * in reverse
 *
 * @Hd: pointer to the shash table
 * Return: no return
 */
void shash_table_print_rev(const shash_table_t *Hd)
{
	shash_node_t *tmpp;
	char *sept;

	if (Hd == NULL)
		return;

	printf("{");
	sept = "";

	tmpp = Hd->stail;

	while (tmpp != NULL)
	{
		printf("%s'%s': '%s'", sept, tmpp->key, tmpp->value);
		sept = ", ";
		tmpp = tmpp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a shash table
 *
 * @Hd: pointer to the shash table
 * Return: no return
 */
void shash_table_delete(shash_table_t *Hd)
{
	unsigned long int i;
	shash_node_t *tmpp1;
	shash_node_t *tmpp2;

	if (Hd == NULL)
		return;

	for (i = 0; i < Hd->size; i++)
	{
		tmpp1 = Hd->array[i];
		while ((tmpp2 = tmpp1) != NULL)
		{
			tmpp1 = tmpp1->next;
			free(tmpp2->key);
			free(tmpp2->value);
			free(tmpp2);
		}
	}
	free(Hd->array);
	free(Hd);
}
