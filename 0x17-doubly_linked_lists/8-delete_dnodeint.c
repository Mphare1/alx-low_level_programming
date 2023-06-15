#include "lists.h"

/**
 * delete_dnodeint_at_index - ...
 * @head: ...
 * @index: ...
 *
 * Return: ...
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;
	
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		curr = *head;
		
		*head = curr->next;

		if (*head != NULL)
			(*head)->prev = NULL;

		free(curr);
		
		return (1);
	}

	curr = *head;

	for (i = 0; curr != NULL && i < index; i++)
		curr = curr->next;

	if (curr == NULL)
		return (-1);

	curr->prev->next = curr->next;

	if (curr->next != NULL)
		curr->next->prev = curr->prev;

	free(curr);
	return (1);
}
