#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	char *dup;

	if (s == NULL)
		return NULL;
	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return NULL;
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return dup;
}
