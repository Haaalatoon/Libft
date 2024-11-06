#include <stdio.h>
#include <stdlib.h>

void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);

size_t ft_strlen(const char *s)
{
	size_t count = 0;

	while (*s)
	{
		count++;
		s++;
	}
	return count;
}

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

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len = ft_strlen(src);

	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (dest == (void *)0 && src == (void *)0)
		return dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}


char *ft_strtrim(char const *s1, char const *set)
{
	size_t start = 0, end, i;
	char *s_trim;

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
		s_trim = (char *)malloc(1 * sizeof(char));
		if (s_trim == NULL)
			return NULL;
		s_trim[0] = '\0';
		return s_trim;
	}

	s_trim = (char *)malloc((end - start + 2) * sizeof(char));

	i = 0;
	while (start <= end)
		s_trim[i++] = s1[start++];
	s_trim[i] = '\0';
	return s_trim;
}

int main(void)
{
    char *result;

    // Test 1: Basic Test with Trimming Characters
    char s1_1[] = "  Hello, World!  ";
    char set_1[] = " ";
    result = ft_strtrim(s1_1, set_1);
    printf("Test 1:\nExpected: 'Hello, World!'\nResult: '%s'\n\n", result);
    free(result);

    // Test 2: No Characters to Trim
    char s1_2[] = "Hello, World!";
    char set_2[] = "xyz";
    result = ft_strtrim(s1_2, set_2);
    printf("Test 2:\nExpected: 'Hello, World!'\nResult: '%s'\n\n", result);
    free(result);

    // Test 3: All Characters Should Be Trimmed
    char s1_3[] = "xxxxxx";
    char set_3[] = "x";
    result = ft_strtrim(s1_3, set_3);
    printf("Test 3:\nExpected: ''\nResult: '%s'\n\n", result);
    free(result);

    // Test 4: Empty s1
    char s1_4[] = "";
    char set_4[] = " ";
    result = ft_strtrim(s1_4, set_4);
    printf("Test 4:\nExpected: ''\nResult: '%s'\n\n", result);
    free(result);

    // Test 5: NULL s1
    char *s1_5 = NULL;
    char set_5[] = " ";
    result = ft_strtrim(s1_5, set_5);
    printf("Test 5:\nExpected: NULL\nResult: '%s'\n\n", result);

    // Test 6: NULL set
    char s1_6[] = "  Hello  ";
    char *set_6 = NULL;
    result = ft_strtrim(s1_6, set_6);
    printf("Test 6:\nExpected: '  Hello  '\nResult: '%s'\n\n", result);
    free(result);

    // Test 7: Entire String Trimmed to Empty (start > end)
    char s1_7[] = "abccba";
    char set_7[] = "abc";
    result = ft_strtrim(s1_7, set_7);
    printf("Test 7:\nExpected: ''\nResult: '%s'\n\n", result);
    free(result);

    // Test 8: set Contains Characters Not in s1
    char s1_8[] = "Hello, World!";
    char set_8[] = "xyz";
    result = ft_strtrim(s1_8, set_8);
    printf("Test 8:\nExpected: 'Hello, World!'\nResult: '%s'\n\n", result);
    free(result);

    // Test 9: s1 Starts and Ends with Trim Characters
    char s1_9[] = "**Hello, World!**";
    char set_9[] = "*";
    result = ft_strtrim(s1_9, set_9);
    printf("Test 9:\nExpected: 'Hello, World!'\nResult: '%s'\n\n", result);
    free(result);

    return 0;
}
