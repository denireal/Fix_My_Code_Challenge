#include <stdlib.h>
#include "lists.h"

/**
* free_dlistint - Frees a doubly linked list
* @head: Pointer to the head of the list
*/

void free_dlistint(dlistint_t *head)
{
dlistint_t *node; /* Pointer to traverse the list */

/* Iterate through the list and free each node */
while (head)
{
node = head; /* Save the current node */
head = head->next; /* Move to the next node */
free(node); /* Free the current node */
}

return;
}
