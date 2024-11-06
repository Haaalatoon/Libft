#include <stdio.h>

size_t count_words(char const *s, char c)
{
	size_t count = 0, len;
	size_t *len_word;

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

{
	char const s1[] = "  Hello World   yay  !";
	char const s2[] = "Hi be er   ada      i  ";

	printf("%zu\t %zu\n", count_words(s1, ' '), count_words(s2, ' '));
	return 0;
}
