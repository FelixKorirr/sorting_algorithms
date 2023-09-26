#include "sort.h"

void merge_sub(int *sub, int *x, size_t y, size_t mid,
		size_t z);
void merge_sort_recursive(int *sub, int *buf, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_sub - Sort a subarray of integers.
 * @sub: Subarray of an array of integers
 * @x: buffer to store the sorted subarray.
 * @y: The front index of the array.
 * @mid: The middle index of the array.
 * @z: The back index of the array.
 */
void merge_sub(int *sub, int *x, size_t y, size_t mid,
		size_t z)
{
	size_t p, q, r = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + y, mid - y);

	printf("[right]: ");
	print_array(sub + mid, z - mid);

	for (p = y, q = mid; p < mid && q < z; r++)
		x[r] = (sub[p] < sub[q]) ? sub[p++] : sub[q++];
	for (; p < mid; p++)
		x[r++] = sub[p];
	for (; q < z; q++)
		x[r++] = sub[q];
	for (p = y, r = 0; p < z; p++)
		sub[p] = x[r++];

	printf("[Done]: ");
	print_array(sub + y, z - y);
}

/**
 * merge_sort_ - Implement the merge sort algorithm through recursion.
 * @sub: A subarray of an array of integers to sort.
 * @x: A buffer to store the sorted result.
 * @y: The front index of the subarray.
 * @z: The back index of the subarray.
 * korir codes
 */
void merge_sort_(int *sub, int *x, size_t y, size_t z)
{
	size_t m;

	if (z - y > 1)
	{
		m = y + (z - y) / 2;
		merge_sort_(sub, x, y, m);
		merge_sort_(sub, x, m, z);
		merge_sub(sub, x, y, m, z);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Implements the merge sort algorithm.
 * korir codes
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
	{
		return;
	}

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
	{
		return;
	}

	merge_sort_(array, buf, 0, size);

	free(buf);
}
