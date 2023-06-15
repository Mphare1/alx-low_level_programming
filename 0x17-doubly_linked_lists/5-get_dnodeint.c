#include "lists.h"

/**
 * get_dnodeint_at_index - ....
 * @head: ....
 * @index: ....
 *
 * Return: ...
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int ct;

	if (head == NULL)
		
		return (NULL);

	for (ct = 0; head != NULL && ct < index; ct++)
		head = head->next;

	
	return (head);
}
