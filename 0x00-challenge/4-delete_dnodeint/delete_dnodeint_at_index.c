#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - Deletes the node at a given position
* in a doubly linked list
* @head: Pointer to a pointer to the head of the list
* @index: The position of the node to delete
*
* Return: 1 if successful, -1 if the node at the index does not exist
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *saved_head; /* Pointer to save the original head */
dlistint_t *tmp; /* Temporary pointer to manipulate nodes */
unsigned int p; /* Counter for iterating through the list */

/* Check if the list is empty */
if (*head == NULL)
{
return (-1); /* Return -1 if the list is empty */
}

/* Save the original head of the list */
saved_head = *head;

/* Initialize the counter to 0 */
p = 0;

/* Iterate through the list until reaching the desired index or the end */
while (p < index && *head != NULL)
{
*head = (*head)->next; /* Move to the next node */
p++; /* Increment the counter */
}

/* If the index is greater than the length of the list */
if (p != index)
{
*head = saved_head; /* Restore the original head */
return (-1); /* Return -1 indicating failure */
}

/* If the index is 0 */
if (0 == index)
{
tmp = (*head)->next; /* Save the next node */
free(*head); /* Free the current node */
*head = tmp; /* Update the head to the next node */
/* If the next node exists, update its previous pointer */
if (tmp != NULL)
{
tmp->prev = NULL;
}
}
else
{
/* Update the next pointer of the previous node */
(*head)->prev->next = (*head)->next;
free(*head); /* Free the current node */
/* If the next node exists, update its previous pointer */
if ((*head)->next)
{
(*head)->next->prev = (*head)->prev;
}
*head = saved_head; /* Restore the original head */
}
return (1); /* Return 1 indicating success */
}
