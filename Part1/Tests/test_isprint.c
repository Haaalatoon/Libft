#include <ctype.h>
#include <stdio.h>

int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return 1;
	else
		return 0;
}

int main(void)
{
	int c = 127;

	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
	return 0;
}
