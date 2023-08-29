#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	// Allocate memory for the new node
	listint_t *new_node = malloc(sizeof(listint_t));
	if (!new_node) {
		return NULL; // Return NULL if memory allocation fails
	}

	// Assign values to the new node
	new_node->n = n;
	new_node->next = *head;

	// Update the head pointer to point to the new node
	*head = new_node;

	return new_node;
}
