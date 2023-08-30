#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a specified index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	// Declare temporary pointers and an index counter
	listint_t *temp = *head;  // Temporary pointer for traversal
	listint_t *current = NULL;  // Pointer to the node to be deleted
	unsigned int i = 0;  // Index counter for traversal

	// Check if the linked list is empty
	if (*head == NULL)
		return (-1);  // Return -1 to indicate an error

	// Check if the index is 0 (deleting the first node)
	if (index == 0)
	{
		*head = (*head)->next;  // Update the head to the next node
		free(temp);  // Free the memory of the original head
		return (1);  // Return 1 to indicate success
	}

	// Traverse the list to the node before the one to be deleted
	while (i < index - 1)
	{
		// Check if the traversal pointer is NULL or the next node is NULL
		if (!temp || !(temp->next))
			return (-1);  // Return -1 to indicate an error
		temp = temp->next;  // Move the traversal pointer
		i++;  // Increment the index counter
	}

	// Store the node to be deleted and its next node
	current = temp->next;
	temp->next = current->next;  // Update the previous node's next pointer
	free(current);  // Free the memory of the deleted node

	return (1);// Return 1 to indicate success    
}
