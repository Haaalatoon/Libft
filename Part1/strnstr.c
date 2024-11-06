#include "libft.h"

char *ft_strnstr(const char *big,const char *little, size_t len)
{
	size_t i = 0, j = 0;
	char *found;

	if (*little == '\0')
		return (char *)big;
	while (little[j] && i < len)
	{
		if (big[i] == little[j])
		{
			found = big[i];
			while (big[i] == little[j])
			{
				i++;
				j++;
			}
			if (little[i] == '\0')
				return found;
		}
		i++;
	}
	return NULL;
}
