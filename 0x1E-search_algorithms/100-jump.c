#include "search_algos.h"
/**
 * jump_search - it searches for values in an array
 * @array: the input array
 * @size: the size of the array
 * @value: the value to search
 * Return: index number
 */
int jump_search(int *array, size_t size, int value)
{
	int index, u, k, prev;

	if (array == NULL || size == 0)
		return (-1);

	u = (int)sqrt((double)size);
	k = 0;
	pre = index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		k++;
		pre = index;
		index = k * u;
	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", pre, index);

	for (; pre <= index && pre < (int)size; pre++)
	{
		printf("Value checked array[%d] = [%d]\n", pre, array[pre]);
		if (array[pre] == value)
			return (pre);
	}

	return (-1);
}
