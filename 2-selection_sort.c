#include "sort.h"

/**
 * selection_sort - function that sorts a data in
 * datastructure
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, min, j;
	int tmp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (array[min] < array[i])
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
