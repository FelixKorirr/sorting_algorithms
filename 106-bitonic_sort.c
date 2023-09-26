
#include "sort.h"

void swap_int(int *x, int *y);
void bitonic_merg(int *array, size_t size, size_t s, size_t sq,
		char dr);
void bitonic_sq(int *array, size_t size, size_t s, size_t sq, char dr);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merg - Sort a bitonic sequence inside an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @s: Starting index
 * @sq: Size of the sequence to sort.
 * @dr: The direction to sort
 */
void bitonic_merg(int *array, size_t size, size_t s, size_t sq,
		char dr)
{
	size_t i, j = sq / 2;

	if (sq > 1)
	{
		for (i = s; i < s + j; i++)
		{
			if ((dr == UP && array[i] > array[i + j]) ||
					(dr == DOWN && array[i] < array[i + j]))
				swap_int(array + i, array + i + j);
		}
		bitonic_merg(array, size, s, j, dr);
		bitonic_merg(array, size, s + j, j, dr);
	}
}

/**
 * bitonic_sq - Convert an array of integers into bitonic sequence.
 * @array: Array of integers
 * @size: Size of the array
 * @s: The starting index
 * @sq: The size of a block
 * @dr: Direction to sort the bitonic sequence
 * korir codes
 */
void bitonic_sq(int *array, size_t size, size_t s, size_t sq, char dr)
{
	size_t c = sq / 2;
	char *str = (dr == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + s, sq);

		bitonic_sq(array, size, s, c, UP);
		bitonic_sq(array, size, s + c, c, DOWN);
		bitonic_merg(array, size, s, sq, dr);

		printf("Result [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + s, sq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Prints the array after each swap
 * korir codes
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_sq(array, size, 0, size, UP);
}
