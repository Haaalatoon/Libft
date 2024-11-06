#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t count = 0;

	while (*s)
	{
		count++;
		s++;
	}
	return count;
}

int main(void)
{
	char str[] = "";

	printf("%zu\n", ft_strlen(str));
	printf("%zu\n", strlen(str));
	return 0;
}
