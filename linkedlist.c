#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "myShell.h"
#include "holberton.h"

/**
 * list_len - the number of elements in a linked list_t list.
 * @h: start of list
 *
 * Return: length of list
 */
size_t list_len(list_t *h)
{
	size_t i;

	for (i = 0; h != 0; i++)
		h = h->next;
	return (i);
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: start of list
 *
 * Return: length of list
 */
size_t print_list(list_t *h)
{
	int count;

	for (count = 0; h != 0; count++)
	{
		if (h->str == NULL)
			_printf("(nil)\n");
		else
			_printf("%s\n", h->str);
		h = h->next;
	}
	return (count);
}

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: start of list
 * @str: to add
 *
 * Return: ptr to new head
 */
list_t *add_node(list_t **head, char *str)
{
	list_t *new;
	size_t i = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	while (str[i])
		i++;
	new->len = i;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: start of list
 * @str: to add
 *
 * Return: ptr to new head
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *new;
	list_t *h;
	size_t i = 0;

	if (!head)
		return (NULL);
	h = *head;
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->str = _strdup(str);
	while (str[i])
		i++;
	new->len = i;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (h->next)
		h = h->next;
	h->next = new;
	return (*head);
}

/**
* free_list - clears a linked list from mem
* @head: ptr to head of linked list
*
* Return: nope void
*/

void free_list(list_t *head)
{
	list_t *new;

	while (head)
	{
		new = head;
		head = head->next;
		free(new->str);
		free(new);
	}
}
