#include <stdlib.h>
#include "lists.h"

/**
* add_dnodeint_end - Adds a new node at the end of a doubly linked list
* @head: Pointer to a pointer to the head of the list
* @n: Value to be stored in the new node
*
* Return: Address of the new node on success, NULL on failure
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new; /* Pointer to the new node */
dlistint_t *l;   /* Pointer to traverse the list */

/* Allocate memory for the new node */
new = malloc(sizeof(dlistint_t));
if (new == NULL)
{
return (NULL); /* Return NULL if memory allocation fails */
}

/* Initialize the new node */
new->n = n;
new->next = NULL;

/* If the list is empty, make the new node the head */
if (*head == NULL)
{
*head = new;
new->prev = NULL;
return (new);
}

/* Traverse the list to find the last node */
l = *head;
while (l->next != NULL)
{
l = l->next;
}

/* Append the new node to the end of the list */
l->next = new;
new->prev = l;

/* Return the address of the new node */
return (new);
}
