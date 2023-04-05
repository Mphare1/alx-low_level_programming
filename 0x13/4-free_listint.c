#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: linked list
 *Return: return type is void
 */

void free_listint(listint_t *head)
{
    listint_t *current = head;
    while (current != NULL) {
        listint_t *next = current->next;
        free(current);
        current = next;
    }
}
