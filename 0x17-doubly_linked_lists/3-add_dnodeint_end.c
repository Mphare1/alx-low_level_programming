#include "lists.h"

/**
 * add_dnodeint_end - ...
 * @head: ....
 * @n: ....
 *
 * Return: ....
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_nod, *curr;

	if (head == NULL)
		return (NULL);

	new_nod = malloc(sizeof(dlistint_t));
	
	if (new_nod == NULL)
		return (NULL);

	new_nod->n = n;
	
	new_nod->next = NULL;

	if (*head == NULL)
	{
		new_nod->prev = NULL;
		
		*head = new_nod;
		
		return (new_nod);
	}

	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = new_nod;
	
	new_nod->prev = curr;

	return (new_nod);
}
