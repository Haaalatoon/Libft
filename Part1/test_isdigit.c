#include <ctype.h>
#include <stdio.h>

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

int main(void)
{
	int c = '0';

	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	return 0;
}

