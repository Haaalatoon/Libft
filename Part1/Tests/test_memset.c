#include <string.h>
#include <stdio.h>

void *ft_memset(void *s, int c, size_t n)
{
	size_t i = 0;
	unsigned char *ptr1;

	if (s == NULL)
		return NULL;
	ptr1 = (unsigned char *)s;
	while (i < n)
	{
		ptr1[i] = (unsigned char)c;
		i++;
	}
	return s;
}

int main(void)
{
	char buffer1[10] = {0};
	char buffer2[10] = {0};

	printf("Before ft_memset: %s\n", buffer1);
	ft_memset(buffer1, 'A', sizeof(buffer1) - 1);
	buffer1[9] = '\0';
	printf("After ft_memset: %s\n", buffer1);
	printf("Before memset: %s\n", buffer2);
	memset(buffer2, 'A', sizeof(buffer2) - 1);
	buffer2[9] = '\0';
	printf("After memset: %s\n", buffer2);
	return 0;
}
