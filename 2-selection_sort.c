#include <stddef.h>
#include "sort.h"
/**
 * selection_sort - implements the selection sort sorting method
 * @array: array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	size_t least;
	int swap;

	for (i = 0; i < size; i++)
	{
		least = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[least])
			{
				least = j;
			}
		}
		if (least != i)
		{
			swap = array[i];
			array[i] = array[least];
			array[least] = swap;
			print_array(array, size);
		}
	}
}
