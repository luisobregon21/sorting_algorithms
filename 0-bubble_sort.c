#include "sort.h"
/**
 * bubble_sort - algorithm sorts an array of integers in ascending order
 * @array: array being passed
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, idx2;
	int flag, tmp = 0;

	if (size < 2 || array == NULL)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		flag = 0;
		for (idx2 = 0; idx2 < size - 1; idx2++)
		{
			if (array[idx2 + 1] < array[idx2])
			{
				tmp = array[idx2];
				array[idx2] = array[idx2 + 1];
				array[idx2 + 1] = tmp;
				flag = 1;
				print_array(array, size);
			}
			if (flag == 0)
				continue;
		}
	}
}
