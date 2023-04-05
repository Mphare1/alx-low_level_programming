#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to head pointer of linked list
 * @n: data to add to new node
 * Return: address of new element, or NULL if failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *the_node = malloc(sizeof(listint_t));
    if (the_node == NULL)
        return NULL;

    the_node->n = n;
    the_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        listint_t *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = the_node;
    }

    return the_node;
}
