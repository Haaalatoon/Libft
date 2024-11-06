#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t sub_size = 0;
	size_t s_len = ft_strlen(s);

	if (s == NULL)
		return NULL;
	if (start >= s_len)
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub == NULL)
			return NULL;
		sub[0] = '\0';
		return sub;
	}
	if (len > ft_strlen(s) - (size_t)start)
		sub_size = s_len - (size_t)start;
	else
		sub_size = len;
	sub = (char *)malloc((sub_size + 1) * sizeof(char));
	if (sub == NULL)
		return NULL;
	ft_strlcpy(sub, s + start, sub_size + 1);
	return sub;
}