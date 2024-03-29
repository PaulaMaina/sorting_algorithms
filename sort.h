#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - Boolean values enumeration
 * @false: Is 0
 * @true: Is 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void node_swap(listint_t **head, listint_t **node1, listint_t *node2);
void selection_sort(int *array, size_t size);
void elem_swap(int *num1, int *num2);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);

#endif
