#include "lists.h"


size_t step_through(const list_t *);
/**
 * list_len - get the length  of a list
 * @h: pointer to a list_t
 *
 * Return: Return the length
 */
size_t list_len(const list_t *h)
{
	if (!h)
		return (0);

	if (!h->next)
		return (1);
	return (1 + step_through(h));
}

/**
 * step_through - step through.
 * @h: ...
 *
 * Return: ...
 */
size_t step_through(const list_t *h)
{
	if (!h->next)
		return (0);
	return (1 + step_through(h->next));
}
