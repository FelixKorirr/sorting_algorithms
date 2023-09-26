#include "sort.h"

void swap_int(int *x, int *y);
int lomuto_partition(int *array, size_t size, int l, int r);
void lomuto_sort(int *array, size_t size, int l, int r);
void quick_sort(int *array, size_t size);

/**
 * swap_int - Swap two integers in an array.
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
 * lomuto_partition - Order a subset of an array of
 * integers according to
 * the lomuto partition scheme
 * @array: Array of integers
 * @size: Size of the array.
 * @l: The starting index.
 * @r: The ending index.
 * Return: The final partition index.
 * korir codes
 */
int lomuto_partition(int *array, size_t size, int l, int r)
{
	int *mid, top, bottom;

	mid = array + r;
	for (top = bottom = l; bottom < r; bottom++)
	{
		if (array[bottom] < *mid)
		{
			if (top < bottom)
			{
				swap_int(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *mid)
	{
		swap_int(array + top, mid);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index.
 * @r: The ending index.
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int l, int r)
{
	int p;

	if (r - l > 0)
	{
		p = lomuto_partition(array, size, l, r);
		lomuto_sort(array, size, l, p - 1);
		lomuto_sort(array, size, p + 1, r);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}
