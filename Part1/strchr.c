#include "libft.h"

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
