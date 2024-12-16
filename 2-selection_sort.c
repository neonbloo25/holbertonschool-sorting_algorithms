#include "sort.h"
/**
 * selection_sort - Im STILL not sure why its "selective" y'know
 * @array: target of sort
 * @size: size of target
 **/
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t i, j = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}

		if (pos != i)
		{
			aux = array[i];
			array[i] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
