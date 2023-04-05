#include "lists.h"

/**
 * add_nodeint - adds a new node
 * @head: ...
 * @n: data
 * Return: address of new element or NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *the_node = malloc(sizeof(listint_t));
    if (the_node == NULL)
        return NULL;

    the_node->n = n;
    the_node->next = *head;
    *head = the_node;

    return the_node;
}
