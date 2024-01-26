#include "lists.h"

/**
 * dlistint_len - it returns the numb of elements in
 * a double linked list
 *
 * @h: the head of the list
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int countt;

	countt = 0;

	if (h == NULL)
		return (countt);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		countt++;
		h = h->next;
	}

	return (countt);
}
