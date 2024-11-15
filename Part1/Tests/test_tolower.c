#include <ctype.h>
#include <stdio.h>

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}

int main(void)
{
	int c = 23;

	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c));
	return 0;
}
