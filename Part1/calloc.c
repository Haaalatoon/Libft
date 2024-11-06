#include "libft.h"
#include <stdlib.h>

void *ft_calloc(size_t number, size_t size)
{
	void *arr;

	if (size == 0 || number == 0)
		return NULL;
	arr = malloc(number * size);
	if (arr == NULL)
		return NULL;
	ft_memset(arr, 0, number * size);
	return arr;
}
