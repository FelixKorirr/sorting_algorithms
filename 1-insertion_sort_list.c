#include "sort.h"

/**
 * swap - Swap two nodes in a doubly-linked list.
 * @x: Pointer to the head of the doubly-linked list.
 * @y: Pointer to the first node
 * @z: The second node
 */
void swap(listint_t **x, listint_t **y, listint_t *z)
{
	(*y)->next = z->next;
	if (z->next != NULL)
		z->next->prev = *y;
	z->prev = (*y)->prev;
	z->next = *y;

	if ((*y)->prev != NULL)
		(*y)->prev->next = z;

	else
		*x = z;
	(*y)->prev = z;
	*y = z->prev;
}

/**
 * insertion_sort_list - Sort a doubly-linked-list of integers
 *                       using the insertion sort algorithm.
 * @list: Pointer to the head of a doubly-linked list
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y, *z;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (x = (*list)->next; x != NULL; x = z)
	{
		z = x->next;
		y = x->prev;
		while (y != NULL && x->n < y->n)
		{
			swap(list, &y, x);
			print_list((const listint_t *)*list);
		}
	}
}
