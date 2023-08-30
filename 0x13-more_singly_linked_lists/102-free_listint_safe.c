#include "lists.h"

/**
 * find_listint_loop - find loop in linked list
 * @head: head pointer of linked list
 * Return: address of node where loop starts from.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *munch, *duke;

	munch = duke = head;

	while (munch != NULL && duke != NULL)
	{
		munch = munch->next;
		duke = duke->next->next;

		if (munch == duke)
		{
			munch = head;
			while (munch != duke)
			{
				munch = munch->next;
				duke = duke->next;
			}
			return (munch);
		}
	}

	return (NULL);
}
