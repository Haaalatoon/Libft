#include <string.h>
#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	char *found = NULL;

	while(*s)
	{
		if (*s == (char)c)
			found = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return found;
}

int main(void)
{
	char str[] = "Hello World";

	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", strrchr(str, '\0'));
	return 0;
}
