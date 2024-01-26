#include "lists.h"

/**
 * get_dnodeint_at_index - it returns the nth node of a dlistint_t linked list.
 * @head: the pointer to head of the list
 * @index: the index of the node to search for, starting from 0
 * Return: the nth node or null
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size;
	dlistint_t *tmpp;

	size = 0;
	if (head == NULL)
	return (NULL);

	tmpp = head;
	while (tmpp)
	{
	if (index == size)
	return (tmpp);
	size++;
	tmpp = tmpp->next;
	}
	return (NULL);
}
