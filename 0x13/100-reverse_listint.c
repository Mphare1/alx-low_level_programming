#include "lists.h"
/**
 * reverse_listint - reverses a linked list in place
 * @head: pointer to pointer to head node
 * Return: pointer to first node of reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *b4, *next;

	if (head == NULL || *head == NULL) {
		return (NULL);
	}

	b4 = NULL;
	while (*head != NULL) {
		next = (*head)->next;
		(*head)->next = b4;
		b4 = *head;
		*head = next;
	}

	*head = b4;
	return (*head);
}
