#include "lists.h"
#include <string.h>
#include <stdio.h>

list_t *new_node(const char *str);
/**
 * add_node_end - add node to end of linked list
 * @head: linked list
 * @str: data for new node
 * Return: address of new element, or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *lst;

	if (!(*head))
	{
		*head = new_node(str);
		return (*head);
	}

	if (!(*head)->next)
	{
		lst = new_node(str);
		lst->next = (*head)->next;
		(*head)->next = lst;
	}
	else
		add_node_end(&(*head)->next, str);

	return (*head);
}

/**
 * new_node - ....
 * @str: string to add to the node.
 *
 * Return: ....
 */
list_t *new_node(const char *str)
{
	list_t *lst;
	size_t x;

	lst = malloc(sizeof(list_t));
	if (!lst)
		return (NULL);
	x = 0;
	while (str[x])
		x++;

	lst->str = strdup(str);
	lst->x = x;
	lst->next = NULL;
	return (lst);
}
