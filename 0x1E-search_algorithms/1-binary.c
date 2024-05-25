#include "search_algos.h"

/**
 * binary_search - it searches for a value in a sorted integers array
 * @array: the pointer to the first element of the array
 * @size: the number of elements
 * @value: value
 *
 * Return: index value, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lowidx = 0;
	size_t upidx = size - 1;
	size_t mid;
	size_t i;

	if (array == NULL)
		return (-1);

	while (lowidx <= upidx)
	{
		printf("Searching in array: ");
		for (i = lowidx; i <= upidx; i++)
		{
			printf("%d", array[i]);
			if (i != upidx)
				printf(", ");
		}
		printf("\n");

		mid = (lowidx + upidx) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			lowidx = mid + 1;
		else
			upridx = mid - 1;
	}

	return (-1);
}
