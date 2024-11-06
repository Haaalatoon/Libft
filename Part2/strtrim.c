#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
	size_t start = 0, end, i;
	char *str_trim;

	if (s1 == NULL)
		return NULL;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	/*prevents potential issues related to memory management. Failed free*/
	/*returning pointer to another location than the old location of s1*/
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));

	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;

	if (start > end)
	{
		str_trim = (char *)malloc(1 * sizeof(char));
		if (str_trim == NULL)
			return NULL;
		str_trim[0] = '\0';
		return str_trim;
	}

	str_trim = (char *)malloc(((end - start + 1) + 1) * sizeof(char));

	i = 0;
	while (start <= end)
		str_trim[i++] = s1[start++];
	str_trim[i] = '\0';
	return str_trim;
}

