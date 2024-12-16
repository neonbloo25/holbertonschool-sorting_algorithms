#include "sort.h"

/* prototype section */
void swap_ints(int *a, int *b);

int lomuto_partition(int *array, size_t size, int left, int right);

void lomuto_sort(int *array, size_t size, int left, int right);

void quick_sort(int *array, size_t size);

/**
 * swap_ints - les dance!!
 * @a: swapee 1
 * @b: swapee 2
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - "last element as pivot"
 * @array: target array
 * @size: array size
 * @left: from here
 * @right: to here
 * Return: Result
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * lomuto_sort - quicksort's recursion element
 * @array: target array
 * @size: array size
 * @left: from here
 * @right: to here
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
/**
 * quick_sort - The essence of it, quicksort
 * @array: target array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
