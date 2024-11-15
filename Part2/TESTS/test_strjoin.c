#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t i;

    if (dstsize == 0) return ft_strlen(src);
    for (i = 0; i < dstsize - 1 && src[i] != '\0'; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return ft_strlen(src);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dst_len = ft_strlen(dst);
    size_t src_len = ft_strlen(src);
    
    if (dstsize <= dst_len)
        return dstsize + src_len; // Not enough space to append

    size_t to_copy = dstsize - dst_len - 1; // Leave space for null terminator
    size_t i = 0;
    while (i < to_copy && src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0'; // Null-terminate

    return dst_len + src_len; // Return total length
}

char *ft_strjoin(char const *s1, char const *s2) {
    size_t len1, len2;
    char *s;

    if (!s1 || !s2)
        return NULL;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    s = (char *)malloc(len1 + len2 + 1);
    if (s == NULL)
        return NULL;

    ft_strlcpy(s, s1, len1 + 1);
    ft_strlcat(s, s2, len1 + len2 + 1);

    return s;
}

int main() {
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result != NULL) {
        printf("Result of ft_strjoin: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Additional tests
    result = ft_strjoin("Goodbye, ", "Cruel World!");
    if (result != NULL) {
        printf("Result of ft_strjoin: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    result = ft_strjoin("", "Empty Prefix");
    if (result != NULL) {
        printf("Result of ft_strjoin: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    result = ft_strjoin("Non-empty", "");
    if (result != NULL) {
        printf("Result of ft_strjoin: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    result = ft_strjoin(NULL, "Should fail");
    if (result == NULL) {
        printf("Correctly handled NULL input.\n");
    }

    return 0;
}

