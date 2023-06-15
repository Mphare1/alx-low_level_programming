#include "lists.h"

/**
 * insert_dnodeint_at_index - ...
 * @h: ...
 * @idx: ...
 * @n: ...
 *
 * Return: Pointer to the  inserted node or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_nod, *old_nod;
	
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	old_nod = *h;

	for (i = 0; old_nod != NULL && i < idx; i++)
		old_nod = old_nod->next;

	if (old_nod == NULL && i == idx)
		return (add_dnodeint_end(h, n));
	
	else if (old_nod != NULL)
	{
		new_nod = malloc(sizeof(dlistint_t));
		
		if (new_nod == NULL)
			return (NULL);

		new_nod->n = n;
		new_nod->prev = old_nod->prev;
		
		new_nod->next = old_nod;

		if (old_nod->prev != NULL)
			old_nod->prev->next = new_nod;
		
		old_nod->prev = new_nod;

		return (new_nod);
	}

	return (NULL);
}
