#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t in, size_t out);
size_t min(size_t a, size_t b);

/**
 * min - prints the minimum of two size_t values
 * @a: the first value
 * @b: the second value
 *
 * Return: `a` if lower or equal to `b`, `b` else
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * binary_search_helper - looks for a value in an integer array using a
 * binary search algorithm.
 * appears in search
 * @array: a pointer to first element of array to seach
 * @value: searcd value 
 * @low: the starting index
 * @high:an ending index
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search_helper(int *array, int value,
			 size_t in, size_t out)
{
	size_t mid, i;

	if (!array)
		return (-1);

	while (in <= out)
	{
		mid = (in + out) / 2;
		printf("Searching in array: ");
		for (i = in; i <= out; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");
		if (array[mid] < value)
			in = mid + 1;
		else if (array[mid] > value)
			out = mid - 1;
		else
			return ((int)mid);
	}

	return (-1);
}

/**
 * exponential_search - this searches for a value in a sorted array of integers
 * using an exponential search algorithm
 * @array: A pointer to first element of array to search
 * @size: THE number of elements in array
 * @value: value
 *
 * Return: The first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t in, out, bound = 1;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	in= bound / 2;
	out = min(bound, size - 1);
	/* 'found' message generated even if array[out] < value */
	printf("Value found between indexes [%lu] and [%lu]\n", in, high);
	return (binary_search_helper(array, value, in, low));
}
