#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>

/**
 * struct dlistint_s - Doubly linked list node structure
 * @n: Integer data stored in the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 *
 * Description: Structure representing a node in a doubly linked list.
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */

/**
 * print_dlistint - Prints all the elements of a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h);

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @head: Pointer to a pointer to the head of the list
 * @n: Integer value to be stored in the new node
 *
 * Return: Address of the new node on success, NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a
 * doubly linked list
 * @head: Pointer to a pointer to the head of the list
 * @index: Position of the node to delete
 *
 * Return: 1 if successful, -1 if the node at the index does not exist
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

/**
 * free_dlistint - Frees a doubly linked list
 * @head: Pointer to the head of the list
 */
void free_dlistint(dlistint_t *head);

#endif /* End of ifndef _LISTS_H_ */
