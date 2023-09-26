#include "sort.h"

/**
 * get_maximum - Get the maximum value in an array of integers.
 * @array: Array of integers
 * @x: Size of the array
 * Return: Maximum integer in the array.
 * korir codes
 */
int get_maximum(int *array, int x)
{
	int max, y;

	for (max = array[0], y = 1; y < x; y++)
	{
		if (array[y] > max)
			max = array[y];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array
 * Description: Prints the counting array
 * korir codes
 */

void counting_sort(int *array, size_t size)
{
	int *c, *d, max, e;

	if (array == NULL || size < 2)
	{
		return;
	}

	d = malloc(sizeof(int) * size);
	if (d == NULL)
	{
		return;
	}
	max = get_maximum(array, size);
	c = malloc(sizeof(int) * (max + 1));
	if (c == NULL)
	{
		free(d);
		return;
	}

	for (e = 0; e < (max + 1); e++)
		c[e] = 0;
	for (e = 0; e < (int)size; e++)
		c[array[e]] += 1;
	for (e = 0; e < (max + 1); e++)
		c[e] += c[e - 1];
	print_array(c, max + 1);
	for (e = 0; e < (int)size; e++)
	{
		d[c[array[e]] - 1] = array[e];
		c[array[e]] -= 1;
	}
	for (e = 0; e < (int)size; e++)
		array[e] = d[e];

	free(d);
	free(c);
}
