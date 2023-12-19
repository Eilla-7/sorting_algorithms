#include "sort.h"

/**
 * swap - function to swap two variables
 * @a: the first one
 * @b: the second one
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - function to split the array into 2 paritions
 * @array: the array to be splited
 * @low: the lower index
 * @high: the higher index
 * @size: the size of the array
 * Return: piovt index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pv_index = low;
	int i = low;
	int pivot = array[high];
	int temp;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[pv_index]);
			if (pv_index != i)
				print_array(array, size);
			pv_index++;
		}
	}
	temp = array[pv_index];
	array[pv_index] = pivot;
	array[high] = temp;
	if (pv_index != high)
		print_array(array, size);
	return (pv_index);
}
/**
 * sort_helper - function to help the work of the algorithm
 * @array: the array to be sorted
 * @lower: the lower index
 * @higher: the higher index
 * @size: the size of the array
 */
void sort_helper(int *array, int lower, int higher, size_t size)
{
	int pv_index;

	if (lower < higher)
	{
		pv_index = lomuto_partition(array, lower, higher, size);

		sort_helper(array, lower, pv_index - 1, size);
		sort_helper(array, pv_index + 1, higher, size);
	}
}
/**
 * quick_sort - function use quicj=k sort to sort the array
 * @array: the array to be sorted
 * @size: the sixe of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;

	}
	sort_helper(array, 0, size - 1, size);
}
