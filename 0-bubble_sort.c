#include "sort.h"

/**
 * swap_integer - Swap integers in an array
 * @x: The first integer
 * @y: The second integer
 * korir codes
 */
void swap_integer(int *x, int *y)
{
	int a;

	a = *x;
	*x = *y;
	*y = a;
}

/**
 * bubble_sort - Sort an array of integers
 * @array: Array of integers to sort
 * @size: Size of array
 * Description: Prints array after each swap
 * korir codes
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, length = size;
	bool b = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (b == false)
	{
		b = true;
		for (a = 0; a < length - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_integer(array + a, array + a + 1);
				print_array(array, size);
				b = false;
			}
		}
		length--;
	}
}
