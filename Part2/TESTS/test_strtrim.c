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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set || ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
	{
		trimmed = (char *)malloc(1 * sizeof(char));
		if (trimmed == NULL)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	ft_strlcpy(trimmed, s1 + start, end - start + 2);
	return (trimmed);
}


#include <stdio.h>
#include <string.h>

void print_result(char *test_name, char *s1, char *set, char *result)
{
    printf("\nTest: %s\n", test_name);
    printf("s1: [%s]\n", s1);
    printf("set: [%s]\n", set ? set : "NULL");
    printf("result: [%s]\n", result ? result : "NULL");
    printf("------------------------\n");
}

int main(void)
{
    char    *result;
    char    *s1;
    char    *set;

    // Basic tests
    s1 = "   Hello World   ";
    set = " ";
    result = ft_strtrim(s1, set);
    print_result("Basic space trim", s1, set, result);

    s1 = "...Hello World...";
    set = ".";
    result = ft_strtrim(s1, set);
    print_result("Basic dot trim", s1, set, result);

    // Edge cases - Empty strings
    s1 = "";
    set = " ";
    result = ft_strtrim(s1, set);
    print_result("Empty string", s1, set, result);

    s1 = "Hello World";
    set = "";
    result = ft_strtrim(s1, set);
    print_result("Empty set", s1, set, result);

    // Edge cases - NULL
    s1 = NULL;
    set = " ";
    result = ft_strtrim(s1, set);
    print_result("NULL string", s1, set, result);

    s1 = "Hello World";
    set = NULL;
    result = ft_strtrim(s1, set);
    print_result("NULL set", s1, set, result);

    // String containing only trim characters
    s1 = "      ";
    set = " ";
    result = ft_strtrim(s1, set);
    print_result("Only spaces", s1, set, result);

    s1 = "...";
    set = ".";
    result = ft_strtrim(s1, set);
    print_result("Only trim chars", s1, set, result);

    // Multiple trim characters
    s1 = "#@!Hello World!@#";
    set = "#@!";
    result = ft_strtrim(s1, set);
    print_result("Multiple trim chars", s1, set, result);

    // Trim characters in middle (shouldn't be trimmed)
    s1 = "...Hello...World...";
    set = ".";
    result = ft_strtrim(s1, set);
    print_result("Trim chars in middle", s1, set, result);

    // Single character string
    s1 = "a";
    set = "a";
    result = ft_strtrim(s1, set);
    print_result("Single char string equals set", s1, set, result);

    // No trim needed
    s1 = "Hello World";
    set = "xyz";
    result = ft_strtrim(s1, set);
    print_result("No trim needed", s1, set, result);

    // Complex cases
    s1 = "\t\n Hello \t\n World \t\n";
    set = " \t\n";
    result = ft_strtrim(s1, set);
    print_result("Whitespace chars", s1, set, result);

    s1 = "aabbccHello Worldccbbaa";
    set = "abc";
    result = ft_strtrim(s1, set);
    print_result("Multiple repeating trim chars", s1, set, result);

    // Overlapping characters
    s1 = "HelloHelloWorldWorldHelloHello";
    set = "Hello";
    result = ft_strtrim(s1, set);
    print_result("Overlapping trim string", s1, set, result);

    return (0);
}
