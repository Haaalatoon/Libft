#include "libft.h"

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
