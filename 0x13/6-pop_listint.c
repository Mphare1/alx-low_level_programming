#include "lists.h"

/**
 * pop_listint - deletes the head node, and returns the head node’s data
 * @head: pointer to linked list
 * Return: deleted head node's data
 */

int pop_listint(listint_t **head)
{
    int data;
    listint_t *old_head;

    if (*head == NULL) {
        return 0;
    }

    old_head = *head; /* save current head node */
    data = old_head->n; /* save its data */
    *head = old_head->next; /* move head to next node */
    free(old_head); /* free old head node */

    return data;
}
