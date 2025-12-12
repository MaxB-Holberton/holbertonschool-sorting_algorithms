#include <stddef.h>
#include <stdio.h>
#include "sort.h"
/**
 * swap_items - swap the two selected items
 * @array: the array
 * @i: index of first item
 * @j: index of second item
 * @size: size of the array
 *
 * Return: void
 */
void swap_items(int *array, size_t i, size_t j, size_t size)
{
	int swap = array[i];

	if (array[i] != array[j])
	{
		array[i] = array[j];
		array[j] = swap;
		print_array(array, size);
	}
}
/**
 * set_partition - perform a partition
 * @array: the array to sort
 * @size: size of the array
 * @start: The start of the partition
 * @end: The end of the partition
 *
 * Return: size_t of the position of the new partition;
 */
size_t set_partition(int *array, size_t size, size_t start, size_t end)
{
	size_t cursor = start;

	for (; start < end; start++)
	{
		if (array[start] < array[end])
		{
			swap_items(array, start, cursor, size);
			cursor++;
		}
	}
	swap_items(array, cursor, end, size);

	return (cursor);
}
/**
 * quicksort_lomuto - quick sort with Lomuto scheme
 * @array: array to sort
 * @size: size of the array
 * @start: the start of the quicksort
 * @end: the end of the quicksort
 *
 * Return: void
 */
void quicksort_lomuto(int *array, size_t size, size_t start, size_t end)
{
	size_t pivot;

	if (start >= end || end >= size)
		return;

	pivot = set_partition(array, size, start, end);

	quicksort_lomuto(array, size, start, pivot - 1);/* left side of pivot */
	quicksort_lomuto(array, size, pivot + 1, end);/* right side of pivot */
}

/**
 * quick_sort - implements the quick sort method w/ Lomuto scheme
 * @array: array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_lomuto(array, size, 0, size - 1);
}
