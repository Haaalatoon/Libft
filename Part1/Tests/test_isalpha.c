#include <ctype.h>
#include <stdio.h>

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;
}

int main(void)
{
	int c = 63;

	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	return 0;
}
