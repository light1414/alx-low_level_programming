#include "search_algos.h"

/**
 * interpolation_search - it finds value in an array
 * @array: a pointer to first element
 * @size: the number of elements
 * @value: value
 *
 * Return: the index of containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t in = 0;
	size_t out = size - 1;
	size_t pos;

	if (!array)
		return (-1);

	while ((array[out] != array[in]) &&
	       (value >= array[in]) && (value <= array[out]))
	{
		pos = in + (((double)(out - in) / (array[out] - array[in]))
			    * (value - array[in]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			in = pos + 1;
		else if (value < array[pos])
			out = pos - 1;
		else
			return (pos);
	}
	if (value == array[in])
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[in]);
		return (in);
	}
	pos = low + (((double)(out - in) / (array[out] - array[in]))
		     * (value - array[in]));
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}
