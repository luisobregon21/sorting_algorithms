#include "sort.h"
/**
 *swap - two numbers
 *@a: num
 *@b: num
 *@array: array to print
 *@size: size of array
 */
void swap(int a, int b, int *array, size_t size)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}
/**
 *partition - takes last element as pivot, places pivot at correct position
 *@array: array being ordered
 *@low: smallest num
 *@high: biggest num
 *@size: size
 *Return: index of smaller element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int newpivot = low;
	int i;

	for (i = low; i < high; ++i)
	{
		if (array[i] < pivot)
		{
			if (i != newpivot)
				swap(newpivot, i, array, size);
			newpivot++;
		}
	}
	if (newpivot != high)
	{
		swap(newpivot, high, array, size);
	}
	return (newpivot);
}
/**
 *quicksort - sorts the array
 *@array: to be sorted
 *@low: lowest number
 *@high: highest number
 *@size: size of arrau
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}
/**
 *quick_sort - sorts an array of integers in ascending order using
 *@array: array being passed
 *@size: of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
