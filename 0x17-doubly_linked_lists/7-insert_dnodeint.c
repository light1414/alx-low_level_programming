#include "lists.h"

/**
 * insert_dnodeint_at_index - it inserts a new node at
 * a given position
 *
 * @h: the head of the list
 * @idx: the index of the new node
 * @n: the value of the new node
 * Return: Address of the neww node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *neww;
	dlistint_t *head;
	unsigned int i;

	neww = NULL;
	if (idx == 0)
		neww = add_dnodeint(h, n);
	else
	{
		head = *h;
		i = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (i == idx)
			{
				if (head->next == NULL)
					neww = add_dnodeint_end(h, n);
				else
				{
					neww = malloc(sizeof(dlistint_t));
					if (neww != NULL)
					{
						neww->n = n;
						neww->next = head->next;
						neww->prev = head;
						head->next->prev = neww;
						head->next = neww;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}

	return (neww);
}
