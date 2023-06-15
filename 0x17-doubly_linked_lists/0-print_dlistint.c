#include "lists.h"

/**
 * print_dlistint - ...
 * @h: ...
 * Return: ...
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t x;

	for (c = 0; h != NULL; x++)
	{
		printf("%d\n", h->n);
		
		h = h->next;
	}
  
	return (x);
}
