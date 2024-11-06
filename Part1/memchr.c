#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *found;
	size_t i = 0;

	found = (unsigned char *)s;
	while(i < n)
	{
		if (found[i] == (unsigned char)c)
			return (void *)(found + i);
		i++;
	}
	return NULL;
}
