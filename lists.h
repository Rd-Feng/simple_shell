#define _GNU_SOURCE
#ifndef LISTSH
#define LISTSH
#include <unistd.h>

/**
 * struct list_s - singly linked list
 * @str: key string - (malloc'ed string)
 * @len: length of the key string
 * @val: value string
 * @valLen: length value string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);


#endif
