#include "sort.h"


void merge(int *array, size_t size, size_t m)
{
	size_t i = 0, j = m, k = 0;
	int *tmp = malloc(size * sizeof(*array));

	puts("Merging...");
	printf("[left]: "), print_array(array, size - m);
	while (k < size)
		if (j == size)
			tmp[k++] = array[i++];
		else if (i == m)
			tmp[k++] = array[j++];
		else if (array[j] < array[i])
			tmp[k++] = array[j++];
		else
			tmp[k++] = array[i++];

	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	printf("[Done]: "), print_array(array, size);
	free(tmp);
}

void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t m = size / 2;

		merge_sort(array, m);
		merge_sort(array + m, size - m);
		merge(array, size, m);
	}
}
