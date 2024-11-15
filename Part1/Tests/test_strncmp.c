#include <string.h>
#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return 0;
}

int main(void)
{
    char str1[] = "Hel";
    char str2[] = "Hello";
    printf("%d\n", ft_strncmp(str1, str2, 1));
    printf("%d\n", ft_strncmp(str1, str2, 2));
    printf("%d\n", strncmp(str1, str2, 1));
    printf("%d\n", strncmp(str1, str2, 2));
    return 0;
}
