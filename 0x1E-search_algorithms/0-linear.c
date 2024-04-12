#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * linear_search - function that searches for a value in an array of integers
 * using the Linear search algorithm.
 * @array: pointer to the first element of the array to search in.
 * @size: the number of the elements in array.
 * @value: the value to search for.
 * return: first index where value is located
 * or -1 if not found.
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array || size == 0)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);

		i++;
	}

	return (-1);
}
