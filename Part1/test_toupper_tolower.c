#include <stdio.h>
#include <ctype.h>

// Your custom functions
int ft_toupper(int c) {
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

int ft_tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

int main() {
    // Test characters
    char testChars[] = {'a', 'A', 'z', 'Z', '1', '#', -1, 128}; // Including non-ASCII and negative
    int length = sizeof(testChars) / sizeof(testChars[0]);
    
    printf("Character | ft_toupper | toupper | ft_tolower | tolower\n");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < length; i++) {
        char c = testChars[i];
        printf("   '%c'    |    '%c'    |   '%c'  |    '%c'     |   '%c'\n",
               c,
               ft_toupper(c), toupper(c),
               ft_tolower(c), tolower(c));
    }
    
    return 0;
}

