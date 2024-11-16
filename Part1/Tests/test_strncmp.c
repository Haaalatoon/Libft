#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]); 
	return (0);
}

int main(void)
{
    // Test cases: Each element contains two strings and a size_t for n
    struct test_case {
        const char *s1;
        const char *s2;
        size_t n;
    };

    struct test_case test_cases[] = {
        {"apple", "apple", 5},  // Identical strings
        {"apple", "apricot", 5}, // Same prefix, different character
        {"apple", "applepie", 5}, // s1 is prefix of s2, n == len of s1
        {"apple", "appl", 5},    // s2 is shorter, n > len of s2
        {"apple", "apricot", 0}, // n == 0 (no comparison should happen)
        {"apple", "banana", 3}, // First 3 characters are different
        {"apple", "banan", 4},  // Partial match, edge case for early termination
        {"", "apple", 5},       // One string is empty
        {"apple", "", 5},       // One string is empty
        {"", "", 0}             // Both strings are empty
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int i;

    for (i = 0; i < num_cases; i++)
    {
        const char *s1 = test_cases[i].s1;
        const char *s2 = test_cases[i].s2;
        size_t n = test_cases[i].n;
        
        printf("Testing ft_strncmp vs strncmp\n");
        printf("s1 = \"%s\", s2 = \"%s\", n = %zu\n", s1, s2, n);
        
        int result_ft = ft_strncmp(s1, s2, n);
        int result_std = strncmp(s1, s2, n);

        printf("ft_strncmp: %d\n", result_ft);
        printf("strncmp: %d\n", result_std);

        if (result_ft == result_std)
            printf("PASS\n\n");
        else
            printf("FAIL\n\n");
    }

    return 0;
}
