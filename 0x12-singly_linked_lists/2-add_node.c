#include "lists.h"
#include <string.h>


/**
 * add_node - add node to head
 * @head: ...
 * @str: a string to add to the lists content
 *
 * Return: pointer to a list_t.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *lst;
	size_t len = 0;

	lst = malloc(sizeof(list_t));
	if (!lst)
		return (NULL);

	while (str[len])
		len++;
	lst->len = len;

	lst->str = strdup(str);
	if (!(*head))
		lst->next = NULL;
	else
		lst->next = *head;
	*head = lst;

	return (*head);
}
