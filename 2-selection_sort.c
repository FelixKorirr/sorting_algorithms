#include "sort.h"

/**
 * swap_int - Swap two integers in an array
 * @x: First integer
 * @y: Second integer
 */
void swap_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using selection sort algorithm
 * @array: Array of integers
 * @size: Size of array
 * Description: Prints the array after each swap
 * korir codes
 */

void selection_sort(int *array, size_t size)
{
	int *x;
	size_t y, z;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (y = 0; y < size - 1; y++)
	{
		x = array + y;

		for (z = y + 1; z < size; z++)
			x = (array[z] < *x) ? (array + z) : x;

		if ((array + y) != x)
		{
			swap_int(array + y, x);
			print_array(array, size);
		}
	}
}
