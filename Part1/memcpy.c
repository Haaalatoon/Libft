#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (dest == (void *)0 && src == (void *)0)
		return dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}
