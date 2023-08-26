#include <stdio.h>
#include "lists.h"

/**
 * _strlen - get the string length
 * @s: the string
 *
 * Return: the length of the string
 */

int _strlen(const char *s)
{
	int a = 0;

	if (s[a] == '\0')
		return (0);
	a++;
	return (i + _strlen(s + a));
}
/**
 * add_node_end - add new node at the end of a linked list
 * @head: pointer to the first node
 * @str: the string value of each node
 *
 * Return: new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *Node, *temp;

	if (str == NULL)
		return (NULL);
	if (strdup(str) == NULL)
		return (NULL);

	Node = malloc(sizeof(list_t));
	if (Node == NULL)
		return (NULL);

	Node->str = strdup(str);
	Node->len = _strlen(str);
	Node->next = NULL;

	if (*head == NULL)
		*head = Node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = Node;
	}
	return (Node);
}
