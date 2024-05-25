#include "search_algos.h"

/**
 * linear_search - this function searches for a value
 * in an array of integers using the Linear search algorithm
 * @value: the value being searched
 * @array: Objects to be searched list
 * @size: the number of elements in array
 * Return: 0
 */

int linear_search(int *array, size_t size, int vau)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%li] = [%d]\n", i, array[i]);
		if (value == array[i])
		{
			return (i);
		}
	}
	return (-1);
}
