#include "lists.h"

/**
 * sum_dlistint - ...
 * @head: ...
 *
 * Return: ...
 */
int sum_dlistint(dlistint_t *head)
{
	int total;

	while (head != NULL)
	{
		total += head->n;
		
		head = head->next;
	}

	return (total);
}
