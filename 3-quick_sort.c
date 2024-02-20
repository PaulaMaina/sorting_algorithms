#include "sort.h"

/**
 * elem_swap - Swaps two elements
 * @el1: First element
 * @el2: Second element
 *
 */

void elem_swap(int *el1, int *el2)
{
	int temp;

	temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}
/**
 * lomuto_partition - Orders a subset of an integer array using the lomuto
 * partition scheme
 * @array: The array to be ordered
 * @size: Number of lements in the array
 * @start: The starting index of the subset
 * @end: The last index of the subset
 *
 * Return: The resulting final partition index
 */

int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, first, last;

	pivot = array + end;
	for (first = last = start; last < end; last++)
	{
		if (array[last] < *pivot)
		{
			if (first < last)
			{
				elem_swap(array + last, array + first);
				print_array(array, size);
			}
			first++;
		}
	}

	if (array[first] > *pivot)
	{
		elem_swap(array + first, pivot);
		print_array(array, size);
	}

	return (first);
}

/**
 * lomuto_sort - Executes the quick sort algorithm through recursion
 * @array: Array to be sorted
 * @size: Number of elements in the array
 * @start: The starting index of the subset
 * @end: The ending index of the subset
 */

void lomuto_sort(int *array, size_t size, int start, int end)
{
	int partition;

	if (end - start > 0)
	{
		partition = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, partition - 1);
		lomuto_sort(array, size, partition + 1, end);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
