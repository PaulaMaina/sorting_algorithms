#include "sort.h"

/**
 * elem_swap - Swaps two integer elements
 * @num1: First integer
 * @num2: Second integer
 */

void elem_swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elemnts in the array
 */

void selection_sort(int *array, size_t size)
{
	int *small;
	size_t a, c;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		small = array + a;
		for (c = a + 1; c < size; c++)
			small = (array[c] < *small) ? (array + c) : small;

		if ((array + a) != small)
		{
			elem_swap(array + a, small);
			print_array(array, size);
		}
	}
}
