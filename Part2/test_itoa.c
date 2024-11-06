#include <stdio.h>
#include <stdlib.h>

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

unsigned int abs_value(int n)
{
	if (n >= 0)
		return n;
	return -n;
}

char *case_0(void)
{
	char *number;

	number = (char *)malloc(2 * sizeof(char));
	if (!number)
		return NULL;
	ft_strlcpy(number, "0", 2);
	return number;
}

char *case_INT_MIN(void)
{
	char *number;

	number = (char *)malloc(12 * sizeof(char));
	if (!number)
		return NULL;
	ft_strlcpy(number, "-2147483648", 12);
	return number;
}

char *fill_number(char *number, unsigned int num, int size)
{
	int i = size;

	while (num)
	{
		number[--i] = num % 10 + '0';
		num = num / 10;
	}
	return number;
}

char *ft_itoa(int n)
{
	char *number;
	int count = 0, size;
	unsigned int num;

	if(n == 0)
		return case_0();
	if (n == -2147483648)
		return case_INT_MIN();
	num = abs_value(n);
	while (num)
	{
		count++;
		num = num / 10;
	}
	size = count + (n < 0);
	number = (char *)malloc((size + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[size] = '\0';
	if (n < 0)
		number[0] = '-';
	num = abs_value(n);
	fill_number(number, num, size);
	return number;
}


int main() {
    // Test Cases
    int test_cases[] = {123, -456, 0, -2147483648, 7890, -1234, 5, -2};
    char *results;

    for (long unsigned int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        results = ft_itoa(test_cases[i]);
        printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], results);
        free(results);  // Free the allocated memory
    }

    return 0;
}
