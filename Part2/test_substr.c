#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your ft_strlen implementation (for demonstration)
size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Your ft_memcpy implementation (for demonstration)
void *ft_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

// Your ft_substr implementation
char *ft_substr(char const *s, unsigned int start, size_t len) {
    char *sub;
    size_t sub_size = 0;
    size_t s_len;

    if (s == NULL) // Check for NULL string
        return NULL;

    s_len = ft_strlen(s);

    if (start >= s_len) // If start index is beyond the string length
    {
        sub = (char *)malloc(1 * sizeof(char)); // Allocate space for empty string
        if (sub == NULL)
            return NULL; // Check for allocation failure
        sub[0] = '\0'; // Null-terminate
        return sub;
    }

    // Calculate the size of the substring to copy
    if (len > s_len - (size_t)start)
        sub_size = s_len - (size_t)start; // Adjust size if len exceeds remaining
    else
        sub_size = len;

    // Allocate memory for the substring including the null terminator
    sub = (char *)malloc((sub_size + 1) * sizeof(char));
    if (sub == NULL)
        return NULL; // Check for allocation failure

    // Copy the substring from the original string
    ft_memcpy(sub, s + start, sub_size);
    sub[sub_size] = '\0'; // Null-terminate the substring

    return sub;
}

// Main function to test ft_substr
int main() {
    // Test cases
    char *str = "Hello, World!";
    
    // Test case 1: Normal case
    char *substr1 = ft_substr(str, 7, 5);
    printf("Substring 1: '%s'\n", substr1); // Expected: "World"
    free(substr1); // Don't forget to free memory!

    // Test case 2: Start index beyond string length
    char *substr2 = ft_substr(str, 15, 5);
    printf("Substring 2: '%s'\n", substr2); // Expected: ""
    free(substr2); // Free memory!

    // Test case 3: Start index at the beginning
    char *substr3 = ft_substr(str, 0, 5);
    printf("Substring 3: '%s'\n", substr3); // Expected: "Hello"
    free(substr3); // Free memory!

    // Test case 4: Length exceeds remaining string length
    char *substr4 = ft_substr(str, 7, 20);
    printf("Substring 4: '%s'\n", substr4); // Expected: "World!"
    free(substr4); // Free memory!

    // Test case 5: NULL input
    char *substr5 = ft_substr(NULL, 0, 5);
    printf("Substring 5: '%s'\n", substr5); // Expected: (NULL)
    free(substr5); // Free memory (though it is NULL)

    return 0;
}
