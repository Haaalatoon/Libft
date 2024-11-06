#include <ctype.h>
#include <stdio.h>

int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return 1;
	else
		return 0;
}


int main (void){
	
	int c = 128;

	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	return 0;
}
