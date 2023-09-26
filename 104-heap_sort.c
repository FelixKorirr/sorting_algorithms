#include "sort.h"

void swap_int(int *x, int *y);
void To_heap(int *array, size_t size, size_t x, size_t y);
void heap_sort(int *array, size_t size);

/**
 * swap_int - Swap two integers in an array.
 * @x: The first integer
 * @y: The second integer
 * korir codes
 */
void swap_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * To_heap - Turn a binary tree into a complete binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @x: Index of the base row of the tree.
 * @y: Root node of the binary tree.
 * korir codes
 */
void To_heap(int *array, size_t size, size_t x, size_t y)
{
	size_t l, r, large;

	l = 2 * y + 1;
	r = 2 * y + 2;
	large = y;

	if (l < x && array[l] > array[large])
		large = l;
	if (r < x && array[r] > array[large])
		large = r;

	if (large != y)
	{
		swap_int(array + y, array + large);
		print_array(array, size);
		To_heap(array, size, x, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Implements heap sort
 * algorithm
 * korir codes
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (a = (size / 2) - 1; a >= 0; a--)
		To_heap(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_int(array, array + a);
		print_array(array, size);
		To_heap(array, size, a, 0);
	}
}
