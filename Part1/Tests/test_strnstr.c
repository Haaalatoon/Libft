#include <stdio.h>

char *ft_strnstr(const char *big,const char *little, size_t len)
{
	size_t i = 0, j = 0;
	char *found;

	if (*little == '\0')
		return (char *)big;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return (char *)(big + i);
		}
		i++;
	}
	return NULL;
}

int main()
{
	const char *big = "Hello, World!";
	const char *little = "world";
	size_t len = 5;
	char *my_fct;

	my_fct = ft_strnstr(big, little, len);
	printf("%s\n", my_fct);
	return 0;
}
