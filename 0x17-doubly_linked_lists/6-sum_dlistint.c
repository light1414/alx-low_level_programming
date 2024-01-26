#include "lists.h"

/**
 * sum_dlistint - it returns the sum of every data (n)
 * of a doubly linked list
 *
 * @head: the head of the list
 * Return: the summ of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int summ;

	summ = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			summ += head->n;
			head = head->next;
		}
	}

	return (summ);
}
