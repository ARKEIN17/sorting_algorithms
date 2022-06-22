#include "sort.h"

/**
 * partition - part the array
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quickSort - quick sorts
 * @array: array to sort through
 * @start: start of array
 * @end: end of array
 * @size: size of full array
 */

void quickSort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quickSort(array, start, pivot - 1, size);
		quickSort(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - quick sorts
 * @array: array to sort through
 * @size: size of full array
 */
void quick_sort(int *array, size_t size)
{
	int end = size - 1;
	int start = 0;

	quickSort(array, start, end, size);
}
