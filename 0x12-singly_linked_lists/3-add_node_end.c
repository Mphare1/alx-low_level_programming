#include "lists.h"
#include <string.h>
#include <stdio.h>

list_t *new_node(const char *str);
/**
 * add_node_end - added a new node to the end of a list.
 * @head: pointer to pointer of a list_t
 * @str: ....
 *
 * Return: ...
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *x;

	if (!(*head))
	{
		*head = new_node(str);
		return (*head);
	}

	if (!(*head)->next)
	{
		x = new_node(str);
		x->next = (*head)->next;
		(*head)->next = x;
	}
	else
		add_node_end(&(*head)->next, str);

	return (*head);
}

/**
 * new_node - create a new node around a string src.
 * @str: ...
 *
 * Return: ...
 */
list_t *new_node(const char *str)
{
	list_t *x;
	size_t length;

	x = malloc(sizeof(list_t));
	if (!x)
		return (NULL);
	length = 0;
	while (str[length])
		length++;

	x->str = strdup(str);
	x->length = length;
	x->next = NULL;
	return (x);
}
