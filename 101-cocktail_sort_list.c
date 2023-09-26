#include "sort.h"

void swap_node_top(listint_t **head, listint_t **tail, listint_t **current);
void swap_node_bottom(listint_t **head, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_top - Swap a node in a listint_t doubly-linked
 * list of integers with the node ahead
 * @head: Pointer to head of a doubly-linked list
 * @tail: Pointer to tail of the doubly-linked list
 * @current: A pointer to the current swapping node
 * korir codes
 */
void swap_node_top(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *t = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = t;
	else
		*head = t;
	t->prev = (*current)->prev;
	(*current)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = t;
	t->next = *current;
	*current = t;
}

/**
 * swap_node_bottom - Swap a node in a listint_t doubly-linked
 * list of integers with a node behind it.
 * @head: Pointer to the head of a doubly-linked list
 * @tail: Pointer to the tail of the doubly-linked list
 * @current: Pointer to the current swapping node
 */
void swap_node_bottom(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *t = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = t;
	else
		*tail = t;
	t->next = (*current)->next;
	(*current)->prev = t->prev;
	if (t->prev != NULL)
		t->prev->next = *current;
	else
		*head = *current;
	(*current)->next = t;
	t->prev = *current;
	*current = t;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail current algorithm.
 * @list: Pointer to the head of a listint_t doubly-linked list
 * korir codes
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool x = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (x == false)
	{
		x = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_top(list, &tail, &current);
				print_list((const listint_t *)*list);
				x = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_bottom(list, &tail, &current);
				print_list((const listint_t *)*list);
				x = false;
			}
		}
	}
}
