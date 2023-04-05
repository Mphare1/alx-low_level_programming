/**
 * get_listint_at_index - returns nth node of listint_t linked list
 * @head: pointer to head of linked list
 * @index: nth node
 * Return: nth node, or NULL if failed
 */

listint_t *get_listint_at_index(listint_t *head, unsigned int index)
{

	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	while (count < index && head != NULL)
	{
		head = head->next;
		count++;
	}

	if (count == index)
		return (head);

	return (NULL);
}
