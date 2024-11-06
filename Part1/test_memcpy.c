#include <string.h>
#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}

int main(void)
{
	char src[] = "Hello WOrld!";
	char dest1[20];
	char dest2[20];

	ft_memcpy(dest1, src, 10);
	memcpy(dest2, src, 10);
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	return 0;
	
}
