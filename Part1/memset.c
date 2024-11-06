#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t i = 0;
	unsigned char *ptr1;

	ptr1 = (unsigned char *)s;
	while (i < n)
	{
		ptr1[i] = (unsigned char)c;
		i++;
	}
	return s;
}
