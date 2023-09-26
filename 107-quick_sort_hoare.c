#include "sort.h"

void swap_int(int *x, int *z);
int hoare_partition(int *array, size_t size, int l, int r);
void hoare_sort(int *array, size_t size, int l, int r);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_int - Swap two integers in an array.
 * @a: The first integer
 * @b: The second integer
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
 * hoare_part - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: Array of integers.
 * @size: Size of the array.
 * @l: The starting index
 * @r: The ending index
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the p.
 * Prints the array after each swap of two elements.
 * korir codes
 */
int hoare_part(int *array, size_t size, int l, int r)
{
	int p, a, b;

	p = array[r];
	for (a = l - 1, b = r + 1; a < b;)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);

		if (a < b)
		{
			swap_int(array + a, array + b);
			print_array(array, size);
		}
	}

	return (a);
}

/**
 * hoare_sort - Implement the quicksort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @l: The starting index
 * @r: The ending index
 * Description: Uses the Hoare partition scheme.
 * korir codes
 */
void hoare_sort(int *array, size_t size, int l, int r)
{
	int p;

	if (r - l > 0)
	{
		p = hoare_part(array, size, l, r);
		hoare_sort(array, size, l, p - 1);
		hoare_sort(array, size, p, r);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Uses the Hoare partition scheme.
 * korir codes
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	hoare_sort(array, size, 0, size - 1);
}
