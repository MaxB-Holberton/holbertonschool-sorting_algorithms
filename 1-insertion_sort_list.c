#include <stddef.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_swap - swapping the nodes
 * @list: the list node
 * @cursor: the current cursor position
 * @swap_node: the node to check for swapping
 *
 * Return: null
 */
void insertion_swap(listint_t **list, listint_t *cursor, listint_t *swap_node)
{
	listint_t *new_next_node;
	listint_t *new_prev_node;

	while ((cursor->n < swap_node->prev->n))
	{
		/* get the pointers to the new position in the list */
		new_next_node = swap_node->prev;
		new_prev_node = swap_node->prev->prev;

		/* set the new next node to point to the next node in the list */
		new_next_node->next = swap_node->next;
		if (swap_node->next != NULL)
			swap_node->next->prev = new_next_node;

		/* set the new previous and node nodes in the current node */
		swap_node->prev = new_prev_node;
		swap_node->next = new_next_node;

		new_next_node->prev = swap_node;
		if (new_prev_node == NULL)
		{
			/* if the new previous node is the start of the list */
			*list = swap_node;
			print_list(*list);
			break;
		}
		new_prev_node->next = swap_node;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - implements the insertion sort method
 * @list: the list to sort
 *
 * Return: null
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cursor = *list;

	if (list == NULL || *list == NULL)
		return;

	cursor = cursor->next;
	while (cursor != NULL)
	{
		insertion_swap(list, cursor, cursor);
		cursor = cursor->next;
	}
}
