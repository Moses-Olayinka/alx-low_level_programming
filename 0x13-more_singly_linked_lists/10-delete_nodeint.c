#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at certian index
 * @head: the head node
 * @index: index of the node to delete
 *
 * Return: modified singly linked list
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp, *prev;

	if (*head == NULL)
		return (-1);

	prev = *head;
	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}
	else
	{
		/**
		 * keep looping while i < node before the target index
		 * && as long as the prev != the end || pointing to null
		 * in case of over size index
		 *
		 * You can also get its length and check first as an
		 * alternative
		 */
		while (i < index - 1 && prev != NULL)
		{
			prev = prev->next;
			i++;
		}
		/**
		 * takes care of index > linked list size
		 *  when the previous node = last node
		 */
		if (i != (index - 1) || prev->next == NULL)
			return (-1);

		temp = prev->next;
		prev->next = temp->next;
		free(temp);
	}

	return (1);
}
