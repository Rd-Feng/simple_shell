#ifndef LISTSH
#define LISTSH
#include <unistd.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
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
	unsigned int val_len;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(list_t *h);
size_t list_len(list_t *h);
list_t *add_node(list_t **head, char *str, char *val);
list_t *add_node_end(list_t **head, char *str, char *val);
void free_list(list_t *head);


#endif
