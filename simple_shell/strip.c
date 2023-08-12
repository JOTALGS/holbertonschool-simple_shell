#include <string.h>
#include <ctype.h>

void strip(char *str) {
    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len - 1;

    while (start < len && isspace((unsigned char)str[start])) {
        start++;
    }

    while (end > start && isspace((unsigned char)str[end])) {
        end--;
    }

    memmove(str, str + start, end - start + 1);

    str[end - start + 1] = '\0';
}
