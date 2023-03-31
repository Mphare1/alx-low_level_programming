#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_list - it prints the contents of a list.
 * @h: pointer to list.
 *
 * Return: elements
 */

size_t print_list(const list_t *h)
{
	size_t elements;

	if (!h)
		return (0);
	elements = 0;
	do {
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next;
		elements = elements + 1;
	}  while (h);

	return (elements);
}
