#include <stdio.h>
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
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
	return (count);
}

static char	**malloc_fail(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	*fillup(char *word, char *start, char *end)
{
	size_t	j;

	j = 0;
	while (start < end)
		word[j++] = *start++;
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*start;
	size_t	i;

	split = (char **)malloc(((count_words(s, c)) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s)
		{
			start = (char *) s;
			while (*s && *s != c)
				++s;
			split[i] = (char *)malloc(((s - start) + 1) * sizeof(char));
			if (!split[i])
				return (malloc_fail(split));
			fillup(split[i++], start, (char *)s);
		}
	}
	split[i] = NULL;
	return (split);
}


// Helper function to print the split array
void	print_split(char **split)
{
	size_t i = 0;
	while (split[i])
	{
		printf("Word %zu: \"%s\"\n", i, split[i]);
		i++;
	}
	if (i == 0)
		printf("No words found.\n");
}

int main() {
	// Test 1: Simple case with words separated by spaces
	char *test1 = "Hello World From C";
	char **result1 = ft_split(test1, ' ');
	print_split(result1);

	// Test 2: Case with multiple consecutive delimiters
	char *test2 = "Hello  World   From C";
	char **result2 = ft_split(test2, ' ');
	print_split(result2);

	// Test 3: Case with no words, only delimiters
	char *test3 = "    ";
	char **result3 = ft_split(test3, ' ');
	print_split(result3);

	// Test 4: Case with an empty string
	char *test4 = "";
	char **result4 = ft_split(test4, ' ');
	print_split(result4);

	// Test 5: Case where the string starts with the delimiter
	char *test5 = "  Hello World";
	char **result5 = ft_split(test5, ' ');
	print_split(result5);

	// Test 6: Case where the string ends with the delimiter
	char *test6 = "Hello World  ";
	char **result6 = ft_split(test6, ' ');
	print_split(result6);

	// Test 7: Case with single-word string
	char *test7 = "SingleWord";
	char **result7 = ft_split(test7, ' ');
	print_split(result7);

	// Test 8: Case with no delimiters (entire string is one word)
	char *test8 = "NoDelimitersHere";
	char **result8 = ft_split(test8, ' ');
	print_split(result8);

	// Test 9: Case with multiple delimiters at the start and end
	char *test9 = "  Hello World  ";
	char **result9 = ft_split(test9, ' ');
	print_split(result9);

	// Test 10: Case with custom delimiter (comma)
	char *test10 = "apple,banana,orange,grape";
	char **result10 = ft_split(test10, ',');
	print_split(result10);

	// Clean up
	// Free all the allocated memory (not included in ft_split)
	return 0;
}
