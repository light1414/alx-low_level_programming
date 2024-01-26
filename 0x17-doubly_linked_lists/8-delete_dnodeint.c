#include "lists.h"

/**
 * delete_dnodeint_at_index - it deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: the head of the list
 * @index: the index of the new node
 * Return: 1 if it succeeded, else -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2;
	unsigned int p;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	p = 0;

	while (h1 != NULL)
	{
		if (p == index)
		{
			if (p == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		p++;
	}

	return (-1);
}
