/*
 * Function:  insert_nodeint_at_index
 * --------------------
 * inserts a new node at a given position
 *
 *  head: pointer to head pointer of linked list
 *  idx: index to insert new node
 *  n: new node's data
 *
 *  returns: address of new node, or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n) {

  unsigned int count = 0;
  listint_t *new_node = NULL;
  listint_t *current = NULL;
  

  if (head == NULL) {
    return NULL;
  }


  new_node = malloc(sizeof(listint_t));
  if (new_node == NULL) {
    return NULL;
  }
  

  new_node->n = n;
  new_node->next = NULL;

 
  if (idx == 0) {
    new_node->next = *head;
    *head = new_node;
    return new_node;
  }
  
  
  current = *head;
  while (current != NULL && count < idx-1) {
    current = current->next;
    count++;
  }

  
  if (current == NULL || current->next == NULL) {
    free(new_node);
    return NULL;
  }

  
  new_node->next = current->next;
  current->next = new_node;
  
  
  return new_node;
}
