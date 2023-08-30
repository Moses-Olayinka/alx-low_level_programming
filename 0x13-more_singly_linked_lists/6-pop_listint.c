#include "lists.h"

/**
 * pop_listint - takes away or delete the head node of a listint_t
 * 
 * @head: the head node
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	int number;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	number = temp->n;
	*head = temp->next;

	free(temp);
	return (number);
}
