#include "libft.h"
#include <stdlio.h>

size_t count_words(char const *s, char c)
{
	size_t count = 0;

	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				++s;
		}
	}
	return count;
}

size_t *count_lengths(char const *s, char c)
{
    size_t len;
    size_t *len_word, *ptr;
    size_t word_count = count_words(s, c);

    len_word = (size_t *)malloc(word_count * sizeof(size_t));
    if (!len_word)
        return NULL;
    ptr = len_word;
    while (*s)
    {
        while (*s == c && *s)
            ++s;
        if (*s && *s != c)
        {
            len = 0;
            while (*s && *s != c)
            {
                ++s;
                ++len;
            }
            *len_word = len;
            ++len_word;
        }
    }
    return ptr;
}

char **ft_split(char const *s, char c)
{
	size_t count = count_words(s, c);
	size_t *lengths = count_lengths(s, c), i = 0, j;
	if(!lengths)
		return NULL;
	char **split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
	{
		free(lengths);
		return NULL;
	}
	while (i < count)
	{
		split[i] = (char *)malloc((lengths[i] + 1) * sizeof(char));
		if (!split[i])
		{
			j = 0;
			while (j < i)
			{
				free(split[j]);
				j++;
			}
			free (split);
			free (lengths);
			return NULL;
		}
		i++;
	}
	i = 0, j = 0;
	while (i < count)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			j = 0;
			while (*s && *s != c)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
	}
	split[count] = NULL;
	free(lengths);
	return split;
}
