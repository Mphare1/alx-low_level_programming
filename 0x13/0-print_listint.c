#include "lists.h"

/**
 * print_listint - prints elements of list
 * @h: list
 * Return: total number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t total = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);

		total = total + 1;
		h = h->next;
	}

	return (total);
}
