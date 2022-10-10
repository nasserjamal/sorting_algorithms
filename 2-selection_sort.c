#include "sort.h"


/**
 * selection_sort - Sorts array using selection sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tempIndex;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		tempIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[tempIndex])
				tempIndex = j;
		}
		if (tempIndex != i)
		{
			/* swap */
			temp = array[i];
			array[i] = array[tempIndex];
			array[tempIndex] = temp;
			print_array(array, size);
		}
	}

}
