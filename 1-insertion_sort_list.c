#include "sort.h"

/**
 * node_swap - Swaps two nodes in a doubly linked list
 * @head: Head
 * @node1: Pointer to the node to swap
 * @node2: Pointer to the node to swap node1 with
 *
 */

void node_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: List to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	listint_t *change;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		change = current->prev;

		while (change != NULL && current->n < change->n)
		{
			node_swap(list, &change, current);
			print_list((const listint_t *)*list);
		}
	}
}
