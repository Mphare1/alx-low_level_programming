/*
 * Function:  delete_nodeint_at_index
 * --------------------
 * deletes a node at a given position
 *
 *  head: pointer to head pointer of linked list
 *  index: index to delete node
 *
 *  returns: 1 if succeeded, or -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index) {
  
  unsigned int count = 0;
  listint_t *current = NULL;
  listint_t *previous = NULL;
  
 
  if (head == NULL || *head == NULL)
  {
    return -1;
  }

  if (index == 0) {
    current = *head;
    *head = current->next;
    free(current);
    return 1;
  }
  
  previous = *head;
  while (previous != NULL && count < index-1) {
    previous = previous->next;
    count++;
  }

  if (previous == NULL || previous->next == NULL)
  {
    return -1;
  }


  current = previous->next;
  previous->next = current->next;
  free(current);
  
  return 1;
}
