#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	char *found;

	found = (char *)s;
	while(*found)
	{
		if (*found == c)
			return found;
		found++;
	}
	if (c == '\0')
		return found;
	return NULL;
}

int main(void)
{
	char str[] = "Hello\0World";

	printf("%s\n", ft_strchr(str, '\0'));
	printf("%s\n", strchr(str, '\0'));
	return 0;
}
