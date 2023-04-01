#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees the memory of a list.
 * @head: pointer to a list.
 *
 * Return: Nothing
 */
void free_list(list_t *head)
{
       list_t *ptr;
 
 	if (head == NULL) // account for no linked list
 		return;
 
 	while (head != NULL) // have ptr keep track of head node and free
 	{
 		ptr = head;
 		head = head->next; // move to next node while ptr frees prior
 		free(ptr->str); // free malloced strings
 		free(ptr);
 	}
}
