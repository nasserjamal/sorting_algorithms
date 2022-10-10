#include "sort.h"


/**
 * quick_sort - Sorts and array using quick sort
 *
 * @array: The array to be sorted
 * @size: Size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	sort_arr(array, 0, size, size);
}


/**
 * sort_arr - sort a sub array
 *
 * @array: The entire array
 * @start: The start of the sub array
 * @end: End of the sub array
 * @size: The size of the array
 */
void sort_arr(int *array, size_t start, size_t end, size_t size)
{
	size_t i = end;
	size_t pivot = start;
	int navigator = -1;
	int temp;
	size_t temp_i;

	/* Just one element remaining so exit */
	if (start == end)
		return;

	while (pivot != i)
	{
		if ((navigator < 0 && array[pivot] > array[i])
|| (navigator > 0 && array[pivot] < array[i]))
		{
			/* swap Values */
			temp = array[pivot];
			array[pivot] = array[i];
			array[i] = temp;

			/* Swap indices */
			temp_i = pivot;
			pivot = i;
			i = temp_i;

			/* Reset navigator */
			if (pivot > i)
				navigator = 1;
			else
				navigator = -1;

			print_array(array, size);
		}
		i += navigator;
	}
	if (pivot != start)
		sort_arr(array, start, pivot - 1, size);
	if (pivot != end)
		sort_arr(array, pivot + 1, end, size);
}
