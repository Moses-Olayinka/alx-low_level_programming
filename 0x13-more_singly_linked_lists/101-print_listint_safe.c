#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *munch, *duke;
	size_t Nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	munch = head->next;
	duke = (head->next)->next;

	while (duke)
	{
		if (munch == duke)
		{
			munch = head;
			while (munch != duke)
			{
				Nodes++;
				munch = munch->next;
				duke = duke->next;
			}

			munch = munch->next;
			while (munch != duke)
			{
				Nodes++;
				munch = munch->next;
			}

			return (Nodes);
		}

		munch = munch->next;
		duke = (duke->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of Nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t Nodes, index = 0;

	Nodes = looped_listint_len(head);

	if (Nodes == 0)
	{
		for (; head != NULL; Nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < Nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (Nodes);
}
