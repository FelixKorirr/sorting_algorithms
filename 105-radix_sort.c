#include "sort.h"

int find_max(int *array, int size);
void radix_counter(int *array, size_t size, int j, int *y);
void radix_sort(int *array, size_t size);

/**
 * find_max - Get the maximum value in an array of integers
 * @array: Array of integers.
 * @size: Size of the array.
 * Return: Maximum integer in the array.
 * korir codes
 */
int find_max(int *array, int size)
{
	int j, y;

	for (j = array[0], y = 1; y < size; y++)
	{
		if (array[y] > j)
			j = array[y];
	}

	return (j);
}

/**
 * radix_counter - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * @j: Significant digit to sort on.
 * @y: buffer to store the sorted array.
 * korir codes
 */
void radix_counter(int *array, size_t size, int j, int *y)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t d;

	for (d = 0; d < size; d++)
		c[(array[d] / j) % 10] += 1;

	for (d = 0; d < 10; d++)
		c[d] += c[d - 1];

	for (d = size - 1; (int)d >= 0; d--)
	{
		y[c[(array[d] / j) % 10] - 1] = array[d];
		c[(array[d] / j) % 10] -= 1;
	}

	for (d = 0; d < size; d++)
		array[d] = y[d];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Implements the LSD radix sort algorithm
 * korir codes
 */
void radix_sort(int *array, size_t size)
{
	int i, j, *k;

	if (array == NULL || size < 2)
	{
		return;
	}

	k = malloc(sizeof(int) * size);
	if (k == NULL)
	{
		return;
	}

	i = find_max(array, size);
	for (j = 1; i / j > 0; j *= 10)
	{
		radix_counter(array, size, j, k);
		print_array(array, size);
	}

	free(k);
}
