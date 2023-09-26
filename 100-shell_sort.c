#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @x: The first integer
 * @y: The second integer
 */
void swap_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Uses the Knuth interval sequence
 * korir codes
 */
void shell_sort(int *array, size_t size)
{
	size_t g, x, y;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (x = g; x < size; x++)
		{
			y = x;
			while (y >= g && array[y - g] > array[y])
			{
				swap_int(array + y, array + (y - g));
				y -= g;
			}
		}
		print_array(array, size);
	}
}
