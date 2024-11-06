#include <ctype.h>
#include <stdio.h>

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return c;
}

int main(void)
{
	int c = 'H';

	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
	return 0;
}
