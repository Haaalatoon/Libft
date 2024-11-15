#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;

	if (s < d && d < s + n)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return dest;
}

int main()
{
	char src1[] = "Hello, World!";
	char src2[] = "1234567890";
	char dest1[14];
	char dest2[14];

	ft_memmove(dest1, src1, 13); // Copying 13 bytes
    memmove(dest2, src1, 13);     // Copying 13 bytes
    printf("with ft_memmove: %s\n", dest1); // Expected: Hello, World!
    printf("with memmove: %s\n", dest2);     // Expected: Hello, World!

    // Test overlapping
    ft_memmove(src2 + 2, src2, 8); // Move "12345678" into "34567890"
    printf("with ft_memmove (overlap): %s\n", src2); // Expected: 1212345670

    // No need to call memmove again for overlapping test
    return 0;
}
