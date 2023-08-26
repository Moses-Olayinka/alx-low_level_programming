#include <stdio.h>
#include "lists.h"

/**
 * free_list - free allocated space for linked stuctures
 * @head: the list-t structure node
 *
 * Return: nil
 */

void free_list(list_t *head)
{
	while (head != NULL)
	{
		free(head->str);
		free(head);
		head = head->next;
	}
}
