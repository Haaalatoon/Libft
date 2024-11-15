#include <stdio.h>
#include <stdlib.h>

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
	split[i] = NULL;
	free(lengths);
	return split;
}

int main()
{
    char **result;
    int i;

    // Test 1: Normal case with spaces as delimiters
    char *test1 = "Hello world this is a test";
    result = ft_split(test1, ' ');
    printf("Test 1:\n");
    for (i = 0; result[i] != NULL; i++)
        printf("result[%d]: '%s'\n", i, result[i]);
    printf("\n");
    // Free memory
    for (i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test 2: Consecutive delimiters
    char *test2 = "Hello,,world,,split,test";
    result = ft_split(test2, ',');
    printf("Test 2:\n");
    for (i = 0; result[i] != NULL; i++)
        printf("result[%d]: '%s'\n", i, result[i]);
    printf("\n");
    // Free memory
    for (i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test 3: Delimiter at start and end
    char *test3 = ",Hello,world,";
    result = ft_split(test3, ',');
    printf("Test 3:\n");
    for (i = 0; result[i] != NULL; i++)
        printf("result[%d]: '%s'\n", i, result[i]);
    printf("\n");
    // Free memory
    for (i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test 4: Empty string
    char *test4 = "";
    result = ft_split(test4, ',');
    printf("Test 4:\n");
    for (i = 0; result[i] != NULL; i++)
        printf("result[%d]: '%s'\n", i, result[i]);
    printf("\n");
    // Free memory
    for (i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test 5: String with only delimiters
    char *test5 = ",,,,,";
    result = ft_split(test5, ',');
    printf("Test 5:\n");
    for (i = 0; result[i] != NULL; i++)
        printf("result[%d]: '%s'\n", i, result[i]);
    printf("\n");
    // Free memory
    for (i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    return 0;
}
