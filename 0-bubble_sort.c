#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints in ascending order using bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	bool unsorted = true;
	int temp;
	size_t a = 0;

	if (array == NULL || size < 2)
		return;
	while (unsorted)
	{
		unsorted = false;
		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				unsorted = true;
				temp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
