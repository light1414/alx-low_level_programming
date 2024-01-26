#include "lists.h"

/**
 * add_dnodeint - it adds a new node at the beginning
 * of a dlistint_t list
 *
 * @head: the head of the list
 * @n: the value of the element
 * Return: Address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *neww;
	dlistint_t *h;

	neww = malloc(sizeof(dlistint_t));
	if (neww == NULL)
		return (NULL);

	neww->n = n;
	neww->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	neww->next = h;

	if (h != NULL)
		h->prev = neww;

	*head = neww;

	return (neww);
}
