#include <stddef.h>
#include "sort.h"
/**
 * bubble_sort - implements the bubble sort sorting method
 * @array: array to sort
 * @size: the size of the array
 *
 * Return:
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t fwd;
	int current;
	int next;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			fwd = j + 1;

			if (fwd >= size)
				fwd = size - 1;

			if (array[j] > array[fwd])
			{
				current = array[j];
				next = array[fwd];
				array[fwd] = current;
				array[j] = next;
				print_array(array, size);
			}
		}
	}
}
