#include <stdio.h>
#include "lists.h"

/**
* print_dlistint - Displays a doubly linked list of integers
* @h: Pointer to the first element of the list
*
* Return: Count the number of output elements
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t n = 0;

for (; h; h = h->next, n++)
printf("%d\n", h->n);

return (n);
}

