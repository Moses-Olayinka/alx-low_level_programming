#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *munch = head;
	listint_t *duke = head;

	if (!head)
		return (NULL);

	while (munch && duke && duke->next)
	{
		duke = duke->next->next;
		munch = munch->next;
		if (duke == munch)
		{
			munch = head;
			while (munch != duke)
			{
				munch = munch->next;
				duke = duke->next;
			}
			return (duke);
		}
	}

	return (NULL);
}
