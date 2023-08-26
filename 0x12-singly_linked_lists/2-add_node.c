#include <stdio.h>
#include "lists.h"

/**
 * _strlen - get the length of string
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
	return (a + _strlen(s + a));
}
/**
 * add_node - add new node at the beginning of linked list
 * list
 * @head: the head of the node / the first node
 * @str: string value of each node
 *
 * Return: address of the new element
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (str == NULL)
		return (NULL);
	if (strdup(str) == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = _strlen(str);

	if (head == NULL)
		return (NULL);

	new->next = *head;
	*head = new;


	return (new);
}
