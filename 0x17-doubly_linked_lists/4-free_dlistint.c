#include "lists.h"

/**
 * free_dlistint - ...
 * @head: ...
 *
 * Return: ...
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr;

	while (head != NULL)
	{
		curr = head->next;
		
		free(head);
		
		head = curr;
	}
}
